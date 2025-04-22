#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "positioning_mode.h"

char *positioning_mode_ToString(positioning_mode_e positioning_mode) {
	const char *positioning_modeArray[] =
	{ "NULL", "UE_BASED", "UE_ASSISTED", "CONVENTIONAL" };
	size_t sizeofArray = sizeof(positioning_modeArray) /
	                     sizeof(positioning_modeArray[0]);
	if(positioning_mode < sizeofArray) {
		return (char *) positioning_modeArray[positioning_mode];
	} else {
		return (char *) "Unknown";
	}
}

positioning_mode_e positioning_mode_FromString(char *positioning_mode) {
	int stringToReturn = 0;
	const char *positioning_modeArray[] =
	{ "NULL", "UE_BASED", "UE_ASSISTED", "CONVENTIONAL" };
	size_t sizeofArray = sizeof(positioning_modeArray) /
	                     sizeof(positioning_modeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(positioning_mode,
		          positioning_modeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
