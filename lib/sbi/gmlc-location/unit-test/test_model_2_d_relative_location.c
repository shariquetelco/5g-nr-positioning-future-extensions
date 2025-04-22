#ifndef model_2_d_relative_location_TEST
#define model_2_d_relative_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_2_d_relative_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_2_d_relative_location.h"
model_2_d_relative_location_t *instantiate_model_2_d_relative_location(
	int include_optional);



model_2_d_relative_location_t *instantiate_model_2_d_relative_location(
	int include_optional) {
	model_2_d_relative_location_t *model_2_d_relative_location = NULL;
	if(include_optional) {
		model_2_d_relative_location =
			model_2_d_relative_location_create(
				0,
				0,
				0
				);
	} else {
		model_2_d_relative_location =
			model_2_d_relative_location_create(
				0,
				0,
				0
				);
	}

	return model_2_d_relative_location;
}


#ifdef model_2_d_relative_location_MAIN

void test_model_2_d_relative_location(int include_optional) {
	model_2_d_relative_location_t *model_2_d_relative_location_1 =
		instantiate_model_2_d_relative_location(include_optional);

	cJSON *jsonmodel_2_d_relative_location_1 =
		model_2_d_relative_location_convertToJSON(
			model_2_d_relative_location_1);
	printf("model_2_d_relative_location :\n%s\n",
	       cJSON_Print(jsonmodel_2_d_relative_location_1));
	model_2_d_relative_location_t *model_2_d_relative_location_2 =
		model_2_d_relative_location_parseFromJSON(
			jsonmodel_2_d_relative_location_1);
	cJSON *jsonmodel_2_d_relative_location_2 =
		model_2_d_relative_location_convertToJSON(
			model_2_d_relative_location_2);
	printf("repeating model_2_d_relative_location:\n%s\n",
	       cJSON_Print(jsonmodel_2_d_relative_location_2));
}

int main() {
	test_model_2_d_relative_location(1);
	test_model_2_d_relative_location(0);

	printf("Hello world \n");
	return 0;
}

#endif // model_2_d_relative_location_MAIN
#endif // model_2_d_relative_location_TEST
