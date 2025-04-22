#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "satellite_backhaul_category_any_of.h"

char *satellite_backhaul_category_any_of_ToString(
	satellite_backhaul_category_any_of_e satellite_backhaul_category_any_of)
{
	const char *satellite_backhaul_category_any_ofArray[] =
	{ "NULL", "GEO", "MEO", "LEO", "OTHER_SAT", "DYNAMIC_GEO",
	  "DYNAMIC_MEO", "DYNAMIC_LEO", "DYNAMIC_OTHER_SAT",
	  "NON_SATELLITE" };
	size_t sizeofArray = sizeof(satellite_backhaul_category_any_ofArray) /
	                     sizeof(satellite_backhaul_category_any_ofArray[0]);
	if(satellite_backhaul_category_any_of < sizeofArray) {
		return (char *) satellite_backhaul_category_any_ofArray[
			satellite_backhaul_category_any_of];
	} else {
		return (char *) "Unknown";
	}
}

satellite_backhaul_category_any_of_e
satellite_backhaul_category_any_of_FromString(
	char *satellite_backhaul_category_any_of) {
	int stringToReturn = 0;
	const char *satellite_backhaul_category_any_ofArray[] =
	{ "NULL", "GEO", "MEO", "LEO", "OTHER_SAT", "DYNAMIC_GEO",
	  "DYNAMIC_MEO", "DYNAMIC_LEO", "DYNAMIC_OTHER_SAT",
	  "NON_SATELLITE" };
	size_t sizeofArray = sizeof(satellite_backhaul_category_any_ofArray) /
	                     sizeof(satellite_backhaul_category_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(satellite_backhaul_category_any_of,
		          satellite_backhaul_category_any_ofArray[stringToReturn
		          ]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
