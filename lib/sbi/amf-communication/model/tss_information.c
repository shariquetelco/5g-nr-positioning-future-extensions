#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tss_information.h"

tss_information_t *tss_information_create(char *nf_id, list_t *tss_container,
                                          list_t *tss_rsp_per_ngran_list) {
	tss_information_t *tss_information_local_var =
		malloc(sizeof(tss_information_t));

	tss_information_local_var->nf_id = nf_id;
	tss_information_local_var->tss_container = tss_container;
	tss_information_local_var->tss_rsp_per_ngran_list =
		tss_rsp_per_ngran_list;

	return tss_information_local_var;
}

void tss_information_free(tss_information_t *tss_information) {
	lnode_t *node = NULL;

	if(NULL == tss_information) {
		return;
	}
	if(tss_information->nf_id) {
		free(tss_information->nf_id);
		tss_information->nf_id = NULL;
	}
	if(tss_information->tss_container) {
		list_for_each(tss_information->tss_container, node) {
			n2_info_content_free(node->data);
		}
		list_free(tss_information->tss_container);
		tss_information->tss_container = NULL;
	}
	if(tss_information->tss_rsp_per_ngran_list) {
		list_for_each(tss_information->tss_rsp_per_ngran_list, node) {
			tss_rsp_per_ngran_free(node->data);
		}
		list_free(tss_information->tss_rsp_per_ngran_list);
		tss_information->tss_rsp_per_ngran_list = NULL;
	}
	free(tss_information);
}

cJSON *tss_information_convertToJSON(tss_information_t *tss_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(tss_information == NULL) {
		printf("tss_information_convertToJSON() failed [TssInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(tss_information->nf_id) {
		if(cJSON_AddStringToObject(item, "nfId",
		                           tss_information->nf_id) == NULL)
		{
			printf("tss_information_convertToJSON() failed [nf_id]");
			goto end;
		}
	}

	if(!tss_information->tss_container) {
		printf("tss_information_convertToJSON() failed [tss_container]");
		return NULL;
	}
	cJSON *tss_containerList = cJSON_AddArrayToObject(item, "tssContainer");
	if(tss_containerList == NULL) {
		printf("tss_information_convertToJSON() failed [tss_container]");
		goto end;
	}
	list_for_each(tss_information->tss_container, node) {
		cJSON *itemLocal = n2_info_content_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"tss_information_convertToJSON() failed [tss_container]");
			goto end;
		}
		cJSON_AddItemToArray(tss_containerList, itemLocal);
	}

	if(tss_information->tss_rsp_per_ngran_list) {
		cJSON *tss_rsp_per_ngran_listList = cJSON_AddArrayToObject(item,
		                                                           "tssRspPerNgranList");
		if(tss_rsp_per_ngran_listList == NULL) {
			printf(
				"tss_information_convertToJSON() failed [tss_rsp_per_ngran_list]");
			goto end;
		}
		list_for_each(tss_information->tss_rsp_per_ngran_list, node) {
			cJSON *itemLocal = tss_rsp_per_ngran_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"tss_information_convertToJSON() failed [tss_rsp_per_ngran_list]");
				goto end;
			}
			cJSON_AddItemToArray(tss_rsp_per_ngran_listList,
			                     itemLocal);
		}
	}

end:
	return item;
}

tss_information_t *tss_information_parseFromJSON(cJSON *tss_informationJSON) {
	tss_information_t *tss_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *nf_id = NULL;
	cJSON *tss_container = NULL;
	list_t *tss_containerList = NULL;
	cJSON *tss_rsp_per_ngran_list = NULL;
	list_t *tss_rsp_per_ngran_listList = NULL;
	nf_id = cJSON_GetObjectItemCaseSensitive(tss_informationJSON, "nfId");
	if(nf_id) {
		if(!cJSON_IsString(nf_id) &&
		   !cJSON_IsNull(nf_id))
		{
			printf("tss_information_parseFromJSON() failed [nf_id]");
			goto end;
		}
	}

	tss_container = cJSON_GetObjectItemCaseSensitive(tss_informationJSON,
	                                                 "tssContainer");
	if(!tss_container) {
		printf("tss_information_parseFromJSON() failed [tss_container]");
		goto end;
	}
	cJSON *tss_container_local = NULL;
	if(!cJSON_IsArray(tss_container)) {
		printf("tss_information_parseFromJSON() failed [tss_container]");
		goto end;
	}

	tss_containerList = list_create();

	cJSON_ArrayForEach(tss_container_local, tss_container) {
		if(!cJSON_IsObject(tss_container_local)) {
			printf(
				"tss_information_parseFromJSON() failed [tss_container]");
			goto end;
		}
		n2_info_content_t *tss_containerItem =
			n2_info_content_parseFromJSON(tss_container_local);
		if(!tss_containerItem) {
			printf("No tss_containerItem");
			goto end;
		}
		list_add(tss_containerList, tss_containerItem);
	}

	tss_rsp_per_ngran_list = cJSON_GetObjectItemCaseSensitive(
		tss_informationJSON, "tssRspPerNgranList");
	if(tss_rsp_per_ngran_list) {
		cJSON *tss_rsp_per_ngran_list_local = NULL;
		if(!cJSON_IsArray(tss_rsp_per_ngran_list)) {
			printf(
				"tss_information_parseFromJSON() failed [tss_rsp_per_ngran_list]");
			goto end;
		}

		tss_rsp_per_ngran_listList = list_create();

		cJSON_ArrayForEach(tss_rsp_per_ngran_list_local,
		                   tss_rsp_per_ngran_list) {
			if(!cJSON_IsObject(tss_rsp_per_ngran_list_local)) {
				printf(
					"tss_information_parseFromJSON() failed [tss_rsp_per_ngran_list]");
				goto end;
			}
			tss_rsp_per_ngran_t *tss_rsp_per_ngran_listItem =
				tss_rsp_per_ngran_parseFromJSON(
					tss_rsp_per_ngran_list_local);
			if(!tss_rsp_per_ngran_listItem) {
				printf("No tss_rsp_per_ngran_listItem");
				goto end;
			}
			list_add(tss_rsp_per_ngran_listList,
			         tss_rsp_per_ngran_listItem);
		}
	}

	tss_information_local_var = tss_information_create(
		nf_id &&
		!cJSON_IsNull(nf_id) ? strdup(nf_id->valuestring) : NULL,
		tss_containerList,
		tss_rsp_per_ngran_list ? tss_rsp_per_ngran_listList : NULL
		);

	return tss_information_local_var;
end:
	if(tss_containerList) {
		list_for_each(tss_containerList, node) {
			n2_info_content_free(node->data);
		}
		list_free(tss_containerList);
		tss_containerList = NULL;
	}
	if(tss_rsp_per_ngran_listList) {
		list_for_each(tss_rsp_per_ngran_listList, node) {
			tss_rsp_per_ngran_free(node->data);
		}
		list_free(tss_rsp_per_ngran_listList);
		tss_rsp_per_ngran_listList = NULL;
	}
	return NULL;
}

tss_information_t *tss_information_copy(tss_information_t	*dst,
                                        tss_information_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = tss_information_convertToJSON(src);
	if(!item) {
		printf("tss_information_convertToJSON() failed");
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

	tss_information_free(dst);
	dst = tss_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
