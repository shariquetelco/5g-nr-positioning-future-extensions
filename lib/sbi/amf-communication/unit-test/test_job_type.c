#ifndef job_type_TEST
#define job_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define job_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/job_type.h"
job_type_t *instantiate_job_type(int include_optional);



job_type_t *instantiate_job_type(int include_optional) {
	job_type_t *job_type = NULL;
	if(include_optional) {
		job_type = job_type_create(
			);
	} else {
		job_type = job_type_create(
			);
	}

	return job_type;
}


#ifdef job_type_MAIN

void test_job_type(int include_optional) {
	job_type_t *job_type_1 = instantiate_job_type(include_optional);

	cJSON *jsonjob_type_1 = job_type_convertToJSON(job_type_1);
	printf("job_type :\n%s\n", cJSON_Print(jsonjob_type_1));
	job_type_t *job_type_2 = job_type_parseFromJSON(jsonjob_type_1);
	cJSON *jsonjob_type_2 = job_type_convertToJSON(job_type_2);
	printf("repeating job_type:\n%s\n", cJSON_Print(jsonjob_type_2));
}

int main() {
	test_job_type(1);
	test_job_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // job_type_MAIN
#endif // job_type_TEST
