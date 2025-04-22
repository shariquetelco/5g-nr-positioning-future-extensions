#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gnb_id.h"

gnb_id_t *gnb_id_create(int bit_length, char *g_nb_value) {
	gnb_id_t *gnb_id_local_var = malloc(sizeof(gnb_id_t));

	gnb_id_local_var->bit_length = bit_length;
	gnb_id_local_var->g_nb_value = g_nb_value;

	return gnb_id_local_var;
}

void gnb_id_free(gnb_id_t *gnb_id) {
	lnode_t *node = NULL;

	if(NULL == gnb_id) {
		return;
	}
	if(gnb_id->g_nb_value) {
		free(gnb_id->g_nb_value);
		gnb_id->g_nb_value = NULL;
	}
	free(gnb_id);
}

cJSON *gnb_id_convertToJSON(gnb_id_t *gnb_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(gnb_id == NULL) {
		printf("gnb_id_convertToJSON() failed [GNbId]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "bitLength",
	                           gnb_id->bit_length) == NULL)
	{
		printf("gnb_id_convertToJSON() failed [bit_length]");
		goto end;
	}

	if(!gnb_id->g_nb_value) {
		printf("gnb_id_convertToJSON() failed [g_nb_value]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "gNBValue",
	                           gnb_id->g_nb_value) == NULL)
	{
		printf("gnb_id_convertToJSON() failed [g_nb_value]");
		goto end;
	}

end:
	return item;
}

gnb_id_t *gnb_id_parseFromJSON(cJSON *gnb_idJSON) {
	gnb_id_t *gnb_id_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *bit_length = NULL;
	cJSON *g_nb_value = NULL;
	bit_length = cJSON_GetObjectItemCaseSensitive(gnb_idJSON, "bitLength");
	if(!bit_length) {
		printf("gnb_id_parseFromJSON() failed [bit_length]");
		goto end;
	}
	if(!cJSON_IsNumber(bit_length)) {
		printf("gnb_id_parseFromJSON() failed [bit_length]");
		goto end;
	}

	g_nb_value = cJSON_GetObjectItemCaseSensitive(gnb_idJSON, "gNBValue");
	if(!g_nb_value) {
		printf("gnb_id_parseFromJSON() failed [g_nb_value]");
		goto end;
	}
	if(!cJSON_IsString(g_nb_value)) {
		printf("gnb_id_parseFromJSON() failed [g_nb_value]");
		goto end;
	}

	gnb_id_local_var = gnb_id_create(

		bit_length->valuedouble,
		strdup(g_nb_value->valuestring)
		);

	return gnb_id_local_var;
end:
	return NULL;
}

gnb_id_t *gnb_id_copy(gnb_id_t *dst, gnb_id_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = gnb_id_convertToJSON(src);
	if(!item) {
		printf("gnb_id_convertToJSON() failed");
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

	gnb_id_free(dst);
	dst = gnb_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
