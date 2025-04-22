/*
 * dispersion_type.h
 *
 * Represents the dispersion type.   Possible values are:   - DVDA: Data Volume Dispersion Analytics.   - TDA: Transactions Dispersion Analytics.   - DVDA_AND_TDA: Data Volume Dispersion Analytics and Transactions Dispersion Analytics.
 */

#ifndef _dispersion_type_H_
#define _dispersion_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "dispersion_type_one_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dispersion_type_s dispersion_type_t;
typedef struct dispersion_type_s {} dispersion_type_t;

dispersion_type_t *dispersion_type_create();
void dispersion_type_free(dispersion_type_t *dispersion_type);
dispersion_type_t *dispersion_type_parseFromJSON(cJSON *dispersion_typeJSON);
cJSON *dispersion_type_convertToJSON(dispersion_type_t *dispersion_type);
dispersion_type_t *dispersion_type_copy(dispersion_type_t	*dst,
                                        dispersion_type_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _dispersion_type_H_ */
