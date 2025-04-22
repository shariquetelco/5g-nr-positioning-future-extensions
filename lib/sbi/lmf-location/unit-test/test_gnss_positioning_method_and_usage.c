#ifndef gnss_positioning_method_and_usage_TEST
#define gnss_positioning_method_and_usage_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gnss_positioning_method_and_usage_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gnss_positioning_method_and_usage.h"
gnss_positioning_method_and_usage_t *
instantiate_gnss_positioning_method_and_usage(int include_optional);



gnss_positioning_method_and_usage_t *
instantiate_gnss_positioning_method_and_usage(int include_optional) {
	gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage =
		NULL;
	if(include_optional) {
		gnss_positioning_method_and_usage =
			gnss_positioning_method_and_usage_create(
				lmf_location_gnss_positioning_method_and_usage__UE_BASED,
				lmf_location_gnss_positioning_method_and_usage__GPS,
				lmf_location_gnss_positioning_method_and_usage__UNSUCCESS
				);
	} else {
		gnss_positioning_method_and_usage =
			gnss_positioning_method_and_usage_create(
				lmf_location_gnss_positioning_method_and_usage__UE_BASED,
				lmf_location_gnss_positioning_method_and_usage__GPS,
				lmf_location_gnss_positioning_method_and_usage__UNSUCCESS
				);
	}

	return gnss_positioning_method_and_usage;
}


#ifdef gnss_positioning_method_and_usage_MAIN

void test_gnss_positioning_method_and_usage(int include_optional) {
	gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_1
	        = instantiate_gnss_positioning_method_and_usage(include_optional);

	cJSON *jsongnss_positioning_method_and_usage_1 =
		gnss_positioning_method_and_usage_convertToJSON(
			gnss_positioning_method_and_usage_1);
	printf("gnss_positioning_method_and_usage :\n%s\n",
	       cJSON_Print(jsongnss_positioning_method_and_usage_1));
	gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_2
	        = gnss_positioning_method_and_usage_parseFromJSON(
			  jsongnss_positioning_method_and_usage_1);
	cJSON *jsongnss_positioning_method_and_usage_2 =
		gnss_positioning_method_and_usage_convertToJSON(
			gnss_positioning_method_and_usage_2);
	printf("repeating gnss_positioning_method_and_usage:\n%s\n", cJSON_Print(
		       jsongnss_positioning_method_and_usage_2));
}

int main() {
	test_gnss_positioning_method_and_usage(1);
	test_gnss_positioning_method_and_usage(0);

	printf("Hello world \n");
	return 0;
}

#endif // gnss_positioning_method_and_usage_MAIN
#endif // gnss_positioning_method_and_usage_TEST
