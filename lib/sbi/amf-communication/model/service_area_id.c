#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_area_id.h"

service_area_id_t *service_area_id_create(plmn_id_t *plmn_id, char *lac,
                                          char *sac) {
	service_area_id_t *service_area_id_local_var =
		malloc(sizeof(service_area_id_t));

	service_area_id_local_var->plmn_id = plmn_id;
	service_area_id_local_var->lac = lac;
	service_area_id_local_var->sac = sac;

	return service_area_id_local_var;
}

void service_area_id_free(service_area_id_t *service_area_id) {
	lnode_t *node = NULL;

	if(NULL == service_area_id) {
		return;
	}
	if(service_area_id->plmn_id) {
		plmn_id_free(service_area_id->plmn_id);
		service_area_id->plmn_id = NULL;
	}
	if(service_area_id->lac) {
		free(service_area_id->lac);
		service_area_id->lac = NULL;
	}
	if(service_area_id->sac) {
		free(service_area_id->sac);
		service_area_id->sac = NULL;
	}
	free(service_area_id);
}

cJSON *service_area_id_convertToJSON(service_area_id_t *service_area_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(service_area_id == NULL) {
		printf("service_area_id_convertToJSON() failed [ServiceAreaId]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!service_area_id->plmn_id) {
		printf("service_area_id_convertToJSON() failed [plmn_id]");
		return NULL;
	}
	cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(
		service_area_id->plmn_id);
	if(plmn_id_local_JSON == NULL) {
		printf("service_area_id_convertToJSON() failed [plmn_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
	if(item->child == NULL) {
		printf("service_area_id_convertToJSON() failed [plmn_id]");
		goto end;
	}

	if(!service_area_id->lac) {
		printf("service_area_id_convertToJSON() failed [lac]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "lac", service_area_id->lac) == NULL) {
		printf("service_area_id_convertToJSON() failed [lac]");
		goto end;
	}

	if(!service_area_id->sac) {
		printf("service_area_id_convertToJSON() failed [sac]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "sac", service_area_id->sac) == NULL) {
		printf("service_area_id_convertToJSON() failed [sac]");
		goto end;
	}

end:
	return item;
}

service_area_id_t *service_area_id_parseFromJSON(cJSON *service_area_idJSON) {
	service_area_id_t *service_area_id_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_t *plmn_id_local_nonprim = NULL;
	cJSON *lac = NULL;
	cJSON *sac = NULL;
	plmn_id =
		cJSON_GetObjectItemCaseSensitive(service_area_idJSON, "plmnId");
	if(!plmn_id) {
		printf("service_area_id_parseFromJSON() failed [plmn_id]");
		goto end;
	}
	plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id);
	if(!plmn_id_local_nonprim) {
		printf("plmn_id_parseFromJSON failed [plmn_id]");
		goto end;
	}

	lac = cJSON_GetObjectItemCaseSensitive(service_area_idJSON, "lac");
	if(!lac) {
		printf("service_area_id_parseFromJSON() failed [lac]");
		goto end;
	}
	if(!cJSON_IsString(lac)) {
		printf("service_area_id_parseFromJSON() failed [lac]");
		goto end;
	}

	sac = cJSON_GetObjectItemCaseSensitive(service_area_idJSON, "sac");
	if(!sac) {
		printf("service_area_id_parseFromJSON() failed [sac]");
		goto end;
	}
	if(!cJSON_IsString(sac)) {
		printf("service_area_id_parseFromJSON() failed [sac]");
		goto end;
	}

	service_area_id_local_var = service_area_id_create(
		plmn_id_local_nonprim,
		strdup(lac->valuestring),
		strdup(sac->valuestring)
		);

	return service_area_id_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	return NULL;
}

service_area_id_t *service_area_id_copy(service_area_id_t	*dst,
                                        service_area_id_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = service_area_id_convertToJSON(src);
	if(!item) {
		printf("service_area_id_convertToJSON() failed");
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

	service_area_id_free(dst);
	dst = service_area_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
