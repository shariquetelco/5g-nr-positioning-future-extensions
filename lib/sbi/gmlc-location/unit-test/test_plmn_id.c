#ifndef plmn_id_TEST
#define plmn_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plmn_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plmn_id.h"
plmn_id_t *instantiate_plmn_id(int include_optional);



plmn_id_t *instantiate_plmn_id(int include_optional) {
	plmn_id_t *plmn_id = NULL;
	if(include_optional) {
		plmn_id = plmn_id_create(
			"a",
			"a"
			);
	} else {
		plmn_id = plmn_id_create(
			"a",
			"a"
			);
	}

	return plmn_id;
}


#ifdef plmn_id_MAIN

void test_plmn_id(int include_optional) {
	plmn_id_t *plmn_id_1 = instantiate_plmn_id(include_optional);

	cJSON *jsonplmn_id_1 = plmn_id_convertToJSON(plmn_id_1);
	printf("plmn_id :\n%s\n", cJSON_Print(jsonplmn_id_1));
	plmn_id_t *plmn_id_2 = plmn_id_parseFromJSON(jsonplmn_id_1);
	cJSON *jsonplmn_id_2 = plmn_id_convertToJSON(plmn_id_2);
	printf("repeating plmn_id:\n%s\n", cJSON_Print(jsonplmn_id_2));
}

int main() {
	test_plmn_id(1);
	test_plmn_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // plmn_id_MAIN
#endif // plmn_id_TEST
