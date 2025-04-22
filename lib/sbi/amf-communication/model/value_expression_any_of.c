#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "value_expression_any_of.h"

char *value_expression_any_of_ToString(
	value_expression_any_of_e value_expression_any_of) {
	const char *value_expression_any_ofArray[] =
	{ "NULL", "AVERAGE", "PEAK" };
	size_t sizeofArray = sizeof(value_expression_any_ofArray) /
	                     sizeof(value_expression_any_ofArray[0]);
	if(value_expression_any_of < sizeofArray) {
		return (char *) value_expression_any_ofArray[
			value_expression_any_of];
	} else {
		return (char *) "Unknown";
	}
}

value_expression_any_of_e value_expression_any_of_FromString(
	char *value_expression_any_of) {
	int stringToReturn = 0;
	const char *value_expression_any_ofArray[] =
	{ "NULL", "AVERAGE", "PEAK" };
	size_t sizeofArray = sizeof(value_expression_any_ofArray) /
	                     sizeof(value_expression_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(value_expression_any_of,
		          value_expression_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
