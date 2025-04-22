#ifndef battery_indication_TEST
#define battery_indication_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define battery_indication_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/battery_indication.h"
battery_indication_t *instantiate_battery_indication(int include_optional);



battery_indication_t *instantiate_battery_indication(int include_optional) {
	battery_indication_t *battery_indication = NULL;
	if(include_optional) {
		battery_indication = battery_indication_create(
			1,
			1,
			1
			);
	} else {
		battery_indication = battery_indication_create(
			1,
			1,
			1
			);
	}

	return battery_indication;
}


#ifdef battery_indication_MAIN

void test_battery_indication(int include_optional) {
	battery_indication_t *battery_indication_1 =
		instantiate_battery_indication(include_optional);

	cJSON *jsonbattery_indication_1 = battery_indication_convertToJSON(
		battery_indication_1);
	printf("battery_indication :\n%s\n",
	       cJSON_Print(jsonbattery_indication_1));
	battery_indication_t *battery_indication_2 =
		battery_indication_parseFromJSON(jsonbattery_indication_1);
	cJSON *jsonbattery_indication_2 = battery_indication_convertToJSON(
		battery_indication_2);
	printf("repeating battery_indication:\n%s\n",
	       cJSON_Print(jsonbattery_indication_2));
}

int main() {
	test_battery_indication(1);
	test_battery_indication(0);

	printf("Hello world \n");
	return 0;
}

#endif // battery_indication_MAIN
#endif // battery_indication_TEST
