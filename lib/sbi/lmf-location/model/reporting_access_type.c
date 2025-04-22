#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_access_type.h"

char *reporting_access_type_ToString(
	reporting_access_type_e reporting_access_type) {
	const char *reporting_access_typeArray[] =
	{ "NULL", "NR", "EUTRA_CONNECTED_TO_5GC", "NON_3GPP_CONNECTED_TO_5GC",
	  "NR_LEO", "NR_MEO", "NR_GEO", "NR_OTHER_SAT",
	  "EUTRA_CONNECTED_TO_EPC" };
	size_t sizeofArray = sizeof(reporting_access_typeArray) /
	                     sizeof(reporting_access_typeArray[0]);
	if(reporting_access_type < sizeofArray) {
		return (char *) reporting_access_typeArray[reporting_access_type
		];
	} else {
		return (char *) "Unknown";
	}
}

reporting_access_type_e reporting_access_type_FromString(
	char *reporting_access_type) {
	int stringToReturn = 0;
	const char *reporting_access_typeArray[] =
	{ "NULL", "NR", "EUTRA_CONNECTED_TO_5GC", "NON_3GPP_CONNECTED_TO_5GC",
	  "NR_LEO", "NR_MEO", "NR_GEO", "NR_OTHER_SAT",
	  "EUTRA_CONNECTED_TO_EPC" };
	size_t sizeofArray = sizeof(reporting_access_typeArray) /
	                     sizeof(reporting_access_typeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(reporting_access_type,
		          reporting_access_typeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
