#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "e2e_data_vol_trans_time_req.h"

e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req_create(
	e2e_data_vol_trans_time_criterion_t *criterion,
	matching_direction_t *order, bool is_high_trans_tm_thr,
	int high_trans_tm_thr, bool is_low_trans_tm_thr, int low_trans_tm_thr,
	bool is_repeat_data_trans, int repeat_data_trans,
	char *ts_interval_data_trans, data_volume_t *data_volume,
	bool is_max_number_ues, int max_number_ues) {
	e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req_local_var =
		malloc(sizeof(e2e_data_vol_trans_time_req_t));

	e2e_data_vol_trans_time_req_local_var->criterion = criterion;
	e2e_data_vol_trans_time_req_local_var->order = order;
	e2e_data_vol_trans_time_req_local_var->is_high_trans_tm_thr =
		is_high_trans_tm_thr;
	e2e_data_vol_trans_time_req_local_var->high_trans_tm_thr =
		high_trans_tm_thr;
	e2e_data_vol_trans_time_req_local_var->is_low_trans_tm_thr =
		is_low_trans_tm_thr;
	e2e_data_vol_trans_time_req_local_var->low_trans_tm_thr =
		low_trans_tm_thr;
	e2e_data_vol_trans_time_req_local_var->is_repeat_data_trans =
		is_repeat_data_trans;
	e2e_data_vol_trans_time_req_local_var->repeat_data_trans =
		repeat_data_trans;
	e2e_data_vol_trans_time_req_local_var->ts_interval_data_trans =
		ts_interval_data_trans;
	e2e_data_vol_trans_time_req_local_var->data_volume = data_volume;
	e2e_data_vol_trans_time_req_local_var->is_max_number_ues =
		is_max_number_ues;
	e2e_data_vol_trans_time_req_local_var->max_number_ues = max_number_ues;

	return e2e_data_vol_trans_time_req_local_var;
}

void e2e_data_vol_trans_time_req_free(
	e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req) {
	lnode_t *node = NULL;

	if(NULL == e2e_data_vol_trans_time_req) {
		return;
	}
	if(e2e_data_vol_trans_time_req->criterion) {
		e2e_data_vol_trans_time_criterion_free(
			e2e_data_vol_trans_time_req->criterion);
		e2e_data_vol_trans_time_req->criterion = NULL;
	}
	if(e2e_data_vol_trans_time_req->order) {
		matching_direction_free(e2e_data_vol_trans_time_req->order);
		e2e_data_vol_trans_time_req->order = NULL;
	}
	if(e2e_data_vol_trans_time_req->ts_interval_data_trans) {
		free(e2e_data_vol_trans_time_req->ts_interval_data_trans);
		e2e_data_vol_trans_time_req->ts_interval_data_trans = NULL;
	}
	if(e2e_data_vol_trans_time_req->data_volume) {
		data_volume_free(e2e_data_vol_trans_time_req->data_volume);
		e2e_data_vol_trans_time_req->data_volume = NULL;
	}
	free(e2e_data_vol_trans_time_req);
}

