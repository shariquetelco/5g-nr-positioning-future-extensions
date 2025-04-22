#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "auth_status_any_of.h"

char *auth_status_any_of_ToString(auth_status_any_of_e auth_status_any_of) {
	const char *auth_status_any_ofArray[] =
	{ "NULL", "EAP_SUCCESS", "EAP_FAILURE", "PENDING" };
	size_t sizeofArray = sizeof(auth_status_any_ofArray) /
	                     sizeof(auth_status_any_ofArray[0]);
	if(auth_status_any_of < sizeofArray) {
		return (char *) auth_status_any_ofArray[auth_status_any_of];
	} else {
		return (char *) "Unknown";
	}
}

auth_status_any_of_e auth_status_any_of_FromString(char *auth_status_any_of) {
	int stringToReturn = 0;
	const char *auth_status_any_ofArray[] =
	{ "NULL", "EAP_SUCCESS", "EAP_FAILURE", "PENDING" };
	size_t sizeofArray = sizeof(auth_status_any_ofArray) /
	                     sizeof(auth_status_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(auth_status_any_of,
		          auth_status_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
