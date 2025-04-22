#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "scheduled_communication_time_1.h"

scheduled_communication_time_1_t *scheduled_communication_time_1_create(
	list_t *days_of_week, char *time_of_day_start, char *time_of_day_end) {
	scheduled_communication_time_1_t *
	        scheduled_communication_time_1_local_var =
		malloc(sizeof(scheduled_communication_time_1_t));

	scheduled_communication_time_1_local_var->days_of_week = days_of_week;
	scheduled_communication_time_1_local_var->time_of_day_start =
		time_of_day_start;
	scheduled_communication_time_1_local_var->time_of_day_end =
		time_of_day_end;

	return scheduled_communication_time_1_local_var;
}

void scheduled_communication_time_1_free(
	scheduled_communication_time_1_t *scheduled_communication_time_1) {
	lnode_t *node = NULL;

	if(NULL == scheduled_communication_time_1) {
		return;
	}
	if(scheduled_communication_time_1->days_of_week) {
		list_for_each(scheduled_communication_time_1->days_of_week,
		              node) {
			free(node->data);
		}
		list_free(scheduled_communication_time_1->days_of_week);
		scheduled_communication_time_1->days_of_week = NULL;
	}
	if(scheduled_communication_time_1->time_of_day_start) {
		free(scheduled_communication_time_1->time_of_day_start);
		scheduled_communication_time_1->time_of_day_start = NULL;
	}
	if(scheduled_communication_time_1->time_of_day_end) {
		free(scheduled_communication_time_1->time_of_day_end);
		scheduled_communication_time_1->time_of_day_end = NULL;
	}
	free(scheduled_communication_time_1);
}

cJSON *scheduled_communication_time_1_convertToJSON(
	scheduled_communication_time_1_t *scheduled_communication_time_1) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(scheduled_communication_time_1 == NULL) {
		printf(
			"scheduled_communication_time_1_convertToJSON() failed [ScheduledCommunicationTime_1]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(scheduled_communication_time_1->days_of_week) {
		cJSON *days_of_weekList = cJSON_AddArrayToObject(item,
		                                                 "daysOfWeek");
		if(days_of_weekList == NULL) {
			printf(
				"scheduled_communication_time_1_convertToJSON() failed [days_of_week]");
			goto end;
		}
		list_for_each(scheduled_communication_time_1->days_of_week,
		              node) {
			if(node->data == NULL) {
				printf(
					"scheduled_communication_time_1_convertToJSON() failed [days_of_week]");
				goto end;
			}
			if(cJSON_AddNumberToObject(days_of_weekList, "",
			                           *(double *) node->data) ==
			   NULL)
			{
				printf(
					"scheduled_communication_time_1_convertToJSON() failed [days_of_week]");
				goto end;
			}
		}
	}

	if(scheduled_communication_time_1->time_of_day_start) {
		if(cJSON_AddStringToObject(item, "timeOfDayStart",
		                           scheduled_communication_time_1->
		                           time_of_day_start) == NULL)
		{
			printf(
				"scheduled_communication_time_1_convertToJSON() failed [time_of_day_start]");
			goto end;
		}
	}

	if(scheduled_communication_time_1->time_of_day_end) {
		if(cJSON_AddStringToObject(item, "timeOfDayEnd",
		                           scheduled_communication_time_1->
		                           time_of_day_end) == NULL)
		{
			printf(
				"scheduled_communication_time_1_convertToJSON() failed [time_of_day_end]");
			goto end;
		}
	}

end:
	return item;
}

scheduled_communication_time_1_t *scheduled_communication_time_1_parseFromJSON(
	cJSON *scheduled_communication_time_1JSON) {
	scheduled_communication_time_1_t *
	        scheduled_communication_time_1_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *days_of_week = NULL;
	list_t *days_of_weekList = NULL;
	cJSON *time_of_day_start = NULL;
	cJSON *time_of_day_end = NULL;
	days_of_week = cJSON_GetObjectItemCaseSensitive(
		scheduled_communication_time_1JSON, "daysOfWeek");
	if(days_of_week) {
		cJSON *days_of_week_local = NULL;
		if(!cJSON_IsArray(days_of_week)) {
			printf(
				"scheduled_communication_time_1_parseFromJSON() failed [days_of_week]");
			goto end;
		}

		days_of_weekList = list_create();

		cJSON_ArrayForEach(days_of_week_local, days_of_week) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsNumber(days_of_week_local)) {
				printf(
					"scheduled_communication_time_1_parseFromJSON() failed [days_of_week]");
				goto end;
			}
			localDouble = (double *) calloc(1, sizeof(double));
			if(!localDouble) {
				printf(
					"scheduled_communication_time_1_parseFromJSON() failed [days_of_week]");
				goto end;
			}
			*localDouble = days_of_week_local->valuedouble;
			list_add(days_of_weekList, localDouble);
		}
	}

	time_of_day_start = cJSON_GetObjectItemCaseSensitive(
		scheduled_communication_time_1JSON, "timeOfDayStart");
	if(time_of_day_start) {
		if(!cJSON_IsString(time_of_day_start) &&
		   !cJSON_IsNull(time_of_day_start))
		{
			printf(
				"scheduled_communication_time_1_parseFromJSON() failed [time_of_day_start]");
			goto end;
		}
	}

	time_of_day_end = cJSON_GetObjectItemCaseSensitive(
		scheduled_communication_time_1JSON, "timeOfDayEnd");
	if(time_of_day_end) {
		if(!cJSON_IsString(time_of_day_end) &&
		   !cJSON_IsNull(time_of_day_end))
		{
			printf(
				"scheduled_communication_time_1_parseFromJSON() failed [time_of_day_end]");
			goto end;
		}
	}

	scheduled_communication_time_1_local_var =
		scheduled_communication_time_1_create(
			days_of_week ? days_of_weekList : NULL,
			time_of_day_start &&
			!cJSON_IsNull(time_of_day_start) ? strdup(
				time_of_day_start->
				valuestring) : NULL,
			time_of_day_end &&
			!cJSON_IsNull(time_of_day_end) ? strdup(time_of_day_end
			                                        ->
			                                        valuestring) : NULL
			);

	return scheduled_communication_time_1_local_var;
end:
	if(days_of_weekList) {
		list_for_each(days_of_weekList, node) {
			free(node->data);
		}
		list_free(days_of_weekList);
		days_of_weekList = NULL;
	}
	return NULL;
}

scheduled_communication_time_1_t *scheduled_communication_time_1_copy(
	scheduled_communication_time_1_t	*dst,
	scheduled_communication_time_1_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = scheduled_communication_time_1_convertToJSON(src);
	if(!item) {
		printf("scheduled_communication_time_1_convertToJSON() failed");
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

	scheduled_communication_time_1_free(dst);
	dst = scheduled_communication_time_1_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
