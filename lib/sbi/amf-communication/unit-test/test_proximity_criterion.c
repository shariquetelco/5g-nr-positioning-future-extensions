#ifndef proximity_criterion_TEST
#define proximity_criterion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define proximity_criterion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/proximity_criterion.h"
proximity_criterion_t *instantiate_proximity_criterion(int include_optional);



proximity_criterion_t *instantiate_proximity_criterion(int include_optional) {
	proximity_criterion_t *proximity_criterion = NULL;
	if(include_optional) {
		proximity_criterion = proximity_criterion_create(
			);
	} else {
		proximity_criterion = proximity_criterion_create(
			);
	}

	return proximity_criterion;
}


#ifdef proximity_criterion_MAIN

void test_proximity_criterion(int include_optional) {
	proximity_criterion_t *proximity_criterion_1 =
		instantiate_proximity_criterion(include_optional);

	cJSON *jsonproximity_criterion_1 = proximity_criterion_convertToJSON(
		proximity_criterion_1);
	printf("proximity_criterion :\n%s\n",
	       cJSON_Print(jsonproximity_criterion_1));
	proximity_criterion_t *proximity_criterion_2 =
		proximity_criterion_parseFromJSON(jsonproximity_criterion_1);
	cJSON *jsonproximity_criterion_2 = proximity_criterion_convertToJSON(
		proximity_criterion_2);
	printf("repeating proximity_criterion:\n%s\n",
	       cJSON_Print(jsonproximity_criterion_2));
}

int main() {
	test_proximity_criterion(1);
	test_proximity_criterion(0);

	printf("Hello world \n");
	return 0;
}

#endif // proximity_criterion_MAIN
#endif // proximity_criterion_TEST
