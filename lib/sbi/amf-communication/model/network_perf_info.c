#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_perf_info.h"

network_perf_info_t *network_perf_info_create(network_area_info_t *network_area,
                                              network_perf_type_t *nw_perf_type,
                                              time_window_t *ana_period,
                                              bool is_relative_ratio,
                                              int relative_ratio,
                                              bool is_absolute_num,
                                              int absolute_num,
                                              resource_usage_requirement_t *rsc_usg_req, bool is_confidence,
                                              int confidence) {
	network_perf_info_t *network_perf_info_local_var =
		malloc(sizeof(network_perf_info_t));

	network_perf_info_local_var->network_area = network_area;
	network_perf_info_local_var->nw_perf_type = nw_perf_type;
	network_perf_info_local_var->ana_period = ana_period;
	network_perf_info_local_var->is_relative_ratio = is_relative_ratio;
	network_perf_info_local_var->relative_ratio = relative_ratio;
	network_perf_info_local_var->is_absolute_num = is_absolute_num;
	network_perf_info_local_var->absolute_num = absolute_num;
	network_perf_info_local_var->rsc_usg_req = rsc_usg_req;
	network_perf_info_local_var->is_confidence = is_confidence;
	network_perf_info_local_var->confidence = confidence;

	return network_perf_info_local_var;
}

void network_perf_info_free(network_perf_info_t *network_perf_info) {
	lnode_t *node = NULL;

	if(NULL == network_perf_info) {
		return;
	}
	if(network_perf_info->network_area) {
		network_area_info_free(network_perf_info->network_area);
		network_perf_info->network_area = NULL;
	}
	if(network_perf_info->nw_perf_type) {
		network_perf_type_free(network_perf_info->nw_perf_type);
		network_perf_info->nw_perf_type = NULL;
	}
	if(network_perf_info->ana_period) {
		time_window_free(network_perf_info->ana_period);
		network_perf_info->ana_period = NULL;
	}
	if(network_perf_info->rsc_usg_req) {
		resource_usage_requirement_free(network_perf_info->rsc_usg_req);
		network_perf_info->rsc_usg_req = NULL;
	}
	free(network_perf_info);
}

