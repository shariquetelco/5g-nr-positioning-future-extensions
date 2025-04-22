#ifndef number_average_TEST
#define number_average_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define number_average_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/number_average.h"
number_average_t *instantiate_number_average(int include_optional);



number_average_t *instantiate_number_average(int include_optional) {
	number_average_t *number_average = NULL;
	if(include_optional) {
		number_average = number_average_create(
			1.337,
			1.337,
			1.337
			);
	} else {
		number_average = number_average_create(
			1.337,
			1.337,
			1.337
			);
	}

	return number_average;
}


#ifdef number_average_MAIN

void test_number_average(int include_optional) {
	number_average_t *number_average_1 = instantiate_number_average(
		include_optional);

	cJSON *jsonnumber_average_1 = number_average_convertToJSON(
		number_average_1);
	printf("number_average :\n%s\n", cJSON_Print(jsonnumber_average_1));
	number_average_t *number_average_2 = number_average_parseFromJSON(
		jsonnumber_average_1);
	cJSON *jsonnumber_average_2 = number_average_convertToJSON(
		number_average_2);
	printf("repeating number_average:\n%s\n",
	       cJSON_Print(jsonnumber_average_2));
}

int main() {
	test_number_average(1);
	test_number_average(0);

	printf("Hello world \n");
	return 0;
}

#endif // number_average_MAIN
#endif // number_average_TEST
