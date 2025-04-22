#ifndef sms_support_TEST
#define sms_support_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sms_support_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sms_support.h"
sms_support_t *instantiate_sms_support(int include_optional);



sms_support_t *instantiate_sms_support(int include_optional) {
	sms_support_t *sms_support = NULL;
	if(include_optional) {
		sms_support = sms_support_create(
			);
	} else {
		sms_support = sms_support_create(
			);
	}

	return sms_support;
}


#ifdef sms_support_MAIN

void test_sms_support(int include_optional) {
	sms_support_t *sms_support_1 =
		instantiate_sms_support(include_optional);

	cJSON *jsonsms_support_1 = sms_support_convertToJSON(sms_support_1);
	printf("sms_support :\n%s\n", cJSON_Print(jsonsms_support_1));
	sms_support_t *sms_support_2 = sms_support_parseFromJSON(
		jsonsms_support_1);
	cJSON *jsonsms_support_2 = sms_support_convertToJSON(sms_support_2);
	printf("repeating sms_support:\n%s\n", cJSON_Print(jsonsms_support_2));
}

int main() {
	test_sms_support(1);
	test_sms_support(0);

	printf("Hello world \n");
	return 0;
}

#endif // sms_support_MAIN
#endif // sms_support_TEST
