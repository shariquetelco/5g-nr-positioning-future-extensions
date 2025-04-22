#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "clock_quality_detail_level_any_of.h"

char *clock_quality_detail_level_any_of_ToString(
	clock_quality_detail_level_any_of_e clock_quality_detail_level_any_of) {
	const char *clock_quality_detail_level_any_ofArray[] =
	{ "NULL", "CLOCK_QUALITY_METRICS", "ACCEPT_INDICATION" };
	size_t sizeofArray = sizeof(clock_quality_detail_level_any_ofArray) /
	                     sizeof(clock_quality_detail_level_any_ofArray[0]);
	if(clock_quality_detail_level_any_of < sizeofArray) {
		return (char *) clock_quality_detail_level_any_ofArray[
			clock_quality_detail_level_any_of];
	} else {
		return (char *) "Unknown";
	}
}

clock_quality_detail_level_any_of_e clock_quality_detail_level_any_of_FromString(
	char *clock_quality_detail_level_any_of) {
	int stringToReturn = 0;
	const char *clock_quality_detail_level_any_ofArray[] =
	{ "NULL", "CLOCK_QUALITY_METRICS", "ACCEPT_INDICATION" };
	size_t sizeofArray = sizeof(clock_quality_detail_level_any_ofArray) /
	                     sizeof(clock_quality_detail_level_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(clock_quality_detail_level_any_of,
		          clock_quality_detail_level_any_ofArray[stringToReturn])
		   == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
