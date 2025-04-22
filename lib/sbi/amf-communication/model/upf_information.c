#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "upf_information.h"

upf_information_t *upf_information_create(char *upf_id, addr_fqdn_t *upf_addr) {
	upf_information_t *upf_information_local_var =
		malloc(sizeof(upf_information_t));

	upf_information_local_var->upf_id = upf_id;
	upf_information_local_var->upf_addr = upf_addr;

	return upf_information_local_var;
}

void upf_information_free(upf_information_t *upf_information) {
	lnode_t *node = NULL;

	if(NULL == upf_information) {
		return;
	}
	if(upf_information->upf_id) {
		free(upf_information->upf_id);
		upf_information->upf_id = NULL;
	}
	if(upf_information->upf_addr) {
		addr_fqdn_free(upf_information->upf_addr);
		upf_information->upf_addr = NULL;
	}
	free(upf_information);
}

cJSON *upf_information_convertToJSON(upf_information_t *upf_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(upf_information == NULL) {
		printf("upf_information_convertToJSON() failed [UpfInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(upf_information->upf_id) {
		if(cJSON_AddStringToObject(item, "upfId",
		                           upf_information->upf_id) == NULL)
		{
			printf("upf_information_convertToJSON() failed [upf_id]");
			goto end;
		}
	}

	if(upf_information->upf_addr) {
		cJSON *upf_addr_local_JSON = addr_fqdn_convertToJSON(
			upf_information->upf_addr);
		if(upf_addr_local_JSON == NULL) {
			printf(
				"upf_information_convertToJSON() failed [upf_addr]");
			goto end;
		}
		cJSON_AddItemToObject(item, "upfAddr", upf_addr_local_JSON);
		if(item->child == NULL) {
			printf(
				"upf_information_convertToJSON() failed [upf_addr]");
			goto end;
		}
	}

end:
	return item;
}

upf_information_t *upf_information_parseFromJSON(cJSON *upf_informationJSON) {
	upf_information_t *upf_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *upf_id = NULL;
	cJSON *upf_addr = NULL;
	addr_fqdn_t *upf_addr_local_nonprim = NULL;
	upf_id = cJSON_GetObjectItemCaseSensitive(upf_informationJSON, "upfId");
	if(upf_id) {
		if(!cJSON_IsString(upf_id) &&
		   !cJSON_IsNull(upf_id))
		{
			printf("upf_information_parseFromJSON() failed [upf_id]");
			goto end;
		}
	}

	upf_addr = cJSON_GetObjectItemCaseSensitive(upf_informationJSON,
	                                            "upfAddr");
	if(upf_addr) {
		upf_addr_local_nonprim = addr_fqdn_parseFromJSON(upf_addr);
		if(!upf_addr_local_nonprim) {
			printf("addr_fqdn_parseFromJSON failed [upf_addr]");
			goto end;
		}
	}

	upf_information_local_var = upf_information_create(
		upf_id &&
		!cJSON_IsNull(upf_id) ? strdup(upf_id->valuestring) : NULL,
		upf_addr ? upf_addr_local_nonprim : NULL
		);

	return upf_information_local_var;
end:
	if(upf_addr_local_nonprim) {
		addr_fqdn_free(upf_addr_local_nonprim);
		upf_addr_local_nonprim = NULL;
	}
	return NULL;
}

upf_information_t *upf_information_copy(upf_information_t	*dst,
                                        upf_information_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = upf_information_convertToJSON(src);
	if(!item) {
		printf("upf_information_convertToJSON() failed");
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

	upf_information_free(dst);
	dst = upf_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
