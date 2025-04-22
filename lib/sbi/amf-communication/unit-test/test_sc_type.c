#ifndef sc_type_TEST
#define sc_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sc_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sc_type.h"
sc_type_t *instantiate_sc_type(int include_optional);



sc_type_t *instantiate_sc_type(int include_optional) {
	sc_type_t *sc_type = NULL;
	if(include_optional) {
		sc_type = sc_type_create(
			);
	} else {
		sc_type = sc_type_create(
			);
	}

	return sc_type;
}


#ifdef sc_type_MAIN

void test_sc_type(int include_optional) {
	sc_type_t *sc_type_1 = instantiate_sc_type(include_optional);

	cJSON *jsonsc_type_1 = sc_type_convertToJSON(sc_type_1);
	printf("sc_type :\n%s\n", cJSON_Print(jsonsc_type_1));
	sc_type_t *sc_type_2 = sc_type_parseFromJSON(jsonsc_type_1);
	cJSON *jsonsc_type_2 = sc_type_convertToJSON(sc_type_2);
	printf("repeating sc_type:\n%s\n", cJSON_Print(jsonsc_type_2));
}

int main() {
	test_sc_type(1);
	test_sc_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // sc_type_MAIN
#endif // sc_type_TEST
