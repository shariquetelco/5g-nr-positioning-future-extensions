#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_class.h"

char *event_class_ToString(event_class_e event_class) {
	const char *event_classArray[] = { "NULL", "SUPPLEMENTARY_SERVICES" };
	size_t sizeofArray = sizeof(event_classArray) /
	                     sizeof(event_classArray[0]);
	if(event_class < sizeofArray) {
		return (char *) event_classArray[event_class];
	} else {
		return (char *) "Unknown";
	}
}

event_class_e event_class_FromString(char *event_class) {
	int stringToReturn = 0;
	const char *event_classArray[] = { "NULL", "SUPPLEMENTARY_SERVICES" };
	size_t sizeofArray = sizeof(event_classArray) /
	                     sizeof(event_classArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(event_class, event_classArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
