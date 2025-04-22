#ifndef dataset_statistical_property_any_of_TEST
#define dataset_statistical_property_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dataset_statistical_property_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dataset_statistical_property_any_of.h"
dataset_statistical_property_any_of_t *
instantiate_dataset_statistical_property_any_of(int include_optional);



dataset_statistical_property_any_of_t *
instantiate_dataset_statistical_property_any_of(int include_optional) {
	dataset_statistical_property_any_of_t *
	        dataset_statistical_property_any_of = NULL;
	if(include_optional) {
		dataset_statistical_property_any_of =
			dataset_statistical_property_any_of_create(
				);
	} else {
		dataset_statistical_property_any_of =
			dataset_statistical_property_any_of_create(
				);
	}

	return dataset_statistical_property_any_of;
}


#ifdef dataset_statistical_property_any_of_MAIN

void test_dataset_statistical_property_any_of(int include_optional) {
	dataset_statistical_property_any_of_t *
	        dataset_statistical_property_any_of_1 =
		instantiate_dataset_statistical_property_any_of(include_optional);

	cJSON *jsondataset_statistical_property_any_of_1 =
		dataset_statistical_property_any_of_convertToJSON(
			dataset_statistical_property_any_of_1);
	printf("dataset_statistical_property_any_of :\n%s\n",
	       cJSON_Print(jsondataset_statistical_property_any_of_1));
	dataset_statistical_property_any_of_t *
	        dataset_statistical_property_any_of_2 =
		dataset_statistical_property_any_of_parseFromJSON(
			jsondataset_statistical_property_any_of_1);
	cJSON *jsondataset_statistical_property_any_of_2 =
		dataset_statistical_property_any_of_convertToJSON(
			dataset_statistical_property_any_of_2);
	printf("repeating dataset_statistical_property_any_of:\n%s\n", cJSON_Print(
		       jsondataset_statistical_property_any_of_2));
}

int main() {
	test_dataset_statistical_property_any_of(1);
	test_dataset_statistical_property_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // dataset_statistical_property_any_of_MAIN
#endif // dataset_statistical_property_any_of_TEST
