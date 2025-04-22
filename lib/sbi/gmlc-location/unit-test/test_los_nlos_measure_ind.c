#ifndef los_nlos_measure_ind_TEST
#define los_nlos_measure_ind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define los_nlos_measure_ind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/los_nlos_measure_ind.h"
los_nlos_measure_ind_t *instantiate_los_nlos_measure_ind(int include_optional);



los_nlos_measure_ind_t *instantiate_los_nlos_measure_ind(int include_optional) {
	los_nlos_measure_ind_t *los_nlos_measure_ind = NULL;
	if(include_optional) {
		los_nlos_measure_ind = los_nlos_measure_ind_create(
			);
	} else {
		los_nlos_measure_ind = los_nlos_measure_ind_create(
			);
	}

	return los_nlos_measure_ind;
}


#ifdef los_nlos_measure_ind_MAIN

void test_los_nlos_measure_ind(int include_optional) {
	los_nlos_measure_ind_t *los_nlos_measure_ind_1 =
		instantiate_los_nlos_measure_ind(include_optional);

	cJSON *jsonlos_nlos_measure_ind_1 = los_nlos_measure_ind_convertToJSON(
		los_nlos_measure_ind_1);
	printf("los_nlos_measure_ind :\n%s\n",
	       cJSON_Print(jsonlos_nlos_measure_ind_1));
	los_nlos_measure_ind_t *los_nlos_measure_ind_2 =
		los_nlos_measure_ind_parseFromJSON(jsonlos_nlos_measure_ind_1);
	cJSON *jsonlos_nlos_measure_ind_2 = los_nlos_measure_ind_convertToJSON(
		los_nlos_measure_ind_2);
	printf("repeating los_nlos_measure_ind:\n%s\n",
	       cJSON_Print(jsonlos_nlos_measure_ind_2));
}

int main() {
	test_los_nlos_measure_ind(1);
	test_los_nlos_measure_ind(0);

	printf("Hello world \n");
	return 0;
}

#endif // los_nlos_measure_ind_MAIN
#endif // los_nlos_measure_ind_TEST
