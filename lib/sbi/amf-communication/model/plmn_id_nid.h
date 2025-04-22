/*
 * plmn_id_nid.h
 *
 * Contains the serving core network operator PLMN ID and, for an SNPN, the NID that together with the PLMN ID identifies the SNPN.
 */

#ifndef _plmn_id_nid_H_
#define _plmn_id_nid_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct plmn_id_nid_s plmn_id_nid_t;
typedef struct plmn_id_nid_s {
	char *mcc;
	char *mnc;
	char *nid;
} plmn_id_nid_t;

plmn_id_nid_t *plmn_id_nid_create(char *mcc, char *mnc, char *nid);
void plmn_id_nid_free(plmn_id_nid_t *plmn_id_nid);
plmn_id_nid_t *plmn_id_nid_parseFromJSON(cJSON *plmn_id_nidJSON);
cJSON *plmn_id_nid_convertToJSON(plmn_id_nid_t *plmn_id_nid);
plmn_id_nid_t *plmn_id_nid_copy(plmn_id_nid_t *dst, plmn_id_nid_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _plmn_id_nid_H_ */
