#ifndef pcf_ue_callback_info_TEST
#define pcf_ue_callback_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pcf_ue_callback_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pcf_ue_callback_info.h"
pcf_ue_callback_info_t *instantiate_pcf_ue_callback_info(int include_optional);



pcf_ue_callback_info_t *instantiate_pcf_ue_callback_info(int include_optional) {
	pcf_ue_callback_info_t *pcf_ue_callback_info = NULL;
	if(include_optional) {
		pcf_ue_callback_info = pcf_ue_callback_info_create(
			"0",
			"0"
			);
	} else {
		pcf_ue_callback_info = pcf_ue_callback_info_create(
			"0",
			"0"
			);
	}

	return pcf_ue_callback_info;
}


#ifdef pcf_ue_callback_info_MAIN

void test_pcf_ue_callback_info(int include_optional) {
	pcf_ue_callback_info_t *pcf_ue_callback_info_1 =
		instantiate_pcf_ue_callback_info(include_optional);

	cJSON *jsonpcf_ue_callback_info_1 = pcf_ue_callback_info_convertToJSON(
		pcf_ue_callback_info_1);
	printf("pcf_ue_callback_info :\n%s\n",
	       cJSON_Print(jsonpcf_ue_callback_info_1));
	pcf_ue_callback_info_t *pcf_ue_callback_info_2 =
		pcf_ue_callback_info_parseFromJSON(jsonpcf_ue_callback_info_1);
	cJSON *jsonpcf_ue_callback_info_2 = pcf_ue_callback_info_convertToJSON(
		pcf_ue_callback_info_2);
	printf("repeating pcf_ue_callback_info:\n%s\n",
	       cJSON_Print(jsonpcf_ue_callback_info_2));
}

int main() {
	test_pcf_ue_callback_info(1);
	test_pcf_ue_callback_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // pcf_ue_callback_info_MAIN
#endif // pcf_ue_callback_info_TEST
