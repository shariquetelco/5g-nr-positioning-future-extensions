#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "speed_threshold_info.h"

speed_threshold_info_t *speed_threshold_info_create(bool is_num_of_ue,
                                                    int num_of_ue,
                                                    bool is_ratio, int ratio) {
	speed_threshold_info_t *speed_threshold_info_local_var =
		malloc(sizeof(speed_threshold_info_t));

	speed_threshold_info_local_var->is_num_of_ue = is_num_of_ue;
	speed_threshold_info_local_var->num_of_ue = num_of_ue;
	speed_threshold_info_local_var->is_ratio = is_ratio;
	speed_threshold_info_local_var->ratio = ratio;

	return speed_threshold_info_local_var;
}

void speed_threshold_info_free(speed_threshold_info_t *speed_threshold_info) {
	lnode_t *node = NULL;

	if(NULL == speed_threshold_info) {
		return;
	}
	free(speed_threshold_info);
}

cJSON *speed_threshold_info_convertToJSON(
	speed_threshold_info_t *speed_threshold_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(speed_threshold_info == NULL) {
		printf(
			"speed_threshold_info_convertToJSON() failed [SpeedThresholdInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(speed_threshold_info->is_num_of_ue) {
		if(cJSON_AddNumberToObject(item, "numOfUe",
		                           speed_threshold_info->num_of_ue) ==
		   NULL)
		{
			printf(
				"speed_threshold_info_convertToJSON() failed [num_of_ue]");
			goto end;
		}
	}

	if(speed_threshold_info->is_ratio) {
		if(cJSON_AddNumberToObject(item, "ratio",
		                           speed_threshold_info->ratio) == NULL)
		{
			printf(
				"speed_threshold_info_convertToJSON() failed [ratio]");
			goto end;
		}
	}

end:
	return item;
}

speed_threshold_info_t *speed_threshold_info_parseFromJSON(
	cJSON *speed_threshold_infoJSON) {
	speed_threshold_info_t *speed_threshold_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *num_of_ue = NULL;
	cJSON *ratio = NULL;
	num_of_ue = cJSON_GetObjectItemCaseSensitive(speed_threshold_infoJSON,
	                                             "numOfUe");
	if(num_of_ue) {
		if(!cJSON_IsNumber(num_of_ue)) {
			printf(
				"speed_threshold_info_parseFromJSON() failed [num_of_ue]");
			goto end;
		}
	}

	ratio = cJSON_GetObjectItemCaseSensitive(speed_threshold_infoJSON,
	                                         "ratio");
	if(ratio) {
		if(!cJSON_IsNumber(ratio)) {
			printf(
				"speed_threshold_info_parseFromJSON() failed [ratio]");
			goto end;
		}
	}

	speed_threshold_info_local_var = speed_threshold_info_create(
		num_of_ue ? true : false,
		num_of_ue ? num_of_ue->valuedouble : 0,
		ratio ? true : false,
		ratio ? ratio->valuedouble : 0
		);

	return speed_threshold_info_local_var;
end:
	return NULL;
}

speed_threshold_info_t *speed_threshold_info_copy(
	speed_threshold_info_t	*dst,
	speed_threshold_info_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = speed_threshold_info_convertToJSON(src);
	if(!item) {
		printf("speed_threshold_info_convertToJSON() failed");
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

	speed_threshold_info_free(dst);
	dst = speed_threshold_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
