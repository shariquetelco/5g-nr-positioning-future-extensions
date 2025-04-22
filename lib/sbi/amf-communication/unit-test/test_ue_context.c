#ifndef ue_context_TEST
#define ue_context_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_context_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_context.h"
ue_context_t *instantiate_ue_context(int include_optional);

#include "test_ambr.c"
#include "test_ambr.c"
#include "test_seaf_data.c"
#include "test_service_area_restriction.c"
#include "test_eps_interworking_info.c"
#include "test_trace_data.c"
#include "test_v2x_context.c"
#include "test_mo_exp_data_counter.c"
#include "test_cag_data.c"
#include "test_immediate_mdt_conf.c"
#include "test_ec_restriction_data_wb.c"
#include "test_prose_context.c"
#include "test_service_area_restriction.c"
#include "test_updp_subscription_data.c"
#include "test_pcf_ue_callback_info.c"
#include "test_smf_selection_data.c"
#include "test_plmn_id.c"
#include "test_satellite_backhaul_category.c"
#include "test_wireline_service_area_restriction.c"
#include "test_as_time_distribution_param.c"
#include "test_am_policy_info_container.c"
#include "test_a2x_context.c"
#include "test_mbsr_operation_allowed.c"
#include "test_lcs_up_context.c"


ue_context_t *instantiate_ue_context(int include_optional) {
	ue_context_t *ue_context = NULL;
	if(include_optional) {
		ue_context = ue_context_create(
			"a",
			1,
			list_createList(),
			"a",
			"0",
			"0",
			"0",
			"0",
			56,
			list_createList(),
			"YQ==",
			1,
			1,
			1,
			// false, not to have infinite recursion
			instantiate_ambr(0),
			// false, not to have infinite recursion
			instantiate_ambr(0),
			list_createList(),
			"0",
			// false, not to have infinite recursion
			instantiate_seaf_data(0),
			"YQ==",
			"0",
			"0",
			"0",
			"0",
			namf_communication_ue_context__NF_INSTANCE_BINDING,
			"0",
			list_createList(),
			"0",
			list_createList(),
			"0",
			"0",
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_service_area_restriction(0),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_eps_interworking_info(0),
			// false, not to have infinite recursion
			instantiate_trace_data(0),
			"2013-10-20T19:20:30+01:00",
			"0",
			"a",
			"YQ==",
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_v2x_context(0),
			1,
			1,
			// false, not to have infinite recursion
			instantiate_mo_exp_data_counter(0),
			// false, not to have infinite recursion
			instantiate_cag_data(0),
			1,
			list_createList(),
			// false, not to have infinite recursion
			instantiate_immediate_mdt_conf(0),
			// false, not to have infinite recursion
			instantiate_ec_restriction_data_wb(0),
			1,
			1,
			// false, not to have infinite recursion
			instantiate_prose_context(0),
			list_createList(),
			"0",
			"0",
			// false, not to have infinite recursion
			instantiate_service_area_restriction(0),
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_updp_subscription_data(0),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_pcf_ue_callback_info(0),
			"YQ==",
			1,
			56,
			1,
			// false, not to have infinite recursion
			instantiate_smf_selection_data(0),
			list_createList(),
			"0",
			"0",
			"0",
			1,
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			null,
			// false, not to have infinite recursion
			instantiate_wireline_service_area_restriction(0),
			// false, not to have infinite recursion
			instantiate_as_time_distribution_param(0),
			// false, not to have infinite recursion
			instantiate_am_policy_info_container(0),
			// false, not to have infinite recursion
			instantiate_a2x_context(0),
			// false, not to have infinite recursion
			instantiate_mbsr_operation_allowed(0),
			// false, not to have infinite recursion
			instantiate_lcs_up_context(0),
			1
			);
	} else {
		ue_context = ue_context_create(
			"a",
			1,
			list_createList(),
			"a",
			"0",
			"0",
			"0",
			"0",
			56,
			list_createList(),
			"YQ==",
			1,
			1,
			1,
			NULL,
			NULL,
			list_createList(),
			"0",
			NULL,
			"YQ==",
			"0",
			"0",
			"0",
			"0",
			namf_communication_ue_context__NF_INSTANCE_BINDING,
			"0",
			list_createList(),
			"0",
			list_createList(),
			"0",
			"0",
			list_createList(),
			list_createList(),
			NULL,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			NULL,
			NULL,
			"2013-10-20T19:20:30+01:00",
			"0",
			"a",
			"YQ==",
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			NULL,
			1,
			1,
			NULL,
			NULL,
			1,
			list_createList(),
			NULL,
			NULL,
			1,
			1,
			NULL,
			list_createList(),
			"0",
			"0",
			NULL,
			list_createList(),
			list_createList(),
			NULL,
			list_createList(),
			NULL,
			"YQ==",
			1,
			56,
			1,
			NULL,
			list_createList(),
			"0",
			"0",
			"0",
			1,
			NULL,
			null,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			1
			);
	}

	return ue_context;
}


#ifdef ue_context_MAIN

void test_ue_context(int include_optional) {
	ue_context_t *ue_context_1 = instantiate_ue_context(include_optional);

	cJSON *jsonue_context_1 = ue_context_convertToJSON(ue_context_1);
	printf("ue_context :\n%s\n", cJSON_Print(jsonue_context_1));
	ue_context_t *ue_context_2 = ue_context_parseFromJSON(jsonue_context_1);
	cJSON *jsonue_context_2 = ue_context_convertToJSON(ue_context_2);
	printf("repeating ue_context:\n%s\n", cJSON_Print(jsonue_context_2));
}

int main() {
	test_ue_context(1);
	test_ue_context(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_context_MAIN
#endif // ue_context_TEST
