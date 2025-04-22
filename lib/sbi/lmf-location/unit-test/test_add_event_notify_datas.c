#ifndef add_event_notify_datas_TEST
#define add_event_notify_datas_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define add_event_notify_datas_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/add_event_notify_datas.h"
add_event_notify_datas_t *instantiate_add_event_notify_datas(
	int include_optional);



add_event_notify_datas_t *instantiate_add_event_notify_datas(
	int include_optional) {
	add_event_notify_datas_t *add_event_notify_datas = NULL;
	if(include_optional) {
		add_event_notify_datas = add_event_notify_datas_create(
			list_createList()
			);
	} else {
		add_event_notify_datas = add_event_notify_datas_create(
			list_createList()
			);
	}

	return add_event_notify_datas;
}


#ifdef add_event_notify_datas_MAIN

void test_add_event_notify_datas(int include_optional) {
	add_event_notify_datas_t *add_event_notify_datas_1 =
		instantiate_add_event_notify_datas(include_optional);

	cJSON *jsonadd_event_notify_datas_1 =
		add_event_notify_datas_convertToJSON(add_event_notify_datas_1);
	printf("add_event_notify_datas :\n%s\n",
	       cJSON_Print(jsonadd_event_notify_datas_1));
	add_event_notify_datas_t *add_event_notify_datas_2 =
		add_event_notify_datas_parseFromJSON(
			jsonadd_event_notify_datas_1);
	cJSON *jsonadd_event_notify_datas_2 =
		add_event_notify_datas_convertToJSON(add_event_notify_datas_2);
	printf("repeating add_event_notify_datas:\n%s\n",
	       cJSON_Print(jsonadd_event_notify_datas_2));
}

int main() {
	test_add_event_notify_datas(1);
	test_add_event_notify_datas(0);

	printf("Hello world \n");
	return 0;
}

#endif // add_event_notify_datas_MAIN
#endif // add_event_notify_datas_TEST
