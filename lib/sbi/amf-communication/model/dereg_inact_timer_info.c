#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dereg_inact_timer_info.h"

dereg_inact_timer_info_t *dereg_inact_timer_info_create(
	nssaa_status_t *dereg_inact_expiry_time) {
	dereg_inact_timer_info_t *dereg_inact_timer_info_local_var = malloc(
		sizeof(dereg_inact_timer_info_t));

	dereg_inact_timer_info_local_var->dereg_inact_expiry_time =
		dereg_inact_expiry_time;

	return dereg_inact_timer_info_local_var;
}

void dereg_inact_timer_info_free(
	dereg_inact_timer_info_t *dereg_inact_timer_info) {
	lnode_t *node = NULL;

	if(NULL == dereg_inact_timer_info) {
		return;
	}
	if(dereg_inact_timer_info->dereg_inact_expiry_time) {
		nssaa_status_free(
			dereg_inact_timer_info->dereg_inact_expiry_time);
		dereg_inact_timer_info->dereg_inact_expiry_time = NULL;
	}
	free(dereg_inact_timer_info);
}

cJSON *dereg_inact_timer_info_convertToJSON(
	dereg_inact_timer_info_t *dereg_inact_timer_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dereg_inact_timer_info == NULL) {
		printf(
			"dereg_inact_timer_info_convertToJSON() failed [DeregInactTimerInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!dereg_inact_timer_info->dereg_inact_expiry_time) {
		printf(
			"dereg_inact_timer_info_convertToJSON() failed [dereg_inact_expiry_time]");
		return NULL;
	}
	cJSON *dereg_inact_expiry_time_local_JSON = nssaa_status_convertToJSON(
		dereg_inact_timer_info->dereg_inact_expiry_time);
	if(dereg_inact_expiry_time_local_JSON == NULL) {
		printf(
			"dereg_inact_timer_info_convertToJSON() failed [dereg_inact_expiry_time]");
		goto end;
	}
	cJSON_AddItemToObject(item, "deregInactExpiryTime",
	                      dereg_inact_expiry_time_local_JSON);
	if(item->child == NULL) {
		printf(
			"dereg_inact_timer_info_convertToJSON() failed [dereg_inact_expiry_time]");
		goto end;
	}

end:
	return item;
}

dereg_inact_timer_info_t *dereg_inact_timer_info_parseFromJSON(
	cJSON *dereg_inact_timer_infoJSON) {
	dereg_inact_timer_info_t *dereg_inact_timer_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *dereg_inact_expiry_time = NULL;
	nssaa_status_t *dereg_inact_expiry_time_local_nonprim = NULL;
	dereg_inact_expiry_time = cJSON_GetObjectItemCaseSensitive(
		dereg_inact_timer_infoJSON, "deregInactExpiryTime");
	if(!dereg_inact_expiry_time) {
		printf(
			"dereg_inact_timer_info_parseFromJSON() failed [dereg_inact_expiry_time]");
		goto end;
	}
	dereg_inact_expiry_time_local_nonprim = nssaa_status_parseFromJSON(
		dereg_inact_expiry_time);
	if(!dereg_inact_expiry_time_local_nonprim) {
		printf(
			"nssaa_status_parseFromJSON failed [dereg_inact_expiry_time]");
		goto end;
	}

	dereg_inact_timer_info_local_var = dereg_inact_timer_info_create(
		dereg_inact_expiry_time_local_nonprim
		);

	return dereg_inact_timer_info_local_var;
end:
	if(dereg_inact_expiry_time_local_nonprim) {
		nssaa_status_free(dereg_inact_expiry_time_local_nonprim);
		dereg_inact_expiry_time_local_nonprim = NULL;
	}
	return NULL;
}

dereg_inact_timer_info_t *dereg_inact_timer_info_copy(
	dereg_inact_timer_info_t *dst, dereg_inact_timer_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dereg_inact_timer_info_convertToJSON(src);
	if(!item) {
		printf("dereg_inact_timer_info_convertToJSON() failed");
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

	dereg_inact_timer_info_free(dst);
	dst = dereg_inact_timer_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
