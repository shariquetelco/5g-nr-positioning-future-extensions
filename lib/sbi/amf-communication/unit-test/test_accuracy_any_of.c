#ifndef accuracy_any_of_TEST
#define accuracy_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define accuracy_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/accuracy_any_of.h"
accuracy_any_of_t *instantiate_accuracy_any_of(int include_optional);



accuracy_any_of_t *instantiate_accuracy_any_of(int include_optional) {
	accuracy_any_of_t *accuracy_any_of = NULL;
	if(include_optional) {
		accuracy_any_of = accuracy_any_of_create(
			);
	} else {
		accuracy_any_of = accuracy_any_of_create(
			);
	}

	return accuracy_any_of;
}


#ifdef accuracy_any_of_MAIN

void test_accuracy_any_of(int include_optional) {
	accuracy_any_of_t *accuracy_any_of_1 = instantiate_accuracy_any_of(
		include_optional);

	cJSON *jsonaccuracy_any_of_1 = accuracy_any_of_convertToJSON(
		accuracy_any_of_1);
	printf("accuracy_any_of :\n%s\n", cJSON_Print(jsonaccuracy_any_of_1));
	accuracy_any_of_t *accuracy_any_of_2 = accuracy_any_of_parseFromJSON(
		jsonaccuracy_any_of_1);
	cJSON *jsonaccuracy_any_of_2 = accuracy_any_of_convertToJSON(
		accuracy_any_of_2);
	printf("repeating accuracy_any_of:\n%s\n",
	       cJSON_Print(jsonaccuracy_any_of_2));
}

int main() {
	test_accuracy_any_of(1);
	test_accuracy_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // accuracy_any_of_MAIN
#endif // accuracy_any_of_TEST
