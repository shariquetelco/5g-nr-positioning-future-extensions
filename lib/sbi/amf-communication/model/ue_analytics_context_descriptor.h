/*
 * ue_analytics_context_descriptor.h
 *
 * Contains information about available UE related analytics contexts.
 */

#ifndef _ue_analytics_context_descriptor_H_
#define _ue_analytics_context_descriptor_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nwdaf_event.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_analytics_context_descriptor_s
        ue_analytics_context_descriptor_t;
typedef struct ue_analytics_context_descriptor_s {
	char *supi;
	list_t *ana_types;
} ue_analytics_context_descriptor_t;

ue_analytics_context_descriptor_t *ue_analytics_context_descriptor_create(
	char *supi, list_t *ana_types);
void ue_analytics_context_descriptor_free(
	ue_analytics_context_descriptor_t *ue_analytics_context_descriptor);
ue_analytics_context_descriptor_t *ue_analytics_context_descriptor_parseFromJSON(
	cJSON *ue_analytics_context_descriptorJSON);
cJSON *ue_analytics_context_descriptor_convertToJSON(
	ue_analytics_context_descriptor_t *ue_analytics_context_descriptor);
ue_analytics_context_descriptor_t *ue_analytics_context_descriptor_copy(
	ue_analytics_context_descriptor_t	*dst,
	ue_analytics_context_descriptor_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_analytics_context_descriptor_H_ */
