#ifndef prose_context_TEST
#define prose_context_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define prose_context_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/prose_context.h"
prose_context_t *instantiate_prose_context(int include_optional);

#include "test_ue_auth.c"
#include "test_ue_auth.c"
#include "test_ue_auth.c"
#include "test_ue_auth.c"
#include "test_ue_auth.c"
#include "test_ue_auth.c"
#include "test_ue_auth.c"
#include "test_ue_auth.c"
#include "test_ue_auth.c"
#include "test_ue_auth.c"
#include "test_ue_auth.c"
#include "test_pc5_qo_s_para.c"


prose_context_t *instantiate_prose_context(int include_optional) {
	prose_context_t *prose_context = NULL;
	if(include_optional) {
		prose_context = prose_context_create(
			null,
			null,
			null,
			null,
			null,
			null,
			null,
			null,
			null,
			null,
			null,
			"a",
			// false, not to have infinite recursion
			instantiate_pc5_qo_s_para(0)
			);
	} else {
		prose_context = prose_context_create(
			null,
			null,
			null,
			null,
			null,
			null,
			null,
			null,
			null,
			null,
			null,
			"a",
			NULL
			);
	}

	return prose_context;
}


#ifdef prose_context_MAIN

void test_prose_context(int include_optional) {
	prose_context_t *prose_context_1 = instantiate_prose_context(
		include_optional);

	cJSON *jsonprose_context_1 =
		prose_context_convertToJSON(prose_context_1);
	printf("prose_context :\n%s\n", cJSON_Print(jsonprose_context_1));
	prose_context_t *prose_context_2 = prose_context_parseFromJSON(
		jsonprose_context_1);
	cJSON *jsonprose_context_2 =
		prose_context_convertToJSON(prose_context_2);
	printf("repeating prose_context:\n%s\n", cJSON_Print(
		       jsonprose_context_2));
}

int main() {
	test_prose_context(1);
	test_prose_context(0);

	printf("Hello world \n");
	return 0;
}

#endif // prose_context_MAIN
#endif // prose_context_TEST
