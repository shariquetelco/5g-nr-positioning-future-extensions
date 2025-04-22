#include "sctpcli.h"

/*
 * initsctpcli - set up SCTP stream ID lists and its mutex
 *
 * @con: target SCTP connection
 * @num_in: number of available input streams
 * @num_out: number of available output streams
 *
 * return: 0 on success, -1 otherwise
 */
int
initsctpcli(sctpcli_t *con, uint16_t num_in, uint16_t num_out)
{
	pthread_mutexattr_t attr;

	/*Check passed input parameter*/
	if(!con || !num_in || !num_out)
	{
		return -1;
	}
#ifdef DEBUG
	/*Initialize POSIX thread mutex attributes*/
	if(pthread_mutexattr_init(&attr) != 0)
	{
		perror("pthread_mutexattr_init()");
		return -1;
	}

	if(pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT) != 0)
	{
		pthread_mutexattr_destroy(&attr);
		perror("pthread_mutexattr_setprotocol");
		return -1;
	}
#endif
	/*Initialize stream lists with 0*/
	explicit_bzero(con->in_list, sizeof(con->in_list));
	explicit_bzero(con->out_list, sizeof(con->out_list));

	/*Set number of available I/O streams*/
	con->num_in = num_in;
	con->num_out = num_out;

	/*Initialize POSIX thread mutex*/
	if(pthread_mutex_init(&con->in, NULL) != 0)
	{
		pthread_mutexattr_destroy(&attr);
		perror("pthread_mutex_init()");
		return -1;
	}

	if(pthread_mutex_init(&con->out, NULL) != 0)
	{
		perror("pthread_mutex_init()");
		pthread_mutexattr_destroy(&attr);
		pthread_mutex_destroy(&con->in);
		return -1;
	}

	return 0;
}

/*
 * freesctpcli - free POSIX semaphores of a SCTP connection
 *
 * @con: target SCTP connection
 */
void
freesctpcli(sctpcli_t *con)
{
	pthread_mutex_destroy(&con->in);
	pthread_mutex_destroy(&con->out);
}

bool
isReserved(sctpcli_t *con, uint16_t id)
{
	bool used = false;

	/*Check passed input parameter*/
	if(!con || id >= con->num_in)
	{
		return false;
	}

retry:
	/*Lock input stream list*/
	if(pthread_mutex_lock(&con->in) != 0)
	{
		perror("pthread_mutex_lock()");
		goto retry;
	}

	if(con->in_list[id][0] > 0)
	{
		used = true;
	}

	/*Unlock input stream list*/
	pthread_mutex_unlock(&con->in);

	return used;
}

/*
 * unlockSCTPStream - mark SCTP stream ID(s) as unused
 *
 * @con: target SCTP connection
 * @isClOne: identifier of target procedure class
 * @id: target stream ID that has to be freed.
 */
static void
unlockSCTPStream(sctpcli_t *con, bool isClOne, uint16_t id)
{
	int i;

	/*Check passed input parameter*/
	if(!con || id >= con->num_in || id >= con->num_out)
	{
		return;
	}

	/*
	 * Class 1 procedure: Unlock an used input AND output stream ID
	 */
	if(isClOne)
	{
again:
		/*Lock output stream list*/
		if(pthread_mutex_lock(&con->out) != 0)
		{
			perror("pthread_mutex_lock()");
			goto again;
		}

		con->out_list[id] = 0;

		/*Unlock input stream list*/
		pthread_mutex_unlock(&con->out);

retry:
		/*Lock input stream list*/
		if(pthread_mutex_lock(&con->in) != 0)
		{
			perror("pthread_mutex_lock()");
			goto retry;
		}

		con->in_list[id][0] = 0;
		close(con->in_list[id][1]);

		/*Unlock input stream list*/
		pthread_mutex_unlock(&con->in);
	}

	/*
	 * Class 2 procedure: Unlock an used output stream ID
	 */
	else
	{
agn:
		/*Lock output stream list*/
		if(pthread_mutex_lock(&con->out) != 0)
		{
			perror("pthread_mutex_lock()");
			goto agn;
		}

		con->out_list[id] = 0;

		/*Unlock output stream list*/
		pthread_mutex_unlock(&con->out);
	}

}

/*
 * lockSCTPStream - reserve an unused SCTP stream for data exhcange over the N2 interface
 *
 * @con: target SCTP connection
 * @isClOne: identifier of target procedure class
 * @ufd: stream oriented UNIX Domain socket where the response data has to be passed in.
 *
 * return: output SCTP stream ID on success, ID > SCTP_MAX_OUT otherwise (error detection)
 */