cJSON *network_perf_info_convertToJSON(network_perf_info_t *network_perf_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(network_perf_info == NULL) {
		printf(
			"network_perf_info_convertToJSON() failed [NetworkPerfInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(network_perf_info->network_area) {
		cJSON *network_area_local_JSON =
			network_area_info_convertToJSON(
				network_perf_info->network_area);
		if(network_area_local_JSON == NULL) {
			printf(
				"network_perf_info_convertToJSON() failed [network_area]");
			goto end;
		}
		cJSON_AddItemToObject(item, "networkArea",
		                      network_area_local_JSON);
		if(item->child == NULL) {
			printf(
				"network_perf_info_convertToJSON() failed [network_area]");
			goto end;
		}
	}

	if(network_perf_info->nw_perf_type) {
		cJSON *nw_perf_type_local_JSON =
			network_perf_type_convertToJSON(
				network_perf_info->nw_perf_type);
		if(nw_perf_type_local_JSON == NULL) {
			printf(
				"network_perf_info_convertToJSON() failed [nw_perf_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "nwPerfType",
		                      nw_perf_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"network_perf_info_convertToJSON() failed [nw_perf_type]");
			goto end;
		}
	}

	if(network_perf_info->ana_period) {
		cJSON *ana_period_local_JSON = time_window_convertToJSON(
			network_perf_info->ana_period);
		if(ana_period_local_JSON == NULL) {
			printf(
				"network_perf_info_convertToJSON() failed [ana_period]");
			goto end;
		}
		cJSON_AddItemToObject(item, "anaPeriod", ana_period_local_JSON);
		if(item->child == NULL) {
			printf(
				"network_perf_info_convertToJSON() failed [ana_period]");
			goto end;
		}
	}

	if(network_perf_info->is_relative_ratio) {
		if(cJSON_AddNumberToObject(item, "relativeRatio",
		                           network_perf_info->relative_ratio) ==
		   NULL)
		{
			printf(
				"network_perf_info_convertToJSON() failed [relative_ratio]");
			goto end;
		}
	}

	if(network_perf_info->is_absolute_num) {
		if(cJSON_AddNumberToObject(item, "absoluteNum",
		                           network_perf_info->absolute_num) ==
		   NULL)
		{
			printf(
				"network_perf_info_convertToJSON() failed [absolute_num]");
			goto end;
		}
	}

	if(network_perf_info->rsc_usg_req) {
		cJSON *rsc_usg_req_local_JSON =
			resource_usage_requirement_convertToJSON(
				network_perf_info->rsc_usg_req);
		if(rsc_usg_req_local_JSON == NULL) {
			printf(
				"network_perf_info_convertToJSON() failed [rsc_usg_req]");
			goto end;
		}
		cJSON_AddItemToObject(item, "rscUsgReq",
		                      rsc_usg_req_local_JSON);
		if(item->child == NULL) {
			printf(
				"network_perf_info_convertToJSON() failed [rsc_usg_req]");
			goto end;
		}
	}

	if(network_perf_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           network_perf_info->confidence) ==
		   NULL)
		{
			printf(
				"network_perf_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

end:
	return item;
}

network_perf_info_t *network_perf_info_parseFromJSON(
	cJSON *network_perf_infoJSON) {
	network_perf_info_t *network_perf_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *network_area = NULL;
	network_area_info_t *network_area_local_nonprim = NULL;
	cJSON *nw_perf_type = NULL;
	network_perf_type_t *nw_perf_type_local_nonprim = NULL;
	cJSON *ana_period = NULL;
	time_window_t *ana_period_local_nonprim = NULL;
	cJSON *relative_ratio = NULL;
	cJSON *absolute_num = NULL;
	cJSON *rsc_usg_req = NULL;
	resource_usage_requirement_t *rsc_usg_req_local_nonprim = NULL;
	cJSON *confidence = NULL;
	network_area = cJSON_GetObjectItemCaseSensitive(network_perf_infoJSON,
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

	nw_perf_type = cJSON_GetObjectItemCaseSensitive(network_perf_infoJSON,
	                                                "nwPerfType");
	if(nw_perf_type) {
		nw_perf_type_local_nonprim = network_perf_type_parseFromJSON(
			nw_perf_type);
		if(!nw_perf_type_local_nonprim) {
			printf(
				"network_perf_type_parseFromJSON failed [nw_perf_type]");
			goto end;
		}
	}

	ana_period = cJSON_GetObjectItemCaseSensitive(network_perf_infoJSON,
	                                              "anaPeriod");
	if(ana_period) {
		ana_period_local_nonprim =
			time_window_parseFromJSON(ana_period);
		if(!ana_period_local_nonprim) {
			printf("time_window_parseFromJSON failed [ana_period]");
			goto end;
		}
	}

	relative_ratio = cJSON_GetObjectItemCaseSensitive(network_perf_infoJSON,
	                                                  "relativeRatio");
	if(relative_ratio) {
		if(!cJSON_IsNumber(relative_ratio)) {
			printf(
				"network_perf_info_parseFromJSON() failed [relative_ratio]");
			goto end;
		}
	}

	absolute_num = cJSON_GetObjectItemCaseSensitive(network_perf_infoJSON,
	                                                "absoluteNum");
	if(absolute_num) {
		if(!cJSON_IsNumber(absolute_num)) {
			printf(
				"network_perf_info_parseFromJSON() failed [absolute_num]");
			goto end;
		}
	}

	rsc_usg_req = cJSON_GetObjectItemCaseSensitive(network_perf_infoJSON,
	                                               "rscUsgReq");
	if(rsc_usg_req) {
		rsc_usg_req_local_nonprim =
			resource_usage_requirement_parseFromJSON(rsc_usg_req);
		if(!rsc_usg_req_local_nonprim) {
			printf(
				"resource_usage_requirement_parseFromJSON failed [rsc_usg_req]");
			goto end;
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(network_perf_infoJSON,
	                                              "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"network_perf_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	network_perf_info_local_var = network_perf_info_create(
		network_area ? network_area_local_nonprim : NULL,
		nw_perf_type ? nw_perf_type_local_nonprim : NULL,
		ana_period ? ana_period_local_nonprim : NULL,
		relative_ratio ? true : false,
		relative_ratio ? relative_ratio->valuedouble : 0,
		absolute_num ? true : false,
		absolute_num ? absolute_num->valuedouble : 0,
		rsc_usg_req ? rsc_usg_req_local_nonprim : NULL,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0
		);

	return network_perf_info_local_var;
end:
	if(network_area_local_nonprim) {
		network_area_info_free(network_area_local_nonprim);
		network_area_local_nonprim = NULL;
	}
	if(nw_perf_type_local_nonprim) {
		network_perf_type_free(nw_perf_type_local_nonprim);
		nw_perf_type_local_nonprim = NULL;
	}
	if(ana_period_local_nonprim) {
		time_window_free(ana_period_local_nonprim);
		ana_period_local_nonprim = NULL;
	}
	if(rsc_usg_req_local_nonprim) {
		resource_usage_requirement_free(rsc_usg_req_local_nonprim);
		rsc_usg_req_local_nonprim = NULL;
	}
	return NULL;
}

network_perf_info_t *network_perf_info_copy(network_perf_info_t *dst,
                                            network_perf_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = network_perf_info_convertToJSON(src);
	if(!item) {
		printf("network_perf_info_convertToJSON() failed");
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

	network_perf_info_free(dst);
	dst = network_perf_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
