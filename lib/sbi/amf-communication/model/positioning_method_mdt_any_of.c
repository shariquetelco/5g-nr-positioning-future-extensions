#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "positioning_method_mdt_any_of.h"

char *positioning_method_mdt_any_of_ToString(
	positioning_method_mdt_any_of_e positioning_method_mdt_any_of) {
	const char *positioning_method_mdt_any_ofArray[] =
	{ "NULL", "GNSS", "E_CELL_ID" };
	size_t sizeofArray = sizeof(positioning_method_mdt_any_ofArray) /
	                     sizeof(positioning_method_mdt_any_ofArray[0]);
	if(positioning_method_mdt_any_of < sizeofArray) {
		return (char *) positioning_method_mdt_any_ofArray[
			positioning_method_mdt_any_of];
	} else {
		return (char *) "Unknown";
	}
}

positioning_method_mdt_any_of_e positioning_method_mdt_any_of_FromString(
	char *positioning_method_mdt_any_of) {
	int stringToReturn = 0;
	const char *positioning_method_mdt_any_ofArray[] =
	{ "NULL", "GNSS", "E_CELL_ID" };
	size_t sizeofArray = sizeof(positioning_method_mdt_any_ofArray) /
	                     sizeof(positioning_method_mdt_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(positioning_method_mdt_any_of,
		          positioning_method_mdt_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
