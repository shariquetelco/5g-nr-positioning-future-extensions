#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "presence_state_any_of.h"

char *presence_state_any_of_ToString(
	presence_state_any_of_e presence_state_any_of) {
	const char *presence_state_any_ofArray[] =
	{ "NULL", "IN_AREA", "OUT_OF_AREA", "UNKNOWN", "INACTIVE" };
	size_t sizeofArray = sizeof(presence_state_any_ofArray) /
	                     sizeof(presence_state_any_ofArray[0]);
	if(presence_state_any_of < sizeofArray) {
		return (char *) presence_state_any_ofArray[presence_state_any_of
		];
	} else {
		return (char *) "Unknown";
	}
}

presence_state_any_of_e presence_state_any_of_FromString(
	char *presence_state_any_of) {
	int stringToReturn = 0;
	const char *presence_state_any_ofArray[] =
	{ "NULL", "IN_AREA", "OUT_OF_AREA", "UNKNOWN", "INACTIVE" };
	size_t sizeofArray = sizeof(presence_state_any_ofArray) /
	                     sizeof(presence_state_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(presence_state_any_of,
		          presence_state_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
