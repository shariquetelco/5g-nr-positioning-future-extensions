/*
 * npn_access_info.h
 *
 * NPN Access Information.
 */

#ifndef _npn_access_info_H_
#define _npn_access_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct npn_access_info_s npn_access_info_t;
typedef struct npn_access_info_s {
	list_t *cell_cag_info;
} npn_access_info_t;

npn_access_info_t *npn_access_info_create(list_t *cell_cag_info);
void npn_access_info_free(npn_access_info_t *npn_access_info);
npn_access_info_t *npn_access_info_parseFromJSON(cJSON *npn_access_infoJSON);
cJSON *npn_access_info_convertToJSON(npn_access_info_t *npn_access_info);
npn_access_info_t *npn_access_info_copy(npn_access_info_t	*dst,
                                        npn_access_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _npn_access_info_H_ */
