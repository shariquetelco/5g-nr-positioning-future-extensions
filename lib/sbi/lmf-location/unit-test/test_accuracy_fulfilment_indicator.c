#ifndef accuracy_fulfilment_indicator_TEST
#define accuracy_fulfilment_indicator_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define accuracy_fulfilment_indicator_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/accuracy_fulfilment_indicator.h"
accuracy_fulfilment_indicator_t *instantiate_accuracy_fulfilment_indicator(
	int include_optional);



accuracy_fulfilment_indicator_t *instantiate_accuracy_fulfilment_indicator(
	int include_optional) {
	accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator = NULL;
	if(include_optional) {
		accuracy_fulfilment_indicator =
			accuracy_fulfilment_indicator_create(
				);
	} else {
		accuracy_fulfilment_indicator =
			accuracy_fulfilment_indicator_create(
				);
	}

	return accuracy_fulfilment_indicator;
}


#ifdef accuracy_fulfilment_indicator_MAIN

void test_accuracy_fulfilment_indicator(int include_optional) {
	accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator_1 =
		instantiate_accuracy_fulfilment_indicator(include_optional);

	cJSON *jsonaccuracy_fulfilment_indicator_1 =
		accuracy_fulfilment_indicator_convertToJSON(
			accuracy_fulfilment_indicator_1);
	printf("accuracy_fulfilment_indicator :\n%s\n",
	       cJSON_Print(jsonaccuracy_fulfilment_indicator_1));
	accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator_2 =
		accuracy_fulfilment_indicator_parseFromJSON(
			jsonaccuracy_fulfilment_indicator_1);
	cJSON *jsonaccuracy_fulfilment_indicator_2 =
		accuracy_fulfilment_indicator_convertToJSON(
			accuracy_fulfilment_indicator_2);
	printf("repeating accuracy_fulfilment_indicator:\n%s\n",
	       cJSON_Print(jsonaccuracy_fulfilment_indicator_2));
}

int main() {
	test_accuracy_fulfilment_indicator(1);
	test_accuracy_fulfilment_indicator(0);

	printf("Hello world \n");
	return 0;
}

#endif // accuracy_fulfilment_indicator_MAIN
#endif // accuracy_fulfilment_indicator_TEST
