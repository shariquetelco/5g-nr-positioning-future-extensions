#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "relocate_ue_context_request.h"

relocate_ue_context_request_t *relocate_ue_context_request_create(
	ue_context_relocate_data_t	*json_data,
	binary_t			*binary_data_forward_relocation_request,
	binary_t			*binary_data_n2_information,
	binary_t			*binary_data_n2_information_ext1,
	binary_t			*binary_data_n2_information_ext2,
	binary_t			*binary_data_n2_information_ext3,
	binary_t			*binary_data_n2_information_ext4,
	binary_t			*binary_data_n2_information_ext5,
	binary_t			*binary_data_n2_information_ext6,
	binary_t			*binary_data_n2_information_ext7,
	binary_t			*binary_data_n2_information_ext8,
	binary_t			*binary_data_n2_information_ext9,
	binary_t			*binary_data_n2_information_ext10,
	binary_t			*binary_data_n2_information_ext11,
	binary_t			*binary_data_n2_information_ext12,
	binary_t			*binary_data_n2_information_ext13,
	binary_t			*binary_data_n2_information_ext14,
	binary_t			*binary_data_n2_information_ext15,
	binary_t			*binary_data_n2_information_ext16) {
	relocate_ue_context_request_t *relocate_ue_context_request_local_var =
		malloc(sizeof(relocate_ue_context_request_t));

	relocate_ue_context_request_local_var->json_data = json_data;
	relocate_ue_context_request_local_var->
	binary_data_forward_relocation_request =
		binary_data_forward_relocation_request;
	relocate_ue_context_request_local_var->binary_data_n2_information =
		binary_data_n2_information;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext1 =
		binary_data_n2_information_ext1;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext2 =
		binary_data_n2_information_ext2;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext3 =
		binary_data_n2_information_ext3;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext4 =
		binary_data_n2_information_ext4;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext5 =
		binary_data_n2_information_ext5;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext6 =
		binary_data_n2_information_ext6;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext7 =
		binary_data_n2_information_ext7;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext8 =
		binary_data_n2_information_ext8;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext9 =
		binary_data_n2_information_ext9;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext10
	        = binary_data_n2_information_ext10;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext11
	        = binary_data_n2_information_ext11;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext12
	        = binary_data_n2_information_ext12;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext13
	        = binary_data_n2_information_ext13;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext14
	        = binary_data_n2_information_ext14;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext15
	        = binary_data_n2_information_ext15;
	relocate_ue_context_request_local_var->binary_data_n2_information_ext16
	        = binary_data_n2_information_ext16;

	return relocate_ue_context_request_local_var;
}

void relocate_ue_context_request_free(
	relocate_ue_context_request_t *relocate_ue_context_request) {
	lnode_t *node = NULL;

	if(NULL == relocate_ue_context_request) {
		return;
	}
	if(relocate_ue_context_request->json_data) {
		ue_context_relocate_data_free(
			relocate_ue_context_request->json_data);
		relocate_ue_context_request->json_data = NULL;
	}
	if(relocate_ue_context_request->binary_data_forward_relocation_request)
	{
		free(
			relocate_ue_context_request->binary_data_forward_relocation_request->data);
		relocate_ue_context_request->
		binary_data_forward_relocation_request = NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information) {
		free(
			relocate_ue_context_request->binary_data_n2_information->data);
		relocate_ue_context_request->binary_data_n2_information = NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext1) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext1->data);
		relocate_ue_context_request->binary_data_n2_information_ext1 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext2) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext2->data);
		relocate_ue_context_request->binary_data_n2_information_ext2 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext3) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext3->data);
		relocate_ue_context_request->binary_data_n2_information_ext3 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext4) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext4->data);
		relocate_ue_context_request->binary_data_n2_information_ext4 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext5) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext5->data);
		relocate_ue_context_request->binary_data_n2_information_ext5 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext6) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext6->data);
		relocate_ue_context_request->binary_data_n2_information_ext6 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext7) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext7->data);
		relocate_ue_context_request->binary_data_n2_information_ext7 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext8) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext8->data);
		relocate_ue_context_request->binary_data_n2_information_ext8 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext9) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext9->data);
		relocate_ue_context_request->binary_data_n2_information_ext9 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext10) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext10->data);
		relocate_ue_context_request->binary_data_n2_information_ext10 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext11) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext11->data);
		relocate_ue_context_request->binary_data_n2_information_ext11 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext12) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext12->data);
		relocate_ue_context_request->binary_data_n2_information_ext12 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext13) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext13->data);
		relocate_ue_context_request->binary_data_n2_information_ext13 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext14) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext14->data);
		relocate_ue_context_request->binary_data_n2_information_ext14 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext15) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext15->data);
		relocate_ue_context_request->binary_data_n2_information_ext15 =
			NULL;
	}
	if(relocate_ue_context_request->binary_data_n2_information_ext16) {
		free(
			relocate_ue_context_request->binary_data_n2_information_ext16->data);
		relocate_ue_context_request->binary_data_n2_information_ext16 =
			NULL;
	}
	free(relocate_ue_context_request);
}

