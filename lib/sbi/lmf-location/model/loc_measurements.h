/*
 * loc_measurements.h
 *
 * PRU Location Measurements.
 */

#ifndef _loc_measurements_H_
#define _loc_measurements_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct loc_measurements_s loc_measurements_t;
typedef struct loc_measurements_s {
	bool is_rstd;
	int rstd;
} loc_measurements_t;

loc_measurements_t *loc_measurements_create(bool is_rstd, int rstd);
void loc_measurements_free(loc_measurements_t *loc_measurements);
loc_measurements_t *loc_measurements_parseFromJSON(cJSON *loc_measurementsJSON);
cJSON *loc_measurements_convertToJSON(loc_measurements_t *loc_measurements);
loc_measurements_t *loc_measurements_copy(loc_measurements_t	*dst,
                                          loc_measurements_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _loc_measurements_H_ */
