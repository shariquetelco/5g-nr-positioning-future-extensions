#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pdu_ses_traffic_info.h"

pdu_ses_traffic_info_t *pdu_ses_traffic_info_create(list_t *supis, char *dnn,
                                                    snssai_t *snssai,
                                                    list_t *td_match_trafs,
                                                    list_t *td_unmatch_trafs) {
	pdu_ses_traffic_info_t *pdu_ses_traffic_info_local_var =
		malloc(sizeof(pdu_ses_traffic_info_t));

	pdu_ses_traffic_info_local_var->supis = supis;
	pdu_ses_traffic_info_local_var->dnn = dnn;
	pdu_ses_traffic_info_local_var->snssai = snssai;
	pdu_ses_traffic_info_local_var->td_match_trafs = td_match_trafs;
	pdu_ses_traffic_info_local_var->td_unmatch_trafs = td_unmatch_trafs;

	return pdu_ses_traffic_info_local_var;
}

void pdu_ses_traffic_info_free(pdu_ses_traffic_info_t *pdu_ses_traffic_info) {
	lnode_t *node = NULL;

	if(NULL == pdu_ses_traffic_info) {
		return;
	}
	if(pdu_ses_traffic_info->supis) {
		list_for_each(pdu_ses_traffic_info->supis, node) {
			free(node->data);
		}
		list_free(pdu_ses_traffic_info->supis);
		pdu_ses_traffic_info->supis = NULL;
	}
	if(pdu_ses_traffic_info->dnn) {
		free(pdu_ses_traffic_info->dnn);
		pdu_ses_traffic_info->dnn = NULL;
	}
	if(pdu_ses_traffic_info->snssai) {
		snssai_free(pdu_ses_traffic_info->snssai);
		pdu_ses_traffic_info->snssai = NULL;
	}
	if(pdu_ses_traffic_info->td_match_trafs) {
		list_for_each(pdu_ses_traffic_info->td_match_trafs, node) {
			td_traffic_free(node->data);
		}
		list_free(pdu_ses_traffic_info->td_match_trafs);
		pdu_ses_traffic_info->td_match_trafs = NULL;
	}
	if(pdu_ses_traffic_info->td_unmatch_trafs) {
		list_for_each(pdu_ses_traffic_info->td_unmatch_trafs, node) {
			td_traffic_free(node->data);
		}
		list_free(pdu_ses_traffic_info->td_unmatch_trafs);
		pdu_ses_traffic_info->td_unmatch_trafs = NULL;
	}
	free(pdu_ses_traffic_info);
}

cJSON *pdu_ses_traffic_info_convertToJSON(
	pdu_ses_traffic_info_t *pdu_ses_traffic_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pdu_ses_traffic_info == NULL) {
		printf(
			"pdu_ses_traffic_info_convertToJSON() failed [PduSesTrafficInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(pdu_ses_traffic_info->supis) {
		cJSON *supisList = cJSON_AddArrayToObject(item, "supis");
		if(supisList == NULL) {
			printf(
				"pdu_ses_traffic_info_convertToJSON() failed [supis]");
			goto end;
		}
		list_for_each(pdu_ses_traffic_info->supis, node) {
			if(cJSON_AddStringToObject(supisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"pdu_ses_traffic_info_convertToJSON() failed [supis]");
				goto end;
			}
		}
	}

	if(pdu_ses_traffic_info->dnn) {
		if(cJSON_AddStringToObject(item, "dnn",
		                           pdu_ses_traffic_info->dnn) == NULL)
		{
			printf(
				"pdu_ses_traffic_info_convertToJSON() failed [dnn]");
			goto end;
		}
	}

	if(pdu_ses_traffic_info->snssai) {
		cJSON *snssai_local_JSON = snssai_convertToJSON(
			pdu_ses_traffic_info->snssai);
		if(snssai_local_JSON == NULL) {
			printf(
				"pdu_ses_traffic_info_convertToJSON() failed [snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"pdu_ses_traffic_info_convertToJSON() failed [snssai]");
			goto end;
		}
	}

	if(pdu_ses_traffic_info->td_match_trafs) {
		cJSON *td_match_trafsList = cJSON_AddArrayToObject(item,
		                                                   "tdMatchTrafs");
		if(td_match_trafsList == NULL) {
			printf(
				"pdu_ses_traffic_info_convertToJSON() failed [td_match_trafs]");
			goto end;
		}
		list_for_each(pdu_ses_traffic_info->td_match_trafs, node) {
			cJSON *itemLocal = td_traffic_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"pdu_ses_traffic_info_convertToJSON() failed [td_match_trafs]");
				goto end;
			}
			cJSON_AddItemToArray(td_match_trafsList, itemLocal);
		}
	}

	if(pdu_ses_traffic_info->td_unmatch_trafs) {
		cJSON *td_unmatch_trafsList = cJSON_AddArrayToObject(item,
		                                                     "tdUnmatchTrafs");
		if(td_unmatch_trafsList == NULL) {
			printf(
				"pdu_ses_traffic_info_convertToJSON() failed [td_unmatch_trafs]");
			goto end;
		}
		list_for_each(pdu_ses_traffic_info->td_unmatch_trafs, node) {
			cJSON *itemLocal = td_traffic_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"pdu_ses_traffic_info_convertToJSON() failed [td_unmatch_trafs]");
				goto end;
			}
			cJSON_AddItemToArray(td_unmatch_trafsList, itemLocal);
		}
	}

end:
	return item;
}

