#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fix_type.h"

char *fix_type_ToString(fix_type_e fix_type) {
	const char *fix_typeArray[] =
	{ "NULL", "CARRIER_PHASE_FLOAT", "CARRIER_PHASE_FIX" };
	size_t sizeofArray = sizeof(fix_typeArray) / sizeof(fix_typeArray[0]);
	if(fix_type < sizeofArray) {
		return (char *) fix_typeArray[fix_type];
	} else {
		return (char *) "Unknown";
	}
}

fix_type_e fix_type_FromString(char *fix_type) {
	int stringToReturn = 0;
	const char *fix_typeArray[] =
	{ "NULL", "CARRIER_PHASE_FLOAT", "CARRIER_PHASE_FIX" };
	size_t sizeofArray = sizeof(fix_typeArray) / sizeof(fix_typeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(fix_type, fix_typeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
