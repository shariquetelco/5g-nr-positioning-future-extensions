#ifndef mapped_location_qo_s_eps_TEST
#define mapped_location_qo_s_eps_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mapped_location_qo_s_eps_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mapped_location_qo_s_eps.h"
mapped_location_qo_s_eps_t *instantiate_mapped_location_qo_s_eps(
	int include_optional);



mapped_location_qo_s_eps_t *instantiate_mapped_location_qo_s_eps(
	int include_optional) {
	mapped_location_qo_s_eps_t *mapped_location_qo_s_eps = NULL;
	if(include_optional) {
		mapped_location_qo_s_eps = mapped_location_qo_s_eps_create(
			0,
			0
			);
	} else {
		mapped_location_qo_s_eps = mapped_location_qo_s_eps_create(
			0,
			0
			);
	}

	return mapped_location_qo_s_eps;
}


#ifdef mapped_location_qo_s_eps_MAIN

void test_mapped_location_qo_s_eps(int include_optional) {
	mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_1 =
		instantiate_mapped_location_qo_s_eps(include_optional);

	cJSON *jsonmapped_location_qo_s_eps_1 =
		mapped_location_qo_s_eps_convertToJSON(
			mapped_location_qo_s_eps_1);
	printf("mapped_location_qo_s_eps :\n%s\n",
	       cJSON_Print(jsonmapped_location_qo_s_eps_1));
	mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_2 =
		mapped_location_qo_s_eps_parseFromJSON(
			jsonmapped_location_qo_s_eps_1);
	cJSON *jsonmapped_location_qo_s_eps_2 =
		mapped_location_qo_s_eps_convertToJSON(
			mapped_location_qo_s_eps_2);
	printf("repeating mapped_location_qo_s_eps:\n%s\n",
	       cJSON_Print(jsonmapped_location_qo_s_eps_2));
}

int main() {
	test_mapped_location_qo_s_eps(1);
	test_mapped_location_qo_s_eps(0);

	printf("Hello world \n");
	return 0;
}

#endif // mapped_location_qo_s_eps_MAIN
#endif // mapped_location_qo_s_eps_TEST
