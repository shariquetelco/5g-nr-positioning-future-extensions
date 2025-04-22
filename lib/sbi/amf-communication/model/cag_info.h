/*
 * cag_info.h
 *
 *
 */

#ifndef _cag_info_H_
#define _cag_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cag_info_s cag_info_t;
typedef struct cag_info_s {
	list_t *allowed_cag_list;
	bool is_cag_only_indicator;
	int cag_only_indicator;
} cag_info_t;

cag_info_t *cag_info_create(list_t *allowed_cag_list,
                            bool is_cag_only_indicator, int cag_only_indicator);
void cag_info_free(cag_info_t *cag_info);
cag_info_t *cag_info_parseFromJSON(cJSON *cag_infoJSON);
cJSON *cag_info_convertToJSON(cag_info_t *cag_info);
cag_info_t *cag_info_copy(cag_info_t *dst, cag_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _cag_info_H_ */
