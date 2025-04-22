#ifndef recur_time_TEST
#define recur_time_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define recur_time_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/recur_time.h"
recur_time_t *instantiate_recur_time(int include_optional);

#include "test_valid_time_period.c"
#include "test_recur_type.c"


recur_time_t *instantiate_recur_time(int include_optional) {
	recur_time_t *recur_time = NULL;
	if(include_optional) {
		recur_time = recur_time_create(
			// false, not to have infinite recursion
			instantiate_valid_time_period(0),
			null,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		recur_time = recur_time_create(
			NULL,
			null,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return recur_time;
}


#ifdef recur_time_MAIN

void test_recur_time(int include_optional) {
	recur_time_t *recur_time_1 = instantiate_recur_time(include_optional);

	cJSON *jsonrecur_time_1 = recur_time_convertToJSON(recur_time_1);
	printf("recur_time :\n%s\n", cJSON_Print(jsonrecur_time_1));
	recur_time_t *recur_time_2 = recur_time_parseFromJSON(jsonrecur_time_1);
	cJSON *jsonrecur_time_2 = recur_time_convertToJSON(recur_time_2);
	printf("repeating recur_time:\n%s\n", cJSON_Print(jsonrecur_time_2));
}

int main() {
	test_recur_time(1);
	test_recur_time(0);

	printf("Hello world \n");
	return 0;
}

#endif // recur_time_MAIN
#endif // recur_time_TEST
