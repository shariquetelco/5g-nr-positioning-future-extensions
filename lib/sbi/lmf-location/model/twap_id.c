#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "twap_id.h"

twap_id_t *twap_id_create(char *ss_id, char *bss_id, char *civic_address) {
	twap_id_t *twap_id_local_var = malloc(sizeof(twap_id_t));

	twap_id_local_var->ss_id = ss_id;
	twap_id_local_var->bss_id = bss_id;
	twap_id_local_var->civic_address = civic_address;

	return twap_id_local_var;
}

void twap_id_free(twap_id_t *twap_id) {
	lnode_t *node = NULL;

	if(NULL == twap_id) {
		return;
	}
	if(twap_id->ss_id) {
		free(twap_id->ss_id);
		twap_id->ss_id = NULL;
	}
	if(twap_id->bss_id) {
		free(twap_id->bss_id);
		twap_id->bss_id = NULL;
	}
	if(twap_id->civic_address) {
		free(twap_id->civic_address);
		twap_id->civic_address = NULL;
	}
	free(twap_id);
}

cJSON *twap_id_convertToJSON(twap_id_t *twap_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(twap_id == NULL) {
		printf("twap_id_convertToJSON() failed [TwapId]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!twap_id->ss_id) {
		printf("twap_id_convertToJSON() failed [ss_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "ssId", twap_id->ss_id) == NULL) {
		printf("twap_id_convertToJSON() failed [ss_id]");
		goto end;
	}

	if(twap_id->bss_id) {
		if(cJSON_AddStringToObject(item, "bssId",
		                           twap_id->bss_id) == NULL)
		{
			printf("twap_id_convertToJSON() failed [bss_id]");
			goto end;
		}
	}

	if(twap_id->civic_address) {
		if(cJSON_AddStringToObject(item, "civicAddress",
		                           twap_id->civic_address) == NULL)
		{
			printf("twap_id_convertToJSON() failed [civic_address]");
			goto end;
		}
	}

end:
	return item;
}

twap_id_t *twap_id_parseFromJSON(cJSON *twap_idJSON) {
	twap_id_t *twap_id_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ss_id = NULL;
	cJSON *bss_id = NULL;
	cJSON *civic_address = NULL;
	ss_id = cJSON_GetObjectItemCaseSensitive(twap_idJSON, "ssId");
	if(!ss_id) {
		printf("twap_id_parseFromJSON() failed [ss_id]");
		goto end;
	}
	if(!cJSON_IsString(ss_id)) {
		printf("twap_id_parseFromJSON() failed [ss_id]");
		goto end;
	}

	bss_id = cJSON_GetObjectItemCaseSensitive(twap_idJSON, "bssId");
	if(bss_id) {
		if(!cJSON_IsString(bss_id) &&
		   !cJSON_IsNull(bss_id))
		{
			printf("twap_id_parseFromJSON() failed [bss_id]");
			goto end;
		}
	}

	civic_address = cJSON_GetObjectItemCaseSensitive(twap_idJSON,
	                                                 "civicAddress");
	if(civic_address) {
		if(!cJSON_IsString(civic_address) &&
		   !cJSON_IsNull(civic_address))
		{
			printf("twap_id_parseFromJSON() failed [civic_address]");
			goto end;
		}
	}

	twap_id_local_var = twap_id_create(
		strdup(ss_id->valuestring),
		bss_id &&
		!cJSON_IsNull(bss_id) ? strdup(bss_id->valuestring) : NULL,
		civic_address &&
		!cJSON_IsNull(civic_address) ? strdup(
			civic_address->valuestring) : NULL
		);

	return twap_id_local_var;
end:
	return NULL;
}

twap_id_t *twap_id_copy(twap_id_t *dst, twap_id_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = twap_id_convertToJSON(src);
	if(!item) {
		printf("twap_id_convertToJSON() failed");
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

	twap_id_free(dst);
	dst = twap_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
