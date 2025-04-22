#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "velocity_requested.h"

char *velocity_requested_ToString(velocity_requested_e velocity_requested) {
	const char *velocity_requestedArray[] =
	{ "NULL", "VELOCITY_IS_NOT_REQUESTED", "VELOCITY_IS_REQUESTED" };
	size_t sizeofArray = sizeof(velocity_requestedArray) /
	                     sizeof(velocity_requestedArray[0]);
	if(velocity_requested < sizeofArray) {
		return (char *) velocity_requestedArray[velocity_requested];
	} else {
		return (char *) "Unknown";
	}
}

velocity_requested_e velocity_requested_FromString(char *velocity_requested) {
	int stringToReturn = 0;
	const char *velocity_requestedArray[] =
	{ "NULL", "VELOCITY_IS_NOT_REQUESTED", "VELOCITY_IS_REQUESTED" };
	size_t sizeofArray = sizeof(velocity_requestedArray) /
	                     sizeof(velocity_requestedArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(velocity_requested,
		          velocity_requestedArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
