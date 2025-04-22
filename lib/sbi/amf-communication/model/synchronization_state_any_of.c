#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "synchronization_state_any_of.h"

char *synchronization_state_any_of_ToString(
	synchronization_state_any_of_e synchronization_state_any_of) {
	const char *synchronization_state_any_ofArray[] =
	{ "NULL", "LOCKED", "HOLDOVER", "FREERUN" };
	size_t sizeofArray = sizeof(synchronization_state_any_ofArray) /
	                     sizeof(synchronization_state_any_ofArray[0]);
	if(synchronization_state_any_of < sizeofArray) {
		return (char *) synchronization_state_any_ofArray[
			synchronization_state_any_of];
	} else {
		return (char *) "Unknown";
	}
}

synchronization_state_any_of_e synchronization_state_any_of_FromString(
	char *synchronization_state_any_of) {
	int stringToReturn = 0;
	const char *synchronization_state_any_ofArray[] =
	{ "NULL", "LOCKED", "HOLDOVER", "FREERUN" };
	size_t sizeofArray = sizeof(synchronization_state_any_ofArray) /
	                     sizeof(synchronization_state_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(synchronization_state_any_of,
		          synchronization_state_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
