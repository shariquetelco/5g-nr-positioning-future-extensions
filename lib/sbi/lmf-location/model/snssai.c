#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snssai.h"

snssai_t *snssai_create(int sst, char *sd) {
	snssai_t *snssai_local_var = malloc(sizeof(snssai_t));

	snssai_local_var->sst = sst;
	snssai_local_var->sd = sd;

	return snssai_local_var;
}

void snssai_free(snssai_t *snssai) {
	lnode_t *node = NULL;

	if(NULL == snssai) {
		return;
	}
	if(snssai->sd) {
		free(snssai->sd);
		snssai->sd = NULL;
	}
	free(snssai);
}

cJSON *snssai_convertToJSON(snssai_t *snssai) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(snssai == NULL) {
		printf("snssai_convertToJSON() failed [Snssai]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "sst", snssai->sst) == NULL) {
		printf("snssai_convertToJSON() failed [sst]");
		goto end;
	}

	if(snssai->sd) {
		if(cJSON_AddStringToObject(item, "sd", snssai->sd) == NULL) {
			printf("snssai_convertToJSON() failed [sd]");
			goto end;
		}
	}

end:
	return item;
}

snssai_t *snssai_parseFromJSON(cJSON *snssaiJSON) {
	snssai_t *snssai_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *sst = NULL;
	cJSON *sd = NULL;
	sst = cJSON_GetObjectItemCaseSensitive(snssaiJSON, "sst");
	if(!sst) {
		printf("snssai_parseFromJSON() failed [sst]");
		goto end;
	}
	if(!cJSON_IsNumber(sst)) {
		printf("snssai_parseFromJSON() failed [sst]");
		goto end;
	}

	sd = cJSON_GetObjectItemCaseSensitive(snssaiJSON, "sd");
	if(sd) {
		if(!cJSON_IsString(sd) &&
		   !cJSON_IsNull(sd))
		{
			printf("snssai_parseFromJSON() failed [sd]");
			goto end;
		}
	}

	snssai_local_var = snssai_create(

		sst->valuedouble,
		sd &&
		!cJSON_IsNull(sd) ? strdup(sd->valuestring) : NULL
		);

	return snssai_local_var;
end:
	return NULL;
}

snssai_t *snssai_copy(snssai_t *dst, snssai_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = snssai_convertToJSON(src);
	if(!item) {
		printf("snssai_convertToJSON() failed");
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

	snssai_free(dst);
	dst = snssai_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
