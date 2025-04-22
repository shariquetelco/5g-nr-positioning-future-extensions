#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "congestion_info.h"

congestion_info_t *congestion_info_create(congestion_type_t *cong_type,
                                          time_window_t *time_intev,
                                          threshold_level_t *nsi,
                                          bool is_confidence, int confidence,
                                          list_t *top_app_list_ul,
                                          list_t *top_app_list_dl) {
	congestion_info_t *congestion_info_local_var =
		malloc(sizeof(congestion_info_t));

	congestion_info_local_var->cong_type = cong_type;
	congestion_info_local_var->time_intev = time_intev;
	congestion_info_local_var->nsi = nsi;
	congestion_info_local_var->is_confidence = is_confidence;
	congestion_info_local_var->confidence = confidence;
	congestion_info_local_var->top_app_list_ul = top_app_list_ul;
	congestion_info_local_var->top_app_list_dl = top_app_list_dl;

	return congestion_info_local_var;
}

void congestion_info_free(congestion_info_t *congestion_info) {
	lnode_t *node = NULL;

	if(NULL == congestion_info) {
		return;
	}
	if(congestion_info->cong_type) {
		congestion_type_free(congestion_info->cong_type);
		congestion_info->cong_type = NULL;
	}
	if(congestion_info->time_intev) {
		time_window_free(congestion_info->time_intev);
		congestion_info->time_intev = NULL;
	}
	if(congestion_info->nsi) {
		threshold_level_free(congestion_info->nsi);
		congestion_info->nsi = NULL;
	}
	if(congestion_info->top_app_list_ul) {
		list_for_each(congestion_info->top_app_list_ul, node) {
			top_application_free(node->data);
		}
		list_free(congestion_info->top_app_list_ul);
		congestion_info->top_app_list_ul = NULL;
	}
	if(congestion_info->top_app_list_dl) {
		list_for_each(congestion_info->top_app_list_dl, node) {
			top_application_free(node->data);
		}
		list_free(congestion_info->top_app_list_dl);
		congestion_info->top_app_list_dl = NULL;
	}
	free(congestion_info);
}

cJSON *congestion_info_convertToJSON(congestion_info_t *congestion_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(congestion_info == NULL) {
		printf("congestion_info_convertToJSON() failed [CongestionInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!congestion_info->cong_type) {
		printf("congestion_info_convertToJSON() failed [cong_type]");
		return NULL;
	}
	cJSON *cong_type_local_JSON = congestion_type_convertToJSON(
		congestion_info->cong_type);
	if(cong_type_local_JSON == NULL) {
		printf("congestion_info_convertToJSON() failed [cong_type]");
		goto end;
	}
	cJSON_AddItemToObject(item, "congType", cong_type_local_JSON);
	if(item->child == NULL) {
		printf("congestion_info_convertToJSON() failed [cong_type]");
		goto end;
	}

	if(!congestion_info->time_intev) {
		printf("congestion_info_convertToJSON() failed [time_intev]");
		return NULL;
	}
	cJSON *time_intev_local_JSON = time_window_convertToJSON(
		congestion_info->time_intev);
	if(time_intev_local_JSON == NULL) {
		printf("congestion_info_convertToJSON() failed [time_intev]");
		goto end;
	}
	cJSON_AddItemToObject(item, "timeIntev", time_intev_local_JSON);
	if(item->child == NULL) {
		printf("congestion_info_convertToJSON() failed [time_intev]");
		goto end;
	}

	if(!congestion_info->nsi) {
		printf("congestion_info_convertToJSON() failed [nsi]");
		return NULL;
	}
	cJSON *nsi_local_JSON = threshold_level_convertToJSON(
		congestion_info->nsi);
	if(nsi_local_JSON == NULL) {
		printf("congestion_info_convertToJSON() failed [nsi]");
		goto end;
	}
	cJSON_AddItemToObject(item, "nsi", nsi_local_JSON);
	if(item->child == NULL) {
		printf("congestion_info_convertToJSON() failed [nsi]");
		goto end;
	}

	if(congestion_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           congestion_info->confidence) == NULL)
		{
			printf(
				"congestion_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

	if(congestion_info->top_app_list_ul) {
		cJSON *top_app_list_ulList = cJSON_AddArrayToObject(item,
		                                                    "topAppListUl");
		if(top_app_list_ulList == NULL) {
			printf(
				"congestion_info_convertToJSON() failed [top_app_list_ul]");
			goto end;
		}
		list_for_each(congestion_info->top_app_list_ul, node) {
			cJSON *itemLocal = top_application_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"congestion_info_convertToJSON() failed [top_app_list_ul]");
				goto end;
			}
			cJSON_AddItemToArray(top_app_list_ulList, itemLocal);
		}
	}

	if(congestion_info->top_app_list_dl) {
		cJSON *top_app_list_dlList = cJSON_AddArrayToObject(item,
		                                                    "topAppListDl");
		if(top_app_list_dlList == NULL) {
			printf(
				"congestion_info_convertToJSON() failed [top_app_list_dl]");
			goto end;
		}
		list_for_each(congestion_info->top_app_list_dl, node) {
			cJSON *itemLocal = top_application_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"congestion_info_convertToJSON() failed [top_app_list_dl]");
				goto end;
			}
			cJSON_AddItemToArray(top_app_list_dlList, itemLocal);
		}
	}

end:
	return item;
}

