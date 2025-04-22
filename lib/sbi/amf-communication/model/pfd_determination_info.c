#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pfd_determination_info.h"

pfd_determination_info_t *pfd_determination_info_create(char		*app_id,
                                                        snssai_t	*snssai,
                                                        char		*dnn,
                                                        list_t		*sugg_pfd_info_list)
{
	pfd_determination_info_t *pfd_determination_info_local_var = malloc(
		sizeof(pfd_determination_info_t));

	pfd_determination_info_local_var->app_id = app_id;
	pfd_determination_info_local_var->snssai = snssai;
	pfd_determination_info_local_var->dnn = dnn;
	pfd_determination_info_local_var->sugg_pfd_info_list =
		sugg_pfd_info_list;

	return pfd_determination_info_local_var;
}

void pfd_determination_info_free(
	pfd_determination_info_t *pfd_determination_info) {
	lnode_t *node = NULL;

	if(NULL == pfd_determination_info) {
		return;
	}
	if(pfd_determination_info->app_id) {
		free(pfd_determination_info->app_id);
		pfd_determination_info->app_id = NULL;
	}
	if(pfd_determination_info->snssai) {
		snssai_free(pfd_determination_info->snssai);
		pfd_determination_info->snssai = NULL;
	}
	if(pfd_determination_info->dnn) {
		free(pfd_determination_info->dnn);
		pfd_determination_info->dnn = NULL;
	}
	if(pfd_determination_info->sugg_pfd_info_list) {
		list_for_each(pfd_determination_info->sugg_pfd_info_list,
		              node) {
			suggested_pfd_info_free(node->data);
		}
		list_free(pfd_determination_info->sugg_pfd_info_list);
		pfd_determination_info->sugg_pfd_info_list = NULL;
	}
	free(pfd_determination_info);
}

cJSON *pfd_determination_info_convertToJSON(
	pfd_determination_info_t *pfd_determination_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pfd_determination_info == NULL) {
		printf(
			"pfd_determination_info_convertToJSON() failed [PfdDeterminationInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!pfd_determination_info->app_id) {
		printf("pfd_determination_info_convertToJSON() failed [app_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "appId",
	                           pfd_determination_info->app_id) == NULL)
	{
		printf("pfd_determination_info_convertToJSON() failed [app_id]");
		goto end;
	}

	if(pfd_determination_info->snssai) {
		cJSON *snssai_local_JSON = snssai_convertToJSON(
			pfd_determination_info->snssai);
		if(snssai_local_JSON == NULL) {
			printf(
				"pfd_determination_info_convertToJSON() failed [snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"pfd_determination_info_convertToJSON() failed [snssai]");
			goto end;
		}
	}

	if(pfd_determination_info->dnn) {
		if(cJSON_AddStringToObject(item, "dnn",
		                           pfd_determination_info->dnn) == NULL)
		{
			printf(
				"pfd_determination_info_convertToJSON() failed [dnn]");
			goto end;
		}
	}

	if(!pfd_determination_info->sugg_pfd_info_list) {
		printf(
			"pfd_determination_info_convertToJSON() failed [sugg_pfd_info_list]");
		return NULL;
	}
	cJSON *sugg_pfd_info_listList = cJSON_AddArrayToObject(item,
	                                                       "suggPfdInfoList");
	if(sugg_pfd_info_listList == NULL) {
		printf(
			"pfd_determination_info_convertToJSON() failed [sugg_pfd_info_list]");
		goto end;
	}
	list_for_each(pfd_determination_info->sugg_pfd_info_list, node) {
		cJSON *itemLocal = suggested_pfd_info_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"pfd_determination_info_convertToJSON() failed [sugg_pfd_info_list]");
			goto end;
		}
		cJSON_AddItemToArray(sugg_pfd_info_listList, itemLocal);
	}

end:
	return item;
}

pfd_determination_info_t *pfd_determination_info_parseFromJSON(
	cJSON *pfd_determination_infoJSON) {
	pfd_determination_info_t *pfd_determination_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *app_id = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *dnn = NULL;
	cJSON *sugg_pfd_info_list = NULL;
	list_t *sugg_pfd_info_listList = NULL;
	app_id = cJSON_GetObjectItemCaseSensitive(pfd_determination_infoJSON,
	                                          "appId");
	if(!app_id) {
		printf("pfd_determination_info_parseFromJSON() failed [app_id]");
		goto end;
	}
	if(!cJSON_IsString(app_id)) {
		printf("pfd_determination_info_parseFromJSON() failed [app_id]");
		goto end;
	}

	snssai = cJSON_GetObjectItemCaseSensitive(pfd_determination_infoJSON,
	                                          "snssai");
	if(snssai) {
		snssai_local_nonprim = snssai_parseFromJSON(snssai);
		if(!snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [snssai]");
			goto end;
		}
	}

	dnn =
		cJSON_GetObjectItemCaseSensitive(pfd_determination_infoJSON,
		                                 "dnn");
	if(dnn) {
		if(!cJSON_IsString(dnn) &&
		   !cJSON_IsNull(dnn))
		{
			printf(
				"pfd_determination_info_parseFromJSON() failed [dnn]");
			goto end;
		}
	}

	sugg_pfd_info_list = cJSON_GetObjectItemCaseSensitive(
		pfd_determination_infoJSON, "suggPfdInfoList");
	if(!sugg_pfd_info_list) {
		printf(
			"pfd_determination_info_parseFromJSON() failed [sugg_pfd_info_list]");
		goto end;
	}
	cJSON *sugg_pfd_info_list_local = NULL;
	if(!cJSON_IsArray(sugg_pfd_info_list)) {
		printf(
			"pfd_determination_info_parseFromJSON() failed [sugg_pfd_info_list]");
		goto end;
	}

	sugg_pfd_info_listList = list_create();

	cJSON_ArrayForEach(sugg_pfd_info_list_local, sugg_pfd_info_list) {
		if(!cJSON_IsObject(sugg_pfd_info_list_local)) {
			printf(
				"pfd_determination_info_parseFromJSON() failed [sugg_pfd_info_list]");
			goto end;
		}
		suggested_pfd_info_t *sugg_pfd_info_listItem =
			suggested_pfd_info_parseFromJSON(
				sugg_pfd_info_list_local);
		if(!sugg_pfd_info_listItem) {
			printf("No sugg_pfd_info_listItem");
			goto end;
		}
		list_add(sugg_pfd_info_listList, sugg_pfd_info_listItem);
	}

	pfd_determination_info_local_var = pfd_determination_info_create(
		strdup(app_id->valuestring),
		snssai ? snssai_local_nonprim : NULL,
		dnn &&
		!cJSON_IsNull(dnn) ? strdup(dnn->valuestring) : NULL,
		sugg_pfd_info_listList
		);

	return pfd_determination_info_local_var;
end:
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(sugg_pfd_info_listList) {
		list_for_each(sugg_pfd_info_listList, node) {
			suggested_pfd_info_free(node->data);
		}
		list_free(sugg_pfd_info_listList);
		sugg_pfd_info_listList = NULL;
	}
	return NULL;
}

pfd_determination_info_t *pfd_determination_info_copy(
	pfd_determination_info_t *dst, pfd_determination_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pfd_determination_info_convertToJSON(src);
	if(!item) {
		printf("pfd_determination_info_convertToJSON() failed");
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

	pfd_determination_info_free(dst);
	dst = pfd_determination_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