pdu_ses_traffic_info_t *pdu_ses_traffic_info_parseFromJSON(
	cJSON *pdu_ses_traffic_infoJSON) {
	pdu_ses_traffic_info_t *pdu_ses_traffic_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *supis = NULL;
	list_t *supisList = NULL;
	cJSON *dnn = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *td_match_trafs = NULL;
	list_t *td_match_trafsList = NULL;
	cJSON *td_unmatch_trafs = NULL;
	list_t *td_unmatch_trafsList = NULL;
	supis = cJSON_GetObjectItemCaseSensitive(pdu_ses_traffic_infoJSON,
	                                         "supis");
	if(supis) {
		cJSON *supis_local = NULL;
		if(!cJSON_IsArray(supis)) {
			printf(
				"pdu_ses_traffic_info_parseFromJSON() failed [supis]");
			goto end;
		}

		supisList = list_create();

		cJSON_ArrayForEach(supis_local, supis) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(supis_local)) {
				printf(
					"pdu_ses_traffic_info_parseFromJSON() failed [supis]");
				goto end;
			}
			list_add(supisList, strdup(supis_local->valuestring));
		}
	}

	dnn = cJSON_GetObjectItemCaseSensitive(pdu_ses_traffic_infoJSON, "dnn");
	if(dnn) {
		if(!cJSON_IsString(dnn) &&
		   !cJSON_IsNull(dnn))
		{
			printf(
				"pdu_ses_traffic_info_parseFromJSON() failed [dnn]");
			goto end;
		}
	}

	snssai = cJSON_GetObjectItemCaseSensitive(pdu_ses_traffic_infoJSON,
	                                          "snssai");
	if(snssai) {
		snssai_local_nonprim = snssai_parseFromJSON(snssai);
		if(!snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [snssai]");
			goto end;
		}
	}

	td_match_trafs = cJSON_GetObjectItemCaseSensitive(
		pdu_ses_traffic_infoJSON, "tdMatchTrafs");
	if(td_match_trafs) {
		cJSON *td_match_trafs_local = NULL;
		if(!cJSON_IsArray(td_match_trafs)) {
			printf(
				"pdu_ses_traffic_info_parseFromJSON() failed [td_match_trafs]");
			goto end;
		}

		td_match_trafsList = list_create();

		cJSON_ArrayForEach(td_match_trafs_local, td_match_trafs) {
			if(!cJSON_IsObject(td_match_trafs_local)) {
				printf(
					"pdu_ses_traffic_info_parseFromJSON() failed [td_match_trafs]");
				goto end;
			}
			td_traffic_t *td_match_trafsItem =
				td_traffic_parseFromJSON(td_match_trafs_local);
			if(!td_match_trafsItem) {
				printf("No td_match_trafsItem");
				goto end;
			}
			list_add(td_match_trafsList, td_match_trafsItem);
		}
	}

	td_unmatch_trafs = cJSON_GetObjectItemCaseSensitive(
		pdu_ses_traffic_infoJSON, "tdUnmatchTrafs");
	if(td_unmatch_trafs) {
		cJSON *td_unmatch_trafs_local = NULL;
		if(!cJSON_IsArray(td_unmatch_trafs)) {
			printf(
				"pdu_ses_traffic_info_parseFromJSON() failed [td_unmatch_trafs]");
			goto end;
		}

		td_unmatch_trafsList = list_create();

		cJSON_ArrayForEach(td_unmatch_trafs_local, td_unmatch_trafs) {
			if(!cJSON_IsObject(td_unmatch_trafs_local)) {
				printf(
					"pdu_ses_traffic_info_parseFromJSON() failed [td_unmatch_trafs]");
				goto end;
			}
			td_traffic_t *td_unmatch_trafsItem =
				td_traffic_parseFromJSON(td_unmatch_trafs_local);
			if(!td_unmatch_trafsItem) {
				printf("No td_unmatch_trafsItem");
				goto end;
			}
			list_add(td_unmatch_trafsList, td_unmatch_trafsItem);
		}
	}

	pdu_ses_traffic_info_local_var = pdu_ses_traffic_info_create(
		supis ? supisList : NULL,
		dnn &&
		!cJSON_IsNull(dnn) ? strdup(dnn->valuestring) : NULL,
		snssai ? snssai_local_nonprim : NULL,
		td_match_trafs ? td_match_trafsList : NULL,
		td_unmatch_trafs ? td_unmatch_trafsList : NULL
		);

	return pdu_ses_traffic_info_local_var;
end:
	if(supisList) {
		list_for_each(supisList, node) {
			free(node->data);
		}
		list_free(supisList);
		supisList = NULL;
	}
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(td_match_trafsList) {
		list_for_each(td_match_trafsList, node) {
			td_traffic_free(node->data);
		}
		list_free(td_match_trafsList);
		td_match_trafsList = NULL;
	}
	if(td_unmatch_trafsList) {
		list_for_each(td_unmatch_trafsList, node) {
			td_traffic_free(node->data);
		}
		list_free(td_unmatch_trafsList);
		td_unmatch_trafsList = NULL;
	}
	return NULL;
}

pdu_ses_traffic_info_t *pdu_ses_traffic_info_copy(
	pdu_ses_traffic_info_t	*dst,
	pdu_ses_traffic_info_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = pdu_ses_traffic_info_convertToJSON(src);
	if(!item) {
		printf("pdu_ses_traffic_info_convertToJSON() failed");
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

	pdu_ses_traffic_info_free(dst);
	dst = pdu_ses_traffic_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
