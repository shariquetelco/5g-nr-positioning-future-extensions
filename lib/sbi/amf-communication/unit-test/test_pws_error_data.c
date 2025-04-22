#ifndef pws_error_data_TEST
#define pws_error_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pws_error_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pws_error_data.h"
pws_error_data_t *instantiate_pws_error_data(int include_optional);



pws_error_data_t *instantiate_pws_error_data(int include_optional) {
	pws_error_data_t *pws_error_data = NULL;
	if(include_optional) {
		pws_error_data = pws_error_data_create(
			56
			);
	} else {
		pws_error_data = pws_error_data_create(
			56
			);
	}

	return pws_error_data;
}


#ifdef pws_error_data_MAIN

void test_pws_error_data(int include_optional) {
	pws_error_data_t *pws_error_data_1 = instantiate_pws_error_data(
		include_optional);

	cJSON *jsonpws_error_data_1 = pws_error_data_convertToJSON(
		pws_error_data_1);
	printf("pws_error_data :\n%s\n", cJSON_Print(jsonpws_error_data_1));
	pws_error_data_t *pws_error_data_2 = pws_error_data_parseFromJSON(
		jsonpws_error_data_1);
	cJSON *jsonpws_error_data_2 = pws_error_data_convertToJSON(
		pws_error_data_2);
	printf("repeating pws_error_data:\n%s\n",
	       cJSON_Print(jsonpws_error_data_2));
}

int main() {
	test_pws_error_data(1);
	test_pws_error_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // pws_error_data_MAIN
#endif // pws_error_data_TEST
