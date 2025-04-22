#ifndef ranking_criterion_TEST
#define ranking_criterion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ranking_criterion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ranking_criterion.h"
ranking_criterion_t *instantiate_ranking_criterion(int include_optional);



ranking_criterion_t *instantiate_ranking_criterion(int include_optional) {
	ranking_criterion_t *ranking_criterion = NULL;
	if(include_optional) {
		ranking_criterion = ranking_criterion_create(
			1,
			1
			);
	} else {
		ranking_criterion = ranking_criterion_create(
			1,
			1
			);
	}

	return ranking_criterion;
}


#ifdef ranking_criterion_MAIN

void test_ranking_criterion(int include_optional) {
	ranking_criterion_t *ranking_criterion_1 =
		instantiate_ranking_criterion(include_optional);

	cJSON *jsonranking_criterion_1 = ranking_criterion_convertToJSON(
		ranking_criterion_1);
	printf("ranking_criterion :\n%s\n",
	       cJSON_Print(jsonranking_criterion_1));
	ranking_criterion_t *ranking_criterion_2 =
		ranking_criterion_parseFromJSON(jsonranking_criterion_1);
	cJSON *jsonranking_criterion_2 = ranking_criterion_convertToJSON(
		ranking_criterion_2);
	printf("repeating ranking_criterion:\n%s\n",
	       cJSON_Print(jsonranking_criterion_2));
}

int main() {
	test_ranking_criterion(1);
	test_ranking_criterion(0);

	printf("Hello world \n");
	return 0;
}

#endif // ranking_criterion_MAIN
#endif // ranking_criterion_TEST
