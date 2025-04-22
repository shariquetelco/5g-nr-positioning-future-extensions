#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_orientation_any_of.h"

char *location_orientation_any_of_ToString(
	location_orientation_any_of_e location_orientation_any_of) {
	const char *location_orientation_any_ofArray[] =
	{ "NULL", "HORIZONTAL", "VERTICAL", "HOR_AND_VER" };
	size_t sizeofArray = sizeof(location_orientation_any_ofArray) /
	                     sizeof(location_orientation_any_ofArray[0]);
	if(location_orientation_any_of < sizeofArray) {
		return (char *) location_orientation_any_ofArray[
			location_orientation_any_of];
	} else {
		return (char *) "Unknown";
	}
}

location_orientation_any_of_e location_orientation_any_of_FromString(
	char *location_orientation_any_of) {
	int stringToReturn = 0;
	const char *location_orientation_any_ofArray[] =
	{ "NULL", "HORIZONTAL", "VERTICAL", "HOR_AND_VER" };
	size_t sizeofArray = sizeof(location_orientation_any_ofArray) /
	                     sizeof(location_orientation_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(location_orientation_any_of,
		          location_orientation_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
