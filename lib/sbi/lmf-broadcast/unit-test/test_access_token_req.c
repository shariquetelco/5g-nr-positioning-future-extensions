#ifndef access_token_req_TEST
#define access_token_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define access_token_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/access_token_req.h"
access_token_req_t *instantiate_access_token_req(int include_optional);

#include "test_nf_type.c"
#include "test_nf_type.c"
#include "test_plmn_id.c"
#include "test_plmn_id.c"
#include "test_plmn_id_nid.c"


access_token_req_t *instantiate_access_token_req(int include_optional) {
	access_token_req_t *access_token_req = NULL;
	if(include_optional) {
		access_token_req = access_token_req_create(
			lmf_broadcast_access_token_req_GRANTTYPE_client_credentials,
			"0",
			null,
			null,
			"a",
			"0",
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			list_createList(),
			list_createList(),
			"a",
			list_createList(),
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			// false, not to have infinite recursion
			instantiate_plmn_id_nid(0),
			list_createList(),
			list_createList(),
			"0",
			"0",
			"0",
			"0"
			);
	} else {
		access_token_req = access_token_req_create(
			lmf_broadcast_access_token_req_GRANTTYPE_client_credentials,
			"0",
			null,
			null,
			"a",
			"0",
			NULL,
			list_createList(),
			list_createList(),
			"a",
			list_createList(),
			NULL,
			NULL,
			list_createList(),
			list_createList(),
			"0",
			"0",
			"0",
			"0"
			);
	}

	return access_token_req;
}


#ifdef access_token_req_MAIN

void test_access_token_req(int include_optional) {
	access_token_req_t *access_token_req_1 = instantiate_access_token_req(
		include_optional);

	cJSON *jsonaccess_token_req_1 = access_token_req_convertToJSON(
		access_token_req_1);
	printf("access_token_req :\n%s\n", cJSON_Print(jsonaccess_token_req_1));
	access_token_req_t *access_token_req_2 = access_token_req_parseFromJSON(
		jsonaccess_token_req_1);
	cJSON *jsonaccess_token_req_2 = access_token_req_convertToJSON(
		access_token_req_2);
	printf("repeating access_token_req:\n%s\n",
	       cJSON_Print(jsonaccess_token_req_2));
}

int main() {
	test_access_token_req(1);
	test_access_token_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // access_token_req_MAIN
#endif // access_token_req_TEST
