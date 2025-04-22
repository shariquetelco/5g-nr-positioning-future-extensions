#ifndef ext_snssai_TEST
#define ext_snssai_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ext_snssai_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ext_snssai.h"
ext_snssai_t *instantiate_ext_snssai(int include_optional);



ext_snssai_t *instantiate_ext_snssai(int include_optional) {
	ext_snssai_t *ext_snssai = NULL;
	if(include_optional) {
		ext_snssai = ext_snssai_create(
			0,
			"a",
			list_createList(),
			namf_communication_ext_snssai_WILDCARDSD_true
			);
	} else {
		ext_snssai = ext_snssai_create(
			0,
			"a",
			list_createList(),
			namf_communication_ext_snssai_WILDCARDSD_true
			);
	}

	return ext_snssai;
}


#ifdef ext_snssai_MAIN

void test_ext_snssai(int include_optional) {
	ext_snssai_t *ext_snssai_1 = instantiate_ext_snssai(include_optional);

	cJSON *jsonext_snssai_1 = ext_snssai_convertToJSON(ext_snssai_1);
	printf("ext_snssai :\n%s\n", cJSON_Print(jsonext_snssai_1));
	ext_snssai_t *ext_snssai_2 = ext_snssai_parseFromJSON(jsonext_snssai_1);
	cJSON *jsonext_snssai_2 = ext_snssai_convertToJSON(ext_snssai_2);
	printf("repeating ext_snssai:\n%s\n", cJSON_Print(jsonext_snssai_2));
}

int main() {
	test_ext_snssai(1);
	test_ext_snssai(0);

	printf("Hello world \n");
	return 0;
}

#endif // ext_snssai_MAIN
#endif // ext_snssai_TEST
