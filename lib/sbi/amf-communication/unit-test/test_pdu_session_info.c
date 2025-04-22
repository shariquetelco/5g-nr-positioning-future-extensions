#ifndef pdu_session_info_TEST
#define pdu_session_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pdu_session_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pdu_session_info.h"
pdu_session_info_t *instantiate_pdu_session_info(int include_optional);

#include "test_snssai.c"


pdu_session_info_t *instantiate_pdu_session_info(int include_optional) {
	pdu_session_info_t *pdu_session_info = NULL;
	if(include_optional) {
		pdu_session_info = pdu_session_info_create(
			// false, not to have infinite recursion
			instantiate_snssai(0),
			"0"
			);
	} else {
		pdu_session_info = pdu_session_info_create(
			NULL,
			"0"
			);
	}

	return pdu_session_info;
}


#ifdef pdu_session_info_MAIN

void test_pdu_session_info(int include_optional) {
	pdu_session_info_t *pdu_session_info_1 = instantiate_pdu_session_info(
		include_optional);

	cJSON *jsonpdu_session_info_1 = pdu_session_info_convertToJSON(
		pdu_session_info_1);
	printf("pdu_session_info :\n%s\n", cJSON_Print(jsonpdu_session_info_1));
	pdu_session_info_t *pdu_session_info_2 = pdu_session_info_parseFromJSON(
		jsonpdu_session_info_1);
	cJSON *jsonpdu_session_info_2 = pdu_session_info_convertToJSON(
		pdu_session_info_2);
	printf("repeating pdu_session_info:\n%s\n",
	       cJSON_Print(jsonpdu_session_info_2));
}

int main() {
	test_pdu_session_info(1);
	test_pdu_session_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // pdu_session_info_MAIN
#endif // pdu_session_info_TEST
