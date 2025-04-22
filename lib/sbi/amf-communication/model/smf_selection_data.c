#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "smf_selection_data.h"

smf_selection_data_t *smf_selection_data_create(bool		is_unsupp_dnn,
                                                int		unsupp_dnn,
                                                bool		is_candidates_null,
                                                list_t		*candidates,
                                                snssai_t	*snssai,
                                                snssai_t	*mapping_snssai,
                                                char		*dnn) {
	smf_selection_data_t *smf_selection_data_local_var =
		malloc(sizeof(smf_selection_data_t));

	smf_selection_data_local_var->is_unsupp_dnn = is_unsupp_dnn;
	smf_selection_data_local_var->unsupp_dnn = unsupp_dnn;
	smf_selection_data_local_var->is_candidates_null = is_candidates_null;
	smf_selection_data_local_var->candidates = candidates;
	smf_selection_data_local_var->snssai = snssai;
	smf_selection_data_local_var->mapping_snssai = mapping_snssai;
	smf_selection_data_local_var->dnn = dnn;

	return smf_selection_data_local_var;
}

void smf_selection_data_free(smf_selection_data_t *smf_selection_data) {
	lnode_t *node = NULL;

	if(NULL == smf_selection_data) {
		return;
	}
	if(smf_selection_data->candidates) {
		list_for_each(smf_selection_data->candidates, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			candidate_for_replacement_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(smf_selection_data->candidates);
		smf_selection_data->candidates = NULL;
	}
	if(smf_selection_data->snssai) {
		snssai_free(smf_selection_data->snssai);
		smf_selection_data->snssai = NULL;
	}
	if(smf_selection_data->mapping_snssai) {
		snssai_free(smf_selection_data->mapping_snssai);
		smf_selection_data->mapping_snssai = NULL;
	}
	if(smf_selection_data->dnn) {
		free(smf_selection_data->dnn);
		smf_selection_data->dnn = NULL;
	}
	free(smf_selection_data);
}

cJSON *smf_selection_data_convertToJSON(
	smf_selection_data_t *smf_selection_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(smf_selection_data == NULL) {
		printf(
			"smf_selection_data_convertToJSON() failed [SmfSelectionData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(smf_selection_data->is_unsupp_dnn) {
		if(cJSON_AddBoolToObject(item, "unsuppDnn",
		                         smf_selection_data->unsupp_dnn) ==
		   NULL)
		{
			printf(
				"smf_selection_data_convertToJSON() failed [unsupp_dnn]");
			goto end;
		}
	}

	if(smf_selection_data->candidates) {
		cJSON *candidates = cJSON_AddObjectToObject(item, "candidates");
		if(candidates == NULL) {
			printf(
				"smf_selection_data_convertToJSON() failed [candidates]");
			goto end;
		}
		cJSON *localMapObject = candidates;
		if(smf_selection_data->candidates) {
			list_for_each(smf_selection_data->candidates, node) {
				map_t *localKeyValue = (map_t *) node->data;
				if(localKeyValue == NULL) {
					printf(
						"smf_selection_data_convertToJSON() failed [candidates]");
					goto end;
				}
				if(localKeyValue->key == NULL) {
					printf(
						"smf_selection_data_convertToJSON() failed [candidates]");
					goto end;
				}
				cJSON *itemLocal = localKeyValue->value ?
				                   candidate_for_replacement_convertToJSON(
					localKeyValue->value) :
				                   cJSON_CreateNull();
				if(itemLocal == NULL) {
					printf(
						"smf_selection_data_convertToJSON() failed [inner]");
					goto end;
				}
				cJSON_AddItemToObject(localMapObject,
				                      localKeyValue->key,
				                      itemLocal);
			}
		}
	} else if(smf_selection_data->is_candidates_null) {
		if(cJSON_AddNullToObject(item, "candidates") == NULL) {
			printf(
				"smf_selection_data_convertToJSON() failed [candidates]");
			goto end;
		}
	}

	if(smf_selection_data->snssai) {
		cJSON *snssai_local_JSON = snssai_convertToJSON(
			smf_selection_data->snssai);
		if(snssai_local_JSON == NULL) {
			printf(
				"smf_selection_data_convertToJSON() failed [snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"smf_selection_data_convertToJSON() failed [snssai]");
			goto end;
		}
	}

	if(smf_selection_data->mapping_snssai) {
		cJSON *mapping_snssai_local_JSON = snssai_convertToJSON(
			smf_selection_data->mapping_snssai);
		if(mapping_snssai_local_JSON == NULL) {
			printf(
				"smf_selection_data_convertToJSON() failed [mapping_snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "mappingSnssai",
		                      mapping_snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"smf_selection_data_convertToJSON() failed [mapping_snssai]");
			goto end;
		}
	}

	if(smf_selection_data->dnn) {
		if(cJSON_AddStringToObject(item, "dnn",
		                           smf_selection_data->dnn) == NULL)
		{
			printf("smf_selection_data_convertToJSON() failed [dnn]");
			goto end;
		}
	}

end:
	return item;
}

smf_selection_data_t *smf_selection_data_parseFromJSON(
	cJSON *smf_selection_dataJSON) {
	smf_selection_data_t *smf_selection_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *unsupp_dnn = NULL;
	cJSON *candidates = NULL;
	list_t *candidatesList = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *mapping_snssai = NULL;
	snssai_t *mapping_snssai_local_nonprim = NULL;
	cJSON *dnn = NULL;
	unsupp_dnn = cJSON_GetObjectItemCaseSensitive(smf_selection_dataJSON,
	                                              "unsuppDnn");
	if(unsupp_dnn) {
		if(!cJSON_IsBool(unsupp_dnn)) {
			printf(
				"smf_selection_data_parseFromJSON() failed [unsupp_dnn]");
			goto end;
		}
	}

	candidates = cJSON_GetObjectItemCaseSensitive(smf_selection_dataJSON,
	                                              "candidates");
	if(candidates) {
		if(!cJSON_IsNull(candidates)) {
			cJSON *candidates_local_map = NULL;
			if(!cJSON_IsObject(candidates) &&
			   !cJSON_IsNull(candidates))
			{
				printf(
					"smf_selection_data_parseFromJSON() failed [candidates]");
				goto end;
			}
			if(cJSON_IsObject(candidates)) {
				candidatesList = list_create();
				map_t *localMapKeyPair = NULL;
				cJSON_ArrayForEach(candidates_local_map,
				                   candidates) {
					cJSON *localMapObject =
						candidates_local_map;
					if(cJSON_IsObject(localMapObject)) {
						localMapKeyPair = map_create(
							strdup(localMapObject->
							       string), candidate_for_replacement_parseFromJSON(
								localMapObject));
					} else if(cJSON_IsNull(localMapObject))
					{
						localMapKeyPair = map_create(strdup(
										     localMapObject
										     ->
										     string),
						                             NULL);
					} else {
						printf(
							"smf_selection_data_parseFromJSON() failed [inner]");
						goto end;
					}
					list_add(candidatesList,
					         localMapKeyPair);
				}
			}
		}
	}

	snssai = cJSON_GetObjectItemCaseSensitive(smf_selection_dataJSON,
	                                          "snssai");
	if(snssai) {
		snssai_local_nonprim = snssai_parseFromJSON(snssai);
		if(!snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [snssai]");
			goto end;
		}
	}

	mapping_snssai = cJSON_GetObjectItemCaseSensitive(
		smf_selection_dataJSON, "mappingSnssai");
	if(mapping_snssai) {
		mapping_snssai_local_nonprim = snssai_parseFromJSON(
			mapping_snssai);
		if(!mapping_snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [mapping_snssai]");
			goto end;
		}
	}

	dnn = cJSON_GetObjectItemCaseSensitive(smf_selection_dataJSON, "dnn");
	if(dnn) {
		if(!cJSON_IsString(dnn) &&
		   !cJSON_IsNull(dnn))
		{
			printf("smf_selection_data_parseFromJSON() failed [dnn]");
			goto end;
		}
	}

	smf_selection_data_local_var = smf_selection_data_create(
		unsupp_dnn ? true : false,
		unsupp_dnn ? unsupp_dnn->valueint : 0,
		candidates &&
		cJSON_IsNull(candidates) ? true : false,
		candidates ? candidatesList : NULL,
		snssai ? snssai_local_nonprim : NULL,
		mapping_snssai ? mapping_snssai_local_nonprim : NULL,
		dnn &&
		!cJSON_IsNull(dnn) ? strdup(dnn->valuestring) : NULL
		);

	return smf_selection_data_local_var;
end:
	if(candidatesList) {
		list_for_each(candidatesList, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			candidate_for_replacement_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(candidatesList);
		candidatesList = NULL;
	}
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(mapping_snssai_local_nonprim) {
		snssai_free(mapping_snssai_local_nonprim);
		mapping_snssai_local_nonprim = NULL;
	}
	return NULL;
}

smf_selection_data_t *smf_selection_data_copy(smf_selection_data_t	*dst,
                                              smf_selection_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = smf_selection_data_convertToJSON(src);
	if(!item) {
		printf("smf_selection_data_convertToJSON() failed");
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

	smf_selection_data_free(dst);
	dst = smf_selection_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
