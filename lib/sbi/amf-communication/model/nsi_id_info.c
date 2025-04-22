#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nsi_id_info.h"

nsi_id_info_t *nsi_id_info_create(snssai_t *snssai, list_t *nsi_ids) {
	nsi_id_info_t *nsi_id_info_local_var = malloc(sizeof(nsi_id_info_t));

	nsi_id_info_local_var->snssai = snssai;
	nsi_id_info_local_var->nsi_ids = nsi_ids;

	return nsi_id_info_local_var;
}

void nsi_id_info_free(nsi_id_info_t *nsi_id_info) {
	lnode_t *node = NULL;

	if(NULL == nsi_id_info) {
		return;
	}
	if(nsi_id_info->snssai) {
		snssai_free(nsi_id_info->snssai);
		nsi_id_info->snssai = NULL;
	}
	if(nsi_id_info->nsi_ids) {
		list_for_each(nsi_id_info->nsi_ids, node) {
			free(node->data);
		}
		list_free(nsi_id_info->nsi_ids);
		nsi_id_info->nsi_ids = NULL;
	}
	free(nsi_id_info);
}

cJSON *nsi_id_info_convertToJSON(nsi_id_info_t *nsi_id_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nsi_id_info == NULL) {
		printf("nsi_id_info_convertToJSON() failed [NsiIdInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!nsi_id_info->snssai) {
		printf("nsi_id_info_convertToJSON() failed [snssai]");
		return NULL;
	}
	cJSON *snssai_local_JSON = snssai_convertToJSON(nsi_id_info->snssai);
	if(snssai_local_JSON == NULL) {
		printf("nsi_id_info_convertToJSON() failed [snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
	if(item->child == NULL) {
		printf("nsi_id_info_convertToJSON() failed [snssai]");
		goto end;
	}

	if(nsi_id_info->nsi_ids) {
		cJSON *nsi_idsList = cJSON_AddArrayToObject(item, "nsiIds");
		if(nsi_idsList == NULL) {
			printf("nsi_id_info_convertToJSON() failed [nsi_ids]");
			goto end;
		}
		list_for_each(nsi_id_info->nsi_ids, node) {
			if(cJSON_AddStringToObject(nsi_idsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"nsi_id_info_convertToJSON() failed [nsi_ids]");
				goto end;
			}
		}
	}

end:
	return item;
}

nsi_id_info_t *nsi_id_info_parseFromJSON(cJSON *nsi_id_infoJSON) {
	nsi_id_info_t *nsi_id_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *nsi_ids = NULL;
	list_t *nsi_idsList = NULL;
	snssai = cJSON_GetObjectItemCaseSensitive(nsi_id_infoJSON, "snssai");
	if(!snssai) {
		printf("nsi_id_info_parseFromJSON() failed [snssai]");
		goto end;
	}
	snssai_local_nonprim = snssai_parseFromJSON(snssai);
	if(!snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [snssai]");
		goto end;
	}

	nsi_ids = cJSON_GetObjectItemCaseSensitive(nsi_id_infoJSON, "nsiIds");
	if(nsi_ids) {
		cJSON *nsi_ids_local = NULL;
		if(!cJSON_IsArray(nsi_ids)) {
			printf("nsi_id_info_parseFromJSON() failed [nsi_ids]");
			goto end;
		}

		nsi_idsList = list_create();

		cJSON_ArrayForEach(nsi_ids_local, nsi_ids) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(nsi_ids_local)) {
				printf(
					"nsi_id_info_parseFromJSON() failed [nsi_ids]");
				goto end;
			}
			list_add(nsi_idsList,
			         strdup(nsi_ids_local->valuestring));
		}
	}

	nsi_id_info_local_var = nsi_id_info_create(
		snssai_local_nonprim,
		nsi_ids ? nsi_idsList : NULL
		);

	return nsi_id_info_local_var;
end:
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(nsi_idsList) {
		list_for_each(nsi_idsList, node) {
			free(node->data);
		}
		list_free(nsi_idsList);
		nsi_idsList = NULL;
	}
	return NULL;
}

nsi_id_info_t *nsi_id_info_copy(nsi_id_info_t *dst, nsi_id_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nsi_id_info_convertToJSON(src);
	if(!item) {
		printf("nsi_id_info_convertToJSON() failed");
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

	nsi_id_info_free(dst);
	dst = nsi_id_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
