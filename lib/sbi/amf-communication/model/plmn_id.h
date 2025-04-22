/*
 * plmn_id.h
 *
 * When PlmnId needs to be converted to string (e.g. when used in maps as key), the string  shall be composed of three digits \&quot;mcc\&quot; followed by \&quot;-\&quot; and two or three digits \&quot;mnc\&quot;.
 */

#ifndef _plmn_id_H_
#define _plmn_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct plmn_id_s plmn_id_t;
typedef struct plmn_id_s {
	char *mcc;
	char *mnc;
} plmn_id_t;

plmn_id_t *plmn_id_create(char *mcc, char *mnc);
void plmn_id_free(plmn_id_t *plmn_id);
plmn_id_t *plmn_id_parseFromJSON(cJSON *plmn_idJSON);
cJSON *plmn_id_convertToJSON(plmn_id_t *plmn_id);
plmn_id_t *plmn_id_copy(plmn_id_t *dst, plmn_id_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _plmn_id_H_ */
