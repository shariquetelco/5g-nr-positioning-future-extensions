/*
 * clock_quality_acceptance_criterion.h
 *
 * Contains a Clock Quality Acceptance Criterion.
 */

#ifndef _clock_quality_acceptance_criterion_H_
#define _clock_quality_acceptance_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "clock_quality.h"
#include "synchronization_state.h"
#include "time_source.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct clock_quality_acceptance_criterion_s
        clock_quality_acceptance_criterion_t;
typedef struct clock_quality_acceptance_criterion_s {
	list_t *synchronization_state;
	struct clock_quality_s *clock_quality;
	list_t *parent_time_source;
} clock_quality_acceptance_criterion_t;

clock_quality_acceptance_criterion_t *clock_quality_acceptance_criterion_create(
	list_t *synchronization_state, clock_quality_t *clock_quality,
	list_t *parent_time_source);
void clock_quality_acceptance_criterion_free(
	clock_quality_acceptance_criterion_t *clock_quality_acceptance_criterion);
clock_quality_acceptance_criterion_t *
clock_quality_acceptance_criterion_parseFromJSON(
	cJSON *clock_quality_acceptance_criterionJSON);
cJSON *clock_quality_acceptance_criterion_convertToJSON(
	clock_quality_acceptance_criterion_t *clock_quality_acceptance_criterion);
clock_quality_acceptance_criterion_t *clock_quality_acceptance_criterion_copy(
	clock_quality_acceptance_criterion_t	*dst,
	clock_quality_acceptance_criterion_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _clock_quality_acceptance_criterion_H_ */
