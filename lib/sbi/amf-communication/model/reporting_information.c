#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_information.h"

reporting_information_t *reporting_information_create(bool is_imm_rep,
                                                      int imm_rep,
                                                      notification_method_1_t *notif_method, bool is_max_report_nbr, int max_report_nbr, char *mon_dur, bool is_rep_period, int rep_period, bool is_samp_ratio, int samp_ratio, list_t *partition_criteria, bool is_grp_rep_time, int grp_rep_time, notification_flag_t *notif_flag, muting_exception_instructions_t *notif_flag_instruct,
                                                      muting_notifications_settings_t *muting_setting)
{
	reporting_information_t *reporting_information_local_var = malloc(
		sizeof(reporting_information_t));

	reporting_information_local_var->is_imm_rep = is_imm_rep;
	reporting_information_local_var->imm_rep = imm_rep;
	reporting_information_local_var->notif_method = notif_method;
	reporting_information_local_var->is_max_report_nbr = is_max_report_nbr;
	reporting_information_local_var->max_report_nbr = max_report_nbr;
	reporting_information_local_var->mon_dur = mon_dur;
	reporting_information_local_var->is_rep_period = is_rep_period;
	reporting_information_local_var->rep_period = rep_period;
	reporting_information_local_var->is_samp_ratio = is_samp_ratio;
	reporting_information_local_var->samp_ratio = samp_ratio;
	reporting_information_local_var->partition_criteria =
		partition_criteria;
	reporting_information_local_var->is_grp_rep_time = is_grp_rep_time;
	reporting_information_local_var->grp_rep_time = grp_rep_time;
	reporting_information_local_var->notif_flag = notif_flag;
	reporting_information_local_var->notif_flag_instruct =
		notif_flag_instruct;
	reporting_information_local_var->muting_setting = muting_setting;

	return reporting_information_local_var;
}

void reporting_information_free(reporting_information_t *reporting_information)
{
	lnode_t *node = NULL;

	if(NULL == reporting_information) {
		return;
	}
	if(reporting_information->notif_method) {
		notification_method_1_free(reporting_information->notif_method);
		reporting_information->notif_method = NULL;
	}
	if(reporting_information->mon_dur) {
		free(reporting_information->mon_dur);
		reporting_information->mon_dur = NULL;
	}
	if(reporting_information->partition_criteria) {
		list_for_each(reporting_information->partition_criteria, node) {
			partitioning_criteria_free(node->data);
		}
		list_free(reporting_information->partition_criteria);
		reporting_information->partition_criteria = NULL;
	}
	if(reporting_information->notif_flag) {
		notification_flag_free(reporting_information->notif_flag);
		reporting_information->notif_flag = NULL;
	}
	if(reporting_information->notif_flag_instruct) {
		muting_exception_instructions_free(
			reporting_information->notif_flag_instruct);
		reporting_information->notif_flag_instruct = NULL;
	}
	if(reporting_information->muting_setting) {
		muting_notifications_settings_free(
			reporting_information->muting_setting);
		reporting_information->muting_setting = NULL;
	}
	free(reporting_information);
}

