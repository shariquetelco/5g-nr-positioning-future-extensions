/*
 * velocity_requested.h
 *
 *
 */

#ifndef _velocity_requested_H_
#define _velocity_requested_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { velocity_requested_NULL = 0,
	       velocity_requested_VELOCITY_IS_NOT_REQUESTED,
	       velocity_requested_VELOCITY_IS_REQUESTED } velocity_requested_e;

char *velocity_requested_ToString(velocity_requested_e velocity_requested);

velocity_requested_e velocity_requested_FromString(char *velocity_requested);

#ifdef __cplusplus
}
#endif

#endif /* _velocity_requested_H_ */
