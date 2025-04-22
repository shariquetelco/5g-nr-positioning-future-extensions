/*
 * location_orientation_any_of.h
 *
 *
 */

#ifndef _location_orientation_any_of_H_
#define _location_orientation_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { location_orientation_any_of_NULL = 0,
	       location_orientation_any_of_HORIZONTAL,
	       location_orientation_any_of_VERTICAL,
	       location_orientation_any_of_HOR_AND_VER }
location_orientation_any_of_e;

char *location_orientation_any_of_ToString(
	location_orientation_any_of_e location_orientation_any_of);

location_orientation_any_of_e location_orientation_any_of_FromString(
	char *location_orientation_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _location_orientation_any_of_H_ */
