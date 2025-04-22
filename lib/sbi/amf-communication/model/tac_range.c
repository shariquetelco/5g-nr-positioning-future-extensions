#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tac_range.h"

tac_range_t *tac_range_create(char *start, char *end, char *pattern) {
	tac_range_t *tac_range_local_var = malloc(sizeof(tac_range_t));

	tac_range_local_var->start = start;
	tac_range_local_var->end = end;
	tac_range_local_var->pattern = pattern;

	return tac_range_local_var;
}

void tac_range_free(tac_range_t *tac_range) {
	lnode_t *node = NULL;

	if(NULL == tac_range) {
		return;
	}
	if(tac_range->start) {
		free(tac_range->start);
		tac_range->start = NULL;
	}
	if(tac_range->end) {
		free(tac_range->end);
		tac_range->end = NULL;
	}
	if(tac_range->pattern) {
		free(tac_range->pattern);
		tac_range->pattern = NULL;
	}
	free(tac_range);
}

cJSON *tac_range_convertToJSON(tac_range_t *tac_range) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(tac_range == NULL) {
		printf("tac_range_convertToJSON() failed [TacRange]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(tac_range->start) {
		if(cJSON_AddStringToObject(item, "start",
		                           tac_range->start) == NULL)
		{
			printf("tac_range_convertToJSON() failed [start]");
			goto end;
		}
	}

	if(tac_range->end) {
		if(cJSON_AddStringToObject(item, "end",
		                           tac_range->end) == NULL)
		{
			printf("tac_range_convertToJSON() failed [end]");
			goto end;
		}
	}

	if(tac_range->pattern) {
		if(cJSON_AddStringToObject(item, "pattern",
		                           tac_range->pattern) == NULL)
		{
			printf("tac_range_convertToJSON() failed [pattern]");
			goto end;
		}
	}

end:
	return item;
}

tac_range_t *tac_range_parseFromJSON(cJSON *tac_rangeJSON) {
	tac_range_t *tac_range_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *start = NULL;
	cJSON *end = NULL;
	cJSON *pattern = NULL;
	start = cJSON_GetObjectItemCaseSensitive(tac_rangeJSON, "start");
	if(start) {
		if(!cJSON_IsString(start) &&
		   !cJSON_IsNull(start))
		{
			printf("tac_range_parseFromJSON() failed [start]");
			goto end;
		}
	}

	end = cJSON_GetObjectItemCaseSensitive(tac_rangeJSON, "end");
	if(end) {
		if(!cJSON_IsString(end) &&
		   !cJSON_IsNull(end))
		{
			printf("tac_range_parseFromJSON() failed [end]");
			goto end;
		}
	}

	pattern = cJSON_GetObjectItemCaseSensitive(tac_rangeJSON, "pattern");
	if(pattern) {
		if(!cJSON_IsString(pattern) &&
		   !cJSON_IsNull(pattern))
		{
			printf("tac_range_parseFromJSON() failed [pattern]");
			goto end;
		}
	}

	tac_range_local_var = tac_range_create(
		start &&
		!cJSON_IsNull(start) ? strdup(start->valuestring) : NULL,
		end &&
		!cJSON_IsNull(end) ? strdup(end->valuestring) : NULL,
		pattern &&
		!cJSON_IsNull(pattern) ? strdup(pattern->valuestring) : NULL
		);

	return tac_range_local_var;
end:
	return NULL;
}

tac_range_t *tac_range_copy(tac_range_t *dst, tac_range_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = tac_range_convertToJSON(src);
	if(!item) {
		printf("tac_range_convertToJSON() failed");
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

	tac_range_free(dst);
	dst = tac_range_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
