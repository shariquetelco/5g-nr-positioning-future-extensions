#ifndef sbi_binding_level_TEST
#define sbi_binding_level_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sbi_binding_level_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sbi_binding_level.h"
sbi_binding_level_t *instantiate_sbi_binding_level(int include_optional);



sbi_binding_level_t *instantiate_sbi_binding_level(int include_optional) {
	sbi_binding_level_t *sbi_binding_level = NULL;
	if(include_optional) {
		sbi_binding_level = sbi_binding_level_create(
			);
	} else {
		sbi_binding_level = sbi_binding_level_create(
			);
	}

	return sbi_binding_level;
}


#ifdef sbi_binding_level_MAIN

void test_sbi_binding_level(int include_optional) {
	sbi_binding_level_t *sbi_binding_level_1 =
		instantiate_sbi_binding_level(include_optional);

	cJSON *jsonsbi_binding_level_1 = sbi_binding_level_convertToJSON(
		sbi_binding_level_1);
	printf("sbi_binding_level :\n%s\n",
	       cJSON_Print(jsonsbi_binding_level_1));
	sbi_binding_level_t *sbi_binding_level_2 =
		sbi_binding_level_parseFromJSON(jsonsbi_binding_level_1);
	cJSON *jsonsbi_binding_level_2 = sbi_binding_level_convertToJSON(
		sbi_binding_level_2);
	printf("repeating sbi_binding_level:\n%s\n",
	       cJSON_Print(jsonsbi_binding_level_2));
}

int main() {
	test_sbi_binding_level(1);
	test_sbi_binding_level(0);

	printf("Hello world \n");
	return 0;
}

#endif // sbi_binding_level_MAIN
#endif // sbi_binding_level_TEST
