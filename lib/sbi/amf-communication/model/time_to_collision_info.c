#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time_to_collision_info.h"

time_to_collision_info_t *time_to_collision_info_create(char	*ttc,
                                                        bool	is_accuracy,
                                                        int	accuracy,
                                                        bool	is_confidence,
                                                        int	confidence) {
	time_to_collision_info_t *time_to_collision_info_local_var = malloc(
		sizeof(time_to_collision_info_t));

	time_to_collision_info_local_var->ttc = ttc;
	time_to_collision_info_local_var->is_accuracy = is_accuracy;
	time_to_collision_info_local_var->accuracy = accuracy;
	time_to_collision_info_local_var->is_confidence = is_confidence;
	time_to_collision_info_local_var->confidence = confidence;

	return time_to_collision_info_local_var;
}

void time_to_collision_info_free(
	time_to_collision_info_t *time_to_collision_info) {
	lnode_t *node = NULL;

	if(NULL == time_to_collision_info) {
		return;
	}
	if(time_to_collision_info->ttc) {
		free(time_to_collision_info->ttc);
		time_to_collision_info->ttc = NULL;
	}
	free(time_to_collision_info);
}

cJSON *time_to_collision_info_convertToJSON(
	time_to_collision_info_t *time_to_collision_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(time_to_collision_info == NULL) {
		printf(
			"time_to_collision_info_convertToJSON() failed [TimeToCollisionInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(time_to_collision_info->ttc) {
		if(cJSON_AddStringToObject(item, "ttc",
		                           time_to_collision_info->ttc) == NULL)
		{
			printf(
				"time_to_collision_info_convertToJSON() failed [ttc]");
			goto end;
		}
	}

	if(time_to_collision_info->is_accuracy) {
		if(cJSON_AddNumberToObject(item, "accuracy",
		                           time_to_collision_info->accuracy) ==
		   NULL)
		{
			printf(
				"time_to_collision_info_convertToJSON() failed [accuracy]");
			goto end;
		}
	}

	if(time_to_collision_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           time_to_collision_info->confidence)
		   == NULL)
		{
			printf(
				"time_to_collision_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

end:
	return item;
}

time_to_collision_info_t *time_to_collision_info_parseFromJSON(
	cJSON *time_to_collision_infoJSON) {
	time_to_collision_info_t *time_to_collision_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ttc = NULL;
	cJSON *accuracy = NULL;
	cJSON *confidence = NULL;
	ttc =
		cJSON_GetObjectItemCaseSensitive(time_to_collision_infoJSON,
		                                 "ttc");
	if(ttc) {
		if(!cJSON_IsString(ttc) &&
		   !cJSON_IsNull(ttc))
		{
			printf(
				"time_to_collision_info_parseFromJSON() failed [ttc]");
			goto end;
		}
	}

	accuracy = cJSON_GetObjectItemCaseSensitive(time_to_collision_infoJSON,
	                                            "accuracy");
	if(accuracy) {
		if(!cJSON_IsNumber(accuracy)) {
			printf(
				"time_to_collision_info_parseFromJSON() failed [accuracy]");
			goto end;
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(
		time_to_collision_infoJSON, "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"time_to_collision_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	time_to_collision_info_local_var = time_to_collision_info_create(
		ttc &&
		!cJSON_IsNull(ttc) ? strdup(ttc->valuestring) : NULL,
		accuracy ? true : false,
		accuracy ? accuracy->valuedouble : 0,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0
		);

	return time_to_collision_info_local_var;
end:
	return NULL;
}

time_to_collision_info_t *time_to_collision_info_copy(
	time_to_collision_info_t *dst, time_to_collision_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = time_to_collision_info_convertToJSON(src);
	if(!item) {
		printf("time_to_collision_info_convertToJSON() failed");
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

	time_to_collision_info_free(dst);
	dst = time_to_collision_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
