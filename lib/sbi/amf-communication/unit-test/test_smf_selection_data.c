#ifndef smf_selection_data_TEST
#define smf_selection_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define smf_selection_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/smf_selection_data.h"
smf_selection_data_t *instantiate_smf_selection_data(int include_optional);

#include "test_snssai.c"
#include "test_snssai.c"


smf_selection_data_t *instantiate_smf_selection_data(int include_optional) {
	smf_selection_data_t *smf_selection_data = NULL;
	if(include_optional) {
		smf_selection_data = smf_selection_data_create(
			1,
			list_createList(),
			// false, not to have infinite recursion
			instantiate_snssai(0),
			// false, not to have infinite recursion
			instantiate_snssai(0),
			"0"
			);
	} else {
		smf_selection_data = smf_selection_data_create(
			1,
			list_createList(),
			NULL,
			NULL,
			"0"
			);
	}

	return smf_selection_data;
}


#ifdef smf_selection_data_MAIN

void test_smf_selection_data(int include_optional) {
	smf_selection_data_t *smf_selection_data_1 =
		instantiate_smf_selection_data(include_optional);

	cJSON *jsonsmf_selection_data_1 = smf_selection_data_convertToJSON(
		smf_selection_data_1);
	printf("smf_selection_data :\n%s\n",
	       cJSON_Print(jsonsmf_selection_data_1));
	smf_selection_data_t *smf_selection_data_2 =
		smf_selection_data_parseFromJSON(jsonsmf_selection_data_1);
	cJSON *jsonsmf_selection_data_2 = smf_selection_data_convertToJSON(
		smf_selection_data_2);
	printf("repeating smf_selection_data:\n%s\n",
	       cJSON_Print(jsonsmf_selection_data_2));
}

int main() {
	test_smf_selection_data(1);
	test_smf_selection_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // smf_selection_data_MAIN
#endif // smf_selection_data_TEST
