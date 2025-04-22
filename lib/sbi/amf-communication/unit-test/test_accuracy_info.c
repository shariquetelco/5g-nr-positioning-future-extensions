#ifndef accuracy_info_TEST
#define accuracy_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define accuracy_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/accuracy_info.h"
accuracy_info_t *instantiate_accuracy_info(int include_optional);

#include "test_analytics_accuracy_indication.c"


accuracy_info_t *instantiate_accuracy_info(int include_optional) {
	accuracy_info_t *accuracy_info = NULL;
	if(include_optional) {
		accuracy_info = accuracy_info_create(
			0,
			0,
			null
			);
	} else {
		accuracy_info = accuracy_info_create(
			0,
			0,
			null
			);
	}

	return accuracy_info;
}


#ifdef accuracy_info_MAIN

void test_accuracy_info(int include_optional) {
	accuracy_info_t *accuracy_info_1 = instantiate_accuracy_info(
		include_optional);

	cJSON *jsonaccuracy_info_1 =
		accuracy_info_convertToJSON(accuracy_info_1);
	printf("accuracy_info :\n%s\n", cJSON_Print(jsonaccuracy_info_1));
	accuracy_info_t *accuracy_info_2 = accuracy_info_parseFromJSON(
		jsonaccuracy_info_1);
	cJSON *jsonaccuracy_info_2 =
		accuracy_info_convertToJSON(accuracy_info_2);
	printf("repeating accuracy_info:\n%s\n", cJSON_Print(
		       jsonaccuracy_info_2));
}

int main() {
	test_accuracy_info(1);
	test_accuracy_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // accuracy_info_MAIN
#endif // accuracy_info_TEST
