#ifndef assigned_ebi_data_TEST
#define assigned_ebi_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assigned_ebi_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assigned_ebi_data.h"
assigned_ebi_data_t *instantiate_assigned_ebi_data(int include_optional);



assigned_ebi_data_t *instantiate_assigned_ebi_data(int include_optional) {
	assigned_ebi_data_t *assigned_ebi_data = NULL;
	if(include_optional) {
		assigned_ebi_data = assigned_ebi_data_create(
			0,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		assigned_ebi_data = assigned_ebi_data_create(
			0,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return assigned_ebi_data;
}


#ifdef assigned_ebi_data_MAIN

void test_assigned_ebi_data(int include_optional) {
	assigned_ebi_data_t *assigned_ebi_data_1 =
		instantiate_assigned_ebi_data(include_optional);

	cJSON *jsonassigned_ebi_data_1 = assigned_ebi_data_convertToJSON(
		assigned_ebi_data_1);
	printf("assigned_ebi_data :\n%s\n",
	       cJSON_Print(jsonassigned_ebi_data_1));
	assigned_ebi_data_t *assigned_ebi_data_2 =
		assigned_ebi_data_parseFromJSON(jsonassigned_ebi_data_1);
	cJSON *jsonassigned_ebi_data_2 = assigned_ebi_data_convertToJSON(
		assigned_ebi_data_2);
	printf("repeating assigned_ebi_data:\n%s\n",
	       cJSON_Print(jsonassigned_ebi_data_2));
}

int main() {
	test_assigned_ebi_data(1);
	test_assigned_ebi_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // assigned_ebi_data_MAIN
#endif // assigned_ebi_data_TEST
