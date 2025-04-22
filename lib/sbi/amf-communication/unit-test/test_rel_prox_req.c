#ifndef rel_prox_req_TEST
#define rel_prox_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rel_prox_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rel_prox_req.h"
rel_prox_req_t *instantiate_rel_prox_req(int include_optional);



rel_prox_req_t *instantiate_rel_prox_req(int include_optional) {
	rel_prox_req_t *rel_prox_req = NULL;
	if(include_optional) {
		rel_prox_req = rel_prox_req_create(
			list_createList(),
			0,
			list_createList()
			);
	} else {
		rel_prox_req = rel_prox_req_create(
			list_createList(),
			0,
			list_createList()
			);
	}

	return rel_prox_req;
}


#ifdef rel_prox_req_MAIN

void test_rel_prox_req(int include_optional) {
	rel_prox_req_t *rel_prox_req_1 = instantiate_rel_prox_req(
		include_optional);

	cJSON *jsonrel_prox_req_1 = rel_prox_req_convertToJSON(rel_prox_req_1);
	printf("rel_prox_req :\n%s\n", cJSON_Print(jsonrel_prox_req_1));
	rel_prox_req_t *rel_prox_req_2 = rel_prox_req_parseFromJSON(
		jsonrel_prox_req_1);
	cJSON *jsonrel_prox_req_2 = rel_prox_req_convertToJSON(rel_prox_req_2);
	printf("repeating rel_prox_req:\n%s\n",
	       cJSON_Print(jsonrel_prox_req_2));
}

int main() {
	test_rel_prox_req(1);
	test_rel_prox_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // rel_prox_req_MAIN
#endif // rel_prox_req_TEST
