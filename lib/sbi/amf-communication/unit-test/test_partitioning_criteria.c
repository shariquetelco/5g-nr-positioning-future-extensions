#ifndef partitioning_criteria_TEST
#define partitioning_criteria_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define partitioning_criteria_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/partitioning_criteria.h"
partitioning_criteria_t *instantiate_partitioning_criteria(
	int include_optional);



partitioning_criteria_t *instantiate_partitioning_criteria(int include_optional)
{
	partitioning_criteria_t *partitioning_criteria = NULL;
	if(include_optional) {
		partitioning_criteria = partitioning_criteria_create(
			);
	} else {
		partitioning_criteria = partitioning_criteria_create(
			);
	}

	return partitioning_criteria;
}


#ifdef partitioning_criteria_MAIN

void test_partitioning_criteria(int include_optional) {
	partitioning_criteria_t *partitioning_criteria_1 =
		instantiate_partitioning_criteria(include_optional);

	cJSON *jsonpartitioning_criteria_1 =
		partitioning_criteria_convertToJSON(partitioning_criteria_1);
	printf("partitioning_criteria :\n%s\n",
	       cJSON_Print(jsonpartitioning_criteria_1));
	partitioning_criteria_t *partitioning_criteria_2 =
		partitioning_criteria_parseFromJSON(jsonpartitioning_criteria_1);
	cJSON *jsonpartitioning_criteria_2 =
		partitioning_criteria_convertToJSON(partitioning_criteria_2);
	printf("repeating partitioning_criteria:\n%s\n",
	       cJSON_Print(jsonpartitioning_criteria_2));
}

int main() {
	test_partitioning_criteria(1);
	test_partitioning_criteria(0);

	printf("Hello world \n");
	return 0;
}

#endif // partitioning_criteria_MAIN
#endif // partitioning_criteria_TEST
