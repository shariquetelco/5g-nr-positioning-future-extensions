#ifndef qos_resource_type_TEST
#define qos_resource_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define qos_resource_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/qos_resource_type.h"
qos_resource_type_t *instantiate_qos_resource_type(int include_optional);



qos_resource_type_t *instantiate_qos_resource_type(int include_optional) {
	qos_resource_type_t *qos_resource_type = NULL;
	if(include_optional) {
		qos_resource_type = qos_resource_type_create(
			);
	} else {
		qos_resource_type = qos_resource_type_create(
			);
	}

	return qos_resource_type;
}


#ifdef qos_resource_type_MAIN

void test_qos_resource_type(int include_optional) {
	qos_resource_type_t *qos_resource_type_1 =
		instantiate_qos_resource_type(include_optional);

	cJSON *jsonqos_resource_type_1 = qos_resource_type_convertToJSON(
		qos_resource_type_1);
	printf("qos_resource_type :\n%s\n",
	       cJSON_Print(jsonqos_resource_type_1));
	qos_resource_type_t *qos_resource_type_2 =
		qos_resource_type_parseFromJSON(jsonqos_resource_type_1);
	cJSON *jsonqos_resource_type_2 = qos_resource_type_convertToJSON(
		qos_resource_type_2);
	printf("repeating qos_resource_type:\n%s\n",
	       cJSON_Print(jsonqos_resource_type_2));
}

int main() {
	test_qos_resource_type(1);
	test_qos_resource_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // qos_resource_type_MAIN
#endif // qos_resource_type_TEST
