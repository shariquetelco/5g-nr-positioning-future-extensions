#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "analytics_subset.h"

analytics_subset_t *analytics_subset_create() {
	analytics_subset_t *analytics_subset_local_var =
		malloc(sizeof(analytics_subset_t));


	return analytics_subset_local_var;
}

void analytics_subset_free(analytics_subset_t *analytics_subset) {
	lnode_t *node = NULL;

	if(NULL == analytics_subset) {
		return;
	}
	free(analytics_subset);
}

cJSON *analytics_subset_convertToJSON(analytics_subset_t *analytics_subset) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(analytics_subset == NULL) {
		printf(
			"analytics_subset_convertToJSON() failed [AnalyticsSubset]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

analytics_subset_t *analytics_subset_parseFromJSON(cJSON *analytics_subsetJSON)
{
	analytics_subset_t *analytics_subset_local_var = NULL;
	lnode_t *node = NULL;
	analytics_subset_local_var = analytics_subset_create(
		);

	return analytics_subset_local_var;
end:
	return NULL;
}

analytics_subset_t *analytics_subset_copy(analytics_subset_t	*dst,
                                          analytics_subset_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = analytics_subset_convertToJSON(src);
	if(!item) {
		printf("analytics_subset_convertToJSON() failed");
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

	analytics_subset_free(dst);
	dst = analytics_subset_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
