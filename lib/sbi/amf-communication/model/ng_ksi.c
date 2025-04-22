#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ng_ksi.h"

ng_ksi_t *ng_ksi_create(sc_type_e tsc, int ksi) {
	ng_ksi_t *ng_ksi_local_var = malloc(sizeof(ng_ksi_t));

	ng_ksi_local_var->tsc = tsc;
	ng_ksi_local_var->ksi = ksi;

	return ng_ksi_local_var;
}

void ng_ksi_free(ng_ksi_t *ng_ksi) {
	lnode_t *node = NULL;

	if(NULL == ng_ksi) {
		return;
	}
	free(ng_ksi);
}

cJSON *ng_ksi_convertToJSON(ng_ksi_t *ng_ksi) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ng_ksi == NULL) {
		printf("ng_ksi_convertToJSON() failed [NgKsi]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ng_ksi->tsc == sc_type_NULL) {
		printf("ng_ksi_convertToJSON() failed [tsc]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "tsc",
	                           sc_type_ToString(ng_ksi->tsc)) == NULL)
	{
		printf("ng_ksi_convertToJSON() failed [tsc]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "ksi", ng_ksi->ksi) == NULL) {
		printf("ng_ksi_convertToJSON() failed [ksi]");
		goto end;
	}

end:
	return item;
}

ng_ksi_t *ng_ksi_parseFromJSON(cJSON *ng_ksiJSON) {
	ng_ksi_t *ng_ksi_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *tsc = NULL;
	sc_type_e tscVariable = 0;
	cJSON *ksi = NULL;
	tsc = cJSON_GetObjectItemCaseSensitive(ng_ksiJSON, "tsc");
	if(!tsc) {
		printf("ng_ksi_parseFromJSON() failed [tsc]");
		goto end;
	}
	if(!cJSON_IsString(tsc)) {
		printf("ng_ksi_parseFromJSON() failed [tsc]");
		goto end;
	}
	tscVariable = sc_type_FromString(tsc->valuestring);

	ksi = cJSON_GetObjectItemCaseSensitive(ng_ksiJSON, "ksi");
	if(!ksi) {
		printf("ng_ksi_parseFromJSON() failed [ksi]");
		goto end;
	}
	if(!cJSON_IsNumber(ksi)) {
		printf("ng_ksi_parseFromJSON() failed [ksi]");
		goto end;
	}

	ng_ksi_local_var = ng_ksi_create(
		tscVariable,

		ksi->valuedouble
		);

	return ng_ksi_local_var;
end:
	return NULL;
}

ng_ksi_t *ng_ksi_copy(ng_ksi_t *dst, ng_ksi_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ng_ksi_convertToJSON(src);
	if(!item) {
		printf("ng_ksi_convertToJSON() failed");
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

	ng_ksi_free(dst);
	dst = ng_ksi_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
