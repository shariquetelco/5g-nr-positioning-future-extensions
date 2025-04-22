/*
 * ldr_type.h
 *
 *
 */

#ifndef _ldr_type_H_
#define _ldr_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ldr_type_NULL = 0, ldr_type_UE_AVAILABLE, ldr_type_PERIODIC,
	       ldr_type_ENTERING_INTO_AREA, ldr_type_LEAVING_FROM_AREA,
	       ldr_type_BEING_INSIDE_AREA, ldr_type_MOTION } ldr_type_e;

char *ldr_type_ToString(ldr_type_e ldr_type);

ldr_type_e ldr_type_FromString(char *ldr_type);

#ifdef __cplusplus
}
#endif

#endif /* _ldr_type_H_ */
