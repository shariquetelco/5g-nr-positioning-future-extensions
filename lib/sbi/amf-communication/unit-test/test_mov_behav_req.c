#ifndef mov_behav_req_TEST
#define mov_behav_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mov_behav_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mov_behav_req.h"
mov_behav_req_t *instantiate_mov_behav_req(int include_optional);

#include "test_loc_info_granularity.c"
#include "test_threshold_level.c"


mov_behav_req_t *instantiate_mov_behav_req(int include_optional) {
	mov_behav_req_t *mov_behav_req = NULL;
	if(include_optional) {
		mov_behav_req = mov_behav_req_create(
			null,
			// false, not to have infinite recursion
			instantiate_threshold_level(0)
			);
	} else {
		mov_behav_req = mov_behav_req_create(
			null,
			NULL
			);
	}

	return mov_behav_req;
}


#ifdef mov_behav_req_MAIN

void test_mov_behav_req(int include_optional) {
	mov_behav_req_t *mov_behav_req_1 = instantiate_mov_behav_req(
		include_optional);

	cJSON *jsonmov_behav_req_1 =
		mov_behav_req_convertToJSON(mov_behav_req_1);
	printf("mov_behav_req :\n%s\n", cJSON_Print(jsonmov_behav_req_1));
	mov_behav_req_t *mov_behav_req_2 = mov_behav_req_parseFromJSON(
		jsonmov_behav_req_1);
	cJSON *jsonmov_behav_req_2 =
		mov_behav_req_convertToJSON(mov_behav_req_2);
	printf("repeating mov_behav_req:\n%s\n", cJSON_Print(
		       jsonmov_behav_req_2));
}

int main() {
	test_mov_behav_req(1);
	test_mov_behav_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // mov_behav_req_MAIN
#endif // mov_behav_req_TEST
