#ifndef termination_cause_TEST
#define termination_cause_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define termination_cause_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/termination_cause.h"
termination_cause_t *instantiate_termination_cause(int include_optional);



termination_cause_t *instantiate_termination_cause(int include_optional) {
	termination_cause_t *termination_cause = NULL;
	if(include_optional) {
		termination_cause = termination_cause_create(
			);
	} else {
		termination_cause = termination_cause_create(
			);
	}

	return termination_cause;
}


#ifdef termination_cause_MAIN

void test_termination_cause(int include_optional) {
	termination_cause_t *termination_cause_1 =
		instantiate_termination_cause(include_optional);

	cJSON *jsontermination_cause_1 = termination_cause_convertToJSON(
		termination_cause_1);
	printf("termination_cause :\n%s\n",
	       cJSON_Print(jsontermination_cause_1));
	termination_cause_t *termination_cause_2 =
		termination_cause_parseFromJSON(jsontermination_cause_1);
	cJSON *jsontermination_cause_2 = termination_cause_convertToJSON(
		termination_cause_2);
	printf("repeating termination_cause:\n%s\n",
	       cJSON_Print(jsontermination_cause_2));
}

int main() {
	test_termination_cause(1);
	test_termination_cause(0);

	printf("Hello world \n");
	return 0;
}

#endif // termination_cause_MAIN
#endif // termination_cause_TEST
