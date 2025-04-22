#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_context_create_error.h"

ue_context_create_error_t *ue_context_create_error_create(
	problem_details_t *error, ng_ap_cause_t *ngap_cause,
	n2_info_content_t *target_to_source_failure_data) {
	ue_context_create_error_t *ue_context_create_error_local_var = malloc(
		sizeof(ue_context_create_error_t));

	ue_context_create_error_local_var->error = error;
	ue_context_create_error_local_var->ngap_cause = ngap_cause;
	ue_context_create_error_local_var->target_to_source_failure_data =
		target_to_source_failure_data;

	return ue_context_create_error_local_var;
}

void ue_context_create_error_free(
	ue_context_create_error_t *ue_context_create_error) {
	lnode_t *node = NULL;

	if(NULL == ue_context_create_error) {
		return;
	}
	if(ue_context_create_error->error) {
		problem_details_free(ue_context_create_error->error);
		ue_context_create_error->error = NULL;
	}
	if(ue_context_create_error->ngap_cause) {
		ng_ap_cause_free(ue_context_create_error->ngap_cause);
		ue_context_create_error->ngap_cause = NULL;
	}
	if(ue_context_create_error->target_to_source_failure_data) {
		n2_info_content_free(
			ue_context_create_error->target_to_source_failure_data);
		ue_context_create_error->target_to_source_failure_data = NULL;
	}
	free(ue_context_create_error);
}

cJSON *ue_context_create_error_convertToJSON(
	ue_context_create_error_t *ue_context_create_error) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_context_create_error == NULL) {
		printf(
			"ue_context_create_error_convertToJSON() failed [UeContextCreateError]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ue_context_create_error->error) {
		printf("ue_context_create_error_convertToJSON() failed [error]");
		return NULL;
	}
	cJSON *error_local_JSON = problem_details_convertToJSON(
		ue_context_create_error->error);
	if(error_local_JSON == NULL) {
		printf("ue_context_create_error_convertToJSON() failed [error]");
		goto end;
	}
	cJSON_AddItemToObject(item, "error", error_local_JSON);
	if(item->child == NULL) {
		printf("ue_context_create_error_convertToJSON() failed [error]");
		goto end;
	}

	if(ue_context_create_error->ngap_cause) {
		cJSON *ngap_cause_local_JSON = ng_ap_cause_convertToJSON(
			ue_context_create_error->ngap_cause);
		if(ngap_cause_local_JSON == NULL) {
			printf(
				"ue_context_create_error_convertToJSON() failed [ngap_cause]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ngapCause", ngap_cause_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_context_create_error_convertToJSON() failed [ngap_cause]");
			goto end;
		}
	}

	if(ue_context_create_error->target_to_source_failure_data) {
		cJSON *target_to_source_failure_data_local_JSON =
			n2_info_content_convertToJSON(
				ue_context_create_error->target_to_source_failure_data);
		if(target_to_source_failure_data_local_JSON == NULL) {
			printf(
				"ue_context_create_error_convertToJSON() failed [target_to_source_failure_data]");
			goto end;
		}
		cJSON_AddItemToObject(item, "targetToSourceFailureData",
		                      target_to_source_failure_data_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_context_create_error_convertToJSON() failed [target_to_source_failure_data]");
			goto end;
		}
	}

end:
	return item;
}

ue_context_create_error_t *ue_context_create_error_parseFromJSON(
	cJSON *ue_context_create_errorJSON) {
	ue_context_create_error_t *ue_context_create_error_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *error = NULL;
	problem_details_t *error_local_nonprim = NULL;
	cJSON *ngap_cause = NULL;
	ng_ap_cause_t *ngap_cause_local_nonprim = NULL;
	cJSON *target_to_source_failure_data = NULL;
	n2_info_content_t *target_to_source_failure_data_local_nonprim = NULL;
	error = cJSON_GetObjectItemCaseSensitive(ue_context_create_errorJSON,
	                                         "error");
	if(!error) {
		printf("ue_context_create_error_parseFromJSON() failed [error]");
		goto end;
	}
	error_local_nonprim = problem_details_parseFromJSON(error);
	if(!error_local_nonprim) {
		printf("problem_details_parseFromJSON failed [error]");
		goto end;
	}

	ngap_cause = cJSON_GetObjectItemCaseSensitive(
		ue_context_create_errorJSON, "ngapCause");
	if(ngap_cause) {
		ngap_cause_local_nonprim =
			ng_ap_cause_parseFromJSON(ngap_cause);
		if(!ngap_cause_local_nonprim) {
			printf("ng_ap_cause_parseFromJSON failed [ngap_cause]");
			goto end;
		}
	}

	target_to_source_failure_data = cJSON_GetObjectItemCaseSensitive(
		ue_context_create_errorJSON, "targetToSourceFailureData");
	if(target_to_source_failure_data) {
		target_to_source_failure_data_local_nonprim =
			n2_info_content_parseFromJSON(
				target_to_source_failure_data);
		if(!target_to_source_failure_data_local_nonprim) {
			printf(
				"n2_info_content_parseFromJSON failed [target_to_source_failure_data]");
			goto end;
		}
	}

	ue_context_create_error_local_var = ue_context_create_error_create(
		error_local_nonprim,
		ngap_cause ? ngap_cause_local_nonprim : NULL,
		target_to_source_failure_data ? target_to_source_failure_data_local_nonprim : NULL
		);

	return ue_context_create_error_local_var;
end:
	if(error_local_nonprim) {
		problem_details_free(error_local_nonprim);
		error_local_nonprim = NULL;
	}
	if(ngap_cause_local_nonprim) {
		ng_ap_cause_free(ngap_cause_local_nonprim);
		ngap_cause_local_nonprim = NULL;
	}
	if(target_to_source_failure_data_local_nonprim) {
		n2_info_content_free(target_to_source_failure_data_local_nonprim);
		target_to_source_failure_data_local_nonprim = NULL;
	}
	return NULL;
}

ue_context_create_error_t *ue_context_create_error_copy(
	ue_context_create_error_t *dst, ue_context_create_error_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_context_create_error_convertToJSON(src);
	if(!item) {
		printf("ue_context_create_error_convertToJSON() failed");
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

	ue_context_create_error_free(dst);
	dst = ue_context_create_error_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
