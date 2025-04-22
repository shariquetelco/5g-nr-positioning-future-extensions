#ifndef ranging_sl_result_TEST
#define ranging_sl_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ranging_sl_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ranging_sl_result.h"
ranging_sl_result_t *instantiate_ranging_sl_result(int include_optional);



ranging_sl_result_t *instantiate_ranging_sl_result(int include_optional) {
	ranging_sl_result_t *ranging_sl_result = NULL;
	if(include_optional) {
		ranging_sl_result = ranging_sl_result_create(
			);
	} else {
		ranging_sl_result = ranging_sl_result_create(
			);
	}

	return ranging_sl_result;
}


#ifdef ranging_sl_result_MAIN

void test_ranging_sl_result(int include_optional) {
	ranging_sl_result_t *ranging_sl_result_1 =
		instantiate_ranging_sl_result(include_optional);

	cJSON *jsonranging_sl_result_1 = ranging_sl_result_convertToJSON(
		ranging_sl_result_1);
	printf("ranging_sl_result :\n%s\n",
	       cJSON_Print(jsonranging_sl_result_1));
	ranging_sl_result_t *ranging_sl_result_2 =
		ranging_sl_result_parseFromJSON(jsonranging_sl_result_1);
	cJSON *jsonranging_sl_result_2 = ranging_sl_result_convertToJSON(
		ranging_sl_result_2);
	printf("repeating ranging_sl_result:\n%s\n",
	       cJSON_Print(jsonranging_sl_result_2));
}

int main() {
	test_ranging_sl_result(1);
	test_ranging_sl_result(0);

	printf("Hello world \n");
	return 0;
}

#endif // ranging_sl_result_MAIN
#endif // ranging_sl_result_TEST
