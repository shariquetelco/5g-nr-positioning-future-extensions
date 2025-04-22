#ifndef ranging_datas_TEST
#define ranging_datas_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ranging_datas_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ranging_datas.h"
ranging_datas_t *instantiate_ranging_datas(int include_optional);



ranging_datas_t *instantiate_ranging_datas(int include_optional) {
	ranging_datas_t *ranging_datas = NULL;
	if(include_optional) {
		ranging_datas = ranging_datas_create(
			list_createList()
			);
	} else {
		ranging_datas = ranging_datas_create(
			list_createList()
			);
	}

	return ranging_datas;
}


#ifdef ranging_datas_MAIN

void test_ranging_datas(int include_optional) {
	ranging_datas_t *ranging_datas_1 = instantiate_ranging_datas(
		include_optional);

	cJSON *jsonranging_datas_1 =
		ranging_datas_convertToJSON(ranging_datas_1);
	printf("ranging_datas :\n%s\n", cJSON_Print(jsonranging_datas_1));
	ranging_datas_t *ranging_datas_2 = ranging_datas_parseFromJSON(
		jsonranging_datas_1);
	cJSON *jsonranging_datas_2 =
		ranging_datas_convertToJSON(ranging_datas_2);
	printf("repeating ranging_datas:\n%s\n", cJSON_Print(
		       jsonranging_datas_2));
}

int main() {
	test_ranging_datas(1);
	test_ranging_datas(0);

	printf("Hello world \n");
	return 0;
}

#endif // ranging_datas_MAIN
#endif // ranging_datas_TEST
