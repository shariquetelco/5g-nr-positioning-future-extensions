#ifndef ssc_mode_any_of_TEST
#define ssc_mode_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ssc_mode_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ssc_mode_any_of.h"
ssc_mode_any_of_t *instantiate_ssc_mode_any_of(int include_optional);



ssc_mode_any_of_t *instantiate_ssc_mode_any_of(int include_optional) {
	ssc_mode_any_of_t *ssc_mode_any_of = NULL;
	if(include_optional) {
		ssc_mode_any_of = ssc_mode_any_of_create(
			);
	} else {
		ssc_mode_any_of = ssc_mode_any_of_create(
			);
	}

	return ssc_mode_any_of;
}


#ifdef ssc_mode_any_of_MAIN

void test_ssc_mode_any_of(int include_optional) {
	ssc_mode_any_of_t *ssc_mode_any_of_1 = instantiate_ssc_mode_any_of(
		include_optional);

	cJSON *jsonssc_mode_any_of_1 = ssc_mode_any_of_convertToJSON(
		ssc_mode_any_of_1);
	printf("ssc_mode_any_of :\n%s\n", cJSON_Print(jsonssc_mode_any_of_1));
	ssc_mode_any_of_t *ssc_mode_any_of_2 = ssc_mode_any_of_parseFromJSON(
		jsonssc_mode_any_of_1);
	cJSON *jsonssc_mode_any_of_2 = ssc_mode_any_of_convertToJSON(
		ssc_mode_any_of_2);
	printf("repeating ssc_mode_any_of:\n%s\n",
	       cJSON_Print(jsonssc_mode_any_of_2));
}

int main() {
	test_ssc_mode_any_of(1);
	test_ssc_mode_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // ssc_mode_any_of_MAIN
#endif // ssc_mode_any_of_TEST
