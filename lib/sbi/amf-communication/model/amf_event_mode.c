#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "amf_event_mode.h"

amf_event_mode_t *amf_event_mode_create(amf_event_trigger_t *trigger,
                                        bool is_max_reports, int max_reports,
                                        char *expiry, bool is_rep_period,
                                        int rep_period, bool is_samp_ratio,
                                        int samp_ratio,
                                        list_t *partitioning_criteria,
                                        notification_flag_t *notif_flag,
                                        amf_event_mode_muting_exc_instructions_t *muting_exc_instructions, muting_notifications_settings_t *muting_not_settings,
                                        list_t *var_rep_period_info) {
	amf_event_mode_t *amf_event_mode_local_var =
		malloc(sizeof(amf_event_mode_t));

	amf_event_mode_local_var->trigger = trigger;
	amf_event_mode_local_var->is_max_reports = is_max_reports;
	amf_event_mode_local_var->max_reports = max_reports;
	amf_event_mode_local_var->expiry = expiry;
	amf_event_mode_local_var->is_rep_period = is_rep_period;
	amf_event_mode_local_var->rep_period = rep_period;
	amf_event_mode_local_var->is_samp_ratio = is_samp_ratio;
	amf_event_mode_local_var->samp_ratio = samp_ratio;
	amf_event_mode_local_var->partitioning_criteria = partitioning_criteria;
	amf_event_mode_local_var->notif_flag = notif_flag;
	amf_event_mode_local_var->muting_exc_instructions =
		muting_exc_instructions;
	amf_event_mode_local_var->muting_not_settings = muting_not_settings;
	amf_event_mode_local_var->var_rep_period_info = var_rep_period_info;

	return amf_event_mode_local_var;
}

void amf_event_mode_free(amf_event_mode_t *amf_event_mode) {
	lnode_t *node = NULL;

	if(NULL == amf_event_mode) {
		return;
	}
	if(amf_event_mode->trigger) {
		amf_event_trigger_free(amf_event_mode->trigger);
		amf_event_mode->trigger = NULL;
	}
	if(amf_event_mode->expiry) {
		free(amf_event_mode->expiry);
		amf_event_mode->expiry = NULL;
	}
	if(amf_event_mode->partitioning_criteria) {
		list_for_each(amf_event_mode->partitioning_criteria, node) {
			partitioning_criteria_free(node->data);
		}
		list_free(amf_event_mode->partitioning_criteria);
		amf_event_mode->partitioning_criteria = NULL;
	}
	if(amf_event_mode->notif_flag) {
		notification_flag_free(amf_event_mode->notif_flag);
		amf_event_mode->notif_flag = NULL;
	}
	if(amf_event_mode->muting_exc_instructions) {
		amf_event_mode_muting_exc_instructions_free(
			amf_event_mode->muting_exc_instructions);
		amf_event_mode->muting_exc_instructions = NULL;
	}
	if(amf_event_mode->muting_not_settings) {
		muting_notifications_settings_free(
			amf_event_mode->muting_not_settings);
		amf_event_mode->muting_not_settings = NULL;
	}
	if(amf_event_mode->var_rep_period_info) {
		list_for_each(amf_event_mode->var_rep_period_info, node) {
			var_rep_period_free(node->data);
		}
		list_free(amf_event_mode->var_rep_period_info);
		amf_event_mode->var_rep_period_info = NULL;
	}
	free(amf_event_mode);
}

