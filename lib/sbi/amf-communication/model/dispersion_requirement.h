/*
 * dispersion_requirement.h
 *
 * Represents the dispersion analytics requirements.
 */

#ifndef _dispersion_requirement_H_
#define _dispersion_requirement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "class_criterion.h"
#include "dispersion_ordering_criterion.h"
#include "dispersion_type.h"
#include "matching_direction.h"
#include "ranking_criterion.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dispersion_requirement_s dispersion_requirement_t;
typedef struct dispersion_requirement_s {
	struct dispersion_type_s *disper_type;
	list_t *class_criters;
	list_t *rank_criters;
	struct dispersion_ordering_criterion_s *disp_order_criter;
	struct matching_direction_s *order;
} dispersion_requirement_t;

dispersion_requirement_t *dispersion_requirement_create(
	dispersion_type_t *disper_type, list_t *class_criters,
	list_t *rank_criters,
	dispersion_ordering_criterion_t *disp_order_criter,
	matching_direction_t *order);
void dispersion_requirement_free(
	dispersion_requirement_t *dispersion_requirement);
dispersion_requirement_t *dispersion_requirement_parseFromJSON(
	cJSON *dispersion_requirementJSON);
cJSON *dispersion_requirement_convertToJSON(
	dispersion_requirement_t *dispersion_requirement);
dispersion_requirement_t *dispersion_requirement_copy(
	dispersion_requirement_t *dst, dispersion_requirement_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _dispersion_requirement_H_ */
