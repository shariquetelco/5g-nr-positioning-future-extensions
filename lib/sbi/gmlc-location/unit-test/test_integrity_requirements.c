#ifndef integrity_requirements_TEST
#define integrity_requirements_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define integrity_requirements_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/integrity_requirements.h"
integrity_requirements_t *instantiate_integrity_requirements(
	int include_optional);

#include "test_alert_limit.c"


integrity_requirements_t *instantiate_integrity_requirements(
	int include_optional) {
	integrity_requirements_t *integrity_requirements = NULL;
	if(include_optional) {
		integrity_requirements = integrity_requirements_create(
			1,
			10,
			// false, not to have infinite recursion
			instantiate_alert_limit(0)
			);
	} else {
		integrity_requirements = integrity_requirements_create(
			1,
			10,
			NULL
			);
	}

	return integrity_requirements;
}


#ifdef integrity_requirements_MAIN

void test_integrity_requirements(int include_optional) {
	integrity_requirements_t *integrity_requirements_1 =
		instantiate_integrity_requirements(include_optional);

	cJSON *jsonintegrity_requirements_1 =
		integrity_requirements_convertToJSON(integrity_requirements_1);
	printf("integrity_requirements :\n%s\n",
	       cJSON_Print(jsonintegrity_requirements_1));
	integrity_requirements_t *integrity_requirements_2 =
		integrity_requirements_parseFromJSON(
			jsonintegrity_requirements_1);
	cJSON *jsonintegrity_requirements_2 =
		integrity_requirements_convertToJSON(integrity_requirements_2);
	printf("repeating integrity_requirements:\n%s\n",
	       cJSON_Print(jsonintegrity_requirements_2));
}

int main() {
	test_integrity_requirements(1);
	test_integrity_requirements(0);

	printf("Hello world \n");
	return 0;
}

#endif // integrity_requirements_MAIN
#endif // integrity_requirements_TEST
