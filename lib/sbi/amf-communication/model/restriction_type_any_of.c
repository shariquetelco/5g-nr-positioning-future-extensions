#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "restriction_type_any_of.h"

char *restriction_type_any_of_ToString(
	restriction_type_any_of_e restriction_type_any_of) {
	const char *restriction_type_any_ofArray[] =
	{ "NULL", "ALLOWED_AREAS", "NOT_ALLOWED_AREAS" };
	size_t sizeofArray = sizeof(restriction_type_any_ofArray) /
	                     sizeof(restriction_type_any_ofArray[0]);
	if(restriction_type_any_of < sizeofArray) {
		return (char *) restriction_type_any_ofArray[
			restriction_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

restriction_type_any_of_e restriction_type_any_of_FromString(
	char *restriction_type_any_of) {
	int stringToReturn = 0;
	const char *restriction_type_any_ofArray[] =
	{ "NULL", "ALLOWED_AREAS", "NOT_ALLOWED_AREAS" };
	size_t sizeofArray = sizeof(restriction_type_any_ofArray) /
	                     sizeof(restriction_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(restriction_type_any_of,
		          restriction_type_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
