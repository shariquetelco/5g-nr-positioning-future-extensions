#ifndef nas_security_mode_TEST
#define nas_security_mode_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nas_security_mode_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nas_security_mode.h"
nas_security_mode_t *instantiate_nas_security_mode(int include_optional);



nas_security_mode_t *instantiate_nas_security_mode(int include_optional) {
	nas_security_mode_t *nas_security_mode = NULL;
	if(include_optional) {
		nas_security_mode = nas_security_mode_create(
			namf_communication_nas_security_mode__NIA0,
			namf_communication_nas_security_mode__NEA0
			);
	} else {
		nas_security_mode = nas_security_mode_create(
			namf_communication_nas_security_mode__NIA0,
			namf_communication_nas_security_mode__NEA0
			);
	}

	return nas_security_mode;
}


#ifdef nas_security_mode_MAIN

void test_nas_security_mode(int include_optional) {
	nas_security_mode_t *nas_security_mode_1 =
		instantiate_nas_security_mode(include_optional);

	cJSON *jsonnas_security_mode_1 = nas_security_mode_convertToJSON(
		nas_security_mode_1);
	printf("nas_security_mode :\n%s\n",
	       cJSON_Print(jsonnas_security_mode_1));
	nas_security_mode_t *nas_security_mode_2 =
		nas_security_mode_parseFromJSON(jsonnas_security_mode_1);
	cJSON *jsonnas_security_mode_2 = nas_security_mode_convertToJSON(
		nas_security_mode_2);
	printf("repeating nas_security_mode:\n%s\n",
	       cJSON_Print(jsonnas_security_mode_2));
}

int main() {
	test_nas_security_mode(1);
	test_nas_security_mode(0);

	printf("Hello world \n");
	return 0;
}

#endif // nas_security_mode_MAIN
#endif // nas_security_mode_TEST
