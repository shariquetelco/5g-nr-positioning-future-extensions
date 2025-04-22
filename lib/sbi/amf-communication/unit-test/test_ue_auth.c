#ifndef ue_auth_TEST
#define ue_auth_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_auth_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_auth.h"
ue_auth_t *instantiate_ue_auth(int include_optional);



ue_auth_t *instantiate_ue_auth(int include_optional) {
	ue_auth_t *ue_auth = NULL;
	if(include_optional) {
		ue_auth = ue_auth_create(
			);
	} else {
		ue_auth = ue_auth_create(
			);
	}

	return ue_auth;
}


#ifdef ue_auth_MAIN

void test_ue_auth(int include_optional) {
	ue_auth_t *ue_auth_1 = instantiate_ue_auth(include_optional);

	cJSON *jsonue_auth_1 = ue_auth_convertToJSON(ue_auth_1);
	printf("ue_auth :\n%s\n", cJSON_Print(jsonue_auth_1));
	ue_auth_t *ue_auth_2 = ue_auth_parseFromJSON(jsonue_auth_1);
	cJSON *jsonue_auth_2 = ue_auth_convertToJSON(ue_auth_2);
	printf("repeating ue_auth:\n%s\n", cJSON_Print(jsonue_auth_2));
}

int main() {
	test_ue_auth(1);
	test_ue_auth(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_auth_MAIN
#endif // ue_auth_TEST
