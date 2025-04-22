#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "termination_cause.h"

char *termination_cause_ToString(termination_cause_e termination_cause) {
	const char *termination_causeArray[] =
	{ "NULL", "TERMINATION_BY_UE", "TERMINATION_BY_NETWORK",
	  "NORMAL_TERMINATION" };
	size_t sizeofArray = sizeof(termination_causeArray) /
	                     sizeof(termination_causeArray[0]);
	if(termination_cause < sizeofArray) {
		return (char *) termination_causeArray[termination_cause];
	} else {
		return (char *) "Unknown";
	}
}

termination_cause_e termination_cause_FromString(char *termination_cause) {
	int stringToReturn = 0;
	const char *termination_causeArray[] =
	{ "NULL", "TERMINATION_BY_UE", "TERMINATION_BY_NETWORK",
	  "NORMAL_TERMINATION" };
	size_t sizeofArray = sizeof(termination_causeArray) /
	                     sizeof(termination_causeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(termination_cause,
		          termination_causeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
