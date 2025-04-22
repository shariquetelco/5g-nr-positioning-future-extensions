#ifndef ncgi_TEST
#define ncgi_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ncgi_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ncgi.h"
ncgi_t *instantiate_ncgi(int include_optional);

#include "test_plmn_id.c"


ncgi_t *instantiate_ncgi(int include_optional) {
	ncgi_t *ncgi = NULL;
	if(include_optional) {
		ncgi = ncgi_create(
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			"a",
			"a"
			);
	} else {
		ncgi = ncgi_create(
			NULL,
			"a",
			"a"
			);
	}

	return ncgi;
}


#ifdef ncgi_MAIN

void test_ncgi(int include_optional) {
	ncgi_t *ncgi_1 = instantiate_ncgi(include_optional);

	cJSON *jsonncgi_1 = ncgi_convertToJSON(ncgi_1);
	printf("ncgi :\n%s\n", cJSON_Print(jsonncgi_1));
	ncgi_t *ncgi_2 = ncgi_parseFromJSON(jsonncgi_1);
	cJSON *jsonncgi_2 = ncgi_convertToJSON(ncgi_2);
	printf("repeating ncgi:\n%s\n", cJSON_Print(jsonncgi_2));
}

int main() {
	test_ncgi(1);
	test_ncgi(0);

	printf("Hello world \n");
	return 0;
}

#endif // ncgi_MAIN
#endif // ncgi_TEST
