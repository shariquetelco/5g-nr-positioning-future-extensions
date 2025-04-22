#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mbsr_time_info.h"

mbsr_time_info_t *mbsr_time_info_create(list_t	*mbsr_time_window,
                                        list_t	*mbsr_recur_time) {
	mbsr_time_info_t *mbsr_time_info_local_var =
		malloc(sizeof(mbsr_time_info_t));

	mbsr_time_info_local_var->mbsr_time_window = mbsr_time_window;
	mbsr_time_info_local_var->mbsr_recur_time = mbsr_recur_time;

	return mbsr_time_info_local_var;
}

void mbsr_time_info_free(mbsr_time_info_t *mbsr_time_info) {
	lnode_t *node = NULL;

	if(NULL == mbsr_time_info) {
		return;
	}
	if(mbsr_time_info->mbsr_time_window) {
		list_for_each(mbsr_time_info->mbsr_time_window, node) {
			valid_time_period_free(node->data);
		}
		list_free(mbsr_time_info->mbsr_time_window);
		mbsr_time_info->mbsr_time_window = NULL;
	}
	if(mbsr_time_info->mbsr_recur_time) {
		list_for_each(mbsr_time_info->mbsr_recur_time, node) {
			recur_time_free(node->data);
		}
		list_free(mbsr_time_info->mbsr_recur_time);
		mbsr_time_info->mbsr_recur_time = NULL;
	}
	free(mbsr_time_info);
}

cJSON *mbsr_time_info_convertToJSON(mbsr_time_info_t *mbsr_time_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(mbsr_time_info == NULL) {
		printf("mbsr_time_info_convertToJSON() failed [MbsrTimeInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(mbsr_time_info->mbsr_time_window) {
		cJSON *mbsr_time_windowList = cJSON_AddArrayToObject(item,
		                                                     "mbsrTimeWindow");
		if(mbsr_time_windowList == NULL) {
			printf(
				"mbsr_time_info_convertToJSON() failed [mbsr_time_window]");
			goto end;
		}
		list_for_each(mbsr_time_info->mbsr_time_window, node) {
			cJSON *itemLocal = valid_time_period_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"mbsr_time_info_convertToJSON() failed [mbsr_time_window]");
				goto end;
			}
			cJSON_AddItemToArray(mbsr_time_windowList, itemLocal);
		}
	}

	if(mbsr_time_info->mbsr_recur_time) {
		cJSON *mbsr_recur_timeList = cJSON_AddArrayToObject(item,
		                                                    "mbsrRecurTime");
		if(mbsr_recur_timeList == NULL) {
			printf(
				"mbsr_time_info_convertToJSON() failed [mbsr_recur_time]");
			goto end;
		}
		list_for_each(mbsr_time_info->mbsr_recur_time, node) {
			cJSON *itemLocal = recur_time_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"mbsr_time_info_convertToJSON() failed [mbsr_recur_time]");
				goto end;
			}
			cJSON_AddItemToArray(mbsr_recur_timeList, itemLocal);
		}
	}

end:
	return item;
}

mbsr_time_info_t *mbsr_time_info_parseFromJSON(cJSON *mbsr_time_infoJSON) {
	mbsr_time_info_t *mbsr_time_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *mbsr_time_window = NULL;
	list_t *mbsr_time_windowList = NULL;
	cJSON *mbsr_recur_time = NULL;
	list_t *mbsr_recur_timeList = NULL;
	mbsr_time_window = cJSON_GetObjectItemCaseSensitive(mbsr_time_infoJSON,
	                                                    "mbsrTimeWindow");
	if(mbsr_time_window) {
		cJSON *mbsr_time_window_local = NULL;
		if(!cJSON_IsArray(mbsr_time_window)) {
			printf(
				"mbsr_time_info_parseFromJSON() failed [mbsr_time_window]");
			goto end;
		}

		mbsr_time_windowList = list_create();

		cJSON_ArrayForEach(mbsr_time_window_local, mbsr_time_window) {
			if(!cJSON_IsObject(mbsr_time_window_local)) {
				printf(
					"mbsr_time_info_parseFromJSON() failed [mbsr_time_window]");
				goto end;
			}
			valid_time_period_t *mbsr_time_windowItem =
				valid_time_period_parseFromJSON(
					mbsr_time_window_local);
			if(!mbsr_time_windowItem) {
				printf("No mbsr_time_windowItem");
				goto end;
			}
			list_add(mbsr_time_windowList, mbsr_time_windowItem);
		}
	}

	mbsr_recur_time = cJSON_GetObjectItemCaseSensitive(mbsr_time_infoJSON,
	                                                   "mbsrRecurTime");
	if(mbsr_recur_time) {
		cJSON *mbsr_recur_time_local = NULL;
		if(!cJSON_IsArray(mbsr_recur_time)) {
			printf(
				"mbsr_time_info_parseFromJSON() failed [mbsr_recur_time]");
			goto end;
		}

		mbsr_recur_timeList = list_create();

		cJSON_ArrayForEach(mbsr_recur_time_local, mbsr_recur_time) {
			if(!cJSON_IsObject(mbsr_recur_time_local)) {
				printf(
					"mbsr_time_info_parseFromJSON() failed [mbsr_recur_time]");
				goto end;
			}
			recur_time_t *mbsr_recur_timeItem =
				recur_time_parseFromJSON(mbsr_recur_time_local);
			if(!mbsr_recur_timeItem) {
				printf("No mbsr_recur_timeItem");
				goto end;
			}
			list_add(mbsr_recur_timeList, mbsr_recur_timeItem);
		}
	}

	mbsr_time_info_local_var = mbsr_time_info_create(
		mbsr_time_window ? mbsr_time_windowList : NULL,
		mbsr_recur_time ? mbsr_recur_timeList : NULL
		);

	return mbsr_time_info_local_var;
end:
	if(mbsr_time_windowList) {
		list_for_each(mbsr_time_windowList, node) {
			valid_time_period_free(node->data);
		}
		list_free(mbsr_time_windowList);
		mbsr_time_windowList = NULL;
	}
	if(mbsr_recur_timeList) {
		list_for_each(mbsr_recur_timeList, node) {
			recur_time_free(node->data);
		}
		list_free(mbsr_recur_timeList);
		mbsr_recur_timeList = NULL;
	}
	return NULL;
}

mbsr_time_info_t *mbsr_time_info_copy(mbsr_time_info_t	*dst,
                                      mbsr_time_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = mbsr_time_info_convertToJSON(src);
	if(!item) {
		printf("mbsr_time_info_convertToJSON() failed");
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

	mbsr_time_info_free(dst);
	dst = mbsr_time_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
