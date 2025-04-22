#ifndef privacy_check_id_mapping_resp_data_TEST
#define privacy_check_id_mapping_resp_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define privacy_check_id_mapping_resp_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/privacy_check_id_mapping_resp_data.h"
privacy_check_id_mapping_resp_data_t *
instantiate_privacy_check_id_mapping_resp_data(int include_optional);



privacy_check_id_mapping_resp_data_t *
instantiate_privacy_check_id_mapping_resp_data(int include_optional) {
	privacy_check_id_mapping_resp_data_t *privacy_check_id_mapping_resp_data
	        = NULL;
	if(include_optional) {
		privacy_check_id_mapping_resp_data =
			privacy_check_id_mapping_resp_data_create(
				"0",
				"a"
				);
	} else {
		privacy_check_id_mapping_resp_data =
			privacy_check_id_mapping_resp_data_create(
				"0",
				"a"
				);
	}

	return privacy_check_id_mapping_resp_data;
}


#ifdef privacy_check_id_mapping_resp_data_MAIN

void test_privacy_check_id_mapping_resp_data(int include_optional) {
	privacy_check_id_mapping_resp_data_t *
	        privacy_check_id_mapping_resp_data_1 =
		instantiate_privacy_check_id_mapping_resp_data(include_optional);

	cJSON *jsonprivacy_check_id_mapping_resp_data_1 =
		privacy_check_id_mapping_resp_data_convertToJSON(
			privacy_check_id_mapping_resp_data_1);
	printf("privacy_check_id_mapping_resp_data :\n%s\n",
	       cJSON_Print(jsonprivacy_check_id_mapping_resp_data_1));
	privacy_check_id_mapping_resp_data_t *
	        privacy_check_id_mapping_resp_data_2 =
		privacy_check_id_mapping_resp_data_parseFromJSON(
			jsonprivacy_check_id_mapping_resp_data_1);
	cJSON *jsonprivacy_check_id_mapping_resp_data_2 =
		privacy_check_id_mapping_resp_data_convertToJSON(
			privacy_check_id_mapping_resp_data_2);
	printf("repeating privacy_check_id_mapping_resp_data:\n%s\n", cJSON_Print(
		       jsonprivacy_check_id_mapping_resp_data_2));
}

int main() {
	test_privacy_check_id_mapping_resp_data(1);
	test_privacy_check_id_mapping_resp_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // privacy_check_id_mapping_resp_data_MAIN
#endif // privacy_check_id_mapping_resp_data_TEST
