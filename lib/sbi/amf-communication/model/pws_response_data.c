#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pws_response_data.h"

char *n2_pws_sub_miss_indpws_response_data_ToString(
	pws_response_data_n2_pws_sub_miss_ind_e n2_pws_sub_miss_ind) {
	const char *n2_pws_sub_miss_indArray[] = { "NULL", "true" };
	size_t sizeofArray = sizeof(n2_pws_sub_miss_indArray) /
	                     sizeof(n2_pws_sub_miss_indArray[0]);
	if(n2_pws_sub_miss_ind < sizeofArray) {
		return (char *) n2_pws_sub_miss_indArray[n2_pws_sub_miss_ind];
	} else {
		return (char *) "Unknown";
	}
}

pws_response_data_n2_pws_sub_miss_ind_e
n2_pws_sub_miss_indpws_response_data_FromString(char *n2_pws_sub_miss_ind) {
	int stringToReturn = 0;
	const char *n2_pws_sub_miss_indArray[] = { "NULL", "true" };
	size_t sizeofArray = sizeof(n2_pws_sub_miss_indArray) /
	                     sizeof(n2_pws_sub_miss_indArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(n2_pws_sub_miss_ind,
		          n2_pws_sub_miss_indArray[stringToReturn]) == 0)
		{
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
pws_response_data_t *pws_response_data_create(
	int					ngap_message_type,
	int					serial_number,
	int					message_identifier,
	list_t					*unknown_tai_list,
	pws_response_data_n2_pws_sub_miss_ind_e n2_pws_sub_miss_ind)
{
	pws_response_data_t *pws_response_data_local_var =
		malloc(sizeof(pws_response_data_t));

	pws_response_data_local_var->ngap_message_type = ngap_message_type;
	pws_response_data_local_var->serial_number = serial_number;
	pws_response_data_local_var->message_identifier = message_identifier;
	pws_response_data_local_var->unknown_tai_list = unknown_tai_list;
	pws_response_data_local_var->n2_pws_sub_miss_ind = n2_pws_sub_miss_ind;

	return pws_response_data_local_var;
}

void pws_response_data_free(pws_response_data_t *pws_response_data) {
	lnode_t *node = NULL;

	if(NULL == pws_response_data) {
		return;
	}
	if(pws_response_data->unknown_tai_list) {
		list_for_each(pws_response_data->unknown_tai_list, node) {
			tai_free(node->data);
		}
		list_free(pws_response_data->unknown_tai_list);
		pws_response_data->unknown_tai_list = NULL;
	}
	free(pws_response_data);
}

cJSON *pws_response_data_convertToJSON(pws_response_data_t *pws_response_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pws_response_data == NULL) {
		printf(
			"pws_response_data_convertToJSON() failed [PWSResponseData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "ngapMessageType",
	                           pws_response_data->ngap_message_type) ==
	   NULL)
	{
		printf(
			"pws_response_data_convertToJSON() failed [ngap_message_type]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "serialNumber",
	                           pws_response_data->serial_number) == NULL)
	{
		printf(
			"pws_response_data_convertToJSON() failed [serial_number]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "messageIdentifier",
	                           pws_response_data->message_identifier) ==
	   NULL)
	{
		printf(
			"pws_response_data_convertToJSON() failed [message_identifier]");
		goto end;
	}

	if(pws_response_data->unknown_tai_list) {
		cJSON *unknown_tai_listList = cJSON_AddArrayToObject(item,
		                                                     "unknownTaiList");
		if(unknown_tai_listList == NULL) {
			printf(
				"pws_response_data_convertToJSON() failed [unknown_tai_list]");
			goto end;
		}
		list_for_each(pws_response_data->unknown_tai_list, node) {
			cJSON *itemLocal = tai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"pws_response_data_convertToJSON() failed [unknown_tai_list]");
				goto end;
			}
			cJSON_AddItemToArray(unknown_tai_listList, itemLocal);
		}
	}

	if(pws_response_data->n2_pws_sub_miss_ind !=
	   pws_response_data_N2PWSSUBMISSIND_NULL)
	{
		if(cJSON_AddStringToObject(item, "n2PwsSubMissInd",
		                           n2_pws_sub_miss_indpws_response_data_ToString(
						   pws_response_data
						   ->
						   n2_pws_sub_miss_ind)) ==
		   NULL)
		{
			printf(
				"pws_response_data_convertToJSON() failed [n2_pws_sub_miss_ind]");
			goto end;
		}
	}

