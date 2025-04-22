#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_data_con_order_crit.h"

user_data_con_order_crit_t *user_data_con_order_crit_create() {
	user_data_con_order_crit_t *user_data_con_order_crit_local_var = malloc(
		sizeof(user_data_con_order_crit_t));


	return user_data_con_order_crit_local_var;
}

void user_data_con_order_crit_free(
	user_data_con_order_crit_t *user_data_con_order_crit) {
	lnode_t *node = NULL;

	if(NULL == user_data_con_order_crit) {
		return;
	}
	free(user_data_con_order_crit);
}

cJSON *user_data_con_order_crit_convertToJSON(
	user_data_con_order_crit_t *user_data_con_order_crit) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(user_data_con_order_crit == NULL) {
		printf(
			"user_data_con_order_crit_convertToJSON() failed [UserDataConOrderCrit]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

user_data_con_order_crit_t *user_data_con_order_crit_parseFromJSON(
	cJSON *user_data_con_order_critJSON) {
	user_data_con_order_crit_t *user_data_con_order_crit_local_var = NULL;
	lnode_t *node = NULL;
	user_data_con_order_crit_local_var = user_data_con_order_crit_create(
		);

	return user_data_con_order_crit_local_var;
end:
	return NULL;
}

user_data_con_order_crit_t *user_data_con_order_crit_copy(
	user_data_con_order_crit_t *dst, user_data_con_order_crit_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = user_data_con_order_crit_convertToJSON(src);
	if(!item) {
		printf("user_data_con_order_crit_convertToJSON() failed");
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

	user_data_con_order_crit_free(dst);
	dst = user_data_con_order_crit_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
