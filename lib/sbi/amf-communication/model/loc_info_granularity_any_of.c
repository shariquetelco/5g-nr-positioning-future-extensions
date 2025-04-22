#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_info_granularity_any_of.h"

char *loc_info_granularity_any_of_ToString(
	loc_info_granularity_any_of_e loc_info_granularity_any_of) {
	const char *loc_info_granularity_any_ofArray[] =
	{ "NULL", "TA_LEVEL", "CELL_LEVEL", "LON_AND_LAT_LEVEL" };
	size_t sizeofArray = sizeof(loc_info_granularity_any_ofArray) /
	                     sizeof(loc_info_granularity_any_ofArray[0]);
	if(loc_info_granularity_any_of < sizeofArray) {
		return (char *) loc_info_granularity_any_ofArray[
			loc_info_granularity_any_of];
	} else {
		return (char *) "Unknown";
	}
}

loc_info_granularity_any_of_e loc_info_granularity_any_of_FromString(
	char *loc_info_granularity_any_of) {
	int stringToReturn = 0;
	const char *loc_info_granularity_any_ofArray[] =
	{ "NULL", "TA_LEVEL", "CELL_LEVEL", "LON_AND_LAT_LEVEL" };
	size_t sizeofArray = sizeof(loc_info_granularity_any_ofArray) /
	                     sizeof(loc_info_granularity_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(loc_info_granularity_any_of,
		          loc_info_granularity_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
