/*
 * ref_to_binary_data.h
 *
 * This parameter provides information about the referenced binary body data.
 */

#ifndef _ref_to_binary_data_H_
#define _ref_to_binary_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ref_to_binary_data_s ref_to_binary_data_t;
typedef struct ref_to_binary_data_s {
	char *content_id;
} ref_to_binary_data_t;

ref_to_binary_data_t *ref_to_binary_data_create(char *content_id);
void ref_to_binary_data_free(ref_to_binary_data_t *ref_to_binary_data);
ref_to_binary_data_t *ref_to_binary_data_parseFromJSON(
	cJSON *ref_to_binary_dataJSON);
cJSON *ref_to_binary_data_convertToJSON(
	ref_to_binary_data_t *ref_to_binary_data);
ref_to_binary_data_t *ref_to_binary_data_copy(ref_to_binary_data_t	*dst,
                                              ref_to_binary_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ref_to_binary_data_H_ */
