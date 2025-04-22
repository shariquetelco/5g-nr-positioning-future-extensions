#ifndef cn_assisted_ran_para_TEST
#define cn_assisted_ran_para_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cn_assisted_ran_para_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cn_assisted_ran_para.h"
cn_assisted_ran_para_t *instantiate_cn_assisted_ran_para(int include_optional);

#include "test_stationary_indication.c"
#include "test_scheduled_communication_time.c"
#include "test_scheduled_communication_type.c"
#include "test_traffic_profile.c"
#include "test_battery_indication.c"


cn_assisted_ran_para_t *instantiate_cn_assisted_ran_para(int include_optional) {
	cn_assisted_ran_para_t *cn_assisted_ran_para = NULL;
	if(include_optional) {
		cn_assisted_ran_para = cn_assisted_ran_para_create(
			null,
			56,
			56,
			// false, not to have infinite recursion
			instantiate_scheduled_communication_time(0),
			null,
			null,
			// false, not to have infinite recursion
			instantiate_battery_indication(0)
			);
	} else {
		cn_assisted_ran_para = cn_assisted_ran_para_create(
			null,
			56,
			56,
			NULL,
			null,
			null,
			NULL
			);
	}

	return cn_assisted_ran_para;
}


#ifdef cn_assisted_ran_para_MAIN

void test_cn_assisted_ran_para(int include_optional) {
	cn_assisted_ran_para_t *cn_assisted_ran_para_1 =
		instantiate_cn_assisted_ran_para(include_optional);

	cJSON *jsoncn_assisted_ran_para_1 = cn_assisted_ran_para_convertToJSON(
		cn_assisted_ran_para_1);
	printf("cn_assisted_ran_para :\n%s\n",
	       cJSON_Print(jsoncn_assisted_ran_para_1));
	cn_assisted_ran_para_t *cn_assisted_ran_para_2 =
		cn_assisted_ran_para_parseFromJSON(jsoncn_assisted_ran_para_1);
	cJSON *jsoncn_assisted_ran_para_2 = cn_assisted_ran_para_convertToJSON(
		cn_assisted_ran_para_2);
	printf("repeating cn_assisted_ran_para:\n%s\n",
	       cJSON_Print(jsoncn_assisted_ran_para_2));
}

int main() {
	test_cn_assisted_ran_para(1);
	test_cn_assisted_ran_para(0);

	printf("Hello world \n");
	return 0;
}

#endif // cn_assisted_ran_para_MAIN
#endif // cn_assisted_ran_para_TEST
