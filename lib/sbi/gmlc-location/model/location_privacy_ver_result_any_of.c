#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_privacy_ver_result_any_of.h"

char *location_privacy_ver_result_any_of_ToString(
	location_privacy_ver_result_any_of_e location_privacy_ver_result_any_of)
{
	const char *location_privacy_ver_result_any_ofArray[] =
	{ "NULL", "LOCATION_ALLOWED", "LOCATION_NOT_ALLOWED",
	  "RESPONSE_TIME_OUT" };
	size_t sizeofArray = sizeof(location_privacy_ver_result_any_ofArray) /
	                     sizeof(location_privacy_ver_result_any_ofArray[0]);
	if(location_privacy_ver_result_any_of < sizeofArray) {
		return (char *) location_privacy_ver_result_any_ofArray[
			location_privacy_ver_result_any_of];
	} else {
		return (char *) "Unknown";
	}
}

location_privacy_ver_result_any_of_e
location_privacy_ver_result_any_of_FromString(
	char *location_privacy_ver_result_any_of) {
	int stringToReturn = 0;
	const char *location_privacy_ver_result_any_ofArray[] =
	{ "NULL", "LOCATION_ALLOWED", "LOCATION_NOT_ALLOWED",
	  "RESPONSE_TIME_OUT" };
	size_t sizeofArray = sizeof(location_privacy_ver_result_any_ofArray) /
	                     sizeof(location_privacy_ver_result_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(location_privacy_ver_result_any_of,
		          location_privacy_ver_result_any_ofArray[stringToReturn
		          ]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
