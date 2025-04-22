#ifndef recur_type_any_of_TEST
#define recur_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define recur_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/recur_type_any_of.h"
recur_type_any_of_t *instantiate_recur_type_any_of(int include_optional);



recur_type_any_of_t *instantiate_recur_type_any_of(int include_optional) {
	recur_type_any_of_t *recur_type_any_of = NULL;
	if(include_optional) {
		recur_type_any_of = recur_type_any_of_create(
			);
	} else {
		recur_type_any_of = recur_type_any_of_create(
			);
	}

	return recur_type_any_of;
}


#ifdef recur_type_any_of_MAIN

void test_recur_type_any_of(int include_optional) {
	recur_type_any_of_t *recur_type_any_of_1 =
		instantiate_recur_type_any_of(include_optional);

	cJSON *jsonrecur_type_any_of_1 = recur_type_any_of_convertToJSON(
		recur_type_any_of_1);
	printf("recur_type_any_of :\n%s\n",
	       cJSON_Print(jsonrecur_type_any_of_1));
	recur_type_any_of_t *recur_type_any_of_2 =
		recur_type_any_of_parseFromJSON(jsonrecur_type_any_of_1);
	cJSON *jsonrecur_type_any_of_2 = recur_type_any_of_convertToJSON(
		recur_type_any_of_2);
	printf("repeating recur_type_any_of:\n%s\n",
	       cJSON_Print(jsonrecur_type_any_of_2));
}

int main() {
	test_recur_type_any_of(1);
	test_recur_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // recur_type_any_of_MAIN
#endif // recur_type_any_of_TEST
