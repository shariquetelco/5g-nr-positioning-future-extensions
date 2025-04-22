#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lcs_priority.h"

char *lcs_priority_ToString(lcs_priority_e lcs_priority) {
	const char *lcs_priorityArray[] =
	{ "NULL", "HIGHEST_PRIORITY", "NORMAL_PRIORITY" };
	size_t sizeofArray = sizeof(lcs_priorityArray) /
	                     sizeof(lcs_priorityArray[0]);
	if(lcs_priority < sizeofArray) {
		return (char *) lcs_priorityArray[lcs_priority];
	} else {
		return (char *) "Unknown";
	}
}

lcs_priority_e lcs_priority_FromString(char *lcs_priority) {
	int stringToReturn = 0;
	const char *lcs_priorityArray[] =
	{ "NULL", "HIGHEST_PRIORITY", "NORMAL_PRIORITY" };
	size_t sizeofArray = sizeof(lcs_priorityArray) /
	                     sizeof(lcs_priorityArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(lcs_priority,
		          lcs_priorityArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
