#ifndef uncertainty_ellipsoid_TEST
#define uncertainty_ellipsoid_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define uncertainty_ellipsoid_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/uncertainty_ellipsoid.h"
uncertainty_ellipsoid_t *instantiate_uncertainty_ellipsoid(
	int include_optional);



uncertainty_ellipsoid_t *instantiate_uncertainty_ellipsoid(int include_optional)
{
	uncertainty_ellipsoid_t *uncertainty_ellipsoid = NULL;
	if(include_optional) {
		uncertainty_ellipsoid = uncertainty_ellipsoid_create(
			0,
			0,
			0,
			0
			);
	} else {
		uncertainty_ellipsoid = uncertainty_ellipsoid_create(
			0,
			0,
			0,
			0
			);
	}

	return uncertainty_ellipsoid;
}


#ifdef uncertainty_ellipsoid_MAIN

void test_uncertainty_ellipsoid(int include_optional) {
	uncertainty_ellipsoid_t *uncertainty_ellipsoid_1 =
		instantiate_uncertainty_ellipsoid(include_optional);

	cJSON *jsonuncertainty_ellipsoid_1 =
		uncertainty_ellipsoid_convertToJSON(uncertainty_ellipsoid_1);
	printf("uncertainty_ellipsoid :\n%s\n",
	       cJSON_Print(jsonuncertainty_ellipsoid_1));
	uncertainty_ellipsoid_t *uncertainty_ellipsoid_2 =
		uncertainty_ellipsoid_parseFromJSON(jsonuncertainty_ellipsoid_1);
	cJSON *jsonuncertainty_ellipsoid_2 =
		uncertainty_ellipsoid_convertToJSON(uncertainty_ellipsoid_2);
	printf("repeating uncertainty_ellipsoid:\n%s\n",
	       cJSON_Print(jsonuncertainty_ellipsoid_2));
}

int main() {
	test_uncertainty_ellipsoid(1);
	test_uncertainty_ellipsoid(0);

	printf("Hello world \n");
	return 0;
}

#endif // uncertainty_ellipsoid_MAIN
#endif // uncertainty_ellipsoid_TEST
