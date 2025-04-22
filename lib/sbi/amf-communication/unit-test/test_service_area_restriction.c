#ifndef service_area_restriction_TEST
#define service_area_restriction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_area_restriction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_area_restriction.h"
service_area_restriction_t *instantiate_service_area_restriction(
	int include_optional);

#include "test_restriction_type.c"


service_area_restriction_t *instantiate_service_area_restriction(
	int include_optional) {
	service_area_restriction_t *service_area_restriction = NULL;
	if(include_optional) {
		service_area_restriction = service_area_restriction_create(
			null,
			list_createList(),
			0,
			0
			);
	} else {
		service_area_restriction = service_area_restriction_create(
			null,
			list_createList(),
			0,
			0
			);
	}

	return service_area_restriction;
}


#ifdef service_area_restriction_MAIN

void test_service_area_restriction(int include_optional) {
	service_area_restriction_t *service_area_restriction_1 =
		instantiate_service_area_restriction(include_optional);

	cJSON *jsonservice_area_restriction_1 =
		service_area_restriction_convertToJSON(
			service_area_restriction_1);
	printf("service_area_restriction :\n%s\n",
	       cJSON_Print(jsonservice_area_restriction_1));
	service_area_restriction_t *service_area_restriction_2 =
		service_area_restriction_parseFromJSON(
			jsonservice_area_restriction_1);
	cJSON *jsonservice_area_restriction_2 =
		service_area_restriction_convertToJSON(
			service_area_restriction_2);
	printf("repeating service_area_restriction:\n%s\n",
	       cJSON_Print(jsonservice_area_restriction_2));
}

int main() {
	test_service_area_restriction(1);
	test_service_area_restriction(0);

	printf("Hello world \n");
	return 0;
}

#endif // service_area_restriction_MAIN
#endif // service_area_restriction_TEST
