#ifndef high_accuracy_gnss_metrics_TEST
#define high_accuracy_gnss_metrics_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define high_accuracy_gnss_metrics_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/high_accuracy_gnss_metrics.h"
high_accuracy_gnss_metrics_t *instantiate_high_accuracy_gnss_metrics(
	int include_optional);



high_accuracy_gnss_metrics_t *instantiate_high_accuracy_gnss_metrics(
	int include_optional) {
	high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics = NULL;
	if(include_optional) {
		high_accuracy_gnss_metrics = high_accuracy_gnss_metrics_create(
			0,
			1,
			1,
			0,
			lmf_location_high_accuracy_gnss_metrics__CARRIER_PHASE_FLOAT
			);
	} else {
		high_accuracy_gnss_metrics = high_accuracy_gnss_metrics_create(
			0,
			1,
			1,
			0,
			lmf_location_high_accuracy_gnss_metrics__CARRIER_PHASE_FLOAT
			);
	}

	return high_accuracy_gnss_metrics;
}


#ifdef high_accuracy_gnss_metrics_MAIN

void test_high_accuracy_gnss_metrics(int include_optional) {
	high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_1 =
		instantiate_high_accuracy_gnss_metrics(include_optional);

	cJSON *jsonhigh_accuracy_gnss_metrics_1 =
		high_accuracy_gnss_metrics_convertToJSON(
			high_accuracy_gnss_metrics_1);
	printf("high_accuracy_gnss_metrics :\n%s\n",
	       cJSON_Print(jsonhigh_accuracy_gnss_metrics_1));
	high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_2 =
		high_accuracy_gnss_metrics_parseFromJSON(
			jsonhigh_accuracy_gnss_metrics_1);
	cJSON *jsonhigh_accuracy_gnss_metrics_2 =
		high_accuracy_gnss_metrics_convertToJSON(
			high_accuracy_gnss_metrics_2);
	printf("repeating high_accuracy_gnss_metrics:\n%s\n",
	       cJSON_Print(jsonhigh_accuracy_gnss_metrics_2));
}

int main() {
	test_high_accuracy_gnss_metrics(1);
	test_high_accuracy_gnss_metrics(0);

	printf("Hello world \n");
	return 0;
}

#endif // high_accuracy_gnss_metrics_MAIN
#endif // high_accuracy_gnss_metrics_TEST
