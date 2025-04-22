#ifndef qos_sustainability_info_TEST
#define qos_sustainability_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define qos_sustainability_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/qos_sustainability_info.h"
qos_sustainability_info_t *instantiate_qos_sustainability_info(
	int include_optional);

#include "test_network_area_info.c"
#include "test_retainability_threshold.c"
#include "test_snssai.c"


qos_sustainability_info_t *instantiate_qos_sustainability_info(
	int include_optional) {
	qos_sustainability_info_t *qos_sustainability_info = NULL;
	if(include_optional) {
		qos_sustainability_info = qos_sustainability_info_create(
			// false, not to have infinite recursion
			instantiate_network_area_info(0),
			"2013-10-20T19:20:30+01:00",
			"2013-10-20T19:20:30+01:00",
			// false, not to have infinite recursion
			instantiate_retainability_threshold(0),
			"a",
			// false, not to have infinite recursion
			instantiate_snssai(0),
			0
			);
	} else {
		qos_sustainability_info = qos_sustainability_info_create(
			NULL,
			"2013-10-20T19:20:30+01:00",
			"2013-10-20T19:20:30+01:00",
			NULL,
			"a",
			NULL,
			0
			);
	}

	return qos_sustainability_info;
}


#ifdef qos_sustainability_info_MAIN

void test_qos_sustainability_info(int include_optional) {
	qos_sustainability_info_t *qos_sustainability_info_1 =
		instantiate_qos_sustainability_info(include_optional);

	cJSON *jsonqos_sustainability_info_1 =
		qos_sustainability_info_convertToJSON(qos_sustainability_info_1);
	printf("qos_sustainability_info :\n%s\n",
	       cJSON_Print(jsonqos_sustainability_info_1));
	qos_sustainability_info_t *qos_sustainability_info_2 =
		qos_sustainability_info_parseFromJSON(
			jsonqos_sustainability_info_1);
	cJSON *jsonqos_sustainability_info_2 =
		qos_sustainability_info_convertToJSON(qos_sustainability_info_2);
	printf("repeating qos_sustainability_info:\n%s\n",
	       cJSON_Print(jsonqos_sustainability_info_2));
}

int main() {
	test_qos_sustainability_info(1);
	test_qos_sustainability_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // qos_sustainability_info_MAIN
#endif // qos_sustainability_info_TEST
