/*
 * related_ue_type.h
 *
 *
 */

#ifndef _related_ue_type_H_
#define _related_ue_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { related_ue_type_NULL = 0, related_ue_type_LOCATED_UE,
	       related_ue_type_REFERENCE_UE } related_ue_type_e;

char *related_ue_type_ToString(related_ue_type_e related_ue_type);

related_ue_type_e related_ue_type_FromString(char *related_ue_type);

#ifdef __cplusplus
}
#endif

#endif /* _related_ue_type_H_ */
