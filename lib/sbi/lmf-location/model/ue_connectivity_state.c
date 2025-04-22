#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_connectivity_state.h"

ue_connectivity_state_t *ue_connectivity_state_create(
	access_type_e	access_type,
	cm_state_t	*connectivitystate)
{
	ue_connectivity_state_t *ue_connectivity_state_local_var = malloc(
		sizeof(ue_connectivity_state_t));

	ue_connectivity_state_local_var->access_type = access_type;
	ue_connectivity_state_local_var->connectivitystate = connectivitystate;

	return ue_connectivity_state_local_var;
}

void ue_connectivity_state_free(ue_connectivity_state_t *ue_connectivity_state)
{
	lnode_t *node = NULL;

	if(NULL == ue_connectivity_state) {
		return;
	}
	if(ue_connectivity_state->connectivitystate) {
		cm_state_free(ue_connectivity_state->connectivitystate);
		ue_connectivity_state->connectivitystate = NULL;
	}
	free(ue_connectivity_state);
}

cJSON *ue_connectivity_state_convertToJSON(
	ue_connectivity_state_t *ue_connectivity_state) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_connectivity_state == NULL) {
		printf(
			"ue_connectivity_state_convertToJSON() failed [UeConnectivityState]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_connectivity_state->access_type == access_type_NULL) {
		printf(
			"ue_connectivity_state_convertToJSON() failed [access_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "accessType",
	                           access_type_ToString(ue_connectivity_state->
	                                                access_type)) == NULL)
	{
		printf(
			"ue_connectivity_state_convertToJSON() failed [access_type]");
		goto end;
	}

	if(ue_connectivity_state->connectivitystate) {
		cJSON *connectivitystate_local_JSON = cm_state_convertToJSON(
			ue_connectivity_state->connectivitystate);
		if(connectivitystate_local_JSON == NULL) {
			printf(
				"ue_connectivity_state_convertToJSON() failed [connectivitystate]");
			goto end;
		}
		cJSON_AddItemToObject(item, "connectivitystate",
		                      connectivitystate_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_connectivity_state_convertToJSON() failed [connectivitystate]");
			goto end;
		}
	}

end:
	return item;
}

ue_connectivity_state_t *ue_connectivity_state_parseFromJSON(
	cJSON *ue_connectivity_stateJSON) {
	ue_connectivity_state_t *ue_connectivity_state_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *access_type = NULL;
	access_type_e access_typeVariable = 0;
	cJSON *connectivitystate = NULL;
	cm_state_t *connectivitystate_local_nonprim = NULL;
	access_type = cJSON_GetObjectItemCaseSensitive(
		ue_connectivity_stateJSON, "accessType");
	if(!access_type) {
		printf(
			"ue_connectivity_state_parseFromJSON() failed [access_type]");
		goto end;
	}
	if(!cJSON_IsString(access_type)) {
		printf(
			"ue_connectivity_state_parseFromJSON() failed [access_type]");
		goto end;
	}
	access_typeVariable = access_type_FromString(access_type->valuestring);

	connectivitystate = cJSON_GetObjectItemCaseSensitive(
		ue_connectivity_stateJSON, "connectivitystate");
	if(connectivitystate) {
		connectivitystate_local_nonprim = cm_state_parseFromJSON(
			connectivitystate);
		if(!connectivitystate_local_nonprim) {
			printf(
				"cm_state_parseFromJSON failed [connectivitystate]");
			goto end;
		}
	}

	ue_connectivity_state_local_var = ue_connectivity_state_create(
		access_typeVariable,
		connectivitystate ? connectivitystate_local_nonprim : NULL
		);

	return ue_connectivity_state_local_var;
end:
	if(connectivitystate_local_nonprim) {
		cm_state_free(connectivitystate_local_nonprim);
		connectivitystate_local_nonprim = NULL;
	}
	return NULL;
}

ue_connectivity_state_t *ue_connectivity_state_copy(
	ue_connectivity_state_t *dst, ue_connectivity_state_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_connectivity_state_convertToJSON(src);
	if(!item) {
		printf("ue_connectivity_state_convertToJSON() failed");
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

	ue_connectivity_state_free(dst);
	dst = ue_connectivity_state_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
