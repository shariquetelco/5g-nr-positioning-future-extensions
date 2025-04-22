#ifndef lp_hap_type_TEST
#define lp_hap_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lp_hap_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lp_hap_type.h"
lp_hap_type_t *instantiate_lp_hap_type(int include_optional);



lp_hap_type_t *instantiate_lp_hap_type(int include_optional) {
	lp_hap_type_t *lp_hap_type = NULL;
	if(include_optional) {
		lp_hap_type = lp_hap_type_create(
			);
	} else {
		lp_hap_type = lp_hap_type_create(
			);
	}

	return lp_hap_type;
}


#ifdef lp_hap_type_MAIN

void test_lp_hap_type(int include_optional) {
	lp_hap_type_t *lp_hap_type_1 =
		instantiate_lp_hap_type(include_optional);

	cJSON *jsonlp_hap_type_1 = lp_hap_type_convertToJSON(lp_hap_type_1);
	printf("lp_hap_type :\n%s\n", cJSON_Print(jsonlp_hap_type_1));
	lp_hap_type_t *lp_hap_type_2 = lp_hap_type_parseFromJSON(
		jsonlp_hap_type_1);
	cJSON *jsonlp_hap_type_2 = lp_hap_type_convertToJSON(lp_hap_type_2);
	printf("repeating lp_hap_type:\n%s\n", cJSON_Print(jsonlp_hap_type_2));
}

int main() {
	test_lp_hap_type(1);
	test_lp_hap_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // lp_hap_type_MAIN
#endif // lp_hap_type_TEST