cJSON *reporting_information_convertToJSON(
	reporting_information_t *reporting_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(reporting_information == NULL) {
		printf(
			"reporting_information_convertToJSON() failed [ReportingInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(reporting_information->is_imm_rep) {
		if(cJSON_AddBoolToObject(item, "immRep",
		                         reporting_information->imm_rep) ==
		   NULL)
		{
			printf(
				"reporting_information_convertToJSON() failed [imm_rep]");
			goto end;
		}
	}

	if(reporting_information->notif_method) {
		cJSON *notif_method_local_JSON =
			notification_method_1_convertToJSON(
				reporting_information->notif_method);
		if(notif_method_local_JSON == NULL) {
			printf(
				"reporting_information_convertToJSON() failed [notif_method]");
			goto end;
		}
		cJSON_AddItemToObject(item, "notifMethod",
		                      notif_method_local_JSON);
		if(item->child == NULL) {
			printf(
				"reporting_information_convertToJSON() failed [notif_method]");
			goto end;
		}
	}

	if(reporting_information->is_max_report_nbr) {
		if(cJSON_AddNumberToObject(item, "maxReportNbr",
		                           reporting_information->max_report_nbr)
		   == NULL)
		{
			printf(
				"reporting_information_convertToJSON() failed [max_report_nbr]");
			goto end;
		}
	}

	if(reporting_information->mon_dur) {
		if(cJSON_AddStringToObject(item, "monDur",
		                           reporting_information->mon_dur) ==
		   NULL)
		{
			printf(
				"reporting_information_convertToJSON() failed [mon_dur]");
			goto end;
		}
	}

	if(reporting_information->is_rep_period) {
		if(cJSON_AddNumberToObject(item, "repPeriod",
		                           reporting_information->rep_period) ==
		   NULL)
		{
			printf(
				"reporting_information_convertToJSON() failed [rep_period]");
			goto end;
		}
	}

	if(reporting_information->is_samp_ratio) {
		if(cJSON_AddNumberToObject(item, "sampRatio",
		                           reporting_information->samp_ratio) ==
		   NULL)
		{
			printf(
				"reporting_information_convertToJSON() failed [samp_ratio]");
			goto end;
		}
	}

	if(reporting_information->partition_criteria) {
		cJSON *partition_criteriaList = cJSON_AddArrayToObject(item,
		                                                       "partitionCriteria");
		if(partition_criteriaList == NULL) {
			printf(
				"reporting_information_convertToJSON() failed [partition_criteria]");
			goto end;
		}
		list_for_each(reporting_information->partition_criteria, node) {
			cJSON *itemLocal = partitioning_criteria_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"reporting_information_convertToJSON() failed [partition_criteria]");
				goto end;
			}
			cJSON_AddItemToArray(partition_criteriaList, itemLocal);
		}
	}

	if(reporting_information->is_grp_rep_time) {
		if(cJSON_AddNumberToObject(item, "grpRepTime",
		                           reporting_information->grp_rep_time)
		   == NULL)
		{
			printf(
				"reporting_information_convertToJSON() failed [grp_rep_time]");
			goto end;
		}
	}

	if(reporting_information->notif_flag) {
		cJSON *notif_flag_local_JSON = notification_flag_convertToJSON(
			reporting_information->notif_flag);
		if(notif_flag_local_JSON == NULL) {
			printf(
				"reporting_information_convertToJSON() failed [notif_flag]");
			goto end;
		}
		cJSON_AddItemToObject(item, "notifFlag", notif_flag_local_JSON);
		if(item->child == NULL) {
			printf(
				"reporting_information_convertToJSON() failed [notif_flag]");
			goto end;
		}
	}

	if(reporting_information->notif_flag_instruct) {
		cJSON *notif_flag_instruct_local_JSON =
			muting_exception_instructions_convertToJSON(
				reporting_information->notif_flag_instruct);
		if(notif_flag_instruct_local_JSON == NULL) {
			printf(
				"reporting_information_convertToJSON() failed [notif_flag_instruct]");
			goto end;
		}
		cJSON_AddItemToObject(item, "notifFlagInstruct",
		                      notif_flag_instruct_local_JSON);
		if(item->child == NULL) {
			printf(
				"reporting_information_convertToJSON() failed [notif_flag_instruct]");
			goto end;
		}
	}

	if(reporting_information->muting_setting) {
		cJSON *muting_setting_local_JSON =
			muting_notifications_settings_convertToJSON(
				reporting_information->muting_setting);
		if(muting_setting_local_JSON == NULL) {
			printf(
				"reporting_information_convertToJSON() failed [muting_setting]");
			goto end;
		}
		cJSON_AddItemToObject(item, "mutingSetting",
		                      muting_setting_local_JSON);
		if(item->child == NULL) {
			printf(
				"reporting_information_convertToJSON() failed [muting_setting]");
			goto end;
		}
	}

