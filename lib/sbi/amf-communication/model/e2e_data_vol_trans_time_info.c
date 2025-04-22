#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "e2e_data_vol_trans_time_info.h"

e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info_create(
	list_t *e2e_data_vol_trans_times,
	list_t *e2e_data_vol_trans_time_ue_lists, list_t *geo_distr_infos,
	bool is_confidence, int confidence) {
	e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info_local_var =
		malloc(sizeof(e2e_data_vol_trans_time_info_t));

	e2e_data_vol_trans_time_info_local_var->e2e_data_vol_trans_times =
		e2e_data_vol_trans_times;
	e2e_data_vol_trans_time_info_local_var->e2e_data_vol_trans_time_ue_lists
	        = e2e_data_vol_trans_time_ue_lists;
	e2e_data_vol_trans_time_info_local_var->geo_distr_infos =
		geo_distr_infos;
	e2e_data_vol_trans_time_info_local_var->is_confidence = is_confidence;
	e2e_data_vol_trans_time_info_local_var->confidence = confidence;

	return e2e_data_vol_trans_time_info_local_var;
}

void e2e_data_vol_trans_time_info_free(
	e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info) {
	lnode_t *node = NULL;

	if(NULL == e2e_data_vol_trans_time_info) {
		return;
	}
	if(e2e_data_vol_trans_time_info->e2e_data_vol_trans_times) {
		list_for_each(
			e2e_data_vol_trans_time_info->e2e_data_vol_trans_times,
			node) {
			e2e_data_vol_trans_time_per_ts_free(node->data);
		}
		list_free(e2e_data_vol_trans_time_info->e2e_data_vol_trans_times);
		e2e_data_vol_trans_time_info->e2e_data_vol_trans_times = NULL;
	}
	if(e2e_data_vol_trans_time_info->e2e_data_vol_trans_time_ue_lists) {
		list_for_each(
			e2e_data_vol_trans_time_info->e2e_data_vol_trans_time_ue_lists,
			node) {
			e2e_data_vol_trans_time_ue_list_free(node->data);
		}
		list_free(
			e2e_data_vol_trans_time_info->e2e_data_vol_trans_time_ue_lists);
		e2e_data_vol_trans_time_info->e2e_data_vol_trans_time_ue_lists =
			NULL;
	}
	if(e2e_data_vol_trans_time_info->geo_distr_infos) {
		list_for_each(e2e_data_vol_trans_time_info->geo_distr_infos,
		              node) {
			geo_distribution_info_free(node->data);
		}
		list_free(e2e_data_vol_trans_time_info->geo_distr_infos);
		e2e_data_vol_trans_time_info->geo_distr_infos = NULL;
	}
	free(e2e_data_vol_trans_time_info);
}

