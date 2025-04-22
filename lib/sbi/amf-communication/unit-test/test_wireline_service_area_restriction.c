#ifndef wireline_service_area_restriction_TEST
#define wireline_service_area_restriction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define wireline_service_area_restriction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/wireline_service_area_restriction.h"
wireline_service_area_restriction_t *
instantiate_wireline_service_area_restriction(int include_optional);

#include "test_restriction_type.c"


wireline_service_area_restriction_t *
instantiate_wireline_service_area_restriction(int include_optional) {
	wireline_service_area_restriction_t *wireline_service_area_restriction =
		NULL;
	if(include_optional) {
		wireline_service_area_restriction =
			wireline_service_area_restriction_create(
				null,
				list_createList()
				);
	} else {
		wireline_service_area_restriction =
			wireline_service_area_restriction_create(
				null,
				list_createList()
				);
	}

	return wireline_service_area_restriction;
}


#ifdef wireline_service_area_restriction_MAIN

void test_wireline_service_area_restriction(int include_optional) {
	wireline_service_area_restriction_t *wireline_service_area_restriction_1
	        = instantiate_wireline_service_area_restriction(include_optional);

	cJSON *jsonwireline_service_area_restriction_1 =
		wireline_service_area_restriction_convertToJSON(
			wireline_service_area_restriction_1);
	printf("wireline_service_area_restriction :\n%s\n",
	       cJSON_Print(jsonwireline_service_area_restriction_1));
	wireline_service_area_restriction_t *wireline_service_area_restriction_2
	        = wireline_service_area_restriction_parseFromJSON(
			  jsonwireline_service_area_restriction_1);
	cJSON *jsonwireline_service_area_restriction_2 =
		wireline_service_area_restriction_convertToJSON(
			wireline_service_area_restriction_2);
	printf("repeating wireline_service_area_restriction:\n%s\n", cJSON_Print(
		       jsonwireline_service_area_restriction_2));
}

int main() {
	test_wireline_service_area_restriction(1);
	test_wireline_service_area_restriction(0);

	printf("Hello world \n");
	return 0;
}

#endif // wireline_service_area_restriction_MAIN
#endif // wireline_service_area_restriction_TEST
