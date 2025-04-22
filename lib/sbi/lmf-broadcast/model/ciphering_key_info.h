/*
 * ciphering_key_info.h
 *
 * Information within Ciphering Key Data Notification request.
 */

#ifndef _ciphering_key_info_H_
#define _ciphering_key_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ciphering_data_set.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ciphering_key_info_s ciphering_key_info_t;
typedef struct ciphering_key_info_s {
	list_t *ciphering_data;
	char *supported_features;
} ciphering_key_info_t;

ciphering_key_info_t *ciphering_key_info_create(list_t	*ciphering_data,
                                                char	*supported_features);
void ciphering_key_info_free(ciphering_key_info_t *ciphering_key_info);
ciphering_key_info_t *ciphering_key_info_parseFromJSON(
	cJSON *ciphering_key_infoJSON);
cJSON *ciphering_key_info_convertToJSON(
	ciphering_key_info_t *ciphering_key_info);
ciphering_key_info_t *ciphering_key_info_copy(ciphering_key_info_t	*dst,
                                              ciphering_key_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ciphering_key_info_H_ */
