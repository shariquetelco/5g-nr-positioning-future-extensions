/*
 * cag_info_1.h
 *
 * contains CAG IDs.
 */

#ifndef _cag_info_1_H_
#define _cag_info_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cag_info_1_s cag_info_1_t;
typedef struct cag_info_1_s {
	list_t *cag_list;
} cag_info_1_t;

cag_info_1_t *cag_info_1_create(list_t *cag_list);
void cag_info_1_free(cag_info_1_t *cag_info_1);
cag_info_1_t *cag_info_1_parseFromJSON(cJSON *cag_info_1JSON);
cJSON *cag_info_1_convertToJSON(cag_info_1_t *cag_info_1);
cag_info_1_t *cag_info_1_copy(cag_info_1_t *dst, cag_info_1_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _cag_info_1_H_ */
