#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n2_information_transfer_result.h"

char *n2_information_transfer_result_ToString(
	n2_information_transfer_result_e n2_information_transfer_result) {
	const char *n2_information_transfer_resultArray[] =
	{ "NULL", "N2_INFO_TRANSFER_INITIATED" };
	size_t sizeofArray = sizeof(n2_information_transfer_resultArray) /
	                     sizeof(n2_information_transfer_resultArray[0]);
	if(n2_information_transfer_result < sizeofArray) {
		return (char *) n2_information_transfer_resultArray[
			n2_information_transfer_result];
	} else {
		return (char *) "Unknown";
	}
}

n2_information_transfer_result_e n2_information_transfer_result_FromString(
	char *n2_information_transfer_result) {
	int stringToReturn = 0;
	const char *n2_information_transfer_resultArray[] =
	{ "NULL", "N2_INFO_TRANSFER_INITIATED" };
	size_t sizeofArray = sizeof(n2_information_transfer_resultArray) /
	                     sizeof(n2_information_transfer_resultArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(n2_information_transfer_result,
		          n2_information_transfer_resultArray[stringToReturn])
		   == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
