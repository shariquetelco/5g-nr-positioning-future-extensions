#ifndef timestamped_location_TEST
#define timestamped_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define timestamped_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/timestamped_location.h"
timestamped_location_t *instantiate_timestamped_location(int include_optional);



timestamped_location_t *instantiate_timestamped_location(int include_optional) {
	timestamped_location_t *timestamped_location = NULL;
	if(include_optional) {
		timestamped_location = timestamped_location_create(
			"2013-10-20T19:20:30+01:00",
			list_createList()
			);
	} else {
		timestamped_location = timestamped_location_create(
			"2013-10-20T19:20:30+01:00",
			list_createList()
			);
	}

	return timestamped_location;
}


#ifdef timestamped_location_MAIN

void test_timestamped_location(int include_optional) {
	timestamped_location_t *timestamped_location_1 =
		instantiate_timestamped_location(include_optional);

	cJSON *jsontimestamped_location_1 = timestamped_location_convertToJSON(
		timestamped_location_1);
	printf("timestamped_location :\n%s\n",
	       cJSON_Print(jsontimestamped_location_1));
	timestamped_location_t *timestamped_location_2 =
		timestamped_location_parseFromJSON(jsontimestamped_location_1);
	cJSON *jsontimestamped_location_2 = timestamped_location_convertToJSON(
		timestamped_location_2);
	printf("repeating timestamped_location:\n%s\n",
	       cJSON_Print(jsontimestamped_location_2));
}

int main() {
	test_timestamped_location(1);
	test_timestamped_location(0);

	printf("Hello world \n");
	return 0;
}

#endif // timestamped_location_MAIN
#endif // timestamped_location_TEST