cJSON *e2e_data_vol_trans_time_req_convertToJSON(
	e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(e2e_data_vol_trans_time_req == NULL) {
		printf(
			"e2e_data_vol_trans_time_req_convertToJSON() failed [E2eDataVolTransTimeReq]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(e2e_data_vol_trans_time_req->criterion) {
		cJSON *criterion_local_JSON =
			e2e_data_vol_trans_time_criterion_convertToJSON(
				e2e_data_vol_trans_time_req->criterion);
		if(criterion_local_JSON == NULL) {
			printf(
				"e2e_data_vol_trans_time_req_convertToJSON() failed [criterion]");
			goto end;
		}
		cJSON_AddItemToObject(item, "criterion", criterion_local_JSON);
		if(item->child == NULL) {
			printf(
				"e2e_data_vol_trans_time_req_convertToJSON() failed [criterion]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_req->order) {
		cJSON *order_local_JSON = matching_direction_convertToJSON(
			e2e_data_vol_trans_time_req->order);
		if(order_local_JSON == NULL) {
			printf(
				"e2e_data_vol_trans_time_req_convertToJSON() failed [order]");
			goto end;
		}
		cJSON_AddItemToObject(item, "order", order_local_JSON);
		if(item->child == NULL) {
			printf(
				"e2e_data_vol_trans_time_req_convertToJSON() failed [order]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_req->is_high_trans_tm_thr) {
		if(cJSON_AddNumberToObject(item, "highTransTmThr",
		                           e2e_data_vol_trans_time_req->
		                           high_trans_tm_thr) == NULL)
		{
			printf(
				"e2e_data_vol_trans_time_req_convertToJSON() failed [high_trans_tm_thr]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_req->is_low_trans_tm_thr) {
		if(cJSON_AddNumberToObject(item, "lowTransTmThr",
		                           e2e_data_vol_trans_time_req->
		                           low_trans_tm_thr) == NULL)
		{
			printf(
				"e2e_data_vol_trans_time_req_convertToJSON() failed [low_trans_tm_thr]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_req->is_repeat_data_trans) {
		if(cJSON_AddNumberToObject(item, "repeatDataTrans",
		                           e2e_data_vol_trans_time_req->
		                           repeat_data_trans) == NULL)
		{
			printf(
				"e2e_data_vol_trans_time_req_convertToJSON() failed [repeat_data_trans]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_req->ts_interval_data_trans) {
		if(cJSON_AddStringToObject(item, "tsIntervalDataTrans",
		                           e2e_data_vol_trans_time_req->
		                           ts_interval_data_trans) == NULL)
		{
			printf(
				"e2e_data_vol_trans_time_req_convertToJSON() failed [ts_interval_data_trans]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_req->data_volume) {
		cJSON *data_volume_local_JSON = data_volume_convertToJSON(
			e2e_data_vol_trans_time_req->data_volume);
		if(data_volume_local_JSON == NULL) {
			printf(
				"e2e_data_vol_trans_time_req_convertToJSON() failed [data_volume]");
			goto end;
		}
		cJSON_AddItemToObject(item, "dataVolume",
		                      data_volume_local_JSON);
		if(item->child == NULL) {
			printf(
				"e2e_data_vol_trans_time_req_convertToJSON() failed [data_volume]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_req->is_max_number_ues) {
		if(cJSON_AddNumberToObject(item, "maxNumberUes",
		                           e2e_data_vol_trans_time_req->
		                           max_number_ues) == NULL)
		{
			printf(
				"e2e_data_vol_trans_time_req_convertToJSON() failed [max_number_ues]");
			goto end;
		}
	}

end:
	return item;
}

e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req_parseFromJSON(
	cJSON *e2e_data_vol_trans_time_reqJSON) {
	e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *criterion = NULL;
	e2e_data_vol_trans_time_criterion_t *criterion_local_nonprim = NULL;
	cJSON *order = NULL;
	matching_direction_t *order_local_nonprim = NULL;
	cJSON *high_trans_tm_thr = NULL;
	cJSON *low_trans_tm_thr = NULL;
	cJSON *repeat_data_trans = NULL;
	cJSON *ts_interval_data_trans = NULL;
	cJSON *data_volume = NULL;
	data_volume_t *data_volume_local_nonprim = NULL;
	cJSON *max_number_ues = NULL;
	criterion = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_reqJSON, "criterion");
	if(criterion) {
		criterion_local_nonprim =
			e2e_data_vol_trans_time_criterion_parseFromJSON(
				criterion);
		if(!criterion_local_nonprim) {
			printf(
				"e2e_data_vol_trans_time_criterion_parseFromJSON failed [criterion]");
			goto end;
		}
	}

	order = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_reqJSON, "order");
	if(order) {
		order_local_nonprim = matching_direction_parseFromJSON(order);
		if(!order_local_nonprim) {
			printf("matching_direction_parseFromJSON failed [order]");
			goto end;
		}
	}

	high_trans_tm_thr = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_reqJSON, "highTransTmThr");
	if(high_trans_tm_thr) {
		if(!cJSON_IsNumber(high_trans_tm_thr)) {
			printf(
				"e2e_data_vol_trans_time_req_parseFromJSON() failed [high_trans_tm_thr]");
			goto end;
		}
	}

	low_trans_tm_thr = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_reqJSON, "lowTransTmThr");
	if(low_trans_tm_thr) {
		if(!cJSON_IsNumber(low_trans_tm_thr)) {
			printf(
				"e2e_data_vol_trans_time_req_parseFromJSON() failed [low_trans_tm_thr]");
			goto end;
		}
	}

	repeat_data_trans = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_reqJSON, "repeatDataTrans");
	if(repeat_data_trans) {
		if(!cJSON_IsNumber(repeat_data_trans)) {
			printf(
				"e2e_data_vol_trans_time_req_parseFromJSON() failed [repeat_data_trans]");
			goto end;
		}
	}

	ts_interval_data_trans = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_reqJSON, "tsIntervalDataTrans");
	if(ts_interval_data_trans) {
		if(!cJSON_IsString(ts_interval_data_trans) &&
		   !cJSON_IsNull(ts_interval_data_trans))
		{
			printf(
				"e2e_data_vol_trans_time_req_parseFromJSON() failed [ts_interval_data_trans]");
			goto end;
		}
	}

	data_volume = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_reqJSON, "dataVolume");
	if(data_volume) {
		data_volume_local_nonprim = data_volume_parseFromJSON(
			data_volume);
		if(!data_volume_local_nonprim) {
			printf("data_volume_parseFromJSON failed [data_volume]");
			goto end;
		}
	}

	max_number_ues = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_reqJSON, "maxNumberUes");
	if(max_number_ues) {
		if(!cJSON_IsNumber(max_number_ues)) {
			printf(
				"e2e_data_vol_trans_time_req_parseFromJSON() failed [max_number_ues]");
			goto end;
		}
	}

	e2e_data_vol_trans_time_req_local_var =
		e2e_data_vol_trans_time_req_create(
			criterion ? criterion_local_nonprim : NULL,
			order ? order_local_nonprim : NULL,
			high_trans_tm_thr ? true : false,
			high_trans_tm_thr ? high_trans_tm_thr->valuedouble : 0,
			low_trans_tm_thr ? true : false,
			low_trans_tm_thr ? low_trans_tm_thr->valuedouble : 0,
			repeat_data_trans ? true : false,
			repeat_data_trans ? repeat_data_trans->valuedouble : 0,
			ts_interval_data_trans &&
			!cJSON_IsNull(ts_interval_data_trans) ? strdup(
				ts_interval_data_trans->valuestring) : NULL,
			data_volume ? data_volume_local_nonprim : NULL,
			max_number_ues ? true : false,
			max_number_ues ? max_number_ues->valuedouble : 0
			);

	return e2e_data_vol_trans_time_req_local_var;
end:
	if(criterion_local_nonprim) {
		e2e_data_vol_trans_time_criterion_free(criterion_local_nonprim);
		criterion_local_nonprim = NULL;
	}
	if(order_local_nonprim) {
		matching_direction_free(order_local_nonprim);
		order_local_nonprim = NULL;
	}
	if(data_volume_local_nonprim) {
		data_volume_free(data_volume_local_nonprim);
		data_volume_local_nonprim = NULL;
	}
	return NULL;
}

e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req_copy(
	e2e_data_vol_trans_time_req_t	*dst,
	e2e_data_vol_trans_time_req_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = e2e_data_vol_trans_time_req_convertToJSON(src);
	if(!item) {
		printf("e2e_data_vol_trans_time_req_convertToJSON() failed");
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

	e2e_data_vol_trans_time_req_free(dst);
	dst = e2e_data_vol_trans_time_req_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