cJSON *relocate_ue_context_request_convertToJSON(
	relocate_ue_context_request_t *relocate_ue_context_request) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(relocate_ue_context_request == NULL) {
		printf(
			"relocate_ue_context_request_convertToJSON() failed [RelocateUEContext_request]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(relocate_ue_context_request->json_data) {
		cJSON *json_data_local_JSON =
			ue_context_relocate_data_convertToJSON(
				relocate_ue_context_request->json_data);
		if(json_data_local_JSON == NULL) {
			printf(
				"relocate_ue_context_request_convertToJSON() failed [json_data]");
			goto end;
		}
		cJSON_AddItemToObject(item, "jsonData", json_data_local_JSON);
		if(item->child == NULL) {
			printf(
				"relocate_ue_context_request_convertToJSON() failed [json_data]");
			goto end;
		}
	}

	if(relocate_ue_context_request->binary_data_forward_relocation_request)
	{
		char *encoded_str_binary_data_forward_relocation_request =
			base64encode(
				relocate_ue_context_request->binary_data_forward_relocation_request->data,
				relocate_ue_context_request->binary_data_forward_relocation_request->len);
		if(cJSON_AddStringToObject(item,
		                           "binaryDataForwardRelocationRequest",
		                           encoded_str_binary_data_forward_relocation_request)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_forward_relocation_request]");
			goto end;
		}
		free(encoded_str_binary_data_forward_relocation_request);
	}

	if(relocate_ue_context_request->binary_data_n2_information) {
		char *encoded_str_binary_data_n2_information = base64encode(
			relocate_ue_context_request->binary_data_n2_information->data,
			relocate_ue_context_request->binary_data_n2_information->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2Information",
		                           encoded_str_binary_data_n2_information)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext1) {
		char *encoded_str_binary_data_n2_information_ext1 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext1->data,
				relocate_ue_context_request->binary_data_n2_information_ext1->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt1",
		                           encoded_str_binary_data_n2_information_ext1)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext1]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext1);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext2) {
		char *encoded_str_binary_data_n2_information_ext2 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext2->data,
				relocate_ue_context_request->binary_data_n2_information_ext2->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt2",
		                           encoded_str_binary_data_n2_information_ext2)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext2]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext2);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext3) {
		char *encoded_str_binary_data_n2_information_ext3 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext3->data,
				relocate_ue_context_request->binary_data_n2_information_ext3->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt3",
		                           encoded_str_binary_data_n2_information_ext3)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext3]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext3);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext4) {
		char *encoded_str_binary_data_n2_information_ext4 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext4->data,
				relocate_ue_context_request->binary_data_n2_information_ext4->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt4",
		                           encoded_str_binary_data_n2_information_ext4)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext4]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext4);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext5) {
		char *encoded_str_binary_data_n2_information_ext5 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext5->data,
				relocate_ue_context_request->binary_data_n2_information_ext5->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt5",
		                           encoded_str_binary_data_n2_information_ext5)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext5]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext5);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext6) {
		char *encoded_str_binary_data_n2_information_ext6 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext6->data,
				relocate_ue_context_request->binary_data_n2_information_ext6->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt6",
		                           encoded_str_binary_data_n2_information_ext6)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext6]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext6);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext7) {
		char *encoded_str_binary_data_n2_information_ext7 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext7->data,
				relocate_ue_context_request->binary_data_n2_information_ext7->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt7",
		                           encoded_str_binary_data_n2_information_ext7)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext7]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext7);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext8) {
		char *encoded_str_binary_data_n2_information_ext8 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext8->data,
				relocate_ue_context_request->binary_data_n2_information_ext8->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt8",
		                           encoded_str_binary_data_n2_information_ext8)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext8]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext8);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext9) {
		char *encoded_str_binary_data_n2_information_ext9 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext9->data,
				relocate_ue_context_request->binary_data_n2_information_ext9->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt9",
		                           encoded_str_binary_data_n2_information_ext9)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext9]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext9);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext10) {
		char *encoded_str_binary_data_n2_information_ext10 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext10->data,
				relocate_ue_context_request->binary_data_n2_information_ext10->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt10",
		                           encoded_str_binary_data_n2_information_ext10)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext10]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext10);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext11) {
		char *encoded_str_binary_data_n2_information_ext11 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext11->data,
				relocate_ue_context_request->binary_data_n2_information_ext11->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt11",
		                           encoded_str_binary_data_n2_information_ext11)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext11]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext11);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext12) {
		char *encoded_str_binary_data_n2_information_ext12 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext12->data,
				relocate_ue_context_request->binary_data_n2_information_ext12->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt12",
		                           encoded_str_binary_data_n2_information_ext12)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext12]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext12);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext13) {
		char *encoded_str_binary_data_n2_information_ext13 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext13->data,
				relocate_ue_context_request->binary_data_n2_information_ext13->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt13",
		                           encoded_str_binary_data_n2_information_ext13)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext13]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext13);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext14) {
		char *encoded_str_binary_data_n2_information_ext14 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext14->data,
				relocate_ue_context_request->binary_data_n2_information_ext14->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt14",
		                           encoded_str_binary_data_n2_information_ext14)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext14]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext14);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext15) {
		char *encoded_str_binary_data_n2_information_ext15 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext15->data,
				relocate_ue_context_request->binary_data_n2_information_ext15->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt15",
		                           encoded_str_binary_data_n2_information_ext15)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext15]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext15);
	}

	if(relocate_ue_context_request->binary_data_n2_information_ext16) {
		char *encoded_str_binary_data_n2_information_ext16 =
			base64encode(
				relocate_ue_context_request->binary_data_n2_information_ext16->data,
				relocate_ue_context_request->binary_data_n2_information_ext16->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2InformationExt16",
		                           encoded_str_binary_data_n2_information_ext16)
		   == NULL)
		{
			printf(
				"relocate_ue_context_request_convertToJSON() failed [binary_data_n2_information_ext16]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information_ext16);
	}

end:
	return item;
}

