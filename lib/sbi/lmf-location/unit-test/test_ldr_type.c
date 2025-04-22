#ifndef ldr_type_TEST
#define ldr_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ldr_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ldr_type.h"
ldr_type_t *instantiate_ldr_type(int include_optional);



ldr_type_t *instantiate_ldr_type(int include_optional) {
	ldr_type_t *ldr_type = NULL;
	if(include_optional) {
		ldr_type = ldr_type_create(
			);
	} else {
		ldr_type = ldr_type_create(
			);
	}

	return ldr_type;
}


#ifdef ldr_type_MAIN

void test_ldr_type(int include_optional) {
	ldr_type_t *ldr_type_1 = instantiate_ldr_type(include_optional);

	cJSON *jsonldr_type_1 = ldr_type_convertToJSON(ldr_type_1);
	printf("ldr_type :\n%s\n", cJSON_Print(jsonldr_type_1));
	ldr_type_t *ldr_type_2 = ldr_type_parseFromJSON(jsonldr_type_1);
	cJSON *jsonldr_type_2 = ldr_type_convertToJSON(ldr_type_2);
	printf("repeating ldr_type:\n%s\n", cJSON_Print(jsonldr_type_2));
}

int main() {
	test_ldr_type(1);
	test_ldr_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // ldr_type_MAIN
#endif // ldr_type_TEST
