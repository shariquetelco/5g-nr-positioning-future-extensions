#ifndef location_privacy_ver_result_TEST
#define location_privacy_ver_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_privacy_ver_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_privacy_ver_result.h"
location_privacy_ver_result_t *instantiate_location_privacy_ver_result(
	int include_optional);



location_privacy_ver_result_t *instantiate_location_privacy_ver_result(
	int include_optional) {
	location_privacy_ver_result_t *location_privacy_ver_result = NULL;
	if(include_optional) {
		location_privacy_ver_result =
			location_privacy_ver_result_create(
				);
	} else {
		location_privacy_ver_result =
			location_privacy_ver_result_create(
				);
	}

	return location_privacy_ver_result;
}


#ifdef location_privacy_ver_result_MAIN

void test_location_privacy_ver_result(int include_optional) {
	location_privacy_ver_result_t *location_privacy_ver_result_1 =
		instantiate_location_privacy_ver_result(include_optional);

	cJSON *jsonlocation_privacy_ver_result_1 =
		location_privacy_ver_result_convertToJSON(
			location_privacy_ver_result_1);
	printf("location_privacy_ver_result :\n%s\n",
	       cJSON_Print(jsonlocation_privacy_ver_result_1));
	location_privacy_ver_result_t *location_privacy_ver_result_2 =
		location_privacy_ver_result_parseFromJSON(
			jsonlocation_privacy_ver_result_1);
	cJSON *jsonlocation_privacy_ver_result_2 =
		location_privacy_ver_result_convertToJSON(
			location_privacy_ver_result_2);
	printf("repeating location_privacy_ver_result:\n%s\n",
	       cJSON_Print(jsonlocation_privacy_ver_result_2));
}

int main() {
	test_location_privacy_ver_result(1);
	test_location_privacy_ver_result(0);

	printf("Hello world \n");
	return 0;
}

#endif // location_privacy_ver_result_MAIN
#endif // location_privacy_ver_result_TEST
