#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mov_behav.h"

mov_behav_t *mov_behav_create(char *ts_start, int ts_duration,
                              bool is_num_of_ue, int num_of_ue, bool is_ratio,
                              int ratio, bool is_avr_speed, float avr_speed,
                              list_t *speed_thresd_infos,
                              list_t *direction_ue_infos) {
	mov_behav_t *mov_behav_local_var = malloc(sizeof(mov_behav_t));

	mov_behav_local_var->ts_start = ts_start;
	mov_behav_local_var->ts_duration = ts_duration;
	mov_behav_local_var->is_num_of_ue = is_num_of_ue;
	mov_behav_local_var->num_of_ue = num_of_ue;
	mov_behav_local_var->is_ratio = is_ratio;
	mov_behav_local_var->ratio = ratio;
	mov_behav_local_var->is_avr_speed = is_avr_speed;
	mov_behav_local_var->avr_speed = avr_speed;
	mov_behav_local_var->speed_thresd_infos = speed_thresd_infos;
	mov_behav_local_var->direction_ue_infos = direction_ue_infos;

	return mov_behav_local_var;
}

void mov_behav_free(mov_behav_t *mov_behav) {
	lnode_t *node = NULL;

	if(NULL == mov_behav) {
		return;
	}
	if(mov_behav->ts_start) {
		free(mov_behav->ts_start);
		mov_behav->ts_start = NULL;
	}
	if(mov_behav->speed_thresd_infos) {
		list_for_each(mov_behav->speed_thresd_infos, node) {
			speed_threshold_info_free(node->data);
		}
		list_free(mov_behav->speed_thresd_infos);
		mov_behav->speed_thresd_infos = NULL;
	}
	if(mov_behav->direction_ue_infos) {
		list_for_each(mov_behav->direction_ue_infos, node) {
			direction_info_free(node->data);
		}
		list_free(mov_behav->direction_ue_infos);
		mov_behav->direction_ue_infos = NULL;
	}
	free(mov_behav);
}

cJSON *mov_behav_convertToJSON(mov_behav_t *mov_behav) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(mov_behav == NULL) {
		printf("mov_behav_convertToJSON() failed [MovBehav]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!mov_behav->ts_start) {
		printf("mov_behav_convertToJSON() failed [ts_start]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "tsStart",
	                           mov_behav->ts_start) == NULL)
	{
		printf("mov_behav_convertToJSON() failed [ts_start]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "tsDuration",
	                           mov_behav->ts_duration) == NULL)
	{
		printf("mov_behav_convertToJSON() failed [ts_duration]");
		goto end;
	}

	if(mov_behav->is_num_of_ue) {
		if(cJSON_AddNumberToObject(item, "numOfUe",
		                           mov_behav->num_of_ue) == NULL)
		{
			printf("mov_behav_convertToJSON() failed [num_of_ue]");
			goto end;
		}
	}

	if(mov_behav->is_ratio) {
		if(cJSON_AddNumberToObject(item, "ratio",
		                           mov_behav->ratio) == NULL)
		{
			printf("mov_behav_convertToJSON() failed [ratio]");
			goto end;
		}
	}

	if(mov_behav->is_avr_speed) {
		if(cJSON_AddNumberToObject(item, "avrSpeed",
		                           mov_behav->avr_speed) == NULL)
		{
			printf("mov_behav_convertToJSON() failed [avr_speed]");
			goto end;
		}
	}

	if(mov_behav->speed_thresd_infos) {
		cJSON *speed_thresd_infosList = cJSON_AddArrayToObject(item,
		                                                       "speedThresdInfos");
		if(speed_thresd_infosList == NULL) {
			printf(
				"mov_behav_convertToJSON() failed [speed_thresd_infos]");
			goto end;
		}
		list_for_each(mov_behav->speed_thresd_infos, node) {
			cJSON *itemLocal = speed_threshold_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"mov_behav_convertToJSON() failed [speed_thresd_infos]");
				goto end;
			}
			cJSON_AddItemToArray(speed_thresd_infosList, itemLocal);
		}
	}

	if(mov_behav->direction_ue_infos) {
		cJSON *direction_ue_infosList = cJSON_AddArrayToObject(item,
		                                                       "directionUeInfos");
		if(direction_ue_infosList == NULL) {
			printf(
				"mov_behav_convertToJSON() failed [direction_ue_infos]");
			goto end;
		}
		list_for_each(mov_behav->direction_ue_infos, node) {
			cJSON *itemLocal = direction_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"mov_behav_convertToJSON() failed [direction_ue_infos]");
				goto end;
			}
			cJSON_AddItemToArray(direction_ue_infosList, itemLocal);
		}
	}

end:
	return item;
}

