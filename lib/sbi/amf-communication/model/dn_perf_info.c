#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dn_perf_info.h"

dn_perf_info_t *dn_perf_info_create(char *app_id, char *dnn, snssai_t *snssai,
                                    list_t *dn_perf, bool is_confidence,
                                    int confidence) {
	dn_perf_info_t *dn_perf_info_local_var = malloc(sizeof(dn_perf_info_t));

	dn_perf_info_local_var->app_id = app_id;
	dn_perf_info_local_var->dnn = dnn;
	dn_perf_info_local_var->snssai = snssai;
	dn_perf_info_local_var->dn_perf = dn_perf;
	dn_perf_info_local_var->is_confidence = is_confidence;
	dn_perf_info_local_var->confidence = confidence;

	return dn_perf_info_local_var;
}

void dn_perf_info_free(dn_perf_info_t *dn_perf_info) {
	lnode_t *node = NULL;

	if(NULL == dn_perf_info) {
		return;
	}
	if(dn_perf_info->app_id) {
		free(dn_perf_info->app_id);
		dn_perf_info->app_id = NULL;
	}
	if(dn_perf_info->dnn) {
		free(dn_perf_info->dnn);
		dn_perf_info->dnn = NULL;
	}
	if(dn_perf_info->snssai) {
		snssai_free(dn_perf_info->snssai);
		dn_perf_info->snssai = NULL;
	}
	if(dn_perf_info->dn_perf) {
		list_for_each(dn_perf_info->dn_perf, node) {
			dn_perf_free(node->data);
		}
		list_free(dn_perf_info->dn_perf);
		dn_perf_info->dn_perf = NULL;
	}
	free(dn_perf_info);
}

cJSON *dn_perf_info_convertToJSON(dn_perf_info_t *dn_perf_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dn_perf_info == NULL) {
		printf("dn_perf_info_convertToJSON() failed [DnPerfInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(dn_perf_info->app_id) {
		if(cJSON_AddStringToObject(item, "appId",
		                           dn_perf_info->app_id) == NULL)
		{
			printf("dn_perf_info_convertToJSON() failed [app_id]");
			goto end;
		}
	}

	if(dn_perf_info->dnn) {
		if(cJSON_AddStringToObject(item, "dnn",
		                           dn_perf_info->dnn) == NULL)
		{
			printf("dn_perf_info_convertToJSON() failed [dnn]");
			goto end;
		}
	}

	if(dn_perf_info->snssai) {
		cJSON *snssai_local_JSON = snssai_convertToJSON(
			dn_perf_info->snssai);
		if(snssai_local_JSON == NULL) {
			printf("dn_perf_info_convertToJSON() failed [snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
		if(item->child == NULL) {
			printf("dn_perf_info_convertToJSON() failed [snssai]");
			goto end;
		}
	}

	if(!dn_perf_info->dn_perf) {
		printf("dn_perf_info_convertToJSON() failed [dn_perf]");
		return NULL;
	}
	cJSON *dn_perfList = cJSON_AddArrayToObject(item, "dnPerf");
	if(dn_perfList == NULL) {
		printf("dn_perf_info_convertToJSON() failed [dn_perf]");
		goto end;
	}
	list_for_each(dn_perf_info->dn_perf, node) {
		cJSON *itemLocal = dn_perf_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf("dn_perf_info_convertToJSON() failed [dn_perf]");
			goto end;
		}
		cJSON_AddItemToArray(dn_perfList, itemLocal);
	}

	if(dn_perf_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           dn_perf_info->confidence) == NULL)
		{
			printf(
				"dn_perf_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

end:
	return item;
}

dn_perf_info_t *dn_perf_info_parseFromJSON(cJSON *dn_perf_infoJSON) {
	dn_perf_info_t *dn_perf_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *app_id = NULL;
	cJSON *dnn = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *dn_perf = NULL;
	list_t *dn_perfList = NULL;
	cJSON *confidence = NULL;
	app_id = cJSON_GetObjectItemCaseSensitive(dn_perf_infoJSON, "appId");
	if(app_id) {
		if(!cJSON_IsString(app_id) &&
		   !cJSON_IsNull(app_id))
		{
			printf("dn_perf_info_parseFromJSON() failed [app_id]");
			goto end;
		}
	}

	dnn = cJSON_GetObjectItemCaseSensitive(dn_perf_infoJSON, "dnn");
	if(dnn) {
		if(!cJSON_IsString(dnn) &&
		   !cJSON_IsNull(dnn))
		{
			printf("dn_perf_info_parseFromJSON() failed [dnn]");
			goto end;
		}
	}

	snssai = cJSON_GetObjectItemCaseSensitive(dn_perf_infoJSON, "snssai");
	if(snssai) {
		snssai_local_nonprim = snssai_parseFromJSON(snssai);
		if(!snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [snssai]");
			goto end;
		}
	}

	dn_perf = cJSON_GetObjectItemCaseSensitive(dn_perf_infoJSON, "dnPerf");
	if(!dn_perf) {
		printf("dn_perf_info_parseFromJSON() failed [dn_perf]");
		goto end;
	}
	cJSON *dn_perf_local = NULL;
	if(!cJSON_IsArray(dn_perf)) {
		printf("dn_perf_info_parseFromJSON() failed [dn_perf]");
		goto end;
	}

	dn_perfList = list_create();

	cJSON_ArrayForEach(dn_perf_local, dn_perf) {
		if(!cJSON_IsObject(dn_perf_local)) {
			printf("dn_perf_info_parseFromJSON() failed [dn_perf]");
			goto end;
		}
		dn_perf_t *dn_perfItem = dn_perf_parseFromJSON(dn_perf_local);
		if(!dn_perfItem) {
			printf("No dn_perfItem");
			goto end;
		}
		list_add(dn_perfList, dn_perfItem);
	}

	confidence = cJSON_GetObjectItemCaseSensitive(dn_perf_infoJSON,
	                                              "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"dn_perf_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	dn_perf_info_local_var = dn_perf_info_create(
		app_id &&
		!cJSON_IsNull(app_id) ? strdup(app_id->valuestring) : NULL,
		dnn &&
		!cJSON_IsNull(dnn) ? strdup(dnn->valuestring) : NULL,
		snssai ? snssai_local_nonprim : NULL,
		dn_perfList,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0
		);

	return dn_perf_info_local_var;
end:
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(dn_perfList) {
		list_for_each(dn_perfList, node) {
			dn_perf_free(node->data);
		}
		list_free(dn_perfList);
		dn_perfList = NULL;
	}
	return NULL;
}

dn_perf_info_t *dn_perf_info_copy(dn_perf_info_t *dst, dn_perf_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dn_perf_info_convertToJSON(src);
	if(!item) {
		printf("dn_perf_info_convertToJSON() failed");
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

	dn_perf_info_free(dst);
	dst = dn_perf_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
