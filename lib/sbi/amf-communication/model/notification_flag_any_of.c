#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notification_flag_any_of.h"

char *notification_flag_any_of_ToString(
	notification_flag_any_of_e notification_flag_any_of) {
	const char *notification_flag_any_ofArray[] =
	{ "NULL", "ACTIVATE", "DEACTIVATE", "RETRIEVAL" };
	size_t sizeofArray = sizeof(notification_flag_any_ofArray) /
	                     sizeof(notification_flag_any_ofArray[0]);
	if(notification_flag_any_of < sizeofArray) {
		return (char *) notification_flag_any_ofArray[
			notification_flag_any_of];
	} else {
		return (char *) "Unknown";
	}
}

notification_flag_any_of_e notification_flag_any_of_FromString(
	char *notification_flag_any_of) {
	int stringToReturn = 0;
	const char *notification_flag_any_ofArray[] =
	{ "NULL", "ACTIVATE", "DEACTIVATE", "RETRIEVAL" };
	size_t sizeofArray = sizeof(notification_flag_any_ofArray) /
	                     sizeof(notification_flag_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(notification_flag_any_of,
		          notification_flag_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
