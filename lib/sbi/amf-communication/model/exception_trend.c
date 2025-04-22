#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "exception_trend.h"

exception_trend_t *exception_trend_create() {
	exception_trend_t *exception_trend_local_var =
		malloc(sizeof(exception_trend_t));


	return exception_trend_local_var;
}

void exception_trend_free(exception_trend_t *exception_trend) {
	lnode_t *node = NULL;

	if(NULL == exception_trend) {
		return;
	}
	free(exception_trend);
}

cJSON *exception_trend_convertToJSON(exception_trend_t *exception_trend) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(exception_trend == NULL) {
		printf("exception_trend_convertToJSON() failed [ExceptionTrend]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

exception_trend_t *exception_trend_parseFromJSON(cJSON *exception_trendJSON) {
	exception_trend_t *exception_trend_local_var = NULL;
	lnode_t *node = NULL;
	exception_trend_local_var = exception_trend_create(
		);

	return exception_trend_local_var;
end:
	return NULL;
}

exception_trend_t *exception_trend_copy(exception_trend_t	*dst,
                                        exception_trend_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = exception_trend_convertToJSON(src);
	if(!item) {
		printf("exception_trend_convertToJSON() failed");
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

	exception_trend_free(dst);
	dst = exception_trend_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
