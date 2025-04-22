#ifndef ue_analytics_context_descriptor_TEST
#define ue_analytics_context_descriptor_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_analytics_context_descriptor_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_analytics_context_descriptor.h"
ue_analytics_context_descriptor_t *instantiate_ue_analytics_context_descriptor(
	int include_optional);



ue_analytics_context_descriptor_t *instantiate_ue_analytics_context_descriptor(
	int include_optional) {
	ue_analytics_context_descriptor_t *ue_analytics_context_descriptor =
		NULL;
	if(include_optional) {
		ue_analytics_context_descriptor =
			ue_analytics_context_descriptor_create(
				"a",
				list_createList()
				);
	} else {
		ue_analytics_context_descriptor =
			ue_analytics_context_descriptor_create(
				"a",
				list_createList()
				);
	}

	return ue_analytics_context_descriptor;
}


#ifdef ue_analytics_context_descriptor_MAIN

void test_ue_analytics_context_descriptor(int include_optional) {
	ue_analytics_context_descriptor_t *ue_analytics_context_descriptor_1 =
		instantiate_ue_analytics_context_descriptor(include_optional);

	cJSON *jsonue_analytics_context_descriptor_1 =
		ue_analytics_context_descriptor_convertToJSON(
			ue_analytics_context_descriptor_1);
	printf("ue_analytics_context_descriptor :\n%s\n",
	       cJSON_Print(jsonue_analytics_context_descriptor_1));
	ue_analytics_context_descriptor_t *ue_analytics_context_descriptor_2 =
		ue_analytics_context_descriptor_parseFromJSON(
			jsonue_analytics_context_descriptor_1);
	cJSON *jsonue_analytics_context_descriptor_2 =
		ue_analytics_context_descriptor_convertToJSON(
			ue_analytics_context_descriptor_2);
	printf("repeating ue_analytics_context_descriptor:\n%s\n",
	       cJSON_Print(jsonue_analytics_context_descriptor_2));
}

int main() {
	test_ue_analytics_context_descriptor(1);
	test_ue_analytics_context_descriptor(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_analytics_context_descriptor_MAIN
#endif // ue_analytics_context_descriptor_TEST
