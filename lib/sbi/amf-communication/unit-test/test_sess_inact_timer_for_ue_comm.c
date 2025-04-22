#ifndef sess_inact_timer_for_ue_comm_TEST
#define sess_inact_timer_for_ue_comm_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sess_inact_timer_for_ue_comm_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sess_inact_timer_for_ue_comm.h"
sess_inact_timer_for_ue_comm_t *instantiate_sess_inact_timer_for_ue_comm(
	int include_optional);



sess_inact_timer_for_ue_comm_t *instantiate_sess_inact_timer_for_ue_comm(
	int include_optional) {
	sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm = NULL;
	if(include_optional) {
		sess_inact_timer_for_ue_comm =
			sess_inact_timer_for_ue_comm_create(
				0,
				56
				);
	} else {
		sess_inact_timer_for_ue_comm =
			sess_inact_timer_for_ue_comm_create(
				0,
				56
				);
	}

	return sess_inact_timer_for_ue_comm;
}


#ifdef sess_inact_timer_for_ue_comm_MAIN

void test_sess_inact_timer_for_ue_comm(int include_optional) {
	sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm_1 =
		instantiate_sess_inact_timer_for_ue_comm(include_optional);

	cJSON *jsonsess_inact_timer_for_ue_comm_1 =
		sess_inact_timer_for_ue_comm_convertToJSON(
			sess_inact_timer_for_ue_comm_1);
	printf("sess_inact_timer_for_ue_comm :\n%s\n",
	       cJSON_Print(jsonsess_inact_timer_for_ue_comm_1));
	sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm_2 =
		sess_inact_timer_for_ue_comm_parseFromJSON(
			jsonsess_inact_timer_for_ue_comm_1);
	cJSON *jsonsess_inact_timer_for_ue_comm_2 =
		sess_inact_timer_for_ue_comm_convertToJSON(
			sess_inact_timer_for_ue_comm_2);
	printf("repeating sess_inact_timer_for_ue_comm:\n%s\n",
	       cJSON_Print(jsonsess_inact_timer_for_ue_comm_2));
}

int main() {
	test_sess_inact_timer_for_ue_comm(1);
	test_sess_inact_timer_for_ue_comm(0);

	printf("Hello world \n");
	return 0;
}

#endif // sess_inact_timer_for_ue_comm_MAIN
#endif // sess_inact_timer_for_ue_comm_TEST
