#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_connection_status_any_of.h"

char *up_connection_status_any_of_ToString(
	up_connection_status_any_of_e up_connection_status_any_of) {
	const char *up_connection_status_any_ofArray[] =
	{ "NULL", "ESTABLISHED", "RELEASED", "MOVE" };
	size_t sizeofArray = sizeof(up_connection_status_any_ofArray) /
	                     sizeof(up_connection_status_any_ofArray[0]);
	if(up_connection_status_any_of < sizeofArray) {
		return (char *) up_connection_status_any_ofArray[
			up_connection_status_any_of];
	} else {
		return (char *) "Unknown";
	}
}

up_connection_status_any_of_e up_connection_status_any_of_FromString(
	char *up_connection_status_any_of) {
	int stringToReturn = 0;
	const char *up_connection_status_any_ofArray[] =
	{ "NULL", "ESTABLISHED", "RELEASED", "MOVE" };
	size_t sizeofArray = sizeof(up_connection_status_any_ofArray) /
	                     sizeof(up_connection_status_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(up_connection_status_any_of,
		          up_connection_status_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
