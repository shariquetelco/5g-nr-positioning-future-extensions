#ifndef satellite_backhaul_category_any_of_TEST
#define satellite_backhaul_category_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define satellite_backhaul_category_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/satellite_backhaul_category_any_of.h"
satellite_backhaul_category_any_of_t *
instantiate_satellite_backhaul_category_any_of(int include_optional);



satellite_backhaul_category_any_of_t *
instantiate_satellite_backhaul_category_any_of(int include_optional) {
	satellite_backhaul_category_any_of_t *satellite_backhaul_category_any_of
	        = NULL;
	if(include_optional) {
		satellite_backhaul_category_any_of =
			satellite_backhaul_category_any_of_create(
				);
	} else {
		satellite_backhaul_category_any_of =
			satellite_backhaul_category_any_of_create(
				);
	}

	return satellite_backhaul_category_any_of;
}


#ifdef satellite_backhaul_category_any_of_MAIN

void test_satellite_backhaul_category_any_of(int include_optional) {
	satellite_backhaul_category_any_of_t *
	        satellite_backhaul_category_any_of_1 =
		instantiate_satellite_backhaul_category_any_of(include_optional);

	cJSON *jsonsatellite_backhaul_category_any_of_1 =
		satellite_backhaul_category_any_of_convertToJSON(
			satellite_backhaul_category_any_of_1);
	printf("satellite_backhaul_category_any_of :\n%s\n",
	       cJSON_Print(jsonsatellite_backhaul_category_any_of_1));
	satellite_backhaul_category_any_of_t *
	        satellite_backhaul_category_any_of_2 =
		satellite_backhaul_category_any_of_parseFromJSON(
			jsonsatellite_backhaul_category_any_of_1);
	cJSON *jsonsatellite_backhaul_category_any_of_2 =
		satellite_backhaul_category_any_of_convertToJSON(
			satellite_backhaul_category_any_of_2);
	printf("repeating satellite_backhaul_category_any_of:\n%s\n", cJSON_Print(
		       jsonsatellite_backhaul_category_any_of_2));
}

int main() {
	test_satellite_backhaul_category_any_of(1);
	test_satellite_backhaul_category_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // satellite_backhaul_category_any_of_MAIN
#endif // satellite_backhaul_category_any_of_TEST
