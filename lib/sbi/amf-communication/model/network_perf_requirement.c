#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_perf_requirement.h"

network_perf_requirement_t *network_perf_requirement_create(
	network_perf_type_t *nw_perf_type, bool is_relative_ratio,
	int relative_ratio, bool is_absolute_num, int absolute_num,
	network_perf_order_criterion_t *order_criterion,
	resource_usage_requirement_t *rsc_usg_req) {
	network_perf_requirement_t *network_perf_requirement_local_var = malloc(
		sizeof(network_perf_requirement_t));

	network_perf_requirement_local_var->nw_perf_type = nw_perf_type;
	network_perf_requirement_local_var->is_relative_ratio =
		is_relative_ratio;
	network_perf_requirement_local_var->relative_ratio = relative_ratio;
	network_perf_requirement_local_var->is_absolute_num = is_absolute_num;
	network_perf_requirement_local_var->absolute_num = absolute_num;
	network_perf_requirement_local_var->order_criterion = order_criterion;
	network_perf_requirement_local_var->rsc_usg_req = rsc_usg_req;

	return network_perf_requirement_local_var;
}

void network_perf_requirement_free(
	network_perf_requirement_t *network_perf_requirement) {
	lnode_t *node = NULL;

	if(NULL == network_perf_requirement) {
		return;
	}
	if(network_perf_requirement->nw_perf_type) {
		network_perf_type_free(network_perf_requirement->nw_perf_type);
		network_perf_requirement->nw_perf_type = NULL;
	}
	if(network_perf_requirement->order_criterion) {
		network_perf_order_criterion_free(
			network_perf_requirement->order_criterion);
		network_perf_requirement->order_criterion = NULL;
	}
	if(network_perf_requirement->rsc_usg_req) {
		resource_usage_requirement_free(
			network_perf_requirement->rsc_usg_req);
		network_perf_requirement->rsc_usg_req = NULL;
	}
	free(network_perf_requirement);
}

cJSON *network_perf_requirement_convertToJSON(
	network_perf_requirement_t *network_perf_requirement) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(network_perf_requirement == NULL) {
		printf(
			"network_perf_requirement_convertToJSON() failed [NetworkPerfRequirement]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!network_perf_requirement->nw_perf_type) {
		printf(
			"network_perf_requirement_convertToJSON() failed [nw_perf_type]");
		return NULL;
	}
	cJSON *nw_perf_type_local_JSON = network_perf_type_convertToJSON(
		network_perf_requirement->nw_perf_type);
	if(nw_perf_type_local_JSON == NULL) {
		printf(
			"network_perf_requirement_convertToJSON() failed [nw_perf_type]");
		goto end;
	}
	cJSON_AddItemToObject(item, "nwPerfType", nw_perf_type_local_JSON);
	if(item->child == NULL) {
		printf(
			"network_perf_requirement_convertToJSON() failed [nw_perf_type]");
		goto end;
	}

	if(network_perf_requirement->is_relative_ratio) {
		if(cJSON_AddNumberToObject(item, "relativeRatio",
		                           network_perf_requirement->
		                           relative_ratio) == NULL)
		{
			printf(
				"network_perf_requirement_convertToJSON() failed [relative_ratio]");
			goto end;
		}
	}

	if(network_perf_requirement->is_absolute_num) {
		if(cJSON_AddNumberToObject(item, "absoluteNum",
		                           network_perf_requirement->
		                           absolute_num) == NULL)
		{
			printf(
				"network_perf_requirement_convertToJSON() failed [absolute_num]");
			goto end;
		}
	}

	if(network_perf_requirement->order_criterion) {
		cJSON *order_criterion_local_JSON =
			network_perf_order_criterion_convertToJSON(
				network_perf_requirement->order_criterion);
		if(order_criterion_local_JSON == NULL) {
			printf(
				"network_perf_requirement_convertToJSON() failed [order_criterion]");
			goto end;
		}
		cJSON_AddItemToObject(item, "orderCriterion",
		                      order_criterion_local_JSON);
		if(item->child == NULL) {
			printf(
				"network_perf_requirement_convertToJSON() failed [order_criterion]");
			goto end;
		}
	}

	if(network_perf_requirement->rsc_usg_req) {
		cJSON *rsc_usg_req_local_JSON =
			resource_usage_requirement_convertToJSON(
				network_perf_requirement->rsc_usg_req);
		if(rsc_usg_req_local_JSON == NULL) {
			printf(
				"network_perf_requirement_convertToJSON() failed [rsc_usg_req]");
			goto end;
		}
		cJSON_AddItemToObject(item, "rscUsgReq",
		                      rsc_usg_req_local_JSON);
		if(item->child == NULL) {
			printf(
				"network_perf_requirement_convertToJSON() failed [rsc_usg_req]");
			goto end;
		}
	}

end:
	return item;
}

