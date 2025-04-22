#ifndef pc5_qo_s_para_TEST
#define pc5_qo_s_para_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pc5_qo_s_para_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pc5_qo_s_para.h"
pc5_qo_s_para_t *instantiate_pc5_qo_s_para(int include_optional);



pc5_qo_s_para_t *instantiate_pc5_qo_s_para(int include_optional) {
	pc5_qo_s_para_t *pc5_qo_s_para = NULL;
	if(include_optional) {
		pc5_qo_s_para = pc5_qo_s_para_create(
			list_createList(),
			"a"
			);
	} else {
		pc5_qo_s_para = pc5_qo_s_para_create(
			list_createList(),
			"a"
			);
	}

	return pc5_qo_s_para;
}


#ifdef pc5_qo_s_para_MAIN

void test_pc5_qo_s_para(int include_optional) {
	pc5_qo_s_para_t *pc5_qo_s_para_1 = instantiate_pc5_qo_s_para(
		include_optional);

	cJSON *jsonpc5_qo_s_para_1 =
		pc5_qo_s_para_convertToJSON(pc5_qo_s_para_1);
	printf("pc5_qo_s_para :\n%s\n", cJSON_Print(jsonpc5_qo_s_para_1));
	pc5_qo_s_para_t *pc5_qo_s_para_2 = pc5_qo_s_para_parseFromJSON(
		jsonpc5_qo_s_para_1);
	cJSON *jsonpc5_qo_s_para_2 =
		pc5_qo_s_para_convertToJSON(pc5_qo_s_para_2);
	printf("repeating pc5_qo_s_para:\n%s\n", cJSON_Print(
		       jsonpc5_qo_s_para_2));
}

int main() {
	test_pc5_qo_s_para(1);
	test_pc5_qo_s_para(0);

	printf("Hello world \n");
	return 0;
}

#endif // pc5_qo_s_para_MAIN
#endif // pc5_qo_s_para_TEST
