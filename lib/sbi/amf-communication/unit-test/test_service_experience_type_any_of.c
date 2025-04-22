#ifndef service_experience_type_any_of_TEST
#define service_experience_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_experience_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_experience_type_any_of.h"
service_experience_type_any_of_t *instantiate_service_experience_type_any_of(
	int include_optional);



service_experience_type_any_of_t *instantiate_service_experience_type_any_of(
	int include_optional) {
	service_experience_type_any_of_t *service_experience_type_any_of = NULL;
	if(include_optional) {
		service_experience_type_any_of =
			service_experience_type_any_of_create(
				);
	} else {
		service_experience_type_any_of =
			service_experience_type_any_of_create(
				);
	}

	return service_experience_type_any_of;
}


#ifdef service_experience_type_any_of_MAIN

void test_service_experience_type_any_of(int include_optional) {
	service_experience_type_any_of_t *service_experience_type_any_of_1 =
		instantiate_service_experience_type_any_of(include_optional);

	cJSON *jsonservice_experience_type_any_of_1 =
		service_experience_type_any_of_convertToJSON(
			service_experience_type_any_of_1);
	printf("service_experience_type_any_of :\n%s\n",
	       cJSON_Print(jsonservice_experience_type_any_of_1));
	service_experience_type_any_of_t *service_experience_type_any_of_2 =
		service_experience_type_any_of_parseFromJSON(
			jsonservice_experience_type_any_of_1);
	cJSON *jsonservice_experience_type_any_of_2 =
		service_experience_type_any_of_convertToJSON(
			service_experience_type_any_of_2);
	printf("repeating service_experience_type_any_of:\n%s\n",
	       cJSON_Print(jsonservice_experience_type_any_of_2));
}

int main() {
	test_service_experience_type_any_of(1);
	test_service_experience_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // service_experience_type_any_of_MAIN
#endif // service_experience_type_any_of_TEST
