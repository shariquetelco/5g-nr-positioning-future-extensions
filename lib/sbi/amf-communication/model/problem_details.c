#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "problem_details.h"

problem_details_t *problem_details_create(char *type, char *title,
                                          bool is_status, int status,
                                          char *detail, char *instance,
                                          char *cause, list_t *invalid_params,
                                          char *supported_features,
                                          access_token_err_t *access_token_error, access_token_req_t *access_token_request, char *nrf_id, list_t *supported_api_versions,
                                          no_profile_match_info_t *no_profile_match_info)
{
	problem_details_t *problem_details_local_var =
		malloc(sizeof(problem_details_t));

	problem_details_local_var->type = type;
	problem_details_local_var->title = title;
	problem_details_local_var->is_status = is_status;
	problem_details_local_var->status = status;
	problem_details_local_var->detail = detail;
	problem_details_local_var->instance = instance;
	problem_details_local_var->cause = cause;
	problem_details_local_var->invalid_params = invalid_params;
	problem_details_local_var->supported_features = supported_features;
	problem_details_local_var->access_token_error = access_token_error;
	problem_details_local_var->access_token_request = access_token_request;
	problem_details_local_var->nrf_id = nrf_id;
	problem_details_local_var->supported_api_versions =
		supported_api_versions;
	problem_details_local_var->no_profile_match_info =
		no_profile_match_info;

	return problem_details_local_var;
}

void problem_details_free(problem_details_t *problem_details) {
	lnode_t *node = NULL;

	if(NULL == problem_details) {
		return;
	}
	if(problem_details->type) {
		free(problem_details->type);
		problem_details->type = NULL;
	}
	if(problem_details->title) {
		free(problem_details->title);
		problem_details->title = NULL;
	}
	if(problem_details->detail) {
		free(problem_details->detail);
		problem_details->detail = NULL;
	}
	if(problem_details->instance) {
		free(problem_details->instance);
		problem_details->instance = NULL;
	}
	if(problem_details->cause) {
		free(problem_details->cause);
		problem_details->cause = NULL;
	}
	if(problem_details->invalid_params) {
		list_for_each(problem_details->invalid_params, node) {
			invalid_param_free(node->data);
		}
		list_free(problem_details->invalid_params);
		problem_details->invalid_params = NULL;
	}
	if(problem_details->supported_features) {
		free(problem_details->supported_features);
		problem_details->supported_features = NULL;
	}
	if(problem_details->access_token_error) {
		access_token_err_free(problem_details->access_token_error);
		problem_details->access_token_error = NULL;
	}
	if(problem_details->access_token_request) {
		access_token_req_free(problem_details->access_token_request);
		problem_details->access_token_request = NULL;
	}
	if(problem_details->nrf_id) {
		free(problem_details->nrf_id);
		problem_details->nrf_id = NULL;
	}
	if(problem_details->supported_api_versions) {
		list_for_each(problem_details->supported_api_versions, node) {
			free(node->data);
		}
		list_free(problem_details->supported_api_versions);
		problem_details->supported_api_versions = NULL;
	}
	if(problem_details->no_profile_match_info) {
		no_profile_match_info_free(
			problem_details->no_profile_match_info);
		problem_details->no_profile_match_info = NULL;
	}
	free(problem_details);
}

