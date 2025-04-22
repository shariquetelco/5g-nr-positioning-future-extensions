#ifndef accuracy_TEST
#define accuracy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define accuracy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/accuracy.h"
accuracy_t *instantiate_accuracy(int include_optional);



accuracy_t *instantiate_accuracy(int include_optional) {
	accuracy_t *accuracy = NULL;
	if(include_optional) {
		accuracy = accuracy_create(
			);
	} else {
		accuracy = accuracy_create(
			);
	}

	return accuracy;
}


#ifdef accuracy_MAIN

void test_accuracy(int include_optional) {
	accuracy_t *accuracy_1 = instantiate_accuracy(include_optional);

	cJSON *jsonaccuracy_1 = accuracy_convertToJSON(accuracy_1);
	printf("accuracy :\n%s\n", cJSON_Print(jsonaccuracy_1));
	accuracy_t *accuracy_2 = accuracy_parseFromJSON(jsonaccuracy_1);
	cJSON *jsonaccuracy_2 = accuracy_convertToJSON(accuracy_2);
	printf("repeating accuracy:\n%s\n", cJSON_Print(jsonaccuracy_2));
}

int main() {
	test_accuracy(1);
	test_accuracy(0);

	printf("Hello world \n");
	return 0;
}

#endif // accuracy_MAIN
#endif // accuracy_TEST
