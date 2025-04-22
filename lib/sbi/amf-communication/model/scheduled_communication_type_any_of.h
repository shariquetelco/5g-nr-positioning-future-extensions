/*
 * scheduled_communication_type_any_of.h
 *
 *
 */

#ifndef _scheduled_communication_type_any_of_H_
#define _scheduled_communication_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { scheduled_communication_type_any_of_NULL = 0,
	       scheduled_communication_type_any_of_DOWNLINK_ONLY,
	       scheduled_communication_type_any_of_UPLINK_ONLY,
	       scheduled_communication_type_any_of_BIDIRECTIONAL }
scheduled_communication_type_any_of_e;

char *scheduled_communication_type_any_of_ToString(
	scheduled_communication_type_any_of_e scheduled_communication_type_any_of);

scheduled_communication_type_any_of_e
scheduled_communication_type_any_of_FromString(
	char *scheduled_communication_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _scheduled_communication_type_any_of_H_ */
