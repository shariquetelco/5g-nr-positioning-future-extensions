#ifndef collection_period_rmm_nr_mdt_TEST
#define collection_period_rmm_nr_mdt_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define collection_period_rmm_nr_mdt_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/collection_period_rmm_nr_mdt.h"
collection_period_rmm_nr_mdt_t *instantiate_collection_period_rmm_nr_mdt(
	int include_optional);



collection_period_rmm_nr_mdt_t *instantiate_collection_period_rmm_nr_mdt(
	int include_optional) {
	collection_period_rmm_nr_mdt_t *collection_period_rmm_nr_mdt = NULL;
	if(include_optional) {
		collection_period_rmm_nr_mdt =
			collection_period_rmm_nr_mdt_create(
				);
	} else {
		collection_period_rmm_nr_mdt =
			collection_period_rmm_nr_mdt_create(
				);
	}

	return collection_period_rmm_nr_mdt;
}


#ifdef collection_period_rmm_nr_mdt_MAIN

void test_collection_period_rmm_nr_mdt(int include_optional) {
	collection_period_rmm_nr_mdt_t *collection_period_rmm_nr_mdt_1 =
		instantiate_collection_period_rmm_nr_mdt(include_optional);

	cJSON *jsoncollection_period_rmm_nr_mdt_1 =
		collection_period_rmm_nr_mdt_convertToJSON(
			collection_period_rmm_nr_mdt_1);
	printf("collection_period_rmm_nr_mdt :\n%s\n",
	       cJSON_Print(jsoncollection_period_rmm_nr_mdt_1));
	collection_period_rmm_nr_mdt_t *collection_period_rmm_nr_mdt_2 =
		collection_period_rmm_nr_mdt_parseFromJSON(
			jsoncollection_period_rmm_nr_mdt_1);
	cJSON *jsoncollection_period_rmm_nr_mdt_2 =
		collection_period_rmm_nr_mdt_convertToJSON(
			collection_period_rmm_nr_mdt_2);
	printf("repeating collection_period_rmm_nr_mdt:\n%s\n",
	       cJSON_Print(jsoncollection_period_rmm_nr_mdt_2));
}

int main() {
	test_collection_period_rmm_nr_mdt(1);
	test_collection_period_rmm_nr_mdt(0);

	printf("Hello world \n");
	return 0;
}

#endif // collection_period_rmm_nr_mdt_MAIN
#endif // collection_period_rmm_nr_mdt_TEST
