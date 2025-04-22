#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "failure_cause.h"

char *failure_cause_ToString(failure_cause_e failure_cause) {
	const char *failure_causeArray[] =
	{ "NULL", "POSITIONING_DENIED", "UNSUPPORTED_BY_UE", "NOT_REGISTED_UE",
	  "UNSPECIFIED" };
	size_t sizeofArray = sizeof(failure_causeArray) /
	                     sizeof(failure_causeArray[0]);
	if(failure_cause < sizeofArray) {
		return (char *) failure_causeArray[failure_cause];
	} else {
		return (char *) "Unknown";
	}
}

failure_cause_e failure_cause_FromString(char *failure_cause) {
	int stringToReturn = 0;
	const char *failure_causeArray[] =
	{ "NULL", "POSITIONING_DENIED", "UNSUPPORTED_BY_UE", "NOT_REGISTED_UE",
	  "UNSPECIFIED" };
	size_t sizeofArray = sizeof(failure_causeArray) /
	                     sizeof(failure_causeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(failure_cause,
		          failure_causeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