end:
	return item;
}

reporting_information_t *reporting_information_parseFromJSON(
	cJSON *reporting_informationJSON) {
	reporting_information_t *reporting_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *imm_rep = NULL;
	cJSON *notif_method = NULL;
	notification_method_1_t *notif_method_local_nonprim = NULL;
	cJSON *max_report_nbr = NULL;
	cJSON *mon_dur = NULL;
	cJSON *rep_period = NULL;
	cJSON *samp_ratio = NULL;
	cJSON *partition_criteria = NULL;
	list_t *partition_criteriaList = NULL;
	cJSON *grp_rep_time = NULL;
	cJSON *notif_flag = NULL;
	notification_flag_t *notif_flag_local_nonprim = NULL;
	cJSON *notif_flag_instruct = NULL;
	muting_exception_instructions_t *notif_flag_instruct_local_nonprim =
		NULL;
	cJSON *muting_setting = NULL;
	muting_notifications_settings_t *muting_setting_local_nonprim = NULL;
	imm_rep = cJSON_GetObjectItemCaseSensitive(reporting_informationJSON,
	                                           "immRep");
	if(imm_rep) {
		if(!cJSON_IsBool(imm_rep)) {
			printf(
				"reporting_information_parseFromJSON() failed [imm_rep]");
			goto end;
		}
	}

	notif_method = cJSON_GetObjectItemCaseSensitive(
		reporting_informationJSON, "notifMethod");
	if(notif_method) {
		notif_method_local_nonprim =
			notification_method_1_parseFromJSON(notif_method);
		if(!notif_method_local_nonprim) {
			printf(
				"notification_method_1_parseFromJSON failed [notif_method]");
			goto end;
		}
	}

	max_report_nbr = cJSON_GetObjectItemCaseSensitive(
		reporting_informationJSON, "maxReportNbr");
	if(max_report_nbr) {
		if(!cJSON_IsNumber(max_report_nbr)) {
			printf(
				"reporting_information_parseFromJSON() failed [max_report_nbr]");
			goto end;
		}
	}

	mon_dur = cJSON_GetObjectItemCaseSensitive(reporting_informationJSON,
	                                           "monDur");
	if(mon_dur) {
		if(!cJSON_IsString(mon_dur) &&
		   !cJSON_IsNull(mon_dur))
		{
			printf(
				"reporting_information_parseFromJSON() failed [mon_dur]");
			goto end;
		}
	}

	rep_period = cJSON_GetObjectItemCaseSensitive(reporting_informationJSON,
	                                              "repPeriod");
	if(rep_period) {
		if(!cJSON_IsNumber(rep_period)) {
			printf(
				"reporting_information_parseFromJSON() failed [rep_period]");
			goto end;
		}
	}

	samp_ratio = cJSON_GetObjectItemCaseSensitive(reporting_informationJSON,
	                                              "sampRatio");
	if(samp_ratio) {
		if(!cJSON_IsNumber(samp_ratio)) {
			printf(
				"reporting_information_parseFromJSON() failed [samp_ratio]");
			goto end;
		}
	}

	partition_criteria = cJSON_GetObjectItemCaseSensitive(
		reporting_informationJSON, "partitionCriteria");
	if(partition_criteria) {
		cJSON *partition_criteria_local = NULL;
		if(!cJSON_IsArray(partition_criteria)) {
			printf(
				"reporting_information_parseFromJSON() failed [partition_criteria]");
			goto end;
		}

		partition_criteriaList = list_create();

		cJSON_ArrayForEach(partition_criteria_local,
		                   partition_criteria) {
			if(!cJSON_IsObject(partition_criteria_local)) {
				printf(
					"reporting_information_parseFromJSON() failed [partition_criteria]");
				goto end;
			}
			partitioning_criteria_t *partition_criteriaItem =
				partitioning_criteria_parseFromJSON(
					partition_criteria_local);
			if(!partition_criteriaItem) {
				printf("No partition_criteriaItem");
				goto end;
			}
			list_add(partition_criteriaList,
			         partition_criteriaItem);
		}
	}

	grp_rep_time = cJSON_GetObjectItemCaseSensitive(
		reporting_informationJSON, "grpRepTime");
	if(grp_rep_time) {
		if(!cJSON_IsNumber(grp_rep_time)) {
			printf(
				"reporting_information_parseFromJSON() failed [grp_rep_time]");
			goto end;
		}
	}

	notif_flag = cJSON_GetObjectItemCaseSensitive(reporting_informationJSON,
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

	notif_flag_instruct = cJSON_GetObjectItemCaseSensitive(
		reporting_informationJSON, "notifFlagInstruct");
	if(notif_flag_instruct) {
		notif_flag_instruct_local_nonprim =
			muting_exception_instructions_parseFromJSON(
				notif_flag_instruct);
		if(!notif_flag_instruct_local_nonprim) {
			printf(
				"muting_exception_instructions_parseFromJSON failed [notif_flag_instruct]");
			goto end;
		}
	}

	muting_setting = cJSON_GetObjectItemCaseSensitive(
		reporting_informationJSON, "mutingSetting");
	if(muting_setting) {
		muting_setting_local_nonprim =
			muting_notifications_settings_parseFromJSON(
				muting_setting);
		if(!muting_setting_local_nonprim) {
			printf(
				"muting_notifications_settings_parseFromJSON failed [muting_setting]");
			goto end;
		}
	}

	reporting_information_local_var = reporting_information_create(
		imm_rep ? true : false,
		imm_rep ? imm_rep->valueint : 0,
		notif_method ? notif_method_local_nonprim : NULL,
		max_report_nbr ? true : false,
		max_report_nbr ? max_report_nbr->valuedouble : 0,
		mon_dur &&
		!cJSON_IsNull(mon_dur) ? strdup(mon_dur->valuestring) : NULL,
		rep_period ? true : false,
		rep_period ? rep_period->valuedouble : 0,
		samp_ratio ? true : false,
		samp_ratio ? samp_ratio->valuedouble : 0,
		partition_criteria ? partition_criteriaList : NULL,
		grp_rep_time ? true : false,
		grp_rep_time ? grp_rep_time->valuedouble : 0,
		notif_flag ? notif_flag_local_nonprim : NULL,
		notif_flag_instruct ? notif_flag_instruct_local_nonprim : NULL,
		muting_setting ? muting_setting_local_nonprim : NULL
		);

	return reporting_information_local_var;
end:
	if(notif_method_local_nonprim) {
		notification_method_1_free(notif_method_local_nonprim);
		notif_method_local_nonprim = NULL;
	}
	if(partition_criteriaList) {
		list_for_each(partition_criteriaList, node) {
			partitioning_criteria_free(node->data);
		}
		list_free(partition_criteriaList);
		partition_criteriaList = NULL;
	}
	if(notif_flag_local_nonprim) {
		notification_flag_free(notif_flag_local_nonprim);
		notif_flag_local_nonprim = NULL;
	}
	if(notif_flag_instruct_local_nonprim) {
		muting_exception_instructions_free(
			notif_flag_instruct_local_nonprim);
		notif_flag_instruct_local_nonprim = NULL;
	}
	if(muting_setting_local_nonprim) {
		muting_notifications_settings_free(muting_setting_local_nonprim);
		muting_setting_local_nonprim = NULL;
	}
	return NULL;
}

reporting_information_t *reporting_information_copy(
	reporting_information_t *dst, reporting_information_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = reporting_information_convertToJSON(src);
	if(!item) {
		printf("reporting_information_convertToJSON() failed");
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

	reporting_information_free(dst);
	dst = reporting_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
