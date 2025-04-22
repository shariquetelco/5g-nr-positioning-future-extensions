#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "recur_type_any_of.h"

char *recur_type_any_of_ToString(recur_type_any_of_e recur_type_any_of) {
	const char *recur_type_any_ofArray[] =
	{ "NULL", "DAILY", "WEEKLY", "MONTHLY_BY_DATE", "MONTHLY_BY_DAY",
	  "YEARLY", "WEEKDAYS_ONLY", "WEEKENDS_ONLY" };
	size_t sizeofArray = sizeof(recur_type_any_ofArray) /
	                     sizeof(recur_type_any_ofArray[0]);
	if(recur_type_any_of < sizeofArray) {
		return (char *) recur_type_any_ofArray[recur_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

recur_type_any_of_e recur_type_any_of_FromString(char *recur_type_any_of) {
	int stringToReturn = 0;
	const char *recur_type_any_ofArray[] =
	{ "NULL", "DAILY", "WEEKLY", "MONTHLY_BY_DATE", "MONTHLY_BY_DAY",
	  "YEARLY", "WEEKDAYS_ONLY", "WEEKENDS_ONLY" };
	size_t sizeofArray = sizeof(recur_type_any_ofArray) /
	                     sizeof(recur_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(recur_type_any_of,
		          recur_type_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
