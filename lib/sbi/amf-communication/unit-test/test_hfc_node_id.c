#ifndef hfc_node_id_TEST
#define hfc_node_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define hfc_node_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/hfc_node_id.h"
hfc_node_id_t *instantiate_hfc_node_id(int include_optional);



hfc_node_id_t *instantiate_hfc_node_id(int include_optional) {
	hfc_node_id_t *hfc_node_id = NULL;
	if(include_optional) {
		hfc_node_id = hfc_node_id_create(
			"0"
			);
	} else {
		hfc_node_id = hfc_node_id_create(
			"0"
			);
	}

	return hfc_node_id;
}


#ifdef hfc_node_id_MAIN

void test_hfc_node_id(int include_optional) {
	hfc_node_id_t *hfc_node_id_1 =
		instantiate_hfc_node_id(include_optional);

	cJSON *jsonhfc_node_id_1 = hfc_node_id_convertToJSON(hfc_node_id_1);
	printf("hfc_node_id :\n%s\n", cJSON_Print(jsonhfc_node_id_1));
	hfc_node_id_t *hfc_node_id_2 = hfc_node_id_parseFromJSON(
		jsonhfc_node_id_1);
	cJSON *jsonhfc_node_id_2 = hfc_node_id_convertToJSON(hfc_node_id_2);
	printf("repeating hfc_node_id:\n%s\n", cJSON_Print(jsonhfc_node_id_2));
}

int main() {
	test_hfc_node_id(1);
	test_hfc_node_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // hfc_node_id_MAIN
#endif // hfc_node_id_TEST
