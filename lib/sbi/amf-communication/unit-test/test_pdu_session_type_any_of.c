#ifndef pdu_session_type_any_of_TEST
#define pdu_session_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pdu_session_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pdu_session_type_any_of.h"
pdu_session_type_any_of_t *instantiate_pdu_session_type_any_of(
	int include_optional);



pdu_session_type_any_of_t *instantiate_pdu_session_type_any_of(
	int include_optional) {
	pdu_session_type_any_of_t *pdu_session_type_any_of = NULL;
	if(include_optional) {
		pdu_session_type_any_of = pdu_session_type_any_of_create(
			);
	} else {
		pdu_session_type_any_of = pdu_session_type_any_of_create(
			);
	}

	return pdu_session_type_any_of;
}


#ifdef pdu_session_type_any_of_MAIN

void test_pdu_session_type_any_of(int include_optional) {
	pdu_session_type_any_of_t *pdu_session_type_any_of_1 =
		instantiate_pdu_session_type_any_of(include_optional);

	cJSON *jsonpdu_session_type_any_of_1 =
		pdu_session_type_any_of_convertToJSON(pdu_session_type_any_of_1);
	printf("pdu_session_type_any_of :\n%s\n",
	       cJSON_Print(jsonpdu_session_type_any_of_1));
	pdu_session_type_any_of_t *pdu_session_type_any_of_2 =
		pdu_session_type_any_of_parseFromJSON(
			jsonpdu_session_type_any_of_1);
	cJSON *jsonpdu_session_type_any_of_2 =
		pdu_session_type_any_of_convertToJSON(pdu_session_type_any_of_2);
	printf("repeating pdu_session_type_any_of:\n%s\n",
	       cJSON_Print(jsonpdu_session_type_any_of_2));
}

int main() {
	test_pdu_session_type_any_of(1);
	test_pdu_session_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // pdu_session_type_any_of_MAIN
#endif // pdu_session_type_any_of_TEST
