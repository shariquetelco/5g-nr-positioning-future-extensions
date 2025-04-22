#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "value_expression.h"

value_expression_t *value_expression_create() {
	value_expression_t *value_expression_local_var =
		malloc(sizeof(value_expression_t));


	return value_expression_local_var;
}

void value_expression_free(value_expression_t *value_expression) {
	lnode_t *node = NULL;

	if(NULL == value_expression) {
		return;
	}
	free(value_expression);
}

cJSON *value_expression_convertToJSON(value_expression_t *value_expression) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(value_expression == NULL) {
		printf(
			"value_expression_convertToJSON() failed [ValueExpression]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

value_expression_t *value_expression_parseFromJSON(cJSON *value_expressionJSON)
{
	value_expression_t *value_expression_local_var = NULL;
	lnode_t *node = NULL;
	value_expression_local_var = value_expression_create(
		);

	return value_expression_local_var;
end:
	return NULL;
}

value_expression_t *value_expression_copy(value_expression_t	*dst,
                                          value_expression_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = value_expression_convertToJSON(src);
	if(!item) {
		printf("value_expression_convertToJSON() failed");
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

	value_expression_free(dst);
	dst = value_expression_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
