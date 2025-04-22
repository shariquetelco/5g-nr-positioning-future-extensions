#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "recur_time.h"

recur_time_t *recur_time_create(valid_time_period_t *recur_time_window,
                                recur_type_t *recur_type, list_t *recur_month,
                                list_t *recur_week, list_t *recur_day,
                                list_t *recur_date) {
	recur_time_t *recur_time_local_var = malloc(sizeof(recur_time_t));

	recur_time_local_var->recur_time_window = recur_time_window;
	recur_time_local_var->recur_type = recur_type;
	recur_time_local_var->recur_month = recur_month;
	recur_time_local_var->recur_week = recur_week;
	recur_time_local_var->recur_day = recur_day;
	recur_time_local_var->recur_date = recur_date;

	return recur_time_local_var;
}

void recur_time_free(recur_time_t *recur_time) {
	lnode_t *node = NULL;

	if(NULL == recur_time) {
		return;
	}
	if(recur_time->recur_time_window) {
		valid_time_period_free(recur_time->recur_time_window);
		recur_time->recur_time_window = NULL;
	}
	if(recur_time->recur_type) {
		recur_type_free(recur_time->recur_type);
		recur_time->recur_type = NULL;
	}
	if(recur_time->recur_month) {
		list_for_each(recur_time->recur_month, node) {
			free(node->data);
		}
		list_free(recur_time->recur_month);
		recur_time->recur_month = NULL;
	}
	if(recur_time->recur_week) {
		list_for_each(recur_time->recur_week, node) {
			free(node->data);
		}
		list_free(recur_time->recur_week);
		recur_time->recur_week = NULL;
	}
	if(recur_time->recur_day) {
		list_for_each(recur_time->recur_day, node) {
			free(node->data);
		}
		list_free(recur_time->recur_day);
		recur_time->recur_day = NULL;
	}
	if(recur_time->recur_date) {
		list_for_each(recur_time->recur_date, node) {
			free(node->data);
		}
		list_free(recur_time->recur_date);
		recur_time->recur_date = NULL;
	}
	free(recur_time);
}

