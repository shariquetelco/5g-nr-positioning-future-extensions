#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dn_performance_req.h"

dn_performance_req_t *dn_performance_req_create(
	dn_perf_ordering_criterion_t *dn_perf_order_criter,
	matching_direction_t *order, list_t *report_thresholds) {
	dn_performance_req_t *dn_performance_req_local_var =
		malloc(sizeof(dn_performance_req_t));

	dn_performance_req_local_var->dn_perf_order_criter =
		dn_perf_order_criter;
	dn_performance_req_local_var->order = order;
	dn_performance_req_local_var->report_thresholds = report_thresholds;

	return dn_performance_req_local_var;
}

void dn_performance_req_free(dn_performance_req_t *dn_performance_req) {
	lnode_t *node = NULL;

	if(NULL == dn_performance_req) {
		return;
	}
	if(dn_performance_req->dn_perf_order_criter) {
		dn_perf_ordering_criterion_free(
			dn_performance_req->dn_perf_order_criter);
		dn_performance_req->dn_perf_order_criter = NULL;
	}
	if(dn_performance_req->order) {
		matching_direction_free(dn_performance_req->order);
		dn_performance_req->order = NULL;
	}
	if(dn_performance_req->report_thresholds) {
		list_for_each(dn_performance_req->report_thresholds, node) {
			threshold_level_free(node->data);
		}
		list_free(dn_performance_req->report_thresholds);
		dn_performance_req->report_thresholds = NULL;
	}
	free(dn_performance_req);
}

cJSON *dn_performance_req_convertToJSON(
	dn_performance_req_t *dn_performance_req) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dn_performance_req == NULL) {
		printf(
			"dn_performance_req_convertToJSON() failed [DnPerformanceReq]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(dn_performance_req->dn_perf_order_criter) {
		cJSON *dn_perf_order_criter_local_JSON =
			dn_perf_ordering_criterion_convertToJSON(
				dn_performance_req->dn_perf_order_criter);
		if(dn_perf_order_criter_local_JSON == NULL) {
			printf(
				"dn_performance_req_convertToJSON() failed [dn_perf_order_criter]");
			goto end;
		}
		cJSON_AddItemToObject(item, "dnPerfOrderCriter",
		                      dn_perf_order_criter_local_JSON);
		if(item->child == NULL) {
			printf(
				"dn_performance_req_convertToJSON() failed [dn_perf_order_criter]");
			goto end;
		}
	}

	if(dn_performance_req->order) {
		cJSON *order_local_JSON = matching_direction_convertToJSON(
			dn_performance_req->order);
		if(order_local_JSON == NULL) {
			printf(
				"dn_performance_req_convertToJSON() failed [order]");
			goto end;
		}
		cJSON_AddItemToObject(item, "order", order_local_JSON);
		if(item->child == NULL) {
			printf(
				"dn_performance_req_convertToJSON() failed [order]");
			goto end;
		}
	}

	if(dn_performance_req->report_thresholds) {
		cJSON *report_thresholdsList = cJSON_AddArrayToObject(item,
		                                                      "reportThresholds");
		if(report_thresholdsList == NULL) {
			printf(
				"dn_performance_req_convertToJSON() failed [report_thresholds]");
			goto end;
		}
		list_for_each(dn_performance_req->report_thresholds, node) {
			cJSON *itemLocal = threshold_level_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"dn_performance_req_convertToJSON() failed [report_thresholds]");
				goto end;
			}
			cJSON_AddItemToArray(report_thresholdsList, itemLocal);
		}
	}

end:
	return item;
}

dn_performance_req_t *dn_performance_req_parseFromJSON(
	cJSON *dn_performance_reqJSON) {
	dn_performance_req_t *dn_performance_req_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *dn_perf_order_criter = NULL;
	dn_perf_ordering_criterion_t *dn_perf_order_criter_local_nonprim = NULL;
	cJSON *order = NULL;
	matching_direction_t *order_local_nonprim = NULL;
	cJSON *report_thresholds = NULL;
	list_t *report_thresholdsList = NULL;
	dn_perf_order_criter = cJSON_GetObjectItemCaseSensitive(
		dn_performance_reqJSON, "dnPerfOrderCriter");
	if(dn_perf_order_criter) {
		dn_perf_order_criter_local_nonprim =
			dn_perf_ordering_criterion_parseFromJSON(
				dn_perf_order_criter);
		if(!dn_perf_order_criter_local_nonprim) {
			printf(
				"dn_perf_ordering_criterion_parseFromJSON failed [dn_perf_order_criter]");
			goto end;
		}
	}

	order =
		cJSON_GetObjectItemCaseSensitive(dn_performance_reqJSON,
		                                 "order");
	if(order) {
		order_local_nonprim = matching_direction_parseFromJSON(order);
		if(!order_local_nonprim) {
			printf("matching_direction_parseFromJSON failed [order]");
			goto end;
		}
	}

	report_thresholds = cJSON_GetObjectItemCaseSensitive(
		dn_performance_reqJSON, "reportThresholds");
	if(report_thresholds) {
		cJSON *report_thresholds_local = NULL;
		if(!cJSON_IsArray(report_thresholds)) {
			printf(
				"dn_performance_req_parseFromJSON() failed [report_thresholds]");
			goto end;
		}

		report_thresholdsList = list_create();

		cJSON_ArrayForEach(report_thresholds_local, report_thresholds) {
			if(!cJSON_IsObject(report_thresholds_local)) {
				printf(
					"dn_performance_req_parseFromJSON() failed [report_thresholds]");
				goto end;
			}
			threshold_level_t *report_thresholdsItem =
				threshold_level_parseFromJSON(
					report_thresholds_local);
			if(!report_thresholdsItem) {
				printf("No report_thresholdsItem");
				goto end;
			}
			list_add(report_thresholdsList, report_thresholdsItem);
		}
	}

	dn_performance_req_local_var = dn_performance_req_create(
		dn_perf_order_criter ? dn_perf_order_criter_local_nonprim : NULL,
		order ? order_local_nonprim : NULL,
		report_thresholds ? report_thresholdsList : NULL
		);

	return dn_performance_req_local_var;
end:
	if(dn_perf_order_criter_local_nonprim) {
		dn_perf_ordering_criterion_free(
			dn_perf_order_criter_local_nonprim);
		dn_perf_order_criter_local_nonprim = NULL;
	}
	if(order_local_nonprim) {
		matching_direction_free(order_local_nonprim);
		order_local_nonprim = NULL;
	}
	if(report_thresholdsList) {
		list_for_each(report_thresholdsList, node) {
			threshold_level_free(node->data);
		}
		list_free(report_thresholdsList);
		report_thresholdsList = NULL;
	}
	return NULL;
}

dn_performance_req_t *dn_performance_req_copy(dn_performance_req_t	*dst,
                                              dn_performance_req_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dn_performance_req_convertToJSON(src);
	if(!item) {
		printf("dn_performance_req_convertToJSON() failed");
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

	dn_performance_req_free(dst);
	dst = dn_performance_req_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
