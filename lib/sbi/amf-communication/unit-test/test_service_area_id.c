#ifndef service_area_id_TEST
#define service_area_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_area_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_area_id.h"
service_area_id_t *instantiate_service_area_id(int include_optional);

#include "test_plmn_id.c"


service_area_id_t *instantiate_service_area_id(int include_optional) {
	service_area_id_t *service_area_id = NULL;
	if(include_optional) {
		service_area_id = service_area_id_create(
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			"a",
			"a"
			);
	} else {
		service_area_id = service_area_id_create(
			NULL,
			"a",
			"a"
			);
	}

	return service_area_id;
}


#ifdef service_area_id_MAIN

void test_service_area_id(int include_optional) {
	service_area_id_t *service_area_id_1 = instantiate_service_area_id(
		include_optional);

	cJSON *jsonservice_area_id_1 = service_area_id_convertToJSON(
		service_area_id_1);
	printf("service_area_id :\n%s\n", cJSON_Print(jsonservice_area_id_1));
	service_area_id_t *service_area_id_2 = service_area_id_parseFromJSON(
		jsonservice_area_id_1);
	cJSON *jsonservice_area_id_2 = service_area_id_convertToJSON(
		service_area_id_2);
	printf("repeating service_area_id:\n%s\n",
	       cJSON_Print(jsonservice_area_id_2));
}

int main() {
	test_service_area_id(1);
	test_service_area_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // service_area_id_MAIN
#endif // service_area_id_TEST
