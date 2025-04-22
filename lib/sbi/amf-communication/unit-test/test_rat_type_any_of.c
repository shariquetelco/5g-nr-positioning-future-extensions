#ifndef rat_type_any_of_TEST
#define rat_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rat_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rat_type_any_of.h"
rat_type_any_of_t *instantiate_rat_type_any_of(int include_optional);



rat_type_any_of_t *instantiate_rat_type_any_of(int include_optional) {
	rat_type_any_of_t *rat_type_any_of = NULL;
	if(include_optional) {
		rat_type_any_of = rat_type_any_of_create(
			);
	} else {
		rat_type_any_of = rat_type_any_of_create(
			);
	}

	return rat_type_any_of;
}


#ifdef rat_type_any_of_MAIN

void test_rat_type_any_of(int include_optional) {
	rat_type_any_of_t *rat_type_any_of_1 = instantiate_rat_type_any_of(
		include_optional);

	cJSON *jsonrat_type_any_of_1 = rat_type_any_of_convertToJSON(
		rat_type_any_of_1);
	printf("rat_type_any_of :\n%s\n", cJSON_Print(jsonrat_type_any_of_1));
	rat_type_any_of_t *rat_type_any_of_2 = rat_type_any_of_parseFromJSON(
		jsonrat_type_any_of_1);
	cJSON *jsonrat_type_any_of_2 = rat_type_any_of_convertToJSON(
		rat_type_any_of_2);
	printf("repeating rat_type_any_of:\n%s\n",
	       cJSON_Print(jsonrat_type_any_of_2));
}

int main() {
	test_rat_type_any_of(1);
	test_rat_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // rat_type_any_of_MAIN
#endif // rat_type_any_of_TEST
