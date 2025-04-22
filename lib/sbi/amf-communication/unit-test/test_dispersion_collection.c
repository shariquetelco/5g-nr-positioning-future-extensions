#ifndef dispersion_collection_TEST
#define dispersion_collection_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dispersion_collection_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dispersion_collection.h"
dispersion_collection_t *instantiate_dispersion_collection(
	int include_optional);

#include "test_user_location.c"
#include "test_snssai.c"
#include "test_dispersion_class.c"


dispersion_collection_t *instantiate_dispersion_collection(int include_optional)
{
	dispersion_collection_t *dispersion_collection = NULL;
	if(include_optional) {
		dispersion_collection = dispersion_collection_create(
			// false, not to have infinite recursion
			instantiate_user_location(0),
			// false, not to have infinite recursion
			instantiate_snssai(0),
			list_createList(),
			list_createList(),
			list_createList(),
			0,
			null,
			1,
			1,
			1,
			0
			);
	} else {
		dispersion_collection = dispersion_collection_create(
			NULL,
			NULL,
			list_createList(),
			list_createList(),
			list_createList(),
			0,
			null,
			1,
			1,
			1,
			0
			);
	}

	return dispersion_collection;
}


#ifdef dispersion_collection_MAIN

void test_dispersion_collection(int include_optional) {
	dispersion_collection_t *dispersion_collection_1 =
		instantiate_dispersion_collection(include_optional);

	cJSON *jsondispersion_collection_1 =
		dispersion_collection_convertToJSON(dispersion_collection_1);
	printf("dispersion_collection :\n%s\n",
	       cJSON_Print(jsondispersion_collection_1));
	dispersion_collection_t *dispersion_collection_2 =
		dispersion_collection_parseFromJSON(jsondispersion_collection_1);
	cJSON *jsondispersion_collection_2 =
		dispersion_collection_convertToJSON(dispersion_collection_2);
	printf("repeating dispersion_collection:\n%s\n",
	       cJSON_Print(jsondispersion_collection_2));
}

int main() {
	test_dispersion_collection(1);
	test_dispersion_collection(0);

	printf("Hello world \n");
	return 0;
}

#endif // dispersion_collection_MAIN
#endif // dispersion_collection_TEST
