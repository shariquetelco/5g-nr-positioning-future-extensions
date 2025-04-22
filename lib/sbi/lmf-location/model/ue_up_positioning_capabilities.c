#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_up_positioning_capabilities.h"

char *ue_up_positioning_capabilities_ToString(
	ue_up_positioning_capabilities_e ue_up_positioning_capabilities) {
	const char *ue_up_positioning_capabilitiesArray[] =
	{ "NULL", "LCS-UPP", "SUPL" };
	size_t sizeofArray = sizeof(ue_up_positioning_capabilitiesArray) /
	                     sizeof(ue_up_positioning_capabilitiesArray[0]);
	if(ue_up_positioning_capabilities < sizeofArray) {
		return (char *) ue_up_positioning_capabilitiesArray[
			ue_up_positioning_capabilities];
	} else {
		return (char *) "Unknown";
	}
}

ue_up_positioning_capabilities_e ue_up_positioning_capabilities_FromString(
	char *ue_up_positioning_capabilities) {
	int stringToReturn = 0;
	const char *ue_up_positioning_capabilitiesArray[] =
	{ "NULL", "LCS-UPP", "SUPL" };
	size_t sizeofArray = sizeof(ue_up_positioning_capabilitiesArray) /
	                     sizeof(ue_up_positioning_capabilitiesArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(ue_up_positioning_capabilities,
		          ue_up_positioning_capabilitiesArray[stringToReturn])
		   == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
