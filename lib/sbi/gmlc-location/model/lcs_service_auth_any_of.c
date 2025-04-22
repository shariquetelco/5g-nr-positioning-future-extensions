#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lcs_service_auth_any_of.h"

char *lcs_service_auth_any_of_ToString(
	lcs_service_auth_any_of_e lcs_service_auth_any_of) {
	const char *lcs_service_auth_any_ofArray[] =
	{ "NULL", "LOCATION_ALLOWED_WITH_NOTIFICATION",
	  "LOCATION_ALLOWED_WITHOUT_NOTIFICATION",
	  "LOCATION_ALLOWED_WITHOUT_RESPONSE",
	  "LOCATION_RESTRICTED_WITHOUT_RESPONSE", "NOTIFICATION_ONLY",
	  "NOTIFICATION_AND_VERIFICATION_ONLY" };
	size_t sizeofArray = sizeof(lcs_service_auth_any_ofArray) /
	                     sizeof(lcs_service_auth_any_ofArray[0]);
	if(lcs_service_auth_any_of < sizeofArray) {
		return (char *) lcs_service_auth_any_ofArray[
			lcs_service_auth_any_of];
	} else {
		return (char *) "Unknown";
	}
}

lcs_service_auth_any_of_e lcs_service_auth_any_of_FromString(
	char *lcs_service_auth_any_of) {
	int stringToReturn = 0;
	const char *lcs_service_auth_any_ofArray[] =
	{ "NULL", "LOCATION_ALLOWED_WITH_NOTIFICATION",
	  "LOCATION_ALLOWED_WITHOUT_NOTIFICATION",
	  "LOCATION_ALLOWED_WITHOUT_RESPONSE",
	  "LOCATION_RESTRICTED_WITHOUT_RESPONSE", "NOTIFICATION_ONLY",
	  "NOTIFICATION_AND_VERIFICATION_ONLY" };
	size_t sizeofArray = sizeof(lcs_service_auth_any_ofArray) /
	                     sizeof(lcs_service_auth_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(lcs_service_auth_any_of,
		          lcs_service_auth_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
