/*
 * dispersion_ordering_criterion_any_of.h
 *
 *
 */

#ifndef _dispersion_ordering_criterion_any_of_H_
#define _dispersion_ordering_criterion_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { dispersion_ordering_criterion_any_of_NULL = 0,
	       dispersion_ordering_criterion_any_of_TIME_SLOT_START,
	       dispersion_ordering_criterion_any_of_DISPERSION,
	       dispersion_ordering_criterion_any_of_CLASSIFICATION,
	       dispersion_ordering_criterion_any_of_RANKING,
	       dispersion_ordering_criterion_any_of_PERCENTILE_RANKING }
dispersion_ordering_criterion_any_of_e;

char *dispersion_ordering_criterion_any_of_ToString(
	dispersion_ordering_criterion_any_of_e dispersion_ordering_criterion_any_of);

dispersion_ordering_criterion_any_of_e
dispersion_ordering_criterion_any_of_FromString(
	char *dispersion_ordering_criterion_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _dispersion_ordering_criterion_any_of_H_ */
