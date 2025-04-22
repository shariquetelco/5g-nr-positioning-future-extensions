#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "los_nlos_measure_ind.h"

char *los_nlos_measure_ind_ToString(los_nlos_measure_ind_e los_nlos_measure_ind)
{
	const char *los_nlos_measure_indArray[] = { "NULL", "LOS", "NLOS" };
	size_t sizeofArray = sizeof(los_nlos_measure_indArray) /
	                     sizeof(los_nlos_measure_indArray[0]);
	if(los_nlos_measure_ind < sizeofArray) {
		return (char *) los_nlos_measure_indArray[los_nlos_measure_ind];
	} else {
		return (char *) "Unknown";
	}
}

los_nlos_measure_ind_e los_nlos_measure_ind_FromString(
	char *los_nlos_measure_ind) {
	int stringToReturn = 0;
	const char *los_nlos_measure_indArray[] = { "NULL", "LOS", "NLOS" };
	size_t sizeofArray = sizeof(los_nlos_measure_indArray) /
	                     sizeof(los_nlos_measure_indArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(los_nlos_measure_ind,
		          los_nlos_measure_indArray[stringToReturn]) == 0)
		{
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
