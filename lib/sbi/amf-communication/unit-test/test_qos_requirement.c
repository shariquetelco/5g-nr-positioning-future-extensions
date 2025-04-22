#ifndef qos_requirement_TEST
#define qos_requirement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define qos_requirement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/qos_requirement.h"
qos_requirement_t *instantiate_qos_requirement(int include_optional);

#include "test_qos_resource_type.c"
#include "test_velocity_estimate.c"
#include "test_device_type.c"


qos_requirement_t *instantiate_qos_requirement(int include_optional) {
	qos_requirement_t *qos_requirement = NULL;
	if(include_optional) {
		qos_requirement = qos_requirement_create(
			0,
			"a",
			"a",
			null,
			1,
			"a",
			null,
			null
			);
	} else {
		qos_requirement = qos_requirement_create(
			0,
			"a",
			"a",
			null,
			1,
			"a",
			null,
			null
			);
	}

	return qos_requirement;
}


#ifdef qos_requirement_MAIN

void test_qos_requirement(int include_optional) {
	qos_requirement_t *qos_requirement_1 = instantiate_qos_requirement(
		include_optional);

	cJSON *jsonqos_requirement_1 = qos_requirement_convertToJSON(
		qos_requirement_1);
	printf("qos_requirement :\n%s\n", cJSON_Print(jsonqos_requirement_1));
	qos_requirement_t *qos_requirement_2 = qos_requirement_parseFromJSON(
		jsonqos_requirement_1);
	cJSON *jsonqos_requirement_2 = qos_requirement_convertToJSON(
		qos_requirement_2);
	printf("repeating qos_requirement:\n%s\n",
	       cJSON_Print(jsonqos_requirement_2));
}

int main() {
	test_qos_requirement(1);
	test_qos_requirement(0);

	printf("Hello world \n");
	return 0;
}

#endif // qos_requirement_MAIN
#endif // qos_requirement_TEST
