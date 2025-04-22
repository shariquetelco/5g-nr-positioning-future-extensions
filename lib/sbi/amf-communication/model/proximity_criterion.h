/*
 * proximity_criterion.h
 *
 * Possible values are:     - VELOCITY: Velocity.   - AVG_SPD: Average speed.   - ORIENTATION: Orientation.   - TRAJECTORY: Mobility trajectory.
 */

#ifndef _proximity_criterion_H_
#define _proximity_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "proximity_criterion_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct proximity_criterion_s proximity_criterion_t;
typedef struct proximity_criterion_s {} proximity_criterion_t;

proximity_criterion_t *proximity_criterion_create();
void proximity_criterion_free(proximity_criterion_t *proximity_criterion);
proximity_criterion_t *proximity_criterion_parseFromJSON(
	cJSON *proximity_criterionJSON);
cJSON *proximity_criterion_convertToJSON(
	proximity_criterion_t *proximity_criterion);
proximity_criterion_t *proximity_criterion_copy(proximity_criterion_t	*dst,
                                                proximity_criterion_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _proximity_criterion_H_ */
