#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_data_set.h"

ciphering_data_set_t *ciphering_data_set_create(int ciphering_set_id,
                                                char *ciphering_key, char *c0,
                                                char *lte_pos_sib_types,
                                                char *nr_pos_sib_types,
                                                char *validity_start_time,
                                                int validity_duration,
                                                char *tai_list) {
	ciphering_data_set_t *ciphering_data_set_local_var =
		malloc(sizeof(ciphering_data_set_t));

	ciphering_data_set_local_var->ciphering_set_id = ciphering_set_id;
	ciphering_data_set_local_var->ciphering_key = ciphering_key;
	ciphering_data_set_local_var->c0 = c0;
	ciphering_data_set_local_var->lte_pos_sib_types = lte_pos_sib_types;
	ciphering_data_set_local_var->nr_pos_sib_types = nr_pos_sib_types;
	ciphering_data_set_local_var->validity_start_time = validity_start_time;
	ciphering_data_set_local_var->validity_duration = validity_duration;
	ciphering_data_set_local_var->tai_list = tai_list;

	return ciphering_data_set_local_var;
}

void ciphering_data_set_free(ciphering_data_set_t *ciphering_data_set) {
	lnode_t *node = NULL;

	if(NULL == ciphering_data_set) {
		return;
	}
	if(ciphering_data_set->ciphering_key) {
		free(ciphering_data_set->ciphering_key);
		ciphering_data_set->ciphering_key = NULL;
	}
	if(ciphering_data_set->c0) {
		free(ciphering_data_set->c0);
		ciphering_data_set->c0 = NULL;
	}
	if(ciphering_data_set->lte_pos_sib_types) {
		free(ciphering_data_set->lte_pos_sib_types);
		ciphering_data_set->lte_pos_sib_types = NULL;
	}
	if(ciphering_data_set->nr_pos_sib_types) {
		free(ciphering_data_set->nr_pos_sib_types);
		ciphering_data_set->nr_pos_sib_types = NULL;
	}
	if(ciphering_data_set->validity_start_time) {
		free(ciphering_data_set->validity_start_time);
		ciphering_data_set->validity_start_time = NULL;
	}
	if(ciphering_data_set->tai_list) {
		free(ciphering_data_set->tai_list);
		ciphering_data_set->tai_list = NULL;
	}
	free(ciphering_data_set);
}

cJSON *ciphering_data_set_convertToJSON(
	ciphering_data_set_t *ciphering_data_set) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ciphering_data_set == NULL) {
		printf(
			"ciphering_data_set_convertToJSON() failed [CipheringDataSet]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "cipheringSetID",
	                           ciphering_data_set->ciphering_set_id) ==
	   NULL)
	{
		printf(
			"ciphering_data_set_convertToJSON() failed [ciphering_set_id]");
		goto end;
	}

	if(!ciphering_data_set->ciphering_key) {
		printf(
			"ciphering_data_set_convertToJSON() failed [ciphering_key]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "cipheringKey",
	                           ciphering_data_set->ciphering_key) == NULL)
	{
		printf(
			"ciphering_data_set_convertToJSON() failed [ciphering_key]");
		goto end;
	}

	if(!ciphering_data_set->c0) {
		printf("ciphering_data_set_convertToJSON() failed [c0]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "c0",
	                           ciphering_data_set->c0) == NULL)
	{
		printf("ciphering_data_set_convertToJSON() failed [c0]");
		goto end;
	}

	if(ciphering_data_set->lte_pos_sib_types) {
		if(cJSON_AddStringToObject(item, "ltePosSibTypes",
		                           ciphering_data_set->lte_pos_sib_types)
		   == NULL)
		{
			printf(
				"ciphering_data_set_convertToJSON() failed [lte_pos_sib_types]");
			goto end;
		}
	}

	if(ciphering_data_set->nr_pos_sib_types) {
		if(cJSON_AddStringToObject(item, "nrPosSibTypes",
		                           ciphering_data_set->nr_pos_sib_types)
		   == NULL)
		{
			printf(
				"ciphering_data_set_convertToJSON() failed [nr_pos_sib_types]");
			goto end;
		}
	}

	if(!ciphering_data_set->validity_start_time) {
		printf(
			"ciphering_data_set_convertToJSON() failed [validity_start_time]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "validityStartTime",
	                           ciphering_data_set->validity_start_time) ==
	   NULL)
	{
		printf(
			"ciphering_data_set_convertToJSON() failed [validity_start_time]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "validityDuration",
	                           ciphering_data_set->validity_duration) ==
	   NULL)
	{
		printf(
			"ciphering_data_set_convertToJSON() failed [validity_duration]");
		goto end;
	}

	if(ciphering_data_set->tai_list) {
		if(cJSON_AddStringToObject(item, "taiList",
		                           ciphering_data_set->tai_list) ==
		   NULL)
		{
			printf(
				"ciphering_data_set_convertToJSON() failed [tai_list]");
			goto end;
		}
	}

end:
	return item;
}

