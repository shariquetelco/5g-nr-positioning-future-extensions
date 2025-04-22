#ifndef registration_context_container_TEST
#define registration_context_container_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define registration_context_container_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/registration_context_container.h"
registration_context_container_t *instantiate_registration_context_container(
	int include_optional);

#include "test_ue_context.c"
#include "test_global_ran_node_id.c"
#include "test_user_location.c"
#include "test_ipv6_addr.c"
#include "test_allowed_nssai.c"
#include "test_plmn_id.c"
#include "test_ce_mode_b_ind.c"
#include "test_lte_m_ind.c"
#include "test_npn_access_info.c"


registration_context_container_t *instantiate_registration_context_container(
	int include_optional) {
	registration_context_container_t *registration_context_container = NULL;
	if(include_optional) {
		registration_context_container =
			registration_context_container_create(
				// false, not to have infinite recursion
				instantiate_ue_context(
					0),
				"-08:00+1",
				namf_communication_registration_context_container__3GPP_ACCESS,
				56,
				// false, not to have infinite recursion
				instantiate_global_ran_node_id(0),
				"a",
				// false, not to have infinite recursion
				instantiate_user_location(0),
				"a",
				1,
				56,
				"198.51.100.1",
				"2001:db8:85a3::8a2e:370:7334",
				// false, not to have infinite recursion
				instantiate_allowed_nssai(0),
				list_createList(),
				list_createList(),
				list_createList(),
				// false, not to have infinite recursion
				instantiate_plmn_id(0),
				1,
				1,
				// false, not to have infinite recursion
				instantiate_ce_mode_b_ind(0),
				// false, not to have infinite recursion
				instantiate_lte_m_ind(0),
				1,
				// false, not to have infinite recursion
				instantiate_npn_access_info(0)
				);
	} else {
		registration_context_container =
			registration_context_container_create(
				NULL,
				"-08:00+1",
				namf_communication_registration_context_container__3GPP_ACCESS,
				56,
				NULL,
				"a",
				NULL,
				"a",
				1,
				56,
				"198.51.100.1",
				"2001:db8:85a3::8a2e:370:7334",
				NULL,
				list_createList(),
				list_createList(),
				list_createList(),
				NULL,
				1,
				1,
				NULL,
				NULL,
				1,
				NULL
				);
	}

	return registration_context_container;
}


#ifdef registration_context_container_MAIN

void test_registration_context_container(int include_optional) {
	registration_context_container_t *registration_context_container_1 =
		instantiate_registration_context_container(include_optional);

	cJSON *jsonregistration_context_container_1 =
		registration_context_container_convertToJSON(
			registration_context_container_1);
	printf("registration_context_container :\n%s\n",
	       cJSON_Print(jsonregistration_context_container_1));
	registration_context_container_t *registration_context_container_2 =
		registration_context_container_parseFromJSON(
			jsonregistration_context_container_1);
	cJSON *jsonregistration_context_container_2 =
		registration_context_container_convertToJSON(
			registration_context_container_2);
	printf("repeating registration_context_container:\n%s\n",
	       cJSON_Print(jsonregistration_context_container_2));
}

int main() {
	test_registration_context_container(1);
	test_registration_context_container(0);

	printf("Hello world \n");
	return 0;
}

#endif // registration_context_container_MAIN
#endif // registration_context_container_TEST
