#ifndef lcs_qos_class_TEST
#define lcs_qos_class_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lcs_qos_class_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lcs_qos_class.h"
lcs_qos_class_t *instantiate_lcs_qos_class(int include_optional);



lcs_qos_class_t *instantiate_lcs_qos_class(int include_optional) {
	lcs_qos_class_t *lcs_qos_class = NULL;
	if(include_optional) {
		lcs_qos_class = lcs_qos_class_create(
			);
	} else {
		lcs_qos_class = lcs_qos_class_create(
			);
	}

	return lcs_qos_class;
}


#ifdef lcs_qos_class_MAIN

void test_lcs_qos_class(int include_optional) {
	lcs_qos_class_t *lcs_qos_class_1 = instantiate_lcs_qos_class(
		include_optional);

	cJSON *jsonlcs_qos_class_1 =
		lcs_qos_class_convertToJSON(lcs_qos_class_1);
	printf("lcs_qos_class :\n%s\n", cJSON_Print(jsonlcs_qos_class_1));
	lcs_qos_class_t *lcs_qos_class_2 = lcs_qos_class_parseFromJSON(
		jsonlcs_qos_class_1);
	cJSON *jsonlcs_qos_class_2 =
		lcs_qos_class_convertToJSON(lcs_qos_class_2);
	printf("repeating lcs_qos_class:\n%s\n", cJSON_Print(
		       jsonlcs_qos_class_2));
}

int main() {
	test_lcs_qos_class(1);
	test_lcs_qos_class(0);

	printf("Hello world \n");
	return 0;
}

#endif // lcs_qos_class_MAIN
#endif // lcs_qos_class_TEST
