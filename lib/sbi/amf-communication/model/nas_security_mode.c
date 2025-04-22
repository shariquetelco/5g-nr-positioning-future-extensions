#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nas_security_mode.h"

nas_security_mode_t *nas_security_mode_create(
	integrity_algorithm_e	integrity_algorithm,
	ciphering_algorithm_e	ciphering_algorithm) {
	nas_security_mode_t *nas_security_mode_local_var =
		malloc(sizeof(nas_security_mode_t));

	nas_security_mode_local_var->integrity_algorithm = integrity_algorithm;
	nas_security_mode_local_var->ciphering_algorithm = ciphering_algorithm;

	return nas_security_mode_local_var;
}

void nas_security_mode_free(nas_security_mode_t *nas_security_mode) {
	lnode_t *node = NULL;

	if(NULL == nas_security_mode) {
		return;
	}
	free(nas_security_mode);
}

cJSON *nas_security_mode_convertToJSON(nas_security_mode_t *nas_security_mode) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nas_security_mode == NULL) {
		printf(
			"nas_security_mode_convertToJSON() failed [NasSecurityMode]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(nas_security_mode->integrity_algorithm == integrity_algorithm_NULL) {
		printf(
			"nas_security_mode_convertToJSON() failed [integrity_algorithm]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "integrityAlgorithm",
	                           integrity_algorithm_ToString(
					   nas_security_mode->
					   integrity_algorithm)) ==
	   NULL)
	{
		printf(
			"nas_security_mode_convertToJSON() failed [integrity_algorithm]");
		goto end;
	}

	if(nas_security_mode->ciphering_algorithm == ciphering_algorithm_NULL) {
		printf(
			"nas_security_mode_convertToJSON() failed [ciphering_algorithm]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "cipheringAlgorithm",
	                           ciphering_algorithm_ToString(
					   nas_security_mode->
					   ciphering_algorithm)) ==
	   NULL)
	{
		printf(
			"nas_security_mode_convertToJSON() failed [ciphering_algorithm]");
		goto end;
	}

end:
	return item;
}

nas_security_mode_t *nas_security_mode_parseFromJSON(
	cJSON *nas_security_modeJSON) {
	nas_security_mode_t *nas_security_mode_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *integrity_algorithm = NULL;
	integrity_algorithm_e integrity_algorithmVariable = 0;
	cJSON *ciphering_algorithm = NULL;
	ciphering_algorithm_e ciphering_algorithmVariable = 0;
	integrity_algorithm = cJSON_GetObjectItemCaseSensitive(
		nas_security_modeJSON, "integrityAlgorithm");
	if(!integrity_algorithm) {
		printf(
			"nas_security_mode_parseFromJSON() failed [integrity_algorithm]");
		goto end;
	}
	if(!cJSON_IsString(integrity_algorithm)) {
		printf(
			"nas_security_mode_parseFromJSON() failed [integrity_algorithm]");
		goto end;
	}
	integrity_algorithmVariable = integrity_algorithm_FromString(
		integrity_algorithm->valuestring);

	ciphering_algorithm = cJSON_GetObjectItemCaseSensitive(
		nas_security_modeJSON, "cipheringAlgorithm");
	if(!ciphering_algorithm) {
		printf(
			"nas_security_mode_parseFromJSON() failed [ciphering_algorithm]");
		goto end;
	}
	if(!cJSON_IsString(ciphering_algorithm)) {
		printf(
			"nas_security_mode_parseFromJSON() failed [ciphering_algorithm]");
		goto end;
	}
	ciphering_algorithmVariable = ciphering_algorithm_FromString(
		ciphering_algorithm->valuestring);

	nas_security_mode_local_var = nas_security_mode_create(
		integrity_algorithmVariable,
		ciphering_algorithmVariable
		);

	return nas_security_mode_local_var;
end:
	return NULL;
}

nas_security_mode_t *nas_security_mode_copy(nas_security_mode_t *dst,
                                            nas_security_mode_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nas_security_mode_convertToJSON(src);
	if(!item) {
		printf("nas_security_mode_convertToJSON() failed");
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

	nas_security_mode_free(dst);
	dst = nas_security_mode_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
