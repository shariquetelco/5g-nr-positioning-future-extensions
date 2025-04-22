#ifndef sd_range_TEST
#define sd_range_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sd_range_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sd_range.h"
sd_range_t *instantiate_sd_range(int include_optional);



sd_range_t *instantiate_sd_range(int include_optional) {
	sd_range_t *sd_range = NULL;
	if(include_optional) {
		sd_range = sd_range_create(
			"a",
			"a"
			);
	} else {
		sd_range = sd_range_create(
			"a",
			"a"
			);
	}

	return sd_range;
}


#ifdef sd_range_MAIN

void test_sd_range(int include_optional) {
	sd_range_t *sd_range_1 = instantiate_sd_range(include_optional);

	cJSON *jsonsd_range_1 = sd_range_convertToJSON(sd_range_1);
	printf("sd_range :\n%s\n", cJSON_Print(jsonsd_range_1));
	sd_range_t *sd_range_2 = sd_range_parseFromJSON(jsonsd_range_1);
	cJSON *jsonsd_range_2 = sd_range_convertToJSON(sd_range_2);
	printf("repeating sd_range:\n%s\n", cJSON_Print(jsonsd_range_2));
}

int main() {
	test_sd_range(1);
	test_sd_range(0);

	printf("Hello world \n");
	return 0;
}

#endif // sd_range_MAIN
#endif // sd_range_TEST
