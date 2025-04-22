#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "analytics_accuracy_indication_any_of.h"

char *analytics_accuracy_indication_any_of_ToString(
	analytics_accuracy_indication_any_of_e analytics_accuracy_indication_any_of)
{
	const char *analytics_accuracy_indication_any_ofArray[] =
	{ "NULL", "MEET", "NOT_MEET" };
	size_t sizeofArray = sizeof(analytics_accuracy_indication_any_ofArray) /
	                     sizeof(analytics_accuracy_indication_any_ofArray[0]);
	if(analytics_accuracy_indication_any_of < sizeofArray) {
		return (char *) analytics_accuracy_indication_any_ofArray[
			analytics_accuracy_indication_any_of];
	} else {
		return (char *) "Unknown";
	}
}

analytics_accuracy_indication_any_of_e
analytics_accuracy_indication_any_of_FromString(
	char *analytics_accuracy_indication_any_of) {
	int stringToReturn = 0;
	const char *analytics_accuracy_indication_any_ofArray[] =
	{ "NULL", "MEET", "NOT_MEET" };
	size_t sizeofArray = sizeof(analytics_accuracy_indication_any_ofArray) /
	                     sizeof(analytics_accuracy_indication_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(analytics_accuracy_indication_any_of,
		          analytics_accuracy_indication_any_ofArray[
				  stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
