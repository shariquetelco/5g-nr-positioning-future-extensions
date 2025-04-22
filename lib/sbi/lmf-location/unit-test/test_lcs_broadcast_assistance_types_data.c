#ifndef lcs_broadcast_assistance_types_data_TEST
#define lcs_broadcast_assistance_types_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lcs_broadcast_assistance_types_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lcs_broadcast_assistance_types_data.h"
lcs_broadcast_assistance_types_data_t *
instantiate_lcs_broadcast_assistance_types_data(int include_optional);



lcs_broadcast_assistance_types_data_t *
instantiate_lcs_broadcast_assistance_types_data(int include_optional) {
	lcs_broadcast_assistance_types_data_t *
	        lcs_broadcast_assistance_types_data = NULL;
	if(include_optional) {
		lcs_broadcast_assistance_types_data =
			lcs_broadcast_assistance_types_data_create(
				instantiate_binary_t("blah", 5)
				);
	} else {
		lcs_broadcast_assistance_types_data =
			lcs_broadcast_assistance_types_data_create(
				instantiate_binary_t("blah", 5)
				);
	}

	return lcs_broadcast_assistance_types_data;
}


#ifdef lcs_broadcast_assistance_types_data_MAIN

void test_lcs_broadcast_assistance_types_data(int include_optional) {
	lcs_broadcast_assistance_types_data_t *
	        lcs_broadcast_assistance_types_data_1 =
		instantiate_lcs_broadcast_assistance_types_data(include_optional);

	cJSON *jsonlcs_broadcast_assistance_types_data_1 =
		lcs_broadcast_assistance_types_data_convertToJSON(
			lcs_broadcast_assistance_types_data_1);
	printf("lcs_broadcast_assistance_types_data :\n%s\n",
	       cJSON_Print(jsonlcs_broadcast_assistance_types_data_1));
	lcs_broadcast_assistance_types_data_t *
	        lcs_broadcast_assistance_types_data_2 =
		lcs_broadcast_assistance_types_data_parseFromJSON(
			jsonlcs_broadcast_assistance_types_data_1);
	cJSON *jsonlcs_broadcast_assistance_types_data_2 =
		lcs_broadcast_assistance_types_data_convertToJSON(
			lcs_broadcast_assistance_types_data_2);
	printf("repeating lcs_broadcast_assistance_types_data:\n%s\n", cJSON_Print(
		       jsonlcs_broadcast_assistance_types_data_2));
}

int main() {
	test_lcs_broadcast_assistance_types_data(1);
	test_lcs_broadcast_assistance_types_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // lcs_broadcast_assistance_types_data_MAIN
#endif // lcs_broadcast_assistance_types_data_TEST
