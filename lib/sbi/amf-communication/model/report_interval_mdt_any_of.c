#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "report_interval_mdt_any_of.h"

char *report_interval_mdt_any_of_ToString(
	report_interval_mdt_any_of_e report_interval_mdt_any_of) {
	const char *report_interval_mdt_any_ofArray[] =
	{ "NULL", "120", "240", "480", "640", "1024", "2048", "5120", "10240",
	  "60000", "360000", "720000", "1800000", "3600000" };
	size_t sizeofArray = sizeof(report_interval_mdt_any_ofArray) /
	                     sizeof(report_interval_mdt_any_ofArray[0]);
	if(report_interval_mdt_any_of < sizeofArray) {
		return (char *) report_interval_mdt_any_ofArray[
			report_interval_mdt_any_of];
	} else {
		return (char *) "Unknown";
	}
}

report_interval_mdt_any_of_e report_interval_mdt_any_of_FromString(
	char *report_interval_mdt_any_of) {
	int stringToReturn = 0;
	const char *report_interval_mdt_any_ofArray[] =
	{ "NULL", "120", "240", "480", "640", "1024", "2048", "5120", "10240",
	  "60000", "360000", "720000", "1800000", "3600000" };
	size_t sizeofArray = sizeof(report_interval_mdt_any_ofArray) /
	                     sizeof(report_interval_mdt_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(report_interval_mdt_any_of,
		          report_interval_mdt_any_ofArray[stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