end:
	return item;
}

pws_response_data_t *pws_response_data_parseFromJSON(
	cJSON *pws_response_dataJSON) {
	pws_response_data_t *pws_response_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ngap_message_type = NULL;
	cJSON *serial_number = NULL;
	cJSON *message_identifier = NULL;
	cJSON *unknown_tai_list = NULL;
	list_t *unknown_tai_listList = NULL;
	cJSON *n2_pws_sub_miss_ind = NULL;
	pws_response_data_n2_pws_sub_miss_ind_e n2_pws_sub_miss_indVariable = 0;
	ngap_message_type = cJSON_GetObjectItemCaseSensitive(
		pws_response_dataJSON, "ngapMessageType");
	if(!ngap_message_type) {
		printf(
			"pws_response_data_parseFromJSON() failed [ngap_message_type]");
		goto end;
	}
	if(!cJSON_IsNumber(ngap_message_type)) {
		printf(
			"pws_response_data_parseFromJSON() failed [ngap_message_type]");
		goto end;
	}

	serial_number = cJSON_GetObjectItemCaseSensitive(pws_response_dataJSON,
	                                                 "serialNumber");
	if(!serial_number) {
		printf(
			"pws_response_data_parseFromJSON() failed [serial_number]");
		goto end;
	}
	if(!cJSON_IsNumber(serial_number)) {
		printf(
			"pws_response_data_parseFromJSON() failed [serial_number]");
		goto end;
	}

	message_identifier = cJSON_GetObjectItemCaseSensitive(
		pws_response_dataJSON, "messageIdentifier");
	if(!message_identifier) {
		printf(
			"pws_response_data_parseFromJSON() failed [message_identifier]");
		goto end;
	}
	if(!cJSON_IsNumber(message_identifier)) {
		printf(
			"pws_response_data_parseFromJSON() failed [message_identifier]");
		goto end;
	}

	unknown_tai_list = cJSON_GetObjectItemCaseSensitive(
		pws_response_dataJSON, "unknownTaiList");
	if(unknown_tai_list) {
		cJSON *unknown_tai_list_local = NULL;
		if(!cJSON_IsArray(unknown_tai_list)) {
			printf(
				"pws_response_data_parseFromJSON() failed [unknown_tai_list]");
			goto end;
		}

		unknown_tai_listList = list_create();

		cJSON_ArrayForEach(unknown_tai_list_local, unknown_tai_list) {
			if(!cJSON_IsObject(unknown_tai_list_local)) {
				printf(
					"pws_response_data_parseFromJSON() failed [unknown_tai_list]");
				goto end;
			}
			tai_t *unknown_tai_listItem = tai_parseFromJSON(
				unknown_tai_list_local);
			if(!unknown_tai_listItem) {
				printf("No unknown_tai_listItem");
				goto end;
			}
			list_add(unknown_tai_listList, unknown_tai_listItem);
		}
	}

	n2_pws_sub_miss_ind = cJSON_GetObjectItemCaseSensitive(
		pws_response_dataJSON, "n2PwsSubMissInd");
	if(n2_pws_sub_miss_ind) {
		if(!cJSON_IsString(n2_pws_sub_miss_ind)) {
			printf(
				"pws_response_data_parseFromJSON() failed [n2_pws_sub_miss_ind]");
			goto end;
		}
		n2_pws_sub_miss_indVariable =
			n2_pws_sub_miss_indpws_response_data_FromString(
				n2_pws_sub_miss_ind->valuestring);
	}

	pws_response_data_local_var = pws_response_data_create(

		ngap_message_type->valuedouble,

		serial_number->valuedouble,

		message_identifier->valuedouble,
		unknown_tai_list ? unknown_tai_listList : NULL,
		n2_pws_sub_miss_ind ? n2_pws_sub_miss_indVariable : 0
		);

	return pws_response_data_local_var;
end:
	if(unknown_tai_listList) {
		list_for_each(unknown_tai_listList, node) {
			tai_free(node->data);
		}
		list_free(unknown_tai_listList);
		unknown_tai_listList = NULL;
	}
	return NULL;
}

pws_response_data_t *pws_response_data_copy(pws_response_data_t *dst,
                                            pws_response_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pws_response_data_convertToJSON(src);
	if(!item) {
		printf("pws_response_data_convertToJSON() failed");
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

	pws_response_data_free(dst);
	dst = pws_response_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
