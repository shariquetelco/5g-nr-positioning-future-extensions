#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "preemption_capability_any_of.h"

char *preemption_capability_any_of_ToString(
	preemption_capability_any_of_e preemption_capability_any_of) {
	const char *preemption_capability_any_ofArray[] =
	{ "NULL", "NOT_PREEMPT", "MAY_PREEMPT" };
	size_t sizeofArray = sizeof(preemption_capability_any_ofArray) /
	                     sizeof(preemption_capability_any_ofArray[0]);
	if(preemption_capability_any_of < sizeofArray) {
		return (char *) preemption_capability_any_ofArray[
			preemption_capability_any_of];
	} else {
		return (char *) "Unknown";
	}
}

preemption_capability_any_of_e preemption_capability_any_of_FromString(
	char *preemption_capability_any_of) {
	int stringToReturn = 0;
	const char *preemption_capability_any_ofArray[] =
	{ "NULL", "NOT_PREEMPT", "MAY_PREEMPT" };
	size_t sizeofArray = sizeof(preemption_capability_any_ofArray) /
	                     sizeof(preemption_capability_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(preemption_capability_any_of,
		          preemption_capability_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
