/*
 * cipher_response_data.h
 *
 * Information within Ciphering Key Data Response.
 */

#ifndef _cipher_response_data_H_
#define _cipher_response_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "data_availability.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cipher_response_data_s cipher_response_data_t;
typedef struct cipher_response_data_s {
	data_availability_e data_availability;
} cipher_response_data_t;

cipher_response_data_t *cipher_response_data_create(
	data_availability_e data_availability);
void cipher_response_data_free(cipher_response_data_t *cipher_response_data);
cipher_response_data_t *cipher_response_data_parseFromJSON(
	cJSON *cipher_response_dataJSON);
cJSON *cipher_response_data_convertToJSON(
	cipher_response_data_t *cipher_response_data);
cipher_response_data_t *cipher_response_data_copy(
	cipher_response_data_t	*dst,
	cipher_response_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _cipher_response_data_H_ */
