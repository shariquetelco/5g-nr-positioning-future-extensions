#ifndef qos_resource_type_any_of_TEST
#define qos_resource_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define qos_resource_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/qos_resource_type_any_of.h"
qos_resource_type_any_of_t *instantiate_qos_resource_type_any_of(
	int include_optional);



qos_resource_type_any_of_t *instantiate_qos_resource_type_any_of(
	int include_optional) {
	qos_resource_type_any_of_t *qos_resource_type_any_of = NULL;
	if(include_optional) {
		qos_resource_type_any_of = qos_resource_type_any_of_create(
			);
	} else {
		qos_resource_type_any_of = qos_resource_type_any_of_create(
			);
	}

	return qos_resource_type_any_of;
}


#ifdef qos_resource_type_any_of_MAIN

void test_qos_resource_type_any_of(int include_optional) {
	qos_resource_type_any_of_t *qos_resource_type_any_of_1 =
		instantiate_qos_resource_type_any_of(include_optional);

	cJSON *jsonqos_resource_type_any_of_1 =
		qos_resource_type_any_of_convertToJSON(
			qos_resource_type_any_of_1);
	printf("qos_resource_type_any_of :\n%s\n",
	       cJSON_Print(jsonqos_resource_type_any_of_1));
	qos_resource_type_any_of_t *qos_resource_type_any_of_2 =
		qos_resource_type_any_of_parseFromJSON(
			jsonqos_resource_type_any_of_1);
	cJSON *jsonqos_resource_type_any_of_2 =
		qos_resource_type_any_of_convertToJSON(
			qos_resource_type_any_of_2);
	printf("repeating qos_resource_type_any_of:\n%s\n",
	       cJSON_Print(jsonqos_resource_type_any_of_2));
}

int main() {
	test_qos_resource_type_any_of(1);
	test_qos_resource_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // qos_resource_type_any_of_MAIN
#endif // qos_resource_type_any_of_TEST
