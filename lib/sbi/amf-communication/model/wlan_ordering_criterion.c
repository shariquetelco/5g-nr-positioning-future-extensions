#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wlan_ordering_criterion.h"

wlan_ordering_criterion_t *wlan_ordering_criterion_create() {
	wlan_ordering_criterion_t *wlan_ordering_criterion_local_var = malloc(
		sizeof(wlan_ordering_criterion_t));


	return wlan_ordering_criterion_local_var;
}

void wlan_ordering_criterion_free(
	wlan_ordering_criterion_t *wlan_ordering_criterion) {
	lnode_t *node = NULL;

	if(NULL == wlan_ordering_criterion) {
		return;
	}
	free(wlan_ordering_criterion);
}

cJSON *wlan_ordering_criterion_convertToJSON(
	wlan_ordering_criterion_t *wlan_ordering_criterion) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(wlan_ordering_criterion == NULL) {
		printf(
			"wlan_ordering_criterion_convertToJSON() failed [WlanOrderingCriterion]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

wlan_ordering_criterion_t *wlan_ordering_criterion_parseFromJSON(
	cJSON *wlan_ordering_criterionJSON) {
	wlan_ordering_criterion_t *wlan_ordering_criterion_local_var = NULL;
	lnode_t *node = NULL;
	wlan_ordering_criterion_local_var = wlan_ordering_criterion_create(
		);

	return wlan_ordering_criterion_local_var;
end:
	return NULL;
}

wlan_ordering_criterion_t *wlan_ordering_criterion_copy(
	wlan_ordering_criterion_t *dst, wlan_ordering_criterion_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = wlan_ordering_criterion_convertToJSON(src);
	if(!item) {
		printf("wlan_ordering_criterion_convertToJSON() failed");
		return NULL;
	}

	content = cJSON_Print(item);
	cJSON_Delete(item);

	if(!content) {
		printf("cJSON_Print() failed");
		return NULL;
	}

	item = cJSON_Parse(content);
	free(content);
	if(!item) {
		printf("cJSON_Parse() failed");
		return NULL;
	}

	wlan_ordering_criterion_free(dst);
	dst = wlan_ordering_criterion_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
