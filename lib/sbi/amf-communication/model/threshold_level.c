#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "threshold_level.h"

threshold_level_t *threshold_level_create(bool is_cong_level, int cong_level,
                                          bool is_nf_load_level,
                                          int nf_load_level,
                                          bool is_nf_cpu_usage,
                                          int nf_cpu_usage,
                                          bool is_nf_memory_usage,
                                          int nf_memory_usage,
                                          bool is_nf_storage_usage,
                                          int nf_storage_usage,
                                          char *avg_traffic_rate,
                                          char *max_traffic_rate,
                                          char *min_traffic_rate,
                                          char *agg_traffic_rate,
                                          bool is_var_traffic_rate,
                                          float var_traffic_rate,
                                          bool is_avg_packet_delay,
                                          int avg_packet_delay,
                                          bool is_max_packet_delay,
                                          int max_packet_delay,
                                          bool is_var_packet_delay,
                                          float var_packet_delay,
                                          bool is_avg_packet_loss_rate,
                                          int avg_packet_loss_rate,
                                          bool is_max_packet_loss_rate,
                                          int max_packet_loss_rate,
                                          bool is_var_packet_loss_rate,
                                          float var_packet_loss_rate,
                                          bool is_svc_exp_level,
                                          float svc_exp_level, bool is_speed,
                                          float speed) {
	threshold_level_t *threshold_level_local_var =
		malloc(sizeof(threshold_level_t));

	threshold_level_local_var->is_cong_level = is_cong_level;
	threshold_level_local_var->cong_level = cong_level;
	threshold_level_local_var->is_nf_load_level = is_nf_load_level;
	threshold_level_local_var->nf_load_level = nf_load_level;
	threshold_level_local_var->is_nf_cpu_usage = is_nf_cpu_usage;
	threshold_level_local_var->nf_cpu_usage = nf_cpu_usage;
	threshold_level_local_var->is_nf_memory_usage = is_nf_memory_usage;
	threshold_level_local_var->nf_memory_usage = nf_memory_usage;
	threshold_level_local_var->is_nf_storage_usage = is_nf_storage_usage;
	threshold_level_local_var->nf_storage_usage = nf_storage_usage;
	threshold_level_local_var->avg_traffic_rate = avg_traffic_rate;
	threshold_level_local_var->max_traffic_rate = max_traffic_rate;
	threshold_level_local_var->min_traffic_rate = min_traffic_rate;
	threshold_level_local_var->agg_traffic_rate = agg_traffic_rate;
	threshold_level_local_var->is_var_traffic_rate = is_var_traffic_rate;
	threshold_level_local_var->var_traffic_rate = var_traffic_rate;
	threshold_level_local_var->is_avg_packet_delay = is_avg_packet_delay;
	threshold_level_local_var->avg_packet_delay = avg_packet_delay;
	threshold_level_local_var->is_max_packet_delay = is_max_packet_delay;
	threshold_level_local_var->max_packet_delay = max_packet_delay;
	threshold_level_local_var->is_var_packet_delay = is_var_packet_delay;
	threshold_level_local_var->var_packet_delay = var_packet_delay;
	threshold_level_local_var->is_avg_packet_loss_rate =
		is_avg_packet_loss_rate;
	threshold_level_local_var->avg_packet_loss_rate = avg_packet_loss_rate;
	threshold_level_local_var->is_max_packet_loss_rate =
		is_max_packet_loss_rate;
	threshold_level_local_var->max_packet_loss_rate = max_packet_loss_rate;
	threshold_level_local_var->is_var_packet_loss_rate =
		is_var_packet_loss_rate;
	threshold_level_local_var->var_packet_loss_rate = var_packet_loss_rate;
	threshold_level_local_var->is_svc_exp_level = is_svc_exp_level;
	threshold_level_local_var->svc_exp_level = svc_exp_level;
	threshold_level_local_var->is_speed = is_speed;
	threshold_level_local_var->speed = speed;

	return threshold_level_local_var;
}

void threshold_level_free(threshold_level_t *threshold_level) {
	lnode_t *node = NULL;

	if(NULL == threshold_level) {
		return;
	}
	if(threshold_level->avg_traffic_rate) {
		free(threshold_level->avg_traffic_rate);
		threshold_level->avg_traffic_rate = NULL;
	}
	if(threshold_level->max_traffic_rate) {
		free(threshold_level->max_traffic_rate);
		threshold_level->max_traffic_rate = NULL;
	}
	if(threshold_level->min_traffic_rate) {
		free(threshold_level->min_traffic_rate);
		threshold_level->min_traffic_rate = NULL;
	}
	if(threshold_level->agg_traffic_rate) {
		free(threshold_level->agg_traffic_rate);
		threshold_level->agg_traffic_rate = NULL;
	}
	free(threshold_level);
}

