/*
 * dataset_statistical_property.h
 *
 * Represents the dataset statistical properties.   Possible values are: - UNIFORM_DIST_DATA: Indicates the use of data samples that are uniformly distributed   according to the different aspects of the requested analytics. - NO_OUTLIERS: Indicates that the data samples shall disregard data samples that are at   the extreme boundaries of the value range.
 */

#ifndef _dataset_statistical_property_H_
#define _dataset_statistical_property_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "dataset_statistical_property_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dataset_statistical_property_s dataset_statistical_property_t;
typedef struct dataset_statistical_property_s {} dataset_statistical_property_t;

dataset_statistical_property_t *dataset_statistical_property_create();
void dataset_statistical_property_free(
	dataset_statistical_property_t *dataset_statistical_property);
dataset_statistical_property_t *dataset_statistical_property_parseFromJSON(
	cJSON *dataset_statistical_propertyJSON);
cJSON *dataset_statistical_property_convertToJSON(
	dataset_statistical_property_t *dataset_statistical_property);
dataset_statistical_property_t *dataset_statistical_property_copy(
	dataset_statistical_property_t	*dst,
	dataset_statistical_property_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _dataset_statistical_property_H_ */
