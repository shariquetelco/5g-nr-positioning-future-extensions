#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "key_amf.h"

key_amf_t *key_amf_create(key_amf_type_e key_type, char *key_val) {
	key_amf_t *key_amf_local_var = malloc(sizeof(key_amf_t));

	key_amf_local_var->key_type = key_type;
	key_amf_local_var->key_val = key_val;

	return key_amf_local_var;
}

void key_amf_free(key_amf_t *key_amf) {
	lnode_t *node = NULL;

	if(NULL == key_amf) {
		return;
	}
	if(key_amf->key_val) {
		free(key_amf->key_val);
		key_amf->key_val = NULL;
	}
	free(key_amf);
}

cJSON *key_amf_convertToJSON(key_amf_t *key_amf) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(key_amf == NULL) {
		printf("key_amf_convertToJSON() failed [KeyAmf]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(key_amf->key_type == key_amf_type_NULL) {
		printf("key_amf_convertToJSON() failed [key_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "keyType",
	                           key_amf_type_ToString(key_amf->key_type)) ==
	   NULL)
	{
		printf("key_amf_convertToJSON() failed [key_type]");
		goto end;
	}

	if(!key_amf->key_val) {
		printf("key_amf_convertToJSON() failed [key_val]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "keyVal", key_amf->key_val) == NULL) {
		printf("key_amf_convertToJSON() failed [key_val]");
		goto end;
	}

end:
	return item;
}

key_amf_t *key_amf_parseFromJSON(cJSON *key_amfJSON) {
	key_amf_t *key_amf_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *key_type = NULL;
	key_amf_type_e key_typeVariable = 0;
	cJSON *key_val = NULL;
	key_type = cJSON_GetObjectItemCaseSensitive(key_amfJSON, "keyType");
	if(!key_type) {
		printf("key_amf_parseFromJSON() failed [key_type]");
		goto end;
	}
	if(!cJSON_IsString(key_type)) {
		printf("key_amf_parseFromJSON() failed [key_type]");
		goto end;
	}
	key_typeVariable = key_amf_type_FromString(key_type->valuestring);

	key_val = cJSON_GetObjectItemCaseSensitive(key_amfJSON, "keyVal");
	if(!key_val) {
		printf("key_amf_parseFromJSON() failed [key_val]");
		goto end;
	}
	if(!cJSON_IsString(key_val)) {
		printf("key_amf_parseFromJSON() failed [key_val]");
		goto end;
	}

	key_amf_local_var = key_amf_create(
		key_typeVariable,
		strdup(key_val->valuestring)
		);

	return key_amf_local_var;
end:
	return NULL;
}

key_amf_t *key_amf_copy(key_amf_t *dst, key_amf_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = key_amf_convertToJSON(src);
	if(!item) {
		printf("key_amf_convertToJSON() failed");
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

	key_amf_free(dst);
	dst = key_amf_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
