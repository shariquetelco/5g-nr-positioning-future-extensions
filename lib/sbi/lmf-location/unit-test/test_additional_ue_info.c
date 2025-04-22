#ifndef additional_ue_info_TEST
#define additional_ue_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define additional_ue_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/additional_ue_info.h"
additional_ue_info_t *instantiate_additional_ue_info(int include_optional);

#include "test_ncgi.c"
#include "test_ecgi.c"


additional_ue_info_t *instantiate_additional_ue_info(int include_optional) {
	additional_ue_info_t *additional_ue_info = NULL;
	if(include_optional) {
		additional_ue_info = additional_ue_info_create(
			// false, not to have infinite recursion
			instantiate_ncgi(0),
			// false, not to have infinite recursion
			instantiate_ecgi(0)
			);
	} else {
		additional_ue_info = additional_ue_info_create(
			NULL,
			NULL
			);
	}

	return additional_ue_info;
}


#ifdef additional_ue_info_MAIN

void test_additional_ue_info(int include_optional) {
	additional_ue_info_t *additional_ue_info_1 =
		instantiate_additional_ue_info(include_optional);

	cJSON *jsonadditional_ue_info_1 = additional_ue_info_convertToJSON(
		additional_ue_info_1);
	printf("additional_ue_info :\n%s\n",
	       cJSON_Print(jsonadditional_ue_info_1));
	additional_ue_info_t *additional_ue_info_2 =
		additional_ue_info_parseFromJSON(jsonadditional_ue_info_1);
	cJSON *jsonadditional_ue_info_2 = additional_ue_info_convertToJSON(
		additional_ue_info_2);
	printf("repeating additional_ue_info:\n%s\n",
	       cJSON_Print(jsonadditional_ue_info_2));
}

int main() {
	test_additional_ue_info(1);
	test_additional_ue_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // additional_ue_info_MAIN
#endif // additional_ue_info_TEST
