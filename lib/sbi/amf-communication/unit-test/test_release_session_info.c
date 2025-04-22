#ifndef release_session_info_TEST
#define release_session_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define release_session_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/release_session_info.h"
release_session_info_t *instantiate_release_session_info(int include_optional);



release_session_info_t *instantiate_release_session_info(int include_optional) {
	release_session_info_t *release_session_info = NULL;
	if(include_optional) {
		release_session_info = release_session_info_create(
			list_createList(),
			namf_communication_release_session_info__SNPN_SNPN_MOBILITY
			);
	} else {
		release_session_info = release_session_info_create(
			list_createList(),
			namf_communication_release_session_info__SNPN_SNPN_MOBILITY
			);
	}

	return release_session_info;
}


#ifdef release_session_info_MAIN

void test_release_session_info(int include_optional) {
	release_session_info_t *release_session_info_1 =
		instantiate_release_session_info(include_optional);

	cJSON *jsonrelease_session_info_1 = release_session_info_convertToJSON(
		release_session_info_1);
	printf("release_session_info :\n%s\n",
	       cJSON_Print(jsonrelease_session_info_1));
	release_session_info_t *release_session_info_2 =
		release_session_info_parseFromJSON(jsonrelease_session_info_1);
	cJSON *jsonrelease_session_info_2 = release_session_info_convertToJSON(
		release_session_info_2);
	printf("repeating release_session_info:\n%s\n",
	       cJSON_Print(jsonrelease_session_info_2));
}

int main() {
	test_release_session_info(1);
	test_release_session_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // release_session_info_MAIN
#endif // release_session_info_TEST
