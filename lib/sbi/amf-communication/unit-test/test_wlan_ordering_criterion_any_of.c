#ifndef wlan_ordering_criterion_any_of_TEST
#define wlan_ordering_criterion_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define wlan_ordering_criterion_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/wlan_ordering_criterion_any_of.h"
wlan_ordering_criterion_any_of_t *instantiate_wlan_ordering_criterion_any_of(
	int include_optional);



wlan_ordering_criterion_any_of_t *instantiate_wlan_ordering_criterion_any_of(
	int include_optional) {
	wlan_ordering_criterion_any_of_t *wlan_ordering_criterion_any_of = NULL;
	if(include_optional) {
		wlan_ordering_criterion_any_of =
			wlan_ordering_criterion_any_of_create(
				);
	} else {
		wlan_ordering_criterion_any_of =
			wlan_ordering_criterion_any_of_create(
				);
	}

	return wlan_ordering_criterion_any_of;
}


#ifdef wlan_ordering_criterion_any_of_MAIN

void test_wlan_ordering_criterion_any_of(int include_optional) {
	wlan_ordering_criterion_any_of_t *wlan_ordering_criterion_any_of_1 =
		instantiate_wlan_ordering_criterion_any_of(include_optional);

	cJSON *jsonwlan_ordering_criterion_any_of_1 =
		wlan_ordering_criterion_any_of_convertToJSON(
			wlan_ordering_criterion_any_of_1);
	printf("wlan_ordering_criterion_any_of :\n%s\n",
	       cJSON_Print(jsonwlan_ordering_criterion_any_of_1));
	wlan_ordering_criterion_any_of_t *wlan_ordering_criterion_any_of_2 =
		wlan_ordering_criterion_any_of_parseFromJSON(
			jsonwlan_ordering_criterion_any_of_1);
	cJSON *jsonwlan_ordering_criterion_any_of_2 =
		wlan_ordering_criterion_any_of_convertToJSON(
			wlan_ordering_criterion_any_of_2);
	printf("repeating wlan_ordering_criterion_any_of:\n%s\n",
	       cJSON_Print(jsonwlan_ordering_criterion_any_of_2));
}

int main() {
	test_wlan_ordering_criterion_any_of(1);
	test_wlan_ordering_criterion_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // wlan_ordering_criterion_any_of_MAIN
#endif // wlan_ordering_criterion_any_of_TEST
