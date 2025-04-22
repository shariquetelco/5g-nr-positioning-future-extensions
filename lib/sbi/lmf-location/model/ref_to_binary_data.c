#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ref_to_binary_data.h"

ref_to_binary_data_t *ref_to_binary_data_create(char *content_id) {
	ref_to_binary_data_t *ref_to_binary_data_local_var =
		malloc(sizeof(ref_to_binary_data_t));

	ref_to_binary_data_local_var->content_id = content_id;

	return ref_to_binary_data_local_var;
}

void ref_to_binary_data_free(ref_to_binary_data_t *ref_to_binary_data) {
	lnode_t *node = NULL;

	if(NULL == ref_to_binary_data) {
		return;
	}
	if(ref_to_binary_data->content_id) {
		free(ref_to_binary_data->content_id);
		ref_to_binary_data->content_id = NULL;
	}
	free(ref_to_binary_data);
}

cJSON *ref_to_binary_data_convertToJSON(
	ref_to_binary_data_t *ref_to_binary_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ref_to_binary_data == NULL) {
		printf(
			"ref_to_binary_data_convertToJSON() failed [RefToBinaryData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ref_to_binary_data->content_id) {
		printf("ref_to_binary_data_convertToJSON() failed [content_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "contentId",
	                           ref_to_binary_data->content_id) == NULL)
	{
		printf("ref_to_binary_data_convertToJSON() failed [content_id]");
		goto end;
	}

end:
	return item;
}

ref_to_binary_data_t *ref_to_binary_data_parseFromJSON(
	cJSON *ref_to_binary_dataJSON) {
	ref_to_binary_data_t *ref_to_binary_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *content_id = NULL;
	content_id = cJSON_GetObjectItemCaseSensitive(ref_to_binary_dataJSON,
	                                              "contentId");
	if(!content_id) {
		printf("ref_to_binary_data_parseFromJSON() failed [content_id]");
		goto end;
	}
	if(!cJSON_IsString(content_id)) {
		printf("ref_to_binary_data_parseFromJSON() failed [content_id]");
		goto end;
	}

	ref_to_binary_data_local_var = ref_to_binary_data_create(
		strdup(content_id->valuestring)
		);

	return ref_to_binary_data_local_var;
end:
	return NULL;
}

ref_to_binary_data_t *ref_to_binary_data_copy(ref_to_binary_data_t	*dst,
                                              ref_to_binary_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ref_to_binary_data_convertToJSON(src);
	if(!item) {
		printf("ref_to_binary_data_convertToJSON() failed");
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

	ref_to_binary_data_free(dst);
	dst = ref_to_binary_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
