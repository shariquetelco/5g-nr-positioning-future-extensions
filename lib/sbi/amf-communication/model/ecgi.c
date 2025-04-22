#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ecgi.h"

ecgi_t *ecgi_create(plmn_id_t *plmn_id, char *eutra_cell_id, char *nid) {
	ecgi_t *ecgi_local_var = malloc(sizeof(ecgi_t));

	ecgi_local_var->plmn_id = plmn_id;
	ecgi_local_var->eutra_cell_id = eutra_cell_id;
	ecgi_local_var->nid = nid;

	return ecgi_local_var;
}

void ecgi_free(ecgi_t *ecgi) {
	lnode_t *node = NULL;

	if(NULL == ecgi) {
		return;
	}
	if(ecgi->plmn_id) {
		plmn_id_free(ecgi->plmn_id);
		ecgi->plmn_id = NULL;
	}
	if(ecgi->eutra_cell_id) {
		free(ecgi->eutra_cell_id);
		ecgi->eutra_cell_id = NULL;
	}
	if(ecgi->nid) {
		free(ecgi->nid);
		ecgi->nid = NULL;
	}
	free(ecgi);
}

cJSON *ecgi_convertToJSON(ecgi_t *ecgi) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ecgi == NULL) {
		printf("ecgi_convertToJSON() failed [Ecgi]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ecgi->plmn_id) {
		printf("ecgi_convertToJSON() failed [plmn_id]");
		return NULL;
	}
	cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(ecgi->plmn_id);
	if(plmn_id_local_JSON == NULL) {
		printf("ecgi_convertToJSON() failed [plmn_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
	if(item->child == NULL) {
		printf("ecgi_convertToJSON() failed [plmn_id]");
		goto end;
	}

	if(!ecgi->eutra_cell_id) {
		printf("ecgi_convertToJSON() failed [eutra_cell_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "eutraCellId",
	                           ecgi->eutra_cell_id) == NULL)
	{
		printf("ecgi_convertToJSON() failed [eutra_cell_id]");
		goto end;
	}

	if(ecgi->nid) {
		if(cJSON_AddStringToObject(item, "nid", ecgi->nid) == NULL) {
			printf("ecgi_convertToJSON() failed [nid]");
			goto end;
		}
	}

end:
	return item;
}

ecgi_t *ecgi_parseFromJSON(cJSON *ecgiJSON) {
	ecgi_t *ecgi_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_t *plmn_id_local_nonprim = NULL;
	cJSON *eutra_cell_id = NULL;
	cJSON *nid = NULL;
	plmn_id = cJSON_GetObjectItemCaseSensitive(ecgiJSON, "plmnId");
	if(!plmn_id) {
		printf("ecgi_parseFromJSON() failed [plmn_id]");
		goto end;
	}
	plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id);
	if(!plmn_id_local_nonprim) {
		printf("plmn_id_parseFromJSON failed [plmn_id]");
		goto end;
	}

	eutra_cell_id =
		cJSON_GetObjectItemCaseSensitive(ecgiJSON, "eutraCellId");
	if(!eutra_cell_id) {
		printf("ecgi_parseFromJSON() failed [eutra_cell_id]");
		goto end;
	}
	if(!cJSON_IsString(eutra_cell_id)) {
		printf("ecgi_parseFromJSON() failed [eutra_cell_id]");
		goto end;
	}

	nid = cJSON_GetObjectItemCaseSensitive(ecgiJSON, "nid");
	if(nid) {
		if(!cJSON_IsString(nid) &&
		   !cJSON_IsNull(nid))
		{
			printf("ecgi_parseFromJSON() failed [nid]");
			goto end;
		}
	}

	ecgi_local_var = ecgi_create(
		plmn_id_local_nonprim,
		strdup(eutra_cell_id->valuestring),
		nid &&
		!cJSON_IsNull(nid) ? strdup(nid->valuestring) : NULL
		);

	return ecgi_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	return NULL;
}

ecgi_t *ecgi_copy(ecgi_t *dst, ecgi_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ecgi_convertToJSON(src);
	if(!item) {
		printf("ecgi_convertToJSON() failed");
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

	ecgi_free(dst);
	dst = ecgi_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
