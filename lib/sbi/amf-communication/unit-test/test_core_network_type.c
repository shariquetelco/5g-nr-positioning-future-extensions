#ifndef core_network_type_TEST
#define core_network_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define core_network_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/core_network_type.h"
core_network_type_t *instantiate_core_network_type(int include_optional);



core_network_type_t *instantiate_core_network_type(int include_optional) {
	core_network_type_t *core_network_type = NULL;
	if(include_optional) {
		core_network_type = core_network_type_create(
			);
	} else {
		core_network_type = core_network_type_create(
			);
	}

	return core_network_type;
}


#ifdef core_network_type_MAIN

void test_core_network_type(int include_optional) {
	core_network_type_t *core_network_type_1 =
		instantiate_core_network_type(include_optional);

	cJSON *jsoncore_network_type_1 = core_network_type_convertToJSON(
		core_network_type_1);
	printf("core_network_type :\n%s\n",
	       cJSON_Print(jsoncore_network_type_1));
	core_network_type_t *core_network_type_2 =
		core_network_type_parseFromJSON(jsoncore_network_type_1);
	cJSON *jsoncore_network_type_2 = core_network_type_convertToJSON(
		core_network_type_2);
	printf("repeating core_network_type:\n%s\n",
	       cJSON_Print(jsoncore_network_type_2));
}

int main() {
	test_core_network_type(1);
	test_core_network_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // core_network_type_MAIN
#endif // core_network_type_TEST
