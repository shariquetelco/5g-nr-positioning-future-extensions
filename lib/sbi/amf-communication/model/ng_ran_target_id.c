#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ng_ran_target_id.h"

ng_ran_target_id_t *ng_ran_target_id_create(
	global_ran_node_id_t	*ran_node_id,
	tai_t			*tai) {
	ng_ran_target_id_t *ng_ran_target_id_local_var =
		malloc(sizeof(ng_ran_target_id_t));

	ng_ran_target_id_local_var->ran_node_id = ran_node_id;
	ng_ran_target_id_local_var->tai = tai;

	return ng_ran_target_id_local_var;
}

void ng_ran_target_id_free(ng_ran_target_id_t *ng_ran_target_id) {
	lnode_t *node = NULL;

	if(NULL == ng_ran_target_id) {
		return;
	}
	if(ng_ran_target_id->ran_node_id) {
		global_ran_node_id_free(ng_ran_target_id->ran_node_id);
		ng_ran_target_id->ran_node_id = NULL;
	}
	if(ng_ran_target_id->tai) {
		tai_free(ng_ran_target_id->tai);
		ng_ran_target_id->tai = NULL;
	}
	free(ng_ran_target_id);
}

cJSON *ng_ran_target_id_convertToJSON(ng_ran_target_id_t *ng_ran_target_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ng_ran_target_id == NULL) {
		printf("ng_ran_target_id_convertToJSON() failed [NgRanTargetId]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ng_ran_target_id->ran_node_id) {
		printf("ng_ran_target_id_convertToJSON() failed [ran_node_id]");
		return NULL;
	}
	cJSON *ran_node_id_local_JSON = global_ran_node_id_convertToJSON(
		ng_ran_target_id->ran_node_id);
	if(ran_node_id_local_JSON == NULL) {
		printf("ng_ran_target_id_convertToJSON() failed [ran_node_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "ranNodeId", ran_node_id_local_JSON);
	if(item->child == NULL) {
		printf("ng_ran_target_id_convertToJSON() failed [ran_node_id]");
		goto end;
	}

	if(!ng_ran_target_id->tai) {
		printf("ng_ran_target_id_convertToJSON() failed [tai]");
		return NULL;
	}
	cJSON *tai_local_JSON = tai_convertToJSON(ng_ran_target_id->tai);
	if(tai_local_JSON == NULL) {
		printf("ng_ran_target_id_convertToJSON() failed [tai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "tai", tai_local_JSON);
	if(item->child == NULL) {
		printf("ng_ran_target_id_convertToJSON() failed [tai]");
		goto end;
	}

end:
	return item;
}

ng_ran_target_id_t *ng_ran_target_id_parseFromJSON(cJSON *ng_ran_target_idJSON)
{
	ng_ran_target_id_t *ng_ran_target_id_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ran_node_id = NULL;
	global_ran_node_id_t *ran_node_id_local_nonprim = NULL;
	cJSON *tai = NULL;
	tai_t *tai_local_nonprim = NULL;
	ran_node_id = cJSON_GetObjectItemCaseSensitive(ng_ran_target_idJSON,
	                                               "ranNodeId");
	if(!ran_node_id) {
		printf("ng_ran_target_id_parseFromJSON() failed [ran_node_id]");
		goto end;
	}
	ran_node_id_local_nonprim =
		global_ran_node_id_parseFromJSON(ran_node_id);
	if(!ran_node_id_local_nonprim) {
		printf("global_ran_node_id_parseFromJSON failed [ran_node_id]");
		goto end;
	}

	tai = cJSON_GetObjectItemCaseSensitive(ng_ran_target_idJSON, "tai");
	if(!tai) {
		printf("ng_ran_target_id_parseFromJSON() failed [tai]");
		goto end;
	}
	tai_local_nonprim = tai_parseFromJSON(tai);
	if(!tai_local_nonprim) {
		printf("tai_parseFromJSON failed [tai]");
		goto end;
	}

	ng_ran_target_id_local_var = ng_ran_target_id_create(
		ran_node_id_local_nonprim,
		tai_local_nonprim
		);

	return ng_ran_target_id_local_var;
end:
	if(ran_node_id_local_nonprim) {
		global_ran_node_id_free(ran_node_id_local_nonprim);
		ran_node_id_local_nonprim = NULL;
	}
	if(tai_local_nonprim) {
		tai_free(tai_local_nonprim);
		tai_local_nonprim = NULL;
	}
	return NULL;
}

ng_ran_target_id_t *ng_ran_target_id_copy(ng_ran_target_id_t	*dst,
                                          ng_ran_target_id_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ng_ran_target_id_convertToJSON(src);
	if(!item) {
		printf("ng_ran_target_id_convertToJSON() failed");
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

	ng_ran_target_id_free(dst);
	dst = ng_ran_target_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
