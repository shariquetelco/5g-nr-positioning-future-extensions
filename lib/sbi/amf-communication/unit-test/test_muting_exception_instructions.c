#ifndef muting_exception_instructions_TEST
#define muting_exception_instructions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define muting_exception_instructions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/muting_exception_instructions.h"
muting_exception_instructions_t *instantiate_muting_exception_instructions(
	int include_optional);

#include "test_buffered_notifications_action.c"
#include "test_subscription_action.c"


muting_exception_instructions_t *instantiate_muting_exception_instructions(
	int include_optional) {
	muting_exception_instructions_t *muting_exception_instructions = NULL;
	if(include_optional) {
		muting_exception_instructions =
			muting_exception_instructions_create(
				null,
				null
				);
	} else {
		muting_exception_instructions =
			muting_exception_instructions_create(
				null,
				null
				);
	}

	return muting_exception_instructions;
}


#ifdef muting_exception_instructions_MAIN

void test_muting_exception_instructions(int include_optional) {
	muting_exception_instructions_t *muting_exception_instructions_1 =
		instantiate_muting_exception_instructions(include_optional);

	cJSON *jsonmuting_exception_instructions_1 =
		muting_exception_instructions_convertToJSON(
			muting_exception_instructions_1);
	printf("muting_exception_instructions :\n%s\n",
	       cJSON_Print(jsonmuting_exception_instructions_1));
	muting_exception_instructions_t *muting_exception_instructions_2 =
		muting_exception_instructions_parseFromJSON(
			jsonmuting_exception_instructions_1);
	cJSON *jsonmuting_exception_instructions_2 =
		muting_exception_instructions_convertToJSON(
			muting_exception_instructions_2);
	printf("repeating muting_exception_instructions:\n%s\n",
	       cJSON_Print(jsonmuting_exception_instructions_2));
}

int main() {
	test_muting_exception_instructions(1);
	test_muting_exception_instructions(0);

	printf("Hello world \n");
	return 0;
}

#endif // muting_exception_instructions_MAIN
#endif // muting_exception_instructions_TEST
