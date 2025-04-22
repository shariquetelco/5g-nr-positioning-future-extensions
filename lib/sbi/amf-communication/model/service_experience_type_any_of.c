#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_experience_type_any_of.h"

char *service_experience_type_any_of_ToString(
	service_experience_type_any_of_e service_experience_type_any_of) {
	const char *service_experience_type_any_ofArray[] =
	{ "NULL", "VOICE", "VIDEO", "OTHER" };
	size_t sizeofArray = sizeof(service_experience_type_any_ofArray) /
	                     sizeof(service_experience_type_any_ofArray[0]);
	if(service_experience_type_any_of < sizeofArray) {
		return (char *) service_experience_type_any_ofArray[
			service_experience_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

service_experience_type_any_of_e service_experience_type_any_of_FromString(
	char *service_experience_type_any_of) {
	int stringToReturn = 0;
	const char *service_experience_type_any_ofArray[] =
	{ "NULL", "VOICE", "VIDEO", "OTHER" };
	size_t sizeofArray = sizeof(service_experience_type_any_ofArray) /
	                     sizeof(service_experience_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(service_experience_type_any_of,
		          service_experience_type_any_ofArray[stringToReturn])
		   == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
