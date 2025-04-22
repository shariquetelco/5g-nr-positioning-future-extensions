#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nsi_load_level_info.h"

nsi_load_level_info_t *nsi_load_level_info_create(int load_level_information,
                                                  snssai_t *snssai,
                                                  char *nsi_id,
                                                  resource_usage_t *res_usage,
                                                  bool is_num_of_exceed_load_level_thr, int num_of_exceed_load_level_thr, bool is_exceed_load_level_thr_ind, int exceed_load_level_thr_ind, network_area_info_t *network_area, time_window_t *time_period, list_t *res_usg_thr_cross_time_period, number_average_t *num_of_ues, number_average_t *num_of_pdu_sess, bool is_confidence,
                                                  int confidence) {
	nsi_load_level_info_t *nsi_load_level_info_local_var =
		malloc(sizeof(nsi_load_level_info_t));

	nsi_load_level_info_local_var->load_level_information =
		load_level_information;
	nsi_load_level_info_local_var->snssai = snssai;
	nsi_load_level_info_local_var->nsi_id = nsi_id;
	nsi_load_level_info_local_var->res_usage = res_usage;
	nsi_load_level_info_local_var->is_num_of_exceed_load_level_thr =
		is_num_of_exceed_load_level_thr;
	nsi_load_level_info_local_var->num_of_exceed_load_level_thr =
		num_of_exceed_load_level_thr;
	nsi_load_level_info_local_var->is_exceed_load_level_thr_ind =
		is_exceed_load_level_thr_ind;
	nsi_load_level_info_local_var->exceed_load_level_thr_ind =
		exceed_load_level_thr_ind;
	nsi_load_level_info_local_var->network_area = network_area;
	nsi_load_level_info_local_var->time_period = time_period;
	nsi_load_level_info_local_var->res_usg_thr_cross_time_period =
		res_usg_thr_cross_time_period;
	nsi_load_level_info_local_var->num_of_ues = num_of_ues;
	nsi_load_level_info_local_var->num_of_pdu_sess = num_of_pdu_sess;
	nsi_load_level_info_local_var->is_confidence = is_confidence;
	nsi_load_level_info_local_var->confidence = confidence;

	return nsi_load_level_info_local_var;
}

void nsi_load_level_info_free(nsi_load_level_info_t *nsi_load_level_info) {
	lnode_t *node = NULL;

	if(NULL == nsi_load_level_info) {
		return;
	}
	if(nsi_load_level_info->snssai) {
		snssai_free(nsi_load_level_info->snssai);
		nsi_load_level_info->snssai = NULL;
	}
	if(nsi_load_level_info->nsi_id) {
		free(nsi_load_level_info->nsi_id);
		nsi_load_level_info->nsi_id = NULL;
	}
	if(nsi_load_level_info->res_usage) {
		resource_usage_free(nsi_load_level_info->res_usage);
		nsi_load_level_info->res_usage = NULL;
	}
	if(nsi_load_level_info->network_area) {
		network_area_info_free(nsi_load_level_info->network_area);
		nsi_load_level_info->network_area = NULL;
	}
	if(nsi_load_level_info->time_period) {
		time_window_free(nsi_load_level_info->time_period);
		nsi_load_level_info->time_period = NULL;
	}
	if(nsi_load_level_info->res_usg_thr_cross_time_period) {
		list_for_each(
			nsi_load_level_info->res_usg_thr_cross_time_period,
			node) {
			time_window_free(node->data);
		}
		list_free(nsi_load_level_info->res_usg_thr_cross_time_period);
		nsi_load_level_info->res_usg_thr_cross_time_period = NULL;
	}
	if(nsi_load_level_info->num_of_ues) {
		number_average_free(nsi_load_level_info->num_of_ues);
		nsi_load_level_info->num_of_ues = NULL;
	}
	if(nsi_load_level_info->num_of_pdu_sess) {
		number_average_free(nsi_load_level_info->num_of_pdu_sess);
		nsi_load_level_info->num_of_pdu_sess = NULL;
	}
	free(nsi_load_level_info);
}

