#ifndef pdu_session_context_TEST
#define pdu_session_context_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pdu_session_context_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pdu_session_context.h"
pdu_session_context_t *instantiate_pdu_session_context(int include_optional);

#include "test_snssai.c"
#include "test_snssai.c"
#include "test_cn_assisted_ran_para.c"
#include "test_snssai.c"
#include "test_snssai.c"
#include "test_ip_address.c"
#include "test_plmn_id.c"


pdu_session_context_t *instantiate_pdu_session_context(int include_optional) {
	pdu_session_context_t *pdu_session_context = NULL;
	if(include_optional) {
		pdu_session_context = pdu_session_context_create(
			0,
			"0",
			// false, not to have infinite recursion
			instantiate_snssai(0),
			// false, not to have infinite recursion
			instantiate_snssai(0),
			"0",
			"0",
			namf_communication_pdu_session_context__3GPP_ACCESS,
			namf_communication_pdu_session_context__3GPP_ACCESS,
			list_createList(),
			"0",
			"0",
			"0",
			namf_communication_pdu_session_context__NF_INSTANCE_BINDING,
			"0",
			"0",
			"0",
			namf_communication_pdu_session_context__NF_INSTANCE_BINDING,
			"0",
			"0",
			"0",
			namf_communication_pdu_session_context__NF_INSTANCE_BINDING,
			"0",
			"0",
			1,
			// false, not to have infinite recursion
			instantiate_cn_assisted_ran_para(0),
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			// false, not to have infinite recursion
			instantiate_snssai(0),
			// false, not to have infinite recursion
			instantiate_snssai(0),
			"0",
			"a",
			// false, not to have infinite recursion
			instantiate_ip_address(0),
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			"a",
			1,
			1
			);
	} else {
		pdu_session_context = pdu_session_context_create(
			0,
			"0",
			NULL,
			NULL,
			"0",
			"0",
			namf_communication_pdu_session_context__3GPP_ACCESS,
			namf_communication_pdu_session_context__3GPP_ACCESS,
			list_createList(),
			"0",
			"0",
			"0",
			namf_communication_pdu_session_context__NF_INSTANCE_BINDING,
			"0",
			"0",
			"0",
			namf_communication_pdu_session_context__NF_INSTANCE_BINDING,
			"0",
			"0",
			"0",
			namf_communication_pdu_session_context__NF_INSTANCE_BINDING,
			"0",
			"0",
			1,
			NULL,
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			NULL,
			NULL,
			"0",
			"a",
			NULL,
			NULL,
			"a",
			1,
			1
			);
	}

	return pdu_session_context;
}


#ifdef pdu_session_context_MAIN

void test_pdu_session_context(int include_optional) {
	pdu_session_context_t *pdu_session_context_1 =
		instantiate_pdu_session_context(include_optional);

	cJSON *jsonpdu_session_context_1 = pdu_session_context_convertToJSON(
		pdu_session_context_1);
	printf("pdu_session_context :\n%s\n",
	       cJSON_Print(jsonpdu_session_context_1));
	pdu_session_context_t *pdu_session_context_2 =
		pdu_session_context_parseFromJSON(jsonpdu_session_context_1);
	cJSON *jsonpdu_session_context_2 = pdu_session_context_convertToJSON(
		pdu_session_context_2);
	printf("repeating pdu_session_context:\n%s\n",
	       cJSON_Print(jsonpdu_session_context_2));
}

int main() {
	test_pdu_session_context(1);
	test_pdu_session_context(0);

	printf("Hello world \n");
	return 0;
}

#endif // pdu_session_context_MAIN
#endif // pdu_session_context_TEST
