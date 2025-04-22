#ifndef line_type_any_of_TEST
#define line_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define line_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/line_type_any_of.h"
line_type_any_of_t *instantiate_line_type_any_of(int include_optional);



line_type_any_of_t *instantiate_line_type_any_of(int include_optional) {
	line_type_any_of_t *line_type_any_of = NULL;
	if(include_optional) {
		line_type_any_of = line_type_any_of_create(
			);
	} else {
		line_type_any_of = line_type_any_of_create(
			);
	}

	return line_type_any_of;
}


#ifdef line_type_any_of_MAIN

void test_line_type_any_of(int include_optional) {
	line_type_any_of_t *line_type_any_of_1 = instantiate_line_type_any_of(
		include_optional);

	cJSON *jsonline_type_any_of_1 = line_type_any_of_convertToJSON(
		line_type_any_of_1);
	printf("line_type_any_of :\n%s\n", cJSON_Print(jsonline_type_any_of_1));
	line_type_any_of_t *line_type_any_of_2 = line_type_any_of_parseFromJSON(
		jsonline_type_any_of_1);
	cJSON *jsonline_type_any_of_2 = line_type_any_of_convertToJSON(
		line_type_any_of_2);
	printf("repeating line_type_any_of:\n%s\n",
	       cJSON_Print(jsonline_type_any_of_2));
}

int main() {
	test_line_type_any_of(1);
	test_line_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // line_type_any_of_MAIN
#endif // line_type_any_of_TEST
