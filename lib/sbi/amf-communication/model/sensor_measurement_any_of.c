#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sensor_measurement_any_of.h"

char *sensor_measurement_any_of_ToString(
	sensor_measurement_any_of_e sensor_measurement_any_of) {
	const char *sensor_measurement_any_ofArray[] =
	{ "NULL", "BAROMETRIC_PRESSURE", "UE_SPEED", "UE_ORIENTATION" };
	size_t sizeofArray = sizeof(sensor_measurement_any_ofArray) /
	                     sizeof(sensor_measurement_any_ofArray[0]);
	if(sensor_measurement_any_of < sizeofArray) {
		return (char *) sensor_measurement_any_ofArray[
			sensor_measurement_any_of];
	} else {
		return (char *) "Unknown";
	}
}

sensor_measurement_any_of_e sensor_measurement_any_of_FromString(
	char *sensor_measurement_any_of) {
	int stringToReturn = 0;
	const char *sensor_measurement_any_ofArray[] =
	{ "NULL", "BAROMETRIC_PRESSURE", "UE_SPEED", "UE_ORIENTATION" };
	size_t sizeofArray = sizeof(sensor_measurement_any_ofArray) /
	                     sizeof(sensor_measurement_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(sensor_measurement_any_of,
		          sensor_measurement_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
