#ifndef ue_mobility_order_criterion_TEST
#define ue_mobility_order_criterion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_mobility_order_criterion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_mobility_order_criterion.h"
ue_mobility_order_criterion_t *instantiate_ue_mobility_order_criterion(
	int include_optional);



ue_mobility_order_criterion_t *instantiate_ue_mobility_order_criterion(
	int include_optional) {
	ue_mobility_order_criterion_t *ue_mobility_order_criterion = NULL;
	if(include_optional) {
		ue_mobility_order_criterion =
			ue_mobility_order_criterion_create(
				);
	} else {
		ue_mobility_order_criterion =
			ue_mobility_order_criterion_create(
				);
	}

	return ue_mobility_order_criterion;
}


#ifdef ue_mobility_order_criterion_MAIN

void test_ue_mobility_order_criterion(int include_optional) {
	ue_mobility_order_criterion_t *ue_mobility_order_criterion_1 =
		instantiate_ue_mobility_order_criterion(include_optional);

	cJSON *jsonue_mobility_order_criterion_1 =
		ue_mobility_order_criterion_convertToJSON(
			ue_mobility_order_criterion_1);
	printf("ue_mobility_order_criterion :\n%s\n",
	       cJSON_Print(jsonue_mobility_order_criterion_1));
	ue_mobility_order_criterion_t *ue_mobility_order_criterion_2 =
		ue_mobility_order_criterion_parseFromJSON(
			jsonue_mobility_order_criterion_1);
	cJSON *jsonue_mobility_order_criterion_2 =
		ue_mobility_order_criterion_convertToJSON(
			ue_mobility_order_criterion_2);
	printf("repeating ue_mobility_order_criterion:\n%s\n",
	       cJSON_Print(jsonue_mobility_order_criterion_2));
}

int main() {
	test_ue_mobility_order_criterion(1);
	test_ue_mobility_order_criterion(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_mobility_order_criterion_MAIN
#endif // ue_mobility_order_criterion_TEST
