#ifndef gnb_id_TEST
#define gnb_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gnb_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gnb_id.h"
gnb_id_t *instantiate_gnb_id(int include_optional);



gnb_id_t *instantiate_gnb_id(int include_optional) {
	gnb_id_t *gnb_id = NULL;
	if(include_optional) {
		gnb_id = gnb_id_create(
			22,
			"a"
			);
	} else {
		gnb_id = gnb_id_create(
			22,
			"a"
			);
	}

	return gnb_id;
}


#ifdef gnb_id_MAIN

void test_gnb_id(int include_optional) {
	gnb_id_t *gnb_id_1 = instantiate_gnb_id(include_optional);

	cJSON *jsongnb_id_1 = gnb_id_convertToJSON(gnb_id_1);
	printf("gnb_id :\n%s\n", cJSON_Print(jsongnb_id_1));
	gnb_id_t *gnb_id_2 = gnb_id_parseFromJSON(jsongnb_id_1);
	cJSON *jsongnb_id_2 = gnb_id_convertToJSON(gnb_id_2);
	printf("repeating gnb_id:\n%s\n", cJSON_Print(jsongnb_id_2));
}

int main() {
	test_gnb_id(1);
	test_gnb_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // gnb_id_MAIN
#endif // gnb_id_TEST
