#ifndef pro_se_information_TEST
#define pro_se_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pro_se_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pro_se_information.h"
pro_se_information_t *instantiate_pro_se_information(int include_optional);

#include "test_n2_info_content.c"


pro_se_information_t *instantiate_pro_se_information(int include_optional) {
	pro_se_information_t *pro_se_information = NULL;
	if(include_optional) {
		pro_se_information = pro_se_information_create(
			// false, not to have infinite recursion
			instantiate_n2_info_content(0)
			);
	} else {
		pro_se_information = pro_se_information_create(
			NULL
			);
	}

	return pro_se_information;
}


#ifdef pro_se_information_MAIN

void test_pro_se_information(int include_optional) {
	pro_se_information_t *pro_se_information_1 =
		instantiate_pro_se_information(include_optional);

	cJSON *jsonpro_se_information_1 = pro_se_information_convertToJSON(
		pro_se_information_1);
	printf("pro_se_information :\n%s\n",
	       cJSON_Print(jsonpro_se_information_1));
	pro_se_information_t *pro_se_information_2 =
		pro_se_information_parseFromJSON(jsonpro_se_information_1);
	cJSON *jsonpro_se_information_2 = pro_se_information_convertToJSON(
		pro_se_information_2);
	printf("repeating pro_se_information:\n%s\n",
	       cJSON_Print(jsonpro_se_information_2));
}

int main() {
	test_pro_se_information(1);
	test_pro_se_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // pro_se_information_MAIN
#endif // pro_se_information_TEST
