/*
 * dispersion_type_one_of.h
 *
 *
 */

#ifndef _dispersion_type_one_of_H_
#define _dispersion_type_one_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { dispersion_type_one_of_NULL = 0, dispersion_type_one_of_DVDA,
	       dispersion_type_one_of_TDA,
	       dispersion_type_one_of_DVDA_AND_TDA } dispersion_type_one_of_e;

char *dispersion_type_one_of_ToString(
	dispersion_type_one_of_e dispersion_type_one_of);

dispersion_type_one_of_e dispersion_type_one_of_FromString(
	char *dispersion_type_one_of);

#ifdef __cplusplus
}
#endif

#endif /* _dispersion_type_one_of_H_ */
