#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "analytics_subscription.h"

analytics_subscription_t *analytics_subscription_create(char	*nwdaf_id,
                                                        char	*nwdaf_set_id,
                                                        list_t	*nwdaf_subscription_list)
{
	analytics_subscription_t *analytics_subscription_local_var = malloc(
		sizeof(analytics_subscription_t));

	analytics_subscription_local_var->nwdaf_id = nwdaf_id;
	analytics_subscription_local_var->nwdaf_set_id = nwdaf_set_id;
	analytics_subscription_local_var->nwdaf_subscription_list =
		nwdaf_subscription_list;

	return analytics_subscription_local_var;
}

void analytics_subscription_free(
	analytics_subscription_t *analytics_subscription) {
	lnode_t *node = NULL;

	if(NULL == analytics_subscription) {
		return;
	}
	if(analytics_subscription->nwdaf_id) {
		free(analytics_subscription->nwdaf_id);
		analytics_subscription->nwdaf_id = NULL;
	}
	if(analytics_subscription->nwdaf_set_id) {
		free(analytics_subscription->nwdaf_set_id);
		analytics_subscription->nwdaf_set_id = NULL;
	}
	if(analytics_subscription->nwdaf_subscription_list) {
		list_for_each(analytics_subscription->nwdaf_subscription_list,
		              node) {
			nwdaf_subscription_free(node->data);
		}
		list_free(analytics_subscription->nwdaf_subscription_list);
		analytics_subscription->nwdaf_subscription_list = NULL;
	}
	free(analytics_subscription);
}

cJSON *analytics_subscription_convertToJSON(
	analytics_subscription_t *analytics_subscription) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(analytics_subscription == NULL) {
		printf(
			"analytics_subscription_convertToJSON() failed [AnalyticsSubscription]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(analytics_subscription->nwdaf_id) {
		if(cJSON_AddStringToObject(item, "nwdafId",
		                           analytics_subscription->nwdaf_id) ==
		   NULL)
		{
			printf(
				"analytics_subscription_convertToJSON() failed [nwdaf_id]");
			goto end;
		}
	}

	if(analytics_subscription->nwdaf_set_id) {
		if(cJSON_AddStringToObject(item, "nwdafSetId",
		                           analytics_subscription->nwdaf_set_id)
		   == NULL)
		{
			printf(
				"analytics_subscription_convertToJSON() failed [nwdaf_set_id]");
			goto end;
		}
	}

	if(!analytics_subscription->nwdaf_subscription_list) {
		printf(
			"analytics_subscription_convertToJSON() failed [nwdaf_subscription_list]");
		return NULL;
	}
	cJSON *nwdaf_subscription_listList = cJSON_AddArrayToObject(item,
	                                                            "nwdafSubscriptionList");
	if(nwdaf_subscription_listList == NULL) {
		printf(
			"analytics_subscription_convertToJSON() failed [nwdaf_subscription_list]");
		goto end;
	}
	list_for_each(analytics_subscription->nwdaf_subscription_list, node) {
		cJSON *itemLocal = nwdaf_subscription_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"analytics_subscription_convertToJSON() failed [nwdaf_subscription_list]");
			goto end;
		}
		cJSON_AddItemToArray(nwdaf_subscription_listList, itemLocal);
	}

end:
	return item;
}

analytics_subscription_t *analytics_subscription_parseFromJSON(
	cJSON *analytics_subscriptionJSON) {
	analytics_subscription_t *analytics_subscription_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *nwdaf_id = NULL;
	cJSON *nwdaf_set_id = NULL;
	cJSON *nwdaf_subscription_list = NULL;
	list_t *nwdaf_subscription_listList = NULL;
	nwdaf_id = cJSON_GetObjectItemCaseSensitive(analytics_subscriptionJSON,
	                                            "nwdafId");
	if(nwdaf_id) {
		if(!cJSON_IsString(nwdaf_id) &&
		   !cJSON_IsNull(nwdaf_id))
		{
			printf(
				"analytics_subscription_parseFromJSON() failed [nwdaf_id]");
			goto end;
		}
	}

	nwdaf_set_id = cJSON_GetObjectItemCaseSensitive(
		analytics_subscriptionJSON, "nwdafSetId");
	if(nwdaf_set_id) {
		if(!cJSON_IsString(nwdaf_set_id) &&
		   !cJSON_IsNull(nwdaf_set_id))
		{
			printf(
				"analytics_subscription_parseFromJSON() failed [nwdaf_set_id]");
			goto end;
		}
	}

	nwdaf_subscription_list = cJSON_GetObjectItemCaseSensitive(
		analytics_subscriptionJSON, "nwdafSubscriptionList");
	if(!nwdaf_subscription_list) {
		printf(
			"analytics_subscription_parseFromJSON() failed [nwdaf_subscription_list]");
		goto end;
	}
	cJSON *nwdaf_subscription_list_local = NULL;
	if(!cJSON_IsArray(nwdaf_subscription_list)) {
		printf(
			"analytics_subscription_parseFromJSON() failed [nwdaf_subscription_list]");
		goto end;
	}

	nwdaf_subscription_listList = list_create();

	cJSON_ArrayForEach(nwdaf_subscription_list_local,
	                   nwdaf_subscription_list) {
		if(!cJSON_IsObject(nwdaf_subscription_list_local)) {
			printf(
				"analytics_subscription_parseFromJSON() failed [nwdaf_subscription_list]");
			goto end;
		}
		nwdaf_subscription_t *nwdaf_subscription_listItem =
			nwdaf_subscription_parseFromJSON(
				nwdaf_subscription_list_local);
		if(!nwdaf_subscription_listItem) {
			printf("No nwdaf_subscription_listItem");
			goto end;
		}
		list_add(nwdaf_subscription_listList,
		         nwdaf_subscription_listItem);
	}

	analytics_subscription_local_var = analytics_subscription_create(
		nwdaf_id &&
		!cJSON_IsNull(nwdaf_id) ? strdup(nwdaf_id->valuestring) : NULL,
		nwdaf_set_id &&
		!cJSON_IsNull(nwdaf_set_id) ? strdup(
			nwdaf_set_id->valuestring) : NULL,
		nwdaf_subscription_listList
		);

	return analytics_subscription_local_var;
end:
	if(nwdaf_subscription_listList) {
		list_for_each(nwdaf_subscription_listList, node) {
			nwdaf_subscription_free(node->data);
		}
		list_free(nwdaf_subscription_listList);
		nwdaf_subscription_listList = NULL;
	}
	return NULL;
}

analytics_subscription_t *analytics_subscription_copy(
	analytics_subscription_t *dst, analytics_subscription_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = analytics_subscription_convertToJSON(src);
	if(!item) {
		printf("analytics_subscription_convertToJSON() failed");
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

	analytics_subscription_free(dst);
	dst = analytics_subscription_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
