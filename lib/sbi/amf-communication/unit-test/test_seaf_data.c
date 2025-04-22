#ifndef seaf_data_TEST
#define seaf_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define seaf_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/seaf_data.h"
seaf_data_t *instantiate_seaf_data(int include_optional);

#include "test_ng_ksi.c"
#include "test_key_amf.c"


seaf_data_t *instantiate_seaf_data(int include_optional) {
	seaf_data_t *seaf_data = NULL;
	if(include_optional) {
		seaf_data = seaf_data_create(
			// false, not to have infinite recursion
			instantiate_ng_ksi(0),
			// false, not to have infinite recursion
			instantiate_key_amf(0),
			"a",
			0,
			1,
			1
			);
	} else {
		seaf_data = seaf_data_create(
			NULL,
			NULL,
			"a",
			0,
			1,
			1
			);
	}

	return seaf_data;
}


#ifdef seaf_data_MAIN

void test_seaf_data(int include_optional) {
	seaf_data_t *seaf_data_1 = instantiate_seaf_data(include_optional);

	cJSON *jsonseaf_data_1 = seaf_data_convertToJSON(seaf_data_1);
	printf("seaf_data :\n%s\n", cJSON_Print(jsonseaf_data_1));
	seaf_data_t *seaf_data_2 = seaf_data_parseFromJSON(jsonseaf_data_1);
	cJSON *jsonseaf_data_2 = seaf_data_convertToJSON(seaf_data_2);
	printf("repeating seaf_data:\n%s\n", cJSON_Print(jsonseaf_data_2));
}

int main() {
	test_seaf_data(1);
	test_seaf_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // seaf_data_MAIN
#endif // seaf_data_TEST
