#ifndef snssai_dnn_item_TEST
#define snssai_dnn_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snssai_dnn_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snssai_dnn_item.h"
snssai_dnn_item_t *instantiate_snssai_dnn_item(int include_optional);



snssai_dnn_item_t *instantiate_snssai_dnn_item(int include_optional) {
	snssai_dnn_item_t *snssai_dnn_item = NULL;
	if(include_optional) {
		snssai_dnn_item = snssai_dnn_item_create(
			list_createList(),
			list_createList()
			);
	} else {
		snssai_dnn_item = snssai_dnn_item_create(
			list_createList(),
			list_createList()
			);
	}

	return snssai_dnn_item;
}


#ifdef snssai_dnn_item_MAIN

void test_snssai_dnn_item(int include_optional) {
	snssai_dnn_item_t *snssai_dnn_item_1 = instantiate_snssai_dnn_item(
		include_optional);

	cJSON *jsonsnssai_dnn_item_1 = snssai_dnn_item_convertToJSON(
		snssai_dnn_item_1);
	printf("snssai_dnn_item :\n%s\n", cJSON_Print(jsonsnssai_dnn_item_1));
	snssai_dnn_item_t *snssai_dnn_item_2 = snssai_dnn_item_parseFromJSON(
		jsonsnssai_dnn_item_1);
	cJSON *jsonsnssai_dnn_item_2 = snssai_dnn_item_convertToJSON(
		snssai_dnn_item_2);
	printf("repeating snssai_dnn_item:\n%s\n",
	       cJSON_Print(jsonsnssai_dnn_item_2));
}

int main() {
	test_snssai_dnn_item(1);
	test_snssai_dnn_item(0);

	printf("Hello world \n");
	return 0;
}

#endif // snssai_dnn_item_MAIN
#endif // snssai_dnn_item_TEST