network_perf_requirement_t *network_perf_requirement_parseFromJSON(
	cJSON *network_perf_requirementJSON) {
	network_perf_requirement_t *network_perf_requirement_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *nw_perf_type = NULL;
	network_perf_type_t *nw_perf_type_local_nonprim = NULL;
	cJSON *relative_ratio = NULL;
	cJSON *absolute_num = NULL;
	cJSON *order_criterion = NULL;
	network_perf_order_criterion_t *order_criterion_local_nonprim = NULL;
	cJSON *rsc_usg_req = NULL;
	resource_usage_requirement_t *rsc_usg_req_local_nonprim = NULL;
	nw_perf_type = cJSON_GetObjectItemCaseSensitive(
		network_perf_requirementJSON, "nwPerfType");
	if(!nw_perf_type) {
		printf(
			"network_perf_requirement_parseFromJSON() failed [nw_perf_type]");
		goto end;
	}
	nw_perf_type_local_nonprim = network_perf_type_parseFromJSON(
		nw_perf_type);
	if(!nw_perf_type_local_nonprim) {
		printf("network_perf_type_parseFromJSON failed [nw_perf_type]");
		goto end;
	}

	relative_ratio = cJSON_GetObjectItemCaseSensitive(
		network_perf_requirementJSON, "relativeRatio");
	if(relative_ratio) {
		if(!cJSON_IsNumber(relative_ratio)) {
			printf(
				"network_perf_requirement_parseFromJSON() failed [relative_ratio]");
			goto end;
		}
	}

	absolute_num = cJSON_GetObjectItemCaseSensitive(
		network_perf_requirementJSON, "absoluteNum");
	if(absolute_num) {
		if(!cJSON_IsNumber(absolute_num)) {
			printf(
				"network_perf_requirement_parseFromJSON() failed [absolute_num]");
			goto end;
		}
	}

	order_criterion = cJSON_GetObjectItemCaseSensitive(
		network_perf_requirementJSON, "orderCriterion");
	if(order_criterion) {
		order_criterion_local_nonprim =
			network_perf_order_criterion_parseFromJSON(
				order_criterion);
		if(!order_criterion_local_nonprim) {
			printf(
				"network_perf_order_criterion_parseFromJSON failed [order_criterion]");
			goto end;
		}
	}

	rsc_usg_req = cJSON_GetObjectItemCaseSensitive(
		network_perf_requirementJSON, "rscUsgReq");
	if(rsc_usg_req) {
		rsc_usg_req_local_nonprim =
			resource_usage_requirement_parseFromJSON(rsc_usg_req);
		if(!rsc_usg_req_local_nonprim) {
			printf(
				"resource_usage_requirement_parseFromJSON failed [rsc_usg_req]");
			goto end;
		}
	}

	network_perf_requirement_local_var = network_perf_requirement_create(
		nw_perf_type_local_nonprim,
		relative_ratio ? true : false,
		relative_ratio ? relative_ratio->valuedouble : 0,
		absolute_num ? true : false,
		absolute_num ? absolute_num->valuedouble : 0,
		order_criterion ? order_criterion_local_nonprim : NULL,
		rsc_usg_req ? rsc_usg_req_local_nonprim : NULL
		);

	return network_perf_requirement_local_var;
end:
	if(nw_perf_type_local_nonprim) {
		network_perf_type_free(nw_perf_type_local_nonprim);
		nw_perf_type_local_nonprim = NULL;
	}
	if(order_criterion_local_nonprim) {
		network_perf_order_criterion_free(order_criterion_local_nonprim);
		order_criterion_local_nonprim = NULL;
	}
	if(rsc_usg_req_local_nonprim) {
		resource_usage_requirement_free(rsc_usg_req_local_nonprim);
		rsc_usg_req_local_nonprim = NULL;
	}
	return NULL;
}

network_perf_requirement_t *network_perf_requirement_copy(
	network_perf_requirement_t *dst, network_perf_requirement_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = network_perf_requirement_convertToJSON(src);
	if(!item) {
		printf("network_perf_requirement_convertToJSON() failed");
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

	network_perf_requirement_free(dst);
	dst = network_perf_requirement_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
