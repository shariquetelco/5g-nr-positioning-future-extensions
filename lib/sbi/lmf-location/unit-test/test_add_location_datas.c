#ifndef add_location_datas_TEST
#define add_location_datas_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define add_location_datas_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/add_location_datas.h"
add_location_datas_t *instantiate_add_location_datas(int include_optional);



add_location_datas_t *instantiate_add_location_datas(int include_optional) {
	add_location_datas_t *add_location_datas = NULL;
	if(include_optional) {
		add_location_datas = add_location_datas_create(
			list_createList()
			);
	} else {
		add_location_datas = add_location_datas_create(
			list_createList()
			);
	}

	return add_location_datas;
}


#ifdef add_location_datas_MAIN

void test_add_location_datas(int include_optional) {
	add_location_datas_t *add_location_datas_1 =
		instantiate_add_location_datas(include_optional);

	cJSON *jsonadd_location_datas_1 = add_location_datas_convertToJSON(
		add_location_datas_1);
	printf("add_location_datas :\n%s\n",
	       cJSON_Print(jsonadd_location_datas_1));
	add_location_datas_t *add_location_datas_2 =
		add_location_datas_parseFromJSON(jsonadd_location_datas_1);
	cJSON *jsonadd_location_datas_2 = add_location_datas_convertToJSON(
		add_location_datas_2);
	printf("repeating add_location_datas:\n%s\n",
	       cJSON_Print(jsonadd_location_datas_2));
}

int main() {
	test_add_location_datas(1);
	test_add_location_datas(0);

	printf("Hello world \n");
	return 0;
}

#endif // add_location_datas_MAIN
#endif // add_location_datas_TEST
