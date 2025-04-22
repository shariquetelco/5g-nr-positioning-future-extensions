/*
 * fix_type.h
 *
 *
 */

#ifndef _fix_type_H_
#define _fix_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { fix_type_NULL = 0, fix_type_CARRIER_PHASE_FLOAT,
	       fix_type_CARRIER_PHASE_FIX } fix_type_e;

char *fix_type_ToString(fix_type_e fix_type);

fix_type_e fix_type_FromString(char *fix_type);

#ifdef __cplusplus
}
#endif

#endif /* _fix_type_H_ */
