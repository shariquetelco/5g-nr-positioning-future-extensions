#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "accuracy_fulfilment_indicator.h"

char *accuracy_fulfilment_indicator_ToString(
	accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator) {
	const char *accuracy_fulfilment_indicatorArray[] =
	{ "NULL", "REQUESTED_ACCURACY_FULFILLED",
	  "REQUESTED_ACCURACY_NOT_FULFILLED" };
	size_t sizeofArray = sizeof(accuracy_fulfilment_indicatorArray) /
	                     sizeof(accuracy_fulfilment_indicatorArray[0]);
	if(accuracy_fulfilment_indicator < sizeofArray) {
		return (char *) accuracy_fulfilment_indicatorArray[
			accuracy_fulfilment_indicator];
	} else {
		return (char *) "Unknown";
	}
}

accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator_FromString(
	char *accuracy_fulfilment_indicator) {
	int stringToReturn = 0;
	const char *accuracy_fulfilment_indicatorArray[] =
	{ "NULL", "REQUESTED_ACCURACY_FULFILLED",
	  "REQUESTED_ACCURACY_NOT_FULFILLED" };
	size_t sizeofArray = sizeof(accuracy_fulfilment_indicatorArray) /
	                     sizeof(accuracy_fulfilment_indicatorArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(accuracy_fulfilment_indicator,
		          accuracy_fulfilment_indicatorArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
