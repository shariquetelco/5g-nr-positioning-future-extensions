/*
 * scheduled_communication_type.h
 *
 * Possible values are: -DOWNLINK_ONLY: Downlink only -UPLINK_ONLY: Uplink only -BIDIRECTIONA: Bi-directional
 */

#ifndef _scheduled_communication_type_H_
#define _scheduled_communication_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "scheduled_communication_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct scheduled_communication_type_s scheduled_communication_type_t;
typedef struct scheduled_communication_type_s {} scheduled_communication_type_t;

scheduled_communication_type_t *scheduled_communication_type_create();
void scheduled_communication_type_free(
	scheduled_communication_type_t *scheduled_communication_type);
scheduled_communication_type_t *scheduled_communication_type_parseFromJSON(
	cJSON *scheduled_communication_typeJSON);
cJSON *scheduled_communication_type_convertToJSON(
	scheduled_communication_type_t *scheduled_communication_type);
scheduled_communication_type_t *scheduled_communication_type_copy(
	scheduled_communication_type_t	*dst,
	scheduled_communication_type_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _scheduled_communication_type_H_ */
