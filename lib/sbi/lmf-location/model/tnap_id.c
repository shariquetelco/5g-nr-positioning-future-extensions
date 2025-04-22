#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tnap_id.h"

tnap_id_t *tnap_id_create(char *ss_id, char *bss_id, char *civic_address) {
	tnap_id_t *tnap_id_local_var = malloc(sizeof(tnap_id_t));

	tnap_id_local_var->ss_id = ss_id;
	tnap_id_local_var->bss_id = bss_id;
	tnap_id_local_var->civic_address = civic_address;

	return tnap_id_local_var;
}

void tnap_id_free(tnap_id_t *tnap_id) {
	lnode_t *node = NULL;

	if(NULL == tnap_id) {
		return;
	}
	if(tnap_id->ss_id) {
		free(tnap_id->ss_id);
		tnap_id->ss_id = NULL;
	}
	if(tnap_id->bss_id) {
		free(tnap_id->bss_id);
		tnap_id->bss_id = NULL;
	}
	if(tnap_id->civic_address) {
		free(tnap_id->civic_address);
		tnap_id->civic_address = NULL;
	}
	free(tnap_id);
}

cJSON *tnap_id_convertToJSON(tnap_id_t *tnap_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(tnap_id == NULL) {
		printf("tnap_id_convertToJSON() failed [TnapId]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(tnap_id->ss_id) {
		if(cJSON_AddStringToObject(item, "ssId",
		                           tnap_id->ss_id) == NULL)
		{
			printf("tnap_id_convertToJSON() failed [ss_id]");
			goto end;
		}
	}

	if(tnap_id->bss_id) {
		if(cJSON_AddStringToObject(item, "bssId",
		                           tnap_id->bss_id) == NULL)
		{
			printf("tnap_id_convertToJSON() failed [bss_id]");
			goto end;
		}
	}

	if(tnap_id->civic_address) {
		if(cJSON_AddStringToObject(item, "civicAddress",
		                           tnap_id->civic_address) == NULL)
		{
			printf("tnap_id_convertToJSON() failed [civic_address]");
			goto end;
		}
	}

end:
	return item;
}

tnap_id_t *tnap_id_parseFromJSON(cJSON *tnap_idJSON) {
	tnap_id_t *tnap_id_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ss_id = NULL;
	cJSON *bss_id = NULL;
	cJSON *civic_address = NULL;
	ss_id = cJSON_GetObjectItemCaseSensitive(tnap_idJSON, "ssId");
	if(ss_id) {
		if(!cJSON_IsString(ss_id) &&
		   !cJSON_IsNull(ss_id))
		{
			printf("tnap_id_parseFromJSON() failed [ss_id]");
			goto end;
		}
	}

	bss_id = cJSON_GetObjectItemCaseSensitive(tnap_idJSON, "bssId");
	if(bss_id) {
		if(!cJSON_IsString(bss_id) &&
		   !cJSON_IsNull(bss_id))
		{
			printf("tnap_id_parseFromJSON() failed [bss_id]");
			goto end;
		}
	}

	civic_address = cJSON_GetObjectItemCaseSensitive(tnap_idJSON,
	                                                 "civicAddress");
	if(civic_address) {
		if(!cJSON_IsString(civic_address) &&
		   !cJSON_IsNull(civic_address))
		{
			printf("tnap_id_parseFromJSON() failed [civic_address]");
			goto end;
		}
	}

	tnap_id_local_var = tnap_id_create(
		ss_id &&
		!cJSON_IsNull(ss_id) ? strdup(ss_id->valuestring) : NULL,
		bss_id &&
		!cJSON_IsNull(bss_id) ? strdup(bss_id->valuestring) : NULL,
		civic_address &&
		!cJSON_IsNull(civic_address) ? strdup(
			civic_address->valuestring) : NULL
		);

	return tnap_id_local_var;
end:
	return NULL;
}

tnap_id_t *tnap_id_copy(tnap_id_t *dst, tnap_id_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = tnap_id_convertToJSON(src);
	if(!item) {
		printf("tnap_id_convertToJSON() failed");
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

	tnap_id_free(dst);
	dst = tnap_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
