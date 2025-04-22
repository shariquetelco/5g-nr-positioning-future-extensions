#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "scheduled_communication_type_any_of.h"

char *scheduled_communication_type_any_of_ToString(
	scheduled_communication_type_any_of_e scheduled_communication_type_any_of)
{
	const char *scheduled_communication_type_any_ofArray[] =
	{ "NULL", "DOWNLINK_ONLY", "UPLINK_ONLY", "BIDIRECTIONAL" };
	size_t sizeofArray = sizeof(scheduled_communication_type_any_ofArray) /
	                     sizeof(scheduled_communication_type_any_ofArray[0]);
	if(scheduled_communication_type_any_of < sizeofArray) {
		return (char *) scheduled_communication_type_any_ofArray[
			scheduled_communication_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

scheduled_communication_type_any_of_e
scheduled_communication_type_any_of_FromString(
	char *scheduled_communication_type_any_of) {
	int stringToReturn = 0;
	const char *scheduled_communication_type_any_ofArray[] =
	{ "NULL", "DOWNLINK_ONLY", "UPLINK_ONLY", "BIDIRECTIONAL" };
	size_t sizeofArray = sizeof(scheduled_communication_type_any_ofArray) /
	                     sizeof(scheduled_communication_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(scheduled_communication_type_any_of,
		          scheduled_communication_type_any_ofArray[
				  stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
