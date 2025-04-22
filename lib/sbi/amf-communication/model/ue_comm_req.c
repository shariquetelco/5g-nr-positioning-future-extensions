#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_comm_req.h"

ue_comm_req_t *ue_comm_req_create(
	ue_comm_order_criterion_t	*order_criterion,
	matching_direction_t		*order_direction)
{
	ue_comm_req_t *ue_comm_req_local_var = malloc(sizeof(ue_comm_req_t));

	ue_comm_req_local_var->order_criterion = order_criterion;
	ue_comm_req_local_var->order_direction = order_direction;

	return ue_comm_req_local_var;
}

void ue_comm_req_free(ue_comm_req_t *ue_comm_req) {
	lnode_t *node = NULL;

	if(NULL == ue_comm_req) {
		return;
	}
	if(ue_comm_req->order_criterion) {
		ue_comm_order_criterion_free(ue_comm_req->order_criterion);
		ue_comm_req->order_criterion = NULL;
	}
	if(ue_comm_req->order_direction) {
		matching_direction_free(ue_comm_req->order_direction);
		ue_comm_req->order_direction = NULL;
	}
	free(ue_comm_req);
}

cJSON *ue_comm_req_convertToJSON(ue_comm_req_t *ue_comm_req) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_comm_req == NULL) {
		printf("ue_comm_req_convertToJSON() failed [UeCommReq]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_comm_req->order_criterion) {
		cJSON *order_criterion_local_JSON =
			ue_comm_order_criterion_convertToJSON(
				ue_comm_req->order_criterion);
		if(order_criterion_local_JSON == NULL) {
			printf(
				"ue_comm_req_convertToJSON() failed [order_criterion]");
			goto end;
		}
		cJSON_AddItemToObject(item, "orderCriterion",
		                      order_criterion_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_comm_req_convertToJSON() failed [order_criterion]");
			goto end;
		}
	}

	if(ue_comm_req->order_direction) {
		cJSON *order_direction_local_JSON =
			matching_direction_convertToJSON(
				ue_comm_req->order_direction);
		if(order_direction_local_JSON == NULL) {
			printf(
				"ue_comm_req_convertToJSON() failed [order_direction]");
			goto end;
		}
		cJSON_AddItemToObject(item, "orderDirection",
		                      order_direction_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_comm_req_convertToJSON() failed [order_direction]");
			goto end;
		}
	}

end:
	return item;
}

ue_comm_req_t *ue_comm_req_parseFromJSON(cJSON *ue_comm_reqJSON) {
	ue_comm_req_t *ue_comm_req_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *order_criterion = NULL;
	ue_comm_order_criterion_t *order_criterion_local_nonprim = NULL;
	cJSON *order_direction = NULL;
	matching_direction_t *order_direction_local_nonprim = NULL;
	order_criterion = cJSON_GetObjectItemCaseSensitive(ue_comm_reqJSON,
	                                                   "orderCriterion");
	if(order_criterion) {
		order_criterion_local_nonprim =
			ue_comm_order_criterion_parseFromJSON(order_criterion);
		if(!order_criterion_local_nonprim) {
			printf(
				"ue_comm_order_criterion_parseFromJSON failed [order_criterion]");
			goto end;
		}
	}

	order_direction = cJSON_GetObjectItemCaseSensitive(ue_comm_reqJSON,
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

	ue_comm_req_local_var = ue_comm_req_create(
		order_criterion ? order_criterion_local_nonprim : NULL,
		order_direction ? order_direction_local_nonprim : NULL
		);

	return ue_comm_req_local_var;
end:
	if(order_criterion_local_nonprim) {
		ue_comm_order_criterion_free(order_criterion_local_nonprim);
		order_criterion_local_nonprim = NULL;
	}
	if(order_direction_local_nonprim) {
		matching_direction_free(order_direction_local_nonprim);
		order_direction_local_nonprim = NULL;
	}
	return NULL;
}

ue_comm_req_t *ue_comm_req_copy(ue_comm_req_t *dst, ue_comm_req_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_comm_req_convertToJSON(src);
	if(!item) {
		printf("ue_comm_req_convertToJSON() failed");
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

	ue_comm_req_free(dst);
	dst = ue_comm_req_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