cJSON *amf_event_mode_convertToJSON(amf_event_mode_t *amf_event_mode) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(amf_event_mode == NULL) {
		printf("amf_event_mode_convertToJSON() failed [AmfEventMode]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!amf_event_mode->trigger) {
		printf("amf_event_mode_convertToJSON() failed [trigger]");
		return NULL;
	}
	cJSON *trigger_local_JSON = amf_event_trigger_convertToJSON(
		amf_event_mode->trigger);
	if(trigger_local_JSON == NULL) {
		printf("amf_event_mode_convertToJSON() failed [trigger]");
		goto end;
	}
	cJSON_AddItemToObject(item, "trigger", trigger_local_JSON);
	if(item->child == NULL) {
		printf("amf_event_mode_convertToJSON() failed [trigger]");
		goto end;
	}

	if(amf_event_mode->is_max_reports) {
		if(cJSON_AddNumberToObject(item, "maxReports",
		                           amf_event_mode->max_reports) == NULL)
		{
			printf(
				"amf_event_mode_convertToJSON() failed [max_reports]");
			goto end;
		}
	}

	if(amf_event_mode->expiry) {
		if(cJSON_AddStringToObject(item, "expiry",
		                           amf_event_mode->expiry) == NULL)
		{
			printf("amf_event_mode_convertToJSON() failed [expiry]");
			goto end;
		}
	}

	if(amf_event_mode->is_rep_period) {
		if(cJSON_AddNumberToObject(item, "repPeriod",
		                           amf_event_mode->rep_period) == NULL)
		{
			printf(
				"amf_event_mode_convertToJSON() failed [rep_period]");
			goto end;
		}
	}

	if(amf_event_mode->is_samp_ratio) {
		if(cJSON_AddNumberToObject(item, "sampRatio",
		                           amf_event_mode->samp_ratio) == NULL)
		{
			printf(
				"amf_event_mode_convertToJSON() failed [samp_ratio]");
			goto end;
		}
	}

	if(amf_event_mode->partitioning_criteria) {
		cJSON *partitioning_criteriaList = cJSON_AddArrayToObject(item,
		                                                          "partitioningCriteria");
		if(partitioning_criteriaList == NULL) {
			printf(
				"amf_event_mode_convertToJSON() failed [partitioning_criteria]");
			goto end;
		}
		list_for_each(amf_event_mode->partitioning_criteria, node) {
			cJSON *itemLocal = partitioning_criteria_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"amf_event_mode_convertToJSON() failed [partitioning_criteria]");
				goto end;
			}
			cJSON_AddItemToArray(partitioning_criteriaList,
			                     itemLocal);
		}
	}

	if(amf_event_mode->notif_flag) {
		cJSON *notif_flag_local_JSON = notification_flag_convertToJSON(
			amf_event_mode->notif_flag);
		if(notif_flag_local_JSON == NULL) {
			printf(
				"amf_event_mode_convertToJSON() failed [notif_flag]");
			goto end;
		}
		cJSON_AddItemToObject(item, "notifFlag", notif_flag_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_mode_convertToJSON() failed [notif_flag]");
			goto end;
		}
	}

	if(amf_event_mode->muting_exc_instructions) {
		cJSON *muting_exc_instructions_local_JSON =
			amf_event_mode_muting_exc_instructions_convertToJSON(
				amf_event_mode->muting_exc_instructions);
		if(muting_exc_instructions_local_JSON == NULL) {
			printf(
				"amf_event_mode_convertToJSON() failed [muting_exc_instructions]");
			goto end;
		}
		cJSON_AddItemToObject(item, "mutingExcInstructions",
		                      muting_exc_instructions_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_mode_convertToJSON() failed [muting_exc_instructions]");
			goto end;
		}
	}

	if(amf_event_mode->muting_not_settings) {
		cJSON *muting_not_settings_local_JSON =
			muting_notifications_settings_convertToJSON(
				amf_event_mode->muting_not_settings);
		if(muting_not_settings_local_JSON == NULL) {
			printf(
				"amf_event_mode_convertToJSON() failed [muting_not_settings]");
			goto end;
		}
		cJSON_AddItemToObject(item, "mutingNotSettings",
		                      muting_not_settings_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_mode_convertToJSON() failed [muting_not_settings]");
			goto end;
		}
	}

	if(amf_event_mode->var_rep_period_info) {
		cJSON *var_rep_period_infoList = cJSON_AddArrayToObject(item,
		                                                        "varRepPeriodInfo");
		if(var_rep_period_infoList == NULL) {
			printf(
				"amf_event_mode_convertToJSON() failed [var_rep_period_info]");
			goto end;
		}
		list_for_each(amf_event_mode->var_rep_period_info, node) {
			cJSON *itemLocal = var_rep_period_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"amf_event_mode_convertToJSON() failed [var_rep_period_info]");
				goto end;
			}
			cJSON_AddItemToArray(var_rep_period_infoList,
			                     itemLocal);
		}
	}

end:
	return item;
}

