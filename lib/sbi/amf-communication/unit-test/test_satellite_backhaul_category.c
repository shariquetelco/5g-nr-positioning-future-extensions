#ifndef satellite_backhaul_category_TEST
#define satellite_backhaul_category_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define satellite_backhaul_category_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/satellite_backhaul_category.h"
satellite_backhaul_category_t *instantiate_satellite_backhaul_category(
	int include_optional);



satellite_backhaul_category_t *instantiate_satellite_backhaul_category(
	int include_optional) {
	satellite_backhaul_category_t *satellite_backhaul_category = NULL;
	if(include_optional) {
		satellite_backhaul_category =
			satellite_backhaul_category_create(
				);
	} else {
		satellite_backhaul_category =
			satellite_backhaul_category_create(
				);
	}

	return satellite_backhaul_category;
}


#ifdef satellite_backhaul_category_MAIN

void test_satellite_backhaul_category(int include_optional) {
	satellite_backhaul_category_t *satellite_backhaul_category_1 =
		instantiate_satellite_backhaul_category(include_optional);

	cJSON *jsonsatellite_backhaul_category_1 =
		satellite_backhaul_category_convertToJSON(
			satellite_backhaul_category_1);
	printf("satellite_backhaul_category :\n%s\n",
	       cJSON_Print(jsonsatellite_backhaul_category_1));
	satellite_backhaul_category_t *satellite_backhaul_category_2 =
		satellite_backhaul_category_parseFromJSON(
			jsonsatellite_backhaul_category_1);
	cJSON *jsonsatellite_backhaul_category_2 =
		satellite_backhaul_category_convertToJSON(
			satellite_backhaul_category_2);
	printf("repeating satellite_backhaul_category:\n%s\n",
	       cJSON_Print(jsonsatellite_backhaul_category_2));
}

int main() {
	test_satellite_backhaul_category(1);
	test_satellite_backhaul_category(0);

	printf("Hello world \n");
	return 0;
}

#endif // satellite_backhaul_category_MAIN
#endif // satellite_backhaul_category_TEST
