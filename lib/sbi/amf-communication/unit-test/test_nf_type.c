#ifndef nf_type_TEST
#define nf_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nf_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nf_type.h"
nf_type_t *instantiate_nf_type(int include_optional);



nf_type_t *instantiate_nf_type(int include_optional) {
	nf_type_t *nf_type = NULL;
	if(include_optional) {
		nf_type = nf_type_create(
			);
	} else {
		nf_type = nf_type_create(
			);
	}

	return nf_type;
}


#ifdef nf_type_MAIN

void test_nf_type(int include_optional) {
	nf_type_t *nf_type_1 = instantiate_nf_type(include_optional);

	cJSON *jsonnf_type_1 = nf_type_convertToJSON(nf_type_1);
	printf("nf_type :\n%s\n", cJSON_Print(jsonnf_type_1));
	nf_type_t *nf_type_2 = nf_type_parseFromJSON(jsonnf_type_1);
	cJSON *jsonnf_type_2 = nf_type_convertToJSON(nf_type_2);
	printf("repeating nf_type:\n%s\n", cJSON_Print(jsonnf_type_2));
}

int main() {
	test_nf_type(1);
	test_nf_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // nf_type_MAIN
#endif // nf_type_TEST