ciphering_data_set_t *ciphering_data_set_parseFromJSON(
	cJSON *ciphering_data_setJSON) {
	ciphering_data_set_t *ciphering_data_set_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ciphering_set_id = NULL;
	cJSON *ciphering_key = NULL;
	cJSON *c0 = NULL;
	cJSON *lte_pos_sib_types = NULL;
	cJSON *nr_pos_sib_types = NULL;
	cJSON *validity_start_time = NULL;
	cJSON *validity_duration = NULL;
	cJSON *tai_list = NULL;
	ciphering_set_id = cJSON_GetObjectItemCaseSensitive(
		ciphering_data_setJSON, "cipheringSetID");
	if(!ciphering_set_id) {
		printf(
			"ciphering_data_set_parseFromJSON() failed [ciphering_set_id]");
		goto end;
	}
	if(!cJSON_IsNumber(ciphering_set_id)) {
		printf(
			"ciphering_data_set_parseFromJSON() failed [ciphering_set_id]");
		goto end;
	}

	ciphering_key = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON,
	                                                 "cipheringKey");
	if(!ciphering_key) {
		printf(
			"ciphering_data_set_parseFromJSON() failed [ciphering_key]");
		goto end;
	}
	if(!cJSON_IsString(ciphering_key)) {
		printf(
			"ciphering_data_set_parseFromJSON() failed [ciphering_key]");
		goto end;
	}

	c0 = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "c0");
	if(!c0) {
		printf("ciphering_data_set_parseFromJSON() failed [c0]");
		goto end;
	}
	if(!cJSON_IsString(c0)) {
		printf("ciphering_data_set_parseFromJSON() failed [c0]");
		goto end;
	}

	lte_pos_sib_types = cJSON_GetObjectItemCaseSensitive(
		ciphering_data_setJSON, "ltePosSibTypes");
	if(lte_pos_sib_types) {
		if(!cJSON_IsString(lte_pos_sib_types) &&
		   !cJSON_IsNull(lte_pos_sib_types))
		{
			printf(
				"ciphering_data_set_parseFromJSON() failed [lte_pos_sib_types]");
			goto end;
		}
	}

	nr_pos_sib_types = cJSON_GetObjectItemCaseSensitive(
		ciphering_data_setJSON, "nrPosSibTypes");
	if(nr_pos_sib_types) {
		if(!cJSON_IsString(nr_pos_sib_types) &&
		   !cJSON_IsNull(nr_pos_sib_types))
		{
			printf(
				"ciphering_data_set_parseFromJSON() failed [nr_pos_sib_types]");
			goto end;
		}
	}

	validity_start_time = cJSON_GetObjectItemCaseSensitive(
		ciphering_data_setJSON, "validityStartTime");
	if(!validity_start_time) {
		printf(
			"ciphering_data_set_parseFromJSON() failed [validity_start_time]");
		goto end;
	}
	if(!cJSON_IsString(validity_start_time) &&
	   !cJSON_IsNull(validity_start_time))
	{
		printf(
			"ciphering_data_set_parseFromJSON() failed [validity_start_time]");
		goto end;
	}

	validity_duration = cJSON_GetObjectItemCaseSensitive(
		ciphering_data_setJSON, "validityDuration");
	if(!validity_duration) {
		printf(
			"ciphering_data_set_parseFromJSON() failed [validity_duration]");
		goto end;
	}
	if(!cJSON_IsNumber(validity_duration)) {
		printf(
			"ciphering_data_set_parseFromJSON() failed [validity_duration]");
		goto end;
	}

	tai_list = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON,
	                                            "taiList");
	if(tai_list) {
		if(!cJSON_IsString(tai_list) &&
		   !cJSON_IsNull(tai_list))
		{
			printf(
				"ciphering_data_set_parseFromJSON() failed [tai_list]");
			goto end;
		}
	}

	ciphering_data_set_local_var = ciphering_data_set_create(

		ciphering_set_id->valuedouble,
		strdup(ciphering_key->valuestring),
		strdup(c0->valuestring),
		lte_pos_sib_types &&
		!cJSON_IsNull(lte_pos_sib_types) ? strdup(lte_pos_sib_types->
		                                          valuestring) : NULL,
		nr_pos_sib_types &&
		!cJSON_IsNull(nr_pos_sib_types) ? strdup(nr_pos_sib_types->
		                                         valuestring) : NULL,
		strdup(validity_start_time->valuestring),

		validity_duration->valuedouble,
		tai_list &&
		!cJSON_IsNull(tai_list) ? strdup(tai_list->valuestring) : NULL
		);

	return ciphering_data_set_local_var;
end:
	return NULL;
}

ciphering_data_set_t *ciphering_data_set_copy(ciphering_data_set_t	*dst,
                                              ciphering_data_set_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ciphering_data_set_convertToJSON(src);
	if(!item) {
		printf("ciphering_data_set_convertToJSON() failed");
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

	ciphering_data_set_free(dst);
	dst = ciphering_data_set_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
