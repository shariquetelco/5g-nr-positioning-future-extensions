#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "success_type.h"

char *success_type_ToString(success_type_e success_type) {
	const char *success_typeArray[] =
	{ "NULL", "SUCCESS_COMPLETELY", "SUCCESS_PARTIALLY" };
	size_t sizeofArray = sizeof(success_typeArray) /
	                     sizeof(success_typeArray[0]);
	if(success_type < sizeofArray) {
		return (char *) success_typeArray[success_type];
	} else {
		return (char *) "Unknown";
	}
}

success_type_e success_type_FromString(char *success_type) {
	int stringToReturn = 0;
	const char *success_typeArray[] =
	{ "NULL", "SUCCESS_COMPLETELY", "SUCCESS_PARTIALLY" };
	size_t sizeofArray = sizeof(success_typeArray) /
	                     sizeof(success_typeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(success_type,
		          success_typeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
