#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lte_v2x_auth.h"

lte_v2x_auth_t *lte_v2x_auth_create(ue_auth_t	*vehicle_ue_auth,
                                    ue_auth_t	*pedestrian_ue_auth) {
	lte_v2x_auth_t *lte_v2x_auth_local_var = malloc(sizeof(lte_v2x_auth_t));

	lte_v2x_auth_local_var->vehicle_ue_auth = vehicle_ue_auth;
	lte_v2x_auth_local_var->pedestrian_ue_auth = pedestrian_ue_auth;

	return lte_v2x_auth_local_var;
}

void lte_v2x_auth_free(lte_v2x_auth_t *lte_v2x_auth) {
	lnode_t *node = NULL;

	if(NULL == lte_v2x_auth) {
		return;
	}
	if(lte_v2x_auth->vehicle_ue_auth) {
		ue_auth_free(lte_v2x_auth->vehicle_ue_auth);
		lte_v2x_auth->vehicle_ue_auth = NULL;
	}
	if(lte_v2x_auth->pedestrian_ue_auth) {
		ue_auth_free(lte_v2x_auth->pedestrian_ue_auth);
		lte_v2x_auth->pedestrian_ue_auth = NULL;
	}
	free(lte_v2x_auth);
}

cJSON *lte_v2x_auth_convertToJSON(lte_v2x_auth_t *lte_v2x_auth) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(lte_v2x_auth == NULL) {
		printf("lte_v2x_auth_convertToJSON() failed [LteV2xAuth]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(lte_v2x_auth->vehicle_ue_auth) {
		cJSON *vehicle_ue_auth_local_JSON = ue_auth_convertToJSON(
			lte_v2x_auth->vehicle_ue_auth);
		if(vehicle_ue_auth_local_JSON == NULL) {
			printf(
				"lte_v2x_auth_convertToJSON() failed [vehicle_ue_auth]");
			goto end;
		}
		cJSON_AddItemToObject(item, "vehicleUeAuth",
		                      vehicle_ue_auth_local_JSON);
		if(item->child == NULL) {
			printf(
				"lte_v2x_auth_convertToJSON() failed [vehicle_ue_auth]");
			goto end;
		}
	}

	if(lte_v2x_auth->pedestrian_ue_auth) {
		cJSON *pedestrian_ue_auth_local_JSON = ue_auth_convertToJSON(
			lte_v2x_auth->pedestrian_ue_auth);
		if(pedestrian_ue_auth_local_JSON == NULL) {
			printf(
				"lte_v2x_auth_convertToJSON() failed [pedestrian_ue_auth]");
			goto end;
		}
		cJSON_AddItemToObject(item, "pedestrianUeAuth",
		                      pedestrian_ue_auth_local_JSON);
		if(item->child == NULL) {
			printf(
				"lte_v2x_auth_convertToJSON() failed [pedestrian_ue_auth]");
			goto end;
		}
	}

end:
	return item;
}

lte_v2x_auth_t *lte_v2x_auth_parseFromJSON(cJSON *lte_v2x_authJSON) {
	lte_v2x_auth_t *lte_v2x_auth_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *vehicle_ue_auth = NULL;
	ue_auth_t *vehicle_ue_auth_local_nonprim = NULL;
	cJSON *pedestrian_ue_auth = NULL;
	ue_auth_t *pedestrian_ue_auth_local_nonprim = NULL;
	vehicle_ue_auth = cJSON_GetObjectItemCaseSensitive(lte_v2x_authJSON,
	                                                   "vehicleUeAuth");
	if(vehicle_ue_auth) {
		vehicle_ue_auth_local_nonprim = ue_auth_parseFromJSON(
			vehicle_ue_auth);
		if(!vehicle_ue_auth_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [vehicle_ue_auth]");
			goto end;
		}
	}

	pedestrian_ue_auth = cJSON_GetObjectItemCaseSensitive(lte_v2x_authJSON,
	                                                      "pedestrianUeAuth");
	if(pedestrian_ue_auth) {
		pedestrian_ue_auth_local_nonprim = ue_auth_parseFromJSON(
			pedestrian_ue_auth);
		if(!pedestrian_ue_auth_local_nonprim) {
			printf(
				"ue_auth_parseFromJSON failed [pedestrian_ue_auth]");
			goto end;
		}
	}

	lte_v2x_auth_local_var = lte_v2x_auth_create(
		vehicle_ue_auth ? vehicle_ue_auth_local_nonprim : NULL,
		pedestrian_ue_auth ? pedestrian_ue_auth_local_nonprim : NULL
		);

	return lte_v2x_auth_local_var;
end:
	if(vehicle_ue_auth_local_nonprim) {
		ue_auth_free(vehicle_ue_auth_local_nonprim);
		vehicle_ue_auth_local_nonprim = NULL;
	}
	if(pedestrian_ue_auth_local_nonprim) {
		ue_auth_free(pedestrian_ue_auth_local_nonprim);
		pedestrian_ue_auth_local_nonprim = NULL;
	}
	return NULL;
}

lte_v2x_auth_t *lte_v2x_auth_copy(lte_v2x_auth_t *dst, lte_v2x_auth_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = lte_v2x_auth_convertToJSON(src);
	if(!item) {
		printf("lte_v2x_auth_convertToJSON() failed");
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

	lte_v2x_auth_free(dst);
	dst = lte_v2x_auth_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
