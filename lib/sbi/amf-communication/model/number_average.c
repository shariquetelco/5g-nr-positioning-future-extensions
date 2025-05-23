#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "number_average.h"

number_average_t *number_average_create(float number, float variance,
                                        bool is_skewness, float skewness) {
	number_average_t *number_average_local_var =
		malloc(sizeof(number_average_t));

	number_average_local_var->number = number;
	number_average_local_var->variance = variance;
	number_average_local_var->is_skewness = is_skewness;
	number_average_local_var->skewness = skewness;

	return number_average_local_var;
}

void number_average_free(number_average_t *number_average) {
	lnode_t *node = NULL;

	if(NULL == number_average) {
		return;
	}
	free(number_average);
}

cJSON *number_average_convertToJSON(number_average_t *number_average) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(number_average == NULL) {
		printf("number_average_convertToJSON() failed [NumberAverage]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "number",
	                           number_average->number) == NULL)
	{
		printf("number_average_convertToJSON() failed [number]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "variance",
	                           number_average->variance) == NULL)
	{
		printf("number_average_convertToJSON() failed [variance]");
		goto end;
	}

	if(number_average->is_skewness) {
		if(cJSON_AddNumberToObject(item, "skewness",
		                           number_average->skewness) == NULL)
		{
			printf(
				"number_average_convertToJSON() failed [skewness]");
			goto end;
		}
	}

end:
	return item;
}

number_average_t *number_average_parseFromJSON(cJSON *number_averageJSON) {
	number_average_t *number_average_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *number = NULL;
	cJSON *variance = NULL;
	cJSON *skewness = NULL;
	number = cJSON_GetObjectItemCaseSensitive(number_averageJSON, "number");
	if(!number) {
		printf("number_average_parseFromJSON() failed [number]");
		goto end;
	}
	if(!cJSON_IsNumber(number)) {
		printf("number_average_parseFromJSON() failed [number]");
		goto end;
	}

	variance = cJSON_GetObjectItemCaseSensitive(number_averageJSON,
	                                            "variance");
	if(!variance) {
		printf("number_average_parseFromJSON() failed [variance]");
		goto end;
	}
	if(!cJSON_IsNumber(variance)) {
		printf("number_average_parseFromJSON() failed [variance]");
		goto end;
	}

	skewness = cJSON_GetObjectItemCaseSensitive(number_averageJSON,
	                                            "skewness");
	if(skewness) {
		if(!cJSON_IsNumber(skewness)) {
			printf(
				"number_average_parseFromJSON() failed [skewness]");
			goto end;
		}
	}

	number_average_local_var = number_average_create(

		number->valuedouble,

		variance->valuedouble,
		skewness ? true : false,
		skewness ? skewness->valuedouble : 0
		);

	return number_average_local_var;
end:
	return NULL;
}

number_average_t *number_average_copy(number_average_t	*dst,
                                      number_average_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = number_average_convertToJSON(src);
	if(!item) {
		printf("number_average_convertToJSON() failed");
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

	number_average_free(dst);
	dst = number_average_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
