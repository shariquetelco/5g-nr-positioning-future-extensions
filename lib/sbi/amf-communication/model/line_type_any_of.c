#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "line_type_any_of.h"

char *line_type_any_of_ToString(line_type_any_of_e line_type_any_of) {
	const char *line_type_any_ofArray[] = { "NULL", "DSL", "PON" };
	size_t sizeofArray = sizeof(line_type_any_ofArray) /
	                     sizeof(line_type_any_ofArray[0]);
	if(line_type_any_of < sizeofArray) {
		return (char *) line_type_any_ofArray[line_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

line_type_any_of_e line_type_any_of_FromString(char *line_type_any_of) {
	int stringToReturn = 0;
	const char *line_type_any_ofArray[] = { "NULL", "DSL", "PON" };
	size_t sizeofArray = sizeof(line_type_any_ofArray) /
	                     sizeof(line_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(line_type_any_of,
		          line_type_any_ofArray[stringToReturn]) == 0)
		{
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
