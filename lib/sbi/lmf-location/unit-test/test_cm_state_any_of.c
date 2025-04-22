#ifndef cm_state_any_of_TEST
#define cm_state_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cm_state_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cm_state_any_of.h"
cm_state_any_of_t *instantiate_cm_state_any_of(int include_optional);



cm_state_any_of_t *instantiate_cm_state_any_of(int include_optional) {
	cm_state_any_of_t *cm_state_any_of = NULL;
	if(include_optional) {
		cm_state_any_of = cm_state_any_of_create(
			);
	} else {
		cm_state_any_of = cm_state_any_of_create(
			);
	}

	return cm_state_any_of;
}


#ifdef cm_state_any_of_MAIN

void test_cm_state_any_of(int include_optional) {
	cm_state_any_of_t *cm_state_any_of_1 = instantiate_cm_state_any_of(
		include_optional);

	cJSON *jsoncm_state_any_of_1 = cm_state_any_of_convertToJSON(
		cm_state_any_of_1);
	printf("cm_state_any_of :\n%s\n", cJSON_Print(jsoncm_state_any_of_1));
	cm_state_any_of_t *cm_state_any_of_2 = cm_state_any_of_parseFromJSON(
		jsoncm_state_any_of_1);
	cJSON *jsoncm_state_any_of_2 = cm_state_any_of_convertToJSON(
		cm_state_any_of_2);
	printf("repeating cm_state_any_of:\n%s\n",
	       cJSON_Print(jsoncm_state_any_of_2));
}

int main() {
	test_cm_state_any_of(1);
	test_cm_state_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // cm_state_any_of_MAIN
#endif // cm_state_any_of_TEST
