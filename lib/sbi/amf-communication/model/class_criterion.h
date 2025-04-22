/*
 * class_criterion.h
 *
 * Indicates the dispersion class criterion for fixed, camper and/or traveller UE, and/or the top-heavy UE dispersion class criterion.
 */

#ifndef _class_criterion_H_
#define _class_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "dispersion_class.h"
#include "matching_direction.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct class_criterion_s class_criterion_t;
typedef struct class_criterion_s {
	struct dispersion_class_s *disper_class;
	int class_threshold;
	struct matching_direction_s *thres_match;
} class_criterion_t;

class_criterion_t *class_criterion_create(dispersion_class_t	*disper_class,
                                          int			class_threshold,
                                          matching_direction_t	*thres_match);
void class_criterion_free(class_criterion_t *class_criterion);
class_criterion_t *class_criterion_parseFromJSON(cJSON *class_criterionJSON);
cJSON *class_criterion_convertToJSON(class_criterion_t *class_criterion);
class_criterion_t *class_criterion_copy(class_criterion_t	*dst,
                                        class_criterion_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _class_criterion_H_ */
