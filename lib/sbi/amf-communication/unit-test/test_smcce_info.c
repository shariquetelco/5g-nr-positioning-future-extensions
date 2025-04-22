#ifndef smcce_info_TEST
#define smcce_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define smcce_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/smcce_info.h"
smcce_info_t *instantiate_smcce_info(int include_optional);

#include "test_snssai.c"
#include "test_smcce_ue_list.c"


smcce_info_t *instantiate_smcce_info(int include_optional) {
	smcce_info_t *smcce_info = NULL;
	if(include_optional) {
		smcce_info = smcce_info_create(
			"0",
			// false, not to have infinite recursion
			instantiate_snssai(0),
			// false, not to have infinite recursion
			instantiate_smcce_ue_list(0)
			);
	} else {
		smcce_info = smcce_info_create(
			"0",
			NULL,
			NULL
			);
	}

	return smcce_info;
}


#ifdef smcce_info_MAIN

void test_smcce_info(int include_optional) {
	smcce_info_t *smcce_info_1 = instantiate_smcce_info(include_optional);

	cJSON *jsonsmcce_info_1 = smcce_info_convertToJSON(smcce_info_1);
	printf("smcce_info :\n%s\n", cJSON_Print(jsonsmcce_info_1));
	smcce_info_t *smcce_info_2 = smcce_info_parseFromJSON(jsonsmcce_info_1);
	cJSON *jsonsmcce_info_2 = smcce_info_convertToJSON(smcce_info_2);
	printf("repeating smcce_info:\n%s\n", cJSON_Print(jsonsmcce_info_2));
}

int main() {
	test_smcce_info(1);
	test_smcce_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // smcce_info_MAIN
#endif // smcce_info_TEST