amf_event_mode_t *amf_event_mode_parseFromJSON(cJSON *amf_event_modeJSON) {
	amf_event_mode_t *amf_event_mode_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *trigger = NULL;
	amf_event_trigger_t *trigger_local_nonprim = NULL;
	cJSON *max_reports = NULL;
	cJSON *expiry = NULL;
	cJSON *rep_period = NULL;
	cJSON *samp_ratio = NULL;
	cJSON *partitioning_criteria = NULL;
	list_t *partitioning_criteriaList = NULL;
	cJSON *notif_flag = NULL;
	notification_flag_t *notif_flag_local_nonprim = NULL;
	cJSON *muting_exc_instructions = NULL;
	amf_event_mode_muting_exc_instructions_t *
	        muting_exc_instructions_local_nonprim = NULL;
	cJSON *muting_not_settings = NULL;
	muting_notifications_settings_t *muting_not_settings_local_nonprim =
		NULL;
	cJSON *var_rep_period_info = NULL;
	list_t *var_rep_period_infoList = NULL;
	trigger =
		cJSON_GetObjectItemCaseSensitive(amf_event_modeJSON, "trigger");
	if(!trigger) {
		printf("amf_event_mode_parseFromJSON() failed [trigger]");
		goto end;
	}
	trigger_local_nonprim = amf_event_trigger_parseFromJSON(trigger);
	if(!trigger_local_nonprim) {
		printf("amf_event_trigger_parseFromJSON failed [trigger]");
		goto end;
	}

	max_reports = cJSON_GetObjectItemCaseSensitive(amf_event_modeJSON,
	                                               "maxReports");
	if(max_reports) {
		if(!cJSON_IsNumber(max_reports)) {
			printf(
				"amf_event_mode_parseFromJSON() failed [max_reports]");
			goto end;
		}
	}

	expiry = cJSON_GetObjectItemCaseSensitive(amf_event_modeJSON, "expiry");
	if(expiry) {
		if(!cJSON_IsString(expiry) &&
		   !cJSON_IsNull(expiry))
		{
			printf("amf_event_mode_parseFromJSON() failed [expiry]");
			goto end;
		}
	}

	rep_period = cJSON_GetObjectItemCaseSensitive(amf_event_modeJSON,
	                                              "repPeriod");
	if(rep_period) {
		if(!cJSON_IsNumber(rep_period)) {
			printf(
				"amf_event_mode_parseFromJSON() failed [rep_period]");
			goto end;
		}
	}

	samp_ratio = cJSON_GetObjectItemCaseSensitive(amf_event_modeJSON,
	                                              "sampRatio");
	if(samp_ratio) {
		if(!cJSON_IsNumber(samp_ratio)) {
			printf(
				"amf_event_mode_parseFromJSON() failed [samp_ratio]");
			goto end;
		}
	}

	partitioning_criteria = cJSON_GetObjectItemCaseSensitive(
		amf_event_modeJSON, "partitioningCriteria");
	if(partitioning_criteria) {
		cJSON *partitioning_criteria_local = NULL;
		if(!cJSON_IsArray(partitioning_criteria)) {
			printf(
				"amf_event_mode_parseFromJSON() failed [partitioning_criteria]");
			goto end;
		}

		partitioning_criteriaList = list_create();

		cJSON_ArrayForEach(partitioning_criteria_local,
		                   partitioning_criteria) {
			if(!cJSON_IsObject(partitioning_criteria_local)) {
				printf(
					"amf_event_mode_parseFromJSON() failed [partitioning_criteria]");
				goto end;
			}
			partitioning_criteria_t *partitioning_criteriaItem =
				partitioning_criteria_parseFromJSON(
					partitioning_criteria_local);
			if(!partitioning_criteriaItem) {
				printf("No partitioning_criteriaItem");
				goto end;
			}
			list_add(partitioning_criteriaList,
			         partitioning_criteriaItem);
		}
	}

	notif_flag = cJSON_GetObjectItemCaseSensitive(amf_event_modeJSON,
	                                              "notifFlag");
	if(notif_flag) {
		notif_flag_local_nonprim = notification_flag_parseFromJSON(
			notif_flag);
		if(!notif_flag_local_nonprim) {
			printf(
				"notification_flag_parseFromJSON failed [notif_flag]");
			goto end;
		}
	}

	muting_exc_instructions = cJSON_GetObjectItemCaseSensitive(
		amf_event_modeJSON, "mutingExcInstructions");
	if(muting_exc_instructions) {
		muting_exc_instructions_local_nonprim =
			amf_event_mode_muting_exc_instructions_parseFromJSON(
				muting_exc_instructions);
		if(!muting_exc_instructions_local_nonprim) {
			printf(
				"amf_event_mode_muting_exc_instructions_parseFromJSON failed [muting_exc_instructions]");
			goto end;
		}
	}

	muting_not_settings = cJSON_GetObjectItemCaseSensitive(
		amf_event_modeJSON, "mutingNotSettings");
	if(muting_not_settings) {
		muting_not_settings_local_nonprim =
			muting_notifications_settings_parseFromJSON(
				muting_not_settings);
		if(!muting_not_settings_local_nonprim) {
			printf(
				"muting_notifications_settings_parseFromJSON failed [muting_not_settings]");
			goto end;
		}
	}

	var_rep_period_info = cJSON_GetObjectItemCaseSensitive(
		amf_event_modeJSON, "varRepPeriodInfo");
	if(var_rep_period_info) {
		cJSON *var_rep_period_info_local = NULL;
		if(!cJSON_IsArray(var_rep_period_info)) {
			printf(
				"amf_event_mode_parseFromJSON() failed [var_rep_period_info]");
			goto end;
		}

		var_rep_period_infoList = list_create();

		cJSON_ArrayForEach(var_rep_period_info_local,
		                   var_rep_period_info) {
			if(!cJSON_IsObject(var_rep_period_info_local)) {
				printf(
					"amf_event_mode_parseFromJSON() failed [var_rep_period_info]");
				goto end;
			}
			var_rep_period_t *var_rep_period_infoItem =
				var_rep_period_parseFromJSON(
					var_rep_period_info_local);
			if(!var_rep_period_infoItem) {
				printf("No var_rep_period_infoItem");
				goto end;
			}
			list_add(var_rep_period_infoList,
			         var_rep_period_infoItem);
		}
	}

	amf_event_mode_local_var = amf_event_mode_create(
		trigger_local_nonprim,
		max_reports ? true : false,
		max_reports ? max_reports->valuedouble : 0,
		expiry &&
		!cJSON_IsNull(expiry) ? strdup(
			expiry->valuestring) : NULL,
		rep_period ? true : false,
		rep_period ? rep_period->valuedouble : 0,
		samp_ratio ? true : false,
		samp_ratio ? samp_ratio->valuedouble : 0,
		partitioning_criteria ? partitioning_criteriaList : NULL,
		notif_flag ? notif_flag_local_nonprim : NULL,
		muting_exc_instructions ? muting_exc_instructions_local_nonprim : NULL,
		muting_not_settings ? muting_not_settings_local_nonprim : NULL,
		var_rep_period_info ? var_rep_period_infoList : NULL
		);

	return amf_event_mode_local_var;
end:
	if(trigger_local_nonprim) {
		amf_event_trigger_free(trigger_local_nonprim);
		trigger_local_nonprim = NULL;
	}
	if(partitioning_criteriaList) {
		list_for_each(partitioning_criteriaList, node) {
			partitioning_criteria_free(node->data);
		}
		list_free(partitioning_criteriaList);
		partitioning_criteriaList = NULL;
	}
	if(notif_flag_local_nonprim) {
		notification_flag_free(notif_flag_local_nonprim);
		notif_flag_local_nonprim = NULL;
	}
	if(muting_exc_instructions_local_nonprim) {
		amf_event_mode_muting_exc_instructions_free(
			muting_exc_instructions_local_nonprim);
		muting_exc_instructions_local_nonprim = NULL;
	}
	if(muting_not_settings_local_nonprim) {
		muting_notifications_settings_free(
			muting_not_settings_local_nonprim);
		muting_not_settings_local_nonprim = NULL;
	}
	if(var_rep_period_infoList) {
		list_for_each(var_rep_period_infoList, node) {
			var_rep_period_free(node->data);
		}
		list_free(var_rep_period_infoList);
		var_rep_period_infoList = NULL;
	}
	return NULL;
}

amf_event_mode_t *amf_event_mode_copy(amf_event_mode_t	*dst,
                                      amf_event_mode_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = amf_event_mode_convertToJSON(src);
	if(!item) {
		printf("amf_event_mode_convertToJSON() failed");
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

	amf_event_mode_free(dst);
	dst = amf_event_mode_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
