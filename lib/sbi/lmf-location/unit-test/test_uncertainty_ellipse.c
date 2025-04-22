#ifndef uncertainty_ellipse_TEST
#define uncertainty_ellipse_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define uncertainty_ellipse_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/uncertainty_ellipse.h"
uncertainty_ellipse_t *instantiate_uncertainty_ellipse(int include_optional);



uncertainty_ellipse_t *instantiate_uncertainty_ellipse(int include_optional) {
	uncertainty_ellipse_t *uncertainty_ellipse = NULL;
	if(include_optional) {
		uncertainty_ellipse = uncertainty_ellipse_create(
			0,
			0,
			0
			);
	} else {
		uncertainty_ellipse = uncertainty_ellipse_create(
			0,
			0,
			0
			);
	}

	return uncertainty_ellipse;
}


#ifdef uncertainty_ellipse_MAIN

void test_uncertainty_ellipse(int include_optional) {
	uncertainty_ellipse_t *uncertainty_ellipse_1 =
		instantiate_uncertainty_ellipse(include_optional);

	cJSON *jsonuncertainty_ellipse_1 = uncertainty_ellipse_convertToJSON(
		uncertainty_ellipse_1);
	printf("uncertainty_ellipse :\n%s\n",
	       cJSON_Print(jsonuncertainty_ellipse_1));
	uncertainty_ellipse_t *uncertainty_ellipse_2 =
		uncertainty_ellipse_parseFromJSON(jsonuncertainty_ellipse_1);
	cJSON *jsonuncertainty_ellipse_2 = uncertainty_ellipse_convertToJSON(
		uncertainty_ellipse_2);
	printf("repeating uncertainty_ellipse:\n%s\n",
	       cJSON_Print(jsonuncertainty_ellipse_2));
}

int main() {
	test_uncertainty_ellipse(1);
	test_uncertainty_ellipse(0);

	printf("Hello world \n");
	return 0;
}

#endif // uncertainty_ellipse_MAIN
#endif // uncertainty_ellipse_TEST
