#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_type_requested.h"

char *location_type_requested_ToString(
	location_type_requested_e location_type_requested) {
	const char *location_type_requestedArray[] =
	{ "NULL", "CURRENT_LOCATION", "CURRENT_OR_LAST_KNOWN_LOCATION",
	  "INITIAL_LOCATION", "NOTIFICATION_VERIFICATION_ONLY" };
	size_t sizeofArray = sizeof(location_type_requestedArray) /
	                     sizeof(location_type_requestedArray[0]);
	if(location_type_requested < sizeofArray) {
		return (char *) location_type_requestedArray[
			location_type_requested];
	} else {
		return (char *) "Unknown";
	}
}

location_type_requested_e location_type_requested_FromString(
	char *location_type_requested) {
	int stringToReturn = 0;
	const char *location_type_requestedArray[] =
	{ "NULL", "CURRENT_LOCATION", "CURRENT_OR_LAST_KNOWN_LOCATION",
	  "INITIAL_LOCATION", "NOTIFICATION_VERIFICATION_ONLY" };
	size_t sizeofArray = sizeof(location_type_requestedArray) /
	                     sizeof(location_type_requestedArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(location_type_requested,
		          location_type_requestedArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
