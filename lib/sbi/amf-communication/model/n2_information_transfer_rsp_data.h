/*
 * n2_information_transfer_rsp_data.h
 *
 * Data within a successful response to the N2 Information Transfer request to transfer N2 Information to the AN
 */

#ifndef _n2_information_transfer_rsp_data_H_
#define _n2_information_transfer_rsp_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_information_transfer_result.h"
#include "pws_response_data.h"
#include "tss_rsp_per_ngran.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n2_information_transfer_rsp_data_s
        n2_information_transfer_rsp_data_t;
typedef struct n2_information_transfer_rsp_data_s {
	n2_information_transfer_result_e result;
	struct pws_response_data_s *pws_rsp_data;
	char *supported_features;
	list_t *tss_rsp_per_ngran_list;
} n2_information_transfer_rsp_data_t;

n2_information_transfer_rsp_data_t *n2_information_transfer_rsp_data_create(
	n2_information_transfer_result_e result,
	pws_response_data_t *pws_rsp_data, char *supported_features,
	list_t *tss_rsp_per_ngran_list);
void n2_information_transfer_rsp_data_free(
	n2_information_transfer_rsp_data_t *n2_information_transfer_rsp_data);
n2_information_transfer_rsp_data_t *
n2_information_transfer_rsp_data_parseFromJSON(
	cJSON *n2_information_transfer_rsp_dataJSON);
cJSON *n2_information_transfer_rsp_data_convertToJSON(
	n2_information_transfer_rsp_data_t *n2_information_transfer_rsp_data);
n2_information_transfer_rsp_data_t *n2_information_transfer_rsp_data_copy(
	n2_information_transfer_rsp_data_t	*dst,
	n2_information_transfer_rsp_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _n2_information_transfer_rsp_data_H_ */
