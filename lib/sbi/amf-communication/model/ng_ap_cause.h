/*
 * ng_ap_cause.h
 *
 * Represents the NGAP cause.
 */

#ifndef _ng_ap_cause_H_
#define _ng_ap_cause_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ng_ap_cause_s ng_ap_cause_t;
typedef struct ng_ap_cause_s {
	int group;
	int value;
} ng_ap_cause_t;

ng_ap_cause_t *ng_ap_cause_create(int group, int value);
void ng_ap_cause_free(ng_ap_cause_t *ng_ap_cause);
ng_ap_cause_t *ng_ap_cause_parseFromJSON(cJSON *ng_ap_causeJSON);
cJSON *ng_ap_cause_convertToJSON(ng_ap_cause_t *ng_ap_cause);
ng_ap_cause_t *ng_ap_cause_copy(ng_ap_cause_t *dst, ng_ap_cause_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ng_ap_cause_H_ */
