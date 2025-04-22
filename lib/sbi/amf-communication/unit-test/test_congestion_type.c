#ifndef congestion_type_TEST
#define congestion_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define congestion_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/congestion_type.h"
congestion_type_t *instantiate_congestion_type(int include_optional);



congestion_type_t *instantiate_congestion_type(int include_optional) {
	congestion_type_t *congestion_type = NULL;
	if(include_optional) {
		congestion_type = congestion_type_create(
			);
	} else {
		congestion_type = congestion_type_create(
			);
	}

	return congestion_type;
}


#ifdef congestion_type_MAIN

void test_congestion_type(int include_optional) {
	congestion_type_t *congestion_type_1 = instantiate_congestion_type(
		include_optional);

	cJSON *jsoncongestion_type_1 = congestion_type_convertToJSON(
		congestion_type_1);
	printf("congestion_type :\n%s\n", cJSON_Print(jsoncongestion_type_1));
	congestion_type_t *congestion_type_2 = congestion_type_parseFromJSON(
		jsoncongestion_type_1);
	cJSON *jsoncongestion_type_2 = congestion_type_convertToJSON(
		congestion_type_2);
	printf("repeating congestion_type:\n%s\n",
	       cJSON_Print(jsoncongestion_type_2));
}

int main() {
	test_congestion_type(1);
	test_congestion_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // congestion_type_MAIN
#endif // congestion_type_TEST
