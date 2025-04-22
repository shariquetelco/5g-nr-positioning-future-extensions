#ifndef transfer_reason_TEST
#define transfer_reason_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transfer_reason_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transfer_reason.h"
transfer_reason_t *instantiate_transfer_reason(int include_optional);



transfer_reason_t *instantiate_transfer_reason(int include_optional) {
	transfer_reason_t *transfer_reason = NULL;
	if(include_optional) {
		transfer_reason = transfer_reason_create(
			);
	} else {
		transfer_reason = transfer_reason_create(
			);
	}

	return transfer_reason;
}


#ifdef transfer_reason_MAIN

void test_transfer_reason(int include_optional) {
	transfer_reason_t *transfer_reason_1 = instantiate_transfer_reason(
		include_optional);

	cJSON *jsontransfer_reason_1 = transfer_reason_convertToJSON(
		transfer_reason_1);
	printf("transfer_reason :\n%s\n", cJSON_Print(jsontransfer_reason_1));
	transfer_reason_t *transfer_reason_2 = transfer_reason_parseFromJSON(
		jsontransfer_reason_1);
	cJSON *jsontransfer_reason_2 = transfer_reason_convertToJSON(
		transfer_reason_2);
	printf("repeating transfer_reason:\n%s\n",
	       cJSON_Print(jsontransfer_reason_2));
}

int main() {
	test_transfer_reason(1);
	test_transfer_reason(0);

	printf("Hello world \n");
	return 0;
}

#endif // transfer_reason_MAIN
#endif // transfer_reason_TEST
