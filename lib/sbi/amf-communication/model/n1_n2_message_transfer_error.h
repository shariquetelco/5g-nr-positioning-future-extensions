/*
 * n1_n2_message_transfer_error.h
 *
 * Data within a N1/N2 Message Transfer Error response
 */

#ifndef _n1_n2_message_transfer_error_H_
#define _n1_n2_message_transfer_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n1_n2_msg_txfr_err_detail.h"
#include "problem_details.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n1_n2_message_transfer_error_s n1_n2_message_transfer_error_t;
typedef struct n1_n2_message_transfer_error_s {
	struct problem_details_s *error;
	struct n1_n2_msg_txfr_err_detail_s *err_info;
} n1_n2_message_transfer_error_t;

n1_n2_message_transfer_error_t *n1_n2_message_transfer_error_create(
	problem_details_t *error, n1_n2_msg_txfr_err_detail_t *err_info);
void n1_n2_message_transfer_error_free(
	n1_n2_message_transfer_error_t *n1_n2_message_transfer_error);
n1_n2_message_transfer_error_t *n1_n2_message_transfer_error_parseFromJSON(
	cJSON *n1_n2_message_transfer_errorJSON);
cJSON *n1_n2_message_transfer_error_convertToJSON(
	n1_n2_message_transfer_error_t *n1_n2_message_transfer_error);
n1_n2_message_transfer_error_t *n1_n2_message_transfer_error_copy(
	n1_n2_message_transfer_error_t	*dst,
	n1_n2_message_transfer_error_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _n1_n2_message_transfer_error_H_ */
