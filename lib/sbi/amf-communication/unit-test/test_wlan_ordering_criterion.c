#ifndef wlan_ordering_criterion_TEST
#define wlan_ordering_criterion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define wlan_ordering_criterion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/wlan_ordering_criterion.h"
wlan_ordering_criterion_t *instantiate_wlan_ordering_criterion(
	int include_optional);



wlan_ordering_criterion_t *instantiate_wlan_ordering_criterion(
	int include_optional) {
	wlan_ordering_criterion_t *wlan_ordering_criterion = NULL;
	if(include_optional) {
		wlan_ordering_criterion = wlan_ordering_criterion_create(
			);
	} else {
		wlan_ordering_criterion = wlan_ordering_criterion_create(
			);
	}

	return wlan_ordering_criterion;
}


#ifdef wlan_ordering_criterion_MAIN

void test_wlan_ordering_criterion(int include_optional) {
	wlan_ordering_criterion_t *wlan_ordering_criterion_1 =
		instantiate_wlan_ordering_criterion(include_optional);

	cJSON *jsonwlan_ordering_criterion_1 =
		wlan_ordering_criterion_convertToJSON(wlan_ordering_criterion_1);
	printf("wlan_ordering_criterion :\n%s\n",
	       cJSON_Print(jsonwlan_ordering_criterion_1));
	wlan_ordering_criterion_t *wlan_ordering_criterion_2 =
		wlan_ordering_criterion_parseFromJSON(
			jsonwlan_ordering_criterion_1);
	cJSON *jsonwlan_ordering_criterion_2 =
		wlan_ordering_criterion_convertToJSON(wlan_ordering_criterion_2);
	printf("repeating wlan_ordering_criterion:\n%s\n",
	       cJSON_Print(jsonwlan_ordering_criterion_2));
}

int main() {
	test_wlan_ordering_criterion(1);
	test_wlan_ordering_criterion(0);

	printf("Hello world \n");
	return 0;
}

#endif // wlan_ordering_criterion_MAIN
#endif // wlan_ordering_criterion_TEST
