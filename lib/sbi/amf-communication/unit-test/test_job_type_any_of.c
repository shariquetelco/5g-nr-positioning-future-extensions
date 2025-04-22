#ifndef job_type_any_of_TEST
#define job_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define job_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/job_type_any_of.h"
job_type_any_of_t *instantiate_job_type_any_of(int include_optional);



job_type_any_of_t *instantiate_job_type_any_of(int include_optional) {
	job_type_any_of_t *job_type_any_of = NULL;
	if(include_optional) {
		job_type_any_of = job_type_any_of_create(
			);
	} else {
		job_type_any_of = job_type_any_of_create(
			);
	}

	return job_type_any_of;
}


#ifdef job_type_any_of_MAIN

void test_job_type_any_of(int include_optional) {
	job_type_any_of_t *job_type_any_of_1 = instantiate_job_type_any_of(
		include_optional);

	cJSON *jsonjob_type_any_of_1 = job_type_any_of_convertToJSON(
		job_type_any_of_1);
	printf("job_type_any_of :\n%s\n", cJSON_Print(jsonjob_type_any_of_1));
	job_type_any_of_t *job_type_any_of_2 = job_type_any_of_parseFromJSON(
		jsonjob_type_any_of_1);
	cJSON *jsonjob_type_any_of_2 = job_type_any_of_convertToJSON(
		job_type_any_of_2);
	printf("repeating job_type_any_of:\n%s\n",
	       cJSON_Print(jsonjob_type_any_of_2));
}

int main() {
	test_job_type_any_of(1);
	test_job_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // job_type_any_of_MAIN
#endif // job_type_any_of_TEST
