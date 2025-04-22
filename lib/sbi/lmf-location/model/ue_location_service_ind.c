#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_location_service_ind.h"

char *ue_location_service_ind_ToString(
	ue_location_service_ind_e ue_location_service_ind) {
	const char *ue_location_service_indArray[] =
	{ "NULL", "LOCATION_ESTIMATE", "LOCATION_ASSISTANCE_DATA" };
	size_t sizeofArray = sizeof(ue_location_service_indArray) /
	                     sizeof(ue_location_service_indArray[0]);
	if(ue_location_service_ind < sizeofArray) {
		return (char *) ue_location_service_indArray[
			ue_location_service_ind];
	} else {
		return (char *) "Unknown";
	}
}

ue_location_service_ind_e ue_location_service_ind_FromString(
	char *ue_location_service_ind) {
	int stringToReturn = 0;
	const char *ue_location_service_indArray[] =
	{ "NULL", "LOCATION_ESTIMATE", "LOCATION_ASSISTANCE_DATA" };
	size_t sizeofArray = sizeof(ue_location_service_indArray) /
	                     sizeof(ue_location_service_indArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(ue_location_service_ind,
		          ue_location_service_indArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
