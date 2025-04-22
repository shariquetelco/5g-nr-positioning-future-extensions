#ifndef indoor_outdoor_ind_TEST
#define indoor_outdoor_ind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define indoor_outdoor_ind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/indoor_outdoor_ind.h"
indoor_outdoor_ind_t *instantiate_indoor_outdoor_ind(int include_optional);



indoor_outdoor_ind_t *instantiate_indoor_outdoor_ind(int include_optional) {
	indoor_outdoor_ind_t *indoor_outdoor_ind = NULL;
	if(include_optional) {
		indoor_outdoor_ind = indoor_outdoor_ind_create(
			);
	} else {
		indoor_outdoor_ind = indoor_outdoor_ind_create(
			);
	}

	return indoor_outdoor_ind;
}


#ifdef indoor_outdoor_ind_MAIN

void test_indoor_outdoor_ind(int include_optional) {
	indoor_outdoor_ind_t *indoor_outdoor_ind_1 =
		instantiate_indoor_outdoor_ind(include_optional);

	cJSON *jsonindoor_outdoor_ind_1 = indoor_outdoor_ind_convertToJSON(
		indoor_outdoor_ind_1);
	printf("indoor_outdoor_ind :\n%s\n",
	       cJSON_Print(jsonindoor_outdoor_ind_1));
	indoor_outdoor_ind_t *indoor_outdoor_ind_2 =
		indoor_outdoor_ind_parseFromJSON(jsonindoor_outdoor_ind_1);
	cJSON *jsonindoor_outdoor_ind_2 = indoor_outdoor_ind_convertToJSON(
		indoor_outdoor_ind_2);
	printf("repeating indoor_outdoor_ind:\n%s\n",
	       cJSON_Print(jsonindoor_outdoor_ind_2));
}

int main() {
	test_indoor_outdoor_ind(1);
	test_indoor_outdoor_ind(0);

	printf("Hello world \n");
	return 0;
}

#endif // indoor_outdoor_ind_MAIN
#endif // indoor_outdoor_ind_TEST
