#ifndef cag_data_TEST
#define cag_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cag_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cag_data.h"
cag_data_t *instantiate_cag_data(int include_optional);



cag_data_t *instantiate_cag_data(int include_optional) {
	cag_data_t *cag_data = NULL;
	if(include_optional) {
		cag_data = cag_data_create(
			list_createList(),
			list_createList(),
			"2013-10-20T19:20:30+01:00"
			);
	} else {
		cag_data = cag_data_create(
			list_createList(),
			list_createList(),
			"2013-10-20T19:20:30+01:00"
			);
	}

	return cag_data;
}


#ifdef cag_data_MAIN

void test_cag_data(int include_optional) {
	cag_data_t *cag_data_1 = instantiate_cag_data(include_optional);

	cJSON *jsoncag_data_1 = cag_data_convertToJSON(cag_data_1);
	printf("cag_data :\n%s\n", cJSON_Print(jsoncag_data_1));
	cag_data_t *cag_data_2 = cag_data_parseFromJSON(jsoncag_data_1);
	cJSON *jsoncag_data_2 = cag_data_convertToJSON(cag_data_2);
	printf("repeating cag_data:\n%s\n", cJSON_Print(jsoncag_data_2));
}

int main() {
	test_cag_data(1);
	test_cag_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // cag_data_MAIN
#endif // cag_data_TEST
