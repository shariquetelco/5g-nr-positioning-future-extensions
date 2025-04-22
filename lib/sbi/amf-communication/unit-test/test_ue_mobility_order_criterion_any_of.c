#ifndef ue_mobility_order_criterion_any_of_TEST
#define ue_mobility_order_criterion_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_mobility_order_criterion_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_mobility_order_criterion_any_of.h"
ue_mobility_order_criterion_any_of_t *
instantiate_ue_mobility_order_criterion_any_of(int include_optional);



ue_mobility_order_criterion_any_of_t *
instantiate_ue_mobility_order_criterion_any_of(int include_optional) {
	ue_mobility_order_criterion_any_of_t *ue_mobility_order_criterion_any_of
	        = NULL;
	if(include_optional) {
		ue_mobility_order_criterion_any_of =
			ue_mobility_order_criterion_any_of_create(
				);
	} else {
		ue_mobility_order_criterion_any_of =
			ue_mobility_order_criterion_any_of_create(
				);
	}

	return ue_mobility_order_criterion_any_of;
}


#ifdef ue_mobility_order_criterion_any_of_MAIN

void test_ue_mobility_order_criterion_any_of(int include_optional) {
	ue_mobility_order_criterion_any_of_t *
	        ue_mobility_order_criterion_any_of_1 =
		instantiate_ue_mobility_order_criterion_any_of(include_optional);

	cJSON *jsonue_mobility_order_criterion_any_of_1 =
		ue_mobility_order_criterion_any_of_convertToJSON(
			ue_mobility_order_criterion_any_of_1);
	printf("ue_mobility_order_criterion_any_of :\n%s\n",
	       cJSON_Print(jsonue_mobility_order_criterion_any_of_1));
	ue_mobility_order_criterion_any_of_t *
	        ue_mobility_order_criterion_any_of_2 =
		ue_mobility_order_criterion_any_of_parseFromJSON(
			jsonue_mobility_order_criterion_any_of_1);
	cJSON *jsonue_mobility_order_criterion_any_of_2 =
		ue_mobility_order_criterion_any_of_convertToJSON(
			ue_mobility_order_criterion_any_of_2);
	printf("repeating ue_mobility_order_criterion_any_of:\n%s\n", cJSON_Print(
		       jsonue_mobility_order_criterion_any_of_2));
}

int main() {
	test_ue_mobility_order_criterion_any_of(1);
	test_ue_mobility_order_criterion_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_mobility_order_criterion_any_of_MAIN
#endif // ue_mobility_order_criterion_any_of_TEST
