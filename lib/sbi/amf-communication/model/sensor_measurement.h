/*
 * sensor_measurement.h
 *
 * The enumeration SensorMeasurement defines sensor measurement type for MDT in the trace. See 3GPP TS 32.422 for further description of the values. It shall comply with the provisions defined in table 5.6.3.7-1.
 */

#ifndef _sensor_measurement_H_
#define _sensor_measurement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "sensor_measurement_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sensor_measurement_s sensor_measurement_t;
typedef struct sensor_measurement_s {} sensor_measurement_t;

sensor_measurement_t *sensor_measurement_create();
void sensor_measurement_free(sensor_measurement_t *sensor_measurement);
sensor_measurement_t *sensor_measurement_parseFromJSON(
	cJSON *sensor_measurementJSON);
cJSON *sensor_measurement_convertToJSON(
	sensor_measurement_t *sensor_measurement);
sensor_measurement_t *sensor_measurement_copy(sensor_measurement_t	*dst,
                                              sensor_measurement_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _sensor_measurement_H_ */
