#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "alert_limit.h"

alert_limit_t *alert_limit_create(int	horizontal_protection_level,
                                  bool	is_vertical_protection_level,
                                  int	vertical_protection_level) {
	alert_limit_t *alert_limit_local_var = malloc(sizeof(alert_limit_t));

	alert_limit_local_var->horizontal_protection_level =
		horizontal_protection_level;
	alert_limit_local_var->is_vertical_protection_level =
		is_vertical_protection_level;
	alert_limit_local_var->vertical_protection_level =
		vertical_protection_level;

	return alert_limit_local_var;
}

void alert_limit_free(alert_limit_t *alert_limit) {
	lnode_t *node = NULL;

	if(NULL == alert_limit) {
		return;
	}
	free(alert_limit);
}

cJSON *alert_limit_convertToJSON(alert_limit_t *alert_limit) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(alert_limit == NULL) {
		printf("alert_limit_convertToJSON() failed [AlertLimit]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "horizontalProtectionLevel",
	                           alert_limit->horizontal_protection_level) ==
	   NULL)
	{
		printf(
			"alert_limit_convertToJSON() failed [horizontal_protection_level]");
		goto end;
	}

	if(alert_limit->is_vertical_protection_level) {
		if(cJSON_AddNumberToObject(item, "verticalProtectionLevel",
		                           alert_limit->
		                           vertical_protection_level) == NULL)
		{
			printf(
				"alert_limit_convertToJSON() failed [vertical_protection_level]");
			goto end;
		}
	}

end:
	return item;
}

alert_limit_t *alert_limit_parseFromJSON(cJSON *alert_limitJSON) {
	alert_limit_t *alert_limit_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *horizontal_protection_level = NULL;
	cJSON *vertical_protection_level = NULL;
	horizontal_protection_level = cJSON_GetObjectItemCaseSensitive(
		alert_limitJSON, "horizontalProtectionLevel");
	if(!horizontal_protection_level) {
		printf(
			"alert_limit_parseFromJSON() failed [horizontal_protection_level]");
		goto end;
	}
	if(!cJSON_IsNumber(horizontal_protection_level)) {
		printf(
			"alert_limit_parseFromJSON() failed [horizontal_protection_level]");
		goto end;
	}

	vertical_protection_level = cJSON_GetObjectItemCaseSensitive(
		alert_limitJSON, "verticalProtectionLevel");
	if(vertical_protection_level) {
		if(!cJSON_IsNumber(vertical_protection_level)) {
			printf(
				"alert_limit_parseFromJSON() failed [vertical_protection_level]");
			goto end;
		}
	}

	alert_limit_local_var = alert_limit_create(

		horizontal_protection_level->valuedouble,
		vertical_protection_level ? true : false,
		vertical_protection_level ? vertical_protection_level->valuedouble : 0
		);

	return alert_limit_local_var;
end:
	return NULL;
}

alert_limit_t *alert_limit_copy(alert_limit_t *dst, alert_limit_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = alert_limit_convertToJSON(src);
	if(!item) {
		printf("alert_limit_convertToJSON() failed");
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

	alert_limit_free(dst);
	dst = alert_limit_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
