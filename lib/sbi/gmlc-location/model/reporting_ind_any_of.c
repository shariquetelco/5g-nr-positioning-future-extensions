#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_ind_any_of.h"

char *reporting_ind_any_of_ToString(reporting_ind_any_of_e reporting_ind_any_of)
{
	const char *reporting_ind_any_ofArray[] =
	{ "NULL", "INSIDE_REPORTING", "OUTSIDE_REPORTING" };
	size_t sizeofArray = sizeof(reporting_ind_any_ofArray) /
	                     sizeof(reporting_ind_any_ofArray[0]);
	if(reporting_ind_any_of < sizeofArray) {
		return (char *) reporting_ind_any_ofArray[reporting_ind_any_of];
	} else {
		return (char *) "Unknown";
	}
}

reporting_ind_any_of_e reporting_ind_any_of_FromString(
	char *reporting_ind_any_of) {
	int stringToReturn = 0;
	const char *reporting_ind_any_ofArray[] =
	{ "NULL", "INSIDE_REPORTING", "OUTSIDE_REPORTING" };
	size_t sizeofArray = sizeof(reporting_ind_any_ofArray) /
	                     sizeof(reporting_ind_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(reporting_ind_any_of,
		          reporting_ind_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
