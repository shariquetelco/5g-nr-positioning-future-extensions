#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_auth_any_of.h"

char *ue_auth_any_of_ToString(ue_auth_any_of_e ue_auth_any_of) {
	const char *ue_auth_any_ofArray[] =
	{ "NULL", "AUTHORIZED", "NOT_AUTHORIZED" };
	size_t sizeofArray = sizeof(ue_auth_any_ofArray) /
	                     sizeof(ue_auth_any_ofArray[0]);
	if(ue_auth_any_of < sizeofArray) {
		return (char *) ue_auth_any_ofArray[ue_auth_any_of];
	} else {
		return (char *) "Unknown";
	}
}

ue_auth_any_of_e ue_auth_any_of_FromString(char *ue_auth_any_of) {
	int stringToReturn = 0;
	const char *ue_auth_any_ofArray[] =
	{ "NULL", "AUTHORIZED", "NOT_AUTHORIZED" };
	size_t sizeofArray = sizeof(ue_auth_any_ofArray) /
	                     sizeof(ue_auth_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(ue_auth_any_of,
		          ue_auth_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