cJSON *e2e_data_vol_trans_time_info_convertToJSON(
	e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(e2e_data_vol_trans_time_info == NULL) {
		printf(
			"e2e_data_vol_trans_time_info_convertToJSON() failed [E2eDataVolTransTimeInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!e2e_data_vol_trans_time_info->e2e_data_vol_trans_times) {
		printf(
			"e2e_data_vol_trans_time_info_convertToJSON() failed [e2e_data_vol_trans_times]");
		return NULL;
	}
	cJSON *e2e_data_vol_trans_timesList = cJSON_AddArrayToObject(item,
	                                                             "e2eDataVolTransTimes");
	if(e2e_data_vol_trans_timesList == NULL) {
		printf(
			"e2e_data_vol_trans_time_info_convertToJSON() failed [e2e_data_vol_trans_times]");
		goto end;
	}
	list_for_each(e2e_data_vol_trans_time_info->e2e_data_vol_trans_times,
	              node) {
		cJSON *itemLocal = e2e_data_vol_trans_time_per_ts_convertToJSON(
			node->data);
		if(itemLocal == NULL) {
			printf(
				"e2e_data_vol_trans_time_info_convertToJSON() failed [e2e_data_vol_trans_times]");
			goto end;
		}
		cJSON_AddItemToArray(e2e_data_vol_trans_timesList, itemLocal);
	}

	if(e2e_data_vol_trans_time_info->e2e_data_vol_trans_time_ue_lists) {
		cJSON *e2e_data_vol_trans_time_ue_listsList =
			cJSON_AddArrayToObject(item,
			                       "e2eDataVolTransTimeUeLists");
		if(e2e_data_vol_trans_time_ue_listsList == NULL) {
			printf(
				"e2e_data_vol_trans_time_info_convertToJSON() failed [e2e_data_vol_trans_time_ue_lists]");
			goto end;
		}
		list_for_each(
			e2e_data_vol_trans_time_info->e2e_data_vol_trans_time_ue_lists,
			node) {
			cJSON *itemLocal =
				e2e_data_vol_trans_time_ue_list_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"e2e_data_vol_trans_time_info_convertToJSON() failed [e2e_data_vol_trans_time_ue_lists]");
				goto end;
			}
			cJSON_AddItemToArray(
				e2e_data_vol_trans_time_ue_listsList,
				itemLocal);
		}
	}

	if(e2e_data_vol_trans_time_info->geo_distr_infos) {
		cJSON *geo_distr_infosList = cJSON_AddArrayToObject(item,
		                                                    "geoDistrInfos");
		if(geo_distr_infosList == NULL) {
			printf(
				"e2e_data_vol_trans_time_info_convertToJSON() failed [geo_distr_infos]");
			goto end;
		}
		list_for_each(e2e_data_vol_trans_time_info->geo_distr_infos,
		              node) {
			cJSON *itemLocal = geo_distribution_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"e2e_data_vol_trans_time_info_convertToJSON() failed [geo_distr_infos]");
				goto end;
			}
			cJSON_AddItemToArray(geo_distr_infosList, itemLocal);
		}
	}

	if(e2e_data_vol_trans_time_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           e2e_data_vol_trans_time_info->
		                           confidence) == NULL)
		{
			printf(
				"e2e_data_vol_trans_time_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

end:
	return item;
}

e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info_parseFromJSON(
	cJSON *e2e_data_vol_trans_time_infoJSON) {
	e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *e2e_data_vol_trans_times = NULL;
	list_t *e2e_data_vol_trans_timesList = NULL;
	cJSON *e2e_data_vol_trans_time_ue_lists = NULL;
	list_t *e2e_data_vol_trans_time_ue_listsList = NULL;
	cJSON *geo_distr_infos = NULL;
	list_t *geo_distr_infosList = NULL;
	cJSON *confidence = NULL;
	e2e_data_vol_trans_times = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_infoJSON, "e2eDataVolTransTimes");
	if(!e2e_data_vol_trans_times) {
		printf(
			"e2e_data_vol_trans_time_info_parseFromJSON() failed [e2e_data_vol_trans_times]");
		goto end;
	}
	cJSON *e2e_data_vol_trans_times_local = NULL;
	if(!cJSON_IsArray(e2e_data_vol_trans_times)) {
		printf(
			"e2e_data_vol_trans_time_info_parseFromJSON() failed [e2e_data_vol_trans_times]");
		goto end;
	}

	e2e_data_vol_trans_timesList = list_create();

	cJSON_ArrayForEach(e2e_data_vol_trans_times_local,
	                   e2e_data_vol_trans_times) {
		if(!cJSON_IsObject(e2e_data_vol_trans_times_local)) {
			printf(
				"e2e_data_vol_trans_time_info_parseFromJSON() failed [e2e_data_vol_trans_times]");
			goto end;
		}
		e2e_data_vol_trans_time_per_ts_t *e2e_data_vol_trans_timesItem =
			e2e_data_vol_trans_time_per_ts_parseFromJSON(
				e2e_data_vol_trans_times_local);
		if(!e2e_data_vol_trans_timesItem) {
			printf("No e2e_data_vol_trans_timesItem");
			goto end;
		}
		list_add(e2e_data_vol_trans_timesList,
		         e2e_data_vol_trans_timesItem);
	}

	e2e_data_vol_trans_time_ue_lists = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_infoJSON, "e2eDataVolTransTimeUeLists");
	if(e2e_data_vol_trans_time_ue_lists) {
		cJSON *e2e_data_vol_trans_time_ue_lists_local = NULL;
		if(!cJSON_IsArray(e2e_data_vol_trans_time_ue_lists)) {
			printf(
				"e2e_data_vol_trans_time_info_parseFromJSON() failed [e2e_data_vol_trans_time_ue_lists]");
			goto end;
		}

		e2e_data_vol_trans_time_ue_listsList = list_create();

		cJSON_ArrayForEach(e2e_data_vol_trans_time_ue_lists_local,
		                   e2e_data_vol_trans_time_ue_lists) {
			if(!cJSON_IsObject(
				   e2e_data_vol_trans_time_ue_lists_local))
			{
				printf(
					"e2e_data_vol_trans_time_info_parseFromJSON() failed [e2e_data_vol_trans_time_ue_lists]");
				goto end;
			}
			e2e_data_vol_trans_time_ue_list_t *
			        e2e_data_vol_trans_time_ue_listsItem =
				e2e_data_vol_trans_time_ue_list_parseFromJSON(
					e2e_data_vol_trans_time_ue_lists_local);
			if(!e2e_data_vol_trans_time_ue_listsItem) {
				printf("No e2e_data_vol_trans_time_ue_listsItem");
				goto end;
			}
			list_add(e2e_data_vol_trans_time_ue_listsList,
			         e2e_data_vol_trans_time_ue_listsItem);
		}
	}

	geo_distr_infos = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_infoJSON, "geoDistrInfos");
	if(geo_distr_infos) {
		cJSON *geo_distr_infos_local = NULL;
		if(!cJSON_IsArray(geo_distr_infos)) {
			printf(
				"e2e_data_vol_trans_time_info_parseFromJSON() failed [geo_distr_infos]");
			goto end;
		}

		geo_distr_infosList = list_create();

		cJSON_ArrayForEach(geo_distr_infos_local, geo_distr_infos) {
			if(!cJSON_IsObject(geo_distr_infos_local)) {
				printf(
					"e2e_data_vol_trans_time_info_parseFromJSON() failed [geo_distr_infos]");
				goto end;
			}
			geo_distribution_info_t *geo_distr_infosItem =
				geo_distribution_info_parseFromJSON(
					geo_distr_infos_local);
			if(!geo_distr_infosItem) {
				printf("No geo_distr_infosItem");
				goto end;
			}
			list_add(geo_distr_infosList, geo_distr_infosItem);
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_infoJSON, "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"e2e_data_vol_trans_time_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	e2e_data_vol_trans_time_info_local_var =
		e2e_data_vol_trans_time_info_create(
			e2e_data_vol_trans_timesList,
			e2e_data_vol_trans_time_ue_lists ? e2e_data_vol_trans_time_ue_listsList : NULL,
			geo_distr_infos ? geo_distr_infosList : NULL,
			confidence ? true : false,
			confidence ? confidence->valuedouble : 0
			);

	return e2e_data_vol_trans_time_info_local_var;
end:
	if(e2e_data_vol_trans_timesList) {
		list_for_each(e2e_data_vol_trans_timesList, node) {
			e2e_data_vol_trans_time_per_ts_free(node->data);
		}
		list_free(e2e_data_vol_trans_timesList);
		e2e_data_vol_trans_timesList = NULL;
	}
	if(e2e_data_vol_trans_time_ue_listsList) {
		list_for_each(e2e_data_vol_trans_time_ue_listsList, node) {
			e2e_data_vol_trans_time_ue_list_free(node->data);
		}
		list_free(e2e_data_vol_trans_time_ue_listsList);
		e2e_data_vol_trans_time_ue_listsList = NULL;
	}
	if(geo_distr_infosList) {
		list_for_each(geo_distr_infosList, node) {
			geo_distribution_info_free(node->data);
		}
		list_free(geo_distr_infosList);
		geo_distr_infosList = NULL;
	}
	return NULL;
}

e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info_copy(
	e2e_data_vol_trans_time_info_t	*dst,
	e2e_data_vol_trans_time_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = e2e_data_vol_trans_time_info_convertToJSON(src);
	if(!item) {
		printf("e2e_data_vol_trans_time_info_convertToJSON() failed");
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

	e2e_data_vol_trans_time_info_free(dst);
	dst = e2e_data_vol_trans_time_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
