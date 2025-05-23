#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pdu_session_type_any_of.h"

char *pdu_session_type_any_of_ToString(
	pdu_session_type_any_of_e pdu_session_type_any_of) {
	const char *pdu_session_type_any_ofArray[] =
	{ "NULL", "IPV4", "IPV6", "IPV4V6", "UNSTRUCTURED", "ETHERNET" };
	size_t sizeofArray = sizeof(pdu_session_type_any_ofArray) /
	                     sizeof(pdu_session_type_any_ofArray[0]);
	if(pdu_session_type_any_of < sizeofArray) {
		return (char *) pdu_session_type_any_ofArray[
			pdu_session_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

pdu_session_type_any_of_e pdu_session_type_any_of_FromString(
	char *pdu_session_type_any_of) {
	int stringToReturn = 0;
	const char *pdu_session_type_any_ofArray[] =
	{ "NULL", "IPV4", "IPV6", "IPV4V6", "UNSTRUCTURED", "ETHERNET" };
	size_t sizeofArray = sizeof(pdu_session_type_any_ofArray) /
	                     sizeof(pdu_session_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(pdu_session_type_any_of,
		          pdu_session_type_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
