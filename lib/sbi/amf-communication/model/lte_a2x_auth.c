#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lte_a2x_auth.h"

lte_a2x_auth_t *lte_a2x_auth_create(ue_auth_t *uav_ue_auth) {
	lte_a2x_auth_t *lte_a2x_auth_local_var = malloc(sizeof(lte_a2x_auth_t));

	lte_a2x_auth_local_var->uav_ue_auth = uav_ue_auth;

	return lte_a2x_auth_local_var;
}

void lte_a2x_auth_free(lte_a2x_auth_t *lte_a2x_auth) {
	lnode_t *node = NULL;

	if(NULL == lte_a2x_auth) {
		return;
	}
	if(lte_a2x_auth->uav_ue_auth) {
		ue_auth_free(lte_a2x_auth->uav_ue_auth);
		lte_a2x_auth->uav_ue_auth = NULL;
	}
	free(lte_a2x_auth);
}

cJSON *lte_a2x_auth_convertToJSON(lte_a2x_auth_t *lte_a2x_auth) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(lte_a2x_auth == NULL) {
		printf("lte_a2x_auth_convertToJSON() failed [LteA2xAuth]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(lte_a2x_auth->uav_ue_auth) {
		cJSON *uav_ue_auth_local_JSON = ue_auth_convertToJSON(
			lte_a2x_auth->uav_ue_auth);
		if(uav_ue_auth_local_JSON == NULL) {
			printf(
				"lte_a2x_auth_convertToJSON() failed [uav_ue_auth]");
			goto end;
		}
		cJSON_AddItemToObject(item, "uavUeAuth",
		                      uav_ue_auth_local_JSON);
		if(item->child == NULL) {
			printf(
				"lte_a2x_auth_convertToJSON() failed [uav_ue_auth]");
			goto end;
		}
	}

end:
	return item;
}

lte_a2x_auth_t *lte_a2x_auth_parseFromJSON(cJSON *lte_a2x_authJSON) {
	lte_a2x_auth_t *lte_a2x_auth_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *uav_ue_auth = NULL;
	ue_auth_t *uav_ue_auth_local_nonprim = NULL;
	uav_ue_auth = cJSON_GetObjectItemCaseSensitive(lte_a2x_authJSON,
	                                               "uavUeAuth");
	if(uav_ue_auth) {
		uav_ue_auth_local_nonprim = ue_auth_parseFromJSON(uav_ue_auth);
		if(!uav_ue_auth_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [uav_ue_auth]");
			goto end;
		}
	}

	lte_a2x_auth_local_var = lte_a2x_auth_create(
		uav_ue_auth ? uav_ue_auth_local_nonprim : NULL
		);

	return lte_a2x_auth_local_var;
end:
	if(uav_ue_auth_local_nonprim) {
		ue_auth_free(uav_ue_auth_local_nonprim);
		uav_ue_auth_local_nonprim = NULL;
	}
	return NULL;
}

lte_a2x_auth_t *lte_a2x_auth_copy(lte_a2x_auth_t *dst, lte_a2x_auth_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = lte_a2x_auth_convertToJSON(src);
	if(!item) {
		printf("lte_a2x_auth_convertToJSON() failed");
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

	lte_a2x_auth_free(dst);
	dst = lte_a2x_auth_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