cJSON *threshold_level_convertToJSON(threshold_level_t *threshold_level) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(threshold_level == NULL) {
		printf("threshold_level_convertToJSON() failed [ThresholdLevel]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(threshold_level->is_cong_level) {
		if(cJSON_AddNumberToObject(item, "congLevel",
		                           threshold_level->cong_level) == NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [cong_level]");
			goto end;
		}
	}

	if(threshold_level->is_nf_load_level) {
		if(cJSON_AddNumberToObject(item, "nfLoadLevel",
		                           threshold_level->nf_load_level) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [nf_load_level]");
			goto end;
		}
	}

	if(threshold_level->is_nf_cpu_usage) {
		if(cJSON_AddNumberToObject(item, "nfCpuUsage",
		                           threshold_level->nf_cpu_usage) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [nf_cpu_usage]");
			goto end;
		}
	}

	if(threshold_level->is_nf_memory_usage) {
		if(cJSON_AddNumberToObject(item, "nfMemoryUsage",
		                           threshold_level->nf_memory_usage) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [nf_memory_usage]");
			goto end;
		}
	}

	if(threshold_level->is_nf_storage_usage) {
		if(cJSON_AddNumberToObject(item, "nfStorageUsage",
		                           threshold_level->nf_storage_usage) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [nf_storage_usage]");
			goto end;
		}
	}

	if(threshold_level->avg_traffic_rate) {
		if(cJSON_AddStringToObject(item, "avgTrafficRate",
		                           threshold_level->avg_traffic_rate) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [avg_traffic_rate]");
			goto end;
		}
	}

	if(threshold_level->max_traffic_rate) {
		if(cJSON_AddStringToObject(item, "maxTrafficRate",
		                           threshold_level->max_traffic_rate) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [max_traffic_rate]");
			goto end;
		}
	}

	if(threshold_level->min_traffic_rate) {
		if(cJSON_AddStringToObject(item, "minTrafficRate",
		                           threshold_level->min_traffic_rate) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [min_traffic_rate]");
			goto end;
		}
	}

	if(threshold_level->agg_traffic_rate) {
		if(cJSON_AddStringToObject(item, "aggTrafficRate",
		                           threshold_level->agg_traffic_rate) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [agg_traffic_rate]");
			goto end;
		}
	}

	if(threshold_level->is_var_traffic_rate) {
		if(cJSON_AddNumberToObject(item, "varTrafficRate",
		                           threshold_level->var_traffic_rate) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [var_traffic_rate]");
			goto end;
		}
	}

	if(threshold_level->is_avg_packet_delay) {
		if(cJSON_AddNumberToObject(item, "avgPacketDelay",
		                           threshold_level->avg_packet_delay) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [avg_packet_delay]");
			goto end;
		}
	}

	if(threshold_level->is_max_packet_delay) {
		if(cJSON_AddNumberToObject(item, "maxPacketDelay",
		                           threshold_level->max_packet_delay) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [max_packet_delay]");
			goto end;
		}
	}

	if(threshold_level->is_var_packet_delay) {
		if(cJSON_AddNumberToObject(item, "varPacketDelay",
		                           threshold_level->var_packet_delay) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [var_packet_delay]");
			goto end;
		}
	}

	if(threshold_level->is_avg_packet_loss_rate) {
		if(cJSON_AddNumberToObject(item, "avgPacketLossRate",
		                           threshold_level->avg_packet_loss_rate)
		   == NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [avg_packet_loss_rate]");
			goto end;
		}
	}

	if(threshold_level->is_max_packet_loss_rate) {
		if(cJSON_AddNumberToObject(item, "maxPacketLossRate",
		                           threshold_level->max_packet_loss_rate)
		   == NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [max_packet_loss_rate]");
			goto end;
		}
	}

	if(threshold_level->is_var_packet_loss_rate) {
		if(cJSON_AddNumberToObject(item, "varPacketLossRate",
		                           threshold_level->var_packet_loss_rate)
		   == NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [var_packet_loss_rate]");
			goto end;
		}
	}

	if(threshold_level->is_svc_exp_level) {
		if(cJSON_AddNumberToObject(item, "svcExpLevel",
		                           threshold_level->svc_exp_level) ==
		   NULL)
		{
			printf(
				"threshold_level_convertToJSON() failed [svc_exp_level]");
			goto end;
		}
	}

	if(threshold_level->is_speed) {
		if(cJSON_AddNumberToObject(item, "speed",
		                           threshold_level->speed) == NULL)
		{
			printf("threshold_level_convertToJSON() failed [speed]");
			goto end;
		}
	}

end:
	return item;
}

