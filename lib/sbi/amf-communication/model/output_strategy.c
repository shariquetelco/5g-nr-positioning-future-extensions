#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "output_strategy.h"

output_strategy_t *output_strategy_create() {
	output_strategy_t *output_strategy_local_var =
		malloc(sizeof(output_strategy_t));


	return output_strategy_local_var;
}

void output_strategy_free(output_strategy_t *output_strategy) {
	lnode_t *node = NULL;

	if(NULL == output_strategy) {
		return;
	}
	free(output_strategy);
}

cJSON *output_strategy_convertToJSON(output_strategy_t *output_strategy) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(output_strategy == NULL) {
		printf("output_strategy_convertToJSON() failed [OutputStrategy]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

output_strategy_t *output_strategy_parseFromJSON(cJSON *output_strategyJSON) {
	output_strategy_t *output_strategy_local_var = NULL;
	lnode_t *node = NULL;
	output_strategy_local_var = output_strategy_create(
		);

	return output_strategy_local_var;
end:
	return NULL;
}

output_strategy_t *output_strategy_copy(output_strategy_t	*dst,
                                        output_strategy_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = output_strategy_convertToJSON(src);
	if(!item) {
		printf("output_strategy_convertToJSON() failed");
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

	output_strategy_free(dst);
	dst = output_strategy_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
