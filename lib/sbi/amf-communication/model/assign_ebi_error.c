#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assign_ebi_error.h"

assign_ebi_error_t *assign_ebi_error_create(problem_details_t	*error,
                                            assign_ebi_failed_t *failure_details)
{
	assign_ebi_error_t *assign_ebi_error_local_var =
		malloc(sizeof(assign_ebi_error_t));

	assign_ebi_error_local_var->error = error;
	assign_ebi_error_local_var->failure_details = failure_details;

	return assign_ebi_error_local_var;
}

void assign_ebi_error_free(assign_ebi_error_t *assign_ebi_error) {
	lnode_t *node = NULL;

	if(NULL == assign_ebi_error) {
		return;
	}
	if(assign_ebi_error->error) {
		problem_details_free(assign_ebi_error->error);
		assign_ebi_error->error = NULL;
	}
	if(assign_ebi_error->failure_details) {
		assign_ebi_failed_free(assign_ebi_error->failure_details);
		assign_ebi_error->failure_details = NULL;
	}
	free(assign_ebi_error);
}

cJSON *assign_ebi_error_convertToJSON(assign_ebi_error_t *assign_ebi_error) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(assign_ebi_error == NULL) {
		printf(
			"assign_ebi_error_convertToJSON() failed [AssignEbiError]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!assign_ebi_error->error) {
		printf("assign_ebi_error_convertToJSON() failed [error]");
		return NULL;
	}
	cJSON *error_local_JSON = problem_details_convertToJSON(
		assign_ebi_error->error);
	if(error_local_JSON == NULL) {
		printf("assign_ebi_error_convertToJSON() failed [error]");
		goto end;
	}
	cJSON_AddItemToObject(item, "error", error_local_JSON);
	if(item->child == NULL) {
		printf("assign_ebi_error_convertToJSON() failed [error]");
		goto end;
	}

	if(!assign_ebi_error->failure_details) {
		printf(
			"assign_ebi_error_convertToJSON() failed [failure_details]");
		return NULL;
	}
	cJSON *failure_details_local_JSON = assign_ebi_failed_convertToJSON(
		assign_ebi_error->failure_details);
	if(failure_details_local_JSON == NULL) {
		printf(
			"assign_ebi_error_convertToJSON() failed [failure_details]");
		goto end;
	}
	cJSON_AddItemToObject(item, "failureDetails",
	                      failure_details_local_JSON);
	if(item->child == NULL) {
		printf(
			"assign_ebi_error_convertToJSON() failed [failure_details]");
		goto end;
	}

end:
	return item;
}

assign_ebi_error_t *assign_ebi_error_parseFromJSON(cJSON *assign_ebi_errorJSON)
{
	assign_ebi_error_t *assign_ebi_error_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *error = NULL;
	problem_details_t *error_local_nonprim = NULL;
	cJSON *failure_details = NULL;
	assign_ebi_failed_t *failure_details_local_nonprim = NULL;
	error = cJSON_GetObjectItemCaseSensitive(assign_ebi_errorJSON, "error");
	if(!error) {
		printf("assign_ebi_error_parseFromJSON() failed [error]");
		goto end;
	}
	error_local_nonprim = problem_details_parseFromJSON(error);
	if(!error_local_nonprim) {
		printf("problem_details_parseFromJSON failed [error]");
		goto end;
	}

	failure_details = cJSON_GetObjectItemCaseSensitive(assign_ebi_errorJSON,
	                                                   "failureDetails");
	if(!failure_details) {
		printf(
			"assign_ebi_error_parseFromJSON() failed [failure_details]");
		goto end;
	}
	failure_details_local_nonprim = assign_ebi_failed_parseFromJSON(
		failure_details);
	if(!failure_details_local_nonprim) {
		printf(
			"assign_ebi_failed_parseFromJSON failed [failure_details]");
		goto end;
	}

	assign_ebi_error_local_var = assign_ebi_error_create(
		error_local_nonprim,
		failure_details_local_nonprim
		);

	return assign_ebi_error_local_var;
end:
	if(error_local_nonprim) {
		problem_details_free(error_local_nonprim);
		error_local_nonprim = NULL;
	}
	if(failure_details_local_nonprim) {
		assign_ebi_failed_free(failure_details_local_nonprim);
		failure_details_local_nonprim = NULL;
	}
	return NULL;
}

assign_ebi_error_t *assign_ebi_error_copy(assign_ebi_error_t	*dst,
                                          assign_ebi_error_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = assign_ebi_error_convertToJSON(src);
	if(!item) {
		printf("assign_ebi_error_convertToJSON() failed");
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

	assign_ebi_error_free(dst);
	dst = assign_ebi_error_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
