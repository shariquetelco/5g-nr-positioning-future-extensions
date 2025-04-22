#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mbsr_info.h"

mbsr_info_t *mbsr_info_create(ncgi_t *ncgi, ecgi_t *ecgi) {
	mbsr_info_t *mbsr_info_local_var = malloc(sizeof(mbsr_info_t));

	mbsr_info_local_var->ncgi = ncgi;
	mbsr_info_local_var->ecgi = ecgi;

	return mbsr_info_local_var;
}

void mbsr_info_free(mbsr_info_t *mbsr_info) {
	lnode_t *node = NULL;

	if(NULL == mbsr_info) {
		return;
	}
	if(mbsr_info->ncgi) {
		ncgi_free(mbsr_info->ncgi);
		mbsr_info->ncgi = NULL;
	}
	if(mbsr_info->ecgi) {
		ecgi_free(mbsr_info->ecgi);
		mbsr_info->ecgi = NULL;
	}
	free(mbsr_info);
}

cJSON *mbsr_info_convertToJSON(mbsr_info_t *mbsr_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(mbsr_info == NULL) {
		printf("mbsr_info_convertToJSON() failed [MbsrInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(mbsr_info->ncgi) {
		cJSON *ncgi_local_JSON = ncgi_convertToJSON(mbsr_info->ncgi);
		if(ncgi_local_JSON == NULL) {
			printf("mbsr_info_convertToJSON() failed [ncgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
		if(item->child == NULL) {
			printf("mbsr_info_convertToJSON() failed [ncgi]");
			goto end;
		}
	}

	if(mbsr_info->ecgi) {
		cJSON *ecgi_local_JSON = ecgi_convertToJSON(mbsr_info->ecgi);
		if(ecgi_local_JSON == NULL) {
			printf("mbsr_info_convertToJSON() failed [ecgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
		if(item->child == NULL) {
			printf("mbsr_info_convertToJSON() failed [ecgi]");
			goto end;
		}
	}

end:
	return item;
}

mbsr_info_t *mbsr_info_parseFromJSON(cJSON *mbsr_infoJSON) {
	mbsr_info_t *mbsr_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ncgi = NULL;
	ncgi_t *ncgi_local_nonprim = NULL;
	cJSON *ecgi = NULL;
	ecgi_t *ecgi_local_nonprim = NULL;
	ncgi = cJSON_GetObjectItemCaseSensitive(mbsr_infoJSON, "ncgi");
	if(ncgi) {
		ncgi_local_nonprim = ncgi_parseFromJSON(ncgi);
		if(!ncgi_local_nonprim) {
			printf("ncgi_parseFromJSON failed [ncgi]");
			goto end;
		}
	}

	ecgi = cJSON_GetObjectItemCaseSensitive(mbsr_infoJSON, "ecgi");
	if(ecgi) {
		ecgi_local_nonprim = ecgi_parseFromJSON(ecgi);
		if(!ecgi_local_nonprim) {
			printf("ecgi_parseFromJSON failed [ecgi]");
			goto end;
		}
	}

	mbsr_info_local_var = mbsr_info_create(
		ncgi ? ncgi_local_nonprim : NULL,
		ecgi ? ecgi_local_nonprim : NULL
		);

	return mbsr_info_local_var;
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

mbsr_info_t *mbsr_info_copy(mbsr_info_t *dst, mbsr_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = mbsr_info_convertToJSON(src);
	if(!item) {
		printf("mbsr_info_convertToJSON() failed");
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

	mbsr_info_free(dst);
	dst = mbsr_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
