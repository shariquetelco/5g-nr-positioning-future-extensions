#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nssai_mapping.h"

nssai_mapping_t *nssai_mapping_create(snssai_t	*mapped_snssai,
                                      snssai_t	*h_snssai) {
	nssai_mapping_t *nssai_mapping_local_var = malloc(
		sizeof(nssai_mapping_t));

	nssai_mapping_local_var->mapped_snssai = mapped_snssai;
	nssai_mapping_local_var->h_snssai = h_snssai;

	return nssai_mapping_local_var;
}

void nssai_mapping_free(nssai_mapping_t *nssai_mapping) {
	lnode_t *node = NULL;

	if(NULL == nssai_mapping) {
		return;
	}
	if(nssai_mapping->mapped_snssai) {
		snssai_free(nssai_mapping->mapped_snssai);
		nssai_mapping->mapped_snssai = NULL;
	}
	if(nssai_mapping->h_snssai) {
		snssai_free(nssai_mapping->h_snssai);
		nssai_mapping->h_snssai = NULL;
	}
	free(nssai_mapping);
}

cJSON *nssai_mapping_convertToJSON(nssai_mapping_t *nssai_mapping) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nssai_mapping == NULL) {
		printf("nssai_mapping_convertToJSON() failed [NssaiMapping]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!nssai_mapping->mapped_snssai) {
		printf("nssai_mapping_convertToJSON() failed [mapped_snssai]");
		return NULL;
	}
	cJSON *mapped_snssai_local_JSON = snssai_convertToJSON(
		nssai_mapping->mapped_snssai);
	if(mapped_snssai_local_JSON == NULL) {
		printf("nssai_mapping_convertToJSON() failed [mapped_snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "mappedSnssai", mapped_snssai_local_JSON);
	if(item->child == NULL) {
		printf("nssai_mapping_convertToJSON() failed [mapped_snssai]");
		goto end;
	}

	if(!nssai_mapping->h_snssai) {
		printf("nssai_mapping_convertToJSON() failed [h_snssai]");
		return NULL;
	}
	cJSON *h_snssai_local_JSON = snssai_convertToJSON(
		nssai_mapping->h_snssai);
	if(h_snssai_local_JSON == NULL) {
		printf("nssai_mapping_convertToJSON() failed [h_snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "hSnssai", h_snssai_local_JSON);
	if(item->child == NULL) {
		printf("nssai_mapping_convertToJSON() failed [h_snssai]");
		goto end;
	}

end:
	return item;
}

nssai_mapping_t *nssai_mapping_parseFromJSON(cJSON *nssai_mappingJSON) {
	nssai_mapping_t *nssai_mapping_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *mapped_snssai = NULL;
	snssai_t *mapped_snssai_local_nonprim = NULL;
	cJSON *h_snssai = NULL;
	snssai_t *h_snssai_local_nonprim = NULL;
	mapped_snssai = cJSON_GetObjectItemCaseSensitive(nssai_mappingJSON,
	                                                 "mappedSnssai");
	if(!mapped_snssai) {
		printf("nssai_mapping_parseFromJSON() failed [mapped_snssai]");
		goto end;
	}
	mapped_snssai_local_nonprim = snssai_parseFromJSON(mapped_snssai);
	if(!mapped_snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [mapped_snssai]");
		goto end;
	}

	h_snssai =
		cJSON_GetObjectItemCaseSensitive(nssai_mappingJSON, "hSnssai");
	if(!h_snssai) {
		printf("nssai_mapping_parseFromJSON() failed [h_snssai]");
		goto end;
	}
	h_snssai_local_nonprim = snssai_parseFromJSON(h_snssai);
	if(!h_snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [h_snssai]");
		goto end;
	}

	nssai_mapping_local_var = nssai_mapping_create(
		mapped_snssai_local_nonprim,
		h_snssai_local_nonprim
		);

	return nssai_mapping_local_var;
end:
	if(mapped_snssai_local_nonprim) {
		snssai_free(mapped_snssai_local_nonprim);
		mapped_snssai_local_nonprim = NULL;
	}
	if(h_snssai_local_nonprim) {
		snssai_free(h_snssai_local_nonprim);
		h_snssai_local_nonprim = NULL;
	}
	return NULL;
}

nssai_mapping_t *nssai_mapping_copy(nssai_mapping_t	*dst,
                                    nssai_mapping_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nssai_mapping_convertToJSON(src);
	if(!item) {
		printf("nssai_mapping_convertToJSON() failed");
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

	nssai_mapping_free(dst);
	dst = nssai_mapping_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
