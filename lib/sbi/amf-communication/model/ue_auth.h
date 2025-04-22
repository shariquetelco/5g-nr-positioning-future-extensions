/*
 * ue_auth.h
 *
 * Possible values are: - AUTHORIZED: Indicates that the UE is authorized. - NOT_AUTHORIZED: Indicates that the UE is not authorized.
 */

#ifndef _ue_auth_H_
#define _ue_auth_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_auth_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_auth_s ue_auth_t;
typedef struct ue_auth_s {} ue_auth_t;

ue_auth_t *ue_auth_create();
void ue_auth_free(ue_auth_t *ue_auth);
ue_auth_t *ue_auth_parseFromJSON(cJSON *ue_authJSON);
cJSON *ue_auth_convertToJSON(ue_auth_t *ue_auth);
ue_auth_t *ue_auth_copy(ue_auth_t *dst, ue_auth_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_auth_H_ */
