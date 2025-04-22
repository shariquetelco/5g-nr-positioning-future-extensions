#ifndef user_location_TEST
#define user_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_location.h"
user_location_t *instantiate_user_location(int include_optional);

#include "test_eutra_location.c"
#include "test_nr_location.c"
#include "test_n3ga_location.c"
#include "test_utra_location.c"
#include "test_gera_location.c"


user_location_t *instantiate_user_location(int include_optional) {
	user_location_t *user_location = NULL;
	if(include_optional) {
		user_location = user_location_create(
			// false, not to have infinite recursion
			instantiate_eutra_location(0),
			// false, not to have infinite recursion
			instantiate_nr_location(0),
			// false, not to have infinite recursion
			instantiate_n3ga_location(0),
			// false, not to have infinite recursion
			instantiate_utra_location(0),
			// false, not to have infinite recursion
			instantiate_gera_location(0)
			);
	} else {
		user_location = user_location_create(
			NULL,
			NULL,
			NULL,
			NULL,
			NULL
			);
	}

	return user_location;
}


#ifdef user_location_MAIN

void test_user_location(int include_optional) {
	user_location_t *user_location_1 = instantiate_user_location(
		include_optional);

	cJSON *jsonuser_location_1 =
		user_location_convertToJSON(user_location_1);
	printf("user_location :\n%s\n", cJSON_Print(jsonuser_location_1));
	user_location_t *user_location_2 = user_location_parseFromJSON(
		jsonuser_location_1);
	cJSON *jsonuser_location_2 =
		user_location_convertToJSON(user_location_2);
	printf("repeating user_location:\n%s\n", cJSON_Print(
		       jsonuser_location_2));
}

int main() {
	test_user_location(1);
	test_user_location(0);

	printf("Hello world \n");
	return 0;
}

#endif // user_location_MAIN
#endif // user_location_TEST
