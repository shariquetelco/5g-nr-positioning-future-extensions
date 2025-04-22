/*C standard library headers*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#ifndef __sgi
#  include <err.h>
#endif
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>

/*POSIX thread pool header*/
#include <pthpool.h>

/*OpenSSL headers*/
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/conf.h>

/*libnghttp2 headers*/
#define NGHTTP2_NO_SSIZE_T
#include <nghttp2/nghttp2.h>

#ifndef _NGHTTP2SRV_H_
#define _NGHTTP2SRV_H_

/*
 * Macros
 */
#define OUTPUT_WOULDBLOCK_THRESHOLD (1 << 16)

#define ARRLEN(x) (sizeof(x) / sizeof(x[0]))

#define MAKE_NV(NAME, VALUE)                                                   \
{                                                                            \
    (uint8_t *)NAME, (uint8_t *)VALUE, sizeof(NAME) - 1, sizeof(VALUE) - 1,    \
        NGHTTP2_NV_FLAG_NONE                                                   \
}

#ifdef __sgi
#define errx(exitcode, format, args...)                                      \
{                                                                          \
	warnx(format, ##args);                                                   \
	exit(exitcode);                                                          \
}
#define warn(format, args...) warnx(format ": %s", ##args, strerror(errno))
#define warnx(format, args...) fprintf(stderr, format "\n", ##args)
#endif

/*
 * HTTP error code cause strings according to 3GPP TS 29.500, Table 5.2.7.2-1
 */
#define HTTP_400_INVAPI "INVALID_API"
#define HTTP_400_INVFORM "INVALID_MSG_FORMAT"
#define HTTP_400_INVURL "INVALID_QUERY_PARAM"
#define HTTP_400_MANIEINC "MANDATORY_IE_INCORRECT"
#define HTTP_400_MANIEMIS "MANDATORY_IE_MISSING"
#define HTTP_400_OPTIEINC "OPTIONAL_IE_INCORRECT"
#define HTTP_400_UNSPEMSG "UNSPECIFIED_MSG_FAILURE"
#define HTTP_403_POSDENIED "POSITIONING_DENIED"
#define HTTP_404_SUBNOFND "SUBSCRIPTION_NOT_FOUND"
#define HTTP_411_INCLENG "INCORRECT_LENGTH"
#define HTTP_500_UNSPEC "UNSPECIFIED_NF_FAILURE"
#define HTTP_500_SYSFAIL "SYSTEM_FAILURE"

#define RECV_DATA_MAX 131072

/*
 * Data structures
 *
 * @http2_cb_data_t: enable caller of start_http2server() to set its own callback functions for HEADERS and DATA frames (added by NK)
 */
struct app_context;
typedef struct app_context app_context;

typedef struct http2_cb_data
{
	int (*on_frame_recv_callback)(nghttp2_session *session, const nghttp2_frame *frame, void *user_data);
	int (*on_header_callback)(nghttp2_session *session, const nghttp2_frame *frame, const uint8_t *name, size_t namelen, const uint8_t *value, size_t valuelen, uint8_t flags, void *user_data);
} http2_cb_data_t;

typedef struct http2_stream_data
{
	struct http2_stream_data *prev, *next;
	char *request_path; /*HTTP2 header field :path*/
	char *user_agent; /*HTTP2 header field :user*/
	char *method; /*HTTP2 header field :method*/
	char *accept; /*HTTP header field accept:*/
	char *ctype; /*HTTP header field content-type*/
	uint32_t clength; /*HTTP header field content-length*/
	uint8_t *data; /*Payload data*/
	size_t size; /*Payload data size [B]*/
	int32_t stream_id;
} http2_stream_data;

typedef struct http2_session_data
{
	struct http2_stream_data root;
	app_context *app_ctx;
	nghttp2_session *session;
	char *client_addr;
} http2_session_data;

struct app_context
{
	SSL_CTX *ssl_ctx;
	SSL *ssl;
	http2_cb_data_t *cb;
	int sockfd;
	pthpool_t **tpool;
};

/*
 * http_list - linked list to store HTTP header fields from a HTTP/2 response
 */
struct http_list
{
	struct http_entry *first, *last;
	uint64_t cnt;
};

/*
 * http_entry - entry in linked http_list
 */
struct http_entry
{
	char *data;
	struct http_entry *next;
};

/*
 * start_http2server - server initialization + server loop
 */
void start_http2server(const char *ip_addr, uint16_t port, const char *key_file, const char *cert_file, http2_cb_data_t *cb, pthpool_t *tpool);

/*
 * HTTP header list: helper function(s)
 */
void freeHTTPList(struct http_list *list);

#endif
