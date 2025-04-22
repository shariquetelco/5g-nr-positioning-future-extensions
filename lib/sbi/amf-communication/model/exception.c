#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "exception.h"

exception_t *exception_create(exception_id_t *excep_id, bool is_excep_level,
                              int excep_level, exception_trend_t *excep_trend) {
	exception_t *exception_local_var = malloc(sizeof(exception_t));

	exception_local_var->excep_id = excep_id;
	exception_local_var->is_excep_level = is_excep_level;
	exception_local_var->excep_level = excep_level;
	exception_local_var->excep_trend = excep_trend;

	return exception_local_var;
}

void exception_free(exception_t *exception) {
	lnode_t *node = NULL;

	if(NULL == exception) {
		return;
	}
	if(exception->excep_id) {
		exception_id_free(exception->excep_id);
		exception->excep_id = NULL;
	}
	if(exception->excep_trend) {
		exception_trend_free(exception->excep_trend);
		exception->excep_trend = NULL;
	}
	free(exception);
}

cJSON *exception_convertToJSON(exception_t *exception) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(exception == NULL) {
		printf("exception_convertToJSON() failed [Exception]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!exception->excep_id) {
		printf("exception_convertToJSON() failed [excep_id]");
		return NULL;
	}
	cJSON *excep_id_local_JSON = exception_id_convertToJSON(
		exception->excep_id);
	if(excep_id_local_JSON == NULL) {
		printf("exception_convertToJSON() failed [excep_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "excepId", excep_id_local_JSON);
	if(item->child == NULL) {
		printf("exception_convertToJSON() failed [excep_id]");
		goto end;
	}

	if(exception->is_excep_level) {
		if(cJSON_AddNumberToObject(item, "excepLevel",
		                           exception->excep_level) == NULL)
		{
			printf("exception_convertToJSON() failed [excep_level]");
			goto end;
		}
	}

	if(exception->excep_trend) {
		cJSON *excep_trend_local_JSON = exception_trend_convertToJSON(
			exception->excep_trend);
		if(excep_trend_local_JSON == NULL) {
			printf("exception_convertToJSON() failed [excep_trend]");
			goto end;
		}
		cJSON_AddItemToObject(item, "excepTrend",
		                      excep_trend_local_JSON);
		if(item->child == NULL) {
			printf("exception_convertToJSON() failed [excep_trend]");
			goto end;
		}
	}

end:
	return item;
}

exception_t *exception_parseFromJSON(cJSON *exceptionJSON) {
	exception_t *exception_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *excep_id = NULL;
	exception_id_t *excep_id_local_nonprim = NULL;
	cJSON *excep_level = NULL;
	cJSON *excep_trend = NULL;
	exception_trend_t *excep_trend_local_nonprim = NULL;
	excep_id = cJSON_GetObjectItemCaseSensitive(exceptionJSON, "excepId");
	if(!excep_id) {
		printf("exception_parseFromJSON() failed [excep_id]");
		goto end;
	}
	excep_id_local_nonprim = exception_id_parseFromJSON(excep_id);
	if(!excep_id_local_nonprim) {
		printf("exception_id_parseFromJSON failed [excep_id]");
		goto end;
	}

	excep_level = cJSON_GetObjectItemCaseSensitive(exceptionJSON,
	                                               "excepLevel");
	if(excep_level) {
		if(!cJSON_IsNumber(excep_level)) {
			printf("exception_parseFromJSON() failed [excep_level]");
			goto end;
		}
	}

	excep_trend = cJSON_GetObjectItemCaseSensitive(exceptionJSON,
	                                               "excepTrend");
	if(excep_trend) {
		excep_trend_local_nonprim = exception_trend_parseFromJSON(
			excep_trend);
		if(!excep_trend_local_nonprim) {
			printf(
				"exception_trend_parseFromJSON failed [excep_trend]");
			goto end;
		}
	}

	exception_local_var = exception_create(
		excep_id_local_nonprim,
		excep_level ? true : false,
		excep_level ? excep_level->valuedouble : 0,
		excep_trend ? excep_trend_local_nonprim : NULL
		);

	return exception_local_var;
end:
	if(excep_id_local_nonprim) {
		exception_id_free(excep_id_local_nonprim);
		excep_id_local_nonprim = NULL;
	}
	if(excep_trend_local_nonprim) {
		exception_trend_free(excep_trend_local_nonprim);
		excep_trend_local_nonprim = NULL;
	}
	return NULL;
}

exception_t *exception_copy(exception_t *dst, exception_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = exception_convertToJSON(src);
	if(!item) {
		printf("exception_convertToJSON() failed");
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

	exception_free(dst);
	dst = exception_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
