#ifndef plmn_id_nid_TEST
#define plmn_id_nid_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plmn_id_nid_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plmn_id_nid.h"
plmn_id_nid_t *instantiate_plmn_id_nid(int include_optional);



plmn_id_nid_t *instantiate_plmn_id_nid(int include_optional) {
	plmn_id_nid_t *plmn_id_nid = NULL;
	if(include_optional) {
		plmn_id_nid = plmn_id_nid_create(
			"a",
			"a",
			"a"
			);
	} else {
		plmn_id_nid = plmn_id_nid_create(
			"a",
			"a",
			"a"
			);
	}

	return plmn_id_nid;
}


#ifdef plmn_id_nid_MAIN

void test_plmn_id_nid(int include_optional) {
	plmn_id_nid_t *plmn_id_nid_1 =
		instantiate_plmn_id_nid(include_optional);

	cJSON *jsonplmn_id_nid_1 = plmn_id_nid_convertToJSON(plmn_id_nid_1);
	printf("plmn_id_nid :\n%s\n", cJSON_Print(jsonplmn_id_nid_1));
	plmn_id_nid_t *plmn_id_nid_2 = plmn_id_nid_parseFromJSON(
		jsonplmn_id_nid_1);
	cJSON *jsonplmn_id_nid_2 = plmn_id_nid_convertToJSON(plmn_id_nid_2);
	printf("repeating plmn_id_nid:\n%s\n", cJSON_Print(jsonplmn_id_nid_2));
}

int main() {
	test_plmn_id_nid(1);
	test_plmn_id_nid(0);

	printf("Hello world \n");
	return 0;
}

#endif // plmn_id_nid_MAIN
#endif // plmn_id_nid_TEST
