/*
 * ue_type_any_of.h
 *
 *
 */

#ifndef _ue_type_any_of_H_
#define _ue_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ue_type_any_of_NULL = 0,
	       ue_type_any_of_AERIAL_UE } ue_type_any_of_e;

char *ue_type_any_of_ToString(ue_type_any_of_e ue_type_any_of);

ue_type_any_of_e ue_type_any_of_FromString(char *ue_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _ue_type_any_of_H_ */
