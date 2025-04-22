#ifndef ssc_mode_TEST
#define ssc_mode_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ssc_mode_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ssc_mode.h"
ssc_mode_t *instantiate_ssc_mode(int include_optional);



ssc_mode_t *instantiate_ssc_mode(int include_optional) {
	ssc_mode_t *ssc_mode = NULL;
	if(include_optional) {
		ssc_mode = ssc_mode_create(
			);
	} else {
		ssc_mode = ssc_mode_create(
			);
	}

	return ssc_mode;
}


#ifdef ssc_mode_MAIN

void test_ssc_mode(int include_optional) {
	ssc_mode_t *ssc_mode_1 = instantiate_ssc_mode(include_optional);

	cJSON *jsonssc_mode_1 = ssc_mode_convertToJSON(ssc_mode_1);
	printf("ssc_mode :\n%s\n", cJSON_Print(jsonssc_mode_1));
	ssc_mode_t *ssc_mode_2 = ssc_mode_parseFromJSON(jsonssc_mode_1);
	cJSON *jsonssc_mode_2 = ssc_mode_convertToJSON(ssc_mode_2);
	printf("repeating ssc_mode:\n%s\n", cJSON_Print(jsonssc_mode_2));
}

int main() {
	test_ssc_mode(1);
	test_ssc_mode(0);

	printf("Hello world \n");
	return 0;
}

#endif // ssc_mode_MAIN
#endif // ssc_mode_TEST
