#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n1_message_container.h"

n1_message_container_t *n1_message_container_create(
	n1_message_class_e n1_message_class,
	ref_to_binary_data_t *n1_message_content, char *nf_id,
	char *service_instance_id) {
	n1_message_container_t *n1_message_container_local_var =
		malloc(sizeof(n1_message_container_t));

	n1_message_container_local_var->n1_message_class = n1_message_class;
	n1_message_container_local_var->n1_message_content = n1_message_content;
	n1_message_container_local_var->nf_id = nf_id;
	n1_message_container_local_var->service_instance_id =
		service_instance_id;

	return n1_message_container_local_var;
}

void n1_message_container_free(n1_message_container_t *n1_message_container) {
	lnode_t *node = NULL;

	if(NULL == n1_message_container) {
		return;
	}
	if(n1_message_container->n1_message_content) {
		ref_to_binary_data_free(n1_message_container->n1_message_content);
		n1_message_container->n1_message_content = NULL;
	}
	if(n1_message_container->nf_id) {
		free(n1_message_container->nf_id);
		n1_message_container->nf_id = NULL;
	}
	if(n1_message_container->service_instance_id) {
		free(n1_message_container->service_instance_id);
		n1_message_container->service_instance_id = NULL;
	}
	free(n1_message_container);
}

cJSON *n1_message_container_convertToJSON(
	n1_message_container_t *n1_message_container) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n1_message_container == NULL) {
		printf(
			"n1_message_container_convertToJSON() failed [N1MessageContainer]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(n1_message_container->n1_message_class == n1_message_class_NULL) {
		printf(
			"n1_message_container_convertToJSON() failed [n1_message_class]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "n1MessageClass",
	                           n1_message_class_ToString(
					   n1_message_container->
					   n1_message_class)) ==
	   NULL)
	{
		printf(
			"n1_message_container_convertToJSON() failed [n1_message_class]");
		goto end;
	}

	if(!n1_message_container->n1_message_content) {
		printf(
			"n1_message_container_convertToJSON() failed [n1_message_content]");
		return NULL;
	}
	cJSON *n1_message_content_local_JSON = ref_to_binary_data_convertToJSON(
		n1_message_container->n1_message_content);
	if(n1_message_content_local_JSON == NULL) {
		printf(
			"n1_message_container_convertToJSON() failed [n1_message_content]");
		goto end;
	}
	cJSON_AddItemToObject(item, "n1MessageContent",
	                      n1_message_content_local_JSON);
	if(item->child == NULL) {
		printf(
			"n1_message_container_convertToJSON() failed [n1_message_content]");
		goto end;
	}

	if(n1_message_container->nf_id) {
		if(cJSON_AddStringToObject(item, "nfId",
		                           n1_message_container->nf_id) == NULL)
		{
			printf(
				"n1_message_container_convertToJSON() failed [nf_id]");
			goto end;
		}
	}

	if(n1_message_container->service_instance_id) {
		if(cJSON_AddStringToObject(item, "serviceInstanceId",
		                           n1_message_container->
		                           service_instance_id) == NULL)
		{
			printf(
				"n1_message_container_convertToJSON() failed [service_instance_id]");
			goto end;
		}
	}

end:
	return item;
}

n1_message_container_t *n1_message_container_parseFromJSON(
	cJSON *n1_message_containerJSON) {
	n1_message_container_t *n1_message_container_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *n1_message_class = NULL;
	n1_message_class_e n1_message_classVariable = 0;
	cJSON *n1_message_content = NULL;
	ref_to_binary_data_t *n1_message_content_local_nonprim = NULL;
	cJSON *nf_id = NULL;
	cJSON *service_instance_id = NULL;
	n1_message_class = cJSON_GetObjectItemCaseSensitive(
		n1_message_containerJSON, "n1MessageClass");
	if(!n1_message_class) {
		printf(
			"n1_message_container_parseFromJSON() failed [n1_message_class]");
		goto end;
	}
	if(!cJSON_IsString(n1_message_class)) {
		printf(
			"n1_message_container_parseFromJSON() failed [n1_message_class]");
		goto end;
	}
	n1_message_classVariable = n1_message_class_FromString(
		n1_message_class->valuestring);

	n1_message_content = cJSON_GetObjectItemCaseSensitive(
		n1_message_containerJSON, "n1MessageContent");
	if(!n1_message_content) {
		printf(
			"n1_message_container_parseFromJSON() failed [n1_message_content]");
		goto end;
	}
	n1_message_content_local_nonprim = ref_to_binary_data_parseFromJSON(
		n1_message_content);
	if(!n1_message_content_local_nonprim) {
		printf(
			"ref_to_binary_data_parseFromJSON failed [n1_message_content]");
		goto end;
	}

	nf_id = cJSON_GetObjectItemCaseSensitive(n1_message_containerJSON,
	                                         "nfId");
	if(nf_id) {
		if(!cJSON_IsString(nf_id) &&
		   !cJSON_IsNull(nf_id))
		{
			printf(
				"n1_message_container_parseFromJSON() failed [nf_id]");
			goto end;
		}
	}

	service_instance_id = cJSON_GetObjectItemCaseSensitive(
		n1_message_containerJSON, "serviceInstanceId");
	if(service_instance_id) {
		if(!cJSON_IsString(service_instance_id) &&
		   !cJSON_IsNull(service_instance_id))
		{
			printf(
				"n1_message_container_parseFromJSON() failed [service_instance_id]");
			goto end;
		}
	}

	n1_message_container_local_var = n1_message_container_create(
		n1_message_classVariable,
		n1_message_content_local_nonprim,
		nf_id &&
		!cJSON_IsNull(nf_id) ? strdup(nf_id->valuestring) : NULL,
		service_instance_id &&
		!cJSON_IsNull(service_instance_id) ? strdup(service_instance_id
		                                            ->valuestring) : NULL
		);

	return n1_message_container_local_var;
end:
	if(n1_message_content_local_nonprim) {
		ref_to_binary_data_free(n1_message_content_local_nonprim);
		n1_message_content_local_nonprim = NULL;
	}
	return NULL;
}

n1_message_container_t *n1_message_container_copy(
	n1_message_container_t	*dst,
	n1_message_container_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = n1_message_container_convertToJSON(src);
	if(!item) {
		printf("n1_message_container_convertToJSON() failed");
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

	n1_message_container_free(dst);
	dst = n1_message_container_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
