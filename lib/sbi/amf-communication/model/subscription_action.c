#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subscription_action.h"

subscription_action_t *subscription_action_create() {
	subscription_action_t *subscription_action_local_var =
		malloc(sizeof(subscription_action_t));


	return subscription_action_local_var;
}

void subscription_action_free(subscription_action_t *subscription_action) {
	lnode_t *node = NULL;

	if(NULL == subscription_action) {
		return;
	}
	free(subscription_action);
}

cJSON *subscription_action_convertToJSON(
	subscription_action_t *subscription_action) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(subscription_action == NULL) {
		printf(
			"subscription_action_convertToJSON() failed [SubscriptionAction]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

subscription_action_t *subscription_action_parseFromJSON(
	cJSON *subscription_actionJSON) {
	subscription_action_t *subscription_action_local_var = NULL;
	lnode_t *node = NULL;
	subscription_action_local_var = subscription_action_create(
		);

	return subscription_action_local_var;
end:
	return NULL;
}

subscription_action_t *subscription_action_copy(subscription_action_t	*dst,
                                                subscription_action_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = subscription_action_convertToJSON(src);
	if(!item) {
		printf("subscription_action_convertToJSON() failed");
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

	subscription_action_free(dst);
	dst = subscription_action_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
