#ifndef smf_change_indication_TEST
#define smf_change_indication_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define smf_change_indication_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/smf_change_indication.h"
smf_change_indication_t *instantiate_smf_change_indication(
	int include_optional);



smf_change_indication_t *instantiate_smf_change_indication(int include_optional)
{
	smf_change_indication_t *smf_change_indication = NULL;
	if(include_optional) {
		smf_change_indication = smf_change_indication_create(
			);
	} else {
		smf_change_indication = smf_change_indication_create(
			);
	}

	return smf_change_indication;
}


#ifdef smf_change_indication_MAIN

void test_smf_change_indication(int include_optional) {
	smf_change_indication_t *smf_change_indication_1 =
		instantiate_smf_change_indication(include_optional);

	cJSON *jsonsmf_change_indication_1 =
		smf_change_indication_convertToJSON(smf_change_indication_1);
	printf("smf_change_indication :\n%s\n",
	       cJSON_Print(jsonsmf_change_indication_1));
	smf_change_indication_t *smf_change_indication_2 =
		smf_change_indication_parseFromJSON(jsonsmf_change_indication_1);
	cJSON *jsonsmf_change_indication_2 =
		smf_change_indication_convertToJSON(smf_change_indication_2);
	printf("repeating smf_change_indication:\n%s\n",
	       cJSON_Print(jsonsmf_change_indication_2));
}

int main() {
	test_smf_change_indication(1);
	test_smf_change_indication(0);

	printf("Hello world \n");
	return 0;
}

#endif // smf_change_indication_MAIN
#endif // smf_change_indication_TEST
