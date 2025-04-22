#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "routing_area_id.h"

routing_area_id_t *routing_area_id_create(plmn_id_t *plmn_id, char *lac,
                                          char *rac) {
	routing_area_id_t *routing_area_id_local_var =
		malloc(sizeof(routing_area_id_t));

	routing_area_id_local_var->plmn_id = plmn_id;
	routing_area_id_local_var->lac = lac;
	routing_area_id_local_var->rac = rac;

	return routing_area_id_local_var;
}

void routing_area_id_free(routing_area_id_t *routing_area_id) {
	lnode_t *node = NULL;

	if(NULL == routing_area_id) {
		return;
	}
	if(routing_area_id->plmn_id) {
		plmn_id_free(routing_area_id->plmn_id);
		routing_area_id->plmn_id = NULL;
	}
	if(routing_area_id->lac) {
		free(routing_area_id->lac);
		routing_area_id->lac = NULL;
	}
	if(routing_area_id->rac) {
		free(routing_area_id->rac);
		routing_area_id->rac = NULL;
	}
	free(routing_area_id);
}

cJSON *routing_area_id_convertToJSON(routing_area_id_t *routing_area_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(routing_area_id == NULL) {
		printf("routing_area_id_convertToJSON() failed [RoutingAreaId]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!routing_area_id->plmn_id) {
		printf("routing_area_id_convertToJSON() failed [plmn_id]");
		return NULL;
	}
	cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(
		routing_area_id->plmn_id);
	if(plmn_id_local_JSON == NULL) {
		printf("routing_area_id_convertToJSON() failed [plmn_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
	if(item->child == NULL) {
		printf("routing_area_id_convertToJSON() failed [plmn_id]");
		goto end;
	}

	if(!routing_area_id->lac) {
		printf("routing_area_id_convertToJSON() failed [lac]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "lac", routing_area_id->lac) == NULL) {
		printf("routing_area_id_convertToJSON() failed [lac]");
		goto end;
	}

	if(!routing_area_id->rac) {
		printf("routing_area_id_convertToJSON() failed [rac]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "rac", routing_area_id->rac) == NULL) {
		printf("routing_area_id_convertToJSON() failed [rac]");
		goto end;
	}

end:
	return item;
}

routing_area_id_t *routing_area_id_parseFromJSON(cJSON *routing_area_idJSON) {
	routing_area_id_t *routing_area_id_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_t *plmn_id_local_nonprim = NULL;
	cJSON *lac = NULL;
	cJSON *rac = NULL;
	plmn_id =
		cJSON_GetObjectItemCaseSensitive(routing_area_idJSON, "plmnId");
	if(!plmn_id) {
		printf("routing_area_id_parseFromJSON() failed [plmn_id]");
		goto end;
	}
	plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id);
	if(!plmn_id_local_nonprim) {
		printf("plmn_id_parseFromJSON failed [plmn_id]");
		goto end;
	}

	lac = cJSON_GetObjectItemCaseSensitive(routing_area_idJSON, "lac");
	if(!lac) {
		printf("routing_area_id_parseFromJSON() failed [lac]");
		goto end;
	}
	if(!cJSON_IsString(lac)) {
		printf("routing_area_id_parseFromJSON() failed [lac]");
		goto end;
	}

	rac = cJSON_GetObjectItemCaseSensitive(routing_area_idJSON, "rac");
	if(!rac) {
		printf("routing_area_id_parseFromJSON() failed [rac]");
		goto end;
	}
	if(!cJSON_IsString(rac)) {
		printf("routing_area_id_parseFromJSON() failed [rac]");
		goto end;
	}

	routing_area_id_local_var = routing_area_id_create(
		plmn_id_local_nonprim,
		strdup(lac->valuestring),
		strdup(rac->valuestring)
		);

	return routing_area_id_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	return NULL;
}

routing_area_id_t *routing_area_id_copy(routing_area_id_t	*dst,
                                        routing_area_id_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = routing_area_id_convertToJSON(src);
	if(!item) {
		printf("routing_area_id_convertToJSON() failed");
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

	routing_area_id_free(dst);
	dst = routing_area_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
