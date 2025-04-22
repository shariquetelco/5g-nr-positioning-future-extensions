/*
 * nid_info.h
 *
 * contains NIDs.
 */

#ifndef _nid_info_H_
#define _nid_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nid_info_s nid_info_t;
typedef struct nid_info_s {
	list_t *nid_list;
} nid_info_t;

nid_info_t *nid_info_create(list_t *nid_list);
void nid_info_free(nid_info_t *nid_info);
nid_info_t *nid_info_parseFromJSON(cJSON *nid_infoJSON);
cJSON *nid_info_convertToJSON(nid_info_t *nid_info);
nid_info_t *nid_info_copy(nid_info_t *dst, nid_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nid_info_H_ */
