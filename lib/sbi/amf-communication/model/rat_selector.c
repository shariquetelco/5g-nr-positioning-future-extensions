#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rat_selector.h"

char *rat_selector_ToString(rat_selector_e rat_selector) {
	const char *rat_selectorArray[] = { "NULL", "E-UTRA", "NR" };
	size_t sizeofArray = sizeof(rat_selectorArray) /
	                     sizeof(rat_selectorArray[0]);
	if(rat_selector < sizeofArray) {
		return (char *) rat_selectorArray[rat_selector];
	} else {
		return (char *) "Unknown";
	}
}

rat_selector_e rat_selector_FromString(char *rat_selector) {
	int stringToReturn = 0;
	const char *rat_selectorArray[] = { "NULL", "E-UTRA", "NR" };
	size_t sizeofArray = sizeof(rat_selectorArray) /
	                     sizeof(rat_selectorArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(rat_selector,
		          rat_selectorArray[stringToReturn]) == 0)
		{
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
