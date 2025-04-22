#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job_type_any_of.h"

char *job_type_any_of_ToString(job_type_any_of_e job_type_any_of) {
	const char *job_type_any_ofArray[] =
	{ "NULL", "IMMEDIATE_MDT_ONLY", "LOGGED_MDT_ONLY", "TRACE_ONLY",
	  "IMMEDIATE_MDT_AND_TRACE", "RLF_REPORTS_ONLY",
	  "RCEF_REPORTS_ONLY", "LOGGED_MBSFN_MDT" };
	size_t sizeofArray = sizeof(job_type_any_ofArray) /
	                     sizeof(job_type_any_ofArray[0]);
	if(job_type_any_of < sizeofArray) {
		return (char *) job_type_any_ofArray[job_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

job_type_any_of_e job_type_any_of_FromString(char *job_type_any_of) {
	int stringToReturn = 0;
	const char *job_type_any_ofArray[] =
	{ "NULL", "IMMEDIATE_MDT_ONLY", "LOGGED_MDT_ONLY", "TRACE_ONLY",
	  "IMMEDIATE_MDT_AND_TRACE", "RLF_REPORTS_ONLY",
	  "RCEF_REPORTS_ONLY", "LOGGED_MBSFN_MDT" };
	size_t sizeofArray = sizeof(job_type_any_ofArray) /
	                     sizeof(job_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(job_type_any_of,
		          job_type_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
