#ifndef tss_information_TEST
#define tss_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tss_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tss_information.h"
tss_information_t *instantiate_tss_information(int include_optional);



tss_information_t *instantiate_tss_information(int include_optional) {
	tss_information_t *tss_information = NULL;
	if(include_optional) {
		tss_information = tss_information_create(
			"0",
			list_createList(),
			list_createList()
			);
	} else {
		tss_information = tss_information_create(
			"0",
			list_createList(),
			list_createList()
			);
	}

	return tss_information;
}


#ifdef tss_information_MAIN

void test_tss_information(int include_optional) {
	tss_information_t *tss_information_1 = instantiate_tss_information(
		include_optional);

	cJSON *jsontss_information_1 = tss_information_convertToJSON(
		tss_information_1);
	printf("tss_information :\n%s\n", cJSON_Print(jsontss_information_1));
	tss_information_t *tss_information_2 = tss_information_parseFromJSON(
		jsontss_information_1);
	cJSON *jsontss_information_2 = tss_information_convertToJSON(
		tss_information_2);
	printf("repeating tss_information:\n%s\n",
	       cJSON_Print(jsontss_information_2));
}

int main() {
	test_tss_information(1);
	test_tss_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // tss_information_MAIN
#endif // tss_information_TEST
