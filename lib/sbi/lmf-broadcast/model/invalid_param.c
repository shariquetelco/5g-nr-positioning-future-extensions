#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invalid_param.h"

invalid_param_t *invalid_param_create(char *param, char *reason) {
	invalid_param_t *invalid_param_local_var = malloc(
		sizeof(invalid_param_t));

	invalid_param_local_var->param = param;
	invalid_param_local_var->reason = reason;

	return invalid_param_local_var;
}

void invalid_param_free(invalid_param_t *invalid_param) {
	lnode_t *node = NULL;

	if(NULL == invalid_param) {
		return;
	}
	if(invalid_param->param) {
		free(invalid_param->param);
		invalid_param->param = NULL;
	}
	if(invalid_param->reason) {
		free(invalid_param->reason);
		invalid_param->reason = NULL;
	}
	free(invalid_param);
}

cJSON *invalid_param_convertToJSON(invalid_param_t *invalid_param) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(invalid_param == NULL) {
		printf("invalid_param_convertToJSON() failed [InvalidParam]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!invalid_param->param) {
		printf("invalid_param_convertToJSON() failed [param]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "param",
	                           invalid_param->param) == NULL)
	{
		printf("invalid_param_convertToJSON() failed [param]");
		goto end;
	}

	if(invalid_param->reason) {
		if(cJSON_AddStringToObject(item, "reason",
		                           invalid_param->reason) == NULL)
		{
			printf("invalid_param_convertToJSON() failed [reason]");
			goto end;
		}
	}

end:
	return item;
}

invalid_param_t *invalid_param_parseFromJSON(cJSON *invalid_paramJSON) {
	invalid_param_t *invalid_param_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *param = NULL;
	cJSON *reason = NULL;
	param = cJSON_GetObjectItemCaseSensitive(invalid_paramJSON, "param");
	if(!param) {
		printf("invalid_param_parseFromJSON() failed [param]");
		goto end;
	}
	if(!cJSON_IsString(param)) {
		printf("invalid_param_parseFromJSON() failed [param]");
		goto end;
	}

	reason = cJSON_GetObjectItemCaseSensitive(invalid_paramJSON, "reason");
	if(reason) {
		if(!cJSON_IsString(reason) &&
		   !cJSON_IsNull(reason))
		{
			printf("invalid_param_parseFromJSON() failed [reason]");
			goto end;
		}
	}

	invalid_param_local_var = invalid_param_create(
		strdup(param->valuestring),
		reason &&
		!cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL
		);

	return invalid_param_local_var;
end:
	return NULL;
}

invalid_param_t *invalid_param_copy(invalid_param_t	*dst,
                                    invalid_param_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = invalid_param_convertToJSON(src);
	if(!item) {
		printf("invalid_param_convertToJSON() failed");
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

	invalid_param_free(dst);
	dst = invalid_param_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
