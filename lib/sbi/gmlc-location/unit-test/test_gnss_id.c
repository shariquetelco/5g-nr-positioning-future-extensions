#ifndef gnss_id_TEST
#define gnss_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gnss_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gnss_id.h"
gnss_id_t *instantiate_gnss_id(int include_optional);



gnss_id_t *instantiate_gnss_id(int include_optional) {
	gnss_id_t *gnss_id = NULL;
	if(include_optional) {
		gnss_id = gnss_id_create(
			);
	} else {
		gnss_id = gnss_id_create(
			);
	}

	return gnss_id;
}


#ifdef gnss_id_MAIN

void test_gnss_id(int include_optional) {
	gnss_id_t *gnss_id_1 = instantiate_gnss_id(include_optional);

	cJSON *jsongnss_id_1 = gnss_id_convertToJSON(gnss_id_1);
	printf("gnss_id :\n%s\n", cJSON_Print(jsongnss_id_1));
	gnss_id_t *gnss_id_2 = gnss_id_parseFromJSON(jsongnss_id_1);
	cJSON *jsongnss_id_2 = gnss_id_convertToJSON(gnss_id_2);
	printf("repeating gnss_id:\n%s\n", cJSON_Print(jsongnss_id_2));
}

int main() {
	test_gnss_id(1);
	test_gnss_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // gnss_id_MAIN
#endif // gnss_id_TEST
