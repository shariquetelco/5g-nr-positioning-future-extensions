#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "suggested_pfd_info.h"

suggested_pfd_info_t *suggested_pfd_info_create(char *pfd_id,
                                                list_t *ip3_tuple_list,
                                                list_t *urls,
                                                list_t *domain_names,
                                                domain_name_protocol_t *dn_protocol, bool is_pfd_confidence,
                                                int pfd_confidence) {
	suggested_pfd_info_t *suggested_pfd_info_local_var =
		malloc(sizeof(suggested_pfd_info_t));

	suggested_pfd_info_local_var->pfd_id = pfd_id;
	suggested_pfd_info_local_var->ip3_tuple_list = ip3_tuple_list;
	suggested_pfd_info_local_var->urls = urls;
	suggested_pfd_info_local_var->domain_names = domain_names;
	suggested_pfd_info_local_var->dn_protocol = dn_protocol;
	suggested_pfd_info_local_var->is_pfd_confidence = is_pfd_confidence;
	suggested_pfd_info_local_var->pfd_confidence = pfd_confidence;

	return suggested_pfd_info_local_var;
}

void suggested_pfd_info_free(suggested_pfd_info_t *suggested_pfd_info) {
	lnode_t *node = NULL;

	if(NULL == suggested_pfd_info) {
		return;
	}
	if(suggested_pfd_info->pfd_id) {
		free(suggested_pfd_info->pfd_id);
		suggested_pfd_info->pfd_id = NULL;
	}
	if(suggested_pfd_info->ip3_tuple_list) {
		list_for_each(suggested_pfd_info->ip3_tuple_list, node) {
			free(node->data);
		}
		list_free(suggested_pfd_info->ip3_tuple_list);
		suggested_pfd_info->ip3_tuple_list = NULL;
	}
	if(suggested_pfd_info->urls) {
		list_for_each(suggested_pfd_info->urls, node) {
			free(node->data);
		}
		list_free(suggested_pfd_info->urls);
		suggested_pfd_info->urls = NULL;
	}
	if(suggested_pfd_info->domain_names) {
		list_for_each(suggested_pfd_info->domain_names, node) {
			free(node->data);
		}
		list_free(suggested_pfd_info->domain_names);
		suggested_pfd_info->domain_names = NULL;
	}
	if(suggested_pfd_info->dn_protocol) {
		domain_name_protocol_free(suggested_pfd_info->dn_protocol);
		suggested_pfd_info->dn_protocol = NULL;
	}
	free(suggested_pfd_info);
}