static uint16_t
lockSCTPStream(sctpcli_t *con, bool isClOne, int ufd)
{
	int i;
	uint16_t out = 0;
	bool found = false;

	/*
	 * Class 1 procedure: Lock an unused input AND output stream ID
	 */
	if(isClOne)
	{
		/*Check passed input parameter*/
		if(!con || ufd < 0)
		{
			return SCTP_MAX_OUT + 1;
		}

		/*Lock input stream list*/
		if(pthread_mutex_lock(&con->in) != 0)
		{
			perror("pthread_mutex_lock()");
			return SCTP_MAX_OUT + 1;
		}

		/*Looking for an unused I/O pair*/
		for(i = 0; i < con->num_in && i < con->num_out; i++)
		{
			if(con->in_list[i][0] == 0)
			{
				/*Check if the identical stream ID is unused for output*/
				if(pthread_mutex_lock(&con->out) != 0)
				{
					perror("pthread_mutex_lock()");
					pthread_mutex_unlock(&con->in);
					return SCTP_MAX_OUT + 1;
				}
				
				if(con->out_list[i] == 0)
				{
					found = true;
					con->out_list[i] = 1;
				}
				else
				{
					found = false;
				}
				pthread_mutex_unlock(&con->out);

				/*If stream ID is not unused: Continue*/
				if(!found)
				{
					continue;
				}

				/*Save found stream ID and store the target UNIX Domain socket in the input list*/
				out = i;
				con->in_list[i][0] = 1;
				con->in_list[i][1] = ufd;
				break;
			}
		}
	
		/*Unlock input stream list*/
		pthread_mutex_unlock(&con->in);
	}

	/*
	 * Class 2 procedure: Lock an unused output stream ID
	 */
	else
	{
		/*Check passed input parameter*/
		if(!con)
		{
			return SCTP_MAX_OUT + 1;
		}
		
		/*Lock output stream list*/
		if(pthread_mutex_lock(&con->out) != 0)
		{
			perror("pthread_mutex_lock()");
			return SCTP_MAX_OUT + 1;
		}
		
		/*Looking for an unused output stream*/
		for(i = 0; i < con->num_out; i++)
		{
			if(con->out_list[i] == 0)
			{			
				out = i;
				con->out_list[i] = 1;
				found = true;
				break;
			}
		}
	
		/*Unlock output stream list*/
		pthread_mutex_unlock(&con->out);
	}

	//TODO: Try to find another workaround until a stream ID is free again ;-)
	if(!found)
	{
		return SCTP_MAX_OUT + 1;
	}
	
	return out;
}

/*
 * sctpcli - sending and receiving NGAP data over the N2 interface
 *
 * @sockfd: socket file descriptor of the target
 * @con: reference to the SCTP stream lists
 * @isClone: handling a Class 1 procedure? (if so, a response is expected!)
 * @in: input data (here: ASN.1 PER encoded NGAP message) that has to be sent.
 * @size_in: size [B] of @in
 * @msg: pointer to the decoded NGAP PDU
 *
 * return: 0 on success, -1 otherwise
 *
 * NOTE: It is expected that the receiver of the decoded NGAP message pass the heap reference to the UNIX Domain socket.
 */
int
sctpcli(int sockfd, sctpcli_t *con, bool isClOne, uint8_t *in, size_t size_in, ngapmsg_t **msg)
{
	struct sctp_sndrcvinfo sinfo;
	int ufd[2]; /*[0] == receive, [1] sending*/
	fd_set fds;
	uint8_t buf[RECV_MAX] = {0};
	size_t len = 0;

	/*Check passed input parameter*/
	if(sockfd < 0 || !con || !in || !size_in || (isClOne && !msg))
	{
		return -1;
	}

	explicit_bzero(&sinfo, sizeof(sinfo));

	/*Class 1 procedure*/
	if(isClOne)
	{
		/*Creation of a stream oriented UNIX Domain socket*/
		if(socketpair(AF_UNIX, SOCK_STREAM, 0, ufd) < 0)
		{
			perror("socketpair()");
			return -1;
		}

		/*Looking for an unused SCTP stream ID ...*/
		if((sinfo.sinfo_stream = lockSCTPStream(con, true, ufd[1])) > con->num_out)
		{
			return -1;
		}

		/*Send data to the target*/
		if(sctp_send(sockfd, in, size_in, &sinfo, 0) != size_in)
		{
			unlockSCTPStream(con, true, sinfo.sinfo_stream);
			return -1;
		}

		/*Waiting for response data*/
		FD_ZERO(&fds);

		/*Set target file descriptor to the file descriptor set*/
		FD_SET(ufd[0], &fds);

		/*Monitor the gNB's file descriptor*/
		if(select(ufd[0] + 1, &fds, 0, 0, 0) < 0)
		{
			unlockSCTPStream(con, true, sinfo.sinfo_stream);
			return -1;
		}

		/*Receive response: decoded NGAP PDU*/
		if(recv(ufd[0], msg, sizeof(ngapmsg_t*), MSG_WAITALL) != sizeof(ngapmsg_t*))
		{
			perror("recv()");
			unlockSCTPStream(con, true, sinfo.sinfo_stream);
			return -1;
		}
		
		unlockSCTPStream(con, true, sinfo.sinfo_stream);
	}
	
	/*Class 2 procedure*/
	else
	{
		/*Looking for an unused SCTP stream ID ...*/
		if((sinfo.sinfo_stream = lockSCTPStream(con, false, 0)) > con->num_out)
		{
			return -1;
		}

		/*Send data to the target*/
		if(sctp_send(sockfd, in, size_in, &sinfo, 0) != size_in)
		{
			perror("sctp_send()");
			unlockSCTPStream(con, false, sinfo.sinfo_stream);
			return -1;
		}

		/*Unlock reserved stream ID*/
		unlockSCTPStream(con, false, sinfo.sinfo_stream);
	}

	return 0;
}
