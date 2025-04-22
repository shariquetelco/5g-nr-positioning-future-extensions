#ifndef ngran_failure_info_TEST
#define ngran_failure_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ngran_failure_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ngran_failure_info.h"
ngran_failure_info_t *instantiate_ngran_failure_info(int include_optional);



ngran_failure_info_t *instantiate_ngran_failure_info(int include_optional) {
	ngran_failure_info_t *ngran_failure_info = NULL;
	if(include_optional) {
		ngran_failure_info = ngran_failure_info_create(
			);
	} else {
		ngran_failure_info = ngran_failure_info_create(
			);
	}

	return ngran_failure_info;
}


#ifdef ngran_failure_info_MAIN

void test_ngran_failure_info(int include_optional) {
	ngran_failure_info_t *ngran_failure_info_1 =
		instantiate_ngran_failure_info(include_optional);

	cJSON *jsonngran_failure_info_1 = ngran_failure_info_convertToJSON(
		ngran_failure_info_1);
	printf("ngran_failure_info :\n%s\n",
	       cJSON_Print(jsonngran_failure_info_1));
	ngran_failure_info_t *ngran_failure_info_2 =
		ngran_failure_info_parseFromJSON(jsonngran_failure_info_1);
	cJSON *jsonngran_failure_info_2 = ngran_failure_info_convertToJSON(
		ngran_failure_info_2);
	printf("repeating ngran_failure_info:\n%s\n",
	       cJSON_Print(jsonngran_failure_info_2));
}

int main() {
	test_ngran_failure_info(1);
	test_ngran_failure_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // ngran_failure_info_MAIN
#endif // ngran_failure_info_TEST
