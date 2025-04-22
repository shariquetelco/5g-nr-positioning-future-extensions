#ifndef eps_interworking_info_TEST
#define eps_interworking_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define eps_interworking_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/eps_interworking_info.h"
eps_interworking_info_t *instantiate_eps_interworking_info(
	int include_optional);



eps_interworking_info_t *instantiate_eps_interworking_info(int include_optional)
{
	eps_interworking_info_t *eps_interworking_info = NULL;
	if(include_optional) {
		eps_interworking_info = eps_interworking_info_create(
			list_createList(),
			"2013-10-20T19:20:30+01:00"
			);
	} else {
		eps_interworking_info = eps_interworking_info_create(
			list_createList(),
			"2013-10-20T19:20:30+01:00"
			);
	}

	return eps_interworking_info;
}


#ifdef eps_interworking_info_MAIN

void test_eps_interworking_info(int include_optional) {
	eps_interworking_info_t *eps_interworking_info_1 =
		instantiate_eps_interworking_info(include_optional);

	cJSON *jsoneps_interworking_info_1 =
		eps_interworking_info_convertToJSON(eps_interworking_info_1);
	printf("eps_interworking_info :\n%s\n",
	       cJSON_Print(jsoneps_interworking_info_1));
	eps_interworking_info_t *eps_interworking_info_2 =
		eps_interworking_info_parseFromJSON(jsoneps_interworking_info_1);
	cJSON *jsoneps_interworking_info_2 =
		eps_interworking_info_convertToJSON(eps_interworking_info_2);
	printf("repeating eps_interworking_info:\n%s\n",
	       cJSON_Print(jsoneps_interworking_info_2));
}

int main() {
	test_eps_interworking_info(1);
	test_eps_interworking_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // eps_interworking_info_MAIN
#endif // eps_interworking_info_TEST
