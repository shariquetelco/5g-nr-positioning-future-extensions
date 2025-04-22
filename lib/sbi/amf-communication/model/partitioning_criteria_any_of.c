#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "partitioning_criteria_any_of.h"

char *partitioning_criteria_any_of_ToString(
	partitioning_criteria_any_of_e partitioning_criteria_any_of) {
	const char *partitioning_criteria_any_ofArray[] =
	{ "NULL", "TAC", "SUBPLMN", "GEOAREA", "SNSSAI", "DNN" };
	size_t sizeofArray = sizeof(partitioning_criteria_any_ofArray) /
	                     sizeof(partitioning_criteria_any_ofArray[0]);
	if(partitioning_criteria_any_of < sizeofArray) {
		return (char *) partitioning_criteria_any_ofArray[
			partitioning_criteria_any_of];
	} else {
		return (char *) "Unknown";
	}
}

partitioning_criteria_any_of_e partitioning_criteria_any_of_FromString(
	char *partitioning_criteria_any_of) {
	int stringToReturn = 0;
	const char *partitioning_criteria_any_ofArray[] =
	{ "NULL", "TAC", "SUBPLMN", "GEOAREA", "SNSSAI", "DNN" };
	size_t sizeofArray = sizeof(partitioning_criteria_any_ofArray) /
	                     sizeof(partitioning_criteria_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(partitioning_criteria_any_of,
		          partitioning_criteria_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
