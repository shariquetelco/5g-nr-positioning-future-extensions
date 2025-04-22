#ifndef usage_TEST
#define usage_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define usage_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/usage.h"
usage_t *instantiate_usage(int include_optional);



usage_t *instantiate_usage(int include_optional) {
	usage_t *usage = NULL;
	if(include_optional) {
		usage = usage_create(
			);
	} else {
		usage = usage_create(
			);
	}

	return usage;
}


#ifdef usage_MAIN

void test_usage(int include_optional) {
	usage_t *usage_1 = instantiate_usage(include_optional);

	cJSON *jsonusage_1 = usage_convertToJSON(usage_1);
	printf("usage :\n%s\n", cJSON_Print(jsonusage_1));
	usage_t *usage_2 = usage_parseFromJSON(jsonusage_1);
	cJSON *jsonusage_2 = usage_convertToJSON(usage_2);
	printf("repeating usage:\n%s\n", cJSON_Print(jsonusage_2));
}

int main() {
	test_usage(1);
	test_usage(0);

	printf("Hello world \n");
	return 0;
}

#endif // usage_MAIN
#endif // usage_TEST
