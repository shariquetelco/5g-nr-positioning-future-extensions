#ifndef _SCTPCLI_H_
#define _SCTPCLI_H_

#include <ngap/ngap_create.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/sctp.h>
#include <unistd.h>


#define SCTP_MAX_OUT 256
#define SCTP_MAX_IN 256
#define RECV_MAX 1024

/*
 * sctpcli - management of SCTP streams list
 *
 * @num_in: number of available input streams
 * @num_out: number of available output streams
 * @in, @out: POSIX thread mutex to access stream lists
 * @in_list: SCTP stream ID list for input
 * @out_list: SCTP stream ID list for output
 */
typedef struct sctpcli
{
	uint16_t num_in;
	uint16_t num_out;
	pthread_mutex_t in, out;
	int in_list[SCTP_MAX_IN][2];
	int out_list[SCTP_MAX_OUT];
} sctpcli_t;

/*
 * SCTP connection management functions
 */
int initsctpcli(sctpcli_t *con, uint16_t num_in, uint16_t num_out);
void freesctpcli(sctpcli_t *con);
int sctpcli(int fd, sctpcli_t *con, bool isClOne, uint8_t *in, size_t size_in, ngapmsg_t **msg);
bool isReserved(sctpcli_t *con, uint16_t id);

#endif
