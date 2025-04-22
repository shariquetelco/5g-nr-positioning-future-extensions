#ifndef svc_experience_TEST
#define svc_experience_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define svc_experience_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/svc_experience.h"
svc_experience_t *instantiate_svc_experience(int include_optional);



svc_experience_t *instantiate_svc_experience(int include_optional) {
	svc_experience_t *svc_experience = NULL;
	if(include_optional) {
		svc_experience = svc_experience_create(
			1.337,
			1.337,
			1.337
			);
	} else {
		svc_experience = svc_experience_create(
			1.337,
			1.337,
			1.337
			);
	}

	return svc_experience;
}


#ifdef svc_experience_MAIN

void test_svc_experience(int include_optional) {
	svc_experience_t *svc_experience_1 = instantiate_svc_experience(
		include_optional);

	cJSON *jsonsvc_experience_1 = svc_experience_convertToJSON(
		svc_experience_1);
	printf("svc_experience :\n%s\n", cJSON_Print(jsonsvc_experience_1));
	svc_experience_t *svc_experience_2 = svc_experience_parseFromJSON(
		jsonsvc_experience_1);
	cJSON *jsonsvc_experience_2 = svc_experience_convertToJSON(
		svc_experience_2);
	printf("repeating svc_experience:\n%s\n",
	       cJSON_Print(jsonsvc_experience_2));
}

int main() {
	test_svc_experience(1);
	test_svc_experience(0);

	printf("Hello world \n");
	return 0;
}

#endif // svc_experience_MAIN
#endif // svc_experience_TEST
