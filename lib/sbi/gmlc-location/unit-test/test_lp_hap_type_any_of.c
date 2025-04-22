#ifndef lp_hap_type_any_of_TEST
#define lp_hap_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lp_hap_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lp_hap_type_any_of.h"
lp_hap_type_any_of_t *instantiate_lp_hap_type_any_of(int include_optional);



lp_hap_type_any_of_t *instantiate_lp_hap_type_any_of(int include_optional) {
	lp_hap_type_any_of_t *lp_hap_type_any_of = NULL;
	if(include_optional) {
		lp_hap_type_any_of = lp_hap_type_any_of_create(
			);
	} else {
		lp_hap_type_any_of = lp_hap_type_any_of_create(
			);
	}

	return lp_hap_type_any_of;
}


#ifdef lp_hap_type_any_of_MAIN

void test_lp_hap_type_any_of(int include_optional) {
	lp_hap_type_any_of_t *lp_hap_type_any_of_1 =
		instantiate_lp_hap_type_any_of(include_optional);

	cJSON *jsonlp_hap_type_any_of_1 = lp_hap_type_any_of_convertToJSON(
		lp_hap_type_any_of_1);
	printf("lp_hap_type_any_of :\n%s\n",
	       cJSON_Print(jsonlp_hap_type_any_of_1));
	lp_hap_type_any_of_t *lp_hap_type_any_of_2 =
		lp_hap_type_any_of_parseFromJSON(jsonlp_hap_type_any_of_1);
	cJSON *jsonlp_hap_type_any_of_2 = lp_hap_type_any_of_convertToJSON(
		lp_hap_type_any_of_2);
	printf("repeating lp_hap_type_any_of:\n%s\n",
	       cJSON_Print(jsonlp_hap_type_any_of_2));
}

int main() {
	test_lp_hap_type_any_of(1);
	test_lp_hap_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // lp_hap_type_any_of_MAIN
#endif // lp_hap_type_any_of_TEST
