#ifndef cm_state_TEST
#define cm_state_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cm_state_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cm_state.h"
cm_state_t *instantiate_cm_state(int include_optional);



cm_state_t *instantiate_cm_state(int include_optional) {
	cm_state_t *cm_state = NULL;
	if(include_optional) {
		cm_state = cm_state_create(
			);
	} else {
		cm_state = cm_state_create(
			);
	}

	return cm_state;
}


#ifdef cm_state_MAIN

void test_cm_state(int include_optional) {
	cm_state_t *cm_state_1 = instantiate_cm_state(include_optional);

	cJSON *jsoncm_state_1 = cm_state_convertToJSON(cm_state_1);
	printf("cm_state :\n%s\n", cJSON_Print(jsoncm_state_1));
	cm_state_t *cm_state_2 = cm_state_parseFromJSON(jsoncm_state_1);
	cJSON *jsoncm_state_2 = cm_state_convertToJSON(cm_state_2);
	printf("repeating cm_state:\n%s\n", cJSON_Print(jsoncm_state_2));
}

int main() {
	test_cm_state(1);
	test_cm_state(0);

	printf("Hello world \n");
	return 0;
}

#endif // cm_state_MAIN
#endif // cm_state_TEST
