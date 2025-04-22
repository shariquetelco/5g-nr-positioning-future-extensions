#ifndef resource_usage_TEST
#define resource_usage_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define resource_usage_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/resource_usage.h"
resource_usage_t *instantiate_resource_usage(int include_optional);



resource_usage_t *instantiate_resource_usage(int include_optional) {
	resource_usage_t *resource_usage = NULL;
	if(include_optional) {
		resource_usage = resource_usage_create(
			0,
			0,
			0
			);
	} else {
		resource_usage = resource_usage_create(
			0,
			0,
			0
			);
	}

	return resource_usage;
}


#ifdef resource_usage_MAIN

void test_resource_usage(int include_optional) {
	resource_usage_t *resource_usage_1 = instantiate_resource_usage(
		include_optional);

	cJSON *jsonresource_usage_1 = resource_usage_convertToJSON(
		resource_usage_1);
	printf("resource_usage :\n%s\n", cJSON_Print(jsonresource_usage_1));
	resource_usage_t *resource_usage_2 = resource_usage_parseFromJSON(
		jsonresource_usage_1);
	cJSON *jsonresource_usage_2 = resource_usage_convertToJSON(
		resource_usage_2);
	printf("repeating resource_usage:\n%s\n",
	       cJSON_Print(jsonresource_usage_2));
}

int main() {
	test_resource_usage(1);
	test_resource_usage(0);

	printf("Hello world \n");
	return 0;
}

#endif // resource_usage_MAIN
#endif // resource_usage_TEST
