#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_mobility_req.h"

ue_mobility_req_t *ue_mobility_req_create(
	ue_mobility_order_criterion_t *order_criterion,
	matching_direction_t *order_direction, bool is_ue_loc_order_ind,
	int ue_loc_order_ind, list_t *dist_thresholds) {
	ue_mobility_req_t *ue_mobility_req_local_var =
		malloc(sizeof(ue_mobility_req_t));

	ue_mobility_req_local_var->order_criterion = order_criterion;
	ue_mobility_req_local_var->order_direction = order_direction;
	ue_mobility_req_local_var->is_ue_loc_order_ind = is_ue_loc_order_ind;
	ue_mobility_req_local_var->ue_loc_order_ind = ue_loc_order_ind;
	ue_mobility_req_local_var->dist_thresholds = dist_thresholds;

	return ue_mobility_req_local_var;
}

void ue_mobility_req_free(ue_mobility_req_t *ue_mobility_req) {
	lnode_t *node = NULL;

	if(NULL == ue_mobility_req) {
		return;
	}
	if(ue_mobility_req->order_criterion) {
		ue_mobility_order_criterion_free(
			ue_mobility_req->order_criterion);
		ue_mobility_req->order_criterion = NULL;
	}
	if(ue_mobility_req->order_direction) {
		matching_direction_free(ue_mobility_req->order_direction);
		ue_mobility_req->order_direction = NULL;
	}
	if(ue_mobility_req->dist_thresholds) {
		list_for_each(ue_mobility_req->dist_thresholds, node) {
			free(node->data);
		}
		list_free(ue_mobility_req->dist_thresholds);
		ue_mobility_req->dist_thresholds = NULL;
	}
	free(ue_mobility_req);
}

cJSON *ue_mobility_req_convertToJSON(ue_mobility_req_t *ue_mobility_req) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_mobility_req == NULL) {
		printf("ue_mobility_req_convertToJSON() failed [UeMobilityReq]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_mobility_req->order_criterion) {
		cJSON *order_criterion_local_JSON =
			ue_mobility_order_criterion_convertToJSON(
				ue_mobility_req->order_criterion);
		if(order_criterion_local_JSON == NULL) {
			printf(
				"ue_mobility_req_convertToJSON() failed [order_criterion]");
			goto end;
		}
		cJSON_AddItemToObject(item, "orderCriterion",
		                      order_criterion_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_mobility_req_convertToJSON() failed [order_criterion]");
			goto end;
		}
	}

	if(ue_mobility_req->order_direction) {
		cJSON *order_direction_local_JSON =
			matching_direction_convertToJSON(
				ue_mobility_req->order_direction);
		if(order_direction_local_JSON == NULL) {
			printf(
				"ue_mobility_req_convertToJSON() failed [order_direction]");
			goto end;
		}
		cJSON_AddItemToObject(item, "orderDirection",
		                      order_direction_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_mobility_req_convertToJSON() failed [order_direction]");
			goto end;
		}
	}

	if(ue_mobility_req->is_ue_loc_order_ind) {
		if(cJSON_AddBoolToObject(item, "ueLocOrderInd",
		                         ue_mobility_req->ue_loc_order_ind) ==
		   NULL)
		{
			printf(
				"ue_mobility_req_convertToJSON() failed [ue_loc_order_ind]");
			goto end;
		}
	}

	if(ue_mobility_req->dist_thresholds) {
		cJSON *dist_thresholdsList = cJSON_AddArrayToObject(item,
		                                                    "distThresholds");
		if(dist_thresholdsList == NULL) {
			printf(
				"ue_mobility_req_convertToJSON() failed [dist_thresholds]");
			goto end;
		}
		list_for_each(ue_mobility_req->dist_thresholds, node) {
			if(node->data == NULL) {
				printf(
					"ue_mobility_req_convertToJSON() failed [dist_thresholds]");
				goto end;
			}
			if(cJSON_AddNumberToObject(dist_thresholdsList, "",
			                           *(double *) node->data) ==
			   NULL)
			{
				printf(
					"ue_mobility_req_convertToJSON() failed [dist_thresholds]");
				goto end;
			}
		}
	}

end:
	return item;
}

