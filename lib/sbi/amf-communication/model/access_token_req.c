#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "access_token_req.h"

char *grant_typeaccess_token_req_ToString(
	access_token_req_grant_type_e grant_type) {
	const char *grant_typeArray[] = { "NULL", "client_credentials" };
	size_t sizeofArray = sizeof(grant_typeArray) /
	                     sizeof(grant_typeArray[0]);
	if(grant_type < sizeofArray) {
		return (char *) grant_typeArray[grant_type];
	} else {
		return (char *) "Unknown";
	}
}

access_token_req_grant_type_e grant_typeaccess_token_req_FromString(
	char *grant_type) {
	int stringToReturn = 0;
	const char *grant_typeArray[] = { "NULL", "client_credentials" };
	size_t sizeofArray = sizeof(grant_typeArray) /
	                     sizeof(grant_typeArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(grant_type, grant_typeArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
access_token_req_t *access_token_req_create(
	access_token_req_grant_type_e grant_type, char *nf_instance_id,
	nf_type_t *nf_type, nf_type_t *target_nf_type, char *scope,
	char *target_nf_instance_id, plmn_id_t *requester_plmn,
	list_t *requester_plmn_list, list_t *requester_snssai_list,
	char *requester_fqdn, list_t *requester_snpn_list,
	plmn_id_t *target_plmn, plmn_id_nid_t *target_snpn,
	list_t *target_snssai_list, list_t *target_nsi_list,
	char *target_nf_set_id, char *target_nf_service_set_id,
	char *hnrf_access_token_uri, char *source_nf_instance_id) {
	access_token_req_t *access_token_req_local_var =
		malloc(sizeof(access_token_req_t));

	access_token_req_local_var->grant_type = grant_type;
	access_token_req_local_var->nf_instance_id = nf_instance_id;
	access_token_req_local_var->nf_type = nf_type;
	access_token_req_local_var->target_nf_type = target_nf_type;
	access_token_req_local_var->scope = scope;
	access_token_req_local_var->target_nf_instance_id =
		target_nf_instance_id;
	access_token_req_local_var->requester_plmn = requester_plmn;
	access_token_req_local_var->requester_plmn_list = requester_plmn_list;
	access_token_req_local_var->requester_snssai_list =
		requester_snssai_list;
	access_token_req_local_var->requester_fqdn = requester_fqdn;
	access_token_req_local_var->requester_snpn_list = requester_snpn_list;
	access_token_req_local_var->target_plmn = target_plmn;
	access_token_req_local_var->target_snpn = target_snpn;
	access_token_req_local_var->target_snssai_list = target_snssai_list;
	access_token_req_local_var->target_nsi_list = target_nsi_list;
	access_token_req_local_var->target_nf_set_id = target_nf_set_id;
	access_token_req_local_var->target_nf_service_set_id =
		target_nf_service_set_id;
	access_token_req_local_var->hnrf_access_token_uri =
		hnrf_access_token_uri;
	access_token_req_local_var->source_nf_instance_id =
		source_nf_instance_id;

	return access_token_req_local_var;
}

void access_token_req_free(access_token_req_t *access_token_req) {
	lnode_t *node = NULL;

	if(NULL == access_token_req) {
		return;
	}
	if(access_token_req->nf_instance_id) {
		free(access_token_req->nf_instance_id);
		access_token_req->nf_instance_id = NULL;
	}
	if(access_token_req->nf_type) {
		nf_type_free(access_token_req->nf_type);
		access_token_req->nf_type = NULL;
	}
	if(access_token_req->target_nf_type) {
		nf_type_free(access_token_req->target_nf_type);
		access_token_req->target_nf_type = NULL;
	}
	if(access_token_req->scope) {
		free(access_token_req->scope);
		access_token_req->scope = NULL;
	}
	if(access_token_req->target_nf_instance_id) {
		free(access_token_req->target_nf_instance_id);
		access_token_req->target_nf_instance_id = NULL;
	}
	if(access_token_req->requester_plmn) {
		plmn_id_free(access_token_req->requester_plmn);
		access_token_req->requester_plmn = NULL;
	}
	if(access_token_req->requester_plmn_list) {
		list_for_each(access_token_req->requester_plmn_list, node) {
			plmn_id_free(node->data);
		}
		list_free(access_token_req->requester_plmn_list);
		access_token_req->requester_plmn_list = NULL;
	}
	if(access_token_req->requester_snssai_list) {
		list_for_each(access_token_req->requester_snssai_list, node) {
			snssai_free(node->data);
		}
		list_free(access_token_req->requester_snssai_list);
		access_token_req->requester_snssai_list = NULL;
	}
	if(access_token_req->requester_fqdn) {
		free(access_token_req->requester_fqdn);
		access_token_req->requester_fqdn = NULL;
	}
	if(access_token_req->requester_snpn_list) {
		list_for_each(access_token_req->requester_snpn_list, node) {
			plmn_id_nid_free(node->data);
		}
		list_free(access_token_req->requester_snpn_list);
		access_token_req->requester_snpn_list = NULL;
	}
	if(access_token_req->target_plmn) {
		plmn_id_free(access_token_req->target_plmn);
		access_token_req->target_plmn = NULL;
	}
	if(access_token_req->target_snpn) {
		plmn_id_nid_free(access_token_req->target_snpn);
		access_token_req->target_snpn = NULL;
	}
	if(access_token_req->target_snssai_list) {
		list_for_each(access_token_req->target_snssai_list, node) {
			snssai_free(node->data);
		}
		list_free(access_token_req->target_snssai_list);
		access_token_req->target_snssai_list = NULL;
	}
	if(access_token_req->target_nsi_list) {
		list_for_each(access_token_req->target_nsi_list, node) {
			free(node->data);
		}
		list_free(access_token_req->target_nsi_list);
		access_token_req->target_nsi_list = NULL;
	}
	if(access_token_req->target_nf_set_id) {
		free(access_token_req->target_nf_set_id);
		access_token_req->target_nf_set_id = NULL;
	}
	if(access_token_req->target_nf_service_set_id) {
		free(access_token_req->target_nf_service_set_id);
		access_token_req->target_nf_service_set_id = NULL;
	}
	if(access_token_req->hnrf_access_token_uri) {
		free(access_token_req->hnrf_access_token_uri);
		access_token_req->hnrf_access_token_uri = NULL;
	}
	if(access_token_req->source_nf_instance_id) {
		free(access_token_req->source_nf_instance_id);
		access_token_req->source_nf_instance_id = NULL;
	}
	free(access_token_req);
}

cJSON *access_token_req_convertToJSON(access_token_req_t *access_token_req) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(access_token_req == NULL) {
		printf(
			"access_token_req_convertToJSON() failed [AccessTokenReq]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(access_token_req->grant_type == access_token_req_GRANTTYPE_NULL) {
		printf("access_token_req_convertToJSON() failed [grant_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "grant_type",
	                           grant_typeaccess_token_req_ToString(
					   access_token_req->grant_type)) ==
	   NULL)
	{
		printf("access_token_req_convertToJSON() failed [grant_type]");
		goto end;
	}

	if(!access_token_req->nf_instance_id) {
		printf(
			"access_token_req_convertToJSON() failed [nf_instance_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "nfInstanceId",
	                           access_token_req->nf_instance_id) == NULL)
	{
		printf(
			"access_token_req_convertToJSON() failed [nf_instance_id]");
		goto end;
	}

	if(access_token_req->nf_type) {
		cJSON *nf_type_local_JSON = nf_type_convertToJSON(
			access_token_req->nf_type);
		if(nf_type_local_JSON == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [nf_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "nfType", nf_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [nf_type]");
			goto end;
		}
	}

	if(access_token_req->target_nf_type) {
		cJSON *target_nf_type_local_JSON = nf_type_convertToJSON(
			access_token_req->target_nf_type);
		if(target_nf_type_local_JSON == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [target_nf_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "targetNfType",
		                      target_nf_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [target_nf_type]");
			goto end;
		}
	}

	if(!access_token_req->scope) {
		printf("access_token_req_convertToJSON() failed [scope]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "scope",
	                           access_token_req->scope) == NULL)
	{
		printf("access_token_req_convertToJSON() failed [scope]");
		goto end;
	}

	if(access_token_req->target_nf_instance_id) {
		if(cJSON_AddStringToObject(item, "targetNfInstanceId",
		                           access_token_req->
		                           target_nf_instance_id) == NULL)
		{
			printf(
				"access_token_req_convertToJSON() failed [target_nf_instance_id]");
			goto end;
		}
	}

	if(access_token_req->requester_plmn) {
		cJSON *requester_plmn_local_JSON = plmn_id_convertToJSON(
			access_token_req->requester_plmn);
		if(requester_plmn_local_JSON == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [requester_plmn]");
			goto end;
		}
		cJSON_AddItemToObject(item, "requesterPlmn",
		                      requester_plmn_local_JSON);
		if(item->child == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [requester_plmn]");
			goto end;
		}
	}

	if(access_token_req->requester_plmn_list) {
		cJSON *requester_plmn_listList = cJSON_AddArrayToObject(item,
		                                                        "requesterPlmnList");
		if(requester_plmn_listList == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [requester_plmn_list]");
			goto end;
		}
		list_for_each(access_token_req->requester_plmn_list, node) {
			cJSON *itemLocal = plmn_id_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"access_token_req_convertToJSON() failed [requester_plmn_list]");
				goto end;
			}
			cJSON_AddItemToArray(requester_plmn_listList,
			                     itemLocal);
		}
	}

	if(access_token_req->requester_snssai_list) {
		cJSON *requester_snssai_listList = cJSON_AddArrayToObject(item,
		                                                          "requesterSnssaiList");
		if(requester_snssai_listList == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [requester_snssai_list]");
			goto end;
		}
		list_for_each(access_token_req->requester_snssai_list, node) {
			cJSON *itemLocal = snssai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"access_token_req_convertToJSON() failed [requester_snssai_list]");
				goto end;
			}
			cJSON_AddItemToArray(requester_snssai_listList,
			                     itemLocal);
		}
	}

	if(access_token_req->requester_fqdn) {
		if(cJSON_AddStringToObject(item, "requesterFqdn",
		                           access_token_req->requester_fqdn) ==
		   NULL)
		{
			printf(
				"access_token_req_convertToJSON() failed [requester_fqdn]");
			goto end;
		}
	}

	if(access_token_req->requester_snpn_list) {
		cJSON *requester_snpn_listList = cJSON_AddArrayToObject(item,
		                                                        "requesterSnpnList");
		if(requester_snpn_listList == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [requester_snpn_list]");
			goto end;
		}
		list_for_each(access_token_req->requester_snpn_list, node) {
			cJSON *itemLocal =
				plmn_id_nid_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"access_token_req_convertToJSON() failed [requester_snpn_list]");
				goto end;
			}
			cJSON_AddItemToArray(requester_snpn_listList,
			                     itemLocal);
		}
	}

	if(access_token_req->target_plmn) {
		cJSON *target_plmn_local_JSON = plmn_id_convertToJSON(
			access_token_req->target_plmn);
		if(target_plmn_local_JSON == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [target_plmn]");
			goto end;
		}
		cJSON_AddItemToObject(item, "targetPlmn",
		                      target_plmn_local_JSON);
		if(item->child == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [target_plmn]");
			goto end;
		}
	}

	if(access_token_req->target_snpn) {
		cJSON *target_snpn_local_JSON = plmn_id_nid_convertToJSON(
			access_token_req->target_snpn);
		if(target_snpn_local_JSON == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [target_snpn]");
			goto end;
		}
		cJSON_AddItemToObject(item, "targetSnpn",
		                      target_snpn_local_JSON);
		if(item->child == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [target_snpn]");
			goto end;
		}
	}

	if(access_token_req->target_snssai_list) {
		cJSON *target_snssai_listList = cJSON_AddArrayToObject(item,
		                                                       "targetSnssaiList");
		if(target_snssai_listList == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [target_snssai_list]");
			goto end;
		}
		list_for_each(access_token_req->target_snssai_list, node) {
			cJSON *itemLocal = snssai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"access_token_req_convertToJSON() failed [target_snssai_list]");
				goto end;
			}
			cJSON_AddItemToArray(target_snssai_listList, itemLocal);
		}
	}

	if(access_token_req->target_nsi_list) {
		cJSON *target_nsi_listList = cJSON_AddArrayToObject(item,
		                                                    "targetNsiList");
		if(target_nsi_listList == NULL) {
			printf(
				"access_token_req_convertToJSON() failed [target_nsi_list]");
			goto end;
		}
		list_for_each(access_token_req->target_nsi_list, node) {
			if(cJSON_AddStringToObject(target_nsi_listList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"access_token_req_convertToJSON() failed [target_nsi_list]");
				goto end;
			}
		}
	}

	if(access_token_req->target_nf_set_id) {
		if(cJSON_AddStringToObject(item, "targetNfSetId",
		                           access_token_req->target_nf_set_id)
		   == NULL)
		{
			printf(
				"access_token_req_convertToJSON() failed [target_nf_set_id]");
			goto end;
		}
	}

	if(access_token_req->target_nf_service_set_id) {
		if(cJSON_AddStringToObject(item, "targetNfServiceSetId",
		                           access_token_req->
		                           target_nf_service_set_id) == NULL)
		{
			printf(
				"access_token_req_convertToJSON() failed [target_nf_service_set_id]");
			goto end;
		}
	}

	if(access_token_req->hnrf_access_token_uri) {
		if(cJSON_AddStringToObject(item, "hnrfAccessTokenUri",
		                           access_token_req->
		                           hnrf_access_token_uri) == NULL)
		{
			printf(
				"access_token_req_convertToJSON() failed [hnrf_access_token_uri]");
			goto end;
		}
	}

	if(access_token_req->source_nf_instance_id) {
		if(cJSON_AddStringToObject(item, "sourceNfInstanceId",
		                           access_token_req->
		                           source_nf_instance_id) == NULL)
		{
			printf(
				"access_token_req_convertToJSON() failed [source_nf_instance_id]");
			goto end;
		}
	}

