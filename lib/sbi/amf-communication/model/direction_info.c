#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "direction_info.h"

direction_info_t *direction_info_create(char *supi, char *gpsi,
                                        bool is_num_of_ue, int num_of_ue,
                                        bool is_avr_speed, float avr_speed,
                                        bool is_ratio, int ratio,
                                        direction_t *direction) {
	direction_info_t *direction_info_local_var =
		malloc(sizeof(direction_info_t));

	direction_info_local_var->supi = supi;
	direction_info_local_var->gpsi = gpsi;
	direction_info_local_var->is_num_of_ue = is_num_of_ue;
	direction_info_local_var->num_of_ue = num_of_ue;
	direction_info_local_var->is_avr_speed = is_avr_speed;
	direction_info_local_var->avr_speed = avr_speed;
	direction_info_local_var->is_ratio = is_ratio;
	direction_info_local_var->ratio = ratio;
	direction_info_local_var->direction = direction;

	return direction_info_local_var;
}

void direction_info_free(direction_info_t *direction_info) {
	lnode_t *node = NULL;

	if(NULL == direction_info) {
		return;
	}
	if(direction_info->supi) {
		free(direction_info->supi);
		direction_info->supi = NULL;
	}
	if(direction_info->gpsi) {
		free(direction_info->gpsi);
		direction_info->gpsi = NULL;
	}
	if(direction_info->direction) {
		direction_free(direction_info->direction);
		direction_info->direction = NULL;
	}
	free(direction_info);
}

cJSON *direction_info_convertToJSON(direction_info_t *direction_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(direction_info == NULL) {
		printf("direction_info_convertToJSON() failed [DirectionInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(direction_info->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           direction_info->supi) == NULL)
		{
			printf("direction_info_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(direction_info->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           direction_info->gpsi) == NULL)
		{
			printf("direction_info_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(direction_info->is_num_of_ue) {
		if(cJSON_AddNumberToObject(item, "numOfUe",
		                           direction_info->num_of_ue) == NULL)
		{
			printf(
				"direction_info_convertToJSON() failed [num_of_ue]");
			goto end;
		}
	}

	if(direction_info->is_avr_speed) {
		if(cJSON_AddNumberToObject(item, "avrSpeed",
		                           direction_info->avr_speed) == NULL)
		{
			printf(
				"direction_info_convertToJSON() failed [avr_speed]");
			goto end;
		}
	}

	if(direction_info->is_ratio) {
		if(cJSON_AddNumberToObject(item, "ratio",
		                           direction_info->ratio) == NULL)
		{
			printf("direction_info_convertToJSON() failed [ratio]");
			goto end;
		}
	}

	if(!direction_info->direction) {
		printf("direction_info_convertToJSON() failed [direction]");
		return NULL;
	}
	cJSON *direction_local_JSON = direction_convertToJSON(
		direction_info->direction);
	if(direction_local_JSON == NULL) {
		printf("direction_info_convertToJSON() failed [direction]");
		goto end;
	}
	cJSON_AddItemToObject(item, "direction", direction_local_JSON);
	if(item->child == NULL) {
		printf("direction_info_convertToJSON() failed [direction]");
		goto end;
	}

end:
	return item;
}

direction_info_t *direction_info_parseFromJSON(cJSON *direction_infoJSON) {
	direction_info_t *direction_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *supi = NULL;
	cJSON *gpsi = NULL;
	cJSON *num_of_ue = NULL;
	cJSON *avr_speed = NULL;
	cJSON *ratio = NULL;
	cJSON *direction = NULL;
	direction_t *direction_local_nonprim = NULL;
	supi = cJSON_GetObjectItemCaseSensitive(direction_infoJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf("direction_info_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(direction_infoJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("direction_info_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	num_of_ue = cJSON_GetObjectItemCaseSensitive(direction_infoJSON,
	                                             "numOfUe");
	if(num_of_ue) {
		if(!cJSON_IsNumber(num_of_ue)) {
			printf(
				"direction_info_parseFromJSON() failed [num_of_ue]");
			goto end;
		}
	}

	avr_speed = cJSON_GetObjectItemCaseSensitive(direction_infoJSON,
	                                             "avrSpeed");
	if(avr_speed) {
		if(!cJSON_IsNumber(avr_speed)) {
			printf(
				"direction_info_parseFromJSON() failed [avr_speed]");
			goto end;
		}
	}

	ratio = cJSON_GetObjectItemCaseSensitive(direction_infoJSON, "ratio");
	if(ratio) {
		if(!cJSON_IsNumber(ratio)) {
			printf("direction_info_parseFromJSON() failed [ratio]");
			goto end;
		}
	}

	direction = cJSON_GetObjectItemCaseSensitive(direction_infoJSON,
	                                             "direction");
	if(!direction) {
		printf("direction_info_parseFromJSON() failed [direction]");
		goto end;
	}
	direction_local_nonprim = direction_parseFromJSON(direction);
	if(!direction_local_nonprim) {
		printf("direction_parseFromJSON failed [direction]");
		goto end;
	}

	direction_info_local_var = direction_info_create(
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		num_of_ue ? true : false,
		num_of_ue ? num_of_ue->valuedouble : 0,
		avr_speed ? true : false,
		avr_speed ? avr_speed->valuedouble : 0,
		ratio ? true : false,
		ratio ? ratio->valuedouble : 0,
		direction_local_nonprim
		);

	return direction_info_local_var;
end:
	if(direction_local_nonprim) {
		direction_free(direction_local_nonprim);
		direction_local_nonprim = NULL;
	}
	return NULL;
}

direction_info_t *direction_info_copy(direction_info_t	*dst,
                                      direction_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = direction_info_convertToJSON(src);
	if(!item) {
		printf("direction_info_convertToJSON() failed");
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

	direction_info_free(dst);
	dst = direction_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
