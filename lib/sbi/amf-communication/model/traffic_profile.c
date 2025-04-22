#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "traffic_profile.h"

traffic_profile_t *traffic_profile_create() {
	traffic_profile_t *traffic_profile_local_var =
		malloc(sizeof(traffic_profile_t));


	return traffic_profile_local_var;
}

void traffic_profile_free(traffic_profile_t *traffic_profile) {
	lnode_t *node = NULL;

	if(NULL == traffic_profile) {
		return;
	}
	free(traffic_profile);
}

cJSON *traffic_profile_convertToJSON(traffic_profile_t *traffic_profile) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(traffic_profile == NULL) {
		printf("traffic_profile_convertToJSON() failed [TrafficProfile]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

traffic_profile_t *traffic_profile_parseFromJSON(cJSON *traffic_profileJSON) {
	traffic_profile_t *traffic_profile_local_var = NULL;
	lnode_t *node = NULL;
	traffic_profile_local_var = traffic_profile_create(
		);

	return traffic_profile_local_var;
end:
	return NULL;
}

traffic_profile_t *traffic_profile_copy(traffic_profile_t	*dst,
                                        traffic_profile_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = traffic_profile_convertToJSON(src);
	if(!item) {
		printf("traffic_profile_convertToJSON() failed");
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

	traffic_profile_free(dst);
	dst = traffic_profile_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
