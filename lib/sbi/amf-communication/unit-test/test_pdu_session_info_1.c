#ifndef pdu_session_info_1_TEST
#define pdu_session_info_1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pdu_session_info_1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pdu_session_info_1.h"
pdu_session_info_1_t *instantiate_pdu_session_info_1(int include_optional);

#include "test_pdu_session_type.c"
#include "test_ssc_mode.c"


pdu_session_info_1_t *instantiate_pdu_session_info_1(int include_optional) {
	pdu_session_info_1_t *pdu_session_info_1 = NULL;
	if(include_optional) {
		pdu_session_info_1 = pdu_session_info_1_create(
			null,
			null,
			list_createList()
			);
	} else {
		pdu_session_info_1 = pdu_session_info_1_create(
			null,
			null,
			list_createList()
			);
	}

	return pdu_session_info_1;
}


#ifdef pdu_session_info_1_MAIN

void test_pdu_session_info_1(int include_optional) {
	pdu_session_info_1_t *pdu_session_info_1_1 =
		instantiate_pdu_session_info_1(include_optional);

	cJSON *jsonpdu_session_info_1_1 = pdu_session_info_1_convertToJSON(
		pdu_session_info_1_1);
	printf("pdu_session_info_1 :\n%s\n",
	       cJSON_Print(jsonpdu_session_info_1_1));
	pdu_session_info_1_t *pdu_session_info_1_2 =
		pdu_session_info_1_parseFromJSON(jsonpdu_session_info_1_1);
	cJSON *jsonpdu_session_info_1_2 = pdu_session_info_1_convertToJSON(
		pdu_session_info_1_2);
	printf("repeating pdu_session_info_1:\n%s\n",
	       cJSON_Print(jsonpdu_session_info_1_2));
}

int main() {
	test_pdu_session_info_1(1);
	test_pdu_session_info_1(0);

	printf("Hello world \n");
	return 0;
}

#endif // pdu_session_info_1_MAIN
#endif // pdu_session_info_1_TEST
