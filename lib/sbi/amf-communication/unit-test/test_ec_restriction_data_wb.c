#ifndef ec_restriction_data_wb_TEST
#define ec_restriction_data_wb_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ec_restriction_data_wb_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ec_restriction_data_wb.h"
ec_restriction_data_wb_t *instantiate_ec_restriction_data_wb(
	int include_optional);



ec_restriction_data_wb_t *instantiate_ec_restriction_data_wb(
	int include_optional) {
	ec_restriction_data_wb_t *ec_restriction_data_wb = NULL;
	if(include_optional) {
		ec_restriction_data_wb = ec_restriction_data_wb_create(
			1,
			1
			);
	} else {
		ec_restriction_data_wb = ec_restriction_data_wb_create(
			1,
			1
			);
	}

	return ec_restriction_data_wb;
}


#ifdef ec_restriction_data_wb_MAIN

void test_ec_restriction_data_wb(int include_optional) {
	ec_restriction_data_wb_t *ec_restriction_data_wb_1 =
		instantiate_ec_restriction_data_wb(include_optional);

	cJSON *jsonec_restriction_data_wb_1 =
		ec_restriction_data_wb_convertToJSON(ec_restriction_data_wb_1);
	printf("ec_restriction_data_wb :\n%s\n",
	       cJSON_Print(jsonec_restriction_data_wb_1));
	ec_restriction_data_wb_t *ec_restriction_data_wb_2 =
		ec_restriction_data_wb_parseFromJSON(
			jsonec_restriction_data_wb_1);
	cJSON *jsonec_restriction_data_wb_2 =
		ec_restriction_data_wb_convertToJSON(ec_restriction_data_wb_2);
	printf("repeating ec_restriction_data_wb:\n%s\n",
	       cJSON_Print(jsonec_restriction_data_wb_2));
}

int main() {
	test_ec_restriction_data_wb(1);
	test_ec_restriction_data_wb(0);

	printf("Hello world \n");
	return 0;
}

#endif // ec_restriction_data_wb_MAIN
#endif // ec_restriction_data_wb_TEST
