#ifndef amf_status_info_TEST
#define amf_status_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define amf_status_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/amf_status_info.h"
amf_status_info_t *instantiate_amf_status_info(int include_optional);



amf_status_info_t *instantiate_amf_status_info(int include_optional) {
	amf_status_info_t *amf_status_info = NULL;
	if(include_optional) {
		amf_status_info = amf_status_info_create(
			list_createList(),
			namf_communication_amf_status_info__AMF_UNAVAILABLE,
			"a",
			"a"
			);
	} else {
		amf_status_info = amf_status_info_create(
			list_createList(),
			namf_communication_amf_status_info__AMF_UNAVAILABLE,
			"a",
			"a"
			);
	}

	return amf_status_info;
}


#ifdef amf_status_info_MAIN

void test_amf_status_info(int include_optional) {
	amf_status_info_t *amf_status_info_1 = instantiate_amf_status_info(
		include_optional);

	cJSON *jsonamf_status_info_1 = amf_status_info_convertToJSON(
		amf_status_info_1);
	printf("amf_status_info :\n%s\n", cJSON_Print(jsonamf_status_info_1));
	amf_status_info_t *amf_status_info_2 = amf_status_info_parseFromJSON(
		jsonamf_status_info_1);
	cJSON *jsonamf_status_info_2 = amf_status_info_convertToJSON(
		amf_status_info_2);
	printf("repeating amf_status_info:\n%s\n",
	       cJSON_Print(jsonamf_status_info_2));
}

int main() {
	test_amf_status_info(1);
	test_amf_status_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // amf_status_info_MAIN
#endif // amf_status_info_TEST
