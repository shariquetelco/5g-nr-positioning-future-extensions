#ifndef app_list_for_ue_comm_TEST
#define app_list_for_ue_comm_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define app_list_for_ue_comm_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/app_list_for_ue_comm.h"
app_list_for_ue_comm_t *instantiate_app_list_for_ue_comm(int include_optional);

#include "test_network_area_info.c"


app_list_for_ue_comm_t *instantiate_app_list_for_ue_comm(int include_optional) {
	app_list_for_ue_comm_t *app_list_for_ue_comm = NULL;
	if(include_optional) {
		app_list_for_ue_comm = app_list_for_ue_comm_create(
			"0",
			"2013-10-20T19:20:30+01:00",
			56,
			1,
			// false, not to have infinite recursion
			instantiate_network_area_info(0)
			);
	} else {
		app_list_for_ue_comm = app_list_for_ue_comm_create(
			"0",
			"2013-10-20T19:20:30+01:00",
			56,
			1,
			NULL
			);
	}

	return app_list_for_ue_comm;
}


#ifdef app_list_for_ue_comm_MAIN

void test_app_list_for_ue_comm(int include_optional) {
	app_list_for_ue_comm_t *app_list_for_ue_comm_1 =
		instantiate_app_list_for_ue_comm(include_optional);

	cJSON *jsonapp_list_for_ue_comm_1 = app_list_for_ue_comm_convertToJSON(
		app_list_for_ue_comm_1);
	printf("app_list_for_ue_comm :\n%s\n",
	       cJSON_Print(jsonapp_list_for_ue_comm_1));
	app_list_for_ue_comm_t *app_list_for_ue_comm_2 =
		app_list_for_ue_comm_parseFromJSON(jsonapp_list_for_ue_comm_1);
	cJSON *jsonapp_list_for_ue_comm_2 = app_list_for_ue_comm_convertToJSON(
		app_list_for_ue_comm_2);
	printf("repeating app_list_for_ue_comm:\n%s\n",
	       cJSON_Print(jsonapp_list_for_ue_comm_2));
}

int main() {
	test_app_list_for_ue_comm(1);
	test_app_list_for_ue_comm(0);

	printf("Hello world \n");
	return 0;
}

#endif // app_list_for_ue_comm_MAIN
#endif // app_list_for_ue_comm_TEST
