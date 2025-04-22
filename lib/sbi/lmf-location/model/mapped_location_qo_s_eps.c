#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mapped_location_qo_s_eps.h"

mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_create(
	float	h_accuracy,
	bool	is_v_accuracy,
	float	v_accuracy)
{
	mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_local_var = malloc(
		sizeof(mapped_location_qo_s_eps_t));

	mapped_location_qo_s_eps_local_var->h_accuracy = h_accuracy;
	mapped_location_qo_s_eps_local_var->is_v_accuracy = is_v_accuracy;
	mapped_location_qo_s_eps_local_var->v_accuracy = v_accuracy;

	return mapped_location_qo_s_eps_local_var;
}

void mapped_location_qo_s_eps_free(
	mapped_location_qo_s_eps_t *mapped_location_qo_s_eps) {
	lnode_t *node = NULL;

	if(NULL == mapped_location_qo_s_eps) {
		return;
	}
	free(mapped_location_qo_s_eps);
}

cJSON *mapped_location_qo_s_eps_convertToJSON(
	mapped_location_qo_s_eps_t *mapped_location_qo_s_eps) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(mapped_location_qo_s_eps == NULL) {
		printf(
			"mapped_location_qo_s_eps_convertToJSON() failed [MappedLocationQoSEps]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "hAccuracy",
	                           mapped_location_qo_s_eps->h_accuracy) ==
	   NULL)
	{
		printf(
			"mapped_location_qo_s_eps_convertToJSON() failed [h_accuracy]");
		goto end;
	}

	if(mapped_location_qo_s_eps->is_v_accuracy) {
		if(cJSON_AddNumberToObject(item, "vAccuracy",
		                           mapped_location_qo_s_eps->v_accuracy)
		   == NULL)
		{
			printf(
				"mapped_location_qo_s_eps_convertToJSON() failed [v_accuracy]");
			goto end;
		}
	}

end:
	return item;
}

mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_parseFromJSON(
	cJSON *mapped_location_qo_s_epsJSON) {
	mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *h_accuracy = NULL;
	cJSON *v_accuracy = NULL;
	h_accuracy = cJSON_GetObjectItemCaseSensitive(
		mapped_location_qo_s_epsJSON, "hAccuracy");
	if(!h_accuracy) {
		printf(
			"mapped_location_qo_s_eps_parseFromJSON() failed [h_accuracy]");
		goto end;
	}
	if(!cJSON_IsNumber(h_accuracy)) {
		printf(
			"mapped_location_qo_s_eps_parseFromJSON() failed [h_accuracy]");
		goto end;
	}

	v_accuracy = cJSON_GetObjectItemCaseSensitive(
		mapped_location_qo_s_epsJSON, "vAccuracy");
	if(v_accuracy) {
		if(!cJSON_IsNumber(v_accuracy)) {
			printf(
				"mapped_location_qo_s_eps_parseFromJSON() failed [v_accuracy]");
			goto end;
		}
	}

	mapped_location_qo_s_eps_local_var = mapped_location_qo_s_eps_create(

		h_accuracy->valuedouble,
		v_accuracy ? true : false,
		v_accuracy ? v_accuracy->valuedouble : 0
		);

	return mapped_location_qo_s_eps_local_var;
end:
	return NULL;
}

mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_copy(
	mapped_location_qo_s_eps_t *dst, mapped_location_qo_s_eps_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = mapped_location_qo_s_eps_convertToJSON(src);
	if(!item) {
		printf("mapped_location_qo_s_eps_convertToJSON() failed");
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

	mapped_location_qo_s_eps_free(dst);
	dst = mapped_location_qo_s_eps_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
