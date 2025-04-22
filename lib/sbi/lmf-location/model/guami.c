#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "guami.h"

guami_t *guami_create(plmn_id_nid_t *plmn_id, char *amf_id) {
	guami_t *guami_local_var = malloc(sizeof(guami_t));

	guami_local_var->plmn_id = plmn_id;
	guami_local_var->amf_id = amf_id;

	return guami_local_var;
}

void guami_free(guami_t *guami) {
	lnode_t *node = NULL;

	if(NULL == guami) {
		return;
	}
	if(guami->plmn_id) {
		plmn_id_nid_free(guami->plmn_id);
		guami->plmn_id = NULL;
	}
	if(guami->amf_id) {
		free(guami->amf_id);
		guami->amf_id = NULL;
	}
	free(guami);
}

cJSON *guami_convertToJSON(guami_t *guami) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(guami == NULL) {
		printf("guami_convertToJSON() failed [Guami]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!guami->plmn_id) {
		printf("guami_convertToJSON() failed [plmn_id]");
		return NULL;
	}
	cJSON *plmn_id_local_JSON = plmn_id_nid_convertToJSON(guami->plmn_id);
	if(plmn_id_local_JSON == NULL) {
		printf("guami_convertToJSON() failed [plmn_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
	if(item->child == NULL) {
		printf("guami_convertToJSON() failed [plmn_id]");
		goto end;
	}

	if(!guami->amf_id) {
		printf("guami_convertToJSON() failed [amf_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "amfId", guami->amf_id) == NULL) {
		printf("guami_convertToJSON() failed [amf_id]");
		goto end;
	}

end:
	return item;
}

guami_t *guami_parseFromJSON(cJSON *guamiJSON) {
	guami_t *guami_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_nid_t *plmn_id_local_nonprim = NULL;
	cJSON *amf_id = NULL;
	plmn_id = cJSON_GetObjectItemCaseSensitive(guamiJSON, "plmnId");
	if(!plmn_id) {
		printf("guami_parseFromJSON() failed [plmn_id]");
		goto end;
	}
	plmn_id_local_nonprim = plmn_id_nid_parseFromJSON(plmn_id);
	if(!plmn_id_local_nonprim) {
		printf("plmn_id_nid_parseFromJSON failed [plmn_id]");
		goto end;
	}

	amf_id = cJSON_GetObjectItemCaseSensitive(guamiJSON, "amfId");
	if(!amf_id) {
		printf("guami_parseFromJSON() failed [amf_id]");
		goto end;
	}
	if(!cJSON_IsString(amf_id)) {
		printf("guami_parseFromJSON() failed [amf_id]");
		goto end;
	}

	guami_local_var = guami_create(
		plmn_id_local_nonprim,
		strdup(amf_id->valuestring)
		);

	return guami_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_nid_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	return NULL;
}

guami_t *guami_copy(guami_t *dst, guami_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = guami_convertToJSON(src);
	if(!item) {
		printf("guami_convertToJSON() failed");
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

	guami_free(dst);
	dst = guami_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
