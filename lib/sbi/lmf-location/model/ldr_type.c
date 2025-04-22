#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ldr_type.h"

char *ldr_type_ToString(ldr_type_e ldr_type) {
	const char *ldr_typeArray[] =
	{ "NULL", "UE_AVAILABLE", "PERIODIC", "ENTERING_INTO_AREA",
	  "LEAVING_FROM_AREA", "BEING_INSIDE_AREA", "MOTION" };
	size_t sizeofArray = sizeof(ldr_typeArray) / sizeof(ldr_typeArray[0]);
	if(ldr_type < sizeofArray) {
		return (char *) ldr_typeArray[ldr_type];
	} else {
		return (char *) "Unknown";
	}
}

ldr_type_e ldr_type_FromString(char *ldr_type) {
	int stringToReturn = 0;
	const char *ldr_typeArray[] =
	{ "NULL", "UE_AVAILABLE", "PERIODIC", "ENTERING_INTO_AREA",
	  "LEAVING_FROM_AREA", "BEING_INSIDE_AREA", "MOTION" };
	size_t sizeofArray = sizeof(ldr_typeArray) / sizeof(ldr_typeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(ldr_type, ldr_typeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
