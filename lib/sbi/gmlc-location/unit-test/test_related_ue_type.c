#ifndef related_ue_type_TEST
#define related_ue_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define related_ue_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/related_ue_type.h"
related_ue_type_t *instantiate_related_ue_type(int include_optional);



related_ue_type_t *instantiate_related_ue_type(int include_optional) {
	related_ue_type_t *related_ue_type = NULL;
	if(include_optional) {
		related_ue_type = related_ue_type_create(
			);
	} else {
		related_ue_type = related_ue_type_create(
			);
	}

	return related_ue_type;
}


#ifdef related_ue_type_MAIN

void test_related_ue_type(int include_optional) {
	related_ue_type_t *related_ue_type_1 = instantiate_related_ue_type(
		include_optional);

	cJSON *jsonrelated_ue_type_1 = related_ue_type_convertToJSON(
		related_ue_type_1);
	printf("related_ue_type :\n%s\n", cJSON_Print(jsonrelated_ue_type_1));
	related_ue_type_t *related_ue_type_2 = related_ue_type_parseFromJSON(
		jsonrelated_ue_type_1);
	cJSON *jsonrelated_ue_type_2 = related_ue_type_convertToJSON(
		related_ue_type_2);
	printf("repeating related_ue_type:\n%s\n",
	       cJSON_Print(jsonrelated_ue_type_2));
}

int main() {
	test_related_ue_type(1);
	test_related_ue_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // related_ue_type_MAIN
#endif // related_ue_type_TEST
