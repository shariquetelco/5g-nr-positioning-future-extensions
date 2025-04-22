#ifndef smcce_ue_list_TEST
#define smcce_ue_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define smcce_ue_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/smcce_ue_list.h"
smcce_ue_list_t *instantiate_smcce_ue_list(int include_optional);



smcce_ue_list_t *instantiate_smcce_ue_list(int include_optional) {
	smcce_ue_list_t *smcce_ue_list = NULL;
	if(include_optional) {
		smcce_ue_list = smcce_ue_list_create(
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		smcce_ue_list = smcce_ue_list_create(
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return smcce_ue_list;
}


#ifdef smcce_ue_list_MAIN

void test_smcce_ue_list(int include_optional) {
	smcce_ue_list_t *smcce_ue_list_1 = instantiate_smcce_ue_list(
		include_optional);

	cJSON *jsonsmcce_ue_list_1 =
		smcce_ue_list_convertToJSON(smcce_ue_list_1);
	printf("smcce_ue_list :\n%s\n", cJSON_Print(jsonsmcce_ue_list_1));
	smcce_ue_list_t *smcce_ue_list_2 = smcce_ue_list_parseFromJSON(
		jsonsmcce_ue_list_1);
	cJSON *jsonsmcce_ue_list_2 =
		smcce_ue_list_convertToJSON(smcce_ue_list_2);
	printf("repeating smcce_ue_list:\n%s\n", cJSON_Print(
		       jsonsmcce_ue_list_2));
}

int main() {
	test_smcce_ue_list(1);
	test_smcce_ue_list(0);

	printf("Hello world \n");
	return 0;
}

#endif // smcce_ue_list_MAIN
#endif // smcce_ue_list_TEST
