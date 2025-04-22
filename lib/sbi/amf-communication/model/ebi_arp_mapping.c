#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ebi_arp_mapping.h"

ebi_arp_mapping_t *ebi_arp_mapping_create(int eps_bearer_id, arp_t *arp) {
	ebi_arp_mapping_t *ebi_arp_mapping_local_var =
		malloc(sizeof(ebi_arp_mapping_t));

	ebi_arp_mapping_local_var->eps_bearer_id = eps_bearer_id;
	ebi_arp_mapping_local_var->arp = arp;

	return ebi_arp_mapping_local_var;
}

void ebi_arp_mapping_free(ebi_arp_mapping_t *ebi_arp_mapping) {
	lnode_t *node = NULL;

	if(NULL == ebi_arp_mapping) {
		return;
	}
	if(ebi_arp_mapping->arp) {
		arp_free(ebi_arp_mapping->arp);
		ebi_arp_mapping->arp = NULL;
	}
	free(ebi_arp_mapping);
}

cJSON *ebi_arp_mapping_convertToJSON(ebi_arp_mapping_t *ebi_arp_mapping) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ebi_arp_mapping == NULL) {
		printf("ebi_arp_mapping_convertToJSON() failed [EbiArpMapping]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "epsBearerId",
	                           ebi_arp_mapping->eps_bearer_id) == NULL)
	{
		printf("ebi_arp_mapping_convertToJSON() failed [eps_bearer_id]");
		goto end;
	}

	if(!ebi_arp_mapping->arp) {
		printf("ebi_arp_mapping_convertToJSON() failed [arp]");
		return NULL;
	}
	cJSON *arp_local_JSON = arp_convertToJSON(ebi_arp_mapping->arp);
	if(arp_local_JSON == NULL) {
		printf("ebi_arp_mapping_convertToJSON() failed [arp]");
		goto end;
	}
	cJSON_AddItemToObject(item, "arp", arp_local_JSON);
	if(item->child == NULL) {
		printf("ebi_arp_mapping_convertToJSON() failed [arp]");
		goto end;
	}

end:
	return item;
}

ebi_arp_mapping_t *ebi_arp_mapping_parseFromJSON(cJSON *ebi_arp_mappingJSON) {
	ebi_arp_mapping_t *ebi_arp_mapping_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *eps_bearer_id = NULL;
	cJSON *arp = NULL;
	arp_t *arp_local_nonprim = NULL;
	eps_bearer_id = cJSON_GetObjectItemCaseSensitive(ebi_arp_mappingJSON,
	                                                 "epsBearerId");
	if(!eps_bearer_id) {
		printf("ebi_arp_mapping_parseFromJSON() failed [eps_bearer_id]");
		goto end;
	}
	if(!cJSON_IsNumber(eps_bearer_id)) {
		printf("ebi_arp_mapping_parseFromJSON() failed [eps_bearer_id]");
		goto end;
	}

	arp = cJSON_GetObjectItemCaseSensitive(ebi_arp_mappingJSON, "arp");
	if(!arp) {
		printf("ebi_arp_mapping_parseFromJSON() failed [arp]");
		goto end;
	}
	arp_local_nonprim = arp_parseFromJSON(arp);
	if(!arp_local_nonprim) {
		printf("arp_parseFromJSON failed [arp]");
		goto end;
	}

	ebi_arp_mapping_local_var = ebi_arp_mapping_create(

		eps_bearer_id->valuedouble,
		arp_local_nonprim
		);

	return ebi_arp_mapping_local_var;
end:
	if(arp_local_nonprim) {
		arp_free(arp_local_nonprim);
		arp_local_nonprim = NULL;
	}
	return NULL;
}

ebi_arp_mapping_t *ebi_arp_mapping_copy(ebi_arp_mapping_t	*dst,
                                        ebi_arp_mapping_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ebi_arp_mapping_convertToJSON(src);
	if(!item) {
		printf("ebi_arp_mapping_convertToJSON() failed");
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

	ebi_arp_mapping_free(dst);
	dst = ebi_arp_mapping_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
