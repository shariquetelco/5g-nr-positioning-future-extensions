#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "allowed_nssai.h"

allowed_nssai_t *allowed_nssai_create(list_t		*allowed_snssai_list,
                                      access_type_e	access_type) {
	allowed_nssai_t *allowed_nssai_local_var = malloc(
		sizeof(allowed_nssai_t));

	allowed_nssai_local_var->allowed_snssai_list = allowed_snssai_list;
	allowed_nssai_local_var->access_type = access_type;

	return allowed_nssai_local_var;
}

void allowed_nssai_free(allowed_nssai_t *allowed_nssai) {
	lnode_t *node = NULL;

	if(NULL == allowed_nssai) {
		return;
	}
	if(allowed_nssai->allowed_snssai_list) {
		list_for_each(allowed_nssai->allowed_snssai_list, node) {
			allowed_snssai_free(node->data);
		}
		list_free(allowed_nssai->allowed_snssai_list);
		allowed_nssai->allowed_snssai_list = NULL;
	}
	free(allowed_nssai);
}

cJSON *allowed_nssai_convertToJSON(allowed_nssai_t *allowed_nssai) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(allowed_nssai == NULL) {
		printf("allowed_nssai_convertToJSON() failed [AllowedNssai]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!allowed_nssai->allowed_snssai_list) {
		printf(
			"allowed_nssai_convertToJSON() failed [allowed_snssai_list]");
		return NULL;
	}
	cJSON *allowed_snssai_listList = cJSON_AddArrayToObject(item,
	                                                        "allowedSnssaiList");
	if(allowed_snssai_listList == NULL) {
		printf(
			"allowed_nssai_convertToJSON() failed [allowed_snssai_list]");
		goto end;
	}
	list_for_each(allowed_nssai->allowed_snssai_list, node) {
		cJSON *itemLocal = allowed_snssai_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"allowed_nssai_convertToJSON() failed [allowed_snssai_list]");
			goto end;
		}
		cJSON_AddItemToArray(allowed_snssai_listList, itemLocal);
	}

	if(allowed_nssai->access_type == access_type_NULL) {
		printf("allowed_nssai_convertToJSON() failed [access_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "accessType",
	                           access_type_ToString(allowed_nssai->
	                                                access_type)) == NULL)
	{
		printf("allowed_nssai_convertToJSON() failed [access_type]");
		goto end;
	}

end:
	return item;
}

allowed_nssai_t *allowed_nssai_parseFromJSON(cJSON *allowed_nssaiJSON) {
	allowed_nssai_t *allowed_nssai_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *allowed_snssai_list = NULL;
	list_t *allowed_snssai_listList = NULL;
	cJSON *access_type = NULL;
	access_type_e access_typeVariable = 0;
	allowed_snssai_list = cJSON_GetObjectItemCaseSensitive(
		allowed_nssaiJSON, "allowedSnssaiList");
	if(!allowed_snssai_list) {
		printf(
			"allowed_nssai_parseFromJSON() failed [allowed_snssai_list]");
		goto end;
	}
	cJSON *allowed_snssai_list_local = NULL;
	if(!cJSON_IsArray(allowed_snssai_list)) {
		printf(
			"allowed_nssai_parseFromJSON() failed [allowed_snssai_list]");
		goto end;
	}

	allowed_snssai_listList = list_create();

	cJSON_ArrayForEach(allowed_snssai_list_local, allowed_snssai_list) {
		if(!cJSON_IsObject(allowed_snssai_list_local)) {
			printf(
				"allowed_nssai_parseFromJSON() failed [allowed_snssai_list]");
			goto end;
		}
		allowed_snssai_t *allowed_snssai_listItem =
			allowed_snssai_parseFromJSON(allowed_snssai_list_local);
		if(!allowed_snssai_listItem) {
			printf("No allowed_snssai_listItem");
			goto end;
		}
		list_add(allowed_snssai_listList, allowed_snssai_listItem);
	}

	access_type = cJSON_GetObjectItemCaseSensitive(allowed_nssaiJSON,
	                                               "accessType");
	if(!access_type) {
		printf("allowed_nssai_parseFromJSON() failed [access_type]");
		goto end;
	}
	if(!cJSON_IsString(access_type)) {
		printf("allowed_nssai_parseFromJSON() failed [access_type]");
		goto end;
	}
	access_typeVariable = access_type_FromString(access_type->valuestring);

	allowed_nssai_local_var = allowed_nssai_create(
		allowed_snssai_listList,
		access_typeVariable
		);

	return allowed_nssai_local_var;
end:
	if(allowed_snssai_listList) {
		list_for_each(allowed_snssai_listList, node) {
			allowed_snssai_free(node->data);
		}
		list_free(allowed_snssai_listList);
		allowed_snssai_listList = NULL;
	}
	return NULL;
}

allowed_nssai_t *allowed_nssai_copy(allowed_nssai_t	*dst,
                                    allowed_nssai_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = allowed_nssai_convertToJSON(src);
	if(!item) {
		printf("allowed_nssai_convertToJSON() failed");
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

	allowed_nssai_free(dst);
	dst = allowed_nssai_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
