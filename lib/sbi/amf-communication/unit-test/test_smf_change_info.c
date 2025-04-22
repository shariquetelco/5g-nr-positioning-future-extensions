#ifndef smf_change_info_TEST
#define smf_change_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define smf_change_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/smf_change_info.h"
smf_change_info_t *instantiate_smf_change_info(int include_optional);



smf_change_info_t *instantiate_smf_change_info(int include_optional) {
	smf_change_info_t *smf_change_info = NULL;
	if(include_optional) {
		smf_change_info = smf_change_info_create(
			list_createList(),
			namf_communication_smf_change_info__CHANGED
			);
	} else {
		smf_change_info = smf_change_info_create(
			list_createList(),
			namf_communication_smf_change_info__CHANGED
			);
	}

	return smf_change_info;
}


#ifdef smf_change_info_MAIN

void test_smf_change_info(int include_optional) {
	smf_change_info_t *smf_change_info_1 = instantiate_smf_change_info(
		include_optional);

	cJSON *jsonsmf_change_info_1 = smf_change_info_convertToJSON(
		smf_change_info_1);
	printf("smf_change_info :\n%s\n", cJSON_Print(jsonsmf_change_info_1));
	smf_change_info_t *smf_change_info_2 = smf_change_info_parseFromJSON(
		jsonsmf_change_info_1);
	cJSON *jsonsmf_change_info_2 = smf_change_info_convertToJSON(
		smf_change_info_2);
	printf("repeating smf_change_info:\n%s\n",
	       cJSON_Print(jsonsmf_change_info_2));
}

int main() {
	test_smf_change_info(1);
	test_smf_change_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // smf_change_info_MAIN
#endif // smf_change_info_TEST