end:
	return item;
}

access_token_req_t *access_token_req_parseFromJSON(cJSON *access_token_reqJSON)
{
	access_token_req_t *access_token_req_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *grant_type = NULL;
	access_token_req_grant_type_e grant_typeVariable = 0;
	cJSON *nf_instance_id = NULL;
	cJSON *nf_type = NULL;
	nf_type_t *nf_type_local_nonprim = NULL;
	cJSON *target_nf_type = NULL;
	nf_type_t *target_nf_type_local_nonprim = NULL;
	cJSON *scope = NULL;
	cJSON *target_nf_instance_id = NULL;
	cJSON *requester_plmn = NULL;
	plmn_id_t *requester_plmn_local_nonprim = NULL;
	cJSON *requester_plmn_list = NULL;
	list_t *requester_plmn_listList = NULL;
	cJSON *requester_snssai_list = NULL;
	list_t *requester_snssai_listList = NULL;
	cJSON *requester_fqdn = NULL;
	cJSON *requester_snpn_list = NULL;
	list_t *requester_snpn_listList = NULL;
	cJSON *target_plmn = NULL;
	plmn_id_t *target_plmn_local_nonprim = NULL;
	cJSON *target_snpn = NULL;
	plmn_id_nid_t *target_snpn_local_nonprim = NULL;
	cJSON *target_snssai_list = NULL;
	list_t *target_snssai_listList = NULL;
	cJSON *target_nsi_list = NULL;
	list_t *target_nsi_listList = NULL;
	cJSON *target_nf_set_id = NULL;
	cJSON *target_nf_service_set_id = NULL;
	cJSON *hnrf_access_token_uri = NULL;
	cJSON *source_nf_instance_id = NULL;
	grant_type = cJSON_GetObjectItemCaseSensitive(access_token_reqJSON,
	                                              "grant_type");
	if(!grant_type) {
		printf("access_token_req_parseFromJSON() failed [grant_type]");
		goto end;
	}
	if(!cJSON_IsString(grant_type)) {
		printf("access_token_req_parseFromJSON() failed [grant_type]");
		goto end;
	}
	grant_typeVariable = grant_typeaccess_token_req_FromString(
		grant_type->valuestring);

	nf_instance_id = cJSON_GetObjectItemCaseSensitive(access_token_reqJSON,
	                                                  "nfInstanceId");
	if(!nf_instance_id) {
		printf(
			"access_token_req_parseFromJSON() failed [nf_instance_id]");
		goto end;
	}
	if(!cJSON_IsString(nf_instance_id)) {
		printf(
			"access_token_req_parseFromJSON() failed [nf_instance_id]");
		goto end;
	}

	nf_type = cJSON_GetObjectItemCaseSensitive(access_token_reqJSON,
	                                           "nfType");
	if(nf_type) {
		nf_type_local_nonprim = nf_type_parseFromJSON(nf_type);
		if(!nf_type_local_nonprim) {
			printf("nf_type_parseFromJSON failed [nf_type]");
			goto end;
		}
	}

	target_nf_type = cJSON_GetObjectItemCaseSensitive(access_token_reqJSON,
	                                                  "targetNfType");
	if(target_nf_type) {
		target_nf_type_local_nonprim = nf_type_parseFromJSON(
			target_nf_type);
		if(!target_nf_type_local_nonprim) {
			printf("nf_type_parseFromJSON failed [target_nf_type]");
			goto end;
		}
	}

	scope = cJSON_GetObjectItemCaseSensitive(access_token_reqJSON, "scope");
	if(!scope) {
		printf("access_token_req_parseFromJSON() failed [scope]");
		goto end;
	}
	if(!cJSON_IsString(scope)) {
		printf("access_token_req_parseFromJSON() failed [scope]");
		goto end;
	}

	target_nf_instance_id = cJSON_GetObjectItemCaseSensitive(
		access_token_reqJSON, "targetNfInstanceId");
	if(target_nf_instance_id) {
		if(!cJSON_IsString(target_nf_instance_id) &&
		   !cJSON_IsNull(target_nf_instance_id))
		{
			printf(
				"access_token_req_parseFromJSON() failed [target_nf_instance_id]");
			goto end;
		}
	}

	requester_plmn = cJSON_GetObjectItemCaseSensitive(access_token_reqJSON,
	                                                  "requesterPlmn");
	if(requester_plmn) {
		requester_plmn_local_nonprim = plmn_id_parseFromJSON(
			requester_plmn);
		if(!requester_plmn_local_nonprim) {
			printf("plmn_id_parseFromJSON failed [requester_plmn]");
			goto end;
		}
	}

	requester_plmn_list = cJSON_GetObjectItemCaseSensitive(
		access_token_reqJSON, "requesterPlmnList");
	if(requester_plmn_list) {
		cJSON *requester_plmn_list_local = NULL;
		if(!cJSON_IsArray(requester_plmn_list)) {
			printf(
				"access_token_req_parseFromJSON() failed [requester_plmn_list]");
			goto end;
		}

		requester_plmn_listList = list_create();

		cJSON_ArrayForEach(requester_plmn_list_local,
		                   requester_plmn_list) {
			if(!cJSON_IsObject(requester_plmn_list_local)) {
				printf(
					"access_token_req_parseFromJSON() failed [requester_plmn_list]");
				goto end;
			}
			plmn_id_t *requester_plmn_listItem =
				plmn_id_parseFromJSON(requester_plmn_list_local);
			if(!requester_plmn_listItem) {
				printf("No requester_plmn_listItem");
				goto end;
			}
			list_add(requester_plmn_listList,
			         requester_plmn_listItem);
		}
	}

	requester_snssai_list = cJSON_GetObjectItemCaseSensitive(
		access_token_reqJSON, "requesterSnssaiList");
	if(requester_snssai_list) {
		cJSON *requester_snssai_list_local = NULL;
		if(!cJSON_IsArray(requester_snssai_list)) {
			printf(
				"access_token_req_parseFromJSON() failed [requester_snssai_list]");
			goto end;
		}

		requester_snssai_listList = list_create();

		cJSON_ArrayForEach(requester_snssai_list_local,
		                   requester_snssai_list) {
			if(!cJSON_IsObject(requester_snssai_list_local)) {
				printf(
					"access_token_req_parseFromJSON() failed [requester_snssai_list]");
				goto end;
			}
			snssai_t *requester_snssai_listItem =
				snssai_parseFromJSON(requester_snssai_list_local);
			if(!requester_snssai_listItem) {
				printf("No requester_snssai_listItem");
				goto end;
			}
			list_add(requester_snssai_listList,
			         requester_snssai_listItem);
		}
	}

	requester_fqdn = cJSON_GetObjectItemCaseSensitive(access_token_reqJSON,
	                                                  "requesterFqdn");
	if(requester_fqdn) {
		if(!cJSON_IsString(requester_fqdn) &&
		   !cJSON_IsNull(requester_fqdn))
		{
			printf(
				"access_token_req_parseFromJSON() failed [requester_fqdn]");
			goto end;
		}
	}

	requester_snpn_list = cJSON_GetObjectItemCaseSensitive(
		access_token_reqJSON, "requesterSnpnList");
	if(requester_snpn_list) {
		cJSON *requester_snpn_list_local = NULL;
		if(!cJSON_IsArray(requester_snpn_list)) {
			printf(
				"access_token_req_parseFromJSON() failed [requester_snpn_list]");
			goto end;
		}

		requester_snpn_listList = list_create();

		cJSON_ArrayForEach(requester_snpn_list_local,
		                   requester_snpn_list) {
			if(!cJSON_IsObject(requester_snpn_list_local)) {
				printf(
					"access_token_req_parseFromJSON() failed [requester_snpn_list]");
				goto end;
			}
			plmn_id_nid_t *requester_snpn_listItem =
				plmn_id_nid_parseFromJSON(
					requester_snpn_list_local);
			if(!requester_snpn_listItem) {
				printf("No requester_snpn_listItem");
				goto end;
			}
			list_add(requester_snpn_listList,
			         requester_snpn_listItem);
		}
	}

	target_plmn = cJSON_GetObjectItemCaseSensitive(access_token_reqJSON,
	                                               "targetPlmn");
	if(target_plmn) {
		target_plmn_local_nonprim = plmn_id_parseFromJSON(target_plmn);
		if(!target_plmn_local_nonprim) {
			printf("plmn_id_parseFromJSON failed [target_plmn]");
			goto end;
		}
	}

	target_snpn = cJSON_GetObjectItemCaseSensitive(access_token_reqJSON,
	                                               "targetSnpn");
	if(target_snpn) {
		target_snpn_local_nonprim = plmn_id_nid_parseFromJSON(
			target_snpn);
		if(!target_snpn_local_nonprim) {
			printf("plmn_id_nid_parseFromJSON failed [target_snpn]");
			goto end;
		}
	}

	target_snssai_list = cJSON_GetObjectItemCaseSensitive(
		access_token_reqJSON, "targetSnssaiList");
	if(target_snssai_list) {
		cJSON *target_snssai_list_local = NULL;
		if(!cJSON_IsArray(target_snssai_list)) {
			printf(
				"access_token_req_parseFromJSON() failed [target_snssai_list]");
			goto end;
		}

		target_snssai_listList = list_create();

		cJSON_ArrayForEach(target_snssai_list_local,
		                   target_snssai_list) {
			if(!cJSON_IsObject(target_snssai_list_local)) {
				printf(
					"access_token_req_parseFromJSON() failed [target_snssai_list]");
				goto end;
			}
			snssai_t *target_snssai_listItem = snssai_parseFromJSON(
				target_snssai_list_local);
			if(!target_snssai_listItem) {
				printf("No target_snssai_listItem");
				goto end;
			}
			list_add(target_snssai_listList,
			         target_snssai_listItem);
		}
	}

	target_nsi_list = cJSON_GetObjectItemCaseSensitive(access_token_reqJSON,
	                                                   "targetNsiList");
	if(target_nsi_list) {
		cJSON *target_nsi_list_local = NULL;
		if(!cJSON_IsArray(target_nsi_list)) {
			printf(
				"access_token_req_parseFromJSON() failed [target_nsi_list]");
			goto end;
		}

		target_nsi_listList = list_create();

		cJSON_ArrayForEach(target_nsi_list_local, target_nsi_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(target_nsi_list_local)) {
				printf(
					"access_token_req_parseFromJSON() failed [target_nsi_list]");
				goto end;
			}
			list_add(target_nsi_listList,
			         strdup(target_nsi_list_local->valuestring));
		}
	}

	target_nf_set_id = cJSON_GetObjectItemCaseSensitive(
		access_token_reqJSON, "targetNfSetId");
	if(target_nf_set_id) {
		if(!cJSON_IsString(target_nf_set_id) &&
		   !cJSON_IsNull(target_nf_set_id))
		{
			printf(
				"access_token_req_parseFromJSON() failed [target_nf_set_id]");
			goto end;
		}
	}

	target_nf_service_set_id = cJSON_GetObjectItemCaseSensitive(
		access_token_reqJSON, "targetNfServiceSetId");
	if(target_nf_service_set_id) {
		if(!cJSON_IsString(target_nf_service_set_id) &&
		   !cJSON_IsNull(target_nf_service_set_id))
		{
			printf(
				"access_token_req_parseFromJSON() failed [target_nf_service_set_id]");
			goto end;
		}
	}

	hnrf_access_token_uri = cJSON_GetObjectItemCaseSensitive(
		access_token_reqJSON, "hnrfAccessTokenUri");
	if(hnrf_access_token_uri) {
		if(!cJSON_IsString(hnrf_access_token_uri) &&
		   !cJSON_IsNull(hnrf_access_token_uri))
		{
			printf(
				"access_token_req_parseFromJSON() failed [hnrf_access_token_uri]");
			goto end;
		}
	}

	source_nf_instance_id = cJSON_GetObjectItemCaseSensitive(
		access_token_reqJSON, "sourceNfInstanceId");
	if(source_nf_instance_id) {
		if(!cJSON_IsString(source_nf_instance_id) &&
		   !cJSON_IsNull(source_nf_instance_id))
		{
			printf(
				"access_token_req_parseFromJSON() failed [source_nf_instance_id]");
			goto end;
		}
	}

	access_token_req_local_var = access_token_req_create(
		grant_typeVariable,
		strdup(nf_instance_id->valuestring),
		nf_type ? nf_type_local_nonprim : NULL,
		target_nf_type ? target_nf_type_local_nonprim : NULL,
		strdup(scope->valuestring),
		target_nf_instance_id &&
		!cJSON_IsNull(target_nf_instance_id) ? strdup(
			target_nf_instance_id->valuestring) : NULL,
		requester_plmn ? requester_plmn_local_nonprim : NULL,
		requester_plmn_list ? requester_plmn_listList : NULL,
		requester_snssai_list ? requester_snssai_listList : NULL,
		requester_fqdn &&
		!cJSON_IsNull(requester_fqdn) ? strdup(requester_fqdn->
		                                       valuestring) : NULL,
		requester_snpn_list ? requester_snpn_listList : NULL,
		target_plmn ? target_plmn_local_nonprim : NULL,
		target_snpn ? target_snpn_local_nonprim : NULL,
		target_snssai_list ? target_snssai_listList : NULL,
		target_nsi_list ? target_nsi_listList : NULL,
		target_nf_set_id &&
		!cJSON_IsNull(target_nf_set_id) ? strdup(target_nf_set_id->
		                                         valuestring) : NULL,
		target_nf_service_set_id &&
		!cJSON_IsNull(target_nf_service_set_id) ? strdup(
			target_nf_service_set_id->valuestring) : NULL,
		hnrf_access_token_uri &&
		!cJSON_IsNull(hnrf_access_token_uri) ? strdup(
			hnrf_access_token_uri->valuestring) : NULL,
		source_nf_instance_id &&
		!cJSON_IsNull(source_nf_instance_id) ? strdup(
			source_nf_instance_id->valuestring) : NULL
		);

	return access_token_req_local_var;
