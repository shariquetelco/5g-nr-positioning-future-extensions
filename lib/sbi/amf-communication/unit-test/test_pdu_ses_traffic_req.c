#ifndef pdu_ses_traffic_req_TEST
#define pdu_ses_traffic_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pdu_ses_traffic_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pdu_ses_traffic_req.h"
pdu_ses_traffic_req_t *instantiate_pdu_ses_traffic_req(int include_optional);



pdu_ses_traffic_req_t *instantiate_pdu_ses_traffic_req(int include_optional) {
	pdu_ses_traffic_req_t *pdu_ses_traffic_req = NULL;
	if(include_optional) {
		pdu_ses_traffic_req = pdu_ses_traffic_req_create(
			list_createList(),
			"0",
			list_createList()
			);
	} else {
		pdu_ses_traffic_req = pdu_ses_traffic_req_create(
			list_createList(),
			"0",
			list_createList()
			);
	}

	return pdu_ses_traffic_req;
}


#ifdef pdu_ses_traffic_req_MAIN

void test_pdu_ses_traffic_req(int include_optional) {
	pdu_ses_traffic_req_t *pdu_ses_traffic_req_1 =
		instantiate_pdu_ses_traffic_req(include_optional);

	cJSON *jsonpdu_ses_traffic_req_1 = pdu_ses_traffic_req_convertToJSON(
		pdu_ses_traffic_req_1);
	printf("pdu_ses_traffic_req :\n%s\n",
	       cJSON_Print(jsonpdu_ses_traffic_req_1));
	pdu_ses_traffic_req_t *pdu_ses_traffic_req_2 =
		pdu_ses_traffic_req_parseFromJSON(jsonpdu_ses_traffic_req_1);
	cJSON *jsonpdu_ses_traffic_req_2 = pdu_ses_traffic_req_convertToJSON(
		pdu_ses_traffic_req_2);
	printf("repeating pdu_ses_traffic_req:\n%s\n",
	       cJSON_Print(jsonpdu_ses_traffic_req_2));
}

int main() {
	test_pdu_ses_traffic_req(1);
	test_pdu_ses_traffic_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // pdu_ses_traffic_req_MAIN
#endif // pdu_ses_traffic_req_TEST
