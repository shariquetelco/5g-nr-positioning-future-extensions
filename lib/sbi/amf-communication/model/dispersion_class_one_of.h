/*
 * dispersion_class_one_of.h
 *
 *
 */

#ifndef _dispersion_class_one_of_H_
#define _dispersion_class_one_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { dispersion_class_one_of_NULL = 0, dispersion_class_one_of_FIXED,
	       dispersion_class_one_of_CAMPER,
	       dispersion_class_one_of_TRAVELLER,
	       dispersion_class_one_of_TOP_HEAVY } dispersion_class_one_of_e;

char *dispersion_class_one_of_ToString(
	dispersion_class_one_of_e dispersion_class_one_of);

dispersion_class_one_of_e dispersion_class_one_of_FromString(
	char *dispersion_class_one_of);

#ifdef __cplusplus
}
#endif

#endif /* _dispersion_class_one_of_H_ */
