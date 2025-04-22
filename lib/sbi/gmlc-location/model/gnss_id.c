#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gnss_id.h"

char *gnss_id_ToString(gnss_id_e gnss_id) {
	const char *gnss_idArray[] =
	{ "NULL", "GPS", "GALILEO", "SBAS", "MODERNIZED_GPS", "QZSS", "GLONASS",
	  "BDS", "NAVIC" };
	size_t sizeofArray = sizeof(gnss_idArray) / sizeof(gnss_idArray[0]);
	if(gnss_id < sizeofArray) {
		return (char *) gnss_idArray[gnss_id];
	} else {
		return (char *) "Unknown";
	}
}

gnss_id_e gnss_id_FromString(char *gnss_id) {
	int stringToReturn = 0;
	const char *gnss_idArray[] =
	{ "NULL", "GPS", "GALILEO", "SBAS", "MODERNIZED_GPS", "QZSS", "GLONASS",
	  "BDS", "NAVIC" };
	size_t sizeofArray = sizeof(gnss_idArray) / sizeof(gnss_idArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(gnss_id, gnss_idArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
