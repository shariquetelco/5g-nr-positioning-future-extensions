#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "indoor_outdoor_ind.h"

char *indoor_outdoor_ind_ToString(indoor_outdoor_ind_e indoor_outdoor_ind) {
	const char *indoor_outdoor_indArray[] = { "NULL", "INDOOR", "OUTDOOR" };
	size_t sizeofArray = sizeof(indoor_outdoor_indArray) /
	                     sizeof(indoor_outdoor_indArray[0]);
	if(indoor_outdoor_ind < sizeofArray) {
		return (char *) indoor_outdoor_indArray[indoor_outdoor_ind];
	} else {
		return (char *) "Unknown";
	}
}

indoor_outdoor_ind_e indoor_outdoor_ind_FromString(char *indoor_outdoor_ind) {
	int stringToReturn = 0;
	const char *indoor_outdoor_indArray[] = { "NULL", "INDOOR", "OUTDOOR" };
	size_t sizeofArray = sizeof(indoor_outdoor_indArray) /
	                     sizeof(indoor_outdoor_indArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(indoor_outdoor_ind,
		          indoor_outdoor_indArray[stringToReturn]) == 0)
		{
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