mov_behav_t *mov_behav_parseFromJSON(cJSON *mov_behavJSON) {
	mov_behav_t *mov_behav_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ts_start = NULL;
	cJSON *ts_duration = NULL;
	cJSON *num_of_ue = NULL;
	cJSON *ratio = NULL;
	cJSON *avr_speed = NULL;
	cJSON *speed_thresd_infos = NULL;
	list_t *speed_thresd_infosList = NULL;
	cJSON *direction_ue_infos = NULL;
	list_t *direction_ue_infosList = NULL;
	ts_start = cJSON_GetObjectItemCaseSensitive(mov_behavJSON, "tsStart");
	if(!ts_start) {
		printf("mov_behav_parseFromJSON() failed [ts_start]");
		goto end;
	}
	if(!cJSON_IsString(ts_start) &&
	   !cJSON_IsNull(ts_start))
	{
		printf("mov_behav_parseFromJSON() failed [ts_start]");
		goto end;
	}

	ts_duration = cJSON_GetObjectItemCaseSensitive(mov_behavJSON,
	                                               "tsDuration");
	if(!ts_duration) {
		printf("mov_behav_parseFromJSON() failed [ts_duration]");
		goto end;
	}
	if(!cJSON_IsNumber(ts_duration)) {
		printf("mov_behav_parseFromJSON() failed [ts_duration]");
		goto end;
	}

	num_of_ue = cJSON_GetObjectItemCaseSensitive(mov_behavJSON, "numOfUe");
	if(num_of_ue) {
		if(!cJSON_IsNumber(num_of_ue)) {
			printf("mov_behav_parseFromJSON() failed [num_of_ue]");
			goto end;
		}
	}

	ratio = cJSON_GetObjectItemCaseSensitive(mov_behavJSON, "ratio");
	if(ratio) {
		if(!cJSON_IsNumber(ratio)) {
			printf("mov_behav_parseFromJSON() failed [ratio]");
			goto end;
		}
	}

	avr_speed = cJSON_GetObjectItemCaseSensitive(mov_behavJSON, "avrSpeed");
	if(avr_speed) {
		if(!cJSON_IsNumber(avr_speed)) {
			printf("mov_behav_parseFromJSON() failed [avr_speed]");
			goto end;
		}
	}

	speed_thresd_infos = cJSON_GetObjectItemCaseSensitive(mov_behavJSON,
	                                                      "speedThresdInfos");
	if(speed_thresd_infos) {
		cJSON *speed_thresd_infos_local = NULL;
		if(!cJSON_IsArray(speed_thresd_infos)) {
			printf(
				"mov_behav_parseFromJSON() failed [speed_thresd_infos]");
			goto end;
		}

		speed_thresd_infosList = list_create();

		cJSON_ArrayForEach(speed_thresd_infos_local,
		                   speed_thresd_infos) {
			if(!cJSON_IsObject(speed_thresd_infos_local)) {
				printf(
					"mov_behav_parseFromJSON() failed [speed_thresd_infos]");
				goto end;
			}
			speed_threshold_info_t *speed_thresd_infosItem =
				speed_threshold_info_parseFromJSON(
					speed_thresd_infos_local);
			if(!speed_thresd_infosItem) {
				printf("No speed_thresd_infosItem");
				goto end;
			}
			list_add(speed_thresd_infosList,
			         speed_thresd_infosItem);
		}
	}

	direction_ue_infos = cJSON_GetObjectItemCaseSensitive(mov_behavJSON,
	                                                      "directionUeInfos");
	if(direction_ue_infos) {
		cJSON *direction_ue_infos_local = NULL;
		if(!cJSON_IsArray(direction_ue_infos)) {
			printf(
				"mov_behav_parseFromJSON() failed [direction_ue_infos]");
			goto end;
		}

		direction_ue_infosList = list_create();

		cJSON_ArrayForEach(direction_ue_infos_local,
		                   direction_ue_infos) {
			if(!cJSON_IsObject(direction_ue_infos_local)) {
				printf(
					"mov_behav_parseFromJSON() failed [direction_ue_infos]");
				goto end;
			}
			direction_info_t *direction_ue_infosItem =
				direction_info_parseFromJSON(
					direction_ue_infos_local);
			if(!direction_ue_infosItem) {
				printf("No direction_ue_infosItem");
				goto end;
			}
			list_add(direction_ue_infosList,
			         direction_ue_infosItem);
		}
	}

	mov_behav_local_var = mov_behav_create(
		strdup(ts_start->valuestring),

		ts_duration->valuedouble,
		num_of_ue ? true : false,
		num_of_ue ? num_of_ue->valuedouble : 0,
		ratio ? true : false,
		ratio ? ratio->valuedouble : 0,
		avr_speed ? true : false,
		avr_speed ? avr_speed->valuedouble : 0,
		speed_thresd_infos ? speed_thresd_infosList : NULL,
		direction_ue_infos ? direction_ue_infosList : NULL
		);

	return mov_behav_local_var;
end:
	if(speed_thresd_infosList) {
		list_for_each(speed_thresd_infosList, node) {
			speed_threshold_info_free(node->data);
		}
		list_free(speed_thresd_infosList);
		speed_thresd_infosList = NULL;
	}
	if(direction_ue_infosList) {
		list_for_each(direction_ue_infosList, node) {
			direction_info_free(node->data);
		}
		list_free(direction_ue_infosList);
		direction_ue_infosList = NULL;
	}
	return NULL;
}

mov_behav_t *mov_behav_copy(mov_behav_t *dst, mov_behav_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = mov_behav_convertToJSON(src);
	if(!item) {
		printf("mov_behav_convertToJSON() failed");
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

	mov_behav_free(dst);
	dst = mov_behav_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
