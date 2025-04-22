#ifndef dataset_statistical_property_TEST
#define dataset_statistical_property_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dataset_statistical_property_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dataset_statistical_property.h"
dataset_statistical_property_t *instantiate_dataset_statistical_property(
	int include_optional);



dataset_statistical_property_t *instantiate_dataset_statistical_property(
	int include_optional) {
	dataset_statistical_property_t *dataset_statistical_property = NULL;
	if(include_optional) {
		dataset_statistical_property =
			dataset_statistical_property_create(
				);
	} else {
		dataset_statistical_property =
			dataset_statistical_property_create(
				);
	}

	return dataset_statistical_property;
}


#ifdef dataset_statistical_property_MAIN

void test_dataset_statistical_property(int include_optional) {
	dataset_statistical_property_t *dataset_statistical_property_1 =
		instantiate_dataset_statistical_property(include_optional);

	cJSON *jsondataset_statistical_property_1 =
		dataset_statistical_property_convertToJSON(
			dataset_statistical_property_1);
	printf("dataset_statistical_property :\n%s\n",
	       cJSON_Print(jsondataset_statistical_property_1));
	dataset_statistical_property_t *dataset_statistical_property_2 =
		dataset_statistical_property_parseFromJSON(
			jsondataset_statistical_property_1);
	cJSON *jsondataset_statistical_property_2 =
		dataset_statistical_property_convertToJSON(
			dataset_statistical_property_2);
	printf("repeating dataset_statistical_property:\n%s\n",
	       cJSON_Print(jsondataset_statistical_property_2));
}

int main() {
	test_dataset_statistical_property(1);
	test_dataset_statistical_property(0);

	printf("Hello world \n");
	return 0;
}

#endif // dataset_statistical_property_MAIN
#endif // dataset_statistical_property_TEST
