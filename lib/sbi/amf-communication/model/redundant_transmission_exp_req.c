#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "redundant_transmission_exp_req.h"

redundant_transmission_exp_req_t *redundant_transmission_exp_req_create(
	red_trans_exp_ordering_criterion_t	*red_t_order_criter,
	matching_direction_t			*order) {
	redundant_transmission_exp_req_t *
	        redundant_transmission_exp_req_local_var =
		malloc(sizeof(redundant_transmission_exp_req_t));

	redundant_transmission_exp_req_local_var->red_t_order_criter =
		red_t_order_criter;
	redundant_transmission_exp_req_local_var->order = order;

	return redundant_transmission_exp_req_local_var;
}

void redundant_transmission_exp_req_free(
	redundant_transmission_exp_req_t *redundant_transmission_exp_req) {
	lnode_t *node = NULL;

	if(NULL == redundant_transmission_exp_req) {
		return;
	}
	if(redundant_transmission_exp_req->red_t_order_criter) {
		red_trans_exp_ordering_criterion_free(
			redundant_transmission_exp_req->red_t_order_criter);
		redundant_transmission_exp_req->red_t_order_criter = NULL;
	}
	if(redundant_transmission_exp_req->order) {
		matching_direction_free(redundant_transmission_exp_req->order);
		redundant_transmission_exp_req->order = NULL;
	}
	free(redundant_transmission_exp_req);
}

cJSON *redundant_transmission_exp_req_convertToJSON(
	redundant_transmission_exp_req_t *redundant_transmission_exp_req) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(redundant_transmission_exp_req == NULL) {
		printf(
			"redundant_transmission_exp_req_convertToJSON() failed [RedundantTransmissionExpReq]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(redundant_transmission_exp_req->red_t_order_criter) {
		cJSON *red_t_order_criter_local_JSON =
			red_trans_exp_ordering_criterion_convertToJSON(
				redundant_transmission_exp_req->red_t_order_criter);
		if(red_t_order_criter_local_JSON == NULL) {
			printf(
				"redundant_transmission_exp_req_convertToJSON() failed [red_t_order_criter]");
			goto end;
		}
		cJSON_AddItemToObject(item, "redTOrderCriter",
		                      red_t_order_criter_local_JSON);
		if(item->child == NULL) {
			printf(
				"redundant_transmission_exp_req_convertToJSON() failed [red_t_order_criter]");
			goto end;
		}
	}

	if(redundant_transmission_exp_req->order) {
		cJSON *order_local_JSON = matching_direction_convertToJSON(
			redundant_transmission_exp_req->order);
		if(order_local_JSON == NULL) {
			printf(
				"redundant_transmission_exp_req_convertToJSON() failed [order]");
			goto end;
		}
		cJSON_AddItemToObject(item, "order", order_local_JSON);
		if(item->child == NULL) {
			printf(
				"redundant_transmission_exp_req_convertToJSON() failed [order]");
			goto end;
		}
	}

end:
	return item;
}

redundant_transmission_exp_req_t *redundant_transmission_exp_req_parseFromJSON(
	cJSON *redundant_transmission_exp_reqJSON) {
	redundant_transmission_exp_req_t *
	        redundant_transmission_exp_req_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *red_t_order_criter = NULL;
	red_trans_exp_ordering_criterion_t *red_t_order_criter_local_nonprim =
		NULL;
	cJSON *order = NULL;
	matching_direction_t *order_local_nonprim = NULL;
	red_t_order_criter = cJSON_GetObjectItemCaseSensitive(
		redundant_transmission_exp_reqJSON, "redTOrderCriter");
	if(red_t_order_criter) {
		red_t_order_criter_local_nonprim =
			red_trans_exp_ordering_criterion_parseFromJSON(
				red_t_order_criter);
		if(!red_t_order_criter_local_nonprim) {
			printf(
				"red_trans_exp_ordering_criterion_parseFromJSON failed [red_t_order_criter]");
			goto end;
		}
	}

	order = cJSON_GetObjectItemCaseSensitive(
		redundant_transmission_exp_reqJSON, "order");
	if(order) {
		order_local_nonprim = matching_direction_parseFromJSON(order);
		if(!order_local_nonprim) {
			printf("matching_direction_parseFromJSON failed [order]");
			goto end;
		}
	}

	redundant_transmission_exp_req_local_var =
		redundant_transmission_exp_req_create(
			red_t_order_criter ? red_t_order_criter_local_nonprim : NULL,
			order ? order_local_nonprim : NULL
			);

	return redundant_transmission_exp_req_local_var;
end:
	if(red_t_order_criter_local_nonprim) {
		red_trans_exp_ordering_criterion_free(
			red_t_order_criter_local_nonprim);
		red_t_order_criter_local_nonprim = NULL;
	}
	if(order_local_nonprim) {
		matching_direction_free(order_local_nonprim);
		order_local_nonprim = NULL;
	}
	return NULL;
}

redundant_transmission_exp_req_t *redundant_transmission_exp_req_copy(
	redundant_transmission_exp_req_t	*dst,
	redundant_transmission_exp_req_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = redundant_transmission_exp_req_convertToJSON(src);
	if(!item) {
		printf("redundant_transmission_exp_req_convertToJSON() failed");
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

	redundant_transmission_exp_req_free(dst);
	dst = redundant_transmission_exp_req_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
