#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "additional_ue_info.h"

additional_ue_info_t *additional_ue_info_create(ncgi_t *ncgi, ecgi_t *ecgi) {
	additional_ue_info_t *additional_ue_info_local_var =
		malloc(sizeof(additional_ue_info_t));

	additional_ue_info_local_var->ncgi = ncgi;
	additional_ue_info_local_var->ecgi = ecgi;

	return additional_ue_info_local_var;
}

void additional_ue_info_free(additional_ue_info_t *additional_ue_info) {
	lnode_t *node = NULL;

	if(NULL == additional_ue_info) {
		return;
	}
	if(additional_ue_info->ncgi) {
		ncgi_free(additional_ue_info->ncgi);
		additional_ue_info->ncgi = NULL;
	}
	if(additional_ue_info->ecgi) {
		ecgi_free(additional_ue_info->ecgi);
		additional_ue_info->ecgi = NULL;
	}
	free(additional_ue_info);
}

cJSON *additional_ue_info_convertToJSON(
	additional_ue_info_t *additional_ue_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(additional_ue_info == NULL) {
		printf(
			"additional_ue_info_convertToJSON() failed [AdditionalUeInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(additional_ue_info->ncgi) {
		cJSON *ncgi_local_JSON = ncgi_convertToJSON(
			additional_ue_info->ncgi);
		if(ncgi_local_JSON == NULL) {
			printf(
				"additional_ue_info_convertToJSON() failed [ncgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
		if(item->child == NULL) {
			printf(
				"additional_ue_info_convertToJSON() failed [ncgi]");
			goto end;
		}
	}

	if(additional_ue_info->ecgi) {
		cJSON *ecgi_local_JSON = ecgi_convertToJSON(
			additional_ue_info->ecgi);
		if(ecgi_local_JSON == NULL) {
			printf(
				"additional_ue_info_convertToJSON() failed [ecgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
		if(item->child == NULL) {
			printf(
				"additional_ue_info_convertToJSON() failed [ecgi]");
			goto end;
		}
	}

end:
	return item;
}

additional_ue_info_t *additional_ue_info_parseFromJSON(
	cJSON *additional_ue_infoJSON) {
	additional_ue_info_t *additional_ue_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ncgi = NULL;
	ncgi_t *ncgi_local_nonprim = NULL;
	cJSON *ecgi = NULL;
	ecgi_t *ecgi_local_nonprim = NULL;
	ncgi = cJSON_GetObjectItemCaseSensitive(additional_ue_infoJSON, "ncgi");
	if(ncgi) {
		ncgi_local_nonprim = ncgi_parseFromJSON(ncgi);
		if(!ncgi_local_nonprim) {
			printf("ncgi_parseFromJSON failed [ncgi]");
			goto end;
		}
	}

	ecgi = cJSON_GetObjectItemCaseSensitive(additional_ue_infoJSON, "ecgi");
	if(ecgi) {
		ecgi_local_nonprim = ecgi_parseFromJSON(ecgi);
		if(!ecgi_local_nonprim) {
			printf("ecgi_parseFromJSON failed [ecgi]");
			goto end;
		}
	}

	additional_ue_info_local_var = additional_ue_info_create(
		ncgi ? ncgi_local_nonprim : NULL,
		ecgi ? ecgi_local_nonprim : NULL
		);

	return additional_ue_info_local_var;
end:
	if(ncgi_local_nonprim) {
		ncgi_free(ncgi_local_nonprim);
		ncgi_local_nonprim = NULL;
	}
	if(ecgi_local_nonprim) {
		ecgi_free(ecgi_local_nonprim);
		ecgi_local_nonprim = NULL;
	}
	return NULL;
}

additional_ue_info_t *additional_ue_info_copy(additional_ue_info_t	*dst,
                                              additional_ue_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = additional_ue_info_convertToJSON(src);
	if(!item) {
		printf("additional_ue_info_convertToJSON() failed");
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

	additional_ue_info_free(dst);
	dst = additional_ue_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