ue_mobility_req_t *ue_mobility_req_parseFromJSON(cJSON *ue_mobility_reqJSON) {
	ue_mobility_req_t *ue_mobility_req_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *order_criterion = NULL;
	ue_mobility_order_criterion_t *order_criterion_local_nonprim = NULL;
	cJSON *order_direction = NULL;
	matching_direction_t *order_direction_local_nonprim = NULL;
	cJSON *ue_loc_order_ind = NULL;
	cJSON *dist_thresholds = NULL;
	list_t *dist_thresholdsList = NULL;
	order_criterion = cJSON_GetObjectItemCaseSensitive(ue_mobility_reqJSON,
	                                                   "orderCriterion");
	if(order_criterion) {
		order_criterion_local_nonprim =
			ue_mobility_order_criterion_parseFromJSON(
				order_criterion);
		if(!order_criterion_local_nonprim) {
			printf(
				"ue_mobility_order_criterion_parseFromJSON failed [order_criterion]");
			goto end;
		}
	}

	order_direction = cJSON_GetObjectItemCaseSensitive(ue_mobility_reqJSON,
	                                                   "orderDirection");
	if(order_direction) {
		order_direction_local_nonprim =
			matching_direction_parseFromJSON(order_direction);
		if(!order_direction_local_nonprim) {
			printf(
				"matching_direction_parseFromJSON failed [order_direction]");
			goto end;
		}
	}

	ue_loc_order_ind = cJSON_GetObjectItemCaseSensitive(ue_mobility_reqJSON,
	                                                    "ueLocOrderInd");
	if(ue_loc_order_ind) {
		if(!cJSON_IsBool(ue_loc_order_ind)) {
			printf(
				"ue_mobility_req_parseFromJSON() failed [ue_loc_order_ind]");
			goto end;
		}
	}

	dist_thresholds = cJSON_GetObjectItemCaseSensitive(ue_mobility_reqJSON,
	                                                   "distThresholds");
	if(dist_thresholds) {
		cJSON *dist_thresholds_local = NULL;
		if(!cJSON_IsArray(dist_thresholds)) {
			printf(
				"ue_mobility_req_parseFromJSON() failed [dist_thresholds]");
			goto end;
		}

		dist_thresholdsList = list_create();

		cJSON_ArrayForEach(dist_thresholds_local, dist_thresholds) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsNumber(dist_thresholds_local)) {
				printf(
					"ue_mobility_req_parseFromJSON() failed [dist_thresholds]");
				goto end;
			}
			localDouble = (double *) calloc(1, sizeof(double));
			if(!localDouble) {
				printf(
					"ue_mobility_req_parseFromJSON() failed [dist_thresholds]");
				goto end;
			}
			*localDouble = dist_thresholds_local->valuedouble;
			list_add(dist_thresholdsList, localDouble);
		}
	}

	ue_mobility_req_local_var = ue_mobility_req_create(
		order_criterion ? order_criterion_local_nonprim : NULL,
		order_direction ? order_direction_local_nonprim : NULL,
		ue_loc_order_ind ? true : false,
		ue_loc_order_ind ? ue_loc_order_ind->valueint : 0,
		dist_thresholds ? dist_thresholdsList : NULL
		);

	return ue_mobility_req_local_var;
end:
	if(order_criterion_local_nonprim) {
		ue_mobility_order_criterion_free(order_criterion_local_nonprim);
		order_criterion_local_nonprim = NULL;
	}
	if(order_direction_local_nonprim) {
		matching_direction_free(order_direction_local_nonprim);
		order_direction_local_nonprim = NULL;
	}
	if(dist_thresholdsList) {
		list_for_each(dist_thresholdsList, node) {
			free(node->data);
		}
		list_free(dist_thresholdsList);
		dist_thresholdsList = NULL;
	}
	return NULL;
}

ue_mobility_req_t *ue_mobility_req_copy(ue_mobility_req_t	*dst,
                                        ue_mobility_req_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_mobility_req_convertToJSON(src);
	if(!item) {
		printf("ue_mobility_req_convertToJSON() failed");
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

	ue_mobility_req_free(dst);
	dst = ue_mobility_req_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
