#ifndef pdu_ses_traffic_info_TEST
#define pdu_ses_traffic_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pdu_ses_traffic_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pdu_ses_traffic_info.h"
pdu_ses_traffic_info_t *instantiate_pdu_ses_traffic_info(int include_optional);

#include "test_snssai.c"


pdu_ses_traffic_info_t *instantiate_pdu_ses_traffic_info(int include_optional) {
	pdu_ses_traffic_info_t *pdu_ses_traffic_info = NULL;
	if(include_optional) {
		pdu_ses_traffic_info = pdu_ses_traffic_info_create(
			list_createList(),
			"0",
			// false, not to have infinite recursion
			instantiate_snssai(0),
			list_createList(),
			list_createList()
			);
	} else {
		pdu_ses_traffic_info = pdu_ses_traffic_info_create(
			list_createList(),
			"0",
			NULL,
			list_createList(),
			list_createList()
			);
	}

	return pdu_ses_traffic_info;
}


#ifdef pdu_ses_traffic_info_MAIN

void test_pdu_ses_traffic_info(int include_optional) {
	pdu_ses_traffic_info_t *pdu_ses_traffic_info_1 =
		instantiate_pdu_ses_traffic_info(include_optional);

	cJSON *jsonpdu_ses_traffic_info_1 = pdu_ses_traffic_info_convertToJSON(
		pdu_ses_traffic_info_1);
	printf("pdu_ses_traffic_info :\n%s\n",
	       cJSON_Print(jsonpdu_ses_traffic_info_1));
	pdu_ses_traffic_info_t *pdu_ses_traffic_info_2 =
		pdu_ses_traffic_info_parseFromJSON(jsonpdu_ses_traffic_info_1);
	cJSON *jsonpdu_ses_traffic_info_2 = pdu_ses_traffic_info_convertToJSON(
		pdu_ses_traffic_info_2);
	printf("repeating pdu_ses_traffic_info:\n%s\n",
	       cJSON_Print(jsonpdu_ses_traffic_info_2));
}

int main() {
	test_pdu_ses_traffic_info(1);
	test_pdu_ses_traffic_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // pdu_ses_traffic_info_MAIN
#endif // pdu_ses_traffic_info_TEST
