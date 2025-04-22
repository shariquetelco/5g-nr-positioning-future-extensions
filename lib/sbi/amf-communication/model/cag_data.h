/*
 * cag_data.h
 *
 *
 */

#ifndef _cag_data_H_
#define _cag_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "cag_info.h"
#include "conditional_cag_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cag_data_s cag_data_t;
typedef struct cag_data_s {
	list_t *cag_infos;
	list_t *conditional_cag_infos;
	char *provisioning_time;
} cag_data_t;

cag_data_t *cag_data_create(list_t *cag_infos, list_t *conditional_cag_infos,
                            char *provisioning_time);
void cag_data_free(cag_data_t *cag_data);
cag_data_t *cag_data_parseFromJSON(cJSON *cag_dataJSON);
cJSON *cag_data_convertToJSON(cag_data_t *cag_data);
cag_data_t *cag_data_copy(cag_data_t *dst, cag_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _cag_data_H_ */
