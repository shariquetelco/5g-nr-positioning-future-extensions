#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "core_network_type_any_of.h"

char *core_network_type_any_of_ToString(
	core_network_type_any_of_e core_network_type_any_of) {
	const char *core_network_type_any_ofArray[] = { "NULL", "5GC", "EPC" };
	size_t sizeofArray = sizeof(core_network_type_any_ofArray) /
	                     sizeof(core_network_type_any_ofArray[0]);
	if(core_network_type_any_of < sizeofArray) {
		return (char *) core_network_type_any_ofArray[
			core_network_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

core_network_type_any_of_e core_network_type_any_of_FromString(
	char *core_network_type_any_of) {
	int stringToReturn = 0;
	const char *core_network_type_any_ofArray[] = { "NULL", "5GC", "EPC" };
	size_t sizeofArray = sizeof(core_network_type_any_ofArray) /
	                     sizeof(core_network_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(core_network_type_any_of,
		          core_network_type_any_ofArray[stringToReturn]) == 0)
		{
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
