#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lcs_up_connection_ind.h"

char *lcs_up_connection_ind_ToString(
	lcs_up_connection_ind_e lcs_up_connection_ind) {
	const char *lcs_up_connection_indArray[] =
	{ "NULL", "TERMINATION", "SETUP" };
	size_t sizeofArray = sizeof(lcs_up_connection_indArray) /
	                     sizeof(lcs_up_connection_indArray[0]);
	if(lcs_up_connection_ind < sizeofArray) {
		return (char *) lcs_up_connection_indArray[lcs_up_connection_ind
		];
	} else {
		return (char *) "Unknown";
	}
}

lcs_up_connection_ind_e lcs_up_connection_ind_FromString(
	char *lcs_up_connection_ind) {
	int stringToReturn = 0;
	const char *lcs_up_connection_indArray[] =
	{ "NULL", "TERMINATION", "SETUP" };
	size_t sizeofArray = sizeof(lcs_up_connection_indArray) /
	                     sizeof(lcs_up_connection_indArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(lcs_up_connection_ind,
		          lcs_up_connection_indArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
