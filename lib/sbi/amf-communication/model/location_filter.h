/*
 * location_filter.h
 *
 * Describes the supported filters of LOCATION_REPORT event type
 */

#ifndef _location_filter_H_
#define _location_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "location_filter_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct location_filter_s location_filter_t;
typedef struct location_filter_s {} location_filter_t;

location_filter_t *location_filter_create();
void location_filter_free(location_filter_t *location_filter);
location_filter_t *location_filter_parseFromJSON(cJSON *location_filterJSON);
cJSON *location_filter_convertToJSON(location_filter_t *location_filter);
location_filter_t *location_filter_copy(location_filter_t	*dst,
                                        location_filter_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _location_filter_H_ */
