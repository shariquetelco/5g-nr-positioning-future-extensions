#ifndef pws_response_data_TEST
#define pws_response_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pws_response_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pws_response_data.h"
pws_response_data_t *instantiate_pws_response_data(int include_optional);



pws_response_data_t *instantiate_pws_response_data(int include_optional) {
	pws_response_data_t *pws_response_data = NULL;
	if(include_optional) {
		pws_response_data = pws_response_data_create(
			0,
			0,
			56,
			list_createList(),
			namf_communication_pws_response_data_N2PWSSUBMISSIND_true
			);
	} else {
		pws_response_data = pws_response_data_create(
			0,
			0,
			56,
			list_createList(),
			namf_communication_pws_response_data_N2PWSSUBMISSIND_true
			);
	}

	return pws_response_data;
}


#ifdef pws_response_data_MAIN

void test_pws_response_data(int include_optional) {
	pws_response_data_t *pws_response_data_1 =
		instantiate_pws_response_data(include_optional);

	cJSON *jsonpws_response_data_1 = pws_response_data_convertToJSON(
		pws_response_data_1);
	printf("pws_response_data :\n%s\n",
	       cJSON_Print(jsonpws_response_data_1));
	pws_response_data_t *pws_response_data_2 =
		pws_response_data_parseFromJSON(jsonpws_response_data_1);
	cJSON *jsonpws_response_data_2 = pws_response_data_convertToJSON(
		pws_response_data_2);
	printf("repeating pws_response_data:\n%s\n",
	       cJSON_Print(jsonpws_response_data_2));
}

int main() {
	test_pws_response_data(1);
	test_pws_response_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // pws_response_data_MAIN
#endif // pws_response_data_TEST
