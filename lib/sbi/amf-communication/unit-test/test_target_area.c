#ifndef target_area_TEST
#define target_area_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define target_area_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/target_area.h"
target_area_t *instantiate_target_area(int include_optional);



target_area_t *instantiate_target_area(int include_optional) {
	target_area_t *target_area = NULL;
	if(include_optional) {
		target_area = target_area_create(
			list_createList(),
			list_createList(),
			1
			);
	} else {
		target_area = target_area_create(
			list_createList(),
			list_createList(),
			1
			);
	}

	return target_area;
}


#ifdef target_area_MAIN

void test_target_area(int include_optional) {
	target_area_t *target_area_1 =
		instantiate_target_area(include_optional);

	cJSON *jsontarget_area_1 = target_area_convertToJSON(target_area_1);
	printf("target_area :\n%s\n", cJSON_Print(jsontarget_area_1));
	target_area_t *target_area_2 = target_area_parseFromJSON(
		jsontarget_area_1);
	cJSON *jsontarget_area_2 = target_area_convertToJSON(target_area_2);
	printf("repeating target_area:\n%s\n", cJSON_Print(jsontarget_area_2));
}

int main() {
	test_target_area(1);
	test_target_area(0);

	printf("Hello world \n");
	return 0;
}

#endif // target_area_MAIN
#endif // target_area_TEST
