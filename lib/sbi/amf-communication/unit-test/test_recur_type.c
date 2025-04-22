#ifndef recur_type_TEST
#define recur_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define recur_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/recur_type.h"
recur_type_t *instantiate_recur_type(int include_optional);



recur_type_t *instantiate_recur_type(int include_optional) {
	recur_type_t *recur_type = NULL;
	if(include_optional) {
		recur_type = recur_type_create(
			);
	} else {
		recur_type = recur_type_create(
			);
	}

	return recur_type;
}


#ifdef recur_type_MAIN

void test_recur_type(int include_optional) {
	recur_type_t *recur_type_1 = instantiate_recur_type(include_optional);

	cJSON *jsonrecur_type_1 = recur_type_convertToJSON(recur_type_1);
	printf("recur_type :\n%s\n", cJSON_Print(jsonrecur_type_1));
	recur_type_t *recur_type_2 = recur_type_parseFromJSON(jsonrecur_type_1);
	cJSON *jsonrecur_type_2 = recur_type_convertToJSON(recur_type_2);
	printf("repeating recur_type:\n%s\n", cJSON_Print(jsonrecur_type_2));
}

int main() {
	test_recur_type(1);
	test_recur_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // recur_type_MAIN
#endif // recur_type_TEST
