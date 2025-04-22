#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data_availability.h"

char *data_availability_ToString(data_availability_e data_availability) {
	const char *data_availabilityArray[] =
	{ "NULL", "CIPHERING_KEY_DATA_AVAILABLE",
	  "CIPHERING_KEY_DATA_NOT_AVAILABLE" };
	size_t sizeofArray = sizeof(data_availabilityArray) /
	                     sizeof(data_availabilityArray[0]);
	if(data_availability < sizeofArray) {
		return (char *) data_availabilityArray[data_availability];
	} else {
		return (char *) "Unknown";
	}
}

data_availability_e data_availability_FromString(char *data_availability) {
	int stringToReturn = 0;
	const char *data_availabilityArray[] =
	{ "NULL", "CIPHERING_KEY_DATA_AVAILABLE",
	  "CIPHERING_KEY_DATA_NOT_AVAILABLE" };
	size_t sizeofArray = sizeof(data_availabilityArray) /
	                     sizeof(data_availabilityArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(data_availability,
		          data_availabilityArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
