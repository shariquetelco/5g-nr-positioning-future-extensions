#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subscription_data.h"

subscription_data_t *subscription_data_create(char	*amf_status_uri,
                                              list_t	*guami_list) {
	subscription_data_t *subscription_data_local_var =
		malloc(sizeof(subscription_data_t));

	subscription_data_local_var->amf_status_uri = amf_status_uri;
	subscription_data_local_var->guami_list = guami_list;

	return subscription_data_local_var;
}

void subscription_data_free(subscription_data_t *subscription_data) {
	lnode_t *node = NULL;

	if(NULL == subscription_data) {
		return;
	}
	if(subscription_data->amf_status_uri) {
		free(subscription_data->amf_status_uri);
		subscription_data->amf_status_uri = NULL;
	}
	if(subscription_data->guami_list) {
		list_for_each(subscription_data->guami_list, node) {
			guami_free(node->data);
		}
		list_free(subscription_data->guami_list);
		subscription_data->guami_list = NULL;
	}
	free(subscription_data);
}

cJSON *subscription_data_convertToJSON(subscription_data_t *subscription_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(subscription_data == NULL) {
		printf(
			"subscription_data_convertToJSON() failed [SubscriptionData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!subscription_data->amf_status_uri) {
		printf(
			"subscription_data_convertToJSON() failed [amf_status_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "amfStatusUri",
	                           subscription_data->amf_status_uri) == NULL)
	{
		printf(
			"subscription_data_convertToJSON() failed [amf_status_uri]");
		goto end;
	}

	if(subscription_data->guami_list) {
		cJSON *guami_listList =
			cJSON_AddArrayToObject(item, "guamiList");
		if(guami_listList == NULL) {
			printf(
				"subscription_data_convertToJSON() failed [guami_list]");
			goto end;
		}
		list_for_each(subscription_data->guami_list, node) {
			cJSON *itemLocal = guami_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"subscription_data_convertToJSON() failed [guami_list]");
				goto end;
			}
			cJSON_AddItemToArray(guami_listList, itemLocal);
		}
	}

end:
	return item;
}

subscription_data_t *subscription_data_parseFromJSON(
	cJSON *subscription_dataJSON) {
	subscription_data_t *subscription_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *amf_status_uri = NULL;
	cJSON *guami_list = NULL;
	list_t *guami_listList = NULL;
	amf_status_uri = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON,
	                                                  "amfStatusUri");
	if(!amf_status_uri) {
		printf(
			"subscription_data_parseFromJSON() failed [amf_status_uri]");
		goto end;
	}
	if(!cJSON_IsString(amf_status_uri)) {
		printf(
			"subscription_data_parseFromJSON() failed [amf_status_uri]");
		goto end;
	}

	guami_list = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON,
	                                              "guamiList");
	if(guami_list) {
		cJSON *guami_list_local = NULL;
		if(!cJSON_IsArray(guami_list)) {
			printf(
				"subscription_data_parseFromJSON() failed [guami_list]");
			goto end;
		}

		guami_listList = list_create();

		cJSON_ArrayForEach(guami_list_local, guami_list) {
			if(!cJSON_IsObject(guami_list_local)) {
				printf(
					"subscription_data_parseFromJSON() failed [guami_list]");
				goto end;
			}
			guami_t *guami_listItem = guami_parseFromJSON(
				guami_list_local);
			if(!guami_listItem) {
				printf("No guami_listItem");
				goto end;
			}
			list_add(guami_listList, guami_listItem);
		}
	}

	subscription_data_local_var = subscription_data_create(
		strdup(amf_status_uri->valuestring),
		guami_list ? guami_listList : NULL
		);

	return subscription_data_local_var;
end:
	if(guami_listList) {
		list_for_each(guami_listList, node) {
			guami_free(node->data);
		}
		list_free(guami_listList);
		guami_listList = NULL;
	}
	return NULL;
}

subscription_data_t *subscription_data_copy(subscription_data_t *dst,
                                            subscription_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = subscription_data_convertToJSON(src);
	if(!item) {
		printf("subscription_data_convertToJSON() failed");
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

	subscription_data_free(dst);
	dst = subscription_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
