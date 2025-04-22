#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "direction_any_of.h"

char *direction_any_of_ToString(direction_any_of_e direction_any_of) {
	const char *direction_any_ofArray[] =
	{ "NULL", "NORTH", "SOUTH", "EAST", "WEST", "NORTHWEST", "NORTHEAST",
	  "SOUTHWEST", "SOUTHEAST" };
	size_t sizeofArray = sizeof(direction_any_ofArray) /
	                     sizeof(direction_any_ofArray[0]);
	if(direction_any_of < sizeofArray) {
		return (char *) direction_any_ofArray[direction_any_of];
	} else {
		return (char *) "Unknown";
	}
}

direction_any_of_e direction_any_of_FromString(char *direction_any_of) {
	int stringToReturn = 0;
	const char *direction_any_ofArray[] =
	{ "NULL", "NORTH", "SOUTH", "EAST", "WEST", "NORTHWEST", "NORTHEAST",
	  "SOUTHWEST", "SOUTHEAST" };
	size_t sizeofArray = sizeof(direction_any_ofArray) /
	                     sizeof(direction_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(direction_any_of,
		          direction_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
