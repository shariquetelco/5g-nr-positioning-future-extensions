#ifndef up_loc_rep_addr_af_rm_TEST
#define up_loc_rep_addr_af_rm_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define up_loc_rep_addr_af_rm_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/up_loc_rep_addr_af_rm.h"
up_loc_rep_addr_af_rm_t *instantiate_up_loc_rep_addr_af_rm(
	int include_optional);



up_loc_rep_addr_af_rm_t *instantiate_up_loc_rep_addr_af_rm(int include_optional)
{
	up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm = NULL;
	if(include_optional) {
		up_loc_rep_addr_af_rm = up_loc_rep_addr_af_rm_create(
			list_createList(),
			list_createList(),
			"a"
			);
	} else {
		up_loc_rep_addr_af_rm = up_loc_rep_addr_af_rm_create(
			list_createList(),
			list_createList(),
			"a"
			);
	}

	return up_loc_rep_addr_af_rm;
}


#ifdef up_loc_rep_addr_af_rm_MAIN

void test_up_loc_rep_addr_af_rm(int include_optional) {
	up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm_1 =
		instantiate_up_loc_rep_addr_af_rm(include_optional);

	cJSON *jsonup_loc_rep_addr_af_rm_1 =
		up_loc_rep_addr_af_rm_convertToJSON(up_loc_rep_addr_af_rm_1);
	printf("up_loc_rep_addr_af_rm :\n%s\n",
	       cJSON_Print(jsonup_loc_rep_addr_af_rm_1));
	up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm_2 =
		up_loc_rep_addr_af_rm_parseFromJSON(jsonup_loc_rep_addr_af_rm_1);
	cJSON *jsonup_loc_rep_addr_af_rm_2 =
		up_loc_rep_addr_af_rm_convertToJSON(up_loc_rep_addr_af_rm_2);
	printf("repeating up_loc_rep_addr_af_rm:\n%s\n",
	       cJSON_Print(jsonup_loc_rep_addr_af_rm_2));
}

int main() {
	test_up_loc_rep_addr_af_rm(1);
	test_up_loc_rep_addr_af_rm(0);

	printf("Hello world \n");
	return 0;
}

#endif // up_loc_rep_addr_af_rm_MAIN
#endif // up_loc_rep_addr_af_rm_TEST
