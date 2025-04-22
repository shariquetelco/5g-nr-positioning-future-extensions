/*
 * n1_n2_message_transfer_rsp_data.h
 *
 * Data within a N1/N2 message transfer response
 */

#ifndef _n1_n2_message_transfer_rsp_data_H_
#define _n1_n2_message_transfer_rsp_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n1_n2_message_transfer_cause.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n1_n2_message_transfer_rsp_data_s
        n1_n2_message_transfer_rsp_data_t;
typedef struct n1_n2_message_transfer_rsp_data_s {
	n1_n2_message_transfer_cause_e cause;
	char *supported_features;
} n1_n2_message_transfer_rsp_data_t;

n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data_create(
	n1_n2_message_transfer_cause_e cause, char *supported_features);
void n1_n2_message_transfer_rsp_data_free(
	n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data);
n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data_parseFromJSON(
	cJSON *n1_n2_message_transfer_rsp_dataJSON);
cJSON *n1_n2_message_transfer_rsp_data_convertToJSON(
	n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data);
n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data_copy(
	n1_n2_message_transfer_rsp_data_t	*dst,
	n1_n2_message_transfer_rsp_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _n1_n2_message_transfer_rsp_data_H_ */
