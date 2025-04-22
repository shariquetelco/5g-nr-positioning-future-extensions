#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "status_change.h"

char *status_change_ToString(status_change_e status_change) {
	const char *status_changeArray[] =
	{ "NULL", "AMF_UNAVAILABLE", "AMF_AVAILABLE" };
	size_t sizeofArray = sizeof(status_changeArray) /
	                     sizeof(status_changeArray[0]);
	if(status_change < sizeofArray) {
		return (char *) status_changeArray[status_change];
	} else {
		return (char *) "Unknown";
	}
}

status_change_e status_change_FromString(char *status_change) {
	int stringToReturn = 0;
	const char *status_changeArray[] =
	{ "NULL", "AMF_UNAVAILABLE", "AMF_AVAILABLE" };
	size_t sizeofArray = sizeof(status_changeArray) /
	                     sizeof(status_changeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(status_change,
		          status_changeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
