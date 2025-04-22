#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "analytics_metadata.h"

analytics_metadata_t *analytics_metadata_create() {
	analytics_metadata_t *analytics_metadata_local_var =
		malloc(sizeof(analytics_metadata_t));


	return analytics_metadata_local_var;
}

void analytics_metadata_free(analytics_metadata_t *analytics_metadata) {
	lnode_t *node = NULL;

	if(NULL == analytics_metadata) {
		return;
	}
	free(analytics_metadata);
}

cJSON *analytics_metadata_convertToJSON(
	analytics_metadata_t *analytics_metadata) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(analytics_metadata == NULL) {
		printf(
			"analytics_metadata_convertToJSON() failed [AnalyticsMetadata]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

analytics_metadata_t *analytics_metadata_parseFromJSON(
	cJSON *analytics_metadataJSON) {
	analytics_metadata_t *analytics_metadata_local_var = NULL;
	lnode_t *node = NULL;
	analytics_metadata_local_var = analytics_metadata_create(
		);

	return analytics_metadata_local_var;
end:
	return NULL;
}

analytics_metadata_t *analytics_metadata_copy(analytics_metadata_t	*dst,
                                              analytics_metadata_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = analytics_metadata_convertToJSON(src);
	if(!item) {
		printf("analytics_metadata_convertToJSON() failed");
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

	analytics_metadata_free(dst);
	dst = analytics_metadata_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
