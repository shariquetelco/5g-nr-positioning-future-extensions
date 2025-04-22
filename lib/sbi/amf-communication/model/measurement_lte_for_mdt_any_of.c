#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "measurement_lte_for_mdt_any_of.h"

char *measurement_lte_for_mdt_any_of_ToString(
	measurement_lte_for_mdt_any_of_e measurement_lte_for_mdt_any_of) {
	const char *measurement_lte_for_mdt_any_ofArray[] =
	{ "NULL", "M1", "M2", "M3", "M4_DL", "M4_UL", "M5_DL", "M5_UL", "M6_DL",
	  "M6_UL", "M7_DL", "M7_UL", "M8", "M9" };
	size_t sizeofArray = sizeof(measurement_lte_for_mdt_any_ofArray) /
	                     sizeof(measurement_lte_for_mdt_any_ofArray[0]);
	if(measurement_lte_for_mdt_any_of < sizeofArray) {
		return (char *) measurement_lte_for_mdt_any_ofArray[
			measurement_lte_for_mdt_any_of];
	} else {
		return (char *) "Unknown";
	}
}

measurement_lte_for_mdt_any_of_e measurement_lte_for_mdt_any_of_FromString(
	char *measurement_lte_for_mdt_any_of) {
	int stringToReturn = 0;
	const char *measurement_lte_for_mdt_any_ofArray[] =
	{ "NULL", "M1", "M2", "M3", "M4_DL", "M4_UL", "M5_DL", "M5_UL", "M6_DL",
	  "M6_UL", "M7_DL", "M7_UL", "M8", "M9" };
	size_t sizeofArray = sizeof(measurement_lte_for_mdt_any_ofArray) /
	                     sizeof(measurement_lte_for_mdt_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(measurement_lte_for_mdt_any_of,
		          measurement_lte_for_mdt_any_ofArray[stringToReturn])
		   == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
