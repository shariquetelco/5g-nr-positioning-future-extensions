#ifndef fix_type_TEST
#define fix_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define fix_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/fix_type.h"
fix_type_t *instantiate_fix_type(int include_optional);



fix_type_t *instantiate_fix_type(int include_optional) {
	fix_type_t *fix_type = NULL;
	if(include_optional) {
		fix_type = fix_type_create(
			);
	} else {
		fix_type = fix_type_create(
			);
	}

	return fix_type;
}


#ifdef fix_type_MAIN

void test_fix_type(int include_optional) {
	fix_type_t *fix_type_1 = instantiate_fix_type(include_optional);

	cJSON *jsonfix_type_1 = fix_type_convertToJSON(fix_type_1);
	printf("fix_type :\n%s\n", cJSON_Print(jsonfix_type_1));
	fix_type_t *fix_type_2 = fix_type_parseFromJSON(jsonfix_type_1);
	cJSON *jsonfix_type_2 = fix_type_convertToJSON(fix_type_2);
	printf("repeating fix_type:\n%s\n", cJSON_Print(jsonfix_type_2));
}

int main() {
	test_fix_type(1);
	test_fix_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // fix_type_MAIN
#endif // fix_type_TEST