relocate_ue_context_request_t *relocate_ue_context_request_parseFromJSON(
	cJSON *relocate_ue_context_requestJSON) {
	relocate_ue_context_request_t *relocate_ue_context_request_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *json_data = NULL;
	ue_context_relocate_data_t *json_data_local_nonprim = NULL;
	cJSON *binary_data_forward_relocation_request = NULL;
	binary_t *decoded_str_binary_data_forward_relocation_request = NULL;
	cJSON *binary_data_n2_information = NULL;
	binary_t *decoded_str_binary_data_n2_information = NULL;
	cJSON *binary_data_n2_information_ext1 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext1 = NULL;
	cJSON *binary_data_n2_information_ext2 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext2 = NULL;
	cJSON *binary_data_n2_information_ext3 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext3 = NULL;
	cJSON *binary_data_n2_information_ext4 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext4 = NULL;
	cJSON *binary_data_n2_information_ext5 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext5 = NULL;
	cJSON *binary_data_n2_information_ext6 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext6 = NULL;
	cJSON *binary_data_n2_information_ext7 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext7 = NULL;
	cJSON *binary_data_n2_information_ext8 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext8 = NULL;
	cJSON *binary_data_n2_information_ext9 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext9 = NULL;
	cJSON *binary_data_n2_information_ext10 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext10 = NULL;
	cJSON *binary_data_n2_information_ext11 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext11 = NULL;
	cJSON *binary_data_n2_information_ext12 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext12 = NULL;
	cJSON *binary_data_n2_information_ext13 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext13 = NULL;
	cJSON *binary_data_n2_information_ext14 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext14 = NULL;
	cJSON *binary_data_n2_information_ext15 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext15 = NULL;
	cJSON *binary_data_n2_information_ext16 = NULL;
	binary_t *decoded_str_binary_data_n2_information_ext16 = NULL;
	json_data = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON, "jsonData");
	if(json_data) {
		json_data_local_nonprim =
			ue_context_relocate_data_parseFromJSON(json_data);
		if(!json_data_local_nonprim) {
			printf(
				"ue_context_relocate_data_parseFromJSON failed [json_data]");
			goto end;
		}
	}

	binary_data_forward_relocation_request =
		cJSON_GetObjectItemCaseSensitive(
			relocate_ue_context_requestJSON,
			"binaryDataForwardRelocationRequest");
	if(binary_data_forward_relocation_request) {
		decoded_str_binary_data_forward_relocation_request = malloc(
			sizeof(binary_t));

		if(!cJSON_IsString(binary_data_forward_relocation_request)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_forward_relocation_request]");
			goto end;
		}
		decoded_str_binary_data_forward_relocation_request->data =
			base64decode(
				binary_data_forward_relocation_request->valuestring, strlen(
					binary_data_forward_relocation_request->
					valuestring),
				&decoded_str_binary_data_forward_relocation_request->len);
		if(!decoded_str_binary_data_forward_relocation_request->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_forward_relocation_request]");
			goto end;
		}
	}

	binary_data_n2_information = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON, "binaryDataN2Information");
	if(binary_data_n2_information) {
		decoded_str_binary_data_n2_information =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information]");
			goto end;
		}
		decoded_str_binary_data_n2_information->data = base64decode(
			binary_data_n2_information->valuestring,
			strlen(
				binary_data_n2_information->valuestring),
			&decoded_str_binary_data_n2_information->len);
		if(!decoded_str_binary_data_n2_information->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information]");
			goto end;
		}
	}

	binary_data_n2_information_ext1 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON, "binaryDataN2InformationExt1");
	if(binary_data_n2_information_ext1) {
		decoded_str_binary_data_n2_information_ext1 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext1)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext1]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext1->data =
			base64decode(
				binary_data_n2_information_ext1->valuestring, strlen(
					binary_data_n2_information_ext1->
					valuestring),
				&decoded_str_binary_data_n2_information_ext1->len);
		if(!decoded_str_binary_data_n2_information_ext1->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext1]");
			goto end;
		}
	}

	binary_data_n2_information_ext2 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON, "binaryDataN2InformationExt2");
	if(binary_data_n2_information_ext2) {
		decoded_str_binary_data_n2_information_ext2 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext2)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext2]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext2->data =
			base64decode(
				binary_data_n2_information_ext2->valuestring, strlen(
					binary_data_n2_information_ext2->
					valuestring),
				&decoded_str_binary_data_n2_information_ext2->len);
		if(!decoded_str_binary_data_n2_information_ext2->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext2]");
			goto end;
		}
	}

	binary_data_n2_information_ext3 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON, "binaryDataN2InformationExt3");
	if(binary_data_n2_information_ext3) {
		decoded_str_binary_data_n2_information_ext3 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext3)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext3]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext3->data =
			base64decode(
				binary_data_n2_information_ext3->valuestring, strlen(
					binary_data_n2_information_ext3->
					valuestring),
				&decoded_str_binary_data_n2_information_ext3->len);
		if(!decoded_str_binary_data_n2_information_ext3->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext3]");
			goto end;
		}
	}

	binary_data_n2_information_ext4 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON, "binaryDataN2InformationExt4");
	if(binary_data_n2_information_ext4) {
		decoded_str_binary_data_n2_information_ext4 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext4)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext4]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext4->data =
			base64decode(
				binary_data_n2_information_ext4->valuestring, strlen(
					binary_data_n2_information_ext4->
					valuestring),
				&decoded_str_binary_data_n2_information_ext4->len);
		if(!decoded_str_binary_data_n2_information_ext4->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext4]");
			goto end;
		}
	}

	binary_data_n2_information_ext5 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON, "binaryDataN2InformationExt5");
	if(binary_data_n2_information_ext5) {
		decoded_str_binary_data_n2_information_ext5 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext5)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext5]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext5->data =
			base64decode(
				binary_data_n2_information_ext5->valuestring, strlen(
					binary_data_n2_information_ext5->
					valuestring),
				&decoded_str_binary_data_n2_information_ext5->len);
		if(!decoded_str_binary_data_n2_information_ext5->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext5]");
			goto end;
		}
	}

	binary_data_n2_information_ext6 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON, "binaryDataN2InformationExt6");
	if(binary_data_n2_information_ext6) {
		decoded_str_binary_data_n2_information_ext6 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext6)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext6]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext6->data =
			base64decode(
				binary_data_n2_information_ext6->valuestring, strlen(
					binary_data_n2_information_ext6->
					valuestring),
				&decoded_str_binary_data_n2_information_ext6->len);
		if(!decoded_str_binary_data_n2_information_ext6->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext6]");
			goto end;
		}
	}

	binary_data_n2_information_ext7 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON, "binaryDataN2InformationExt7");
	if(binary_data_n2_information_ext7) {
		decoded_str_binary_data_n2_information_ext7 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext7)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext7]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext7->data =
			base64decode(
				binary_data_n2_information_ext7->valuestring, strlen(
					binary_data_n2_information_ext7->
					valuestring),
				&decoded_str_binary_data_n2_information_ext7->len);
		if(!decoded_str_binary_data_n2_information_ext7->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext7]");
			goto end;
		}
	}

	binary_data_n2_information_ext8 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON, "binaryDataN2InformationExt8");
	if(binary_data_n2_information_ext8) {
		decoded_str_binary_data_n2_information_ext8 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext8)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext8]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext8->data =
			base64decode(
				binary_data_n2_information_ext8->valuestring, strlen(
					binary_data_n2_information_ext8->
					valuestring),
				&decoded_str_binary_data_n2_information_ext8->len);
		if(!decoded_str_binary_data_n2_information_ext8->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext8]");
			goto end;
		}
	}

	binary_data_n2_information_ext9 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON, "binaryDataN2InformationExt9");
	if(binary_data_n2_information_ext9) {
		decoded_str_binary_data_n2_information_ext9 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext9)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext9]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext9->data =
			base64decode(
				binary_data_n2_information_ext9->valuestring, strlen(
					binary_data_n2_information_ext9->
					valuestring),
				&decoded_str_binary_data_n2_information_ext9->len);
		if(!decoded_str_binary_data_n2_information_ext9->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext9]");
			goto end;
		}
	}

	binary_data_n2_information_ext10 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON,
		"binaryDataN2InformationExt10");
	if(binary_data_n2_information_ext10) {
		decoded_str_binary_data_n2_information_ext10 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext10)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext10]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext10->data =
			base64decode(
				binary_data_n2_information_ext10->valuestring, strlen(
					binary_data_n2_information_ext10->
					valuestring),
				&decoded_str_binary_data_n2_information_ext10->len);
		if(!decoded_str_binary_data_n2_information_ext10->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext10]");
			goto end;
		}
	}

	binary_data_n2_information_ext11 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON,
		"binaryDataN2InformationExt11");
	if(binary_data_n2_information_ext11) {
		decoded_str_binary_data_n2_information_ext11 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext11)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext11]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext11->data =
			base64decode(
				binary_data_n2_information_ext11->valuestring, strlen(
					binary_data_n2_information_ext11->
					valuestring),
				&decoded_str_binary_data_n2_information_ext11->len);
		if(!decoded_str_binary_data_n2_information_ext11->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext11]");
			goto end;
		}
	}

	binary_data_n2_information_ext12 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON,
		"binaryDataN2InformationExt12");
	if(binary_data_n2_information_ext12) {
		decoded_str_binary_data_n2_information_ext12 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext12)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext12]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext12->data =
			base64decode(
				binary_data_n2_information_ext12->valuestring, strlen(
					binary_data_n2_information_ext12->
					valuestring),
				&decoded_str_binary_data_n2_information_ext12->len);
		if(!decoded_str_binary_data_n2_information_ext12->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext12]");
			goto end;
		}
	}

	binary_data_n2_information_ext13 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON,
		"binaryDataN2InformationExt13");
	if(binary_data_n2_information_ext13) {
		decoded_str_binary_data_n2_information_ext13 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext13)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext13]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext13->data =
			base64decode(
				binary_data_n2_information_ext13->valuestring, strlen(
					binary_data_n2_information_ext13->
					valuestring),
				&decoded_str_binary_data_n2_information_ext13->len);
		if(!decoded_str_binary_data_n2_information_ext13->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext13]");
			goto end;
		}
	}

	binary_data_n2_information_ext14 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON,
		"binaryDataN2InformationExt14");
	if(binary_data_n2_information_ext14) {
		decoded_str_binary_data_n2_information_ext14 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext14)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext14]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext14->data =
			base64decode(
				binary_data_n2_information_ext14->valuestring, strlen(
					binary_data_n2_information_ext14->
					valuestring),
				&decoded_str_binary_data_n2_information_ext14->len);
		if(!decoded_str_binary_data_n2_information_ext14->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext14]");
			goto end;
		}
	}

	binary_data_n2_information_ext15 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON,
		"binaryDataN2InformationExt15");
	if(binary_data_n2_information_ext15) {
		decoded_str_binary_data_n2_information_ext15 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext15)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext15]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext15->data =
			base64decode(
				binary_data_n2_information_ext15->valuestring, strlen(
					binary_data_n2_information_ext15->
					valuestring),
				&decoded_str_binary_data_n2_information_ext15->len);
		if(!decoded_str_binary_data_n2_information_ext15->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext15]");
			goto end;
		}
	}

	binary_data_n2_information_ext16 = cJSON_GetObjectItemCaseSensitive(
		relocate_ue_context_requestJSON,
		"binaryDataN2InformationExt16");
	if(binary_data_n2_information_ext16) {
		decoded_str_binary_data_n2_information_ext16 =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information_ext16)) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext16]");
			goto end;
		}
		decoded_str_binary_data_n2_information_ext16->data =
			base64decode(
				binary_data_n2_information_ext16->valuestring, strlen(
					binary_data_n2_information_ext16->
					valuestring),
				&decoded_str_binary_data_n2_information_ext16->len);
		if(!decoded_str_binary_data_n2_information_ext16->data) {
			printf(
				"relocate_ue_context_request_parseFromJSON() failed [binary_data_n2_information_ext16]");
			goto end;
		}
	}

	relocate_ue_context_request_local_var =
		relocate_ue_context_request_create(
			json_data ? json_data_local_nonprim : NULL,
			binary_data_forward_relocation_request ? decoded_str_binary_data_forward_relocation_request : NULL,
			binary_data_n2_information ? decoded_str_binary_data_n2_information : NULL,
			binary_data_n2_information_ext1 ? decoded_str_binary_data_n2_information_ext1 : NULL,
			binary_data_n2_information_ext2 ? decoded_str_binary_data_n2_information_ext2 : NULL,
			binary_data_n2_information_ext3 ? decoded_str_binary_data_n2_information_ext3 : NULL,
			binary_data_n2_information_ext4 ? decoded_str_binary_data_n2_information_ext4 : NULL,
			binary_data_n2_information_ext5 ? decoded_str_binary_data_n2_information_ext5 : NULL,
			binary_data_n2_information_ext6 ? decoded_str_binary_data_n2_information_ext6 : NULL,
			binary_data_n2_information_ext7 ? decoded_str_binary_data_n2_information_ext7 : NULL,
			binary_data_n2_information_ext8 ? decoded_str_binary_data_n2_information_ext8 : NULL,
			binary_data_n2_information_ext9 ? decoded_str_binary_data_n2_information_ext9 : NULL,
			binary_data_n2_information_ext10 ? decoded_str_binary_data_n2_information_ext10 : NULL,
			binary_data_n2_information_ext11 ? decoded_str_binary_data_n2_information_ext11 : NULL,
			binary_data_n2_information_ext12 ? decoded_str_binary_data_n2_information_ext12 : NULL,
			binary_data_n2_information_ext13 ? decoded_str_binary_data_n2_information_ext13 : NULL,
			binary_data_n2_information_ext14 ? decoded_str_binary_data_n2_information_ext14 : NULL,
			binary_data_n2_information_ext15 ? decoded_str_binary_data_n2_information_ext15 : NULL,
			binary_data_n2_information_ext16 ? decoded_str_binary_data_n2_information_ext16 : NULL
			);

	return relocate_ue_context_request_local_var;
end:
	if(json_data_local_nonprim) {
		ue_context_relocate_data_free(json_data_local_nonprim);
		json_data_local_nonprim = NULL;
	}
	return NULL;
}

relocate_ue_context_request_t *relocate_ue_context_request_copy(
	relocate_ue_context_request_t	*dst,
	relocate_ue_context_request_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = relocate_ue_context_request_convertToJSON(src);
	if(!item) {
		printf("relocate_ue_context_request_convertToJSON() failed");
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

	relocate_ue_context_request_free(dst);
	dst = relocate_ue_context_request_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
