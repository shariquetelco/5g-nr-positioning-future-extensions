#ifndef external_client_type_TEST
#define external_client_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define external_client_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/external_client_type.h"
external_client_type_t *instantiate_external_client_type(int include_optional);



external_client_type_t *instantiate_external_client_type(int include_optional) {
	external_client_type_t *external_client_type = NULL;
	if(include_optional) {
		external_client_type = external_client_type_create(
			);
	} else {
		external_client_type = external_client_type_create(
			);
	}

	return external_client_type;
}


#ifdef external_client_type_MAIN

void test_external_client_type(int include_optional) {
	external_client_type_t *external_client_type_1 =
		instantiate_external_client_type(include_optional);

	cJSON *jsonexternal_client_type_1 = external_client_type_convertToJSON(
		external_client_type_1);
	printf("external_client_type :\n%s\n",
	       cJSON_Print(jsonexternal_client_type_1));
	external_client_type_t *external_client_type_2 =
		external_client_type_parseFromJSON(jsonexternal_client_type_1);
	cJSON *jsonexternal_client_type_2 = external_client_type_convertToJSON(
		external_client_type_2);
	printf("repeating external_client_type:\n%s\n",
	       cJSON_Print(jsonexternal_client_type_2));
}

int main() {
	test_external_client_type(1);
	test_external_client_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // external_client_type_MAIN
#endif // external_client_type_TEST
