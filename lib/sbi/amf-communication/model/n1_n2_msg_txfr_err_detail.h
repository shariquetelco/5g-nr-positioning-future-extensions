/*
 * n1_n2_msg_txfr_err_detail.h
 *
 * N1/N2 Message Transfer Error Details
 */

#ifndef _n1_n2_msg_txfr_err_detail_H_
#define _n1_n2_msg_txfr_err_detail_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "arp.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n1_n2_msg_txfr_err_detail_s n1_n2_msg_txfr_err_detail_t;
typedef struct n1_n2_msg_txfr_err_detail_s {
	bool is_retry_after;
	int retry_after;
	struct arp_s *highest_prio_arp;
	bool is_max_waiting_time;
	int max_waiting_time;
} n1_n2_msg_txfr_err_detail_t;

n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail_create(
	bool is_retry_after, int retry_after, arp_t *highest_prio_arp,
	bool is_max_waiting_time, int max_waiting_time);
void n1_n2_msg_txfr_err_detail_free(
	n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail);
n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail_parseFromJSON(
	cJSON *n1_n2_msg_txfr_err_detailJSON);
cJSON *n1_n2_msg_txfr_err_detail_convertToJSON(
	n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail);
n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail_copy(
	n1_n2_msg_txfr_err_detail_t *dst, n1_n2_msg_txfr_err_detail_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _n1_n2_msg_txfr_err_detail_H_ */
