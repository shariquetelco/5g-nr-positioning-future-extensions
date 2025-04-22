#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "storage_outcome.h"

char *storage_outcome_ToString(storage_outcome_e storage_outcome) {
	const char *storage_outcomeArray[] =
	{ "NULL", "STORAGE_SUCCESSFUL", "STORAGE_FAILED" };
	size_t sizeofArray = sizeof(storage_outcomeArray) /
	                     sizeof(storage_outcomeArray[0]);
	if(storage_outcome < sizeofArray) {
		return (char *) storage_outcomeArray[storage_outcome];
	} else {
		return (char *) "Unknown";
	}
}

storage_outcome_e storage_outcome_FromString(char *storage_outcome) {
	int stringToReturn = 0;
	const char *storage_outcomeArray[] =
	{ "NULL", "STORAGE_SUCCESSFUL", "STORAGE_FAILED" };
	size_t sizeofArray = sizeof(storage_outcomeArray) /
	                     sizeof(storage_outcomeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(storage_outcome,
		          storage_outcomeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
