/*
 * dispersion_ordering_criterion.h
 *
 * Represents the order criterion for the list of dispersion.   Possible values are: - TIME_SLOT_START: Indicates the order of time slot start. - DISPERSION: Indicates the order of data/transaction dispersion. - CLASSIFICATION: Indicates the order of data/transaction classification. - RANKING: Indicates the order of data/transaction ranking. - PERCENTILE_RANKING: Indicates the order of data/transaction percentile ranking.
 */

#ifndef _dispersion_ordering_criterion_H_
#define _dispersion_ordering_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "dispersion_ordering_criterion_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dispersion_ordering_criterion_s dispersion_ordering_criterion_t;
typedef struct dispersion_ordering_criterion_s {}
dispersion_ordering_criterion_t;

dispersion_ordering_criterion_t *dispersion_ordering_criterion_create();
void dispersion_ordering_criterion_free(
	dispersion_ordering_criterion_t *dispersion_ordering_criterion);
dispersion_ordering_criterion_t *dispersion_ordering_criterion_parseFromJSON(
	cJSON *dispersion_ordering_criterionJSON);
cJSON *dispersion_ordering_criterion_convertToJSON(
	dispersion_ordering_criterion_t *dispersion_ordering_criterion);
dispersion_ordering_criterion_t *dispersion_ordering_criterion_copy(
	dispersion_ordering_criterion_t *dst,
	dispersion_ordering_criterion_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _dispersion_ordering_criterion_H_ */
