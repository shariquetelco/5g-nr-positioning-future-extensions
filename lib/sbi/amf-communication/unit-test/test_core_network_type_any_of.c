#ifndef core_network_type_any_of_TEST
#define core_network_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define core_network_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/core_network_type_any_of.h"
core_network_type_any_of_t *instantiate_core_network_type_any_of(
	int include_optional);



core_network_type_any_of_t *instantiate_core_network_type_any_of(
	int include_optional) {
	core_network_type_any_of_t *core_network_type_any_of = NULL;
	if(include_optional) {
		core_network_type_any_of = core_network_type_any_of_create(
			);
	} else {
		core_network_type_any_of = core_network_type_any_of_create(
			);
	}

	return core_network_type_any_of;
}


#ifdef core_network_type_any_of_MAIN

void test_core_network_type_any_of(int include_optional) {
	core_network_type_any_of_t *core_network_type_any_of_1 =
		instantiate_core_network_type_any_of(include_optional);

	cJSON *jsoncore_network_type_any_of_1 =
		core_network_type_any_of_convertToJSON(
			core_network_type_any_of_1);
	printf("core_network_type_any_of :\n%s\n",
	       cJSON_Print(jsoncore_network_type_any_of_1));
	core_network_type_any_of_t *core_network_type_any_of_2 =
		core_network_type_any_of_parseFromJSON(
			jsoncore_network_type_any_of_1);
	cJSON *jsoncore_network_type_any_of_2 =
		core_network_type_any_of_convertToJSON(
			core_network_type_any_of_2);
	printf("repeating core_network_type_any_of:\n%s\n",
	       cJSON_Print(jsoncore_network_type_any_of_2));
}

int main() {
	test_core_network_type_any_of(1);
	test_core_network_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // core_network_type_any_of_MAIN
#endif // core_network_type_any_of_TEST
