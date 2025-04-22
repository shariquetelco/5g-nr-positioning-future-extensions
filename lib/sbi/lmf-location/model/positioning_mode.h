/*
 * positioning_mode.h
 *
 *
 */

#ifndef _positioning_mode_H_
#define _positioning_mode_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { positioning_mode_NULL = 0, positioning_mode_UE_BASED,
	       positioning_mode_UE_ASSISTED,
	       positioning_mode_CONVENTIONAL } positioning_mode_e;

char *positioning_mode_ToString(positioning_mode_e positioning_mode);

positioning_mode_e positioning_mode_FromString(char *positioning_mode);

#ifdef __cplusplus
}
#endif

#endif /* _positioning_mode_H_ */
