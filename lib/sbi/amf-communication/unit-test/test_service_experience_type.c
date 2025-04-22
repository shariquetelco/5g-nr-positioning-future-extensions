#ifndef service_experience_type_TEST
#define service_experience_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_experience_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_experience_type.h"
service_experience_type_t *instantiate_service_experience_type(
	int include_optional);



service_experience_type_t *instantiate_service_experience_type(
	int include_optional) {
	service_experience_type_t *service_experience_type = NULL;
	if(include_optional) {
		service_experience_type = service_experience_type_create(
			);
	} else {
		service_experience_type = service_experience_type_create(
			);
	}

	return service_experience_type;
}


#ifdef service_experience_type_MAIN

void test_service_experience_type(int include_optional) {
	service_experience_type_t *service_experience_type_1 =
		instantiate_service_experience_type(include_optional);

	cJSON *jsonservice_experience_type_1 =
		service_experience_type_convertToJSON(service_experience_type_1);
	printf("service_experience_type :\n%s\n",
	       cJSON_Print(jsonservice_experience_type_1));
	service_experience_type_t *service_experience_type_2 =
		service_experience_type_parseFromJSON(
			jsonservice_experience_type_1);
	cJSON *jsonservice_experience_type_2 =
		service_experience_type_convertToJSON(service_experience_type_2);
	printf("repeating service_experience_type:\n%s\n",
	       cJSON_Print(jsonservice_experience_type_2));
}

int main() {
	test_service_experience_type(1);
	test_service_experience_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // service_experience_type_MAIN
#endif // service_experience_type_TEST
