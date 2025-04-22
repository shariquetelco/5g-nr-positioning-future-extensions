#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nrppa_information.h"

nrppa_information_t *nrppa_information_create(char		*nf_id,
                                              n2_info_content_t *nrppa_pdu,
                                              char		*service_instance_id)
{
	nrppa_information_t *nrppa_information_local_var =
		malloc(sizeof(nrppa_information_t));

	nrppa_information_local_var->nf_id = nf_id;
	nrppa_information_local_var->nrppa_pdu = nrppa_pdu;
	nrppa_information_local_var->service_instance_id = service_instance_id;

	return nrppa_information_local_var;
}

void nrppa_information_free(nrppa_information_t *nrppa_information) {
	lnode_t *node = NULL;

	if(NULL == nrppa_information) {
		return;
	}
	if(nrppa_information->nf_id) {
		free(nrppa_information->nf_id);
		nrppa_information->nf_id = NULL;
	}
	if(nrppa_information->nrppa_pdu) {
		n2_info_content_free(nrppa_information->nrppa_pdu);
		nrppa_information->nrppa_pdu = NULL;
	}
	if(nrppa_information->service_instance_id) {
		free(nrppa_information->service_instance_id);
		nrppa_information->service_instance_id = NULL;
	}
	free(nrppa_information);
}

cJSON *nrppa_information_convertToJSON(nrppa_information_t *nrppa_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nrppa_information == NULL) {
		printf(
			"nrppa_information_convertToJSON() failed [NrppaInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!nrppa_information->nf_id) {
		printf("nrppa_information_convertToJSON() failed [nf_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "nfId",
	                           nrppa_information->nf_id) == NULL)
	{
		printf("nrppa_information_convertToJSON() failed [nf_id]");
		goto end;
	}

	if(!nrppa_information->nrppa_pdu) {
		printf("nrppa_information_convertToJSON() failed [nrppa_pdu]");
		return NULL;
	}
	cJSON *nrppa_pdu_local_JSON = n2_info_content_convertToJSON(
		nrppa_information->nrppa_pdu);
	if(nrppa_pdu_local_JSON == NULL) {
		printf("nrppa_information_convertToJSON() failed [nrppa_pdu]");
		goto end;
	}
	cJSON_AddItemToObject(item, "nrppaPdu", nrppa_pdu_local_JSON);
	if(item->child == NULL) {
		printf("nrppa_information_convertToJSON() failed [nrppa_pdu]");
		goto end;
	}

	if(nrppa_information->service_instance_id) {
		if(cJSON_AddStringToObject(item, "serviceInstanceId",
		                           nrppa_information->
		                           service_instance_id) == NULL)
		{
			printf(
				"nrppa_information_convertToJSON() failed [service_instance_id]");
			goto end;
		}
	}

end:
	return item;
}

nrppa_information_t *nrppa_information_parseFromJSON(
	cJSON *nrppa_informationJSON) {
	nrppa_information_t *nrppa_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *nf_id = NULL;
	cJSON *nrppa_pdu = NULL;
	n2_info_content_t *nrppa_pdu_local_nonprim = NULL;
	cJSON *service_instance_id = NULL;
	nf_id = cJSON_GetObjectItemCaseSensitive(nrppa_informationJSON, "nfId");
	if(!nf_id) {
		printf("nrppa_information_parseFromJSON() failed [nf_id]");
		goto end;
	}
	if(!cJSON_IsString(nf_id)) {
		printf("nrppa_information_parseFromJSON() failed [nf_id]");
		goto end;
	}

	nrppa_pdu = cJSON_GetObjectItemCaseSensitive(nrppa_informationJSON,
	                                             "nrppaPdu");
	if(!nrppa_pdu) {
		printf("nrppa_information_parseFromJSON() failed [nrppa_pdu]");
		goto end;
	}
	nrppa_pdu_local_nonprim = n2_info_content_parseFromJSON(nrppa_pdu);
	if(!nrppa_pdu_local_nonprim) {
		printf("n2_info_content_parseFromJSON failed [nrppa_pdu]");
		goto end;
	}

	service_instance_id = cJSON_GetObjectItemCaseSensitive(
		nrppa_informationJSON, "serviceInstanceId");
	if(service_instance_id) {
		if(!cJSON_IsString(service_instance_id) &&
		   !cJSON_IsNull(service_instance_id))
		{
			printf(
				"nrppa_information_parseFromJSON() failed [service_instance_id]");
			goto end;
		}
	}

	nrppa_information_local_var = nrppa_information_create(
		strdup(nf_id->valuestring),
		nrppa_pdu_local_nonprim,
		service_instance_id &&
		!cJSON_IsNull(service_instance_id) ? strdup(service_instance_id
		                                            ->valuestring) : NULL
		);

	return nrppa_information_local_var;
end:
	if(nrppa_pdu_local_nonprim) {
		n2_info_content_free(nrppa_pdu_local_nonprim);
		nrppa_pdu_local_nonprim = NULL;
	}
	return NULL;
}

nrppa_information_t *nrppa_information_copy(nrppa_information_t *dst,
                                            nrppa_information_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nrppa_information_convertToJSON(src);
	if(!item) {
		printf("nrppa_information_convertToJSON() failed");
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

	nrppa_information_free(dst);
	dst = nrppa_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
