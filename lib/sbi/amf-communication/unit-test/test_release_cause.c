#ifndef release_cause_TEST
#define release_cause_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define release_cause_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/release_cause.h"
release_cause_t *instantiate_release_cause(int include_optional);



release_cause_t *instantiate_release_cause(int include_optional) {
	release_cause_t *release_cause = NULL;
	if(include_optional) {
		release_cause = release_cause_create(
			);
	} else {
		release_cause = release_cause_create(
			);
	}

	return release_cause;
}


#ifdef release_cause_MAIN

void test_release_cause(int include_optional) {
	release_cause_t *release_cause_1 = instantiate_release_cause(
		include_optional);

	cJSON *jsonrelease_cause_1 =
		release_cause_convertToJSON(release_cause_1);
	printf("release_cause :\n%s\n", cJSON_Print(jsonrelease_cause_1));
	release_cause_t *release_cause_2 = release_cause_parseFromJSON(
		jsonrelease_cause_1);
	cJSON *jsonrelease_cause_2 =
		release_cause_convertToJSON(release_cause_2);
	printf("repeating release_cause:\n%s\n", cJSON_Print(
		       jsonrelease_cause_2));
}

int main() {
	test_release_cause(1);
	test_release_cause(0);

	printf("Hello world \n");
	return 0;
}

#endif // release_cause_MAIN
#endif // release_cause_TEST
