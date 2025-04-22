/*
 * timestamped_location.h
 *
 * The timestamped locations of the trajectory of the UE.
 */

#ifndef _timestamped_location_H_
#define _timestamped_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "location_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct timestamped_location_s timestamped_location_t;
typedef struct timestamped_location_s {
	char *ts;
	list_t *loc_info;
} timestamped_location_t;

timestamped_location_t *timestamped_location_create(char *ts, list_t *loc_info);
void timestamped_location_free(timestamped_location_t *timestamped_location);
timestamped_location_t *timestamped_location_parseFromJSON(
	cJSON *timestamped_locationJSON);
cJSON *timestamped_location_convertToJSON(
	timestamped_location_t *timestamped_location);
timestamped_location_t *timestamped_location_copy(
	timestamped_location_t	*dst,
	timestamped_location_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _timestamped_location_H_ */
