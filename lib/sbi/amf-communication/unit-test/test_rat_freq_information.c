#ifndef rat_freq_information_TEST
#define rat_freq_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rat_freq_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rat_freq_information.h"
rat_freq_information_t *instantiate_rat_freq_information(int include_optional);

#include "test_rat_type.c"
#include "test_threshold_level.c"
#include "test_matching_direction.c"


rat_freq_information_t *instantiate_rat_freq_information(int include_optional) {
	rat_freq_information_t *rat_freq_information = NULL;
	if(include_optional) {
		rat_freq_information = rat_freq_information_create(
			1,
			1,
			0,
			null,
			// false, not to have infinite recursion
			instantiate_threshold_level(0),
			null
			);
	} else {
		rat_freq_information = rat_freq_information_create(
			1,
			1,
			0,
			null,
			NULL,
			null
			);
	}

	return rat_freq_information;
}


#ifdef rat_freq_information_MAIN

void test_rat_freq_information(int include_optional) {
	rat_freq_information_t *rat_freq_information_1 =
		instantiate_rat_freq_information(include_optional);

	cJSON *jsonrat_freq_information_1 = rat_freq_information_convertToJSON(
		rat_freq_information_1);
	printf("rat_freq_information :\n%s\n",
	       cJSON_Print(jsonrat_freq_information_1));
	rat_freq_information_t *rat_freq_information_2 =
		rat_freq_information_parseFromJSON(jsonrat_freq_information_1);
	cJSON *jsonrat_freq_information_2 = rat_freq_information_convertToJSON(
		rat_freq_information_2);
	printf("repeating rat_freq_information:\n%s\n",
	       cJSON_Print(jsonrat_freq_information_2));
}

int main() {
	test_rat_freq_information(1);
	test_rat_freq_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // rat_freq_information_MAIN
#endif // rat_freq_information_TEST
