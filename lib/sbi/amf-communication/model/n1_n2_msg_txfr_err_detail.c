#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n1_n2_msg_txfr_err_detail.h"

n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail_create(
	bool is_retry_after, int retry_after, arp_t *highest_prio_arp,
	bool is_max_waiting_time, int max_waiting_time) {
	n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail_local_var =
		malloc(sizeof(n1_n2_msg_txfr_err_detail_t));

	n1_n2_msg_txfr_err_detail_local_var->is_retry_after = is_retry_after;
	n1_n2_msg_txfr_err_detail_local_var->retry_after = retry_after;
	n1_n2_msg_txfr_err_detail_local_var->highest_prio_arp =
		highest_prio_arp;
	n1_n2_msg_txfr_err_detail_local_var->is_max_waiting_time =
		is_max_waiting_time;
	n1_n2_msg_txfr_err_detail_local_var->max_waiting_time =
		max_waiting_time;

	return n1_n2_msg_txfr_err_detail_local_var;
}

void n1_n2_msg_txfr_err_detail_free(
	n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail) {
	lnode_t *node = NULL;

	if(NULL == n1_n2_msg_txfr_err_detail) {
		return;
	}
	if(n1_n2_msg_txfr_err_detail->highest_prio_arp) {
		arp_free(n1_n2_msg_txfr_err_detail->highest_prio_arp);
		n1_n2_msg_txfr_err_detail->highest_prio_arp = NULL;
	}
	free(n1_n2_msg_txfr_err_detail);
}

cJSON *n1_n2_msg_txfr_err_detail_convertToJSON(
	n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n1_n2_msg_txfr_err_detail == NULL) {
		printf(
			"n1_n2_msg_txfr_err_detail_convertToJSON() failed [N1N2MsgTxfrErrDetail]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(n1_n2_msg_txfr_err_detail->is_retry_after) {
		if(cJSON_AddNumberToObject(item, "retryAfter",
		                           n1_n2_msg_txfr_err_detail->
		                           retry_after) == NULL)
		{
			printf(
				"n1_n2_msg_txfr_err_detail_convertToJSON() failed [retry_after]");
			goto end;
		}
	}

	if(n1_n2_msg_txfr_err_detail->highest_prio_arp) {
		cJSON *highest_prio_arp_local_JSON = arp_convertToJSON(
			n1_n2_msg_txfr_err_detail->highest_prio_arp);
		if(highest_prio_arp_local_JSON == NULL) {
			printf(
				"n1_n2_msg_txfr_err_detail_convertToJSON() failed [highest_prio_arp]");
			goto end;
		}
		cJSON_AddItemToObject(item, "highestPrioArp",
		                      highest_prio_arp_local_JSON);
		if(item->child == NULL) {
			printf(
				"n1_n2_msg_txfr_err_detail_convertToJSON() failed [highest_prio_arp]");
			goto end;
		}
	}

	if(n1_n2_msg_txfr_err_detail->is_max_waiting_time) {
		if(cJSON_AddNumberToObject(item, "maxWaitingTime",
		                           n1_n2_msg_txfr_err_detail->
		                           max_waiting_time) == NULL)
		{
			printf(
				"n1_n2_msg_txfr_err_detail_convertToJSON() failed [max_waiting_time]");
			goto end;
		}
	}

end:
	return item;
}

n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail_parseFromJSON(
	cJSON *n1_n2_msg_txfr_err_detailJSON) {
	n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *retry_after = NULL;
	cJSON *highest_prio_arp = NULL;
	arp_t *highest_prio_arp_local_nonprim = NULL;
	cJSON *max_waiting_time = NULL;
	retry_after = cJSON_GetObjectItemCaseSensitive(
		n1_n2_msg_txfr_err_detailJSON, "retryAfter");
	if(retry_after) {
		if(!cJSON_IsNumber(retry_after)) {
			printf(
				"n1_n2_msg_txfr_err_detail_parseFromJSON() failed [retry_after]");
			goto end;
		}
	}

	highest_prio_arp = cJSON_GetObjectItemCaseSensitive(
		n1_n2_msg_txfr_err_detailJSON, "highestPrioArp");
	if(highest_prio_arp) {
		highest_prio_arp_local_nonprim = arp_parseFromJSON(
			highest_prio_arp);
		if(!highest_prio_arp_local_nonprim) {
			printf("arp_parseFromJSON failed [highest_prio_arp]");
			goto end;
		}
	}

	max_waiting_time = cJSON_GetObjectItemCaseSensitive(
		n1_n2_msg_txfr_err_detailJSON, "maxWaitingTime");
	if(max_waiting_time) {
		if(!cJSON_IsNumber(max_waiting_time)) {
			printf(
				"n1_n2_msg_txfr_err_detail_parseFromJSON() failed [max_waiting_time]");
			goto end;
		}
	}

	n1_n2_msg_txfr_err_detail_local_var = n1_n2_msg_txfr_err_detail_create(
		retry_after ? true : false,
		retry_after ? retry_after->valuedouble : 0,
		highest_prio_arp ? highest_prio_arp_local_nonprim : NULL,
		max_waiting_time ? true : false,
		max_waiting_time ? max_waiting_time->valuedouble : 0
		);

	return n1_n2_msg_txfr_err_detail_local_var;
end:
	if(highest_prio_arp_local_nonprim) {
		arp_free(highest_prio_arp_local_nonprim);
		highest_prio_arp_local_nonprim = NULL;
	}
	return NULL;
}

n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail_copy(
	n1_n2_msg_txfr_err_detail_t *dst, n1_n2_msg_txfr_err_detail_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = n1_n2_msg_txfr_err_detail_convertToJSON(src);
	if(!item) {
		printf("n1_n2_msg_txfr_err_detail_convertToJSON() failed");
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

	n1_n2_msg_txfr_err_detail_free(dst);
	dst = n1_n2_msg_txfr_err_detail_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
