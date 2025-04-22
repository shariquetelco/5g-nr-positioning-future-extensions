#ifndef nwdaf_failure_code_TEST
#define nwdaf_failure_code_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nwdaf_failure_code_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nwdaf_failure_code.h"
nwdaf_failure_code_t *instantiate_nwdaf_failure_code(int include_optional);



nwdaf_failure_code_t *instantiate_nwdaf_failure_code(int include_optional) {
	nwdaf_failure_code_t *nwdaf_failure_code = NULL;
	if(include_optional) {
		nwdaf_failure_code = nwdaf_failure_code_create(
			);
	} else {
		nwdaf_failure_code = nwdaf_failure_code_create(
			);
	}

	return nwdaf_failure_code;
}


#ifdef nwdaf_failure_code_MAIN

void test_nwdaf_failure_code(int include_optional) {
	nwdaf_failure_code_t *nwdaf_failure_code_1 =
		instantiate_nwdaf_failure_code(include_optional);

	cJSON *jsonnwdaf_failure_code_1 = nwdaf_failure_code_convertToJSON(
		nwdaf_failure_code_1);
	printf("nwdaf_failure_code :\n%s\n",
	       cJSON_Print(jsonnwdaf_failure_code_1));
	nwdaf_failure_code_t *nwdaf_failure_code_2 =
		nwdaf_failure_code_parseFromJSON(jsonnwdaf_failure_code_1);
	cJSON *jsonnwdaf_failure_code_2 = nwdaf_failure_code_convertToJSON(
		nwdaf_failure_code_2);
	printf("repeating nwdaf_failure_code:\n%s\n",
	       cJSON_Print(jsonnwdaf_failure_code_2));
}

int main() {
	test_nwdaf_failure_code(1);
	test_nwdaf_failure_code(0);

	printf("Hello world \n");
	return 0;
}

#endif // nwdaf_failure_code_MAIN
#endif // nwdaf_failure_code_TEST
