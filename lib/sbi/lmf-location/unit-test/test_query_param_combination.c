#ifndef query_param_combination_TEST
#define query_param_combination_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define query_param_combination_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/query_param_combination.h"
query_param_combination_t *instantiate_query_param_combination(
	int include_optional);



query_param_combination_t *instantiate_query_param_combination(
	int include_optional) {
	query_param_combination_t *query_param_combination = NULL;
	if(include_optional) {
		query_param_combination = query_param_combination_create(
			list_createList()
			);
	} else {
		query_param_combination = query_param_combination_create(
			list_createList()
			);
	}

	return query_param_combination;
}


#ifdef query_param_combination_MAIN

void test_query_param_combination(int include_optional) {
	query_param_combination_t *query_param_combination_1 =
		instantiate_query_param_combination(include_optional);

	cJSON *jsonquery_param_combination_1 =
		query_param_combination_convertToJSON(query_param_combination_1);
	printf("query_param_combination :\n%s\n",
	       cJSON_Print(jsonquery_param_combination_1));
	query_param_combination_t *query_param_combination_2 =
		query_param_combination_parseFromJSON(
			jsonquery_param_combination_1);
	cJSON *jsonquery_param_combination_2 =
		query_param_combination_convertToJSON(query_param_combination_2);
	printf("repeating query_param_combination:\n%s\n",
	       cJSON_Print(jsonquery_param_combination_2));
}

int main() {
	test_query_param_combination(1);
	test_query_param_combination(0);

	printf("Hello world \n");
	return 0;
}

#endif // query_param_combination_MAIN
#endif // query_param_combination_TEST
