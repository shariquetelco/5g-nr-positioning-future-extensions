/*
 * roaming_info.h
 *
 * Information related to roaming analytics.
 */

#ifndef _roaming_info_H_
#define _roaming_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographical_area.h"
#include "plmn_id_nid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct roaming_info_s roaming_info_t;
typedef struct roaming_info_s {
	struct plmn_id_nid_s *plmn_id;
	list_t *aois;
	list_t *serving_nf_ids;
	list_t *serving_nf_set_ids;
} roaming_info_t;

roaming_info_t *roaming_info_create(plmn_id_nid_t *plmn_id, list_t *aois,
                                    list_t *serving_nf_ids,
                                    list_t *serving_nf_set_ids);
void roaming_info_free(roaming_info_t *roaming_info);
roaming_info_t *roaming_info_parseFromJSON(cJSON *roaming_infoJSON);
cJSON *roaming_info_convertToJSON(roaming_info_t *roaming_info);
roaming_info_t *roaming_info_copy(roaming_info_t *dst, roaming_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _roaming_info_H_ */