threshold_level_t *threshold_level_parseFromJSON(cJSON *threshold_levelJSON) {
	threshold_level_t *threshold_level_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *cong_level = NULL;
	cJSON *nf_load_level = NULL;
	cJSON *nf_cpu_usage = NULL;
	cJSON *nf_memory_usage = NULL;
	cJSON *nf_storage_usage = NULL;
	cJSON *avg_traffic_rate = NULL;
	cJSON *max_traffic_rate = NULL;
	cJSON *min_traffic_rate = NULL;
	cJSON *agg_traffic_rate = NULL;
	cJSON *var_traffic_rate = NULL;
	cJSON *avg_packet_delay = NULL;
	cJSON *max_packet_delay = NULL;
	cJSON *var_packet_delay = NULL;
	cJSON *avg_packet_loss_rate = NULL;
	cJSON *max_packet_loss_rate = NULL;
	cJSON *var_packet_loss_rate = NULL;
	cJSON *svc_exp_level = NULL;
	cJSON *speed = NULL;
	cong_level = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                              "congLevel");
	if(cong_level) {
		if(!cJSON_IsNumber(cong_level)) {
			printf(
				"threshold_level_parseFromJSON() failed [cong_level]");
			goto end;
		}
	}

	nf_load_level = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                 "nfLoadLevel");
	if(nf_load_level) {
		if(!cJSON_IsNumber(nf_load_level)) {
			printf(
				"threshold_level_parseFromJSON() failed [nf_load_level]");
			goto end;
		}
	}

	nf_cpu_usage = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                "nfCpuUsage");
	if(nf_cpu_usage) {
		if(!cJSON_IsNumber(nf_cpu_usage)) {
			printf(
				"threshold_level_parseFromJSON() failed [nf_cpu_usage]");
			goto end;
		}
	}

	nf_memory_usage = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                   "nfMemoryUsage");
	if(nf_memory_usage) {
		if(!cJSON_IsNumber(nf_memory_usage)) {
			printf(
				"threshold_level_parseFromJSON() failed [nf_memory_usage]");
			goto end;
		}
	}

	nf_storage_usage = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                    "nfStorageUsage");
	if(nf_storage_usage) {
		if(!cJSON_IsNumber(nf_storage_usage)) {
			printf(
				"threshold_level_parseFromJSON() failed [nf_storage_usage]");
			goto end;
		}
	}

	avg_traffic_rate = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                    "avgTrafficRate");
	if(avg_traffic_rate) {
		if(!cJSON_IsString(avg_traffic_rate) &&
		   !cJSON_IsNull(avg_traffic_rate))
		{
			printf(
				"threshold_level_parseFromJSON() failed [avg_traffic_rate]");
			goto end;
		}
	}

	max_traffic_rate = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                    "maxTrafficRate");
	if(max_traffic_rate) {
		if(!cJSON_IsString(max_traffic_rate) &&
		   !cJSON_IsNull(max_traffic_rate))
		{
			printf(
				"threshold_level_parseFromJSON() failed [max_traffic_rate]");
			goto end;
		}
	}

	min_traffic_rate = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                    "minTrafficRate");
	if(min_traffic_rate) {
		if(!cJSON_IsString(min_traffic_rate) &&
		   !cJSON_IsNull(min_traffic_rate))
		{
			printf(
				"threshold_level_parseFromJSON() failed [min_traffic_rate]");
			goto end;
		}
	}

	agg_traffic_rate = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                    "aggTrafficRate");
	if(agg_traffic_rate) {
		if(!cJSON_IsString(agg_traffic_rate) &&
		   !cJSON_IsNull(agg_traffic_rate))
		{
			printf(
				"threshold_level_parseFromJSON() failed [agg_traffic_rate]");
			goto end;
		}
	}

	var_traffic_rate = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                    "varTrafficRate");
	if(var_traffic_rate) {
		if(!cJSON_IsNumber(var_traffic_rate)) {
			printf(
				"threshold_level_parseFromJSON() failed [var_traffic_rate]");
			goto end;
		}
	}

	avg_packet_delay = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                    "avgPacketDelay");
	if(avg_packet_delay) {
		if(!cJSON_IsNumber(avg_packet_delay)) {
			printf(
				"threshold_level_parseFromJSON() failed [avg_packet_delay]");
			goto end;
		}
	}

	max_packet_delay = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                    "maxPacketDelay");
	if(max_packet_delay) {
		if(!cJSON_IsNumber(max_packet_delay)) {
			printf(
				"threshold_level_parseFromJSON() failed [max_packet_delay]");
			goto end;
		}
	}

	var_packet_delay = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                    "varPacketDelay");
	if(var_packet_delay) {
		if(!cJSON_IsNumber(var_packet_delay)) {
			printf(
				"threshold_level_parseFromJSON() failed [var_packet_delay]");
			goto end;
		}
	}

	avg_packet_loss_rate = cJSON_GetObjectItemCaseSensitive(
		threshold_levelJSON, "avgPacketLossRate");
	if(avg_packet_loss_rate) {
		if(!cJSON_IsNumber(avg_packet_loss_rate)) {
			printf(
				"threshold_level_parseFromJSON() failed [avg_packet_loss_rate]");
			goto end;
		}
	}

	max_packet_loss_rate = cJSON_GetObjectItemCaseSensitive(
		threshold_levelJSON, "maxPacketLossRate");
	if(max_packet_loss_rate) {
		if(!cJSON_IsNumber(max_packet_loss_rate)) {
			printf(
				"threshold_level_parseFromJSON() failed [max_packet_loss_rate]");
			goto end;
		}
	}

	var_packet_loss_rate = cJSON_GetObjectItemCaseSensitive(
		threshold_levelJSON, "varPacketLossRate");
	if(var_packet_loss_rate) {
		if(!cJSON_IsNumber(var_packet_loss_rate)) {
			printf(
				"threshold_level_parseFromJSON() failed [var_packet_loss_rate]");
			goto end;
		}
	}

	svc_exp_level = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON,
	                                                 "svcExpLevel");
	if(svc_exp_level) {
		if(!cJSON_IsNumber(svc_exp_level)) {
			printf(
				"threshold_level_parseFromJSON() failed [svc_exp_level]");
			goto end;
		}
	}

	speed = cJSON_GetObjectItemCaseSensitive(threshold_levelJSON, "speed");
	if(speed) {
		if(!cJSON_IsNumber(speed)) {
			printf("threshold_level_parseFromJSON() failed [speed]");
			goto end;
		}
	}

	threshold_level_local_var = threshold_level_create(
		cong_level ? true : false,
		cong_level ? cong_level->valuedouble : 0,
		nf_load_level ? true : false,
		nf_load_level ? nf_load_level->valuedouble : 0,
		nf_cpu_usage ? true : false,
		nf_cpu_usage ? nf_cpu_usage->valuedouble : 0,
		nf_memory_usage ? true : false,
		nf_memory_usage ? nf_memory_usage->valuedouble : 0,
		nf_storage_usage ? true : false,
		nf_storage_usage ? nf_storage_usage->valuedouble : 0,
		avg_traffic_rate &&
		!cJSON_IsNull(avg_traffic_rate) ? strdup(avg_traffic_rate->
		                                         valuestring) : NULL,
		max_traffic_rate &&
		!cJSON_IsNull(max_traffic_rate) ? strdup(max_traffic_rate->
		                                         valuestring) : NULL,
		min_traffic_rate &&
		!cJSON_IsNull(min_traffic_rate) ? strdup(min_traffic_rate->
		                                         valuestring) : NULL,
		agg_traffic_rate &&
		!cJSON_IsNull(agg_traffic_rate) ? strdup(agg_traffic_rate->
		                                         valuestring) : NULL,
		var_traffic_rate ? true : false,
		var_traffic_rate ? var_traffic_rate->valuedouble : 0,
		avg_packet_delay ? true : false,
		avg_packet_delay ? avg_packet_delay->valuedouble : 0,
		max_packet_delay ? true : false,
		max_packet_delay ? max_packet_delay->valuedouble : 0,
		var_packet_delay ? true : false,
		var_packet_delay ? var_packet_delay->valuedouble : 0,
		avg_packet_loss_rate ? true : false,
		avg_packet_loss_rate ? avg_packet_loss_rate->valuedouble : 0,
		max_packet_loss_rate ? true : false,
		max_packet_loss_rate ? max_packet_loss_rate->valuedouble : 0,
		var_packet_loss_rate ? true : false,
		var_packet_loss_rate ? var_packet_loss_rate->valuedouble : 0,
		svc_exp_level ? true : false,
		svc_exp_level ? svc_exp_level->valuedouble : 0,
		speed ? true : false,
		speed ? speed->valuedouble : 0
		);

	return threshold_level_local_var;
end:
	return NULL;
}

threshold_level_t *threshold_level_copy(threshold_level_t	*dst,
                                        threshold_level_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = threshold_level_convertToJSON(src);
	if(!item) {
		printf("threshold_level_convertToJSON() failed");
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

	threshold_level_free(dst);
	dst = threshold_level_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
