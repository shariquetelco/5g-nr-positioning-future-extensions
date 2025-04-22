#ifndef amf_event_type_TEST
#define amf_event_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define amf_event_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/amf_event_type.h"
amf_event_type_t *instantiate_amf_event_type(int include_optional);



amf_event_type_t *instantiate_amf_event_type(int include_optional) {
	amf_event_type_t *amf_event_type = NULL;
	if(include_optional) {
		amf_event_type = amf_event_type_create(
			);
	} else {
		amf_event_type = amf_event_type_create(
			);
	}

	return amf_event_type;
}


#ifdef amf_event_type_MAIN

void test_amf_event_type(int include_optional) {
	amf_event_type_t *amf_event_type_1 = instantiate_amf_event_type(
		include_optional);

	cJSON *jsonamf_event_type_1 = amf_event_type_convertToJSON(
		amf_event_type_1);
	printf("amf_event_type :\n%s\n", cJSON_Print(jsonamf_event_type_1));
	amf_event_type_t *amf_event_type_2 = amf_event_type_parseFromJSON(
		jsonamf_event_type_1);
	cJSON *jsonamf_event_type_2 = amf_event_type_convertToJSON(
		amf_event_type_2);
	printf("repeating amf_event_type:\n%s\n",
	       cJSON_Print(jsonamf_event_type_2));
}

int main() {
	test_amf_event_type(1);
	test_amf_event_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // amf_event_type_MAIN
#endif // amf_event_type_TEST
