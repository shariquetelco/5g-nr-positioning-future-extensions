#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "traffic_profile_any_of.h"

char *traffic_profile_any_of_ToString(
	traffic_profile_any_of_e traffic_profile_any_of) {
	const char *traffic_profile_any_ofArray[] =
	{ "NULL", "SINGLE_TRANS_UL", "SINGLE_TRANS_DL", "DUAL_TRANS_UL_FIRST",
	  "DUAL_TRANS_DL_FIRST", "MULTI_TRANS" };
	size_t sizeofArray = sizeof(traffic_profile_any_ofArray) /
	                     sizeof(traffic_profile_any_ofArray[0]);
	if(traffic_profile_any_of < sizeofArray) {
		return (char *) traffic_profile_any_ofArray[
			traffic_profile_any_of];
	} else {
		return (char *) "Unknown";
	}
}

traffic_profile_any_of_e traffic_profile_any_of_FromString(
	char *traffic_profile_any_of) {
	int stringToReturn = 0;
	const char *traffic_profile_any_ofArray[] =
	{ "NULL", "SINGLE_TRANS_UL", "SINGLE_TRANS_DL", "DUAL_TRANS_UL_FIRST",
	  "DUAL_TRANS_DL_FIRST", "MULTI_TRANS" };
	size_t sizeofArray = sizeof(traffic_profile_any_ofArray) /
	                     sizeof(traffic_profile_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(traffic_profile_any_of,
		          traffic_profile_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
