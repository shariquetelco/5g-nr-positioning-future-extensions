#ifndef ref_to_binary_data_TEST
#define ref_to_binary_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ref_to_binary_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ref_to_binary_data.h"
ref_to_binary_data_t *instantiate_ref_to_binary_data(int include_optional);



ref_to_binary_data_t *instantiate_ref_to_binary_data(int include_optional) {
	ref_to_binary_data_t *ref_to_binary_data = NULL;
	if(include_optional) {
		ref_to_binary_data = ref_to_binary_data_create(
			"0"
			);
	} else {
		ref_to_binary_data = ref_to_binary_data_create(
			"0"
			);
	}

	return ref_to_binary_data;
}


#ifdef ref_to_binary_data_MAIN

void test_ref_to_binary_data(int include_optional) {
	ref_to_binary_data_t *ref_to_binary_data_1 =
		instantiate_ref_to_binary_data(include_optional);

	cJSON *jsonref_to_binary_data_1 = ref_to_binary_data_convertToJSON(
		ref_to_binary_data_1);
	printf("ref_to_binary_data :\n%s\n",
	       cJSON_Print(jsonref_to_binary_data_1));
	ref_to_binary_data_t *ref_to_binary_data_2 =
		ref_to_binary_data_parseFromJSON(jsonref_to_binary_data_1);
	cJSON *jsonref_to_binary_data_2 = ref_to_binary_data_convertToJSON(
		ref_to_binary_data_2);
	printf("repeating ref_to_binary_data:\n%s\n",
	       cJSON_Print(jsonref_to_binary_data_2));
}

int main() {
	test_ref_to_binary_data(1);
	test_ref_to_binary_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // ref_to_binary_data_MAIN
#endif // ref_to_binary_data_TEST
