#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "configured_snssai.h"

configured_snssai_t *configured_snssai_create(snssai_t	*configured_snssai,
                                              snssai_t	*mapped_home_snssai) {
	configured_snssai_t *configured_snssai_local_var =
		malloc(sizeof(configured_snssai_t));

	configured_snssai_local_var->configured_snssai = configured_snssai;
	configured_snssai_local_var->mapped_home_snssai = mapped_home_snssai;

	return configured_snssai_local_var;
}

void configured_snssai_free(configured_snssai_t *configured_snssai) {
	lnode_t *node = NULL;

	if(NULL == configured_snssai) {
		return;
	}
	if(configured_snssai->configured_snssai) {
		snssai_free(configured_snssai->configured_snssai);
		configured_snssai->configured_snssai = NULL;
	}
	if(configured_snssai->mapped_home_snssai) {
		snssai_free(configured_snssai->mapped_home_snssai);
		configured_snssai->mapped_home_snssai = NULL;
	}
	free(configured_snssai);
}

cJSON *configured_snssai_convertToJSON(configured_snssai_t *configured_snssai) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(configured_snssai == NULL) {
		printf(
			"configured_snssai_convertToJSON() failed [ConfiguredSnssai]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!configured_snssai->configured_snssai) {
		printf(
			"configured_snssai_convertToJSON() failed [configured_snssai]");
		return NULL;
	}
	cJSON *configured_snssai_local_JSON = snssai_convertToJSON(
		configured_snssai->configured_snssai);
	if(configured_snssai_local_JSON == NULL) {
		printf(
			"configured_snssai_convertToJSON() failed [configured_snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "configuredSnssai",
	                      configured_snssai_local_JSON);
	if(item->child == NULL) {
		printf(
			"configured_snssai_convertToJSON() failed [configured_snssai]");
		goto end;
	}

	if(configured_snssai->mapped_home_snssai) {
		cJSON *mapped_home_snssai_local_JSON = snssai_convertToJSON(
			configured_snssai->mapped_home_snssai);
		if(mapped_home_snssai_local_JSON == NULL) {
			printf(
				"configured_snssai_convertToJSON() failed [mapped_home_snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "mappedHomeSnssai",
		                      mapped_home_snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"configured_snssai_convertToJSON() failed [mapped_home_snssai]");
			goto end;
		}
	}

end:
	return item;
}

configured_snssai_t *configured_snssai_parseFromJSON(
	cJSON *configured_snssaiJSON) {
	configured_snssai_t *configured_snssai_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *configured_snssai = NULL;
	snssai_t *configured_snssai_local_nonprim = NULL;
	cJSON *mapped_home_snssai = NULL;
	snssai_t *mapped_home_snssai_local_nonprim = NULL;
	configured_snssai = cJSON_GetObjectItemCaseSensitive(
		configured_snssaiJSON, "configuredSnssai");
	if(!configured_snssai) {
		printf(
			"configured_snssai_parseFromJSON() failed [configured_snssai]");
		goto end;
	}
	configured_snssai_local_nonprim =
		snssai_parseFromJSON(configured_snssai);
	if(!configured_snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [configured_snssai]");
		goto end;
	}

	mapped_home_snssai = cJSON_GetObjectItemCaseSensitive(
		configured_snssaiJSON, "mappedHomeSnssai");
	if(mapped_home_snssai) {
		mapped_home_snssai_local_nonprim = snssai_parseFromJSON(
			mapped_home_snssai);
		if(!mapped_home_snssai_local_nonprim) {
			printf(
				"snssai_parseFromJSON failed [mapped_home_snssai]");
			goto end;
		}
	}

	configured_snssai_local_var = configured_snssai_create(
		configured_snssai_local_nonprim,
		mapped_home_snssai ? mapped_home_snssai_local_nonprim : NULL
		);

	return configured_snssai_local_var;
end:
	if(configured_snssai_local_nonprim) {
		snssai_free(configured_snssai_local_nonprim);
		configured_snssai_local_nonprim = NULL;
	}
	if(mapped_home_snssai_local_nonprim) {
		snssai_free(mapped_home_snssai_local_nonprim);
		mapped_home_snssai_local_nonprim = NULL;
	}
	return NULL;
}

configured_snssai_t *configured_snssai_copy(configured_snssai_t *dst,
                                            configured_snssai_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = configured_snssai_convertToJSON(src);
	if(!item) {
		printf("configured_snssai_convertToJSON() failed");
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

	configured_snssai_free(dst);
	dst = configured_snssai_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
