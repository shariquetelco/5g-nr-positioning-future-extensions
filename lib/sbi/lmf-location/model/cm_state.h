/*
 * cm_state.h
 *
 * Describes the connection management state of a UE
 */

#ifndef _cm_state_H_
#define _cm_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "cm_state_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cm_state_s cm_state_t;
typedef struct cm_state_s {} cm_state_t;

cm_state_t *cm_state_create();
void cm_state_free(cm_state_t *cm_state);
cm_state_t *cm_state_parseFromJSON(cJSON *cm_stateJSON);
cJSON *cm_state_convertToJSON(cm_state_t *cm_state);
cm_state_t *cm_state_copy(cm_state_t *dst, cm_state_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _cm_state_H_ */
