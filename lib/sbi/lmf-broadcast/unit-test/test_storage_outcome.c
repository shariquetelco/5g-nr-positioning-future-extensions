#ifndef storage_outcome_TEST
#define storage_outcome_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define storage_outcome_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/storage_outcome.h"
storage_outcome_t *instantiate_storage_outcome(int include_optional);



storage_outcome_t *instantiate_storage_outcome(int include_optional) {
	storage_outcome_t *storage_outcome = NULL;
	if(include_optional) {
		storage_outcome = storage_outcome_create(
			);
	} else {
		storage_outcome = storage_outcome_create(
			);
	}

	return storage_outcome;
}


#ifdef storage_outcome_MAIN

void test_storage_outcome(int include_optional) {
	storage_outcome_t *storage_outcome_1 = instantiate_storage_outcome(
		include_optional);

	cJSON *jsonstorage_outcome_1 = storage_outcome_convertToJSON(
		storage_outcome_1);
	printf("storage_outcome :\n%s\n", cJSON_Print(jsonstorage_outcome_1));
	storage_outcome_t *storage_outcome_2 = storage_outcome_parseFromJSON(
		jsonstorage_outcome_1);
	cJSON *jsonstorage_outcome_2 = storage_outcome_convertToJSON(
		storage_outcome_2);
	printf("repeating storage_outcome:\n%s\n",
	       cJSON_Print(jsonstorage_outcome_2));
}

int main() {
	test_storage_outcome(1);
	test_storage_outcome(0);

	printf("Hello world \n");
	return 0;
}

#endif // storage_outcome_MAIN
#endif // storage_outcome_TEST
