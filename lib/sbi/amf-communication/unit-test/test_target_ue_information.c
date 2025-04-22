#ifndef target_ue_information_TEST
#define target_ue_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define target_ue_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/target_ue_information.h"
target_ue_information_t *instantiate_target_ue_information(
	int include_optional);



target_ue_information_t *instantiate_target_ue_information(int include_optional)
{
	target_ue_information_t *target_ue_information = NULL;
	if(include_optional) {
		target_ue_information = target_ue_information_create(
			1,
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		target_ue_information = target_ue_information_create(
			1,
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return target_ue_information;
}


#ifdef target_ue_information_MAIN

void test_target_ue_information(int include_optional) {
	target_ue_information_t *target_ue_information_1 =
		instantiate_target_ue_information(include_optional);

	cJSON *jsontarget_ue_information_1 =
		target_ue_information_convertToJSON(target_ue_information_1);
	printf("target_ue_information :\n%s\n",
	       cJSON_Print(jsontarget_ue_information_1));
	target_ue_information_t *target_ue_information_2 =
		target_ue_information_parseFromJSON(jsontarget_ue_information_1);
	cJSON *jsontarget_ue_information_2 =
		target_ue_information_convertToJSON(target_ue_information_2);
	printf("repeating target_ue_information:\n%s\n",
	       cJSON_Print(jsontarget_ue_information_2));
}

int main() {
	test_target_ue_information(1);
	test_target_ue_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // target_ue_information_MAIN
#endif // target_ue_information_TEST
