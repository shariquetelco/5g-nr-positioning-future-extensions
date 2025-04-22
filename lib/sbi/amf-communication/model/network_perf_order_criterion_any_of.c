#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_perf_order_criterion_any_of.h"

char *network_perf_order_criterion_any_of_ToString(
	network_perf_order_criterion_any_of_e network_perf_order_criterion_any_of)
{
	const char *network_perf_order_criterion_any_ofArray[] =
	{ "NULL", "NUMBER_OF_UES", "COMMUNICATION_PERF", "MOBILITY_PERF" };
	size_t sizeofArray = sizeof(network_perf_order_criterion_any_ofArray) /
	                     sizeof(network_perf_order_criterion_any_ofArray[0]);
	if(network_perf_order_criterion_any_of < sizeofArray) {
		return (char *) network_perf_order_criterion_any_ofArray[
			network_perf_order_criterion_any_of];
	} else {
		return (char *) "Unknown";
	}
}

network_perf_order_criterion_any_of_e
network_perf_order_criterion_any_of_FromString(
	char *network_perf_order_criterion_any_of) {
	int stringToReturn = 0;
	const char *network_perf_order_criterion_any_ofArray[] =
	{ "NULL", "NUMBER_OF_UES", "COMMUNICATION_PERF", "MOBILITY_PERF" };
	size_t sizeofArray = sizeof(network_perf_order_criterion_any_ofArray) /
	                     sizeof(network_perf_order_criterion_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(network_perf_order_criterion_any_of,
		          network_perf_order_criterion_any_ofArray[
				  stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
