#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trace_depth_any_of.h"

char *trace_depth_any_of_ToString(trace_depth_any_of_e trace_depth_any_of) {
	const char *trace_depth_any_ofArray[] =
	{ "NULL", "MINIMUM", "MEDIUM", "MAXIMUM", "MINIMUM_WO_VENDOR_EXTENSION",
	  "MEDIUM_WO_VENDOR_EXTENSION", "MAXIMUM_WO_VENDOR_EXTENSION" };
	size_t sizeofArray = sizeof(trace_depth_any_ofArray) /
	                     sizeof(trace_depth_any_ofArray[0]);
	if(trace_depth_any_of < sizeofArray) {
		return (char *) trace_depth_any_ofArray[trace_depth_any_of];
	} else {
		return (char *) "Unknown";
	}
}

trace_depth_any_of_e trace_depth_any_of_FromString(char *trace_depth_any_of) {
	int stringToReturn = 0;
	const char *trace_depth_any_ofArray[] =
	{ "NULL", "MINIMUM", "MEDIUM", "MAXIMUM", "MINIMUM_WO_VENDOR_EXTENSION",
	  "MEDIUM_WO_VENDOR_EXTENSION", "MAXIMUM_WO_VENDOR_EXTENSION" };
	size_t sizeofArray = sizeof(trace_depth_any_ofArray) /
	                     sizeof(trace_depth_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(trace_depth_any_of,
		          trace_depth_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
