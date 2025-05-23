#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "query_parameter.h"

query_parameter_t *query_parameter_create(char *name, char *value) {
	query_parameter_t *query_parameter_local_var =
		malloc(sizeof(query_parameter_t));

	query_parameter_local_var->name = name;
	query_parameter_local_var->value = value;

	return query_parameter_local_var;
}

void query_parameter_free(query_parameter_t *query_parameter) {
	lnode_t *node = NULL;

	if(NULL == query_parameter) {
		return;
	}
	if(query_parameter->name) {
		free(query_parameter->name);
		query_parameter->name = NULL;
	}
	if(query_parameter->value) {
		free(query_parameter->value);
		query_parameter->value = NULL;
	}
	free(query_parameter);
}

cJSON *query_parameter_convertToJSON(query_parameter_t *query_parameter) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(query_parameter == NULL) {
		printf("query_parameter_convertToJSON() failed [QueryParameter]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!query_parameter->name) {
		printf("query_parameter_convertToJSON() failed [name]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "name",
	                           query_parameter->name) == NULL)
	{
		printf("query_parameter_convertToJSON() failed [name]");
		goto end;
	}

	if(!query_parameter->value) {
		printf("query_parameter_convertToJSON() failed [value]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "value",
	                           query_parameter->value) == NULL)
	{
		printf("query_parameter_convertToJSON() failed [value]");
		goto end;
	}

end:
	return item;
}

query_parameter_t *query_parameter_parseFromJSON(cJSON *query_parameterJSON) {
	query_parameter_t *query_parameter_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *name = NULL;
	cJSON *value = NULL;
	name = cJSON_GetObjectItemCaseSensitive(query_parameterJSON, "name");
	if(!name) {
		printf("query_parameter_parseFromJSON() failed [name]");
		goto end;
	}
	if(!cJSON_IsString(name)) {
		printf("query_parameter_parseFromJSON() failed [name]");
		goto end;
	}

	value = cJSON_GetObjectItemCaseSensitive(query_parameterJSON, "value");
	if(!value) {
		printf("query_parameter_parseFromJSON() failed [value]");
		goto end;
	}
	if(!cJSON_IsString(value)) {
		printf("query_parameter_parseFromJSON() failed [value]");
		goto end;
	}

	query_parameter_local_var = query_parameter_create(
		strdup(name->valuestring),
		strdup(value->valuestring)
		);

	return query_parameter_local_var;
end:
	return NULL;
}

query_parameter_t *query_parameter_copy(query_parameter_t	*dst,
                                        query_parameter_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = query_parameter_convertToJSON(src);
	if(!item) {
		printf("query_parameter_convertToJSON() failed");
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

	query_parameter_free(dst);
	dst = query_parameter_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
