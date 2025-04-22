/*
 * guami.h
 *
 * Globally Unique AMF Identifier constructed out of PLMN, Network and AMF identity.
 */

#ifndef _guami_H_
#define _guami_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id_nid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct guami_s guami_t;
typedef struct guami_s {
	struct plmn_id_nid_s *plmn_id;
	char *amf_id;
} guami_t;

guami_t *guami_create(plmn_id_nid_t *plmn_id, char *amf_id);
void guami_free(guami_t *guami);
guami_t *guami_parseFromJSON(cJSON *guamiJSON);
cJSON *guami_convertToJSON(guami_t *guami);
guami_t *guami_copy(guami_t *dst, guami_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _guami_H_ */
