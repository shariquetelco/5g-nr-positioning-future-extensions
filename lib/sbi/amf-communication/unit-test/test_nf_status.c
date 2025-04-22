#ifndef nf_status_TEST
#define nf_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nf_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nf_status.h"
nf_status_t *instantiate_nf_status(int include_optional);



nf_status_t *instantiate_nf_status(int include_optional) {
	nf_status_t *nf_status = NULL;
	if(include_optional) {
		nf_status = nf_status_create(
			1,
			1,
			1
			);
	} else {
		nf_status = nf_status_create(
			1,
			1,
			1
			);
	}

	return nf_status;
}


#ifdef nf_status_MAIN

void test_nf_status(int include_optional) {
	nf_status_t *nf_status_1 = instantiate_nf_status(include_optional);

	cJSON *jsonnf_status_1 = nf_status_convertToJSON(nf_status_1);
	printf("nf_status :\n%s\n", cJSON_Print(jsonnf_status_1));
	nf_status_t *nf_status_2 = nf_status_parseFromJSON(jsonnf_status_1);
	cJSON *jsonnf_status_2 = nf_status_convertToJSON(nf_status_2);
	printf("repeating nf_status:\n%s\n", cJSON_Print(jsonnf_status_2));
}

int main() {
	test_nf_status(1);
	test_nf_status(0);

	printf("Hello world \n");
	return 0;
}

#endif // nf_status_MAIN
#endif // nf_status_TEST
