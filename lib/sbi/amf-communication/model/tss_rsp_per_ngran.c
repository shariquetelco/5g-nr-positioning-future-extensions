#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tss_rsp_per_ngran.h"

tss_rsp_per_ngran_t *tss_rsp_per_ngran_create(
	global_ran_node_id_t	*ngran_id,
	ngran_failure_info_e	ngran_failure_info,
	n2_info_content_t	*tss_container)
{
	tss_rsp_per_ngran_t *tss_rsp_per_ngran_local_var =
		malloc(sizeof(tss_rsp_per_ngran_t));

	tss_rsp_per_ngran_local_var->ngran_id = ngran_id;
	tss_rsp_per_ngran_local_var->ngran_failure_info = ngran_failure_info;
	tss_rsp_per_ngran_local_var->tss_container = tss_container;

	return tss_rsp_per_ngran_local_var;
}

void tss_rsp_per_ngran_free(tss_rsp_per_ngran_t *tss_rsp_per_ngran) {
	lnode_t *node = NULL;

	if(NULL == tss_rsp_per_ngran) {
		return;
	}
	if(tss_rsp_per_ngran->ngran_id) {
		global_ran_node_id_free(tss_rsp_per_ngran->ngran_id);
		tss_rsp_per_ngran->ngran_id = NULL;
	}
	if(tss_rsp_per_ngran->tss_container) {
		n2_info_content_free(tss_rsp_per_ngran->tss_container);
		tss_rsp_per_ngran->tss_container = NULL;
	}
	free(tss_rsp_per_ngran);
}

cJSON *tss_rsp_per_ngran_convertToJSON(tss_rsp_per_ngran_t *tss_rsp_per_ngran) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(tss_rsp_per_ngran == NULL) {
		printf(
			"tss_rsp_per_ngran_convertToJSON() failed [TssRspPerNgran]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!tss_rsp_per_ngran->ngran_id) {
		printf("tss_rsp_per_ngran_convertToJSON() failed [ngran_id]");
		return NULL;
	}
	cJSON *ngran_id_local_JSON = global_ran_node_id_convertToJSON(
		tss_rsp_per_ngran->ngran_id);
	if(ngran_id_local_JSON == NULL) {
		printf("tss_rsp_per_ngran_convertToJSON() failed [ngran_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "ngranId", ngran_id_local_JSON);
	if(item->child == NULL) {
		printf("tss_rsp_per_ngran_convertToJSON() failed [ngran_id]");
		goto end;
	}

	if(tss_rsp_per_ngran->ngran_failure_info != ngran_failure_info_NULL) {
		if(cJSON_AddStringToObject(item, "ngranFailureInfo",
		                           ngran_failure_info_ToString(
						   tss_rsp_per_ngran->
						   ngran_failure_info))
		   == NULL)
		{
			printf(
				"tss_rsp_per_ngran_convertToJSON() failed [ngran_failure_info]");
			goto end;
		}
	}

	if(tss_rsp_per_ngran->tss_container) {
		cJSON *tss_container_local_JSON = n2_info_content_convertToJSON(
			tss_rsp_per_ngran->tss_container);
		if(tss_container_local_JSON == NULL) {
			printf(
				"tss_rsp_per_ngran_convertToJSON() failed [tss_container]");
			goto end;
		}
		cJSON_AddItemToObject(item, "tssContainer",
		                      tss_container_local_JSON);
		if(item->child == NULL) {
			printf(
				"tss_rsp_per_ngran_convertToJSON() failed [tss_container]");
			goto end;
		}
	}

end:
	return item;
}

tss_rsp_per_ngran_t *tss_rsp_per_ngran_parseFromJSON(
	cJSON *tss_rsp_per_ngranJSON) {
	tss_rsp_per_ngran_t *tss_rsp_per_ngran_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ngran_id = NULL;
	global_ran_node_id_t *ngran_id_local_nonprim = NULL;
	cJSON *ngran_failure_info = NULL;
	ngran_failure_info_e ngran_failure_infoVariable = 0;
	cJSON *tss_container = NULL;
	n2_info_content_t *tss_container_local_nonprim = NULL;
	ngran_id = cJSON_GetObjectItemCaseSensitive(tss_rsp_per_ngranJSON,
	                                            "ngranId");
	if(!ngran_id) {
		printf("tss_rsp_per_ngran_parseFromJSON() failed [ngran_id]");
		goto end;
	}
	ngran_id_local_nonprim = global_ran_node_id_parseFromJSON(ngran_id);
	if(!ngran_id_local_nonprim) {
		printf("global_ran_node_id_parseFromJSON failed [ngran_id]");
		goto end;
	}

	ngran_failure_info = cJSON_GetObjectItemCaseSensitive(
		tss_rsp_per_ngranJSON, "ngranFailureInfo");
	if(ngran_failure_info) {
		if(!cJSON_IsString(ngran_failure_info)) {
			printf(
				"tss_rsp_per_ngran_parseFromJSON() failed [ngran_failure_info]");
			goto end;
		}
		ngran_failure_infoVariable = ngran_failure_info_FromString(
			ngran_failure_info->valuestring);
	}

	tss_container = cJSON_GetObjectItemCaseSensitive(tss_rsp_per_ngranJSON,
	                                                 "tssContainer");
	if(tss_container) {
		tss_container_local_nonprim = n2_info_content_parseFromJSON(
			tss_container);
		if(!tss_container_local_nonprim) {
			printf(
				"n2_info_content_parseFromJSON failed [tss_container]");
			goto end;
		}
	}

	tss_rsp_per_ngran_local_var = tss_rsp_per_ngran_create(
		ngran_id_local_nonprim,
		ngran_failure_info ? ngran_failure_infoVariable : 0,
		tss_container ? tss_container_local_nonprim : NULL
		);

	return tss_rsp_per_ngran_local_var;
end:
	if(ngran_id_local_nonprim) {
		global_ran_node_id_free(ngran_id_local_nonprim);
		ngran_id_local_nonprim = NULL;
	}
	if(tss_container_local_nonprim) {
		n2_info_content_free(tss_container_local_nonprim);
		tss_container_local_nonprim = NULL;
	}
	return NULL;
}

tss_rsp_per_ngran_t *tss_rsp_per_ngran_copy(tss_rsp_per_ngran_t *dst,
                                            tss_rsp_per_ngran_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = tss_rsp_per_ngran_convertToJSON(src);
	if(!item) {
		printf("tss_rsp_per_ngran_convertToJSON() failed");
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

	tss_rsp_per_ngran_free(dst);
	dst = tss_rsp_per_ngran_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
