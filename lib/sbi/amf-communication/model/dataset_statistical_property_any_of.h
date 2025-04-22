/*
 * dataset_statistical_property_any_of.h
 *
 *
 */

#ifndef _dataset_statistical_property_any_of_H_
#define _dataset_statistical_property_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { dataset_statistical_property_any_of_NULL = 0,
	       dataset_statistical_property_any_of_UNIFORM_DIST_DATA,
	       dataset_statistical_property_any_of_NO_OUTLIERS }
dataset_statistical_property_any_of_e;

char *dataset_statistical_property_any_of_ToString(
	dataset_statistical_property_any_of_e dataset_statistical_property_any_of);

dataset_statistical_property_any_of_e
dataset_statistical_property_any_of_FromString(
	char *dataset_statistical_property_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _dataset_statistical_property_any_of_H_ */
