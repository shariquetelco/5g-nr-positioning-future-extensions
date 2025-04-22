#ifndef location_request_type_TEST
#define location_request_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_request_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_request_type.h"
location_request_type_t *instantiate_location_request_type(
	int include_optional);



location_request_type_t *instantiate_location_request_type(int include_optional)
{
	location_request_type_t *location_request_type = NULL;
	if(include_optional) {
		location_request_type = location_request_type_create(
			);
	} else {
		location_request_type = location_request_type_create(
			);
	}

	return location_request_type;
}


#ifdef location_request_type_MAIN

void test_location_request_type(int include_optional) {
	location_request_type_t *location_request_type_1 =
		instantiate_location_request_type(include_optional);

	cJSON *jsonlocation_request_type_1 =
		location_request_type_convertToJSON(location_request_type_1);
	printf("location_request_type :\n%s\n",
	       cJSON_Print(jsonlocation_request_type_1));
	location_request_type_t *location_request_type_2 =
		location_request_type_parseFromJSON(jsonlocation_request_type_1);
	cJSON *jsonlocation_request_type_2 =
		location_request_type_convertToJSON(location_request_type_2);
	printf("repeating location_request_type:\n%s\n",
	       cJSON_Print(jsonlocation_request_type_2));
}

int main() {
	test_location_request_type(1);
	test_location_request_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // location_request_type_MAIN
#endif // location_request_type_TEST
