#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "qos_sustainability_info.h"

qos_sustainability_info_t *qos_sustainability_info_create(
	network_area_info_t *area_info, char *fine_area_infos, char *end_ts,
	retainability_threshold_t *qos_flow_ret_thd, char *ran_ue_throu_thd,
	snssai_t *snssai, bool is_confidence, int confidence) {
	qos_sustainability_info_t *qos_sustainability_info_local_var = malloc(
		sizeof(qos_sustainability_info_t));

	qos_sustainability_info_local_var->area_info = area_info;
	qos_sustainability_info_local_var->fine_area_infos = fine_area_infos;
	qos_sustainability_info_local_var->end_ts = end_ts;
	qos_sustainability_info_local_var->qos_flow_ret_thd = qos_flow_ret_thd;
	qos_sustainability_info_local_var->ran_ue_throu_thd = ran_ue_throu_thd;
	qos_sustainability_info_local_var->snssai = snssai;
	qos_sustainability_info_local_var->is_confidence = is_confidence;
	qos_sustainability_info_local_var->confidence = confidence;

	return qos_sustainability_info_local_var;
}

void qos_sustainability_info_free(
	qos_sustainability_info_t *qos_sustainability_info) {
	lnode_t *node = NULL;

	if(NULL == qos_sustainability_info) {
		return;
	}
	if(qos_sustainability_info->area_info) {
		network_area_info_free(qos_sustainability_info->area_info);
		qos_sustainability_info->area_info = NULL;
	}
	if(qos_sustainability_info->fine_area_infos) {
		free(qos_sustainability_info->fine_area_infos);
		qos_sustainability_info->fine_area_infos = NULL;
	}
	if(qos_sustainability_info->end_ts) {
		free(qos_sustainability_info->end_ts);
		qos_sustainability_info->end_ts = NULL;
	}
	if(qos_sustainability_info->qos_flow_ret_thd) {
		retainability_threshold_free(
			qos_sustainability_info->qos_flow_ret_thd);
		qos_sustainability_info->qos_flow_ret_thd = NULL;
	}
	if(qos_sustainability_info->ran_ue_throu_thd) {
		free(qos_sustainability_info->ran_ue_throu_thd);
		qos_sustainability_info->ran_ue_throu_thd = NULL;
	}
	if(qos_sustainability_info->snssai) {
		snssai_free(qos_sustainability_info->snssai);
		qos_sustainability_info->snssai = NULL;
	}
	free(qos_sustainability_info);
}

