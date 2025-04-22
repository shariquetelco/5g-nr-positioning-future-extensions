#ifndef eps_nas_security_mode_TEST
#define eps_nas_security_mode_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define eps_nas_security_mode_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/eps_nas_security_mode.h"
eps_nas_security_mode_t *instantiate_eps_nas_security_mode(
	int include_optional);



eps_nas_security_mode_t *instantiate_eps_nas_security_mode(int include_optional)
{
	eps_nas_security_mode_t *eps_nas_security_mode = NULL;
	if(include_optional) {
		eps_nas_security_mode = eps_nas_security_mode_create(
			namf_communication_eps_nas_security_mode__EIA0,
			namf_communication_eps_nas_security_mode__EEA0
			);
	} else {
		eps_nas_security_mode = eps_nas_security_mode_create(
			namf_communication_eps_nas_security_mode__EIA0,
			namf_communication_eps_nas_security_mode__EEA0
			);
	}

	return eps_nas_security_mode;
}


#ifdef eps_nas_security_mode_MAIN

void test_eps_nas_security_mode(int include_optional) {
	eps_nas_security_mode_t *eps_nas_security_mode_1 =
		instantiate_eps_nas_security_mode(include_optional);

	cJSON *jsoneps_nas_security_mode_1 =
		eps_nas_security_mode_convertToJSON(eps_nas_security_mode_1);
	printf("eps_nas_security_mode :\n%s\n",
	       cJSON_Print(jsoneps_nas_security_mode_1));
	eps_nas_security_mode_t *eps_nas_security_mode_2 =
		eps_nas_security_mode_parseFromJSON(jsoneps_nas_security_mode_1);
	cJSON *jsoneps_nas_security_mode_2 =
		eps_nas_security_mode_convertToJSON(eps_nas_security_mode_2);
	printf("repeating eps_nas_security_mode:\n%s\n",
	       cJSON_Print(jsoneps_nas_security_mode_2));
}

int main() {
	test_eps_nas_security_mode(1);
	test_eps_nas_security_mode(0);

	printf("Hello world \n");
	return 0;
}

#endif // eps_nas_security_mode_MAIN
#endif // eps_nas_security_mode_TEST
