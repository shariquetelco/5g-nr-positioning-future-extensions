#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mo_exp_data_counter.h"

mo_exp_data_counter_t *mo_exp_data_counter_create(int	counter,
                                                  char	*time_stamp) {
	mo_exp_data_counter_t *mo_exp_data_counter_local_var =
		malloc(sizeof(mo_exp_data_counter_t));

	mo_exp_data_counter_local_var->counter = counter;
	mo_exp_data_counter_local_var->time_stamp = time_stamp;

	return mo_exp_data_counter_local_var;
}

void mo_exp_data_counter_free(mo_exp_data_counter_t *mo_exp_data_counter) {
	lnode_t *node = NULL;

	if(NULL == mo_exp_data_counter) {
		return;
	}
	if(mo_exp_data_counter->time_stamp) {
		free(mo_exp_data_counter->time_stamp);
		mo_exp_data_counter->time_stamp = NULL;
	}
	free(mo_exp_data_counter);
}

cJSON *mo_exp_data_counter_convertToJSON(
	mo_exp_data_counter_t *mo_exp_data_counter) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(mo_exp_data_counter == NULL) {
		printf(
			"mo_exp_data_counter_convertToJSON() failed [MoExpDataCounter]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "counter",
	                           mo_exp_data_counter->counter) == NULL)
	{
		printf("mo_exp_data_counter_convertToJSON() failed [counter]");
		goto end;
	}

	if(mo_exp_data_counter->time_stamp) {
		if(cJSON_AddStringToObject(item, "timeStamp",
		                           mo_exp_data_counter->time_stamp) ==
		   NULL)
		{
			printf(
				"mo_exp_data_counter_convertToJSON() failed [time_stamp]");
			goto end;
		}
	}

end:
	return item;
}

mo_exp_data_counter_t *mo_exp_data_counter_parseFromJSON(
	cJSON *mo_exp_data_counterJSON) {
	mo_exp_data_counter_t *mo_exp_data_counter_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *counter = NULL;
	cJSON *time_stamp = NULL;
	counter = cJSON_GetObjectItemCaseSensitive(mo_exp_data_counterJSON,
	                                           "counter");
	if(!counter) {
		printf("mo_exp_data_counter_parseFromJSON() failed [counter]");
		goto end;
	}
	if(!cJSON_IsNumber(counter)) {
		printf("mo_exp_data_counter_parseFromJSON() failed [counter]");
		goto end;
	}

	time_stamp = cJSON_GetObjectItemCaseSensitive(mo_exp_data_counterJSON,
	                                              "timeStamp");
	if(time_stamp) {
		if(!cJSON_IsString(time_stamp) &&
		   !cJSON_IsNull(time_stamp))
		{
			printf(
				"mo_exp_data_counter_parseFromJSON() failed [time_stamp]");
			goto end;
		}
	}

	mo_exp_data_counter_local_var = mo_exp_data_counter_create(

		counter->valuedouble,
		time_stamp &&
		!cJSON_IsNull(time_stamp) ? strdup(
			time_stamp->valuestring) : NULL
		);

	return mo_exp_data_counter_local_var;
end:
	return NULL;
}

mo_exp_data_counter_t *mo_exp_data_counter_copy(mo_exp_data_counter_t	*dst,
                                                mo_exp_data_counter_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = mo_exp_data_counter_convertToJSON(src);
	if(!item) {
		printf("mo_exp_data_counter_convertToJSON() failed");
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

	mo_exp_data_counter_free(dst);
	dst = mo_exp_data_counter_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