cJSON *recur_time_convertToJSON(recur_time_t *recur_time) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(recur_time == NULL) {
		printf("recur_time_convertToJSON() failed [RecurTime]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(recur_time->recur_time_window) {
		cJSON *recur_time_window_local_JSON =
			valid_time_period_convertToJSON(
				recur_time->recur_time_window);
		if(recur_time_window_local_JSON == NULL) {
			printf(
				"recur_time_convertToJSON() failed [recur_time_window]");
			goto end;
		}
		cJSON_AddItemToObject(item, "recurTimeWindow",
		                      recur_time_window_local_JSON);
		if(item->child == NULL) {
			printf(
				"recur_time_convertToJSON() failed [recur_time_window]");
			goto end;
		}
	}

	if(recur_time->recur_type) {
		cJSON *recur_type_local_JSON = recur_type_convertToJSON(
			recur_time->recur_type);
		if(recur_type_local_JSON == NULL) {
			printf("recur_time_convertToJSON() failed [recur_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "recurType", recur_type_local_JSON);
		if(item->child == NULL) {
			printf("recur_time_convertToJSON() failed [recur_type]");
			goto end;
		}
	}

	if(recur_time->recur_month) {
		cJSON *recur_monthList = cJSON_AddArrayToObject(item,
		                                                "recurMonth");
		if(recur_monthList == NULL) {
			printf("recur_time_convertToJSON() failed [recur_month]");
			goto end;
		}
		list_for_each(recur_time->recur_month, node) {
			if(node->data == NULL) {
				printf(
					"recur_time_convertToJSON() failed [recur_month]");
				goto end;
			}
			if(cJSON_AddNumberToObject(recur_monthList, "",
			                           *(double *) node->data) ==
			   NULL)
			{
				printf(
					"recur_time_convertToJSON() failed [recur_month]");
				goto end;
			}
		}
	}

	if(recur_time->recur_week) {
		cJSON *recur_weekList =
			cJSON_AddArrayToObject(item, "recurWeek");
		if(recur_weekList == NULL) {
			printf("recur_time_convertToJSON() failed [recur_week]");
			goto end;
		}
		list_for_each(recur_time->recur_week, node) {
			if(node->data == NULL) {
				printf(
					"recur_time_convertToJSON() failed [recur_week]");
				goto end;
			}
			if(cJSON_AddNumberToObject(recur_weekList, "",
			                           *(double *) node->data) ==
			   NULL)
			{
				printf(
					"recur_time_convertToJSON() failed [recur_week]");
				goto end;
			}
		}
	}

	if(recur_time->recur_day) {
		cJSON *recur_dayList = cJSON_AddArrayToObject(item, "recurDay");
		if(recur_dayList == NULL) {
			printf("recur_time_convertToJSON() failed [recur_day]");
			goto end;
		}
		list_for_each(recur_time->recur_day, node) {
			if(node->data == NULL) {
				printf(
					"recur_time_convertToJSON() failed [recur_day]");
				goto end;
			}
			if(cJSON_AddNumberToObject(recur_dayList, "",
			                           *(double *) node->data) ==
			   NULL)
			{
				printf(
					"recur_time_convertToJSON() failed [recur_day]");
				goto end;
			}
		}
	}

	if(recur_time->recur_date) {
		cJSON *recur_dateList =
			cJSON_AddArrayToObject(item, "recurDate");
		if(recur_dateList == NULL) {
			printf("recur_time_convertToJSON() failed [recur_date]");
			goto end;
		}
		list_for_each(recur_time->recur_date, node) {}
	}

end:
	return item;
}

recur_time_t *recur_time_parseFromJSON(cJSON *recur_timeJSON) {
	recur_time_t *recur_time_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *recur_time_window = NULL;
	valid_time_period_t *recur_time_window_local_nonprim = NULL;
	cJSON *recur_type = NULL;
	recur_type_t *recur_type_local_nonprim = NULL;
	cJSON *recur_month = NULL;
	list_t *recur_monthList = NULL;
	cJSON *recur_week = NULL;
	list_t *recur_weekList = NULL;
	cJSON *recur_day = NULL;
	list_t *recur_dayList = NULL;
	cJSON *recur_date = NULL;
	list_t *recur_dateList = NULL;
	recur_time_window = cJSON_GetObjectItemCaseSensitive(recur_timeJSON,
	                                                     "recurTimeWindow");
	if(recur_time_window) {
		recur_time_window_local_nonprim =
			valid_time_period_parseFromJSON(recur_time_window);
		if(!recur_time_window_local_nonprim) {
			printf(
				"valid_time_period_parseFromJSON failed [recur_time_window]");
			goto end;
		}
	}

	recur_type = cJSON_GetObjectItemCaseSensitive(recur_timeJSON,
	                                              "recurType");
	if(recur_type) {
		recur_type_local_nonprim = recur_type_parseFromJSON(recur_type);
		if(!recur_type_local_nonprim) {
			printf("recur_type_parseFromJSON failed [recur_type]");
			goto end;
		}
	}

	recur_month = cJSON_GetObjectItemCaseSensitive(recur_timeJSON,
	                                               "recurMonth");
	if(recur_month) {
		cJSON *recur_month_local = NULL;
		if(!cJSON_IsArray(recur_month)) {
			printf("recur_time_parseFromJSON() failed [recur_month]");
			goto end;
		}

		recur_monthList = list_create();

		cJSON_ArrayForEach(recur_month_local, recur_month) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsNumber(recur_month_local)) {
				printf(
					"recur_time_parseFromJSON() failed [recur_month]");
				goto end;
			}
			localDouble = (double *) calloc(1, sizeof(double));
			if(!localDouble) {
				printf(
					"recur_time_parseFromJSON() failed [recur_month]");
				goto end;
			}
			*localDouble = recur_month_local->valuedouble;
			list_add(recur_monthList, localDouble);
		}
	}

	recur_week = cJSON_GetObjectItemCaseSensitive(recur_timeJSON,
	                                              "recurWeek");
	if(recur_week) {
		cJSON *recur_week_local = NULL;
		if(!cJSON_IsArray(recur_week)) {
			printf("recur_time_parseFromJSON() failed [recur_week]");
			goto end;
		}

		recur_weekList = list_create();

		cJSON_ArrayForEach(recur_week_local, recur_week) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsNumber(recur_week_local)) {
				printf(
					"recur_time_parseFromJSON() failed [recur_week]");
				goto end;
			}
			localDouble = (double *) calloc(1, sizeof(double));
			if(!localDouble) {
				printf(
					"recur_time_parseFromJSON() failed [recur_week]");
				goto end;
			}
			*localDouble = recur_week_local->valuedouble;
			list_add(recur_weekList, localDouble);
		}
	}

	recur_day =
		cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurDay");
	if(recur_day) {
		cJSON *recur_day_local = NULL;
		if(!cJSON_IsArray(recur_day)) {
			printf("recur_time_parseFromJSON() failed [recur_day]");
			goto end;
		}

		recur_dayList = list_create();

		cJSON_ArrayForEach(recur_day_local, recur_day) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsNumber(recur_day_local)) {
				printf(
					"recur_time_parseFromJSON() failed [recur_day]");
				goto end;
			}
			localDouble = (double *) calloc(1, sizeof(double));
			if(!localDouble) {
				printf(
					"recur_time_parseFromJSON() failed [recur_day]");
				goto end;
			}
			*localDouble = recur_day_local->valuedouble;
			list_add(recur_dayList, localDouble);
		}
	}

	recur_date = cJSON_GetObjectItemCaseSensitive(recur_timeJSON,
	                                              "recurDate");
	if(recur_date) {
		cJSON *recur_date_local = NULL;
		if(!cJSON_IsArray(recur_date)) {
			printf("recur_time_parseFromJSON() failed [recur_date]");
			goto end;
		}

		recur_dateList = list_create();

		cJSON_ArrayForEach(recur_date_local, recur_date) {
			double *localDouble = NULL;
			int *localInt = NULL;
		}
	}

	recur_time_local_var = recur_time_create(
		recur_time_window ? recur_time_window_local_nonprim : NULL,
		recur_type ? recur_type_local_nonprim : NULL,
		recur_month ? recur_monthList : NULL,
		recur_week ? recur_weekList : NULL,
		recur_day ? recur_dayList : NULL,
		recur_date ? recur_dateList : NULL
		);

	return recur_time_local_var;
