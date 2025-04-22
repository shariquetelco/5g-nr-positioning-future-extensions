#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sd_range.h"

sd_range_t *sd_range_create(char *start, char *end) {
	sd_range_t *sd_range_local_var = malloc(sizeof(sd_range_t));

	sd_range_local_var->start = start;
	sd_range_local_var->end = end;

	return sd_range_local_var;
}

void sd_range_free(sd_range_t *sd_range) {
	lnode_t *node = NULL;

	if(NULL == sd_range) {
		return;
	}
	if(sd_range->start) {
		free(sd_range->start);
		sd_range->start = NULL;
	}
	if(sd_range->end) {
		free(sd_range->end);
		sd_range->end = NULL;
	}
	free(sd_range);
}

cJSON *sd_range_convertToJSON(sd_range_t *sd_range) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(sd_range == NULL) {
		printf("sd_range_convertToJSON() failed [SdRange]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(sd_range->start) {
		if(cJSON_AddStringToObject(item, "start",
		                           sd_range->start) == NULL)
		{
			printf("sd_range_convertToJSON() failed [start]");
			goto end;
		}
	}

	if(sd_range->end) {
		if(cJSON_AddStringToObject(item, "end",
		                           sd_range->end) == NULL)
		{
			printf("sd_range_convertToJSON() failed [end]");
			goto end;
		}
	}

end:
	return item;
}

sd_range_t *sd_range_parseFromJSON(cJSON *sd_rangeJSON) {
	sd_range_t *sd_range_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *start = NULL;
	cJSON *end = NULL;
	start = cJSON_GetObjectItemCaseSensitive(sd_rangeJSON, "start");
	if(start) {
		if(!cJSON_IsString(start) &&
		   !cJSON_IsNull(start))
		{
			printf("sd_range_parseFromJSON() failed [start]");
			goto end;
		}
	}

	end = cJSON_GetObjectItemCaseSensitive(sd_rangeJSON, "end");
	if(end) {
		if(!cJSON_IsString(end) &&
		   !cJSON_IsNull(end))
		{
			printf("sd_range_parseFromJSON() failed [end]");
			goto end;
		}
	}

	sd_range_local_var = sd_range_create(
		start &&
		!cJSON_IsNull(start) ? strdup(start->valuestring) : NULL,
		end &&
		!cJSON_IsNull(end) ? strdup(end->valuestring) : NULL
		);

	return sd_range_local_var;
end:
	return NULL;
}

sd_range_t *sd_range_copy(sd_range_t *dst, sd_range_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = sd_range_convertToJSON(src);
	if(!item) {
		printf("sd_range_convertToJSON() failed");
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

	sd_range_free(dst);
	dst = sd_range_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
