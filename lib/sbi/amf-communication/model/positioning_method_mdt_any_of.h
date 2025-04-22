/*
 * positioning_method_mdt_any_of.h
 *
 *
 */

#ifndef _positioning_method_mdt_any_of_H_
#define _positioning_method_mdt_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { positioning_method_mdt_any_of_NULL = 0,
	       positioning_method_mdt_any_of_GNSS,
	       positioning_method_mdt_any_of_E_CELL_ID }
positioning_method_mdt_any_of_e;

char *positioning_method_mdt_any_of_ToString(
	positioning_method_mdt_any_of_e positioning_method_mdt_any_of);

positioning_method_mdt_any_of_e positioning_method_mdt_any_of_FromString(
	char *positioning_method_mdt_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _positioning_method_mdt_any_of_H_ */
