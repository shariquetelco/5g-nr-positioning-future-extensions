#ifndef partitioning_criteria_any_of_TEST
#define partitioning_criteria_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define partitioning_criteria_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/partitioning_criteria_any_of.h"
partitioning_criteria_any_of_t *instantiate_partitioning_criteria_any_of(
	int include_optional);



partitioning_criteria_any_of_t *instantiate_partitioning_criteria_any_of(
	int include_optional) {
	partitioning_criteria_any_of_t *partitioning_criteria_any_of = NULL;
	if(include_optional) {
		partitioning_criteria_any_of =
			partitioning_criteria_any_of_create(
				);
	} else {
		partitioning_criteria_any_of =
			partitioning_criteria_any_of_create(
				);
	}

	return partitioning_criteria_any_of;
}


#ifdef partitioning_criteria_any_of_MAIN

void test_partitioning_criteria_any_of(int include_optional) {
	partitioning_criteria_any_of_t *partitioning_criteria_any_of_1 =
		instantiate_partitioning_criteria_any_of(include_optional);

	cJSON *jsonpartitioning_criteria_any_of_1 =
		partitioning_criteria_any_of_convertToJSON(
			partitioning_criteria_any_of_1);
	printf("partitioning_criteria_any_of :\n%s\n",
	       cJSON_Print(jsonpartitioning_criteria_any_of_1));
	partitioning_criteria_any_of_t *partitioning_criteria_any_of_2 =
		partitioning_criteria_any_of_parseFromJSON(
			jsonpartitioning_criteria_any_of_1);
	cJSON *jsonpartitioning_criteria_any_of_2 =
		partitioning_criteria_any_of_convertToJSON(
			partitioning_criteria_any_of_2);
	printf("repeating partitioning_criteria_any_of:\n%s\n",
	       cJSON_Print(jsonpartitioning_criteria_any_of_2));
}

int main() {
	test_partitioning_criteria_any_of(1);
	test_partitioning_criteria_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // partitioning_criteria_any_of_MAIN
#endif // partitioning_criteria_any_of_TEST
