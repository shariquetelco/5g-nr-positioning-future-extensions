#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transport_protocol_any_of.h"

char *transport_protocol_any_of_ToString(
	transport_protocol_any_of_e transport_protocol_any_of) {
	const char *transport_protocol_any_ofArray[] = { "NULL", "UDP", "TCP" };
	size_t sizeofArray = sizeof(transport_protocol_any_ofArray) /
	                     sizeof(transport_protocol_any_ofArray[0]);
	if(transport_protocol_any_of < sizeofArray) {
		return (char *) transport_protocol_any_ofArray[
			transport_protocol_any_of];
	} else {
		return (char *) "Unknown";
	}
}

transport_protocol_any_of_e transport_protocol_any_of_FromString(
	char *transport_protocol_any_of) {
	int stringToReturn = 0;
	const char *transport_protocol_any_ofArray[] = { "NULL", "UDP", "TCP" };
	size_t sizeofArray = sizeof(transport_protocol_any_ofArray) /
	                     sizeof(transport_protocol_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(transport_protocol_any_of,
		          transport_protocol_any_ofArray[stringToReturn]) == 0)
		{
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
