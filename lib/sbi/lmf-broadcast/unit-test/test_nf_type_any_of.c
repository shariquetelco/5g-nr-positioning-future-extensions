#ifndef nf_type_any_of_TEST
#define nf_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nf_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nf_type_any_of.h"
nf_type_any_of_t *instantiate_nf_type_any_of(int include_optional);



nf_type_any_of_t *instantiate_nf_type_any_of(int include_optional) {
	nf_type_any_of_t *nf_type_any_of = NULL;
	if(include_optional) {
		nf_type_any_of = nf_type_any_of_create(
			);
	} else {
		nf_type_any_of = nf_type_any_of_create(
			);
	}

	return nf_type_any_of;
}


#ifdef nf_type_any_of_MAIN

void test_nf_type_any_of(int include_optional) {
	nf_type_any_of_t *nf_type_any_of_1 = instantiate_nf_type_any_of(
		include_optional);

	cJSON *jsonnf_type_any_of_1 = nf_type_any_of_convertToJSON(
		nf_type_any_of_1);
	printf("nf_type_any_of :\n%s\n", cJSON_Print(jsonnf_type_any_of_1));
	nf_type_any_of_t *nf_type_any_of_2 = nf_type_any_of_parseFromJSON(
		jsonnf_type_any_of_1);
	cJSON *jsonnf_type_any_of_2 = nf_type_any_of_convertToJSON(
		nf_type_any_of_2);
	printf("repeating nf_type_any_of:\n%s\n",
	       cJSON_Print(jsonnf_type_any_of_2));
}

int main() {
	test_nf_type_any_of(1);
	test_nf_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // nf_type_any_of_MAIN
#endif // nf_type_any_of_TEST
