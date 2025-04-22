#ifndef class_criterion_TEST
#define class_criterion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define class_criterion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/class_criterion.h"
class_criterion_t *instantiate_class_criterion(int include_optional);

#include "test_dispersion_class.c"
#include "test_matching_direction.c"


class_criterion_t *instantiate_class_criterion(int include_optional) {
	class_criterion_t *class_criterion = NULL;
	if(include_optional) {
		class_criterion = class_criterion_create(
			null,
			1,
			null
			);
	} else {
		class_criterion = class_criterion_create(
			null,
			1,
			null
			);
	}

	return class_criterion;
}


#ifdef class_criterion_MAIN

void test_class_criterion(int include_optional) {
	class_criterion_t *class_criterion_1 = instantiate_class_criterion(
		include_optional);

	cJSON *jsonclass_criterion_1 = class_criterion_convertToJSON(
		class_criterion_1);
	printf("class_criterion :\n%s\n", cJSON_Print(jsonclass_criterion_1));
	class_criterion_t *class_criterion_2 = class_criterion_parseFromJSON(
		jsonclass_criterion_1);
	cJSON *jsonclass_criterion_2 = class_criterion_convertToJSON(
		class_criterion_2);
	printf("repeating class_criterion:\n%s\n",
	       cJSON_Print(jsonclass_criterion_2));
}

int main() {
	test_class_criterion(1);
	test_class_criterion(0);

	printf("Hello world \n");
	return 0;
}

#endif // class_criterion_MAIN
#endif // class_criterion_TEST
