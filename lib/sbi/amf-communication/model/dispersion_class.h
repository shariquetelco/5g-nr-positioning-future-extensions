/*
 * dispersion_class.h
 *
 * Represents the dispersion class.   Possible values are: - FIXED: Dispersion class as fixed UE its data or transaction usage at a location or   a slice, is higher than its class threshold set for its all data or transaction usage. - CAMPER: Dispersion class as camper UE, its data or transaction usage at a location or   a slice, is higher than its class threshold and lower than the fixed class threshold set   for its all data or transaction usage. - TRAVELLER: Dispersion class as traveller UE, its data or transaction usage at a location   or a slice, is lower than the camper class threshold set for its all data or transaction   usage. - TOP_HEAVY: Dispersion class as Top_Heavy UE, who&#39;s dispersion percentile rating at a   location or a slice, is higher than its class threshold.
 */

#ifndef _dispersion_class_H_
#define _dispersion_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "dispersion_class_one_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dispersion_class_s dispersion_class_t;
typedef struct dispersion_class_s {} dispersion_class_t;

dispersion_class_t *dispersion_class_create();
void dispersion_class_free(dispersion_class_t *dispersion_class);
dispersion_class_t *dispersion_class_parseFromJSON(cJSON *dispersion_classJSON);
cJSON *dispersion_class_convertToJSON(dispersion_class_t *dispersion_class);
dispersion_class_t *dispersion_class_copy(dispersion_class_t	*dst,
                                          dispersion_class_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _dispersion_class_H_ */
