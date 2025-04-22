#ifndef n2_info_container_TEST
#define n2_info_container_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_info_container_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_info_container.h"
n2_info_container_t *instantiate_n2_info_container(int include_optional);

#include "test_n2_sm_information.c"
#include "test_n2_ran_information.c"
#include "test_nrppa_information.c"
#include "test_pws_information.c"
#include "test_v2x_information.c"
#include "test_pro_se_information.c"
#include "test_tss_information.c"
#include "test_rslp_information.c"
#include "test_a2x_information.c"


n2_info_container_t *instantiate_n2_info_container(int include_optional) {
	n2_info_container_t *n2_info_container = NULL;
	if(include_optional) {
		n2_info_container = n2_info_container_create(
			namf_communication_n2_info_container__SM,
			// false, not to have infinite recursion
			instantiate_n2_sm_information(0),
			// false, not to have infinite recursion
			instantiate_n2_ran_information(0),
			// false, not to have infinite recursion
			instantiate_nrppa_information(0),
			// false, not to have infinite recursion
			instantiate_pws_information(0),
			// false, not to have infinite recursion
			instantiate_v2x_information(0),
			// false, not to have infinite recursion
			instantiate_pro_se_information(0),
			// false, not to have infinite recursion
			instantiate_tss_information(0),
			// false, not to have infinite recursion
			instantiate_rslp_information(0),
			// false, not to have infinite recursion
			instantiate_a2x_information(0)
			);
	} else {
		n2_info_container = n2_info_container_create(
			namf_communication_n2_info_container__SM,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL
			);
	}

	return n2_info_container;
}


#ifdef n2_info_container_MAIN

void test_n2_info_container(int include_optional) {
	n2_info_container_t *n2_info_container_1 =
		instantiate_n2_info_container(include_optional);

	cJSON *jsonn2_info_container_1 = n2_info_container_convertToJSON(
		n2_info_container_1);
	printf("n2_info_container :\n%s\n",
	       cJSON_Print(jsonn2_info_container_1));
	n2_info_container_t *n2_info_container_2 =
		n2_info_container_parseFromJSON(jsonn2_info_container_1);
	cJSON *jsonn2_info_container_2 = n2_info_container_convertToJSON(
		n2_info_container_2);
	printf("repeating n2_info_container:\n%s\n",
	       cJSON_Print(jsonn2_info_container_2));
}

int main() {
	test_n2_info_container(1);
	test_n2_info_container(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_info_container_MAIN
#endif // n2_info_container_TEST
