#ifndef collection_period_rmm_nr_mdt_any_of_TEST
#define collection_period_rmm_nr_mdt_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define collection_period_rmm_nr_mdt_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/collection_period_rmm_nr_mdt_any_of.h"
collection_period_rmm_nr_mdt_any_of_t *
instantiate_collection_period_rmm_nr_mdt_any_of(int include_optional);



collection_period_rmm_nr_mdt_any_of_t *
instantiate_collection_period_rmm_nr_mdt_any_of(int include_optional) {
	collection_period_rmm_nr_mdt_any_of_t *
	        collection_period_rmm_nr_mdt_any_of = NULL;
	if(include_optional) {
		collection_period_rmm_nr_mdt_any_of =
			collection_period_rmm_nr_mdt_any_of_create(
				);
	} else {
		collection_period_rmm_nr_mdt_any_of =
			collection_period_rmm_nr_mdt_any_of_create(
				);
	}

	return collection_period_rmm_nr_mdt_any_of;
}


#ifdef collection_period_rmm_nr_mdt_any_of_MAIN

void test_collection_period_rmm_nr_mdt_any_of(int include_optional) {
	collection_period_rmm_nr_mdt_any_of_t *
	        collection_period_rmm_nr_mdt_any_of_1 =
		instantiate_collection_period_rmm_nr_mdt_any_of(include_optional);

	cJSON *jsoncollection_period_rmm_nr_mdt_any_of_1 =
		collection_period_rmm_nr_mdt_any_of_convertToJSON(
			collection_period_rmm_nr_mdt_any_of_1);
	printf("collection_period_rmm_nr_mdt_any_of :\n%s\n",
	       cJSON_Print(jsoncollection_period_rmm_nr_mdt_any_of_1));
	collection_period_rmm_nr_mdt_any_of_t *
	        collection_period_rmm_nr_mdt_any_of_2 =
		collection_period_rmm_nr_mdt_any_of_parseFromJSON(
			jsoncollection_period_rmm_nr_mdt_any_of_1);
	cJSON *jsoncollection_period_rmm_nr_mdt_any_of_2 =
		collection_period_rmm_nr_mdt_any_of_convertToJSON(
			collection_period_rmm_nr_mdt_any_of_2);
	printf("repeating collection_period_rmm_nr_mdt_any_of:\n%s\n", cJSON_Print(
		       jsoncollection_period_rmm_nr_mdt_any_of_2));
}

int main() {
	test_collection_period_rmm_nr_mdt_any_of(1);
	test_collection_period_rmm_nr_mdt_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // collection_period_rmm_nr_mdt_any_of_MAIN
#endif // collection_period_rmm_nr_mdt_any_of_TEST
