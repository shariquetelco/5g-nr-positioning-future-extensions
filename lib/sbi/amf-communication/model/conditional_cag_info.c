#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "conditional_cag_info.h"

conditional_cag_info_t *conditional_cag_info_create(
	list_t			*allowed_cag_list,
	bool			is_cag_only_indicator,
	int			cag_only_indicator,
	valid_time_period_t	*valid_time_period)
{
	conditional_cag_info_t *conditional_cag_info_local_var =
		malloc(sizeof(conditional_cag_info_t));

	conditional_cag_info_local_var->allowed_cag_list = allowed_cag_list;
	conditional_cag_info_local_var->is_cag_only_indicator =
		is_cag_only_indicator;
	conditional_cag_info_local_var->cag_only_indicator = cag_only_indicator;
	conditional_cag_info_local_var->valid_time_period = valid_time_period;

	return conditional_cag_info_local_var;
}

void conditional_cag_info_free(conditional_cag_info_t *conditional_cag_info) {
	lnode_t *node = NULL;

	if(NULL == conditional_cag_info) {
		return;
	}
	if(conditional_cag_info->allowed_cag_list) {
		list_for_each(conditional_cag_info->allowed_cag_list, node) {
			free(node->data);
		}
		list_free(conditional_cag_info->allowed_cag_list);
		conditional_cag_info->allowed_cag_list = NULL;
	}
	if(conditional_cag_info->valid_time_period) {
		valid_time_period_free(conditional_cag_info->valid_time_period);
		conditional_cag_info->valid_time_period = NULL;
	}
	free(conditional_cag_info);
}

cJSON *conditional_cag_info_convertToJSON(
	conditional_cag_info_t *conditional_cag_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(conditional_cag_info == NULL) {
		printf(
			"conditional_cag_info_convertToJSON() failed [ConditionalCagInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!conditional_cag_info->allowed_cag_list) {
		printf(
			"conditional_cag_info_convertToJSON() failed [allowed_cag_list]");
		return NULL;
	}
	cJSON *allowed_cag_listList = cJSON_AddArrayToObject(item,
	                                                     "allowedCagList");
	if(allowed_cag_listList == NULL) {
		printf(
			"conditional_cag_info_convertToJSON() failed [allowed_cag_list]");
		goto end;
	}
	list_for_each(conditional_cag_info->allowed_cag_list, node) {
		if(cJSON_AddStringToObject(allowed_cag_listList, "",
		                           (char *) node->data) == NULL)
		{
			printf(
				"conditional_cag_info_convertToJSON() failed [allowed_cag_list]");
			goto end;
		}
	}

	if(conditional_cag_info->is_cag_only_indicator) {
		if(cJSON_AddBoolToObject(item, "cagOnlyIndicator",
		                         conditional_cag_info->
		                         cag_only_indicator) == NULL)
		{
			printf(
				"conditional_cag_info_convertToJSON() failed [cag_only_indicator]");
			goto end;
		}
	}

	if(conditional_cag_info->valid_time_period) {
		cJSON *valid_time_period_local_JSON =
			valid_time_period_convertToJSON(
				conditional_cag_info->valid_time_period);
		if(valid_time_period_local_JSON == NULL) {
			printf(
				"conditional_cag_info_convertToJSON() failed [valid_time_period]");
			goto end;
		}
		cJSON_AddItemToObject(item, "validTimePeriod",
		                      valid_time_period_local_JSON);
		if(item->child == NULL) {
			printf(
				"conditional_cag_info_convertToJSON() failed [valid_time_period]");
			goto end;
		}
	}

end:
	return item;
}

conditional_cag_info_t *conditional_cag_info_parseFromJSON(
	cJSON *conditional_cag_infoJSON) {
	conditional_cag_info_t *conditional_cag_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *allowed_cag_list = NULL;
	list_t *allowed_cag_listList = NULL;
	cJSON *cag_only_indicator = NULL;
	cJSON *valid_time_period = NULL;
	valid_time_period_t *valid_time_period_local_nonprim = NULL;
	allowed_cag_list = cJSON_GetObjectItemCaseSensitive(
		conditional_cag_infoJSON, "allowedCagList");
	if(!allowed_cag_list) {
		printf(
			"conditional_cag_info_parseFromJSON() failed [allowed_cag_list]");
		goto end;
	}
	cJSON *allowed_cag_list_local = NULL;
	if(!cJSON_IsArray(allowed_cag_list)) {
		printf(
			"conditional_cag_info_parseFromJSON() failed [allowed_cag_list]");
		goto end;
	}

	allowed_cag_listList = list_create();

	cJSON_ArrayForEach(allowed_cag_list_local, allowed_cag_list) {
		double *localDouble = NULL;
		int *localInt = NULL;
		if(!cJSON_IsString(allowed_cag_list_local)) {
			printf(
				"conditional_cag_info_parseFromJSON() failed [allowed_cag_list]");
			goto end;
		}
		list_add(allowed_cag_listList,
		         strdup(allowed_cag_list_local->valuestring));
	}

	cag_only_indicator = cJSON_GetObjectItemCaseSensitive(
		conditional_cag_infoJSON, "cagOnlyIndicator");
	if(cag_only_indicator) {
		if(!cJSON_IsBool(cag_only_indicator)) {
			printf(
				"conditional_cag_info_parseFromJSON() failed [cag_only_indicator]");
			goto end;
		}
	}

	valid_time_period = cJSON_GetObjectItemCaseSensitive(
		conditional_cag_infoJSON, "validTimePeriod");
	if(valid_time_period) {
		valid_time_period_local_nonprim =
			valid_time_period_parseFromJSON(valid_time_period);
		if(!valid_time_period_local_nonprim) {
			printf(
				"valid_time_period_parseFromJSON failed [valid_time_period]");
			goto end;
		}
	}

	conditional_cag_info_local_var = conditional_cag_info_create(
		allowed_cag_listList,
		cag_only_indicator ? true : false,
		cag_only_indicator ? cag_only_indicator->valueint : 0,
		valid_time_period ? valid_time_period_local_nonprim : NULL
		);

	return conditional_cag_info_local_var;
end:
	if(allowed_cag_listList) {
		list_for_each(allowed_cag_listList, node) {
			free(node->data);
		}
		list_free(allowed_cag_listList);
		allowed_cag_listList = NULL;
	}
	if(valid_time_period_local_nonprim) {
		valid_time_period_free(valid_time_period_local_nonprim);
		valid_time_period_local_nonprim = NULL;
	}
	return NULL;
}

conditional_cag_info_t *conditional_cag_info_copy(
	conditional_cag_info_t	*dst,
	conditional_cag_info_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = conditional_cag_info_convertToJSON(src);
	if(!item) {
		printf("conditional_cag_info_convertToJSON() failed");
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

	conditional_cag_info_free(dst);
	dst = conditional_cag_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
