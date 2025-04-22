#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "occurrence_info.h"

char *occurrence_info_ToString(occurrence_info_e occurrence_info) {
	const char *occurrence_infoArray[] =
	{ "NULL", "ONE_TIME_EVENT", "MULTIPLE_TIME_EVENT" };
	size_t sizeofArray = sizeof(occurrence_infoArray) /
	                     sizeof(occurrence_infoArray[0]);
	if(occurrence_info < sizeofArray) {
		return (char *) occurrence_infoArray[occurrence_info];
	} else {
		return (char *) "Unknown";
	}
}

occurrence_info_e occurrence_info_FromString(char *occurrence_info) {
	int stringToReturn = 0;
	const char *occurrence_infoArray[] =
	{ "NULL", "ONE_TIME_EVENT", "MULTIPLE_TIME_EVENT" };
	size_t sizeofArray = sizeof(occurrence_infoArray) /
	                     sizeof(occurrence_infoArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(occurrence_info,
		          occurrence_infoArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
