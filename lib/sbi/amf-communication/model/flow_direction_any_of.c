#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "flow_direction_any_of.h"

char *flow_direction_any_of_ToString(
	flow_direction_any_of_e flow_direction_any_of) {
	const char *flow_direction_any_ofArray[] =
	{ "NULL", "DOWNLINK", "UPLINK", "BIDIRECTIONAL", "UNSPECIFIED" };
	size_t sizeofArray = sizeof(flow_direction_any_ofArray) /
	                     sizeof(flow_direction_any_ofArray[0]);
	if(flow_direction_any_of < sizeofArray) {
		return (char *) flow_direction_any_ofArray[flow_direction_any_of
		];
	} else {
		return (char *) "Unknown";
	}
}

flow_direction_any_of_e flow_direction_any_of_FromString(
	char *flow_direction_any_of) {
	int stringToReturn = 0;
	const char *flow_direction_any_ofArray[] =
	{ "NULL", "DOWNLINK", "UPLINK", "BIDIRECTIONAL", "UNSPECIFIED" };
	size_t sizeofArray = sizeof(flow_direction_any_ofArray) /
	                     sizeof(flow_direction_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(flow_direction_any_of,
		          flow_direction_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
