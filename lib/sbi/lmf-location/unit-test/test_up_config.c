#ifndef up_config_TEST
#define up_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define up_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/up_config.h"
up_config_t *instantiate_up_config(int include_optional);



up_config_t *instantiate_up_config(int include_optional) {
	up_config_t *up_config = NULL;
	if(include_optional) {
		up_config = up_config_create(
			"0",
			"0",
			"a",
			"a",
			1,
			lmf_location_up_config__TERMINATION,
			"0"
			);
	} else {
		up_config = up_config_create(
			"0",
			"0",
			"a",
			"a",
			1,
			lmf_location_up_config__TERMINATION,
			"0"
			);
	}

	return up_config;
}


#ifdef up_config_MAIN

void test_up_config(int include_optional) {
	up_config_t *up_config_1 = instantiate_up_config(include_optional);

	cJSON *jsonup_config_1 = up_config_convertToJSON(up_config_1);
	printf("up_config :\n%s\n", cJSON_Print(jsonup_config_1));
	up_config_t *up_config_2 = up_config_parseFromJSON(jsonup_config_1);
	cJSON *jsonup_config_2 = up_config_convertToJSON(up_config_2);
	printf("repeating up_config:\n%s\n", cJSON_Print(jsonup_config_2));
}

int main() {
	test_up_config(1);
	test_up_config(0);

	printf("Hello world \n");
	return 0;
}

#endif // up_config_MAIN
#endif // up_config_TEST
