#ifndef positioning_method_mdt_TEST
#define positioning_method_mdt_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define positioning_method_mdt_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/positioning_method_mdt.h"
positioning_method_mdt_t *instantiate_positioning_method_mdt(
	int include_optional);



positioning_method_mdt_t *instantiate_positioning_method_mdt(
	int include_optional) {
	positioning_method_mdt_t *positioning_method_mdt = NULL;
	if(include_optional) {
		positioning_method_mdt = positioning_method_mdt_create(
			);
	} else {
		positioning_method_mdt = positioning_method_mdt_create(
			);
	}

	return positioning_method_mdt;
}


#ifdef positioning_method_mdt_MAIN

void test_positioning_method_mdt(int include_optional) {
	positioning_method_mdt_t *positioning_method_mdt_1 =
		instantiate_positioning_method_mdt(include_optional);

	cJSON *jsonpositioning_method_mdt_1 =
		positioning_method_mdt_convertToJSON(positioning_method_mdt_1);
	printf("positioning_method_mdt :\n%s\n",
	       cJSON_Print(jsonpositioning_method_mdt_1));
	positioning_method_mdt_t *positioning_method_mdt_2 =
		positioning_method_mdt_parseFromJSON(
			jsonpositioning_method_mdt_1);
	cJSON *jsonpositioning_method_mdt_2 =
		positioning_method_mdt_convertToJSON(positioning_method_mdt_2);
	printf("repeating positioning_method_mdt:\n%s\n",
	       cJSON_Print(jsonpositioning_method_mdt_2));
}

int main() {
	test_positioning_method_mdt(1);
	test_positioning_method_mdt(0);

	printf("Hello world \n");
	return 0;
}

#endif // positioning_method_mdt_MAIN
#endif // positioning_method_mdt_TEST
