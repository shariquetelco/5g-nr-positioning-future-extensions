#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n1_message_class.h"

char *n1_message_class_ToString(n1_message_class_e n1_message_class) {
	const char *n1_message_classArray[] =
	{ "NULL", "5GMM", "SM", "LPP", "SMS", "UPDP", "LCS", "UPP-CM" };
	size_t sizeofArray = sizeof(n1_message_classArray) /
	                     sizeof(n1_message_classArray[0]);
	if(n1_message_class < sizeofArray) {
		return (char *) n1_message_classArray[n1_message_class];
	} else {
		return (char *) "Unknown";
	}
}

n1_message_class_e n1_message_class_FromString(char *n1_message_class) {
	int stringToReturn = 0;
	const char *n1_message_classArray[] =
	{ "NULL", "5GMM", "SM", "LPP", "SMS", "UPDP", "LCS", "UPP-CM" };
	size_t sizeofArray = sizeof(n1_message_classArray) /
	                     sizeof(n1_message_classArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(n1_message_class,
		          n1_message_classArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
