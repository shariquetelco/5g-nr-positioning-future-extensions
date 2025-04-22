#ifndef pdu_session_type_TEST
#define pdu_session_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pdu_session_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pdu_session_type.h"
pdu_session_type_t *instantiate_pdu_session_type(int include_optional);



pdu_session_type_t *instantiate_pdu_session_type(int include_optional) {
	pdu_session_type_t *pdu_session_type = NULL;
	if(include_optional) {
		pdu_session_type = pdu_session_type_create(
			);
	} else {
		pdu_session_type = pdu_session_type_create(
			);
	}

	return pdu_session_type;
}


#ifdef pdu_session_type_MAIN

void test_pdu_session_type(int include_optional) {
	pdu_session_type_t *pdu_session_type_1 = instantiate_pdu_session_type(
		include_optional);

	cJSON *jsonpdu_session_type_1 = pdu_session_type_convertToJSON(
		pdu_session_type_1);
	printf("pdu_session_type :\n%s\n", cJSON_Print(jsonpdu_session_type_1));
	pdu_session_type_t *pdu_session_type_2 = pdu_session_type_parseFromJSON(
		jsonpdu_session_type_1);
	cJSON *jsonpdu_session_type_2 = pdu_session_type_convertToJSON(
		pdu_session_type_2);
	printf("repeating pdu_session_type:\n%s\n",
	       cJSON_Print(jsonpdu_session_type_2));
}

int main() {
	test_pdu_session_type(1);
	test_pdu_session_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // pdu_session_type_MAIN
#endif // pdu_session_type_TEST
