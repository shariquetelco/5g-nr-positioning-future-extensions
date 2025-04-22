#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pdu_ses_traffic_req.h"

pdu_ses_traffic_req_t *pdu_ses_traffic_req_create(list_t	*flow_descs,
                                                  char		*app_id,
                                                  list_t	*domain_descs) {
	pdu_ses_traffic_req_t *pdu_ses_traffic_req_local_var =
		malloc(sizeof(pdu_ses_traffic_req_t));

	pdu_ses_traffic_req_local_var->flow_descs = flow_descs;
	pdu_ses_traffic_req_local_var->app_id = app_id;
	pdu_ses_traffic_req_local_var->domain_descs = domain_descs;

	return pdu_ses_traffic_req_local_var;
}

void pdu_ses_traffic_req_free(pdu_ses_traffic_req_t *pdu_ses_traffic_req) {
	lnode_t *node = NULL;

	if(NULL == pdu_ses_traffic_req) {
		return;
	}
	if(pdu_ses_traffic_req->flow_descs) {
		list_for_each(pdu_ses_traffic_req->flow_descs, node) {
			free(node->data);
		}
		list_free(pdu_ses_traffic_req->flow_descs);
		pdu_ses_traffic_req->flow_descs = NULL;
	}
	if(pdu_ses_traffic_req->app_id) {
		free(pdu_ses_traffic_req->app_id);
		pdu_ses_traffic_req->app_id = NULL;
	}
	if(pdu_ses_traffic_req->domain_descs) {
		list_for_each(pdu_ses_traffic_req->domain_descs, node) {
			free(node->data);
		}
		list_free(pdu_ses_traffic_req->domain_descs);
		pdu_ses_traffic_req->domain_descs = NULL;
	}
	free(pdu_ses_traffic_req);
}

cJSON *pdu_ses_traffic_req_convertToJSON(
	pdu_ses_traffic_req_t *pdu_ses_traffic_req) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pdu_ses_traffic_req == NULL) {
		printf(
			"pdu_ses_traffic_req_convertToJSON() failed [PduSesTrafficReq]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(pdu_ses_traffic_req->flow_descs) {
		cJSON *flow_descsList =
			cJSON_AddArrayToObject(item, "flowDescs");
		if(flow_descsList == NULL) {
			printf(
				"pdu_ses_traffic_req_convertToJSON() failed [flow_descs]");
			goto end;
		}
		list_for_each(pdu_ses_traffic_req->flow_descs, node) {
			if(cJSON_AddStringToObject(flow_descsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"pdu_ses_traffic_req_convertToJSON() failed [flow_descs]");
				goto end;
			}
		}
	}

	if(pdu_ses_traffic_req->app_id) {
		if(cJSON_AddStringToObject(item, "appId",
		                           pdu_ses_traffic_req->app_id) == NULL)
		{
			printf(
				"pdu_ses_traffic_req_convertToJSON() failed [app_id]");
			goto end;
		}
	}

	if(pdu_ses_traffic_req->domain_descs) {
		cJSON *domain_descsList = cJSON_AddArrayToObject(item,
		                                                 "domainDescs");
		if(domain_descsList == NULL) {
			printf(
				"pdu_ses_traffic_req_convertToJSON() failed [domain_descs]");
			goto end;
		}
		list_for_each(pdu_ses_traffic_req->domain_descs, node) {
			if(cJSON_AddStringToObject(domain_descsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"pdu_ses_traffic_req_convertToJSON() failed [domain_descs]");
				goto end;
			}
		}
	}

end:
	return item;
}

pdu_ses_traffic_req_t *pdu_ses_traffic_req_parseFromJSON(
	cJSON *pdu_ses_traffic_reqJSON) {
	pdu_ses_traffic_req_t *pdu_ses_traffic_req_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *flow_descs = NULL;
	list_t *flow_descsList = NULL;
	cJSON *app_id = NULL;
	cJSON *domain_descs = NULL;
	list_t *domain_descsList = NULL;
	flow_descs = cJSON_GetObjectItemCaseSensitive(pdu_ses_traffic_reqJSON,
	                                              "flowDescs");
	if(flow_descs) {
		cJSON *flow_descs_local = NULL;
		if(!cJSON_IsArray(flow_descs)) {
			printf(
				"pdu_ses_traffic_req_parseFromJSON() failed [flow_descs]");
			goto end;
		}

		flow_descsList = list_create();

		cJSON_ArrayForEach(flow_descs_local, flow_descs) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(flow_descs_local)) {
				printf(
					"pdu_ses_traffic_req_parseFromJSON() failed [flow_descs]");
				goto end;
			}
			list_add(flow_descsList,
			         strdup(flow_descs_local->valuestring));
		}
	}

	app_id = cJSON_GetObjectItemCaseSensitive(pdu_ses_traffic_reqJSON,
	                                          "appId");
	if(app_id) {
		if(!cJSON_IsString(app_id) &&
		   !cJSON_IsNull(app_id))
		{
			printf(
				"pdu_ses_traffic_req_parseFromJSON() failed [app_id]");
			goto end;
		}
	}

	domain_descs = cJSON_GetObjectItemCaseSensitive(pdu_ses_traffic_reqJSON,
	                                                "domainDescs");
	if(domain_descs) {
		cJSON *domain_descs_local = NULL;
		if(!cJSON_IsArray(domain_descs)) {
			printf(
				"pdu_ses_traffic_req_parseFromJSON() failed [domain_descs]");
			goto end;
		}

		domain_descsList = list_create();

		cJSON_ArrayForEach(domain_descs_local, domain_descs) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(domain_descs_local)) {
				printf(
					"pdu_ses_traffic_req_parseFromJSON() failed [domain_descs]");
				goto end;
			}
			list_add(domain_descsList,
			         strdup(domain_descs_local->valuestring));
		}
	}

	pdu_ses_traffic_req_local_var = pdu_ses_traffic_req_create(
		flow_descs ? flow_descsList : NULL,
		app_id &&
		!cJSON_IsNull(app_id) ? strdup(app_id->valuestring) : NULL,
		domain_descs ? domain_descsList : NULL
		);

	return pdu_ses_traffic_req_local_var;
end:
	if(flow_descsList) {
		list_for_each(flow_descsList, node) {
			free(node->data);
		}
		list_free(flow_descsList);
		flow_descsList = NULL;
	}
	if(domain_descsList) {
		list_for_each(domain_descsList, node) {
			free(node->data);
		}
		list_free(domain_descsList);
		domain_descsList = NULL;
	}
	return NULL;
}

pdu_ses_traffic_req_t *pdu_ses_traffic_req_copy(pdu_ses_traffic_req_t	*dst,
                                                pdu_ses_traffic_req_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pdu_ses_traffic_req_convertToJSON(src);
	if(!item) {
		printf("pdu_ses_traffic_req_convertToJSON() failed");
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

	pdu_ses_traffic_req_free(dst);
	dst = pdu_ses_traffic_req_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
