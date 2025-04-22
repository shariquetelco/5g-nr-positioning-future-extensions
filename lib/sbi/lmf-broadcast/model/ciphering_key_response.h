/*
 * ciphering_key_response.h
 *
 * Information within Ciphering Key Data Notification Response.
 */

#ifndef _ciphering_key_response_H_
#define _ciphering_key_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ciphering_set_report.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ciphering_key_response_s ciphering_key_response_t;
typedef struct ciphering_key_response_s {
	list_t *ciphering_data_report;
} ciphering_key_response_t;

ciphering_key_response_t *ciphering_key_response_create(
	list_t *ciphering_data_report);
void ciphering_key_response_free(
	ciphering_key_response_t *ciphering_key_response);
ciphering_key_response_t *ciphering_key_response_parseFromJSON(
	cJSON *ciphering_key_responseJSON);
cJSON *ciphering_key_response_convertToJSON(
	ciphering_key_response_t *ciphering_key_response);
ciphering_key_response_t *ciphering_key_response_copy(
	ciphering_key_response_t *dst, ciphering_key_response_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ciphering_key_response_H_ */
