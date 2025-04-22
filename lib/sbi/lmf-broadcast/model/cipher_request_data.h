/*
 * cipher_request_data.h
 *
 * Information within Ciphering Key Data request.
 */

#ifndef _cipher_request_data_H_
#define _cipher_request_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cipher_request_data_s cipher_request_data_t;
typedef struct cipher_request_data_s {
	char *amf_call_back_uri;
	char *supported_features;
} cipher_request_data_t;

cipher_request_data_t *cipher_request_data_create(char	*amf_call_back_uri,
                                                  char	*supported_features);
void cipher_request_data_free(cipher_request_data_t *cipher_request_data);
cipher_request_data_t *cipher_request_data_parseFromJSON(
	cJSON *cipher_request_dataJSON);
cJSON *cipher_request_data_convertToJSON(
	cipher_request_data_t *cipher_request_data);
cipher_request_data_t *cipher_request_data_copy(cipher_request_data_t	*dst,
                                                cipher_request_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _cipher_request_data_H_ */
