#ifndef consumer_nf_information_TEST
#define consumer_nf_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define consumer_nf_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/consumer_nf_information.h"
consumer_nf_information_t *instantiate_consumer_nf_information(
	int include_optional);



consumer_nf_information_t *instantiate_consumer_nf_information(
	int include_optional) {
	consumer_nf_information_t *consumer_nf_information = NULL;
	if(include_optional) {
		consumer_nf_information = consumer_nf_information_create(
			"0",
			"0",
			list_createList()
			);
	} else {
		consumer_nf_information = consumer_nf_information_create(
			"0",
			"0",
			list_createList()
			);
	}

	return consumer_nf_information;
}


#ifdef consumer_nf_information_MAIN

void test_consumer_nf_information(int include_optional) {
	consumer_nf_information_t *consumer_nf_information_1 =
		instantiate_consumer_nf_information(include_optional);

	cJSON *jsonconsumer_nf_information_1 =
		consumer_nf_information_convertToJSON(consumer_nf_information_1);
	printf("consumer_nf_information :\n%s\n",
	       cJSON_Print(jsonconsumer_nf_information_1));
	consumer_nf_information_t *consumer_nf_information_2 =
		consumer_nf_information_parseFromJSON(
			jsonconsumer_nf_information_1);
	cJSON *jsonconsumer_nf_information_2 =
		consumer_nf_information_convertToJSON(consumer_nf_information_2);
	printf("repeating consumer_nf_information:\n%s\n",
	       cJSON_Print(jsonconsumer_nf_information_2));
}

int main() {
	test_consumer_nf_information(1);
	test_consumer_nf_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // consumer_nf_information_MAIN
#endif // consumer_nf_information_TEST
