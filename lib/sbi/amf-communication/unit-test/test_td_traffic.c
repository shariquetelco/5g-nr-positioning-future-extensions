#ifndef td_traffic_TEST
#define td_traffic_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define td_traffic_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/td_traffic.h"
td_traffic_t *instantiate_td_traffic(int include_optional);



td_traffic_t *instantiate_td_traffic(int include_optional) {
	td_traffic_t *td_traffic = NULL;
	if(include_optional) {
		td_traffic = td_traffic_create(
			list_createList(),
			0,
			0,
			0,
			0,
			0,
			0
			);
	} else {
		td_traffic = td_traffic_create(
			list_createList(),
			0,
			0,
			0,
			0,
			0,
			0
			);
	}

	return td_traffic;
}


#ifdef td_traffic_MAIN

void test_td_traffic(int include_optional) {
	td_traffic_t *td_traffic_1 = instantiate_td_traffic(include_optional);

	cJSON *jsontd_traffic_1 = td_traffic_convertToJSON(td_traffic_1);
	printf("td_traffic :\n%s\n", cJSON_Print(jsontd_traffic_1));
	td_traffic_t *td_traffic_2 = td_traffic_parseFromJSON(jsontd_traffic_1);
	cJSON *jsontd_traffic_2 = td_traffic_convertToJSON(td_traffic_2);
	printf("repeating td_traffic:\n%s\n", cJSON_Print(jsontd_traffic_2));
}

int main() {
	test_td_traffic(1);
	test_td_traffic(0);

	printf("Hello world \n");
	return 0;
}

#endif // td_traffic_MAIN
#endif // td_traffic_TEST
