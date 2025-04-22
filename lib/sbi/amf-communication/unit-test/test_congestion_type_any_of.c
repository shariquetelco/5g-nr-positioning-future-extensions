#ifndef congestion_type_any_of_TEST
#define congestion_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define congestion_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/congestion_type_any_of.h"
congestion_type_any_of_t *instantiate_congestion_type_any_of(
	int include_optional);



congestion_type_any_of_t *instantiate_congestion_type_any_of(
	int include_optional) {
	congestion_type_any_of_t *congestion_type_any_of = NULL;
	if(include_optional) {
		congestion_type_any_of = congestion_type_any_of_create(
			);
	} else {
		congestion_type_any_of = congestion_type_any_of_create(
			);
	}

	return congestion_type_any_of;
}


#ifdef congestion_type_any_of_MAIN

void test_congestion_type_any_of(int include_optional) {
	congestion_type_any_of_t *congestion_type_any_of_1 =
		instantiate_congestion_type_any_of(include_optional);

	cJSON *jsoncongestion_type_any_of_1 =
		congestion_type_any_of_convertToJSON(congestion_type_any_of_1);
	printf("congestion_type_any_of :\n%s\n",
	       cJSON_Print(jsoncongestion_type_any_of_1));
	congestion_type_any_of_t *congestion_type_any_of_2 =
		congestion_type_any_of_parseFromJSON(
			jsoncongestion_type_any_of_1);
	cJSON *jsoncongestion_type_any_of_2 =
		congestion_type_any_of_convertToJSON(congestion_type_any_of_2);
	printf("repeating congestion_type_any_of:\n%s\n",
	       cJSON_Print(jsoncongestion_type_any_of_2));
}

int main() {
	test_congestion_type_any_of(1);
	test_congestion_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // congestion_type_any_of_MAIN
#endif // congestion_type_any_of_TEST
