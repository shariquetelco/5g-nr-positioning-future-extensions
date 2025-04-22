/*
 * sensor_measurement_any_of.h
 *
 *
 */

#ifndef _sensor_measurement_any_of_H_
#define _sensor_measurement_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { sensor_measurement_any_of_NULL = 0,
	       sensor_measurement_any_of_BAROMETRIC_PRESSURE,
	       sensor_measurement_any_of_UE_SPEED,
	       sensor_measurement_any_of_UE_ORIENTATION }
sensor_measurement_any_of_e;

char *sensor_measurement_any_of_ToString(
	sensor_measurement_any_of_e sensor_measurement_any_of);

sensor_measurement_any_of_e sensor_measurement_any_of_FromString(
	char *sensor_measurement_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _sensor_measurement_any_of_H_ */
