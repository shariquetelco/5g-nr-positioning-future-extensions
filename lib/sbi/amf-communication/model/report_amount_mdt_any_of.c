#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "report_amount_mdt_any_of.h"

char *report_amount_mdt_any_of_ToString(
	report_amount_mdt_any_of_e report_amount_mdt_any_of) {
	const char *report_amount_mdt_any_ofArray[] =
	{ "NULL", "1", "2", "4", "8", "16", "32", "64", "infinity" };
	size_t sizeofArray = sizeof(report_amount_mdt_any_ofArray) /
	                     sizeof(report_amount_mdt_any_ofArray[0]);
	if(report_amount_mdt_any_of < sizeofArray) {
		return (char *) report_amount_mdt_any_ofArray[
			report_amount_mdt_any_of];
	} else {
		return (char *) "Unknown";
	}
}

report_amount_mdt_any_of_e report_amount_mdt_any_of_FromString(
	char *report_amount_mdt_any_of) {
	int stringToReturn = 0;
	const char *report_amount_mdt_any_ofArray[] =
	{ "NULL", "1", "2", "4", "8", "16", "32", "64", "infinity" };
	size_t sizeofArray = sizeof(report_amount_mdt_any_ofArray) /
	                     sizeof(report_amount_mdt_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(report_amount_mdt_any_of,
		          report_amount_mdt_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
