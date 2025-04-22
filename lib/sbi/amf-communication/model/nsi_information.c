#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nsi_information.h"

nsi_information_t *nsi_information_create(char *nrf_id, char *nsi_id,
                                          char *nrf_nf_mgt_uri,
                                          char *nrf_access_token_uri,
                                          list_t *nrf_oauth2_required) {
	nsi_information_t *nsi_information_local_var =
		malloc(sizeof(nsi_information_t));

	nsi_information_local_var->nrf_id = nrf_id;
	nsi_information_local_var->nsi_id = nsi_id;
	nsi_information_local_var->nrf_nf_mgt_uri = nrf_nf_mgt_uri;
	nsi_information_local_var->nrf_access_token_uri = nrf_access_token_uri;
	nsi_information_local_var->nrf_oauth2_required = nrf_oauth2_required;

	return nsi_information_local_var;
}

void nsi_information_free(nsi_information_t *nsi_information) {
	lnode_t *node = NULL;

	if(NULL == nsi_information) {
		return;
	}
	if(nsi_information->nrf_id) {
		free(nsi_information->nrf_id);
		nsi_information->nrf_id = NULL;
	}
	if(nsi_information->nsi_id) {
		free(nsi_information->nsi_id);
		nsi_information->nsi_id = NULL;
	}
	if(nsi_information->nrf_nf_mgt_uri) {
		free(nsi_information->nrf_nf_mgt_uri);
		nsi_information->nrf_nf_mgt_uri = NULL;
	}
	if(nsi_information->nrf_access_token_uri) {
		free(nsi_information->nrf_access_token_uri);
		nsi_information->nrf_access_token_uri = NULL;
	}
	if(nsi_information->nrf_oauth2_required) {
		list_for_each(nsi_information->nrf_oauth2_required, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(nsi_information->nrf_oauth2_required);
		nsi_information->nrf_oauth2_required = NULL;
	}
	free(nsi_information);
}

cJSON *nsi_information_convertToJSON(nsi_information_t *nsi_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nsi_information == NULL) {
		printf("nsi_information_convertToJSON() failed [NsiInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!nsi_information->nrf_id) {
		printf("nsi_information_convertToJSON() failed [nrf_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "nrfId",
	                           nsi_information->nrf_id) == NULL)
	{
		printf("nsi_information_convertToJSON() failed [nrf_id]");
		goto end;
	}

	if(nsi_information->nsi_id) {
		if(cJSON_AddStringToObject(item, "nsiId",
		                           nsi_information->nsi_id) == NULL)
		{
			printf("nsi_information_convertToJSON() failed [nsi_id]");
			goto end;
		}
	}

	if(nsi_information->nrf_nf_mgt_uri) {
		if(cJSON_AddStringToObject(item, "nrfNfMgtUri",
		                           nsi_information->nrf_nf_mgt_uri) ==
		   NULL)
		{
			printf(
				"nsi_information_convertToJSON() failed [nrf_nf_mgt_uri]");
			goto end;
		}
	}

	if(nsi_information->nrf_access_token_uri) {
		if(cJSON_AddStringToObject(item, "nrfAccessTokenUri",
		                           nsi_information->nrf_access_token_uri)
		   == NULL)
		{
			printf(
				"nsi_information_convertToJSON() failed [nrf_access_token_uri]");
			goto end;
		}
	}

	if(nsi_information->nrf_oauth2_required) {
		cJSON *nrf_oauth2_required = cJSON_AddObjectToObject(item,
		                                                     "nrfOauth2Required");
		if(nrf_oauth2_required == NULL) {
			printf(
				"nsi_information_convertToJSON() failed [nrf_oauth2_required]");
			goto end;
		}
		cJSON *localMapObject = nrf_oauth2_required;
		if(nsi_information->nrf_oauth2_required) {
			list_for_each(nsi_information->nrf_oauth2_required,
			              node) {
				map_t *localKeyValue = (map_t *) node->data;
				if(localKeyValue == NULL) {
					printf(
						"nsi_information_convertToJSON() failed [nrf_oauth2_required]");
					goto end;
				}
				if(localKeyValue->key == NULL) {
					printf(
						"nsi_information_convertToJSON() failed [nrf_oauth2_required]");
					goto end;
				}
				if(cJSON_AddBoolToObject(localMapObject,
				                         localKeyValue->key,
				                         (uintptr_t)
				                         localKeyValue->value)
				   == NULL)
				{
					printf(
						"nsi_information_convertToJSON() failed [inner]");
					goto end;
				}
			}
		}
	}

end:
	return item;
}

nsi_information_t *nsi_information_parseFromJSON(cJSON *nsi_informationJSON) {
	nsi_information_t *nsi_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *nrf_id = NULL;
	cJSON *nsi_id = NULL;
	cJSON *nrf_nf_mgt_uri = NULL;
	cJSON *nrf_access_token_uri = NULL;
	cJSON *nrf_oauth2_required = NULL;
	list_t *nrf_oauth2_requiredList = NULL;
	nrf_id = cJSON_GetObjectItemCaseSensitive(nsi_informationJSON, "nrfId");
	if(!nrf_id) {
		printf("nsi_information_parseFromJSON() failed [nrf_id]");
		goto end;
	}
	if(!cJSON_IsString(nrf_id)) {
		printf("nsi_information_parseFromJSON() failed [nrf_id]");
		goto end;
	}

	nsi_id = cJSON_GetObjectItemCaseSensitive(nsi_informationJSON, "nsiId");
	if(nsi_id) {
		if(!cJSON_IsString(nsi_id) &&
		   !cJSON_IsNull(nsi_id))
		{
			printf("nsi_information_parseFromJSON() failed [nsi_id]");
			goto end;
		}
	}

	nrf_nf_mgt_uri = cJSON_GetObjectItemCaseSensitive(nsi_informationJSON,
	                                                  "nrfNfMgtUri");
	if(nrf_nf_mgt_uri) {
		if(!cJSON_IsString(nrf_nf_mgt_uri) &&
		   !cJSON_IsNull(nrf_nf_mgt_uri))
		{
			printf(
				"nsi_information_parseFromJSON() failed [nrf_nf_mgt_uri]");
			goto end;
		}
	}

	nrf_access_token_uri = cJSON_GetObjectItemCaseSensitive(
		nsi_informationJSON, "nrfAccessTokenUri");
	if(nrf_access_token_uri) {
		if(!cJSON_IsString(nrf_access_token_uri) &&
		   !cJSON_IsNull(nrf_access_token_uri))
		{
			printf(
				"nsi_information_parseFromJSON() failed [nrf_access_token_uri]");
			goto end;
		}
	}

	nrf_oauth2_required = cJSON_GetObjectItemCaseSensitive(
		nsi_informationJSON, "nrfOauth2Required");
	if(nrf_oauth2_required) {
		cJSON *nrf_oauth2_required_local_map = NULL;
		if(!cJSON_IsObject(nrf_oauth2_required) &&
		   !cJSON_IsNull(nrf_oauth2_required))
		{
			printf(
				"nsi_information_parseFromJSON() failed [nrf_oauth2_required]");
			goto end;
		}
		if(cJSON_IsObject(nrf_oauth2_required)) {
			nrf_oauth2_requiredList = list_create();
			map_t *localMapKeyPair = NULL;
			cJSON_ArrayForEach(nrf_oauth2_required_local_map,
			                   nrf_oauth2_required) {
				cJSON *localMapObject =
					nrf_oauth2_required_local_map;
				double *localDouble = NULL;
				int *localInt = NULL;
				if(!cJSON_IsBool(localMapObject)) {
					printf(
						"nsi_information_parseFromJSON() failed [inner]");
					goto end;
				}
				localInt = (int *) calloc(1, sizeof(int));
				if(!localInt) {
					printf(
						"nsi_information_parseFromJSON() failed [inner]");
					goto end;
				}
				*localInt = localMapObject->valueint;
				localMapKeyPair =
					map_create(strdup(
							   localMapObject->
							   string), localInt);
				list_add(nrf_oauth2_requiredList,
				         localMapKeyPair);
			}
		}
	}

	nsi_information_local_var = nsi_information_create(
		strdup(nrf_id->valuestring),
		nsi_id &&
		!cJSON_IsNull(nsi_id) ? strdup(nsi_id->valuestring) : NULL,
		nrf_nf_mgt_uri &&
		!cJSON_IsNull(nrf_nf_mgt_uri) ? strdup(nrf_nf_mgt_uri->
		                                       valuestring) : NULL,
		nrf_access_token_uri &&
		!cJSON_IsNull(nrf_access_token_uri) ? strdup(
			nrf_access_token_uri->valuestring) : NULL,
		nrf_oauth2_required ? nrf_oauth2_requiredList : NULL
		);

	return nsi_information_local_var;
end:
	if(nrf_oauth2_requiredList) {
		list_for_each(nrf_oauth2_requiredList, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(nrf_oauth2_requiredList);
		nrf_oauth2_requiredList = NULL;
	}
	return NULL;
}

nsi_information_t *nsi_information_copy(nsi_information_t	*dst,
                                        nsi_information_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nsi_information_convertToJSON(src);
	if(!item) {
		printf("nsi_information_convertToJSON() failed");
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

	nsi_information_free(dst);
	dst = nsi_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
