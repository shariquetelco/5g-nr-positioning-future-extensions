#ifndef restriction_type_any_of_TEST
#define restriction_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define restriction_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/restriction_type_any_of.h"
restriction_type_any_of_t *instantiate_restriction_type_any_of(
	int include_optional);



restriction_type_any_of_t *instantiate_restriction_type_any_of(
	int include_optional) {
	restriction_type_any_of_t *restriction_type_any_of = NULL;
	if(include_optional) {
		restriction_type_any_of = restriction_type_any_of_create(
			);
	} else {
		restriction_type_any_of = restriction_type_any_of_create(
			);
	}

	return restriction_type_any_of;
}


#ifdef restriction_type_any_of_MAIN

void test_restriction_type_any_of(int include_optional) {
	restriction_type_any_of_t *restriction_type_any_of_1 =
		instantiate_restriction_type_any_of(include_optional);

	cJSON *jsonrestriction_type_any_of_1 =
		restriction_type_any_of_convertToJSON(restriction_type_any_of_1);
	printf("restriction_type_any_of :\n%s\n",
	       cJSON_Print(jsonrestriction_type_any_of_1));
	restriction_type_any_of_t *restriction_type_any_of_2 =
		restriction_type_any_of_parseFromJSON(
			jsonrestriction_type_any_of_1);
	cJSON *jsonrestriction_type_any_of_2 =
		restriction_type_any_of_convertToJSON(restriction_type_any_of_2);
	printf("repeating restriction_type_any_of:\n%s\n",
	       cJSON_Print(jsonrestriction_type_any_of_2));
}

int main() {
	test_restriction_type_any_of(1);
	test_restriction_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // restriction_type_any_of_MAIN
#endif // restriction_type_any_of_TEST
