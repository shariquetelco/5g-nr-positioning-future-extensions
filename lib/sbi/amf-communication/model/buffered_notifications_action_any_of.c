#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "buffered_notifications_action_any_of.h"

char *buffered_notifications_action_any_of_ToString(
	buffered_notifications_action_any_of_e buffered_notifications_action_any_of)
{
	const char *buffered_notifications_action_any_ofArray[] =
	{ "NULL", "SEND_ALL", "DISCARD_ALL", "DROP_OLD" };
	size_t sizeofArray = sizeof(buffered_notifications_action_any_ofArray) /
	                     sizeof(buffered_notifications_action_any_ofArray[0]);
	if(buffered_notifications_action_any_of < sizeofArray) {
		return (char *) buffered_notifications_action_any_ofArray[
			buffered_notifications_action_any_of];
	} else {
		return (char *) "Unknown";
	}
}

buffered_notifications_action_any_of_e
buffered_notifications_action_any_of_FromString(
	char *buffered_notifications_action_any_of) {
	int stringToReturn = 0;
	const char *buffered_notifications_action_any_ofArray[] =
	{ "NULL", "SEND_ALL", "DISCARD_ALL", "DROP_OLD" };
	size_t sizeofArray = sizeof(buffered_notifications_action_any_ofArray) /
	                     sizeof(buffered_notifications_action_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(buffered_notifications_action_any_of,
		          buffered_notifications_action_any_ofArray[
				  stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
