#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stationary_indication_any_of.h"

char *stationary_indication_any_of_ToString(
	stationary_indication_any_of_e stationary_indication_any_of) {
	const char *stationary_indication_any_ofArray[] =
	{ "NULL", "STATIONARY", "MOBILE" };
	size_t sizeofArray = sizeof(stationary_indication_any_ofArray) /
	                     sizeof(stationary_indication_any_ofArray[0]);
	if(stationary_indication_any_of < sizeofArray) {
		return (char *) stationary_indication_any_ofArray[
			stationary_indication_any_of];
	} else {
		return (char *) "Unknown";
	}
}

stationary_indication_any_of_e stationary_indication_any_of_FromString(
	char *stationary_indication_any_of) {
	int stringToReturn = 0;
	const char *stationary_indication_any_ofArray[] =
	{ "NULL", "STATIONARY", "MOBILE" };
	size_t sizeofArray = sizeof(stationary_indication_any_ofArray) /
	                     sizeof(stationary_indication_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(stationary_indication_any_of,
		          stationary_indication_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
