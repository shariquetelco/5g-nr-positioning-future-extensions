#ifndef ue_context_transfer_status_TEST
#define ue_context_transfer_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_context_transfer_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_context_transfer_status.h"
ue_context_transfer_status_t *instantiate_ue_context_transfer_status(
	int include_optional);



ue_context_transfer_status_t *instantiate_ue_context_transfer_status(
	int include_optional) {
	ue_context_transfer_status_t *ue_context_transfer_status = NULL;
	if(include_optional) {
		ue_context_transfer_status = ue_context_transfer_status_create(
			);
	} else {
		ue_context_transfer_status = ue_context_transfer_status_create(
			);
	}

	return ue_context_transfer_status;
}


#ifdef ue_context_transfer_status_MAIN

void test_ue_context_transfer_status(int include_optional) {
	ue_context_transfer_status_t *ue_context_transfer_status_1 =
		instantiate_ue_context_transfer_status(include_optional);

	cJSON *jsonue_context_transfer_status_1 =
		ue_context_transfer_status_convertToJSON(
			ue_context_transfer_status_1);
	printf("ue_context_transfer_status :\n%s\n",
	       cJSON_Print(jsonue_context_transfer_status_1));
	ue_context_transfer_status_t *ue_context_transfer_status_2 =
		ue_context_transfer_status_parseFromJSON(
			jsonue_context_transfer_status_1);
	cJSON *jsonue_context_transfer_status_2 =
		ue_context_transfer_status_convertToJSON(
			ue_context_transfer_status_2);
	printf("repeating ue_context_transfer_status:\n%s\n",
	       cJSON_Print(jsonue_context_transfer_status_2));
}

int main() {
	test_ue_context_transfer_status(1);
	test_ue_context_transfer_status(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_context_transfer_status_MAIN
#endif // ue_context_transfer_status_TEST
