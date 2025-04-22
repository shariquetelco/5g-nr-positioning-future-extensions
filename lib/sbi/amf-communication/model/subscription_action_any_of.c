#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subscription_action_any_of.h"

char *subscription_action_any_of_ToString(
	subscription_action_any_of_e subscription_action_any_of) {
	const char *subscription_action_any_ofArray[] =
	{ "NULL", "CLOSE", "CONTINUE_WITH_MUTING", "CONTINUE_WITHOUT_MUTING" };
	size_t sizeofArray = sizeof(subscription_action_any_ofArray) /
	                     sizeof(subscription_action_any_ofArray[0]);
	if(subscription_action_any_of < sizeofArray) {
		return (char *) subscription_action_any_ofArray[
			subscription_action_any_of];
	} else {
		return (char *) "Unknown";
	}
}

subscription_action_any_of_e subscription_action_any_of_FromString(
	char *subscription_action_any_of) {
	int stringToReturn = 0;
	const char *subscription_action_any_ofArray[] =
	{ "NULL", "CLOSE", "CONTINUE_WITH_MUTING", "CONTINUE_WITHOUT_MUTING" };
	size_t sizeofArray = sizeof(subscription_action_any_ofArray) /
	                     sizeof(subscription_action_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(subscription_action_any_of,
		          subscription_action_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
