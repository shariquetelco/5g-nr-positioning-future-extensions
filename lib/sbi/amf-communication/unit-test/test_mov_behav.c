#ifndef mov_behav_TEST
#define mov_behav_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mov_behav_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mov_behav.h"
mov_behav_t *instantiate_mov_behav(int include_optional);



mov_behav_t *instantiate_mov_behav(int include_optional) {
	mov_behav_t *mov_behav = NULL;
	if(include_optional) {
		mov_behav = mov_behav_create(
			"2013-10-20T19:20:30+01:00",
			56,
			0,
			1,
			1.337,
			list_createList(),
			list_createList()
			);
	} else {
		mov_behav = mov_behav_create(
			"2013-10-20T19:20:30+01:00",
			56,
			0,
			1,
			1.337,
			list_createList(),
			list_createList()
			);
	}

	return mov_behav;
}


#ifdef mov_behav_MAIN

void test_mov_behav(int include_optional) {
	mov_behav_t *mov_behav_1 = instantiate_mov_behav(include_optional);

	cJSON *jsonmov_behav_1 = mov_behav_convertToJSON(mov_behav_1);
	printf("mov_behav :\n%s\n", cJSON_Print(jsonmov_behav_1));
	mov_behav_t *mov_behav_2 = mov_behav_parseFromJSON(jsonmov_behav_1);
	cJSON *jsonmov_behav_2 = mov_behav_convertToJSON(mov_behav_2);
	printf("repeating mov_behav:\n%s\n", cJSON_Print(jsonmov_behav_2));
}

int main() {
	test_mov_behav(1);
	test_mov_behav(0);

	printf("Hello world \n");
	return 0;
}

#endif // mov_behav_MAIN
#endif // mov_behav_TEST
