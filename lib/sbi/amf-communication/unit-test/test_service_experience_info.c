#ifndef service_experience_info_TEST
#define service_experience_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_experience_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_experience_info.h"
service_experience_info_t *instantiate_service_experience_info(
	int include_optional);

#include "test_svc_experience.c"
#include "test_snssai.c"
#include "test_service_experience_type.c"
#include "test_upf_information.c"
#include "test_addr_fqdn.c"
#include "test_network_area_info.c"
#include "test_rat_freq_information.c"
#include "test_pdu_session_info_1.c"


service_experience_info_t *instantiate_service_experience_info(
	int include_optional) {
	service_experience_info_t *service_experience_info = NULL;
	if(include_optional) {
		service_experience_info = service_experience_info_create(
			// false, not to have infinite recursion
			instantiate_svc_experience(0),
			1.337,
			list_createList(),
			// false, not to have infinite recursion
			instantiate_snssai(0),
			"0",
			null,
			list_createList(),
			// false, not to have infinite recursion
			instantiate_upf_information(0),
			"0",
			// false, not to have infinite recursion
			instantiate_addr_fqdn(0),
			0,
			"0",
			// false, not to have infinite recursion
			instantiate_network_area_info(0),
			"0",
			1,
			// false, not to have infinite recursion
			instantiate_rat_freq_information(0),
			// false, not to have infinite recursion
			instantiate_pdu_session_info_1(0)
			);
	} else {
		service_experience_info = service_experience_info_create(
			NULL,
			1.337,
			list_createList(),
			NULL,
			"0",
			null,
			list_createList(),
			NULL,
			"0",
			NULL,
			0,
			"0",
			NULL,
			"0",
			1,
			NULL,
			NULL
			);
	}

	return service_experience_info;
}


#ifdef service_experience_info_MAIN

void test_service_experience_info(int include_optional) {
	service_experience_info_t *service_experience_info_1 =
		instantiate_service_experience_info(include_optional);

	cJSON *jsonservice_experience_info_1 =
		service_experience_info_convertToJSON(service_experience_info_1);
	printf("service_experience_info :\n%s\n",
	       cJSON_Print(jsonservice_experience_info_1));
	service_experience_info_t *service_experience_info_2 =
		service_experience_info_parseFromJSON(
			jsonservice_experience_info_1);
	cJSON *jsonservice_experience_info_2 =
		service_experience_info_convertToJSON(service_experience_info_2);
	printf("repeating service_experience_info:\n%s\n",
	       cJSON_Print(jsonservice_experience_info_2));
}

int main() {
	test_service_experience_info(1);
	test_service_experience_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // service_experience_info_MAIN
#endif // service_experience_info_TEST
