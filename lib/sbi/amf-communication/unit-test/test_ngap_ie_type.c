#ifndef ngap_ie_type_TEST
#define ngap_ie_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ngap_ie_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ngap_ie_type.h"
ngap_ie_type_t *instantiate_ngap_ie_type(int include_optional);



ngap_ie_type_t *instantiate_ngap_ie_type(int include_optional) {
	ngap_ie_type_t *ngap_ie_type = NULL;
	if(include_optional) {
		ngap_ie_type = ngap_ie_type_create(
			);
	} else {
		ngap_ie_type = ngap_ie_type_create(
			);
	}

	return ngap_ie_type;
}


#ifdef ngap_ie_type_MAIN

void test_ngap_ie_type(int include_optional) {
	ngap_ie_type_t *ngap_ie_type_1 = instantiate_ngap_ie_type(
		include_optional);

	cJSON *jsonngap_ie_type_1 = ngap_ie_type_convertToJSON(ngap_ie_type_1);
	printf("ngap_ie_type :\n%s\n", cJSON_Print(jsonngap_ie_type_1));
	ngap_ie_type_t *ngap_ie_type_2 = ngap_ie_type_parseFromJSON(
		jsonngap_ie_type_1);
	cJSON *jsonngap_ie_type_2 = ngap_ie_type_convertToJSON(ngap_ie_type_2);
	printf("repeating ngap_ie_type:\n%s\n",
	       cJSON_Print(jsonngap_ie_type_2));
}

int main() {
	test_ngap_ie_type(1);
	test_ngap_ie_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // ngap_ie_type_MAIN
#endif // ngap_ie_type_TEST
