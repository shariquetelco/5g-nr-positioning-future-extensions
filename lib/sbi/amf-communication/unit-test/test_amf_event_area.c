#ifndef amf_event_area_TEST
#define amf_event_area_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define amf_event_area_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/amf_event_area.h"
amf_event_area_t *instantiate_amf_event_area(int include_optional);

#include "test_presence_info.c"
#include "test_ladn_info.c"
#include "test_snssai.c"


amf_event_area_t *instantiate_amf_event_area(int include_optional) {
	amf_event_area_t *amf_event_area = NULL;
	if(include_optional) {
		amf_event_area = amf_event_area_create(
			// false, not to have infinite recursion
			instantiate_presence_info(0),
			// false, not to have infinite recursion
			instantiate_ladn_info(0),
			// false, not to have infinite recursion
			instantiate_snssai(0),
			"0"
			);
	} else {
		amf_event_area = amf_event_area_create(
			NULL,
			NULL,
			NULL,
			"0"
			);
	}

	return amf_event_area;
}


#ifdef amf_event_area_MAIN

void test_amf_event_area(int include_optional) {
	amf_event_area_t *amf_event_area_1 = instantiate_amf_event_area(
		include_optional);

	cJSON *jsonamf_event_area_1 = amf_event_area_convertToJSON(
		amf_event_area_1);
	printf("amf_event_area :\n%s\n", cJSON_Print(jsonamf_event_area_1));
	amf_event_area_t *amf_event_area_2 = amf_event_area_parseFromJSON(
		jsonamf_event_area_1);
	cJSON *jsonamf_event_area_2 = amf_event_area_convertToJSON(
		amf_event_area_2);
	printf("repeating amf_event_area:\n%s\n",
	       cJSON_Print(jsonamf_event_area_2));
}

int main() {
	test_amf_event_area(1);
	test_amf_event_area(0);

	printf("Hello world \n");
	return 0;
}

#endif // amf_event_area_MAIN
#endif // amf_event_area_TEST
