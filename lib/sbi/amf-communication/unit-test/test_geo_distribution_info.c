#ifndef geo_distribution_info_TEST
#define geo_distribution_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define geo_distribution_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/geo_distribution_info.h"
geo_distribution_info_t *instantiate_geo_distribution_info(
	int include_optional);

#include "test_user_location.c"


geo_distribution_info_t *instantiate_geo_distribution_info(int include_optional)
{
	geo_distribution_info_t *geo_distribution_info = NULL;
	if(include_optional) {
		geo_distribution_info = geo_distribution_info_create(
			// false, not to have infinite recursion
			instantiate_user_location(0),
			list_createList(),
			list_createList()
			);
	} else {
		geo_distribution_info = geo_distribution_info_create(
			NULL,
			list_createList(),
			list_createList()
			);
	}

	return geo_distribution_info;
}


#ifdef geo_distribution_info_MAIN

void test_geo_distribution_info(int include_optional) {
	geo_distribution_info_t *geo_distribution_info_1 =
		instantiate_geo_distribution_info(include_optional);

	cJSON *jsongeo_distribution_info_1 =
		geo_distribution_info_convertToJSON(geo_distribution_info_1);
	printf("geo_distribution_info :\n%s\n",
	       cJSON_Print(jsongeo_distribution_info_1));
	geo_distribution_info_t *geo_distribution_info_2 =
		geo_distribution_info_parseFromJSON(jsongeo_distribution_info_1);
	cJSON *jsongeo_distribution_info_2 =
		geo_distribution_info_convertToJSON(geo_distribution_info_2);
	printf("repeating geo_distribution_info:\n%s\n",
	       cJSON_Print(jsongeo_distribution_info_2));
}

int main() {
	test_geo_distribution_info(1);
	test_geo_distribution_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // geo_distribution_info_MAIN
#endif // geo_distribution_info_TEST
