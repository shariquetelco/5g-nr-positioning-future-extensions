#ifndef ue_trajectory_TEST
#define ue_trajectory_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_trajectory_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_trajectory.h"
ue_trajectory_t *instantiate_ue_trajectory(int include_optional);



ue_trajectory_t *instantiate_ue_trajectory(int include_optional) {
	ue_trajectory_t *ue_trajectory = NULL;
	if(include_optional) {
		ue_trajectory = ue_trajectory_create(
			"a",
			"a",
			list_createList()
			);
	} else {
		ue_trajectory = ue_trajectory_create(
			"a",
			"a",
			list_createList()
			);
	}

	return ue_trajectory;
}


#ifdef ue_trajectory_MAIN

void test_ue_trajectory(int include_optional) {
	ue_trajectory_t *ue_trajectory_1 = instantiate_ue_trajectory(
		include_optional);

	cJSON *jsonue_trajectory_1 =
		ue_trajectory_convertToJSON(ue_trajectory_1);
	printf("ue_trajectory :\n%s\n", cJSON_Print(jsonue_trajectory_1));
	ue_trajectory_t *ue_trajectory_2 = ue_trajectory_parseFromJSON(
		jsonue_trajectory_1);
	cJSON *jsonue_trajectory_2 =
		ue_trajectory_convertToJSON(ue_trajectory_2);
	printf("repeating ue_trajectory:\n%s\n", cJSON_Print(
		       jsonue_trajectory_2));
}

int main() {
	test_ue_trajectory(1);
	test_ue_trajectory(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_trajectory_MAIN
#endif // ue_trajectory_TEST
