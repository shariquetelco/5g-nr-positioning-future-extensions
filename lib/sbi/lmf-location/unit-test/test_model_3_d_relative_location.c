#ifndef model_3_d_relative_location_TEST
#define model_3_d_relative_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_3_d_relative_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_3_d_relative_location.h"
model_3_d_relative_location_t *instantiate_model_3_d_relative_location(
	int include_optional);



model_3_d_relative_location_t *instantiate_model_3_d_relative_location(
	int include_optional) {
	model_3_d_relative_location_t *model_3_d_relative_location = NULL;
	if(include_optional) {
		model_3_d_relative_location =
			model_3_d_relative_location_create(
				0,
				0,
				0,
				0
				);
	} else {
		model_3_d_relative_location =
			model_3_d_relative_location_create(
				0,
				0,
				0,
				0
				);
	}

	return model_3_d_relative_location;
}


#ifdef model_3_d_relative_location_MAIN

void test_model_3_d_relative_location(int include_optional) {
	model_3_d_relative_location_t *model_3_d_relative_location_1 =
		instantiate_model_3_d_relative_location(include_optional);

	cJSON *jsonmodel_3_d_relative_location_1 =
		model_3_d_relative_location_convertToJSON(
			model_3_d_relative_location_1);
	printf("model_3_d_relative_location :\n%s\n",
	       cJSON_Print(jsonmodel_3_d_relative_location_1));
	model_3_d_relative_location_t *model_3_d_relative_location_2 =
		model_3_d_relative_location_parseFromJSON(
			jsonmodel_3_d_relative_location_1);
	cJSON *jsonmodel_3_d_relative_location_2 =
		model_3_d_relative_location_convertToJSON(
			model_3_d_relative_location_2);
	printf("repeating model_3_d_relative_location:\n%s\n",
	       cJSON_Print(jsonmodel_3_d_relative_location_2));
}

int main() {
	test_model_3_d_relative_location(1);
	test_model_3_d_relative_location(0);

	printf("Hello world \n");
	return 0;
}

#endif // model_3_d_relative_location_MAIN
#endif // model_3_d_relative_location_TEST
