#ifndef proximity_criterion_any_of_TEST
#define proximity_criterion_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define proximity_criterion_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/proximity_criterion_any_of.h"
proximity_criterion_any_of_t *instantiate_proximity_criterion_any_of(
	int include_optional);



proximity_criterion_any_of_t *instantiate_proximity_criterion_any_of(
	int include_optional) {
	proximity_criterion_any_of_t *proximity_criterion_any_of = NULL;
	if(include_optional) {
		proximity_criterion_any_of = proximity_criterion_any_of_create(
			);
	} else {
		proximity_criterion_any_of = proximity_criterion_any_of_create(
			);
	}

	return proximity_criterion_any_of;
}


#ifdef proximity_criterion_any_of_MAIN

void test_proximity_criterion_any_of(int include_optional) {
	proximity_criterion_any_of_t *proximity_criterion_any_of_1 =
		instantiate_proximity_criterion_any_of(include_optional);

	cJSON *jsonproximity_criterion_any_of_1 =
		proximity_criterion_any_of_convertToJSON(
			proximity_criterion_any_of_1);
	printf("proximity_criterion_any_of :\n%s\n",
	       cJSON_Print(jsonproximity_criterion_any_of_1));
	proximity_criterion_any_of_t *proximity_criterion_any_of_2 =
		proximity_criterion_any_of_parseFromJSON(
			jsonproximity_criterion_any_of_1);
	cJSON *jsonproximity_criterion_any_of_2 =
		proximity_criterion_any_of_convertToJSON(
			proximity_criterion_any_of_2);
	printf("repeating proximity_criterion_any_of:\n%s\n",
	       cJSON_Print(jsonproximity_criterion_any_of_2));
}

int main() {
	test_proximity_criterion_any_of(1);
	test_proximity_criterion_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // proximity_criterion_any_of_MAIN
#endif // proximity_criterion_any_of_TEST
