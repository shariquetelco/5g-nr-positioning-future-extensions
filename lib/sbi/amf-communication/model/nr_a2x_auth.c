#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nr_a2x_auth.h"

nr_a2x_auth_t *nr_a2x_auth_create(ue_auth_t *uav_ue_auth) {
	nr_a2x_auth_t *nr_a2x_auth_local_var = malloc(sizeof(nr_a2x_auth_t));

	nr_a2x_auth_local_var->uav_ue_auth = uav_ue_auth;

	return nr_a2x_auth_local_var;
}

void nr_a2x_auth_free(nr_a2x_auth_t *nr_a2x_auth) {
	lnode_t *node = NULL;

	if(NULL == nr_a2x_auth) {
		return;
	}
	if(nr_a2x_auth->uav_ue_auth) {
		ue_auth_free(nr_a2x_auth->uav_ue_auth);
		nr_a2x_auth->uav_ue_auth = NULL;
	}
	free(nr_a2x_auth);
}

cJSON *nr_a2x_auth_convertToJSON(nr_a2x_auth_t *nr_a2x_auth) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nr_a2x_auth == NULL) {
		printf("nr_a2x_auth_convertToJSON() failed [NrA2xAuth]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(nr_a2x_auth->uav_ue_auth) {
		cJSON *uav_ue_auth_local_JSON = ue_auth_convertToJSON(
			nr_a2x_auth->uav_ue_auth);
		if(uav_ue_auth_local_JSON == NULL) {
			printf(
				"nr_a2x_auth_convertToJSON() failed [uav_ue_auth]");
			goto end;
		}
		cJSON_AddItemToObject(item, "uavUeAuth",
		                      uav_ue_auth_local_JSON);
		if(item->child == NULL) {
			printf(
				"nr_a2x_auth_convertToJSON() failed [uav_ue_auth]");
			goto end;
		}
	}

end:
	return item;
}

nr_a2x_auth_t *nr_a2x_auth_parseFromJSON(cJSON *nr_a2x_authJSON) {
	nr_a2x_auth_t *nr_a2x_auth_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *uav_ue_auth = NULL;
	ue_auth_t *uav_ue_auth_local_nonprim = NULL;
	uav_ue_auth = cJSON_GetObjectItemCaseSensitive(nr_a2x_authJSON,
	                                               "uavUeAuth");
	if(uav_ue_auth) {
		uav_ue_auth_local_nonprim = ue_auth_parseFromJSON(uav_ue_auth);
		if(!uav_ue_auth_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [uav_ue_auth]");
			goto end;
		}
	}

	nr_a2x_auth_local_var = nr_a2x_auth_create(
		uav_ue_auth ? uav_ue_auth_local_nonprim : NULL
		);

	return nr_a2x_auth_local_var;
end:
	if(uav_ue_auth_local_nonprim) {
		ue_auth_free(uav_ue_auth_local_nonprim);
		uav_ue_auth_local_nonprim = NULL;
	}
	return NULL;
}

nr_a2x_auth_t *nr_a2x_auth_copy(nr_a2x_auth_t *dst, nr_a2x_auth_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nr_a2x_auth_convertToJSON(src);
	if(!item) {
		printf("nr_a2x_auth_convertToJSON() failed");
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

	nr_a2x_auth_free(dst);
	dst = nr_a2x_auth_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
