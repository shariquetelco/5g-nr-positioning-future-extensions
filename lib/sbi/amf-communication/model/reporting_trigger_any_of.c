#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_trigger_any_of.h"

char *reporting_trigger_any_of_ToString(
	reporting_trigger_any_of_e reporting_trigger_any_of) {
	const char *reporting_trigger_any_ofArray[] =
	{ "NULL", "PERIODICAL", "EVENT_A2", "EVENT_A2_PERIODIC",
	  "ALL_RRM_EVENT_TRIGGERS" };
	size_t sizeofArray = sizeof(reporting_trigger_any_ofArray) /
	                     sizeof(reporting_trigger_any_ofArray[0]);
	if(reporting_trigger_any_of < sizeofArray) {
		return (char *) reporting_trigger_any_ofArray[
			reporting_trigger_any_of];
	} else {
		return (char *) "Unknown";
	}
}

reporting_trigger_any_of_e reporting_trigger_any_of_FromString(
	char *reporting_trigger_any_of) {
	int stringToReturn = 0;
	const char *reporting_trigger_any_ofArray[] =
	{ "NULL", "PERIODICAL", "EVENT_A2", "EVENT_A2_PERIODIC",
	  "ALL_RRM_EVENT_TRIGGERS" };
	size_t sizeofArray = sizeof(reporting_trigger_any_ofArray) /
	                     sizeof(reporting_trigger_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(reporting_trigger_any_of,
		          reporting_trigger_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
