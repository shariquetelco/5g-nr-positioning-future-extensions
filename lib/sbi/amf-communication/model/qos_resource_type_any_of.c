#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "qos_resource_type_any_of.h"

char *qos_resource_type_any_of_ToString(
	qos_resource_type_any_of_e qos_resource_type_any_of) {
	const char *qos_resource_type_any_ofArray[] =
	{ "NULL", "NON_GBR", "NON_CRITICAL_GBR", "CRITICAL_GBR" };
	size_t sizeofArray = sizeof(qos_resource_type_any_ofArray) /
	                     sizeof(qos_resource_type_any_ofArray[0]);
	if(qos_resource_type_any_of < sizeofArray) {
		return (char *) qos_resource_type_any_ofArray[
			qos_resource_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

qos_resource_type_any_of_e qos_resource_type_any_of_FromString(
	char *qos_resource_type_any_of) {
	int stringToReturn = 0;
	const char *qos_resource_type_any_ofArray[] =
	{ "NULL", "NON_GBR", "NON_CRITICAL_GBR", "CRITICAL_GBR" };
	size_t sizeofArray = sizeof(qos_resource_type_any_ofArray) /
	                     sizeof(qos_resource_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(qos_resource_type_any_of,
		          qos_resource_type_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
