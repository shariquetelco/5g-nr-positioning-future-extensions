/*
 * ntn_tai_info.h
 *
 *
 */

#ifndef _ntn_tai_info_H_
#define _ntn_tai_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id_nid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ntn_tai_info_s ntn_tai_info_t;
typedef struct ntn_tai_info_s {
	struct plmn_id_nid_s *plmn_id;
	list_t *tac_list;
	char *derived_tac;
} ntn_tai_info_t;

ntn_tai_info_t *ntn_tai_info_create(plmn_id_nid_t *plmn_id, list_t *tac_list,
                                    char *derived_tac);
void ntn_tai_info_free(ntn_tai_info_t *ntn_tai_info);
ntn_tai_info_t *ntn_tai_info_parseFromJSON(cJSON *ntn_tai_infoJSON);
cJSON *ntn_tai_info_convertToJSON(ntn_tai_info_t *ntn_tai_info);
ntn_tai_info_t *ntn_tai_info_copy(ntn_tai_info_t *dst, ntn_tai_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ntn_tai_info_H_ */
