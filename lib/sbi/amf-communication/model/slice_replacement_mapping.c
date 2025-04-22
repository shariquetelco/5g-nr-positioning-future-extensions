#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "slice_replacement_mapping.h"

slice_replacement_mapping_t *slice_replacement_mapping_create(
	snssai_t *replaced_snssai, snssai_t *alt_snssai) {
	slice_replacement_mapping_t *slice_replacement_mapping_local_var =
		malloc(sizeof(slice_replacement_mapping_t));

	slice_replacement_mapping_local_var->replaced_snssai = replaced_snssai;
	slice_replacement_mapping_local_var->alt_snssai = alt_snssai;

	return slice_replacement_mapping_local_var;
}

void slice_replacement_mapping_free(
	slice_replacement_mapping_t *slice_replacement_mapping) {
	lnode_t *node = NULL;

	if(NULL == slice_replacement_mapping) {
		return;
	}
	if(slice_replacement_mapping->replaced_snssai) {
		snssai_free(slice_replacement_mapping->replaced_snssai);
		slice_replacement_mapping->replaced_snssai = NULL;
	}
	if(slice_replacement_mapping->alt_snssai) {
		snssai_free(slice_replacement_mapping->alt_snssai);
		slice_replacement_mapping->alt_snssai = NULL;
	}
	free(slice_replacement_mapping);
}

cJSON *slice_replacement_mapping_convertToJSON(
	slice_replacement_mapping_t *slice_replacement_mapping) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(slice_replacement_mapping == NULL) {
		printf(
			"slice_replacement_mapping_convertToJSON() failed [SliceReplacementMapping]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!slice_replacement_mapping->replaced_snssai) {
		printf(
			"slice_replacement_mapping_convertToJSON() failed [replaced_snssai]");
		return NULL;
	}
	cJSON *replaced_snssai_local_JSON = snssai_convertToJSON(
		slice_replacement_mapping->replaced_snssai);
	if(replaced_snssai_local_JSON == NULL) {
		printf(
			"slice_replacement_mapping_convertToJSON() failed [replaced_snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "replacedSnssai",
	                      replaced_snssai_local_JSON);
	if(item->child == NULL) {
		printf(
			"slice_replacement_mapping_convertToJSON() failed [replaced_snssai]");
		goto end;
	}

	if(!slice_replacement_mapping->alt_snssai) {
		printf(
			"slice_replacement_mapping_convertToJSON() failed [alt_snssai]");
		return NULL;
	}
	cJSON *alt_snssai_local_JSON = snssai_convertToJSON(
		slice_replacement_mapping->alt_snssai);
	if(alt_snssai_local_JSON == NULL) {
		printf(
			"slice_replacement_mapping_convertToJSON() failed [alt_snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "altSnssai", alt_snssai_local_JSON);
	if(item->child == NULL) {
		printf(
			"slice_replacement_mapping_convertToJSON() failed [alt_snssai]");
		goto end;
	}

end:
	return item;
}

slice_replacement_mapping_t *slice_replacement_mapping_parseFromJSON(
	cJSON *slice_replacement_mappingJSON) {
	slice_replacement_mapping_t *slice_replacement_mapping_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *replaced_snssai = NULL;
	snssai_t *replaced_snssai_local_nonprim = NULL;
	cJSON *alt_snssai = NULL;
	snssai_t *alt_snssai_local_nonprim = NULL;
	replaced_snssai = cJSON_GetObjectItemCaseSensitive(
		slice_replacement_mappingJSON, "replacedSnssai");
	if(!replaced_snssai) {
		printf(
			"slice_replacement_mapping_parseFromJSON() failed [replaced_snssai]");
		goto end;
	}
	replaced_snssai_local_nonprim = snssai_parseFromJSON(replaced_snssai);
	if(!replaced_snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [replaced_snssai]");
		goto end;
	}

	alt_snssai = cJSON_GetObjectItemCaseSensitive(
		slice_replacement_mappingJSON, "altSnssai");
	if(!alt_snssai) {
		printf(
			"slice_replacement_mapping_parseFromJSON() failed [alt_snssai]");
		goto end;
	}
	alt_snssai_local_nonprim = snssai_parseFromJSON(alt_snssai);
	if(!alt_snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [alt_snssai]");
		goto end;
	}

	slice_replacement_mapping_local_var = slice_replacement_mapping_create(
		replaced_snssai_local_nonprim,
		alt_snssai_local_nonprim
		);

	return slice_replacement_mapping_local_var;
end:
	if(replaced_snssai_local_nonprim) {
		snssai_free(replaced_snssai_local_nonprim);
		replaced_snssai_local_nonprim = NULL;
	}
	if(alt_snssai_local_nonprim) {
		snssai_free(alt_snssai_local_nonprim);
		alt_snssai_local_nonprim = NULL;
	}
	return NULL;
}

slice_replacement_mapping_t *slice_replacement_mapping_copy(
	slice_replacement_mapping_t *dst, slice_replacement_mapping_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = slice_replacement_mapping_convertToJSON(src);
	if(!item) {
		printf("slice_replacement_mapping_convertToJSON() failed");
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

	slice_replacement_mapping_free(dst);
	dst = slice_replacement_mapping_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
