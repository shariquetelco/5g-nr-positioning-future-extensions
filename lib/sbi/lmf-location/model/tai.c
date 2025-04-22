#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tai.h"

tai_t *tai_create(plmn_id_t *plmn_id, char *tac, char *nid) {
	tai_t *tai_local_var = malloc(sizeof(tai_t));

	tai_local_var->plmn_id = plmn_id;
	tai_local_var->tac = tac;
	tai_local_var->nid = nid;

	return tai_local_var;
}

void tai_free(tai_t *tai) {
	lnode_t *node = NULL;

	if(NULL == tai) {
		return;
	}
	if(tai->plmn_id) {
		plmn_id_free(tai->plmn_id);
		tai->plmn_id = NULL;
	}
	if(tai->tac) {
		free(tai->tac);
		tai->tac = NULL;
	}
	if(tai->nid) {
		free(tai->nid);
		tai->nid = NULL;
	}
	free(tai);
}

cJSON *tai_convertToJSON(tai_t *tai) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(tai == NULL) {
		printf("tai_convertToJSON() failed [Tai]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!tai->plmn_id) {
		printf("tai_convertToJSON() failed [plmn_id]");
		return NULL;
	}
	cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(tai->plmn_id);
	if(plmn_id_local_JSON == NULL) {
		printf("tai_convertToJSON() failed [plmn_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
	if(item->child == NULL) {
		printf("tai_convertToJSON() failed [plmn_id]");
		goto end;
	}

	if(!tai->tac) {
		printf("tai_convertToJSON() failed [tac]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "tac", tai->tac) == NULL) {
		printf("tai_convertToJSON() failed [tac]");
		goto end;
	}

	if(tai->nid) {
		if(cJSON_AddStringToObject(item, "nid", tai->nid) == NULL) {
			printf("tai_convertToJSON() failed [nid]");
			goto end;
		}
	}

end:
	return item;
}

tai_t *tai_parseFromJSON(cJSON *taiJSON) {
	tai_t *tai_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_t *plmn_id_local_nonprim = NULL;
	cJSON *tac = NULL;
	cJSON *nid = NULL;
	plmn_id = cJSON_GetObjectItemCaseSensitive(taiJSON, "plmnId");
	if(!plmn_id) {
		printf("tai_parseFromJSON() failed [plmn_id]");
		goto end;
	}
	plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id);
	if(!plmn_id_local_nonprim) {
		printf("plmn_id_parseFromJSON failed [plmn_id]");
		goto end;
	}

	tac = cJSON_GetObjectItemCaseSensitive(taiJSON, "tac");
	if(!tac) {
		printf("tai_parseFromJSON() failed [tac]");
		goto end;
	}
	if(!cJSON_IsString(tac)) {
		printf("tai_parseFromJSON() failed [tac]");
		goto end;
	}

	nid = cJSON_GetObjectItemCaseSensitive(taiJSON, "nid");
	if(nid) {
		if(!cJSON_IsString(nid) &&
		   !cJSON_IsNull(nid))
		{
			printf("tai_parseFromJSON() failed [nid]");
			goto end;
		}
	}

	tai_local_var = tai_create(
		plmn_id_local_nonprim,
		strdup(tac->valuestring),
		nid &&
		!cJSON_IsNull(nid) ? strdup(nid->valuestring) : NULL
		);

	return tai_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	return NULL;
}

tai_t *tai_copy(tai_t *dst, tai_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = tai_convertToJSON(src);
	if(!item) {
		printf("tai_convertToJSON() failed");
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

	tai_free(dst);
	dst = tai_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
