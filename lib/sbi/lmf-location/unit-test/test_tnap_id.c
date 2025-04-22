#ifndef tnap_id_TEST
#define tnap_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tnap_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tnap_id.h"
tnap_id_t *instantiate_tnap_id(int include_optional);



tnap_id_t *instantiate_tnap_id(int include_optional) {
	tnap_id_t *tnap_id = NULL;
	if(include_optional) {
		tnap_id = tnap_id_create(
			"0",
			"0",
			"YQ=="
			);
	} else {
		tnap_id = tnap_id_create(
			"0",
			"0",
			"YQ=="
			);
	}

	return tnap_id;
}


#ifdef tnap_id_MAIN

void test_tnap_id(int include_optional) {
	tnap_id_t *tnap_id_1 = instantiate_tnap_id(include_optional);

	cJSON *jsontnap_id_1 = tnap_id_convertToJSON(tnap_id_1);
	printf("tnap_id :\n%s\n", cJSON_Print(jsontnap_id_1));
	tnap_id_t *tnap_id_2 = tnap_id_parseFromJSON(jsontnap_id_1);
	cJSON *jsontnap_id_2 = tnap_id_convertToJSON(tnap_id_2);
	printf("repeating tnap_id:\n%s\n", cJSON_Print(jsontnap_id_2));
}

int main() {
	test_tnap_id(1);
	test_tnap_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // tnap_id_MAIN
#endif // tnap_id_TEST
