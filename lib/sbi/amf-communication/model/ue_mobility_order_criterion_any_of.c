#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_mobility_order_criterion_any_of.h"

char *ue_mobility_order_criterion_any_of_ToString(
	ue_mobility_order_criterion_any_of_e ue_mobility_order_criterion_any_of)
{
	const char *ue_mobility_order_criterion_any_ofArray[] =
	{ "NULL", "TIME_SLOT" };
	size_t sizeofArray = sizeof(ue_mobility_order_criterion_any_ofArray) /
	                     sizeof(ue_mobility_order_criterion_any_ofArray[0]);
	if(ue_mobility_order_criterion_any_of < sizeofArray) {
		return (char *) ue_mobility_order_criterion_any_ofArray[
			ue_mobility_order_criterion_any_of];
	} else {
		return (char *) "Unknown";
	}
}

ue_mobility_order_criterion_any_of_e
ue_mobility_order_criterion_any_of_FromString(
	char *ue_mobility_order_criterion_any_of) {
	int stringToReturn = 0;
	const char *ue_mobility_order_criterion_any_ofArray[] =
	{ "NULL", "TIME_SLOT" };
	size_t sizeofArray = sizeof(ue_mobility_order_criterion_any_ofArray) /
	                     sizeof(ue_mobility_order_criterion_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(ue_mobility_order_criterion_any_of,
		          ue_mobility_order_criterion_any_ofArray[stringToReturn
		          ]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
