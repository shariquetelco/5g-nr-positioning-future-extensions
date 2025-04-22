#ifndef nssaa_status_TEST
#define nssaa_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nssaa_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nssaa_status.h"
nssaa_status_t *instantiate_nssaa_status(int include_optional);

#include "test_snssai.c"
#include "test_auth_status.c"


nssaa_status_t *instantiate_nssaa_status(int include_optional) {
	nssaa_status_t *nssaa_status = NULL;
	if(include_optional) {
		nssaa_status = nssaa_status_create(
			// false, not to have infinite recursion
			instantiate_snssai(0),
			null
			);
	} else {
		nssaa_status = nssaa_status_create(
			NULL,
			null
			);
	}

	return nssaa_status;
}


#ifdef nssaa_status_MAIN

void test_nssaa_status(int include_optional) {
	nssaa_status_t *nssaa_status_1 = instantiate_nssaa_status(
		include_optional);

	cJSON *jsonnssaa_status_1 = nssaa_status_convertToJSON(nssaa_status_1);
	printf("nssaa_status :\n%s\n", cJSON_Print(jsonnssaa_status_1));
	nssaa_status_t *nssaa_status_2 = nssaa_status_parseFromJSON(
		jsonnssaa_status_1);
	cJSON *jsonnssaa_status_2 = nssaa_status_convertToJSON(nssaa_status_2);
	printf("repeating nssaa_status:\n%s\n",
	       cJSON_Print(jsonnssaa_status_2));
}

int main() {
	test_nssaa_status(1);
	test_nssaa_status(0);

	printf("Hello world \n");
	return 0;
}

#endif // nssaa_status_MAIN
#endif // nssaa_status_TEST
