#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pru_ind_any_of.h"

char *pru_ind_any_of_ToString(pru_ind_any_of_e pru_ind_any_of) {
	const char *pru_ind_any_ofArray[] =
	{ "NULL", "NON_PRU", "STATIONARY_PRU", "NON_STATIONARY_PRU" };
	size_t sizeofArray = sizeof(pru_ind_any_ofArray) /
	                     sizeof(pru_ind_any_ofArray[0]);
	if(pru_ind_any_of < sizeofArray) {
		return (char *) pru_ind_any_ofArray[pru_ind_any_of];
	} else {
		return (char *) "Unknown";
	}
}

pru_ind_any_of_e pru_ind_any_of_FromString(char *pru_ind_any_of) {
	int stringToReturn = 0;
	const char *pru_ind_any_ofArray[] =
	{ "NULL", "NON_PRU", "STATIONARY_PRU", "NON_STATIONARY_PRU" };
	size_t sizeofArray = sizeof(pru_ind_any_ofArray) /
	                     sizeof(pru_ind_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(pru_ind_any_of,
		          pru_ind_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
