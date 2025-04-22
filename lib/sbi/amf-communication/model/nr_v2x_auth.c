#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nr_v2x_auth.h"

nr_v2x_auth_t *nr_v2x_auth_create(ue_auth_t	*vehicle_ue_auth,
                                  ue_auth_t	*pedestrian_ue_auth) {
	nr_v2x_auth_t *nr_v2x_auth_local_var = malloc(sizeof(nr_v2x_auth_t));

	nr_v2x_auth_local_var->vehicle_ue_auth = vehicle_ue_auth;
	nr_v2x_auth_local_var->pedestrian_ue_auth = pedestrian_ue_auth;

	return nr_v2x_auth_local_var;
}

void nr_v2x_auth_free(nr_v2x_auth_t *nr_v2x_auth) {
	lnode_t *node = NULL;

	if(NULL == nr_v2x_auth) {
		return;
	}
	if(nr_v2x_auth->vehicle_ue_auth) {
		ue_auth_free(nr_v2x_auth->vehicle_ue_auth);
		nr_v2x_auth->vehicle_ue_auth = NULL;
	}
	if(nr_v2x_auth->pedestrian_ue_auth) {
		ue_auth_free(nr_v2x_auth->pedestrian_ue_auth);
		nr_v2x_auth->pedestrian_ue_auth = NULL;
	}
	free(nr_v2x_auth);
}

cJSON *nr_v2x_auth_convertToJSON(nr_v2x_auth_t *nr_v2x_auth) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nr_v2x_auth == NULL) {
		printf("nr_v2x_auth_convertToJSON() failed [NrV2xAuth]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(nr_v2x_auth->vehicle_ue_auth) {
		cJSON *vehicle_ue_auth_local_JSON = ue_auth_convertToJSON(
			nr_v2x_auth->vehicle_ue_auth);
		if(vehicle_ue_auth_local_JSON == NULL) {
			printf(
				"nr_v2x_auth_convertToJSON() failed [vehicle_ue_auth]");
			goto end;
		}
		cJSON_AddItemToObject(item, "vehicleUeAuth",
		                      vehicle_ue_auth_local_JSON);
		if(item->child == NULL) {
			printf(
				"nr_v2x_auth_convertToJSON() failed [vehicle_ue_auth]");
			goto end;
		}
	}

	if(nr_v2x_auth->pedestrian_ue_auth) {
		cJSON *pedestrian_ue_auth_local_JSON = ue_auth_convertToJSON(
			nr_v2x_auth->pedestrian_ue_auth);
		if(pedestrian_ue_auth_local_JSON == NULL) {
			printf(
				"nr_v2x_auth_convertToJSON() failed [pedestrian_ue_auth]");
			goto end;
		}
		cJSON_AddItemToObject(item, "pedestrianUeAuth",
		                      pedestrian_ue_auth_local_JSON);
		if(item->child == NULL) {
			printf(
				"nr_v2x_auth_convertToJSON() failed [pedestrian_ue_auth]");
			goto end;
		}
	}

end:
	return item;
}

nr_v2x_auth_t *nr_v2x_auth_parseFromJSON(cJSON *nr_v2x_authJSON) {
	nr_v2x_auth_t *nr_v2x_auth_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *vehicle_ue_auth = NULL;
	ue_auth_t *vehicle_ue_auth_local_nonprim = NULL;
	cJSON *pedestrian_ue_auth = NULL;
	ue_auth_t *pedestrian_ue_auth_local_nonprim = NULL;
	vehicle_ue_auth = cJSON_GetObjectItemCaseSensitive(nr_v2x_authJSON,
	                                                   "vehicleUeAuth");
	if(vehicle_ue_auth) {
		vehicle_ue_auth_local_nonprim = ue_auth_parseFromJSON(
			vehicle_ue_auth);
		if(!vehicle_ue_auth_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [vehicle_ue_auth]");
			goto end;
		}
	}

	pedestrian_ue_auth = cJSON_GetObjectItemCaseSensitive(nr_v2x_authJSON,
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

	nr_v2x_auth_local_var = nr_v2x_auth_create(
		vehicle_ue_auth ? vehicle_ue_auth_local_nonprim : NULL,
		pedestrian_ue_auth ? pedestrian_ue_auth_local_nonprim : NULL
		);

	return nr_v2x_auth_local_var;
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

nr_v2x_auth_t *nr_v2x_auth_copy(nr_v2x_auth_t *dst, nr_v2x_auth_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nr_v2x_auth_convertToJSON(src);
	if(!item) {
		printf("nr_v2x_auth_convertToJSON() failed");
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

	nr_v2x_auth_free(dst);
	dst = nr_v2x_auth_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
