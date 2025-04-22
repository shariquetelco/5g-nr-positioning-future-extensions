#ifndef restriction_type_TEST
#define restriction_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define restriction_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/restriction_type.h"
restriction_type_t *instantiate_restriction_type(int include_optional);



restriction_type_t *instantiate_restriction_type(int include_optional) {
	restriction_type_t *restriction_type = NULL;
	if(include_optional) {
		restriction_type = restriction_type_create(
			);
	} else {
		restriction_type = restriction_type_create(
			);
	}

	return restriction_type;
}


#ifdef restriction_type_MAIN

void test_restriction_type(int include_optional) {
	restriction_type_t *restriction_type_1 = instantiate_restriction_type(
		include_optional);

	cJSON *jsonrestriction_type_1 = restriction_type_convertToJSON(
		restriction_type_1);
	printf("restriction_type :\n%s\n", cJSON_Print(jsonrestriction_type_1));
	restriction_type_t *restriction_type_2 = restriction_type_parseFromJSON(
		jsonrestriction_type_1);
	cJSON *jsonrestriction_type_2 = restriction_type_convertToJSON(
		restriction_type_2);
	printf("repeating restriction_type:\n%s\n",
	       cJSON_Print(jsonrestriction_type_2));
}

int main() {
	test_restriction_type(1);
	test_restriction_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // restriction_type_MAIN
#endif // restriction_type_TEST
