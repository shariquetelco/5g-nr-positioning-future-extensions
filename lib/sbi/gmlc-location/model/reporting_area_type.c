#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_area_type.h"

char *reporting_area_type_ToString(reporting_area_type_e reporting_area_type) {
	const char *reporting_area_typeArray[] =
	{ "NULL", "EPS_TRACKING_AREA_IDENTITY",
	  "E-UTRAN_CELL_GLOBAL_IDENTIFICATION",
	  "5GS_TRACKING_AREA_IDENTITY", "NR_CELL_GLOBAL_IDENTITY" };
	size_t sizeofArray = sizeof(reporting_area_typeArray) /
	                     sizeof(reporting_area_typeArray[0]);
	if(reporting_area_type < sizeofArray) {
		return (char *) reporting_area_typeArray[reporting_area_type];
	} else {
		return (char *) "Unknown";
	}
}

reporting_area_type_e reporting_area_type_FromString(char *reporting_area_type)
{
	int stringToReturn = 0;
	const char *reporting_area_typeArray[] =
	{ "NULL", "EPS_TRACKING_AREA_IDENTITY",
	  "E-UTRAN_CELL_GLOBAL_IDENTIFICATION",
	  "5GS_TRACKING_AREA_IDENTITY", "NR_CELL_GLOBAL_IDENTITY" };
	size_t sizeofArray = sizeof(reporting_area_typeArray) /
	                     sizeof(reporting_area_typeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(reporting_area_type,
		          reporting_area_typeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
