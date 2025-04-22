#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_comm_order_criterion_any_of.h"

char *ue_comm_order_criterion_any_of_ToString(
	ue_comm_order_criterion_any_of_e ue_comm_order_criterion_any_of) {
	const char *ue_comm_order_criterion_any_ofArray[] =
	{ "NULL", "START_TIME", "DURATION" };
	size_t sizeofArray = sizeof(ue_comm_order_criterion_any_ofArray) /
	                     sizeof(ue_comm_order_criterion_any_ofArray[0]);
	if(ue_comm_order_criterion_any_of < sizeofArray) {
		return (char *) ue_comm_order_criterion_any_ofArray[
			ue_comm_order_criterion_any_of];
	} else {
		return (char *) "Unknown";
	}
}

ue_comm_order_criterion_any_of_e ue_comm_order_criterion_any_of_FromString(
	char *ue_comm_order_criterion_any_of) {
	int stringToReturn = 0;
	const char *ue_comm_order_criterion_any_ofArray[] =
	{ "NULL", "START_TIME", "DURATION" };
	size_t sizeofArray = sizeof(ue_comm_order_criterion_any_ofArray) /
	                     sizeof(ue_comm_order_criterion_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(ue_comm_order_criterion_any_of,
		          ue_comm_order_criterion_any_ofArray[stringToReturn])
		   == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
