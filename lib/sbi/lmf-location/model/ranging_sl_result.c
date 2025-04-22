#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ranging_sl_result.h"

char *ranging_sl_result_ToString(ranging_sl_result_e ranging_sl_result) {
	const char *ranging_sl_resultArray[] =
	{ "NULL", "ABSOLUTE_LOCATION", "RELATIVE_LOCATION", "RANGING_DIRECTION",
	  "RANGING", "DIRECTION", "VELOCITY", "RELATIVE_VELOCITY" };
	size_t sizeofArray = sizeof(ranging_sl_resultArray) /
	                     sizeof(ranging_sl_resultArray[0]);
	if(ranging_sl_result < sizeofArray) {
		return (char *) ranging_sl_resultArray[ranging_sl_result];
	} else {
		return (char *) "Unknown";
	}
}

ranging_sl_result_e ranging_sl_result_FromString(char *ranging_sl_result) {
	int stringToReturn = 0;
	const char *ranging_sl_resultArray[] =
	{ "NULL", "ABSOLUTE_LOCATION", "RELATIVE_LOCATION", "RANGING_DIRECTION",
	  "RANGING", "DIRECTION", "VELOCITY", "RELATIVE_VELOCITY" };
	size_t sizeofArray = sizeof(ranging_sl_resultArray) /
	                     sizeof(ranging_sl_resultArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(ranging_sl_result,
		          ranging_sl_resultArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
