#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ngran_failure_info.h"

char *ngran_failure_info_ToString(ngran_failure_info_e ngran_failure_info) {
	const char *ngran_failure_infoArray[] =
	{ "NULL", "NG_RAN_NOT_REACHABLE" };
	size_t sizeofArray = sizeof(ngran_failure_infoArray) /
	                     sizeof(ngran_failure_infoArray[0]);
	if(ngran_failure_info < sizeofArray) {
		return (char *) ngran_failure_infoArray[ngran_failure_info];
	} else {
		return (char *) "Unknown";
	}
}

ngran_failure_info_e ngran_failure_info_FromString(char *ngran_failure_info) {
	int stringToReturn = 0;
	const char *ngran_failure_infoArray[] =
	{ "NULL", "NG_RAN_NOT_REACHABLE" };
	size_t sizeofArray = sizeof(ngran_failure_infoArray) /
	                     sizeof(ngran_failure_infoArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(ngran_failure_info,
		          ngran_failure_infoArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
