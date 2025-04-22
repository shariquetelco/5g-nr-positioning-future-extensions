#ifndef resource_usage_requirement_TEST
#define resource_usage_requirement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define resource_usage_requirement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/resource_usage_requirement.h"
resource_usage_requirement_t *instantiate_resource_usage_requirement(
	int include_optional);

#include "test_traffic_direction.c"
#include "test_value_expression.c"


resource_usage_requirement_t *instantiate_resource_usage_requirement(
	int include_optional) {
	resource_usage_requirement_t *resource_usage_requirement = NULL;
	if(include_optional) {
		resource_usage_requirement = resource_usage_requirement_create(
			null,
			null
			);
	} else {
		resource_usage_requirement = resource_usage_requirement_create(
			null,
			null
			);
	}

	return resource_usage_requirement;
}


#ifdef resource_usage_requirement_MAIN

void test_resource_usage_requirement(int include_optional) {
	resource_usage_requirement_t *resource_usage_requirement_1 =
		instantiate_resource_usage_requirement(include_optional);

	cJSON *jsonresource_usage_requirement_1 =
		resource_usage_requirement_convertToJSON(
			resource_usage_requirement_1);
	printf("resource_usage_requirement :\n%s\n",
	       cJSON_Print(jsonresource_usage_requirement_1));
	resource_usage_requirement_t *resource_usage_requirement_2 =
		resource_usage_requirement_parseFromJSON(
			jsonresource_usage_requirement_1);
	cJSON *jsonresource_usage_requirement_2 =
		resource_usage_requirement_convertToJSON(
			resource_usage_requirement_2);
	printf("repeating resource_usage_requirement:\n%s\n",
	       cJSON_Print(jsonresource_usage_requirement_2));
}

int main() {
	test_resource_usage_requirement(1);
	test_resource_usage_requirement(0);

	printf("Hello world \n");
	return 0;
}

#endif // resource_usage_requirement_MAIN
#endif // resource_usage_requirement_TEST