congestion_info_t *congestion_info_parseFromJSON(cJSON *congestion_infoJSON) {
	congestion_info_t *congestion_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *cong_type = NULL;
	congestion_type_t *cong_type_local_nonprim = NULL;
	cJSON *time_intev = NULL;
	time_window_t *time_intev_local_nonprim = NULL;
	cJSON *nsi = NULL;
	threshold_level_t *nsi_local_nonprim = NULL;
	cJSON *confidence = NULL;
	cJSON *top_app_list_ul = NULL;
	list_t *top_app_list_ulList = NULL;
	cJSON *top_app_list_dl = NULL;
	list_t *top_app_list_dlList = NULL;
	cong_type = cJSON_GetObjectItemCaseSensitive(congestion_infoJSON,
	                                             "congType");
	if(!cong_type) {
		printf("congestion_info_parseFromJSON() failed [cong_type]");
		goto end;
	}
	cong_type_local_nonprim = congestion_type_parseFromJSON(cong_type);
	if(!cong_type_local_nonprim) {
		printf("congestion_type_parseFromJSON failed [cong_type]");
		goto end;
	}

	time_intev = cJSON_GetObjectItemCaseSensitive(congestion_infoJSON,
	                                              "timeIntev");
	if(!time_intev) {
		printf("congestion_info_parseFromJSON() failed [time_intev]");
		goto end;
	}
	time_intev_local_nonprim = time_window_parseFromJSON(time_intev);
	if(!time_intev_local_nonprim) {
		printf("time_window_parseFromJSON failed [time_intev]");
		goto end;
	}

	nsi = cJSON_GetObjectItemCaseSensitive(congestion_infoJSON, "nsi");
	if(!nsi) {
		printf("congestion_info_parseFromJSON() failed [nsi]");
		goto end;
	}
	nsi_local_nonprim = threshold_level_parseFromJSON(nsi);
	if(!nsi_local_nonprim) {
		printf("threshold_level_parseFromJSON failed [nsi]");
		goto end;
	}

	confidence = cJSON_GetObjectItemCaseSensitive(congestion_infoJSON,
	                                              "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"congestion_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	top_app_list_ul = cJSON_GetObjectItemCaseSensitive(congestion_infoJSON,
	                                                   "topAppListUl");
	if(top_app_list_ul) {
		cJSON *top_app_list_ul_local = NULL;
		if(!cJSON_IsArray(top_app_list_ul)) {
			printf(
				"congestion_info_parseFromJSON() failed [top_app_list_ul]");
			goto end;
		}

		top_app_list_ulList = list_create();

		cJSON_ArrayForEach(top_app_list_ul_local, top_app_list_ul) {
			if(!cJSON_IsObject(top_app_list_ul_local)) {
				printf(
					"congestion_info_parseFromJSON() failed [top_app_list_ul]");
				goto end;
			}
			top_application_t *top_app_list_ulItem =
				top_application_parseFromJSON(
					top_app_list_ul_local);
			if(!top_app_list_ulItem) {
				printf("No top_app_list_ulItem");
				goto end;
			}
			list_add(top_app_list_ulList, top_app_list_ulItem);
		}
	}

	top_app_list_dl = cJSON_GetObjectItemCaseSensitive(congestion_infoJSON,
	                                                   "topAppListDl");
	if(top_app_list_dl) {
		cJSON *top_app_list_dl_local = NULL;
		if(!cJSON_IsArray(top_app_list_dl)) {
			printf(
				"congestion_info_parseFromJSON() failed [top_app_list_dl]");
			goto end;
		}

		top_app_list_dlList = list_create();

		cJSON_ArrayForEach(top_app_list_dl_local, top_app_list_dl) {
			if(!cJSON_IsObject(top_app_list_dl_local)) {
				printf(
					"congestion_info_parseFromJSON() failed [top_app_list_dl]");
				goto end;
			}
			top_application_t *top_app_list_dlItem =
				top_application_parseFromJSON(
					top_app_list_dl_local);
			if(!top_app_list_dlItem) {
				printf("No top_app_list_dlItem");
				goto end;
			}
			list_add(top_app_list_dlList, top_app_list_dlItem);
		}
	}

	congestion_info_local_var = congestion_info_create(
		cong_type_local_nonprim,
		time_intev_local_nonprim,
		nsi_local_nonprim,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0,
		top_app_list_ul ? top_app_list_ulList : NULL,
		top_app_list_dl ? top_app_list_dlList : NULL
		);

	return congestion_info_local_var;
end:
	if(cong_type_local_nonprim) {
		congestion_type_free(cong_type_local_nonprim);
		cong_type_local_nonprim = NULL;
	}
	if(time_intev_local_nonprim) {
		time_window_free(time_intev_local_nonprim);
		time_intev_local_nonprim = NULL;
	}
	if(nsi_local_nonprim) {
		threshold_level_free(nsi_local_nonprim);
		nsi_local_nonprim = NULL;
	}
	if(top_app_list_ulList) {
		list_for_each(top_app_list_ulList, node) {
			top_application_free(node->data);
		}
		list_free(top_app_list_ulList);
		top_app_list_ulList = NULL;
	}
	if(top_app_list_dlList) {
		list_for_each(top_app_list_dlList, node) {
			top_application_free(node->data);
		}
		list_free(top_app_list_dlList);
		top_app_list_dlList = NULL;
	}
	return NULL;
}

congestion_info_t *congestion_info_copy(congestion_info_t	*dst,
                                        congestion_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = congestion_info_convertToJSON(src);
	if(!item) {
		printf("congestion_info_convertToJSON() failed");
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

	congestion_info_free(dst);
	dst = congestion_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
