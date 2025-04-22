/*
 * ue_up_positioning_capabilities.h
 *
 *
 */

#ifndef _ue_up_positioning_capabilities_H_
#define _ue_up_positioning_capabilities_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ue_up_positioning_capabilities_NULL = 0,
	       ue_up_positioning_capabilities_LCS_UPP,
	       ue_up_positioning_capabilities_SUPL }
ue_up_positioning_capabilities_e;

char *ue_up_positioning_capabilities_ToString(
	ue_up_positioning_capabilities_e ue_up_positioning_capabilities);

ue_up_positioning_capabilities_e ue_up_positioning_capabilities_FromString(
	char *ue_up_positioning_capabilities);

#ifdef __cplusplus
}
#endif

#endif /* _ue_up_positioning_capabilities_H_ */