end:
	if(nf_type_local_nonprim) {
		nf_type_free(nf_type_local_nonprim);
		nf_type_local_nonprim = NULL;
	}
	if(target_nf_type_local_nonprim) {
		nf_type_free(target_nf_type_local_nonprim);
		target_nf_type_local_nonprim = NULL;
	}
	if(requester_plmn_local_nonprim) {
		plmn_id_free(requester_plmn_local_nonprim);
		requester_plmn_local_nonprim = NULL;
	}
	if(requester_plmn_listList) {
		list_for_each(requester_plmn_listList, node) {
			plmn_id_free(node->data);
		}
		list_free(requester_plmn_listList);
		requester_plmn_listList = NULL;
	}
	if(requester_snssai_listList) {
		list_for_each(requester_snssai_listList, node) {
			snssai_free(node->data);
		}
		list_free(requester_snssai_listList);
		requester_snssai_listList = NULL;
	}
	if(requester_snpn_listList) {
		list_for_each(requester_snpn_listList, node) {
			plmn_id_nid_free(node->data);
		}
		list_free(requester_snpn_listList);
		requester_snpn_listList = NULL;
	}
	if(target_plmn_local_nonprim) {
		plmn_id_free(target_plmn_local_nonprim);
		target_plmn_local_nonprim = NULL;
	}
	if(target_snpn_local_nonprim) {
		plmn_id_nid_free(target_snpn_local_nonprim);
		target_snpn_local_nonprim = NULL;
	}
	if(target_snssai_listList) {
		list_for_each(target_snssai_listList, node) {
			snssai_free(node->data);
		}
		list_free(target_snssai_listList);
		target_snssai_listList = NULL;
	}
	if(target_nsi_listList) {
		list_for_each(target_nsi_listList, node) {
			free(node->data);
		}
		list_free(target_nsi_listList);
		target_nsi_listList = NULL;
	}
	return NULL;
}

access_token_req_t *access_token_req_copy(access_token_req_t	*dst,
                                          access_token_req_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = access_token_req_convertToJSON(src);
	if(!item) {
		printf("access_token_req_convertToJSON() failed");
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

	access_token_req_free(dst);
	dst = access_token_req_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
