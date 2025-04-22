#ifndef minor_location_qo_s_TEST
#define minor_location_qo_s_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define minor_location_qo_s_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/minor_location_qo_s.h"
minor_location_qo_s_t *instantiate_minor_location_qo_s(int include_optional);



minor_location_qo_s_t *instantiate_minor_location_qo_s(int include_optional) {
	minor_location_qo_s_t *minor_location_qo_s = NULL;
	if(include_optional) {
		minor_location_qo_s = minor_location_qo_s_create(
			0,
			0
			);
	} else {
		minor_location_qo_s = minor_location_qo_s_create(
			0,
			0
			);
	}

	return minor_location_qo_s;
}


#ifdef minor_location_qo_s_MAIN

void test_minor_location_qo_s(int include_optional) {
	minor_location_qo_s_t *minor_location_qo_s_1 =
		instantiate_minor_location_qo_s(include_optional);

	cJSON *jsonminor_location_qo_s_1 = minor_location_qo_s_convertToJSON(
		minor_location_qo_s_1);
	printf("minor_location_qo_s :\n%s\n",
	       cJSON_Print(jsonminor_location_qo_s_1));
	minor_location_qo_s_t *minor_location_qo_s_2 =
		minor_location_qo_s_parseFromJSON(jsonminor_location_qo_s_1);
	cJSON *jsonminor_location_qo_s_2 = minor_location_qo_s_convertToJSON(
		minor_location_qo_s_2);
	printf("repeating minor_location_qo_s:\n%s\n",
	       cJSON_Print(jsonminor_location_qo_s_2));
}

int main() {
	test_minor_location_qo_s(1);
	test_minor_location_qo_s(0);

	printf("Hello world \n");
	return 0;
}

#endif // minor_location_qo_s_MAIN
#endif // minor_location_qo_s_TEST
