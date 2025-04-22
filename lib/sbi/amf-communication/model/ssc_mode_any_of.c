#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ssc_mode_any_of.h"

char *ssc_mode_any_of_ToString(ssc_mode_any_of_e ssc_mode_any_of) {
	const char *ssc_mode_any_ofArray[] =
	{ "NULL", "SSC_MODE_1", "SSC_MODE_2", "SSC_MODE_3" };
	size_t sizeofArray = sizeof(ssc_mode_any_ofArray) /
	                     sizeof(ssc_mode_any_ofArray[0]);
	if(ssc_mode_any_of < sizeofArray) {
		return (char *) ssc_mode_any_ofArray[ssc_mode_any_of];
	} else {
		return (char *) "Unknown";
	}
}

ssc_mode_any_of_e ssc_mode_any_of_FromString(char *ssc_mode_any_of) {
	int stringToReturn = 0;
	const char *ssc_mode_any_ofArray[] =
	{ "NULL", "SSC_MODE_1", "SSC_MODE_2", "SSC_MODE_3" };
	size_t sizeofArray = sizeof(ssc_mode_any_ofArray) /
	                     sizeof(ssc_mode_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(ssc_mode_any_of,
		          ssc_mode_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
