#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "consumer_nf_information.h"

consumer_nf_information_t *consumer_nf_information_create(char		*nf_id,
                                                          char		*nf_set_id,
                                                          list_t	*tai_list)
{
	consumer_nf_information_t *consumer_nf_information_local_var = malloc(
		sizeof(consumer_nf_information_t));

	consumer_nf_information_local_var->nf_id = nf_id;
	consumer_nf_information_local_var->nf_set_id = nf_set_id;
	consumer_nf_information_local_var->tai_list = tai_list;

	return consumer_nf_information_local_var;
}

void consumer_nf_information_free(
	consumer_nf_information_t *consumer_nf_information) {
	lnode_t *node = NULL;

	if(NULL == consumer_nf_information) {
		return;
	}
	if(consumer_nf_information->nf_id) {
		free(consumer_nf_information->nf_id);
		consumer_nf_information->nf_id = NULL;
	}
	if(consumer_nf_information->nf_set_id) {
		free(consumer_nf_information->nf_set_id);
		consumer_nf_information->nf_set_id = NULL;
	}
	if(consumer_nf_information->tai_list) {
		list_for_each(consumer_nf_information->tai_list, node) {
			tai_free(node->data);
		}
		list_free(consumer_nf_information->tai_list);
		consumer_nf_information->tai_list = NULL;
	}
	free(consumer_nf_information);
}

cJSON *consumer_nf_information_convertToJSON(
	consumer_nf_information_t *consumer_nf_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(consumer_nf_information == NULL) {
		printf(
			"consumer_nf_information_convertToJSON() failed [ConsumerNfInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(consumer_nf_information->nf_id) {
		if(cJSON_AddStringToObject(item, "nfId",
		                           consumer_nf_information->nf_id) ==
		   NULL)
		{
			printf(
				"consumer_nf_information_convertToJSON() failed [nf_id]");
			goto end;
		}
	}

	if(consumer_nf_information->nf_set_id) {
		if(cJSON_AddStringToObject(item, "nfSetId",
		                           consumer_nf_information->nf_set_id)
		   == NULL)
		{
			printf(
				"consumer_nf_information_convertToJSON() failed [nf_set_id]");
			goto end;
		}
	}

	if(consumer_nf_information->tai_list) {
		cJSON *tai_listList = cJSON_AddArrayToObject(item, "taiList");
		if(tai_listList == NULL) {
			printf(
				"consumer_nf_information_convertToJSON() failed [tai_list]");
			goto end;
		}
		list_for_each(consumer_nf_information->tai_list, node) {
			cJSON *itemLocal = tai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"consumer_nf_information_convertToJSON() failed [tai_list]");
				goto end;
			}
			cJSON_AddItemToArray(tai_listList, itemLocal);
		}
	}

end:
	return item;
}

consumer_nf_information_t *consumer_nf_information_parseFromJSON(
	cJSON *consumer_nf_informationJSON) {
	consumer_nf_information_t *consumer_nf_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *nf_id = NULL;
	cJSON *nf_set_id = NULL;
	cJSON *tai_list = NULL;
	list_t *tai_listList = NULL;
	nf_id = cJSON_GetObjectItemCaseSensitive(consumer_nf_informationJSON,
	                                         "nfId");
	if(nf_id) {
		if(!cJSON_IsString(nf_id) &&
		   !cJSON_IsNull(nf_id))
		{
			printf(
				"consumer_nf_information_parseFromJSON() failed [nf_id]");
			goto end;
		}
	}

	nf_set_id = cJSON_GetObjectItemCaseSensitive(
		consumer_nf_informationJSON, "nfSetId");
	if(nf_set_id) {
		if(!cJSON_IsString(nf_set_id) &&
		   !cJSON_IsNull(nf_set_id))
		{
			printf(
				"consumer_nf_information_parseFromJSON() failed [nf_set_id]");
			goto end;
		}
	}

	tai_list = cJSON_GetObjectItemCaseSensitive(consumer_nf_informationJSON,
	                                            "taiList");
	if(tai_list) {
		cJSON *tai_list_local = NULL;
		if(!cJSON_IsArray(tai_list)) {
			printf(
				"consumer_nf_information_parseFromJSON() failed [tai_list]");
			goto end;
		}

		tai_listList = list_create();

		cJSON_ArrayForEach(tai_list_local, tai_list) {
			if(!cJSON_IsObject(tai_list_local)) {
				printf(
					"consumer_nf_information_parseFromJSON() failed [tai_list]");
				goto end;
			}
			tai_t *tai_listItem = tai_parseFromJSON(tai_list_local);
			if(!tai_listItem) {
				printf("No tai_listItem");
				goto end;
			}
			list_add(tai_listList, tai_listItem);
		}
	}

	consumer_nf_information_local_var = consumer_nf_information_create(
		nf_id &&
		!cJSON_IsNull(nf_id) ? strdup(nf_id->valuestring) : NULL,
		nf_set_id &&
		!cJSON_IsNull(nf_set_id) ? strdup(
			nf_set_id->valuestring) : NULL,
		tai_list ? tai_listList : NULL
		);

	return consumer_nf_information_local_var;
end:
	if(tai_listList) {
		list_for_each(tai_listList, node) {
			tai_free(node->data);
		}
		list_free(tai_listList);
		tai_listList = NULL;
	}
	return NULL;
}

consumer_nf_information_t *consumer_nf_information_copy(
	consumer_nf_information_t *dst, consumer_nf_information_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = consumer_nf_information_convertToJSON(src);
	if(!item) {
		printf("consumer_nf_information_convertToJSON() failed");
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

	consumer_nf_information_free(dst);
	dst = consumer_nf_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
