#ifndef rat_type_TEST
#define rat_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rat_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rat_type.h"
rat_type_t *instantiate_rat_type(int include_optional);



rat_type_t *instantiate_rat_type(int include_optional) {
	rat_type_t *rat_type = NULL;
	if(include_optional) {
		rat_type = rat_type_create(
			);
	} else {
		rat_type = rat_type_create(
			);
	}

	return rat_type;
}


#ifdef rat_type_MAIN

void test_rat_type(int include_optional) {
	rat_type_t *rat_type_1 = instantiate_rat_type(include_optional);

	cJSON *jsonrat_type_1 = rat_type_convertToJSON(rat_type_1);
	printf("rat_type :\n%s\n", cJSON_Print(jsonrat_type_1));
	rat_type_t *rat_type_2 = rat_type_parseFromJSON(jsonrat_type_1);
	cJSON *jsonrat_type_2 = rat_type_convertToJSON(rat_type_2);
	printf("repeating rat_type:\n%s\n", cJSON_Print(jsonrat_type_2));
}

int main() {
	test_rat_type(1);
	test_rat_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // rat_type_MAIN
#endif // rat_type_TEST
