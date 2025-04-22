/*
 * n2_information_transfer_error.h
 *
 * Data within a failure response for a non-UE related N2 Information Transfer
 */

#ifndef _n2_information_transfer_error_H_
#define _n2_information_transfer_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "problem_details.h"
#include "pws_error_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n2_information_transfer_error_s n2_information_transfer_error_t;
typedef struct n2_information_transfer_error_s {
	struct problem_details_s *error;
	struct pws_error_data_s *pws_error_info;
} n2_information_transfer_error_t;

n2_information_transfer_error_t *n2_information_transfer_error_create(
	problem_details_t *error, pws_error_data_t *pws_error_info);
void n2_information_transfer_error_free(
	n2_information_transfer_error_t *n2_information_transfer_error);
n2_information_transfer_error_t *n2_information_transfer_error_parseFromJSON(
	cJSON *n2_information_transfer_errorJSON);
cJSON *n2_information_transfer_error_convertToJSON(
	n2_information_transfer_error_t *n2_information_transfer_error);
n2_information_transfer_error_t *n2_information_transfer_error_copy(
	n2_information_transfer_error_t *dst,
	n2_information_transfer_error_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _n2_information_transfer_error_H_ */
