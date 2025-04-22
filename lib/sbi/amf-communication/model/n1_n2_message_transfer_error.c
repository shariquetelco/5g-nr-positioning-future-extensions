#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n1_n2_message_transfer_error.h"

n1_n2_message_transfer_error_t *n1_n2_message_transfer_error_create(
	problem_details_t *error, n1_n2_msg_txfr_err_detail_t *err_info) {
	n1_n2_message_transfer_error_t *n1_n2_message_transfer_error_local_var =
		malloc(sizeof(n1_n2_message_transfer_error_t));

	n1_n2_message_transfer_error_local_var->error = error;
	n1_n2_message_transfer_error_local_var->err_info = err_info;

	return n1_n2_message_transfer_error_local_var;
}

void n1_n2_message_transfer_error_free(
	n1_n2_message_transfer_error_t *n1_n2_message_transfer_error) {
	lnode_t *node = NULL;

	if(NULL == n1_n2_message_transfer_error) {
		return;
	}
	if(n1_n2_message_transfer_error->error) {
		problem_details_free(n1_n2_message_transfer_error->error);
		n1_n2_message_transfer_error->error = NULL;
	}
	if(n1_n2_message_transfer_error->err_info) {
		n1_n2_msg_txfr_err_detail_free(
			n1_n2_message_transfer_error->err_info);
		n1_n2_message_transfer_error->err_info = NULL;
	}
	free(n1_n2_message_transfer_error);
}

cJSON *n1_n2_message_transfer_error_convertToJSON(
	n1_n2_message_transfer_error_t *n1_n2_message_transfer_error) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n1_n2_message_transfer_error == NULL) {
		printf(
			"n1_n2_message_transfer_error_convertToJSON() failed [N1N2MessageTransferError]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!n1_n2_message_transfer_error->error) {
		printf(
			"n1_n2_message_transfer_error_convertToJSON() failed [error]");
		return NULL;
	}
	cJSON *error_local_JSON = problem_details_convertToJSON(
		n1_n2_message_transfer_error->error);
	if(error_local_JSON == NULL) {
		printf(
			"n1_n2_message_transfer_error_convertToJSON() failed [error]");
		goto end;
	}
	cJSON_AddItemToObject(item, "error", error_local_JSON);
	if(item->child == NULL) {
		printf(
			"n1_n2_message_transfer_error_convertToJSON() failed [error]");
		goto end;
	}

	if(n1_n2_message_transfer_error->err_info) {
		cJSON *err_info_local_JSON =
			n1_n2_msg_txfr_err_detail_convertToJSON(
				n1_n2_message_transfer_error->err_info);
		if(err_info_local_JSON == NULL) {
			printf(
				"n1_n2_message_transfer_error_convertToJSON() failed [err_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "errInfo", err_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"n1_n2_message_transfer_error_convertToJSON() failed [err_info]");
			goto end;
		}
	}

end:
	return item;
}

n1_n2_message_transfer_error_t *n1_n2_message_transfer_error_parseFromJSON(
	cJSON *n1_n2_message_transfer_errorJSON) {
	n1_n2_message_transfer_error_t *n1_n2_message_transfer_error_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *error = NULL;
	problem_details_t *error_local_nonprim = NULL;
	cJSON *err_info = NULL;
	n1_n2_msg_txfr_err_detail_t *err_info_local_nonprim = NULL;
	error = cJSON_GetObjectItemCaseSensitive(
		n1_n2_message_transfer_errorJSON, "error");
	if(!error) {
		printf(
			"n1_n2_message_transfer_error_parseFromJSON() failed [error]");
		goto end;
	}
	error_local_nonprim = problem_details_parseFromJSON(error);
	if(!error_local_nonprim) {
		printf("problem_details_parseFromJSON failed [error]");
		goto end;
	}

	err_info = cJSON_GetObjectItemCaseSensitive(
		n1_n2_message_transfer_errorJSON, "errInfo");
	if(err_info) {
		err_info_local_nonprim =
			n1_n2_msg_txfr_err_detail_parseFromJSON(err_info);
		if(!err_info_local_nonprim) {
			printf(
				"n1_n2_msg_txfr_err_detail_parseFromJSON failed [err_info]");
			goto end;
		}
	}

	n1_n2_message_transfer_error_local_var =
		n1_n2_message_transfer_error_create(
			error_local_nonprim,
			err_info ? err_info_local_nonprim : NULL
			);

	return n1_n2_message_transfer_error_local_var;
end:
	if(error_local_nonprim) {
		problem_details_free(error_local_nonprim);
		error_local_nonprim = NULL;
	}
	if(err_info_local_nonprim) {
		n1_n2_msg_txfr_err_detail_free(err_info_local_nonprim);
		err_info_local_nonprim = NULL;
	}
	return NULL;
}

n1_n2_message_transfer_error_t *n1_n2_message_transfer_error_copy(
	n1_n2_message_transfer_error_t	*dst,
	n1_n2_message_transfer_error_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = n1_n2_message_transfer_error_convertToJSON(src);
	if(!item) {
		printf("n1_n2_message_transfer_error_convertToJSON() failed");
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

	n1_n2_message_transfer_error_free(dst);
	dst = n1_n2_message_transfer_error_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
