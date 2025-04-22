#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ladn_info.h"

ladn_info_t *ladn_info_create(char *ladn, presence_state_t *presence) {
	ladn_info_t *ladn_info_local_var = malloc(sizeof(ladn_info_t));

	ladn_info_local_var->ladn = ladn;
	ladn_info_local_var->presence = presence;

	return ladn_info_local_var;
}

void ladn_info_free(ladn_info_t *ladn_info) {
	lnode_t *node = NULL;

	if(NULL == ladn_info) {
		return;
	}
	if(ladn_info->ladn) {
		free(ladn_info->ladn);
		ladn_info->ladn = NULL;
	}
	if(ladn_info->presence) {
		presence_state_free(ladn_info->presence);
		ladn_info->presence = NULL;
	}
	free(ladn_info);
}

cJSON *ladn_info_convertToJSON(ladn_info_t *ladn_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ladn_info == NULL) {
		printf("ladn_info_convertToJSON() failed [LadnInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ladn_info->ladn) {
		printf("ladn_info_convertToJSON() failed [ladn]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "ladn", ladn_info->ladn) == NULL) {
		printf("ladn_info_convertToJSON() failed [ladn]");
		goto end;
	}

	if(ladn_info->presence) {
		cJSON *presence_local_JSON = presence_state_convertToJSON(
			ladn_info->presence);
		if(presence_local_JSON == NULL) {
			printf("ladn_info_convertToJSON() failed [presence]");
			goto end;
		}
		cJSON_AddItemToObject(item, "presence", presence_local_JSON);
		if(item->child == NULL) {
			printf("ladn_info_convertToJSON() failed [presence]");
			goto end;
		}
	}

end:
	return item;
}

ladn_info_t *ladn_info_parseFromJSON(cJSON *ladn_infoJSON) {
	ladn_info_t *ladn_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ladn = NULL;
	cJSON *presence = NULL;
	presence_state_t *presence_local_nonprim = NULL;
	ladn = cJSON_GetObjectItemCaseSensitive(ladn_infoJSON, "ladn");
	if(!ladn) {
		printf("ladn_info_parseFromJSON() failed [ladn]");
		goto end;
	}
	if(!cJSON_IsString(ladn)) {
		printf("ladn_info_parseFromJSON() failed [ladn]");
		goto end;
	}

	presence = cJSON_GetObjectItemCaseSensitive(ladn_infoJSON, "presence");
	if(presence) {
		presence_local_nonprim = presence_state_parseFromJSON(presence);
		if(!presence_local_nonprim) {
			printf("presence_state_parseFromJSON failed [presence]");
			goto end;
		}
	}

	ladn_info_local_var = ladn_info_create(
		strdup(ladn->valuestring),
		presence ? presence_local_nonprim : NULL
		);

	return ladn_info_local_var;
end:
	if(presence_local_nonprim) {
		presence_state_free(presence_local_nonprim);
		presence_local_nonprim = NULL;
	}
	return NULL;
}

ladn_info_t *ladn_info_copy(ladn_info_t *dst, ladn_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ladn_info_convertToJSON(src);
	if(!item) {
		printf("ladn_info_convertToJSON() failed");
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

	ladn_info_free(dst);
	dst = ladn_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
