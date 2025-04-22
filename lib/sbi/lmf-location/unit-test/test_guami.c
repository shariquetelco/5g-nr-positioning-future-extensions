#ifndef guami_TEST
#define guami_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define guami_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/guami.h"
guami_t *instantiate_guami(int include_optional);

#include "test_plmn_id_nid.c"


guami_t *instantiate_guami(int include_optional) {
	guami_t *guami = NULL;
	if(include_optional) {
		guami = guami_create(
			// false, not to have infinite recursion
			instantiate_plmn_id_nid(0),
			"a"
			);
	} else {
		guami = guami_create(
			NULL,
			"a"
			);
	}

	return guami;
}


#ifdef guami_MAIN

void test_guami(int include_optional) {
	guami_t *guami_1 = instantiate_guami(include_optional);

	cJSON *jsonguami_1 = guami_convertToJSON(guami_1);
	printf("guami :\n%s\n", cJSON_Print(jsonguami_1));
	guami_t *guami_2 = guami_parseFromJSON(jsonguami_1);
	cJSON *jsonguami_2 = guami_convertToJSON(guami_2);
	printf("repeating guami:\n%s\n", cJSON_Print(jsonguami_2));
}

int main() {
	test_guami(1);
	test_guami(0);

	printf("Hello world \n");
	return 0;
}

#endif // guami_MAIN
#endif // guami_TEST