cJSON *nsi_load_level_info_convertToJSON(
	nsi_load_level_info_t *nsi_load_level_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nsi_load_level_info == NULL) {
		printf(
			"nsi_load_level_info_convertToJSON() failed [NsiLoadLevelInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "loadLevelInformation",
	                           nsi_load_level_info->load_level_information)
	   == NULL)
	{
		printf(
			"nsi_load_level_info_convertToJSON() failed [load_level_information]");
		goto end;
	}

	if(!nsi_load_level_info->snssai) {
		printf("nsi_load_level_info_convertToJSON() failed [snssai]");
		return NULL;
	}
	cJSON *snssai_local_JSON = snssai_convertToJSON(
		nsi_load_level_info->snssai);
	if(snssai_local_JSON == NULL) {
		printf("nsi_load_level_info_convertToJSON() failed [snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
	if(item->child == NULL) {
		printf("nsi_load_level_info_convertToJSON() failed [snssai]");
		goto end;
	}

	if(nsi_load_level_info->nsi_id) {
		if(cJSON_AddStringToObject(item, "nsiId",
		                           nsi_load_level_info->nsi_id) == NULL)
		{
			printf(
				"nsi_load_level_info_convertToJSON() failed [nsi_id]");
			goto end;
		}
	}

	if(nsi_load_level_info->res_usage) {
		cJSON *res_usage_local_JSON = resource_usage_convertToJSON(
			nsi_load_level_info->res_usage);
		if(res_usage_local_JSON == NULL) {
			printf(
				"nsi_load_level_info_convertToJSON() failed [res_usage]");
			goto end;
		}
		cJSON_AddItemToObject(item, "resUsage", res_usage_local_JSON);
		if(item->child == NULL) {
			printf(
				"nsi_load_level_info_convertToJSON() failed [res_usage]");
			goto end;
		}
	}

	if(nsi_load_level_info->is_num_of_exceed_load_level_thr) {
		if(cJSON_AddNumberToObject(item, "numOfExceedLoadLevelThr",
		                           nsi_load_level_info->
		                           num_of_exceed_load_level_thr) ==
		   NULL)
		{
			printf(
				"nsi_load_level_info_convertToJSON() failed [num_of_exceed_load_level_thr]");
			goto end;
		}
	}

	if(nsi_load_level_info->is_exceed_load_level_thr_ind) {
		if(cJSON_AddBoolToObject(item, "exceedLoadLevelThrInd",
		                         nsi_load_level_info->
		                         exceed_load_level_thr_ind) == NULL)
		{
			printf(
				"nsi_load_level_info_convertToJSON() failed [exceed_load_level_thr_ind]");
			goto end;
		}
	}

	if(nsi_load_level_info->network_area) {
		cJSON *network_area_local_JSON =
			network_area_info_convertToJSON(
				nsi_load_level_info->network_area);
		if(network_area_local_JSON == NULL) {
			printf(
				"nsi_load_level_info_convertToJSON() failed [network_area]");
			goto end;
		}
		cJSON_AddItemToObject(item, "networkArea",
		                      network_area_local_JSON);
		if(item->child == NULL) {
			printf(
				"nsi_load_level_info_convertToJSON() failed [network_area]");
			goto end;
		}
	}

	if(nsi_load_level_info->time_period) {
		cJSON *time_period_local_JSON = time_window_convertToJSON(
			nsi_load_level_info->time_period);
		if(time_period_local_JSON == NULL) {
			printf(
				"nsi_load_level_info_convertToJSON() failed [time_period]");
			goto end;
		}
		cJSON_AddItemToObject(item, "timePeriod",
		                      time_period_local_JSON);
		if(item->child == NULL) {
			printf(
				"nsi_load_level_info_convertToJSON() failed [time_period]");
			goto end;
		}
	}

	if(nsi_load_level_info->res_usg_thr_cross_time_period) {
		cJSON *res_usg_thr_cross_time_periodList =
			cJSON_AddArrayToObject(item,
			                       "resUsgThrCrossTimePeriod");
		if(res_usg_thr_cross_time_periodList == NULL) {
			printf(
				"nsi_load_level_info_convertToJSON() failed [res_usg_thr_cross_time_period]");
			goto end;
		}
		list_for_each(
			nsi_load_level_info->res_usg_thr_cross_time_period,
			node) {
			cJSON *itemLocal =
				time_window_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"nsi_load_level_info_convertToJSON() failed [res_usg_thr_cross_time_period]");
				goto end;
			}
			cJSON_AddItemToArray(res_usg_thr_cross_time_periodList,
			                     itemLocal);
		}
	}

	if(nsi_load_level_info->num_of_ues) {
		cJSON *num_of_ues_local_JSON = number_average_convertToJSON(
			nsi_load_level_info->num_of_ues);
		if(num_of_ues_local_JSON == NULL) {
			printf(
				"nsi_load_level_info_convertToJSON() failed [num_of_ues]");
			goto end;
		}
		cJSON_AddItemToObject(item, "numOfUes", num_of_ues_local_JSON);
		if(item->child == NULL) {
			printf(
				"nsi_load_level_info_convertToJSON() failed [num_of_ues]");
			goto end;
		}
	}

	if(nsi_load_level_info->num_of_pdu_sess) {
		cJSON *num_of_pdu_sess_local_JSON =
			number_average_convertToJSON(
				nsi_load_level_info->num_of_pdu_sess);
		if(num_of_pdu_sess_local_JSON == NULL) {
			printf(
				"nsi_load_level_info_convertToJSON() failed [num_of_pdu_sess]");
			goto end;
		}
		cJSON_AddItemToObject(item, "numOfPduSess",
		                      num_of_pdu_sess_local_JSON);
		if(item->child == NULL) {
			printf(
				"nsi_load_level_info_convertToJSON() failed [num_of_pdu_sess]");
			goto end;
		}
	}

	if(nsi_load_level_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           nsi_load_level_info->confidence) ==
		   NULL)
		{
			printf(
				"nsi_load_level_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

end:
	return item;
}

nsi_load_level_info_t *nsi_load_level_info_parseFromJSON(
	cJSON *nsi_load_level_infoJSON) {
	nsi_load_level_info_t *nsi_load_level_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *load_level_information = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *nsi_id = NULL;
	cJSON *res_usage = NULL;
	resource_usage_t *res_usage_local_nonprim = NULL;
	cJSON *num_of_exceed_load_level_thr = NULL;
	cJSON *exceed_load_level_thr_ind = NULL;
	cJSON *network_area = NULL;
	network_area_info_t *network_area_local_nonprim = NULL;
	cJSON *time_period = NULL;
	time_window_t *time_period_local_nonprim = NULL;
	cJSON *res_usg_thr_cross_time_period = NULL;
	list_t *res_usg_thr_cross_time_periodList = NULL;
	cJSON *num_of_ues = NULL;
	number_average_t *num_of_ues_local_nonprim = NULL;
	cJSON *num_of_pdu_sess = NULL;
	number_average_t *num_of_pdu_sess_local_nonprim = NULL;
	cJSON *confidence = NULL;
	load_level_information = cJSON_GetObjectItemCaseSensitive(
		nsi_load_level_infoJSON, "loadLevelInformation");
	if(!load_level_information) {
		printf(
			"nsi_load_level_info_parseFromJSON() failed [load_level_information]");
		goto end;
	}
	if(!cJSON_IsNumber(load_level_information)) {
		printf(
			"nsi_load_level_info_parseFromJSON() failed [load_level_information]");
		goto end;
	}

	snssai = cJSON_GetObjectItemCaseSensitive(nsi_load_level_infoJSON,
	                                          "snssai");
	if(!snssai) {
		printf("nsi_load_level_info_parseFromJSON() failed [snssai]");
		goto end;
	}
	snssai_local_nonprim = snssai_parseFromJSON(snssai);
	if(!snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [snssai]");
		goto end;
	}

	nsi_id = cJSON_GetObjectItemCaseSensitive(nsi_load_level_infoJSON,
	                                          "nsiId");
	if(nsi_id) {
		if(!cJSON_IsString(nsi_id) &&
		   !cJSON_IsNull(nsi_id))
		{
			printf(
				"nsi_load_level_info_parseFromJSON() failed [nsi_id]");
			goto end;
		}
	}

	res_usage = cJSON_GetObjectItemCaseSensitive(nsi_load_level_infoJSON,
	                                             "resUsage");
	if(res_usage) {
		res_usage_local_nonprim =
			resource_usage_parseFromJSON(res_usage);
		if(!res_usage_local_nonprim) {
			printf("resource_usage_parseFromJSON failed [res_usage]");
			goto end;
		}
	}

	num_of_exceed_load_level_thr = cJSON_GetObjectItemCaseSensitive(
		nsi_load_level_infoJSON, "numOfExceedLoadLevelThr");
	if(num_of_exceed_load_level_thr) {
		if(!cJSON_IsNumber(num_of_exceed_load_level_thr)) {
			printf(
				"nsi_load_level_info_parseFromJSON() failed [num_of_exceed_load_level_thr]");
			goto end;
		}
	}

	exceed_load_level_thr_ind = cJSON_GetObjectItemCaseSensitive(
		nsi_load_level_infoJSON, "exceedLoadLevelThrInd");
	if(exceed_load_level_thr_ind) {
		if(!cJSON_IsBool(exceed_load_level_thr_ind)) {
			printf(
				"nsi_load_level_info_parseFromJSON() failed [exceed_load_level_thr_ind]");
			goto end;
		}
	}

	network_area = cJSON_GetObjectItemCaseSensitive(nsi_load_level_infoJSON,
	                                                "networkArea");
	if(network_area) {
		network_area_local_nonprim = network_area_info_parseFromJSON(
			network_area);
		if(!network_area_local_nonprim) {
			printf(
				"network_area_info_parseFromJSON failed [network_area]");
			goto end;
		}
	}

	time_period = cJSON_GetObjectItemCaseSensitive(nsi_load_level_infoJSON,
	                                               "timePeriod");
	if(time_period) {
		time_period_local_nonprim = time_window_parseFromJSON(
			time_period);
		if(!time_period_local_nonprim) {
			printf("time_window_parseFromJSON failed [time_period]");
			goto end;
		}
	}

	res_usg_thr_cross_time_period = cJSON_GetObjectItemCaseSensitive(
		nsi_load_level_infoJSON, "resUsgThrCrossTimePeriod");
	if(res_usg_thr_cross_time_period) {
		cJSON *res_usg_thr_cross_time_period_local = NULL;
		if(!cJSON_IsArray(res_usg_thr_cross_time_period)) {
			printf(
				"nsi_load_level_info_parseFromJSON() failed [res_usg_thr_cross_time_period]");
			goto end;
		}

		res_usg_thr_cross_time_periodList = list_create();

		cJSON_ArrayForEach(res_usg_thr_cross_time_period_local,
		                   res_usg_thr_cross_time_period) {
			if(!cJSON_IsObject(res_usg_thr_cross_time_period_local))
			{
				printf(
					"nsi_load_level_info_parseFromJSON() failed [res_usg_thr_cross_time_period]");
				goto end;
			}
			time_window_t *res_usg_thr_cross_time_periodItem =
				time_window_parseFromJSON(
					res_usg_thr_cross_time_period_local);
			if(!res_usg_thr_cross_time_periodItem) {
				printf("No res_usg_thr_cross_time_periodItem");
				goto end;
			}
			list_add(res_usg_thr_cross_time_periodList,
			         res_usg_thr_cross_time_periodItem);
		}
	}

	num_of_ues = cJSON_GetObjectItemCaseSensitive(nsi_load_level_infoJSON,
	                                              "numOfUes");
	if(num_of_ues) {
		num_of_ues_local_nonprim = number_average_parseFromJSON(
			num_of_ues);
		if(!num_of_ues_local_nonprim) {
			printf(
				"number_average_parseFromJSON failed [num_of_ues]");
			goto end;
		}
	}

	num_of_pdu_sess = cJSON_GetObjectItemCaseSensitive(
		nsi_load_level_infoJSON, "numOfPduSess");
	if(num_of_pdu_sess) {
		num_of_pdu_sess_local_nonprim = number_average_parseFromJSON(
			num_of_pdu_sess);
		if(!num_of_pdu_sess_local_nonprim) {
			printf(
				"number_average_parseFromJSON failed [num_of_pdu_sess]");
			goto end;
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(nsi_load_level_infoJSON,
	                                              "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"nsi_load_level_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	nsi_load_level_info_local_var = nsi_load_level_info_create(

		load_level_information->valuedouble,
		snssai_local_nonprim,
		nsi_id &&
		!cJSON_IsNull(nsi_id) ? strdup(
			nsi_id->valuestring) : NULL,
		res_usage ? res_usage_local_nonprim : NULL,
		num_of_exceed_load_level_thr ? true : false,
		num_of_exceed_load_level_thr ? num_of_exceed_load_level_thr->valuedouble : 0,
		exceed_load_level_thr_ind ? true : false,
		exceed_load_level_thr_ind ? exceed_load_level_thr_ind->valueint : 0,
		network_area ? network_area_local_nonprim : NULL,
		time_period ? time_period_local_nonprim : NULL,
		res_usg_thr_cross_time_period ? res_usg_thr_cross_time_periodList : NULL,
		num_of_ues ? num_of_ues_local_nonprim : NULL,
		num_of_pdu_sess ? num_of_pdu_sess_local_nonprim : NULL,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0
		);

	return nsi_load_level_info_local_var;
end:
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(res_usage_local_nonprim) {
		resource_usage_free(res_usage_local_nonprim);
		res_usage_local_nonprim = NULL;
	}
	if(network_area_local_nonprim) {
		network_area_info_free(network_area_local_nonprim);
		network_area_local_nonprim = NULL;
	}
	if(time_period_local_nonprim) {
		time_window_free(time_period_local_nonprim);
		time_period_local_nonprim = NULL;
	}
	if(res_usg_thr_cross_time_periodList) {
		list_for_each(res_usg_thr_cross_time_periodList, node) {
			time_window_free(node->data);
		}
		list_free(res_usg_thr_cross_time_periodList);
		res_usg_thr_cross_time_periodList = NULL;
	}
	if(num_of_ues_local_nonprim) {
		number_average_free(num_of_ues_local_nonprim);
		num_of_ues_local_nonprim = NULL;
	}
	if(num_of_pdu_sess_local_nonprim) {
		number_average_free(num_of_pdu_sess_local_nonprim);
		num_of_pdu_sess_local_nonprim = NULL;
	}
	return NULL;
}

nsi_load_level_info_t *nsi_load_level_info_copy(nsi_load_level_info_t	*dst,
                                                nsi_load_level_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nsi_load_level_info_convertToJSON(src);
	if(!item) {
		printf("nsi_load_level_info_convertToJSON() failed");
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

	nsi_load_level_info_free(dst);
	dst = nsi_load_level_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
