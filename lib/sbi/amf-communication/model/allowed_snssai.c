#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "allowed_snssai.h"

allowed_snssai_t *allowed_snssai_create(snssai_t	*allowed_snssai,
                                        list_t		*nsi_information_list,
                                        snssai_t	*mapped_home_snssai) {
	allowed_snssai_t *allowed_snssai_local_var =
		malloc(sizeof(allowed_snssai_t));

	allowed_snssai_local_var->allowed_snssai = allowed_snssai;
	allowed_snssai_local_var->nsi_information_list = nsi_information_list;
	allowed_snssai_local_var->mapped_home_snssai = mapped_home_snssai;

	return allowed_snssai_local_var;
}

void allowed_snssai_free(allowed_snssai_t *allowed_snssai) {
	lnode_t *node = NULL;

	if(NULL == allowed_snssai) {
		return;
	}
	if(allowed_snssai->allowed_snssai) {
		snssai_free(allowed_snssai->allowed_snssai);
		allowed_snssai->allowed_snssai = NULL;
	}
	if(allowed_snssai->nsi_information_list) {
		list_for_each(allowed_snssai->nsi_information_list, node) {
			nsi_information_free(node->data);
		}
		list_free(allowed_snssai->nsi_information_list);
		allowed_snssai->nsi_information_list = NULL;
	}
	if(allowed_snssai->mapped_home_snssai) {
		snssai_free(allowed_snssai->mapped_home_snssai);
		allowed_snssai->mapped_home_snssai = NULL;
	}
	free(allowed_snssai);
}

cJSON *allowed_snssai_convertToJSON(allowed_snssai_t *allowed_snssai) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(allowed_snssai == NULL) {
		printf("allowed_snssai_convertToJSON() failed [AllowedSnssai]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!allowed_snssai->allowed_snssai) {
		printf("allowed_snssai_convertToJSON() failed [allowed_snssai]");
		return NULL;
	}
	cJSON *allowed_snssai_local_JSON = snssai_convertToJSON(
		allowed_snssai->allowed_snssai);
	if(allowed_snssai_local_JSON == NULL) {
		printf("allowed_snssai_convertToJSON() failed [allowed_snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "allowedSnssai", allowed_snssai_local_JSON);
	if(item->child == NULL) {
		printf("allowed_snssai_convertToJSON() failed [allowed_snssai]");
		goto end;
	}

	if(allowed_snssai->nsi_information_list) {
		cJSON *nsi_information_listList = cJSON_AddArrayToObject(item,
		                                                         "nsiInformationList");
		if(nsi_information_listList == NULL) {
			printf(
				"allowed_snssai_convertToJSON() failed [nsi_information_list]");
			goto end;
		}
		list_for_each(allowed_snssai->nsi_information_list, node) {
			cJSON *itemLocal = nsi_information_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"allowed_snssai_convertToJSON() failed [nsi_information_list]");
				goto end;
			}
			cJSON_AddItemToArray(nsi_information_listList,
			                     itemLocal);
		}
	}

	if(allowed_snssai->mapped_home_snssai) {
		cJSON *mapped_home_snssai_local_JSON = snssai_convertToJSON(
			allowed_snssai->mapped_home_snssai);
		if(mapped_home_snssai_local_JSON == NULL) {
			printf(
				"allowed_snssai_convertToJSON() failed [mapped_home_snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "mappedHomeSnssai",
		                      mapped_home_snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"allowed_snssai_convertToJSON() failed [mapped_home_snssai]");
			goto end;
		}
	}

end:
	return item;
}

allowed_snssai_t *allowed_snssai_parseFromJSON(cJSON *allowed_snssaiJSON) {
	allowed_snssai_t *allowed_snssai_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *allowed_snssai = NULL;
	snssai_t *allowed_snssai_local_nonprim = NULL;
	cJSON *nsi_information_list = NULL;
	list_t *nsi_information_listList = NULL;
	cJSON *mapped_home_snssai = NULL;
	snssai_t *mapped_home_snssai_local_nonprim = NULL;
	allowed_snssai = cJSON_GetObjectItemCaseSensitive(allowed_snssaiJSON,
	                                                  "allowedSnssai");
	if(!allowed_snssai) {
		printf("allowed_snssai_parseFromJSON() failed [allowed_snssai]");
		goto end;
	}
	allowed_snssai_local_nonprim = snssai_parseFromJSON(allowed_snssai);
	if(!allowed_snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [allowed_snssai]");
		goto end;
	}

	nsi_information_list = cJSON_GetObjectItemCaseSensitive(
		allowed_snssaiJSON, "nsiInformationList");
	if(nsi_information_list) {
		cJSON *nsi_information_list_local = NULL;
		if(!cJSON_IsArray(nsi_information_list)) {
			printf(
				"allowed_snssai_parseFromJSON() failed [nsi_information_list]");
			goto end;
		}

		nsi_information_listList = list_create();

		cJSON_ArrayForEach(nsi_information_list_local,
		                   nsi_information_list) {
			if(!cJSON_IsObject(nsi_information_list_local)) {
				printf(
					"allowed_snssai_parseFromJSON() failed [nsi_information_list]");
				goto end;
			}
			nsi_information_t *nsi_information_listItem =
				nsi_information_parseFromJSON(
					nsi_information_list_local);
			if(!nsi_information_listItem) {
				printf("No nsi_information_listItem");
				goto end;
			}
			list_add(nsi_information_listList,
			         nsi_information_listItem);
		}
	}

	mapped_home_snssai = cJSON_GetObjectItemCaseSensitive(
		allowed_snssaiJSON, "mappedHomeSnssai");
	if(mapped_home_snssai) {
		mapped_home_snssai_local_nonprim = snssai_parseFromJSON(
			mapped_home_snssai);
		if(!mapped_home_snssai_local_nonprim) {
			printf(
				"snssai_parseFromJSON failed [mapped_home_snssai]");
			goto end;
		}
	}

	allowed_snssai_local_var = allowed_snssai_create(
		allowed_snssai_local_nonprim,
		nsi_information_list ? nsi_information_listList : NULL,
		mapped_home_snssai ? mapped_home_snssai_local_nonprim : NULL
		);

	return allowed_snssai_local_var;
end:
	if(allowed_snssai_local_nonprim) {
		snssai_free(allowed_snssai_local_nonprim);
		allowed_snssai_local_nonprim = NULL;
	}
	if(nsi_information_listList) {
		list_for_each(nsi_information_listList, node) {
			nsi_information_free(node->data);
		}
		list_free(nsi_information_listList);
		nsi_information_listList = NULL;
	}
	if(mapped_home_snssai_local_nonprim) {
		snssai_free(mapped_home_snssai_local_nonprim);
		mapped_home_snssai_local_nonprim = NULL;
	}
	return NULL;
}

allowed_snssai_t *allowed_snssai_copy(allowed_snssai_t	*dst,
                                      allowed_snssai_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = allowed_snssai_convertToJSON(src);
	if(!item) {
		printf("allowed_snssai_convertToJSON() failed");
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

	allowed_snssai_free(dst);
	dst = allowed_snssai_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
