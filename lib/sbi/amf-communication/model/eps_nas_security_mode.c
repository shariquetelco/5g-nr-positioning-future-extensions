#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "eps_nas_security_mode.h"

eps_nas_security_mode_t *eps_nas_security_mode_create(
	eps_nas_integrity_algorithm_e	integrity_algorithm,
	eps_nas_ciphering_algorithm_e	ciphering_algorithm) {
	eps_nas_security_mode_t *eps_nas_security_mode_local_var = malloc(
		sizeof(eps_nas_security_mode_t));

	eps_nas_security_mode_local_var->integrity_algorithm =
		integrity_algorithm;
	eps_nas_security_mode_local_var->ciphering_algorithm =
		ciphering_algorithm;

	return eps_nas_security_mode_local_var;
}

void eps_nas_security_mode_free(eps_nas_security_mode_t *eps_nas_security_mode)
{
	lnode_t *node = NULL;

	if(NULL == eps_nas_security_mode) {
		return;
	}
	free(eps_nas_security_mode);
}

cJSON *eps_nas_security_mode_convertToJSON(
	eps_nas_security_mode_t *eps_nas_security_mode) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(eps_nas_security_mode == NULL) {
		printf(
			"eps_nas_security_mode_convertToJSON() failed [EpsNasSecurityMode]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(eps_nas_security_mode->integrity_algorithm ==
	   eps_nas_integrity_algorithm_NULL)
	{
		printf(
			"eps_nas_security_mode_convertToJSON() failed [integrity_algorithm]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "integrityAlgorithm",
	                           eps_nas_integrity_algorithm_ToString(
					   eps_nas_security_mode->
					   integrity_algorithm))
	   == NULL)
	{
		printf(
			"eps_nas_security_mode_convertToJSON() failed [integrity_algorithm]");
		goto end;
	}

	if(eps_nas_security_mode->ciphering_algorithm ==
	   eps_nas_ciphering_algorithm_NULL)
	{
		printf(
			"eps_nas_security_mode_convertToJSON() failed [ciphering_algorithm]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "cipheringAlgorithm",
	                           eps_nas_ciphering_algorithm_ToString(
					   eps_nas_security_mode->
					   ciphering_algorithm))
	   == NULL)
	{
		printf(
			"eps_nas_security_mode_convertToJSON() failed [ciphering_algorithm]");
		goto end;
	}

end:
	return item;
}

eps_nas_security_mode_t *eps_nas_security_mode_parseFromJSON(
	cJSON *eps_nas_security_modeJSON) {
	eps_nas_security_mode_t *eps_nas_security_mode_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *integrity_algorithm = NULL;
	eps_nas_integrity_algorithm_e integrity_algorithmVariable = 0;
	cJSON *ciphering_algorithm = NULL;
	eps_nas_ciphering_algorithm_e ciphering_algorithmVariable = 0;
	integrity_algorithm = cJSON_GetObjectItemCaseSensitive(
		eps_nas_security_modeJSON, "integrityAlgorithm");
	if(!integrity_algorithm) {
		printf(
			"eps_nas_security_mode_parseFromJSON() failed [integrity_algorithm]");
		goto end;
	}
	if(!cJSON_IsString(integrity_algorithm)) {
		printf(
			"eps_nas_security_mode_parseFromJSON() failed [integrity_algorithm]");
		goto end;
	}
	integrity_algorithmVariable = eps_nas_integrity_algorithm_FromString(
		integrity_algorithm->valuestring);

	ciphering_algorithm = cJSON_GetObjectItemCaseSensitive(
		eps_nas_security_modeJSON, "cipheringAlgorithm");
	if(!ciphering_algorithm) {
		printf(
			"eps_nas_security_mode_parseFromJSON() failed [ciphering_algorithm]");
		goto end;
	}
	if(!cJSON_IsString(ciphering_algorithm)) {
		printf(
			"eps_nas_security_mode_parseFromJSON() failed [ciphering_algorithm]");
		goto end;
	}
	ciphering_algorithmVariable = eps_nas_ciphering_algorithm_FromString(
		ciphering_algorithm->valuestring);

	eps_nas_security_mode_local_var = eps_nas_security_mode_create(
		integrity_algorithmVariable,
		ciphering_algorithmVariable
		);

	return eps_nas_security_mode_local_var;
end:
	return NULL;
}

eps_nas_security_mode_t *eps_nas_security_mode_copy(
	eps_nas_security_mode_t *dst, eps_nas_security_mode_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = eps_nas_security_mode_convertToJSON(src);
	if(!item) {
		printf("eps_nas_security_mode_convertToJSON() failed");
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

	eps_nas_security_mode_free(dst);
	dst = eps_nas_security_mode_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
