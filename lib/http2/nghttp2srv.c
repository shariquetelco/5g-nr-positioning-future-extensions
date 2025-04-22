#include "nghttp2srv.h"
#include <openssl/ssl.h>

static int
alpn_select_proto_cb(SSL *ssl, const unsigned char **out, unsigned char *outlen, const unsigned char *in, unsigned int inlen, void *arg)
{
	int rv;
	(void)ssl;
	(void)arg;

	rv = nghttp2_select_alpn(out, outlen, in, inlen);

	if (rv != 1)
	{
		return SSL_TLSEXT_ERR_NOACK;
	}

	return SSL_TLSEXT_ERR_OK;
}

static int
pem_passwd_cb(char *buf, int size, int rwflag, void *password)
{
	strncpy(buf, (char *)(password), size);
	buf[size - 1] = '\0';
	return(strlen(buf));
}

/* Create SSL_CTX. */
static SSL_CTX*
create_ssl_ctx(const char *key_file, const char *cert_file)
{
	SSL_CTX *ssl_ctx = 0;
	char *pw = "123456789";

	ssl_ctx = SSL_CTX_new(TLS_server_method());
	if (!ssl_ctx)
	{
		errx(1, "Could not create SSL/TLS context: %s", ERR_error_string(ERR_get_error(), NULL));
		return ssl_ctx;
	}

	SSL_CTX_set_options(ssl_ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_COMPRESSION | SSL_OP_NO_SESSION_RESUMPTION_ON_RENEGOTIATION | SSL_OP_IGNORE_UNEXPECTED_EOF);

#if OPENSSL_VERSION_NUMBER >= 0x30000000L
	if (SSL_CTX_set1_curves_list(ssl_ctx, "P-256") != 1)
	{
		errx(1, "SSL_CTX_set1_curves_list failed: %s", ERR_error_string(ERR_get_error(), NULL));
		SSL_CTX_free(ssl_ctx);
		return NULL;
	}
#else  /* !(OPENSSL_VERSION_NUMBER >= 0x30000000L) */
	{
		EC_KEY *ecdh;
		ecdh = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
		if (!ecdh)
		{
			errx(1, "EC_KEY_new_by_curv_name failed: %s", ERR_error_string(ERR_get_error(), NULL));
			SSL_CTX_free(ssl_ctx);
			return NULL;
		}
		SSL_CTX_set_tmp_ecdh(ssl_ctx, ecdh);
		EC_KEY_free(ecdh);
	}
#endif /* !(OPENSSL_VERSION_NUMBER >= 0x30000000L) */

	/*Added by NK: set PEM password by default*/
	SSL_CTX_set_default_passwd_cb(ssl_ctx, pem_passwd_cb);
	SSL_CTX_set_default_passwd_cb_userdata(ssl_ctx, pw);

	if (SSL_CTX_use_PrivateKey_file(ssl_ctx, key_file, SSL_FILETYPE_PEM) != 1)
	{
		errx(1, "Could not read private key file %s", key_file);
		SSL_CTX_free(ssl_ctx);
		return NULL;
	}
	if (SSL_CTX_use_certificate_chain_file(ssl_ctx, cert_file) != 1)
	{
		errx(1, "Could not read certificate file %s", cert_file);
		SSL_CTX_free(ssl_ctx);
		return NULL;
	}

	SSL_CTX_set_alpn_select_cb(ssl_ctx, alpn_select_proto_cb, NULL);

	return ssl_ctx;
}

static void
add_stream(http2_session_data *session_data, http2_stream_data *stream_data)
{
	stream_data->next = session_data->root.next;
	session_data->root.next = stream_data;
	stream_data->prev = &session_data->root;
	
	if (stream_data->next)
	{
		stream_data->next->prev = stream_data;
	}
}

static void
remove_stream(http2_session_data *session_data, http2_stream_data *stream_data)
{
	(void)session_data;

	stream_data->prev->next = stream_data->next;
	if (stream_data->next)
	{
		stream_data->next->prev = stream_data->prev;
	}
}

static http2_stream_data *
create_http2_stream_data(http2_session_data *session_data, int32_t stream_id)
{
	http2_stream_data *stream_data;
	stream_data = malloc(sizeof(http2_stream_data));
	memset(stream_data, 0, sizeof(http2_stream_data));
	stream_data->stream_id = stream_id;

	add_stream(session_data, stream_data);
	return stream_data;
}

