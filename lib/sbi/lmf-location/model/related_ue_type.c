#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "related_ue_type.h"

char *related_ue_type_ToString(related_ue_type_e related_ue_type) {
	const char *related_ue_typeArray[] =
	{ "NULL", "LOCATED_UE", "REFERENCE_UE" };
	size_t sizeofArray = sizeof(related_ue_typeArray) /
	                     sizeof(related_ue_typeArray[0]);
	if(related_ue_type < sizeofArray) {
		return (char *) related_ue_typeArray[related_ue_type];
	} else {
		return (char *) "Unknown";
	}
}

related_ue_type_e related_ue_type_FromString(char *related_ue_type) {
	int stringToReturn = 0;
	const char *related_ue_typeArray[] =
	{ "NULL", "LOCATED_UE", "REFERENCE_UE" };
	size_t sizeofArray = sizeof(related_ue_typeArray) /
	                     sizeof(related_ue_typeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(related_ue_type,
		          related_ue_typeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
