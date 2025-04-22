#ifndef line_type_TEST
#define line_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define line_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/line_type.h"
line_type_t *instantiate_line_type(int include_optional);



line_type_t *instantiate_line_type(int include_optional) {
	line_type_t *line_type = NULL;
	if(include_optional) {
		line_type = line_type_create(
			);
	} else {
		line_type = line_type_create(
			);
	}

	return line_type;
}


#ifdef line_type_MAIN

void test_line_type(int include_optional) {
	line_type_t *line_type_1 = instantiate_line_type(include_optional);

	cJSON *jsonline_type_1 = line_type_convertToJSON(line_type_1);
	printf("line_type :\n%s\n", cJSON_Print(jsonline_type_1));
	line_type_t *line_type_2 = line_type_parseFromJSON(jsonline_type_1);
	cJSON *jsonline_type_2 = line_type_convertToJSON(line_type_2);
	printf("repeating line_type:\n%s\n", cJSON_Print(jsonline_type_2));
}

int main() {
	test_line_type(1);
	test_line_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // line_type_MAIN
#endif // line_type_TEST