cJSON *problem_details_convertToJSON(problem_details_t *problem_details) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(problem_details == NULL) {
		printf("problem_details_convertToJSON() failed [ProblemDetails]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(problem_details->type) {
		if(cJSON_AddStringToObject(item, "type",
		                           problem_details->type) == NULL)
		{
			printf("problem_details_convertToJSON() failed [type]");
			goto end;
		}
	}

	if(problem_details->title) {
		if(cJSON_AddStringToObject(item, "title",
		                           problem_details->title) == NULL)
		{
			printf("problem_details_convertToJSON() failed [title]");
			goto end;
		}
	}

	if(problem_details->is_status) {
		if(cJSON_AddNumberToObject(item, "status",
		                           problem_details->status) == NULL)
		{
			printf("problem_details_convertToJSON() failed [status]");
			goto end;
		}
	}

	if(problem_details->detail) {
		if(cJSON_AddStringToObject(item, "detail",
		                           problem_details->detail) == NULL)
		{
			printf("problem_details_convertToJSON() failed [detail]");
			goto end;
		}
	}

	if(problem_details->instance) {
		if(cJSON_AddStringToObject(item, "instance",
		                           problem_details->instance) == NULL)
		{
			printf(
				"problem_details_convertToJSON() failed [instance]");
			goto end;
		}
	}

	if(problem_details->cause) {
		if(cJSON_AddStringToObject(item, "cause",
		                           problem_details->cause) == NULL)
		{
			printf("problem_details_convertToJSON() failed [cause]");
			goto end;
		}
	}

	if(problem_details->invalid_params) {
		cJSON *invalid_paramsList = cJSON_AddArrayToObject(item,
		                                                   "invalidParams");
		if(invalid_paramsList == NULL) {
			printf(
				"problem_details_convertToJSON() failed [invalid_params]");
			goto end;
		}
		list_for_each(problem_details->invalid_params, node) {
			cJSON *itemLocal = invalid_param_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"problem_details_convertToJSON() failed [invalid_params]");
				goto end;
			}
			cJSON_AddItemToArray(invalid_paramsList, itemLocal);
		}
	}

	if(problem_details->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           problem_details->supported_features)
		   == NULL)
		{
			printf(
				"problem_details_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

	if(problem_details->access_token_error) {
		cJSON *access_token_error_local_JSON =
			access_token_err_convertToJSON(
				problem_details->access_token_error);
		if(access_token_error_local_JSON == NULL) {
			printf(
				"problem_details_convertToJSON() failed [access_token_error]");
			goto end;
		}
		cJSON_AddItemToObject(item, "accessTokenError",
		                      access_token_error_local_JSON);
		if(item->child == NULL) {
			printf(
				"problem_details_convertToJSON() failed [access_token_error]");
			goto end;
		}
	}

	if(problem_details->access_token_request) {
		cJSON *access_token_request_local_JSON =
			access_token_req_convertToJSON(
				problem_details->access_token_request);
		if(access_token_request_local_JSON == NULL) {
			printf(
				"problem_details_convertToJSON() failed [access_token_request]");
			goto end;
		}
		cJSON_AddItemToObject(item, "accessTokenRequest",
		                      access_token_request_local_JSON);
		if(item->child == NULL) {
			printf(
				"problem_details_convertToJSON() failed [access_token_request]");
			goto end;
		}
	}

	if(problem_details->nrf_id) {
		if(cJSON_AddStringToObject(item, "nrfId",
		                           problem_details->nrf_id) == NULL)
		{
			printf("problem_details_convertToJSON() failed [nrf_id]");
			goto end;
		}
	}

	if(problem_details->supported_api_versions) {
		cJSON *supported_api_versionsList = cJSON_AddArrayToObject(item,
		                                                           "supportedApiVersions");
		if(supported_api_versionsList == NULL) {
			printf(
				"problem_details_convertToJSON() failed [supported_api_versions]");
			goto end;
		}
		list_for_each(problem_details->supported_api_versions, node) {
			if(cJSON_AddStringToObject(supported_api_versionsList,
			                           "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"problem_details_convertToJSON() failed [supported_api_versions]");
				goto end;
			}
		}
	}

	if(problem_details->no_profile_match_info) {
		cJSON *no_profile_match_info_local_JSON =
			no_profile_match_info_convertToJSON(
				problem_details->no_profile_match_info);
		if(no_profile_match_info_local_JSON == NULL) {
			printf(
				"problem_details_convertToJSON() failed [no_profile_match_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "noProfileMatchInfo",
		                      no_profile_match_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"problem_details_convertToJSON() failed [no_profile_match_info]");
			goto end;
		}
	}

end:
	return item;
}

problem_details_t *problem_details_parseFromJSON(cJSON *problem_detailsJSON) {
	problem_details_t *problem_details_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *type = NULL;
	cJSON *title = NULL;
	cJSON *status = NULL;
	cJSON *detail = NULL;
	cJSON *instance = NULL;
	cJSON *cause = NULL;
	cJSON *invalid_params = NULL;
	list_t *invalid_paramsList = NULL;
	cJSON *supported_features = NULL;
	cJSON *access_token_error = NULL;
	access_token_err_t *access_token_error_local_nonprim = NULL;
	cJSON *access_token_request = NULL;
	access_token_req_t *access_token_request_local_nonprim = NULL;
	cJSON *nrf_id = NULL;
	cJSON *supported_api_versions = NULL;
	list_t *supported_api_versionsList = NULL;
	cJSON *no_profile_match_info = NULL;
	no_profile_match_info_t *no_profile_match_info_local_nonprim = NULL;
	type = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "type");
	if(type) {
		if(!cJSON_IsString(type) &&
		   !cJSON_IsNull(type))
		{
			printf("problem_details_parseFromJSON() failed [type]");
			goto end;
		}
	}

	title = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "title");
	if(title) {
		if(!cJSON_IsString(title) &&
		   !cJSON_IsNull(title))
		{
			printf("problem_details_parseFromJSON() failed [title]");
			goto end;
		}
	}

	status =
		cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "status");
	if(status) {
		if(!cJSON_IsNumber(status)) {
			printf("problem_details_parseFromJSON() failed [status]");
			goto end;
		}
	}

	detail =
		cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "detail");
	if(detail) {
		if(!cJSON_IsString(detail) &&
		   !cJSON_IsNull(detail))
		{
			printf("problem_details_parseFromJSON() failed [detail]");
			goto end;
		}
	}

	instance = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON,
	                                            "instance");
	if(instance) {
		if(!cJSON_IsString(instance) &&
		   !cJSON_IsNull(instance))
		{
			printf(
				"problem_details_parseFromJSON() failed [instance]");
			goto end;
		}
	}

	cause = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "cause");
	if(cause) {
		if(!cJSON_IsString(cause) &&
		   !cJSON_IsNull(cause))
		{
			printf("problem_details_parseFromJSON() failed [cause]");
			goto end;
		}
	}

	invalid_params = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON,
	                                                  "invalidParams");
	if(invalid_params) {
		cJSON *invalid_params_local = NULL;
		if(!cJSON_IsArray(invalid_params)) {
			printf(
				"problem_details_parseFromJSON() failed [invalid_params]");
			goto end;
		}

		invalid_paramsList = list_create();

		cJSON_ArrayForEach(invalid_params_local, invalid_params) {
			if(!cJSON_IsObject(invalid_params_local)) {
				printf(
					"problem_details_parseFromJSON() failed [invalid_params]");
				goto end;
			}
			invalid_param_t *invalid_paramsItem =
				invalid_param_parseFromJSON(invalid_params_local);
			if(!invalid_paramsItem) {
				printf("No invalid_paramsItem");
				goto end;
			}
			list_add(invalid_paramsList, invalid_paramsItem);
		}
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		problem_detailsJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"problem_details_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	access_token_error = cJSON_GetObjectItemCaseSensitive(
		problem_detailsJSON, "accessTokenError");
	if(access_token_error) {
		access_token_error_local_nonprim =
			access_token_err_parseFromJSON(access_token_error);
		if(!access_token_error_local_nonprim) {
			printf(
				"access_token_err_parseFromJSON failed [access_token_error]");
			goto end;
		}
	}

	access_token_request = cJSON_GetObjectItemCaseSensitive(
		problem_detailsJSON, "accessTokenRequest");
	if(access_token_request) {
		access_token_request_local_nonprim =
			access_token_req_parseFromJSON(access_token_request);
		if(!access_token_request_local_nonprim) {
			printf(
				"access_token_req_parseFromJSON failed [access_token_request]");
			goto end;
		}
	}

	nrf_id = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "nrfId");
	if(nrf_id) {
		if(!cJSON_IsString(nrf_id) &&
		   !cJSON_IsNull(nrf_id))
		{
			printf("problem_details_parseFromJSON() failed [nrf_id]");
			goto end;
		}
	}

	supported_api_versions = cJSON_GetObjectItemCaseSensitive(
		problem_detailsJSON, "supportedApiVersions");
	if(supported_api_versions) {
		cJSON *supported_api_versions_local = NULL;
		if(!cJSON_IsArray(supported_api_versions)) {
			printf(
				"problem_details_parseFromJSON() failed [supported_api_versions]");
			goto end;
		}

		supported_api_versionsList = list_create();

		cJSON_ArrayForEach(supported_api_versions_local,
		                   supported_api_versions) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(supported_api_versions_local)) {
				printf(
					"problem_details_parseFromJSON() failed [supported_api_versions]");
				goto end;
			}
			list_add(supported_api_versionsList,
			         strdup(supported_api_versions_local->
			                valuestring));
		}
	}

	no_profile_match_info = cJSON_GetObjectItemCaseSensitive(
		problem_detailsJSON, "noProfileMatchInfo");
	if(no_profile_match_info) {
		no_profile_match_info_local_nonprim =
			no_profile_match_info_parseFromJSON(
				no_profile_match_info);
		if(!no_profile_match_info_local_nonprim) {
			printf(
				"no_profile_match_info_parseFromJSON failed [no_profile_match_info]");
			goto end;
		}
	}

	problem_details_local_var = problem_details_create(
		type &&
		!cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
		title &&
		!cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
		status ? true : false,
		status ? status->valuedouble : 0,
		detail &&
		!cJSON_IsNull(detail) ? strdup(detail->valuestring) : NULL,
		instance &&
		!cJSON_IsNull(instance) ? strdup(instance->valuestring) : NULL,
		cause &&
		!cJSON_IsNull(cause) ? strdup(cause->valuestring) : NULL,
		invalid_params ? invalid_paramsList : NULL,
		supported_features &&
		!cJSON_IsNull(supported_features) ? strdup(supported_features->
		                                           valuestring) : NULL,
		access_token_error ? access_token_error_local_nonprim : NULL,
		access_token_request ? access_token_request_local_nonprim : NULL,
		nrf_id &&
		!cJSON_IsNull(nrf_id) ? strdup(
			nrf_id->valuestring) : NULL,
		supported_api_versions ? supported_api_versionsList : NULL,
		no_profile_match_info ? no_profile_match_info_local_nonprim : NULL
		);

	return problem_details_local_var;
end:
	if(invalid_paramsList) {
		list_for_each(invalid_paramsList, node) {
			invalid_param_free(node->data);
		}
		list_free(invalid_paramsList);
		invalid_paramsList = NULL;
	}
	if(access_token_error_local_nonprim) {
		access_token_err_free(access_token_error_local_nonprim);
		access_token_error_local_nonprim = NULL;
	}
	if(access_token_request_local_nonprim) {
		access_token_req_free(access_token_request_local_nonprim);
		access_token_request_local_nonprim = NULL;
	}
	if(supported_api_versionsList) {
		list_for_each(supported_api_versionsList, node) {
			free(node->data);
		}
		list_free(supported_api_versionsList);
		supported_api_versionsList = NULL;
	}
	if(no_profile_match_info_local_nonprim) {
		no_profile_match_info_free(no_profile_match_info_local_nonprim);
		no_profile_match_info_local_nonprim = NULL;
	}
	return NULL;
}

problem_details_t *problem_details_copy(problem_details_t	*dst,
                                        problem_details_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = problem_details_convertToJSON(src);
	if(!item) {
		printf("problem_details_convertToJSON() failed");
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

	problem_details_free(dst);
	dst = problem_details_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
