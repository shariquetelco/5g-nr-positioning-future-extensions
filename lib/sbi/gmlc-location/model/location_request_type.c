#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_request_type.h"

char *location_request_type_ToString(
	location_request_type_e location_request_type) {
	const char *location_request_typeArray[] =
	{ "NULL", "NI_LR", "MT_LR", "MO_LR" };
	size_t sizeofArray = sizeof(location_request_typeArray) /
	                     sizeof(location_request_typeArray[0]);
	if(location_request_type < sizeofArray) {
		return (char *) location_request_typeArray[location_request_type
		];
	} else {
		return (char *) "Unknown";
	}
}

location_request_type_e location_request_type_FromString(
	char *location_request_type) {
	int stringToReturn = 0;
	const char *location_request_typeArray[] =
	{ "NULL", "NI_LR", "MT_LR", "MO_LR" };
	size_t sizeofArray = sizeof(location_request_typeArray) /
	                     sizeof(location_request_typeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(location_request_type,
		          location_request_typeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
