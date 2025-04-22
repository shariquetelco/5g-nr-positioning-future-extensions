#ifndef positioning_method_and_usage_TEST
#define positioning_method_and_usage_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define positioning_method_and_usage_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/positioning_method_and_usage.h"
positioning_method_and_usage_t *instantiate_positioning_method_and_usage(
	int include_optional);



positioning_method_and_usage_t *instantiate_positioning_method_and_usage(
	int include_optional) {
	positioning_method_and_usage_t *positioning_method_and_usage = NULL;
	if(include_optional) {
		positioning_method_and_usage =
			positioning_method_and_usage_create(
				lmf_location_positioning_method_and_usage__CELLID,
				lmf_location_positioning_method_and_usage__UE_BASED,
				lmf_location_positioning_method_and_usage__UNSUCCESS,
				16
				);
	} else {
		positioning_method_and_usage =
			positioning_method_and_usage_create(
				lmf_location_positioning_method_and_usage__CELLID,
				lmf_location_positioning_method_and_usage__UE_BASED,
				lmf_location_positioning_method_and_usage__UNSUCCESS,
				16
				);
	}

	return positioning_method_and_usage;
}


#ifdef positioning_method_and_usage_MAIN

void test_positioning_method_and_usage(int include_optional) {
	positioning_method_and_usage_t *positioning_method_and_usage_1 =
		instantiate_positioning_method_and_usage(include_optional);

	cJSON *jsonpositioning_method_and_usage_1 =
		positioning_method_and_usage_convertToJSON(
			positioning_method_and_usage_1);
	printf("positioning_method_and_usage :\n%s\n",
	       cJSON_Print(jsonpositioning_method_and_usage_1));
	positioning_method_and_usage_t *positioning_method_and_usage_2 =
		positioning_method_and_usage_parseFromJSON(
			jsonpositioning_method_and_usage_1);
	cJSON *jsonpositioning_method_and_usage_2 =
		positioning_method_and_usage_convertToJSON(
			positioning_method_and_usage_2);
	printf("repeating positioning_method_and_usage:\n%s\n",
	       cJSON_Print(jsonpositioning_method_and_usage_2));
}

int main() {
	test_positioning_method_and_usage(1);
	test_positioning_method_and_usage(0);

	printf("Hello world \n");
	return 0;
}

#endif // positioning_method_and_usage_MAIN
#endif // positioning_method_and_usage_TEST