cJSON *qos_sustainability_info_convertToJSON(
	qos_sustainability_info_t *qos_sustainability_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(qos_sustainability_info == NULL) {
		printf(
			"qos_sustainability_info_convertToJSON() failed [QosSustainabilityInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(qos_sustainability_info->area_info) {
		cJSON *area_info_local_JSON = network_area_info_convertToJSON(
			qos_sustainability_info->area_info);
		if(area_info_local_JSON == NULL) {
			printf(
				"qos_sustainability_info_convertToJSON() failed [area_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "areaInfo", area_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"qos_sustainability_info_convertToJSON() failed [area_info]");
			goto end;
		}
	}

	if(qos_sustainability_info->fine_area_infos) {
		if(cJSON_AddStringToObject(item, "fineAreaInfos",
		                           qos_sustainability_info->
		                           fine_area_infos) == NULL)
		{
			printf(
				"qos_sustainability_info_convertToJSON() failed [fine_area_infos]");
			goto end;
		}
	}

	if(qos_sustainability_info->end_ts) {
		if(cJSON_AddStringToObject(item, "endTs",
		                           qos_sustainability_info->end_ts) ==
		   NULL)
		{
			printf(
				"qos_sustainability_info_convertToJSON() failed [end_ts]");
			goto end;
		}
	}

	if(qos_sustainability_info->qos_flow_ret_thd) {
		cJSON *qos_flow_ret_thd_local_JSON =
			retainability_threshold_convertToJSON(
				qos_sustainability_info->qos_flow_ret_thd);
		if(qos_flow_ret_thd_local_JSON == NULL) {
			printf(
				"qos_sustainability_info_convertToJSON() failed [qos_flow_ret_thd]");
			goto end;
		}
		cJSON_AddItemToObject(item, "qosFlowRetThd",
		                      qos_flow_ret_thd_local_JSON);
		if(item->child == NULL) {
			printf(
				"qos_sustainability_info_convertToJSON() failed [qos_flow_ret_thd]");
			goto end;
		}
	}

	if(qos_sustainability_info->ran_ue_throu_thd) {
		if(cJSON_AddStringToObject(item, "ranUeThrouThd",
		                           qos_sustainability_info->
		                           ran_ue_throu_thd) == NULL)
		{
			printf(
				"qos_sustainability_info_convertToJSON() failed [ran_ue_throu_thd]");
			goto end;
		}
	}

	if(qos_sustainability_info->snssai) {
		cJSON *snssai_local_JSON = snssai_convertToJSON(
			qos_sustainability_info->snssai);
		if(snssai_local_JSON == NULL) {
			printf(
				"qos_sustainability_info_convertToJSON() failed [snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"qos_sustainability_info_convertToJSON() failed [snssai]");
			goto end;
		}
	}

	if(qos_sustainability_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           qos_sustainability_info->confidence)
		   == NULL)
		{
			printf(
				"qos_sustainability_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

end:
	return item;
}

qos_sustainability_info_t *qos_sustainability_info_parseFromJSON(
	cJSON *qos_sustainability_infoJSON) {
	qos_sustainability_info_t *qos_sustainability_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *area_info = NULL;
	network_area_info_t *area_info_local_nonprim = NULL;
	cJSON *fine_area_infos = NULL;
	cJSON *end_ts = NULL;
	cJSON *qos_flow_ret_thd = NULL;
	retainability_threshold_t *qos_flow_ret_thd_local_nonprim = NULL;
	cJSON *ran_ue_throu_thd = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *confidence = NULL;
	area_info = cJSON_GetObjectItemCaseSensitive(
		qos_sustainability_infoJSON, "areaInfo");
	if(area_info) {
		area_info_local_nonprim = network_area_info_parseFromJSON(
			area_info);
		if(!area_info_local_nonprim) {
			printf(
				"network_area_info_parseFromJSON failed [area_info]");
			goto end;
		}
	}

	fine_area_infos = cJSON_GetObjectItemCaseSensitive(
		qos_sustainability_infoJSON, "fineAreaInfos");
	if(fine_area_infos) {
		if(!cJSON_IsString(fine_area_infos) &&
		   !cJSON_IsNull(fine_area_infos))
		{
			printf(
				"qos_sustainability_info_parseFromJSON() failed [fine_area_infos]");
			goto end;
		}
	}

	end_ts = cJSON_GetObjectItemCaseSensitive(qos_sustainability_infoJSON,
	                                          "endTs");
	if(end_ts) {
		if(!cJSON_IsString(end_ts) &&
		   !cJSON_IsNull(end_ts))
		{
			printf(
				"qos_sustainability_info_parseFromJSON() failed [end_ts]");
			goto end;
		}
	}

	qos_flow_ret_thd = cJSON_GetObjectItemCaseSensitive(
		qos_sustainability_infoJSON, "qosFlowRetThd");
	if(qos_flow_ret_thd) {
		qos_flow_ret_thd_local_nonprim =
			retainability_threshold_parseFromJSON(qos_flow_ret_thd);
		if(!qos_flow_ret_thd_local_nonprim) {
			printf(
				"retainability_threshold_parseFromJSON failed [qos_flow_ret_thd]");
			goto end;
		}
	}

	ran_ue_throu_thd = cJSON_GetObjectItemCaseSensitive(
		qos_sustainability_infoJSON, "ranUeThrouThd");
	if(ran_ue_throu_thd) {
		if(!cJSON_IsString(ran_ue_throu_thd) &&
		   !cJSON_IsNull(ran_ue_throu_thd))
		{
			printf(
				"qos_sustainability_info_parseFromJSON() failed [ran_ue_throu_thd]");
			goto end;
		}
	}

	snssai = cJSON_GetObjectItemCaseSensitive(qos_sustainability_infoJSON,
	                                          "snssai");
	if(snssai) {
		snssai_local_nonprim = snssai_parseFromJSON(snssai);
		if(!snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [snssai]");
			goto end;
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(
		qos_sustainability_infoJSON, "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"qos_sustainability_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	qos_sustainability_info_local_var = qos_sustainability_info_create(
		area_info ? area_info_local_nonprim : NULL,
		fine_area_infos &&
		!cJSON_IsNull(fine_area_infos) ? strdup(fine_area_infos->
		                                        valuestring) : NULL,
		end_ts &&
		!cJSON_IsNull(end_ts) ? strdup(end_ts->valuestring) : NULL,
		qos_flow_ret_thd ? qos_flow_ret_thd_local_nonprim : NULL,
		ran_ue_throu_thd &&
		!cJSON_IsNull(ran_ue_throu_thd) ? strdup(ran_ue_throu_thd->
		                                         valuestring) : NULL,
		snssai ? snssai_local_nonprim : NULL,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0
		);

	return qos_sustainability_info_local_var;
end:
	if(area_info_local_nonprim) {
		network_area_info_free(area_info_local_nonprim);
		area_info_local_nonprim = NULL;
	}
	if(qos_flow_ret_thd_local_nonprim) {
		retainability_threshold_free(qos_flow_ret_thd_local_nonprim);
		qos_flow_ret_thd_local_nonprim = NULL;
	}
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	return NULL;
}

qos_sustainability_info_t *qos_sustainability_info_copy(
	qos_sustainability_info_t *dst, qos_sustainability_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = qos_sustainability_info_convertToJSON(src);
	if(!item) {
		printf("qos_sustainability_info_convertToJSON() failed");
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

	qos_sustainability_info_free(dst);
	dst = qos_sustainability_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
