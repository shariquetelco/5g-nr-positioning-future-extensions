#ifndef query_parameter_TEST
#define query_parameter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define query_parameter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/query_parameter.h"
query_parameter_t *instantiate_query_parameter(int include_optional);



query_parameter_t *instantiate_query_parameter(int include_optional) {
	query_parameter_t *query_parameter = NULL;
	if(include_optional) {
		query_parameter = query_parameter_create(
			"0",
			"0"
			);
	} else {
		query_parameter = query_parameter_create(
			"0",
			"0"
			);
	}

	return query_parameter;
}


#ifdef query_parameter_MAIN

void test_query_parameter(int include_optional) {
	query_parameter_t *query_parameter_1 = instantiate_query_parameter(
		include_optional);

	cJSON *jsonquery_parameter_1 = query_parameter_convertToJSON(
		query_parameter_1);
	printf("query_parameter :\n%s\n", cJSON_Print(jsonquery_parameter_1));
	query_parameter_t *query_parameter_2 = query_parameter_parseFromJSON(
		jsonquery_parameter_1);
	cJSON *jsonquery_parameter_2 = query_parameter_convertToJSON(
		query_parameter_2);
	printf("repeating query_parameter:\n%s\n",
	       cJSON_Print(jsonquery_parameter_2));
}

int main() {
	test_query_parameter(1);
	test_query_parameter(0);

	printf("Hello world \n");
	return 0;
}

#endif // query_parameter_MAIN
#endif // query_parameter_TEST