end:
	if(recur_time_window_local_nonprim) {
		valid_time_period_free(recur_time_window_local_nonprim);
		recur_time_window_local_nonprim = NULL;
	}
	if(recur_type_local_nonprim) {
		recur_type_free(recur_type_local_nonprim);
		recur_type_local_nonprim = NULL;
	}
	if(recur_monthList) {
		list_for_each(recur_monthList, node) {
			free(node->data);
		}
		list_free(recur_monthList);
		recur_monthList = NULL;
	}
	if(recur_weekList) {
		list_for_each(recur_weekList, node) {
			free(node->data);
		}
		list_free(recur_weekList);
		recur_weekList = NULL;
	}
	if(recur_dayList) {
		list_for_each(recur_dayList, node) {
			free(node->data);
		}
		list_free(recur_dayList);
		recur_dayList = NULL;
	}
	if(recur_dateList) {
		list_for_each(recur_dateList, node) {
			free(node->data);
		}
		list_free(recur_dateList);
		recur_dateList = NULL;
	}
	return NULL;
}

recur_time_t *recur_time_copy(recur_time_t *dst, recur_time_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = recur_time_convertToJSON(src);
	if(!item) {
		printf("recur_time_convertToJSON() failed");
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

	recur_time_free(dst);
	dst = recur_time_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
