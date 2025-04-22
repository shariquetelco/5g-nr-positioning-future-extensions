#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sc_type.h"

char *sc_type_ToString(sc_type_e sc_type) {
	const char *sc_typeArray[] = { "NULL", "NATIVE", "MAPPED" };
	size_t sizeofArray = sizeof(sc_typeArray) / sizeof(sc_typeArray[0]);
	if(sc_type < sizeofArray) {
		return (char *) sc_typeArray[sc_type];
	} else {
		return (char *) "Unknown";
	}
}

sc_type_e sc_type_FromString(char *sc_type) {
	int stringToReturn = 0;
	const char *sc_typeArray[] = { "NULL", "NATIVE", "MAPPED" };
	size_t sizeofArray = sizeof(sc_typeArray) / sizeof(sc_typeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(sc_type, sc_typeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
