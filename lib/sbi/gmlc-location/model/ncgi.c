#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ncgi.h"

ncgi_t *ncgi_create(plmn_id_t *plmn_id, char *nr_cell_id, char *nid) {
	ncgi_t *ncgi_local_var = malloc(sizeof(ncgi_t));

	ncgi_local_var->plmn_id = plmn_id;
	ncgi_local_var->nr_cell_id = nr_cell_id;
	ncgi_local_var->nid = nid;

	return ncgi_local_var;
}

void ncgi_free(ncgi_t *ncgi) {
	lnode_t *node = NULL;

	if(NULL == ncgi) {
		return;
	}
	if(ncgi->plmn_id) {
		plmn_id_free(ncgi->plmn_id);
		ncgi->plmn_id = NULL;
	}
	if(ncgi->nr_cell_id) {
		free(ncgi->nr_cell_id);
		ncgi->nr_cell_id = NULL;
	}
	if(ncgi->nid) {
		free(ncgi->nid);
		ncgi->nid = NULL;
	}
	free(ncgi);
}

cJSON *ncgi_convertToJSON(ncgi_t *ncgi) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ncgi == NULL) {
		printf("ncgi_convertToJSON() failed [Ncgi]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ncgi->plmn_id) {
		printf("ncgi_convertToJSON() failed [plmn_id]");
		return NULL;
	}
	cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(ncgi->plmn_id);
	if(plmn_id_local_JSON == NULL) {
		printf("ncgi_convertToJSON() failed [plmn_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
	if(item->child == NULL) {
		printf("ncgi_convertToJSON() failed [plmn_id]");
		goto end;
	}

	if(!ncgi->nr_cell_id) {
		printf("ncgi_convertToJSON() failed [nr_cell_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "nrCellId",
	                           ncgi->nr_cell_id) == NULL)
	{
		printf("ncgi_convertToJSON() failed [nr_cell_id]");
		goto end;
	}

	if(ncgi->nid) {
		if(cJSON_AddStringToObject(item, "nid", ncgi->nid) == NULL) {
			printf("ncgi_convertToJSON() failed [nid]");
			goto end;
		}
	}

end:
	return item;
}

ncgi_t *ncgi_parseFromJSON(cJSON *ncgiJSON) {
	ncgi_t *ncgi_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_t *plmn_id_local_nonprim = NULL;
	cJSON *nr_cell_id = NULL;
	cJSON *nid = NULL;
	plmn_id = cJSON_GetObjectItemCaseSensitive(ncgiJSON, "plmnId");
	if(!plmn_id) {
		printf("ncgi_parseFromJSON() failed [plmn_id]");
		goto end;
	}
	plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id);
	if(!plmn_id_local_nonprim) {
		printf("plmn_id_parseFromJSON failed [plmn_id]");
		goto end;
	}

	nr_cell_id = cJSON_GetObjectItemCaseSensitive(ncgiJSON, "nrCellId");
	if(!nr_cell_id) {
		printf("ncgi_parseFromJSON() failed [nr_cell_id]");
		goto end;
	}
	if(!cJSON_IsString(nr_cell_id)) {
		printf("ncgi_parseFromJSON() failed [nr_cell_id]");
		goto end;
	}

	nid = cJSON_GetObjectItemCaseSensitive(ncgiJSON, "nid");
	if(nid) {
		if(!cJSON_IsString(nid) &&
		   !cJSON_IsNull(nid))
		{
			printf("ncgi_parseFromJSON() failed [nid]");
			goto end;
		}
	}

	ncgi_local_var = ncgi_create(
		plmn_id_local_nonprim,
		strdup(nr_cell_id->valuestring),
		nid &&
		!cJSON_IsNull(nid) ? strdup(nid->valuestring) : NULL
		);

	return ncgi_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	return NULL;
}

ncgi_t *ncgi_copy(ncgi_t *dst, ncgi_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ncgi_convertToJSON(src);
	if(!item) {
		printf("ncgi_convertToJSON() failed");
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

	ncgi_free(dst);
	dst = ncgi_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
