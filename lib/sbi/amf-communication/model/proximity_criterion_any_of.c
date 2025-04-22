#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "proximity_criterion_any_of.h"

char *proximity_criterion_any_of_ToString(
	proximity_criterion_any_of_e proximity_criterion_any_of) {
	const char *proximity_criterion_any_ofArray[] =
	{ "NULL", "VELOCITY", "AVG_SPD", "ORIENTATION", "TRAJECTORY" };
	size_t sizeofArray = sizeof(proximity_criterion_any_ofArray) /
	                     sizeof(proximity_criterion_any_ofArray[0]);
	if(proximity_criterion_any_of < sizeofArray) {
		return (char *) proximity_criterion_any_ofArray[
			proximity_criterion_any_of];
	} else {
		return (char *) "Unknown";
	}
}

proximity_criterion_any_of_e proximity_criterion_any_of_FromString(
	char *proximity_criterion_any_of) {
	int stringToReturn = 0;
	const char *proximity_criterion_any_ofArray[] =
	{ "NULL", "VELOCITY", "AVG_SPD", "ORIENTATION", "TRAJECTORY" };
	size_t sizeofArray = sizeof(proximity_criterion_any_ofArray) /
	                     sizeof(proximity_criterion_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(proximity_criterion_any_of,
		          proximity_criterion_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
