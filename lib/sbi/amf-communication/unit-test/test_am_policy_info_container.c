#ifndef am_policy_info_container_TEST
#define am_policy_info_container_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define am_policy_info_container_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/am_policy_info_container.h"
am_policy_info_container_t *instantiate_am_policy_info_container(
	int include_optional);



am_policy_info_container_t *instantiate_am_policy_info_container(
	int include_optional) {
	am_policy_info_container_t *am_policy_info_container = NULL;
	if(include_optional) {
		am_policy_info_container = am_policy_info_container_create(
			list_createList()
			);
	} else {
		am_policy_info_container = am_policy_info_container_create(
			list_createList()
			);
	}

	return am_policy_info_container;
}


#ifdef am_policy_info_container_MAIN

void test_am_policy_info_container(int include_optional) {
	am_policy_info_container_t *am_policy_info_container_1 =
		instantiate_am_policy_info_container(include_optional);

	cJSON *jsonam_policy_info_container_1 =
		am_policy_info_container_convertToJSON(
			am_policy_info_container_1);
	printf("am_policy_info_container :\n%s\n",
	       cJSON_Print(jsonam_policy_info_container_1));
	am_policy_info_container_t *am_policy_info_container_2 =
		am_policy_info_container_parseFromJSON(
			jsonam_policy_info_container_1);
	cJSON *jsonam_policy_info_container_2 =
		am_policy_info_container_convertToJSON(
			am_policy_info_container_2);
	printf("repeating am_policy_info_container:\n%s\n",
	       cJSON_Print(jsonam_policy_info_container_2));
}

int main() {
	test_am_policy_info_container(1);
	test_am_policy_info_container(0);

	printf("Hello world \n");
	return 0;
}

#endif // am_policy_info_container_MAIN
#endif // am_policy_info_container_TEST