static void
delete_http2_stream_data(http2_stream_data *stream_data)
{
	/*:path field*/
	if(stream_data->request_path)
	{
		free(stream_data->request_path);
	}

	/*:user-agent field*/
	if(stream_data->user_agent)
	{
		free(stream_data->user_agent);
	}

	/*:method field*/
	if(stream_data->method)
	{
		free(stream_data->method);
	}

	/*accept: field*/
	if(stream_data->accept)
	{
		free(stream_data->accept);
	}

	/*content-type: field*/
	if(stream_data->ctype)
	{
		free(stream_data->ctype);
	}
	
	/*payload data*/
	if(stream_data->data)
	{
		free(stream_data->data);
	}

	free(stream_data);
}

static http2_session_data *
create_http2_session_data(app_context *app_ctx, int fd, struct sockaddr *addr, int addrlen) {

	/*Variables*/
	int rv;
	http2_session_data *session_data;
	char host[NI_MAXHOST];
	int val = 1;

	/*Initialize data structures*/
	if((session_data = calloc(1, sizeof(http2_session_data))) == NULL)
	{
		perror("calloc()");
		return NULL;
	}

	/*NK: Create a copy of app_ctx*/
	if((session_data->app_ctx = calloc(1, sizeof(app_context))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	session_data->app_ctx->ssl_ctx = app_ctx->ssl_ctx;
	session_data->app_ctx->cb = app_ctx->cb;
	session_data->app_ctx->sockfd = fd;

	/*Initialize TLS over TCP socket for accepted client*/
	if((session_data->app_ctx->ssl = SSL_new(app_ctx->ssl_ctx)) == NULL)
	{
		errx(1, "Could not create SSL/TLS session object: %s", ERR_error_string(ERR_get_error(), NULL));
		goto err;
	}

	if(setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (char *)&val, sizeof(val)) < 0)
	{
		perror("setsockopt()");
		goto err;
	}

	/*Associate connected TCP socket with SSL structure*/
	if(SSL_set_fd(session_data->app_ctx->ssl, fd) == 0)
	{
		ERR_print_errors_fp(stdout);
		perror("SSL_set_fd()");
		goto err;
	}

	if (SSL_accept(session_data->app_ctx->ssl) <= 0)
	{
		ERR_print_errors_fp(stdout);
		perror("SSL_accept()");
		goto err;
	}

	/*Map IPv4 address of client to human readable string*/
	if ((rv = getnameinfo(addr, (socklen_t)addrlen, host, sizeof(host), NULL, 0, NI_NUMERICHOST)) != 0)
	{
		session_data->client_addr = strdup("(unknown)");
	}
	else
	{
		session_data->client_addr = strdup(host);
	}

	return session_data;

err:
	/*Free memory*/
	if(session_data)
	{
		if(session_data->app_ctx)
		{
			if(session_data->app_ctx->ssl)
			{
				SSL_shutdown(session_data->app_ctx->ssl);
				SSL_free(session_data->app_ctx->ssl);
			}
		
			free(session_data->app_ctx);
		}

		free(session_data);
	}

	return NULL;
}

static void
delete_http2_session_data(http2_session_data *session_data)
{
	/*Variables*/
	http2_stream_data *stream_data;

#ifdef DEBUG
	fprintf(stderr, "%s disconnected\n", session_data->client_addr);
#endif

	/*Free stream data*/
	for (stream_data = session_data->root.next; stream_data;)
	{
		http2_stream_data *next = stream_data->next;
		delete_http2_stream_data(stream_data);
		stream_data = next;
	}

	/*Free memory of HTTP/2 session data*/
	free(session_data->client_addr);
	if(session_data->app_ctx)
	{
		if(session_data->app_ctx->ssl)
		{
			SSL_shutdown(session_data->app_ctx->ssl);
			SSL_free(session_data->app_ctx->ssl);
		}

		/*Close file descriptors*/
		close(session_data->app_ctx->sockfd);
		session_data->app_ctx->sockfd = -1;

		free(session_data->app_ctx);
	}

	nghttp2_session_del(session_data->session);

	free(session_data);
}

/*
 * Serialize the frame and send (or buffer) the data to
 * bufferevent.
 */
static int
session_send(http2_session_data *session_data) {

	/*Variable*/
	int rv;

	/*Force sending*/
	rv = nghttp2_session_send(session_data->session);	//calling: send_callback()

	/*Check for errors*/
	if (rv != 0)
	{
		warnx("Fatal error 3 http: %s", nghttp2_strerror(rv));
		return -1;
	}

	return 0;
}

/* 
 * session_recv - receive data from client for an established HTTP/2 session
 */
static int
session_recv(http2_session_data *session_data, uint8_t *data, size_t len) {

	/*Variables*/
	nghttp2_ssize readlen;

	/*Trigger: Get and set data from recv and send queue*/
	readlen = nghttp2_session_mem_recv2(session_data->session, data, len);
	if (readlen < 0)
	{
		warnx("Fatal error 1 http: %s", nghttp2_strerror((int)readlen));
		return -1;
	}

	if (session_send(session_data) != 0)
	{
		return -1;
	}

	return 0;
}

/*
 * send_callback - write data to network 
 */
static nghttp2_ssize
send_callback(nghttp2_session *session, const uint8_t *data, size_t length, int flags, void *user_data)
{
	/*Variables*/
	http2_session_data *session_data = (http2_session_data *)user_data;
	(void)session;
	(void)flags;
	int ret = 0;
	size_t len = length;

	/*Close connection*/
	if (nghttp2_session_want_read(session_data->session) == 0 && nghttp2_session_want_write(session_data->session) == 0)
	{
		delete_http2_session_data(session_data);
		pthread_exit(NULL);
	}

again:
	len -= ret;
	/*Write data to client using the established TLS connection*/
	if((ret = SSL_write(session_data->app_ctx->ssl, data, len)) != len)
	{
		switch(SSL_get_error(session_data->app_ctx->ssl, ret))
		{
			case SSL_ERROR_NONE:
				goto again;

			/*Connection was closed by the client*/
			case SSL_ERROR_ZERO_RETURN:
				delete_http2_session_data(session_data);
				pthread_exit(NULL);

			default:
				return NGHTTP2_ERR_WOULDBLOCK;
		}
	}

	return (nghttp2_ssize)length;
}

/*
 * on_begin_headers_callback - callback that is invoked while a HEADER frame is received
 */
static int
on_begin_headers_callback(nghttp2_session *session, const nghttp2_frame *frame, void *user_data)
{
	/*Variables*/
	http2_session_data *session_data = (http2_session_data *)user_data;
	http2_stream_data *stream_data;

	/*Focus: HEADERS frame*/
	if (frame->hd.type != NGHTTP2_HEADERS || frame->headers.cat != NGHTTP2_HCAT_REQUEST)
	{
		return 0;
	}
	
	/*Store header data (stream_data) referenced by stream ID*/
	stream_data = create_http2_stream_data(session_data, frame->hd.stream_id);
	nghttp2_session_set_stream_user_data(session, frame->hd.stream_id, stream_data);

	return 0;
}

/*
 * on_data_recv_callback - callback that is invoked when a DATA frame is received
 */
static int
on_data_recv_callback(nghttp2_session *session, uint8_t flags, int32_t stream_id, const uint8_t *data, size_t len, void *user_data)
{
	http2_stream_data *stream_data = 0;
	uint8_t *tmp = 0, *prev = 0;

	/*Store data (stream_data) referenced by stream ID*/
	if((stream_data = nghttp2_session_get_stream_user_data(session, stream_id)) == NULL)
	{
		return 0;
	}

	/*
	 * Allocate memory and copy data
	 *
	 * NOTE: If multiple DATA frames are received, the memory has to be reallocated and concatenated.
	 */
	if(!stream_data->data)
	{
		if((stream_data->data = (uint8_t*) calloc(len, sizeof(uint8_t))) == NULL)
		{
			return 0;
		}
		memcpy(stream_data->data, data, len);
		stream_data->size = len;
	}
	else
	{
		if((tmp = (uint8_t*) calloc(len + stream_data->size, sizeof(uint8_t))) == NULL)
		{
			return 0;
		}
		memcpy(tmp, stream_data->data, stream_data->size);
		memcpy(tmp + stream_data->size, data, len);
		prev = stream_data->data;
		stream_data->data = tmp;
		stream_data->size += len;
		
		/*Free old memory allocation from heap*/
		free(prev);
	}

	return 0;
}

/*
 * on_stream_close_callback - free memory for a closed stream
 */
static int
on_stream_close_callback(nghttp2_session *session, int32_t stream_id, uint32_t error_code, void *user_data)
{
	/*Variables*/
	http2_session_data *session_data = (http2_session_data *)user_data;
	http2_stream_data *stream_data;
	(void)error_code;

	stream_data = nghttp2_session_get_stream_user_data(session, stream_id);
	if (!stream_data)
	{
		return 0;
	}
	remove_stream(session_data, stream_data);
	delete_http2_stream_data(stream_data);
	
	return 0;
}

/*
 * initialize_nghttp2_session - set up the server and its callback functions
 */
static void
initialize_nghttp2_session(http2_session_data *session_data)
{

	/*Variable*/
	nghttp2_session_callbacks *callbacks;

	/*Initialize callback data structure*/
	nghttp2_session_callbacks_new(&callbacks);

	/*
	 * Set callbacks for different purposes:
	 *
	 * send_callback:--
	 * on_frame_recv_callback: needed, frame completely received
	 * on_stream_close callback: --
	 * on_header callback: needed, invoked for each header key-value pair
	 * on_begin_headers callback: needed, invoked when a HEADER frame was received
	 */
	nghttp2_session_callbacks_set_send_callback2(callbacks, send_callback);
	nghttp2_session_callbacks_set_on_frame_recv_callback(callbacks, session_data->app_ctx->cb->on_frame_recv_callback); //get callback function from caller of the HTTP/2 server
	nghttp2_session_callbacks_set_on_stream_close_callback(callbacks, on_stream_close_callback);
	nghttp2_session_callbacks_set_on_header_callback(callbacks, session_data->app_ctx->cb->on_header_callback); //get callback function from caller of the HTTP/2 server
	nghttp2_session_callbacks_set_on_begin_headers_callback(callbacks, on_begin_headers_callback);
	nghttp2_session_callbacks_set_on_data_chunk_recv_callback(callbacks, on_data_recv_callback);

	/*Set up nghttp2 session by using defined callback functions*/
	nghttp2_session_server_new(&session_data->session, callbacks, session_data);

	/*Free memory*/
	nghttp2_session_callbacks_del(callbacks);
}

/*
 * send_server_connection_header - send HTTP/2 client connection header, which includes 24 bytes magic octets and SETTINGS frame
 */
static int
send_server_connection_header(http2_session_data *session_data)
{
	/*Variables*/
	int rv;
	nghttp2_settings_entry iv[1] = {{NGHTTP2_SETTINGS_MAX_CONCURRENT_STREAMS, 256}};
	
	/*Queue SETTIGNS frame for transmission*/
	rv = nghttp2_submit_settings(session_data->session, NGHTTP2_FLAG_NONE, iv, ARRLEN(iv));
	
	/*Error check*/
	if (rv != 0) {
		warnx("Fatal error 2 http: %s", nghttp2_strerror(rv));
		return -1;
	}
    
    return 0;
}

/*
 * handle_client - handle client HTTP/2 request
 */
static void
handle_client(void *data)
{
	/*Variables*/
	volatile int ret, max;
	struct pollfd pfd = {0};
	uint8_t buf[RECV_DATA_MAX] = {0};
	http2_session_data *session_data = 0;
	const unsigned char *alpn = NULL;
	unsigned int alpnlen = 0;
	pthpool_data_t *tpinfo = (pthpool_data_t*) data;
	pthpool_t *src = 0;

	if(!tpinfo || (session_data = (http2_session_data*) tpinfo->arg) == NULL || (session_data->app_ctx->tpool = tpinfo->pool) == NULL)
	{
		return;
	}

	/*Store old thread pool reference*/
	src = session_data->app_ctx->tpool[0];

	/*HTTP/2 negotiation*/
#ifdef DEBUG
	fprintf(stderr, "%s connected\n", session_data->client_addr);
#endif
	SSL_get0_alpn_selected(session_data->app_ctx->ssl, &alpn, &alpnlen);

	/*Error: Closing connection*/
	if (alpn == NULL || alpnlen != 2 || memcmp("h2", alpn, 2) != 0)
	{
		fprintf(stderr, "%s h2 is not negotiated\n", session_data->client_addr);
		goto end;
	}

	/*Initialize HTTP/2 session and set its callback functions*/
	initialize_nghttp2_session(session_data);

	/*Initialize connection preface (SETTINGS FRAME) + sending via session_send()*/
	if (send_server_connection_header(session_data) != 0 || session_send(session_data) != 0)
	{
		goto end;
	}

	/*Setting connected TCP socket in non blocking mode*/
	if(fcntl(session_data->app_ctx->sockfd, F_SETFL, fcntl(session_data->app_ctx->sockfd, F_GETFL, 0) | O_NONBLOCK) < 0)
	{
		perror("fcntl()");
		goto end;
	}

	/*
	 * Waiting loop for incoming data from client
	 */
	while(1)
	{
		/*Reset maximum number of bytes that can be read*/
		max = RECV_DATA_MAX;

		pfd.fd = session_data->app_ctx->sockfd;
		pfd.events = POLLIN;

		/*Monitor the connected socket file descriptor*/
		if((ret = poll(&pfd, 1, 1000)) <= 0)
		{
			/*Interrupted by a signal*/
			if(errno == EINTR)
			{
				continue;
			}
			goto end;
		}

again:
		/*Reading encoded NGAP data from socket*/
		if((ret=SSL_read(session_data->app_ctx->ssl, buf, max-ret)) <= 0)
		{
			if(!ret)
			{
				//printf("Connection was closed by client!\n");
				goto end;
			}
			else
			{
				ret = 0;
				goto again;
			}
		}
		max -= ret;

		if(session_recv(session_data, buf, RECV_DATA_MAX - max) != 0)
		{
			break;
		}
	}

end:
	/*Thread pool migration detection test*/
	if(src != session_data->app_ctx->tpool[0])
	{
#ifndef RESEARCH
		printf("[http2] Thread pool migration detected: %p -> %p\n", src, session_data->app_ctx->tpool[0]);
#endif
		/*Terminate thread, if no jobs are in its new thread pool*/
		pthread_mutex_lock(&(session_data->app_ctx->tpool[0]->lock));
		if(session_data->app_ctx->tpool[0]->first == NULL && session_data->app_ctx->tpool[0]->thr_cnt > 0)
		{
			session_data->app_ctx->tpool[0]->thr_cnt--;
			session_data->app_ctx->tpool[0]->process_cnt--;
			pthread_mutex_unlock(&(session_data->app_ctx->tpool[0]->lock));
#ifndef RESEARCH
			printf("[http2] Thread removed from its thread pool %p\n", session_data->app_ctx->tpool[0]);
#endif
			/*Finally: close connection by server*/
			delete_http2_session_data(session_data);

			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&(session_data->app_ctx->tpool[0]->lock));
	}

	/*Finally: close connection by server*/
	delete_http2_session_data(session_data);

	return;
}

/*
 * start_http2server - server initialization + server loop
 */
void
start_http2server(const char *ip_addr, uint16_t port, const char *key_file, const char *cert_file, http2_cb_data_t *cbs, pthpool_t *tpool)
{
	/*Variables*/
	SSL_CTX *ssl_ctx = 0;
	app_context app_ctx;
	struct sockaddr_in srvaddr, cliaddr;
	int sockfd, cfd;
	const int enable = 1;

	http2_session_data *session_data;

	/*Check if passed parameters are valid*/
	if(!cbs->on_frame_recv_callback || !cbs->on_header_callback || !tpool || !tpool->thr_cnt)
	{
		printf("Callback functions or thread pool are not initialized...\n");
		return;
	}

	/*Create TCP socket*/
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket()");
		return;
	}

	/*Enable reuse of target socket address structure*/
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
	{
		perror("setsockopt()");
		return;
	}

	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)) < 0)
	{
		perror("setsockopt()");
		return;
	}

	/*Initialize and bind server address structure to socket*/
	memset(&srvaddr, 0, sizeof(srvaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(port);
	srvaddr.sin_addr.s_addr = inet_addr(ip_addr);

	if(bind(sockfd, (struct sockaddr*)&srvaddr, sizeof(srvaddr)) < 0)
	{
		perror("bind()");
		return;
	}

	/*Transition socket to listen state*/
	if(listen(sockfd, 5) < 0)
	{
		perror("listen()");
		return;
	}

	/*Initialize data structures*/
	if((ssl_ctx = create_ssl_ctx(key_file, cert_file)) == NULL)
	{
		return;
	}
	memset(&app_ctx, 0, sizeof(app_context));
	app_ctx.ssl_ctx = ssl_ctx;
	app_ctx.cb = cbs;

	/*Server loop*/
	while(1)
	{
		memset(&cliaddr, 0, sizeof(cliaddr));
		unsigned int len = sizeof(cliaddr);

		/*Waiting for next client request*/
		if((cfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len)) < 0)
		{
			perror("accept()");
			continue;
		}

		/*Create HTTP/2 session*/
		if((session_data = create_http2_session_data(&app_ctx, cfd, (struct sockaddr*)&cliaddr, len)) == NULL)
		{
			close(cfd);
			continue;
		}

		/*Adding the client request to the POSIX thread pool*/
		if(!pthpool_add_job(tpool, handle_client, session_data))
		{
			printf("[http2] Client request couldn't be added to the target thread pool\n");
			delete_http2_session_data(session_data);
		}
	}

	/*Free memory*/
	SSL_CTX_free(ssl_ctx);

	return;
}
