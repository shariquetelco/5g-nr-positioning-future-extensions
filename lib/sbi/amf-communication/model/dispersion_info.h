/*
 * dispersion_info.h
 *
 * Represents the Dispersion information. When subscribed event is \&quot;DISPERSION\&quot;, the \&quot;disperInfos\&quot; attribute shall be included.
 */

#ifndef _dispersion_info_H_
#define _dispersion_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "dispersion_collection.h"
#include "dispersion_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dispersion_info_s dispersion_info_t;
typedef struct dispersion_info_s {
	char *ts_start;
	int ts_duration;
	list_t *disper_collects;
	struct dispersion_type_s *disper_type;
} dispersion_info_t;

dispersion_info_t *dispersion_info_create(char *ts_start, int ts_duration,
                                          list_t *disper_collects,
                                          dispersion_type_t *disper_type);
void dispersion_info_free(dispersion_info_t *dispersion_info);
dispersion_info_t *dispersion_info_parseFromJSON(cJSON *dispersion_infoJSON);
cJSON *dispersion_info_convertToJSON(dispersion_info_t *dispersion_info);
dispersion_info_t *dispersion_info_copy(dispersion_info_t	*dst,
                                        dispersion_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _dispersion_info_H_ */
