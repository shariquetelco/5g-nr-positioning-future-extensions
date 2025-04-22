#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_measurements.h"

loc_measurements_t *loc_measurements_create(bool is_rstd, int rstd) {
	loc_measurements_t *loc_measurements_local_var =
		malloc(sizeof(loc_measurements_t));

	loc_measurements_local_var->is_rstd = is_rstd;
	loc_measurements_local_var->rstd = rstd;

	return loc_measurements_local_var;
}

void loc_measurements_free(loc_measurements_t *loc_measurements) {
	lnode_t *node = NULL;

	if(NULL == loc_measurements) {
		return;
	}
	free(loc_measurements);
}

cJSON *loc_measurements_convertToJSON(loc_measurements_t *loc_measurements) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(loc_measurements == NULL) {
		printf(
			"loc_measurements_convertToJSON() failed [LocMeasurements]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(loc_measurements->is_rstd) {
		if(cJSON_AddNumberToObject(item, "rstd",
		                           loc_measurements->rstd) == NULL)
		{
			printf("loc_measurements_convertToJSON() failed [rstd]");
			goto end;
		}
	}

end:
	return item;
}

loc_measurements_t *loc_measurements_parseFromJSON(cJSON *loc_measurementsJSON)
{
	loc_measurements_t *loc_measurements_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *rstd = NULL;
	rstd = cJSON_GetObjectItemCaseSensitive(loc_measurementsJSON, "rstd");
	if(rstd) {
		if(!cJSON_IsNumber(rstd)) {
			printf("loc_measurements_parseFromJSON() failed [rstd]");
			goto end;
		}
	}

	loc_measurements_local_var = loc_measurements_create(
		rstd ? true : false,
		rstd ? rstd->valuedouble : 0
		);

	return loc_measurements_local_var;
end:
	return NULL;
}

loc_measurements_t *loc_measurements_copy(loc_measurements_t	*dst,
                                          loc_measurements_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = loc_measurements_convertToJSON(src);
	if(!item) {
		printf("loc_measurements_convertToJSON() failed");
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

	loc_measurements_free(dst);
	dst = loc_measurements_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
