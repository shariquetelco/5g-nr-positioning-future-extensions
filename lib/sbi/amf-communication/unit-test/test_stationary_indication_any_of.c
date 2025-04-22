#ifndef stationary_indication_any_of_TEST
#define stationary_indication_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stationary_indication_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stationary_indication_any_of.h"
stationary_indication_any_of_t *instantiate_stationary_indication_any_of(
	int include_optional);



stationary_indication_any_of_t *instantiate_stationary_indication_any_of(
	int include_optional) {
	stationary_indication_any_of_t *stationary_indication_any_of = NULL;
	if(include_optional) {
		stationary_indication_any_of =
			stationary_indication_any_of_create(
				);
	} else {
		stationary_indication_any_of =
			stationary_indication_any_of_create(
				);
	}

	return stationary_indication_any_of;
}


#ifdef stationary_indication_any_of_MAIN

void test_stationary_indication_any_of(int include_optional) {
	stationary_indication_any_of_t *stationary_indication_any_of_1 =
		instantiate_stationary_indication_any_of(include_optional);

	cJSON *jsonstationary_indication_any_of_1 =
		stationary_indication_any_of_convertToJSON(
			stationary_indication_any_of_1);
	printf("stationary_indication_any_of :\n%s\n",
	       cJSON_Print(jsonstationary_indication_any_of_1));
	stationary_indication_any_of_t *stationary_indication_any_of_2 =
		stationary_indication_any_of_parseFromJSON(
			jsonstationary_indication_any_of_1);
	cJSON *jsonstationary_indication_any_of_2 =
		stationary_indication_any_of_convertToJSON(
			stationary_indication_any_of_2);
	printf("repeating stationary_indication_any_of:\n%s\n",
	       cJSON_Print(jsonstationary_indication_any_of_2));
}

int main() {
	test_stationary_indication_any_of(1);
	test_stationary_indication_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // stationary_indication_any_of_MAIN
#endif // stationary_indication_any_of_TEST
