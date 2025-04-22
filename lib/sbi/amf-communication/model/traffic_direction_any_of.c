#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "traffic_direction_any_of.h"

char *traffic_direction_any_of_ToString(
	traffic_direction_any_of_e traffic_direction_any_of) {
	const char *traffic_direction_any_ofArray[] =
	{ "NULL", "UL_AND_DL", "UL", "DL" };
	size_t sizeofArray = sizeof(traffic_direction_any_ofArray) /
	                     sizeof(traffic_direction_any_ofArray[0]);
	if(traffic_direction_any_of < sizeofArray) {
		return (char *) traffic_direction_any_ofArray[
			traffic_direction_any_of];
	} else {
		return (char *) "Unknown";
	}
}

traffic_direction_any_of_e traffic_direction_any_of_FromString(
	char *traffic_direction_any_of) {
	int stringToReturn = 0;
	const char *traffic_direction_any_ofArray[] =
	{ "NULL", "UL_AND_DL", "UL", "DL" };
	size_t sizeofArray = sizeof(traffic_direction_any_ofArray) /
	                     sizeof(traffic_direction_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(traffic_direction_any_of,
		          traffic_direction_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