cJSON *suggested_pfd_info_convertToJSON(
	suggested_pfd_info_t *suggested_pfd_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(suggested_pfd_info == NULL) {
		printf(
			"suggested_pfd_info_convertToJSON() failed [SuggestedPfdInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!suggested_pfd_info->pfd_id) {
		printf("suggested_pfd_info_convertToJSON() failed [pfd_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "pfdId",
	                           suggested_pfd_info->pfd_id) == NULL)
	{
		printf("suggested_pfd_info_convertToJSON() failed [pfd_id]");
		goto end;
	}

	if(suggested_pfd_info->ip3_tuple_list) {
		cJSON *ip3_tuple_listList = cJSON_AddArrayToObject(item,
		                                                   "ip3TupleList");
		if(ip3_tuple_listList == NULL) {
			printf(
				"suggested_pfd_info_convertToJSON() failed [ip3_tuple_list]");
			goto end;
		}
		list_for_each(suggested_pfd_info->ip3_tuple_list, node) {
			if(cJSON_AddStringToObject(ip3_tuple_listList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"suggested_pfd_info_convertToJSON() failed [ip3_tuple_list]");
				goto end;
			}
		}
	}

	if(suggested_pfd_info->urls) {
		cJSON *urlsList = cJSON_AddArrayToObject(item, "urls");
		if(urlsList == NULL) {
			printf(
				"suggested_pfd_info_convertToJSON() failed [urls]");
			goto end;
		}
		list_for_each(suggested_pfd_info->urls, node) {
			if(cJSON_AddStringToObject(urlsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"suggested_pfd_info_convertToJSON() failed [urls]");
				goto end;
			}
		}
	}

	if(suggested_pfd_info->domain_names) {
		cJSON *domain_namesList = cJSON_AddArrayToObject(item,
		                                                 "domainNames");
		if(domain_namesList == NULL) {
			printf(
				"suggested_pfd_info_convertToJSON() failed [domain_names]");
			goto end;
		}
		list_for_each(suggested_pfd_info->domain_names, node) {
			if(cJSON_AddStringToObject(domain_namesList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"suggested_pfd_info_convertToJSON() failed [domain_names]");
				goto end;
			}
		}
	}

	if(suggested_pfd_info->dn_protocol) {
		cJSON *dn_protocol_local_JSON =
			domain_name_protocol_convertToJSON(
				suggested_pfd_info->dn_protocol);
		if(dn_protocol_local_JSON == NULL) {
			printf(
				"suggested_pfd_info_convertToJSON() failed [dn_protocol]");
			goto end;
		}
		cJSON_AddItemToObject(item, "dnProtocol",
		                      dn_protocol_local_JSON);
		if(item->child == NULL) {
			printf(
				"suggested_pfd_info_convertToJSON() failed [dn_protocol]");
			goto end;
		}
	}

	if(suggested_pfd_info->is_pfd_confidence) {
		if(cJSON_AddNumberToObject(item, "pfdConfidence",
		                           suggested_pfd_info->pfd_confidence)
		   == NULL)
		{
			printf(
				"suggested_pfd_info_convertToJSON() failed [pfd_confidence]");
			goto end;
		}
	}

end:
	return item;
}

suggested_pfd_info_t *suggested_pfd_info_parseFromJSON(
	cJSON *suggested_pfd_infoJSON) {
	suggested_pfd_info_t *suggested_pfd_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pfd_id = NULL;
	cJSON *ip3_tuple_list = NULL;
	list_t *ip3_tuple_listList = NULL;
	cJSON *urls = NULL;
	list_t *urlsList = NULL;
	cJSON *domain_names = NULL;
	list_t *domain_namesList = NULL;
	cJSON *dn_protocol = NULL;
	domain_name_protocol_t *dn_protocol_local_nonprim = NULL;
	cJSON *pfd_confidence = NULL;
	pfd_id = cJSON_GetObjectItemCaseSensitive(suggested_pfd_infoJSON,
	                                          "pfdId");
	if(!pfd_id) {
		printf("suggested_pfd_info_parseFromJSON() failed [pfd_id]");
		goto end;
	}
	if(!cJSON_IsString(pfd_id)) {
		printf("suggested_pfd_info_parseFromJSON() failed [pfd_id]");
		goto end;
	}

	ip3_tuple_list = cJSON_GetObjectItemCaseSensitive(
		suggested_pfd_infoJSON, "ip3TupleList");
	if(ip3_tuple_list) {
		cJSON *ip3_tuple_list_local = NULL;
		if(!cJSON_IsArray(ip3_tuple_list)) {
			printf(
				"suggested_pfd_info_parseFromJSON() failed [ip3_tuple_list]");
			goto end;
		}

		ip3_tuple_listList = list_create();

		cJSON_ArrayForEach(ip3_tuple_list_local, ip3_tuple_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(ip3_tuple_list_local)) {
				printf(
					"suggested_pfd_info_parseFromJSON() failed [ip3_tuple_list]");
				goto end;
			}
			list_add(ip3_tuple_listList,
			         strdup(ip3_tuple_list_local->valuestring));
		}
	}

	urls = cJSON_GetObjectItemCaseSensitive(suggested_pfd_infoJSON, "urls");
	if(urls) {
		cJSON *urls_local = NULL;
		if(!cJSON_IsArray(urls)) {
			printf(
				"suggested_pfd_info_parseFromJSON() failed [urls]");
			goto end;
		}

		urlsList = list_create();

		cJSON_ArrayForEach(urls_local, urls) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(urls_local)) {
				printf(
					"suggested_pfd_info_parseFromJSON() failed [urls]");
				goto end;
			}
			list_add(urlsList, strdup(urls_local->valuestring));
		}
	}

	domain_names = cJSON_GetObjectItemCaseSensitive(suggested_pfd_infoJSON,
	                                                "domainNames");
	if(domain_names) {
		cJSON *domain_names_local = NULL;
		if(!cJSON_IsArray(domain_names)) {
			printf(
				"suggested_pfd_info_parseFromJSON() failed [domain_names]");
			goto end;
		}

		domain_namesList = list_create();

		cJSON_ArrayForEach(domain_names_local, domain_names) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(domain_names_local)) {
				printf(
					"suggested_pfd_info_parseFromJSON() failed [domain_names]");
				goto end;
			}
			list_add(domain_namesList,
			         strdup(domain_names_local->valuestring));
		}
	}

	dn_protocol = cJSON_GetObjectItemCaseSensitive(suggested_pfd_infoJSON,
	                                               "dnProtocol");
	if(dn_protocol) {
		dn_protocol_local_nonprim = domain_name_protocol_parseFromJSON(
			dn_protocol);
		if(!dn_protocol_local_nonprim) {
			printf(
				"domain_name_protocol_parseFromJSON failed [dn_protocol]");
			goto end;
		}
	}

	pfd_confidence = cJSON_GetObjectItemCaseSensitive(
		suggested_pfd_infoJSON, "pfdConfidence");
	if(pfd_confidence) {
		if(!cJSON_IsNumber(pfd_confidence)) {
			printf(
				"suggested_pfd_info_parseFromJSON() failed [pfd_confidence]");
			goto end;
		}
	}

	suggested_pfd_info_local_var = suggested_pfd_info_create(
		strdup(pfd_id->valuestring),
		ip3_tuple_list ? ip3_tuple_listList : NULL,
		urls ? urlsList : NULL,
		domain_names ? domain_namesList : NULL,
		dn_protocol ? dn_protocol_local_nonprim : NULL,
		pfd_confidence ? true : false,
		pfd_confidence ? pfd_confidence->valuedouble : 0
		);

	return suggested_pfd_info_local_var;
end:
	if(ip3_tuple_listList) {
		list_for_each(ip3_tuple_listList, node) {
			free(node->data);
		}
		list_free(ip3_tuple_listList);
		ip3_tuple_listList = NULL;
	}
	if(urlsList) {
		list_for_each(urlsList, node) {
			free(node->data);
		}
		list_free(urlsList);
		urlsList = NULL;
	}
	if(domain_namesList) {
		list_for_each(domain_namesList, node) {
			free(node->data);
		}
		list_free(domain_namesList);
		domain_namesList = NULL;
	}
	if(dn_protocol_local_nonprim) {
		domain_name_protocol_free(dn_protocol_local_nonprim);
		dn_protocol_local_nonprim = NULL;
	}
	return NULL;
}

suggested_pfd_info_t *suggested_pfd_info_copy(suggested_pfd_info_t	*dst,
                                              suggested_pfd_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = suggested_pfd_info_convertToJSON(src);
	if(!item) {
		printf("suggested_pfd_info_convertToJSON() failed");
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

	suggested_pfd_info_free(dst);
	dst = suggested_pfd_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
