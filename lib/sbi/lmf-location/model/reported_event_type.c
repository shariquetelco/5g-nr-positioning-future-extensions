#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reported_event_type.h"

char *reported_event_type_ToString(reported_event_type_e reported_event_type) {
	const char *reported_event_typeArray[] =
	{ "NULL", "PERIODIC_EVENT", "ENTERING_AREA_EVENT", "LEAVING_AREA_EVENT",
	  "BEING_INSIDE_AREA_EVENT", "MOTION_EVENT",
	  "MAXIMUM_INTERVAL_EXPIRATION_EVENT",
	  "LOCATION_CANCELLATION_EVENT", "INTERMEDIATE_EVENT",
	  "DIRECT_REPORT_EVENT", "CUMULATIVE_EVENT_REPORT" };
	size_t sizeofArray = sizeof(reported_event_typeArray) /
	                     sizeof(reported_event_typeArray[0]);
	if(reported_event_type < sizeofArray) {
		return (char *) reported_event_typeArray[reported_event_type];
	} else {
		return (char *) "Unknown";
	}
}

reported_event_type_e reported_event_type_FromString(char *reported_event_type)
{
	int stringToReturn = 0;
	const char *reported_event_typeArray[] =
	{ "NULL", "PERIODIC_EVENT", "ENTERING_AREA_EVENT", "LEAVING_AREA_EVENT",
	  "BEING_INSIDE_AREA_EVENT", "MOTION_EVENT",
	  "MAXIMUM_INTERVAL_EXPIRATION_EVENT",
	  "LOCATION_CANCELLATION_EVENT", "INTERMEDIATE_EVENT",
	  "DIRECT_REPORT_EVENT", "CUMULATIVE_EVENT_REPORT" };
	size_t sizeofArray = sizeof(reported_event_typeArray) /
	                     sizeof(reported_event_typeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(reported_event_type,
		          reported_event_typeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
