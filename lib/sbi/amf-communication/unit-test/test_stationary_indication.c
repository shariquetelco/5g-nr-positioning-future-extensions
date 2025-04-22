#ifndef stationary_indication_TEST
#define stationary_indication_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stationary_indication_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stationary_indication.h"
stationary_indication_t *instantiate_stationary_indication(
	int include_optional);



stationary_indication_t *instantiate_stationary_indication(int include_optional)
{
	stationary_indication_t *stationary_indication = NULL;
	if(include_optional) {
		stationary_indication = stationary_indication_create(
			);
	} else {
		stationary_indication = stationary_indication_create(
			);
	}

	return stationary_indication;
}


#ifdef stationary_indication_MAIN

void test_stationary_indication(int include_optional) {
	stationary_indication_t *stationary_indication_1 =
		instantiate_stationary_indication(include_optional);

	cJSON *jsonstationary_indication_1 =
		stationary_indication_convertToJSON(stationary_indication_1);
	printf("stationary_indication :\n%s\n",
	       cJSON_Print(jsonstationary_indication_1));
	stationary_indication_t *stationary_indication_2 =
		stationary_indication_parseFromJSON(jsonstationary_indication_1);
	cJSON *jsonstationary_indication_2 =
		stationary_indication_convertToJSON(stationary_indication_2);
	printf("repeating stationary_indication:\n%s\n",
	       cJSON_Print(jsonstationary_indication_2));
}

int main() {
	test_stationary_indication(1);
	test_stationary_indication(0);

	printf("Hello world \n");
	return 0;
}

#endif // stationary_indication_MAIN
#endif // stationary_indication_TEST
