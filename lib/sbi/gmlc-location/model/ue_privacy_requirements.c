#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_privacy_requirements.h"

ue_privacy_requirements_t *ue_privacy_requirements_create(
	lcs_service_auth_t *lcs_service_auth_info, bool is_code_word_check,
	int code_word_check) {
	ue_privacy_requirements_t *ue_privacy_requirements_local_var = malloc(
		sizeof(ue_privacy_requirements_t));

	ue_privacy_requirements_local_var->lcs_service_auth_info =
		lcs_service_auth_info;
	ue_privacy_requirements_local_var->is_code_word_check =
		is_code_word_check;
	ue_privacy_requirements_local_var->code_word_check = code_word_check;

	return ue_privacy_requirements_local_var;
}

void ue_privacy_requirements_free(
	ue_privacy_requirements_t *ue_privacy_requirements) {
	lnode_t *node = NULL;

	if(NULL == ue_privacy_requirements) {
		return;
	}
	if(ue_privacy_requirements->lcs_service_auth_info) {
		lcs_service_auth_free(
			ue_privacy_requirements->lcs_service_auth_info);
		ue_privacy_requirements->lcs_service_auth_info = NULL;
	}
	free(ue_privacy_requirements);
}

cJSON *ue_privacy_requirements_convertToJSON(
	ue_privacy_requirements_t *ue_privacy_requirements) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_privacy_requirements == NULL) {
		printf(
			"ue_privacy_requirements_convertToJSON() failed [UePrivacyRequirements]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_privacy_requirements->lcs_service_auth_info) {
		cJSON *lcs_service_auth_info_local_JSON =
			lcs_service_auth_convertToJSON(
				ue_privacy_requirements->lcs_service_auth_info);
		if(lcs_service_auth_info_local_JSON == NULL) {
			printf(
				"ue_privacy_requirements_convertToJSON() failed [lcs_service_auth_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "lcsServiceAuthInfo",
		                      lcs_service_auth_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_privacy_requirements_convertToJSON() failed [lcs_service_auth_info]");
			goto end;
		}
	}

	if(ue_privacy_requirements->is_code_word_check) {
		if(cJSON_AddBoolToObject(item, "codeWordCheck",
		                         ue_privacy_requirements->
		                         code_word_check) == NULL)
		{
			printf(
				"ue_privacy_requirements_convertToJSON() failed [code_word_check]");
			goto end;
		}
	}

end:
	return item;
}

ue_privacy_requirements_t *ue_privacy_requirements_parseFromJSON(
	cJSON *ue_privacy_requirementsJSON) {
	ue_privacy_requirements_t *ue_privacy_requirements_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *lcs_service_auth_info = NULL;
	lcs_service_auth_t *lcs_service_auth_info_local_nonprim = NULL;
	cJSON *code_word_check = NULL;
	lcs_service_auth_info = cJSON_GetObjectItemCaseSensitive(
		ue_privacy_requirementsJSON, "lcsServiceAuthInfo");
	if(lcs_service_auth_info) {
		lcs_service_auth_info_local_nonprim =
			lcs_service_auth_parseFromJSON(lcs_service_auth_info);
		if(!lcs_service_auth_info_local_nonprim) {
			printf(
				"lcs_service_auth_parseFromJSON failed [lcs_service_auth_info]");
			goto end;
		}
	}

	code_word_check = cJSON_GetObjectItemCaseSensitive(
		ue_privacy_requirementsJSON, "codeWordCheck");
	if(code_word_check) {
		if(!cJSON_IsBool(code_word_check)) {
			printf(
				"ue_privacy_requirements_parseFromJSON() failed [code_word_check]");
			goto end;
		}
	}

	ue_privacy_requirements_local_var = ue_privacy_requirements_create(
		lcs_service_auth_info ? lcs_service_auth_info_local_nonprim : NULL,
		code_word_check ? true : false,
		code_word_check ? code_word_check->valueint : 0
		);

	return ue_privacy_requirements_local_var;
end:
	if(lcs_service_auth_info_local_nonprim) {
		lcs_service_auth_free(lcs_service_auth_info_local_nonprim);
		lcs_service_auth_info_local_nonprim = NULL;
	}
	return NULL;
}

ue_privacy_requirements_t *ue_privacy_requirements_copy(
	ue_privacy_requirements_t *dst, ue_privacy_requirements_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_privacy_requirements_convertToJSON(src);
	if(!item) {
		printf("ue_privacy_requirements_convertToJSON() failed");
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

	ue_privacy_requirements_free(dst);
	dst = ue_privacy_requirements_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
