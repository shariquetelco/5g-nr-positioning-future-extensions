/*
 * preemption_capability.h
 *
 * The enumeration PreemptionCapability indicates the pre-emption capability of a request on other QoS flows. See clause 5.7.2.2 of 3GPP TS 23.501. It shall comply with the provisions defined in table 5.5.3.1-1.
 */

#ifndef _preemption_capability_H_
#define _preemption_capability_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "preemption_capability_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct preemption_capability_s preemption_capability_t;
typedef struct preemption_capability_s {} preemption_capability_t;

preemption_capability_t *preemption_capability_create();
void preemption_capability_free(preemption_capability_t *preemption_capability);
preemption_capability_t *preemption_capability_parseFromJSON(
	cJSON *preemption_capabilityJSON);
cJSON *preemption_capability_convertToJSON(
	preemption_capability_t *preemption_capability);
preemption_capability_t *preemption_capability_copy(
	preemption_capability_t *dst, preemption_capability_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _preemption_capability_H_ */
