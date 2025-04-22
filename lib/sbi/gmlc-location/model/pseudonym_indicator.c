#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pseudonym_indicator.h"

char *pseudonym_indicator_ToString(pseudonym_indicator_e pseudonym_indicator) {
	const char *pseudonym_indicatorArray[] =
	{ "NULL", "PSEUDONYM_REQUESTED", "PSEUDONYM_NOT_REQUESTED" };
	size_t sizeofArray = sizeof(pseudonym_indicatorArray) /
	                     sizeof(pseudonym_indicatorArray[0]);
	if(pseudonym_indicator < sizeofArray) {
		return (char *) pseudonym_indicatorArray[pseudonym_indicator];
	} else {
		return (char *) "Unknown";
	}
}

pseudonym_indicator_e pseudonym_indicator_FromString(char *pseudonym_indicator)
{
	int stringToReturn = 0;
	const char *pseudonym_indicatorArray[] =
	{ "NULL", "PSEUDONYM_REQUESTED", "PSEUDONYM_NOT_REQUESTED" };
	size_t sizeofArray = sizeof(pseudonym_indicatorArray) /
	                     sizeof(pseudonym_indicatorArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(pseudonym_indicator,
		          pseudonym_indicatorArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
