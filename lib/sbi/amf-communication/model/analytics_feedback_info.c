#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "analytics_feedback_info.h"

analytics_feedback_info_t *analytics_feedback_info_create(list_t *action_times,
                                                          list_t *used_ana_types, bool is_impact_ind,
                                                          int impact_ind) {
	analytics_feedback_info_t *analytics_feedback_info_local_var = malloc(
		sizeof(analytics_feedback_info_t));

	analytics_feedback_info_local_var->action_times = action_times;
	analytics_feedback_info_local_var->used_ana_types = used_ana_types;
	analytics_feedback_info_local_var->is_impact_ind = is_impact_ind;
	analytics_feedback_info_local_var->impact_ind = impact_ind;

	return analytics_feedback_info_local_var;
}

void analytics_feedback_info_free(
	analytics_feedback_info_t *analytics_feedback_info) {
	lnode_t *node = NULL;

	if(NULL == analytics_feedback_info) {
		return;
	}
	if(analytics_feedback_info->action_times) {
		list_for_each(analytics_feedback_info->action_times, node) {
			free(node->data);
		}
		list_free(analytics_feedback_info->action_times);
		analytics_feedback_info->action_times = NULL;
	}
	if(analytics_feedback_info->used_ana_types) {
		list_for_each(analytics_feedback_info->used_ana_types, node) {
			nwdaf_event_free(node->data);
		}
		list_free(analytics_feedback_info->used_ana_types);
		analytics_feedback_info->used_ana_types = NULL;
	}
	free(analytics_feedback_info);
}

cJSON *analytics_feedback_info_convertToJSON(
	analytics_feedback_info_t *analytics_feedback_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(analytics_feedback_info == NULL) {
		printf(
			"analytics_feedback_info_convertToJSON() failed [AnalyticsFeedbackInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!analytics_feedback_info->action_times) {
		printf(
			"analytics_feedback_info_convertToJSON() failed [action_times]");
		return NULL;
	}
	cJSON *action_timesList = cJSON_AddArrayToObject(item, "actionTimes");
	if(action_timesList == NULL) {
		printf(
			"analytics_feedback_info_convertToJSON() failed [action_times]");
		goto end;
	}
	list_for_each(analytics_feedback_info->action_times, node) {}

	if(analytics_feedback_info->used_ana_types) {
		cJSON *used_ana_typesList = cJSON_AddArrayToObject(item,
		                                                   "usedAnaTypes");
		if(used_ana_typesList == NULL) {
			printf(
				"analytics_feedback_info_convertToJSON() failed [used_ana_types]");
			goto end;
		}
		list_for_each(analytics_feedback_info->used_ana_types, node) {
			cJSON *itemLocal =
				nwdaf_event_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"analytics_feedback_info_convertToJSON() failed [used_ana_types]");
				goto end;
			}
			cJSON_AddItemToArray(used_ana_typesList, itemLocal);
		}
	}

	if(analytics_feedback_info->is_impact_ind) {
		if(cJSON_AddBoolToObject(item, "impactInd",
		                         analytics_feedback_info->impact_ind) ==
		   NULL)
		{
			printf(
				"analytics_feedback_info_convertToJSON() failed [impact_ind]");
			goto end;
		}
	}

end:
	return item;
}

analytics_feedback_info_t *analytics_feedback_info_parseFromJSON(
	cJSON *analytics_feedback_infoJSON) {
	analytics_feedback_info_t *analytics_feedback_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *action_times = NULL;
	list_t *action_timesList = NULL;
	cJSON *used_ana_types = NULL;
	list_t *used_ana_typesList = NULL;
	cJSON *impact_ind = NULL;
	action_times = cJSON_GetObjectItemCaseSensitive(
		analytics_feedback_infoJSON, "actionTimes");
	if(!action_times) {
		printf(
			"analytics_feedback_info_parseFromJSON() failed [action_times]");
		goto end;
	}
	cJSON *action_times_local = NULL;
	if(!cJSON_IsArray(action_times)) {
		printf(
			"analytics_feedback_info_parseFromJSON() failed [action_times]");
		goto end;
	}

	action_timesList = list_create();

	cJSON_ArrayForEach(action_times_local, action_times) {
		double *localDouble = NULL;
		int *localInt = NULL;
	}

	used_ana_types = cJSON_GetObjectItemCaseSensitive(
		analytics_feedback_infoJSON, "usedAnaTypes");
	if(used_ana_types) {
		cJSON *used_ana_types_local = NULL;
		if(!cJSON_IsArray(used_ana_types)) {
			printf(
				"analytics_feedback_info_parseFromJSON() failed [used_ana_types]");
			goto end;
		}

		used_ana_typesList = list_create();

		cJSON_ArrayForEach(used_ana_types_local, used_ana_types) {
			if(!cJSON_IsObject(used_ana_types_local)) {
				printf(
					"analytics_feedback_info_parseFromJSON() failed [used_ana_types]");
				goto end;
			}
			nwdaf_event_t *used_ana_typesItem =
				nwdaf_event_parseFromJSON(used_ana_types_local);
			if(!used_ana_typesItem) {
				printf("No used_ana_typesItem");
				goto end;
			}
			list_add(used_ana_typesList, used_ana_typesItem);
		}
	}

	impact_ind = cJSON_GetObjectItemCaseSensitive(
		analytics_feedback_infoJSON, "impactInd");
	if(impact_ind) {
		if(!cJSON_IsBool(impact_ind)) {
			printf(
				"analytics_feedback_info_parseFromJSON() failed [impact_ind]");
			goto end;
		}
	}

	analytics_feedback_info_local_var = analytics_feedback_info_create(
		action_timesList,
		used_ana_types ? used_ana_typesList : NULL,
		impact_ind ? true : false,
		impact_ind ? impact_ind->valueint : 0
		);

	return analytics_feedback_info_local_var;
end:
	if(action_timesList) {
		list_for_each(action_timesList, node) {
			free(node->data);
		}
		list_free(action_timesList);
		action_timesList = NULL;
	}
	if(used_ana_typesList) {
		list_for_each(used_ana_typesList, node) {
			nwdaf_event_free(node->data);
		}
		list_free(used_ana_typesList);
		used_ana_typesList = NULL;
	}
	return NULL;
}

analytics_feedback_info_t *analytics_feedback_info_copy(
	analytics_feedback_info_t *dst, analytics_feedback_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = analytics_feedback_info_convertToJSON(src);
	if(!item) {
		printf("analytics_feedback_info_convertToJSON() failed");
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

	analytics_feedback_info_free(dst);
	dst = analytics_feedback_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
