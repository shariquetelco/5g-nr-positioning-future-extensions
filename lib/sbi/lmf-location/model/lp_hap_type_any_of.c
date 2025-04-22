#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lp_hap_type_any_of.h"

char *lp_hap_type_any_of_ToString(lp_hap_type_any_of_e lp_hap_type_any_of) {
	const char *lp_hap_type_any_ofArray[] =
	{ "NULL", "LOW_POW_HIGH_ACCU_POS" };
	size_t sizeofArray = sizeof(lp_hap_type_any_ofArray) /
	                     sizeof(lp_hap_type_any_ofArray[0]);
	if(lp_hap_type_any_of < sizeofArray) {
		return (char *) lp_hap_type_any_ofArray[lp_hap_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

lp_hap_type_any_of_e lp_hap_type_any_of_FromString(char *lp_hap_type_any_of) {
	int stringToReturn = 0;
	const char *lp_hap_type_any_ofArray[] =
	{ "NULL", "LOW_POW_HIGH_ACCU_POS" };
	size_t sizeofArray = sizeof(lp_hap_type_any_ofArray) /
	                     sizeof(lp_hap_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(lp_hap_type_any_of,
		          lp_hap_type_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
