#ifndef application_volume_TEST
#define application_volume_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define application_volume_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/application_volume.h"
application_volume_t *instantiate_application_volume(int include_optional);



application_volume_t *instantiate_application_volume(int include_optional) {
	application_volume_t *application_volume = NULL;
	if(include_optional) {
		application_volume = application_volume_create(
			"0",
			0
			);
	} else {
		application_volume = application_volume_create(
			"0",
			0
			);
	}

	return application_volume;
}


#ifdef application_volume_MAIN

void test_application_volume(int include_optional) {
	application_volume_t *application_volume_1 =
		instantiate_application_volume(include_optional);

	cJSON *jsonapplication_volume_1 = application_volume_convertToJSON(
		application_volume_1);
	printf("application_volume :\n%s\n",
	       cJSON_Print(jsonapplication_volume_1));
	application_volume_t *application_volume_2 =
		application_volume_parseFromJSON(jsonapplication_volume_1);
	cJSON *jsonapplication_volume_2 = application_volume_convertToJSON(
		application_volume_2);
	printf("repeating application_volume:\n%s\n",
	       cJSON_Print(jsonapplication_volume_2));
}

int main() {
	test_application_volume(1);
	test_application_volume(0);

	printf("Hello world \n");
	return 0;
}

#endif // application_volume_MAIN
#endif // application_volume_TEST
