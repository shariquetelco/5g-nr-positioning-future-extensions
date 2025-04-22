#ifndef alert_limit_TEST
#define alert_limit_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define alert_limit_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/alert_limit.h"
alert_limit_t *instantiate_alert_limit(int include_optional);



alert_limit_t *instantiate_alert_limit(int include_optional) {
	alert_limit_t *alert_limit = NULL;
	if(include_optional) {
		alert_limit = alert_limit_create(
			0,
			0
			);
	} else {
		alert_limit = alert_limit_create(
			0,
			0
			);
	}

	return alert_limit;
}


#ifdef alert_limit_MAIN

void test_alert_limit(int include_optional) {
	alert_limit_t *alert_limit_1 =
		instantiate_alert_limit(include_optional);

	cJSON *jsonalert_limit_1 = alert_limit_convertToJSON(alert_limit_1);
	printf("alert_limit :\n%s\n", cJSON_Print(jsonalert_limit_1));
	alert_limit_t *alert_limit_2 = alert_limit_parseFromJSON(
		jsonalert_limit_1);
	cJSON *jsonalert_limit_2 = alert_limit_convertToJSON(alert_limit_2);
	printf("repeating alert_limit:\n%s\n", cJSON_Print(jsonalert_limit_2));
}

int main() {
	test_alert_limit(1);
	test_alert_limit(0);

	printf("Hello world \n");
	return 0;
}

#endif // alert_limit_MAIN
#endif // alert_limit_TEST
