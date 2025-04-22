#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time_source_any_of.h"

char *time_source_any_of_ToString(time_source_any_of_e time_source_any_of) {
	const char *time_source_any_ofArray[] =
	{ "NULL", "SYNC_E", "PTP", "GNSS", "ATOMIC_CLOCK", "TERRESTRIAL_RADIO",
	  "SERIAL_TIME_CODE", "NTP", "HAND_SET", "OTHER" };
	size_t sizeofArray = sizeof(time_source_any_ofArray) /
	                     sizeof(time_source_any_ofArray[0]);
	if(time_source_any_of < sizeofArray) {
		return (char *) time_source_any_ofArray[time_source_any_of];
	} else {
		return (char *) "Unknown";
	}
}

time_source_any_of_e time_source_any_of_FromString(char *time_source_any_of) {
	int stringToReturn = 0;
	const char *time_source_any_ofArray[] =
	{ "NULL", "SYNC_E", "PTP", "GNSS", "ATOMIC_CLOCK", "TERRESTRIAL_RADIO",
	  "SERIAL_TIME_CODE", "NTP", "HAND_SET", "OTHER" };
	size_t sizeofArray = sizeof(time_source_any_ofArray) /
	                     sizeof(time_source_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(time_source_any_of,
		          time_source_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
