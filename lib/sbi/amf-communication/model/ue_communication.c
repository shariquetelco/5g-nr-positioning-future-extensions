#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_communication.h"

ue_communication_t *ue_communication_create(bool is_comm_dur, int comm_dur,
                                            bool is_comm_dur_variance,
                                            float comm_dur_variance,
                                            bool is_perio_time, int perio_time,
                                            bool is_perio_time_variance,
                                            float perio_time_variance, char *ts,
                                            bool is_ts_variance,
                                            float ts_variance,
                                            scheduled_communication_time_1_t *recurring_time, traffic_characterization_t *traf_char, bool is_ratio, int ratio, bool is_perio_comm_ind, int perio_comm_ind, bool is_confidence, int confidence, app_list_for_ue_comm_t *ana_of_app_list,
                                            sess_inact_timer_for_ue_comm_t *sess_inact_timer)
{
	ue_communication_t *ue_communication_local_var =
		malloc(sizeof(ue_communication_t));

	ue_communication_local_var->is_comm_dur = is_comm_dur;
	ue_communication_local_var->comm_dur = comm_dur;
	ue_communication_local_var->is_comm_dur_variance = is_comm_dur_variance;
	ue_communication_local_var->comm_dur_variance = comm_dur_variance;
	ue_communication_local_var->is_perio_time = is_perio_time;
	ue_communication_local_var->perio_time = perio_time;
	ue_communication_local_var->is_perio_time_variance =
		is_perio_time_variance;
	ue_communication_local_var->perio_time_variance = perio_time_variance;
	ue_communication_local_var->ts = ts;
	ue_communication_local_var->is_ts_variance = is_ts_variance;
	ue_communication_local_var->ts_variance = ts_variance;
	ue_communication_local_var->recurring_time = recurring_time;
	ue_communication_local_var->traf_char = traf_char;
	ue_communication_local_var->is_ratio = is_ratio;
	ue_communication_local_var->ratio = ratio;
	ue_communication_local_var->is_perio_comm_ind = is_perio_comm_ind;
	ue_communication_local_var->perio_comm_ind = perio_comm_ind;
	ue_communication_local_var->is_confidence = is_confidence;
	ue_communication_local_var->confidence = confidence;
	ue_communication_local_var->ana_of_app_list = ana_of_app_list;
	ue_communication_local_var->sess_inact_timer = sess_inact_timer;

	return ue_communication_local_var;
}

void ue_communication_free(ue_communication_t *ue_communication) {
	lnode_t *node = NULL;

	if(NULL == ue_communication) {
		return;
	}
	if(ue_communication->ts) {
		free(ue_communication->ts);
		ue_communication->ts = NULL;
	}
	if(ue_communication->recurring_time) {
		scheduled_communication_time_1_free(
			ue_communication->recurring_time);
		ue_communication->recurring_time = NULL;
	}
	if(ue_communication->traf_char) {
		traffic_characterization_free(ue_communication->traf_char);
		ue_communication->traf_char = NULL;
	}
	if(ue_communication->ana_of_app_list) {
		app_list_for_ue_comm_free(ue_communication->ana_of_app_list);
		ue_communication->ana_of_app_list = NULL;
	}
	if(ue_communication->sess_inact_timer) {
		sess_inact_timer_for_ue_comm_free(
			ue_communication->sess_inact_timer);
		ue_communication->sess_inact_timer = NULL;
	}
	free(ue_communication);
}

cJSON *ue_communication_convertToJSON(ue_communication_t *ue_communication) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_communication == NULL) {
		printf(
			"ue_communication_convertToJSON() failed [UeCommunication]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_communication->is_comm_dur) {
		if(cJSON_AddNumberToObject(item, "commDur",
		                           ue_communication->comm_dur) == NULL)
		{
			printf(
				"ue_communication_convertToJSON() failed [comm_dur]");
			goto end;
		}
	}

	if(ue_communication->is_comm_dur_variance) {
		if(cJSON_AddNumberToObject(item, "commDurVariance",
		                           ue_communication->comm_dur_variance)
		   == NULL)
		{
			printf(
				"ue_communication_convertToJSON() failed [comm_dur_variance]");
			goto end;
		}
	}

	if(ue_communication->is_perio_time) {
		if(cJSON_AddNumberToObject(item, "perioTime",
		                           ue_communication->perio_time) ==
		   NULL)
		{
			printf(
				"ue_communication_convertToJSON() failed [perio_time]");
			goto end;
		}
	}

	if(ue_communication->is_perio_time_variance) {
		if(cJSON_AddNumberToObject(item, "perioTimeVariance",
		                           ue_communication->perio_time_variance)
		   == NULL)
		{
			printf(
				"ue_communication_convertToJSON() failed [perio_time_variance]");
			goto end;
		}
	}

	if(ue_communication->ts) {
		if(cJSON_AddStringToObject(item, "ts",
		                           ue_communication->ts) == NULL)
		{
			printf("ue_communication_convertToJSON() failed [ts]");
			goto end;
		}
	}

	if(ue_communication->is_ts_variance) {
		if(cJSON_AddNumberToObject(item, "tsVariance",
		                           ue_communication->ts_variance) ==
		   NULL)
		{
			printf(
				"ue_communication_convertToJSON() failed [ts_variance]");
			goto end;
		}
	}

	if(ue_communication->recurring_time) {
		cJSON *recurring_time_local_JSON =
			scheduled_communication_time_1_convertToJSON(
				ue_communication->recurring_time);
		if(recurring_time_local_JSON == NULL) {
			printf(
				"ue_communication_convertToJSON() failed [recurring_time]");
			goto end;
		}
		cJSON_AddItemToObject(item, "recurringTime",
		                      recurring_time_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_communication_convertToJSON() failed [recurring_time]");
			goto end;
		}
	}

	if(ue_communication->traf_char) {
		cJSON *traf_char_local_JSON =
			traffic_characterization_convertToJSON(
				ue_communication->traf_char);
		if(traf_char_local_JSON == NULL) {
			printf(
				"ue_communication_convertToJSON() failed [traf_char]");
			goto end;
		}
		cJSON_AddItemToObject(item, "trafChar", traf_char_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_communication_convertToJSON() failed [traf_char]");
			goto end;
		}
	}

	if(ue_communication->is_ratio) {
		if(cJSON_AddNumberToObject(item, "ratio",
		                           ue_communication->ratio) == NULL)
		{
			printf("ue_communication_convertToJSON() failed [ratio]");
			goto end;
		}
	}

	if(ue_communication->is_perio_comm_ind) {
		if(cJSON_AddBoolToObject(item, "perioCommInd",
		                         ue_communication->perio_comm_ind) ==
		   NULL)
		{
			printf(
				"ue_communication_convertToJSON() failed [perio_comm_ind]");
			goto end;
		}
	}

	if(ue_communication->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           ue_communication->confidence) ==
		   NULL)
		{
			printf(
				"ue_communication_convertToJSON() failed [confidence]");
			goto end;
		}
	}

	if(ue_communication->ana_of_app_list) {
		cJSON *ana_of_app_list_local_JSON =
			app_list_for_ue_comm_convertToJSON(
				ue_communication->ana_of_app_list);
		if(ana_of_app_list_local_JSON == NULL) {
			printf(
				"ue_communication_convertToJSON() failed [ana_of_app_list]");
			goto end;
		}
		cJSON_AddItemToObject(item, "anaOfAppList",
		                      ana_of_app_list_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_communication_convertToJSON() failed [ana_of_app_list]");
			goto end;
		}
	}

	if(ue_communication->sess_inact_timer) {
		cJSON *sess_inact_timer_local_JSON =
			sess_inact_timer_for_ue_comm_convertToJSON(
				ue_communication->sess_inact_timer);
		if(sess_inact_timer_local_JSON == NULL) {
			printf(
				"ue_communication_convertToJSON() failed [sess_inact_timer]");
			goto end;
		}
		cJSON_AddItemToObject(item, "sessInactTimer",
		                      sess_inact_timer_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_communication_convertToJSON() failed [sess_inact_timer]");
			goto end;
		}
	}

end:
	return item;
}

ue_communication_t *ue_communication_parseFromJSON(cJSON *ue_communicationJSON)
{
	ue_communication_t *ue_communication_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *comm_dur = NULL;
	cJSON *comm_dur_variance = NULL;
	cJSON *perio_time = NULL;
	cJSON *perio_time_variance = NULL;
	cJSON *ts = NULL;
	cJSON *ts_variance = NULL;
	cJSON *recurring_time = NULL;
	scheduled_communication_time_1_t *recurring_time_local_nonprim = NULL;
	cJSON *traf_char = NULL;
	traffic_characterization_t *traf_char_local_nonprim = NULL;
	cJSON *ratio = NULL;
	cJSON *perio_comm_ind = NULL;
	cJSON *confidence = NULL;
	cJSON *ana_of_app_list = NULL;
	app_list_for_ue_comm_t *ana_of_app_list_local_nonprim = NULL;
	cJSON *sess_inact_timer = NULL;
	sess_inact_timer_for_ue_comm_t *sess_inact_timer_local_nonprim = NULL;
	comm_dur = cJSON_GetObjectItemCaseSensitive(ue_communicationJSON,
	                                            "commDur");
	if(comm_dur) {
		if(!cJSON_IsNumber(comm_dur)) {
			printf(
				"ue_communication_parseFromJSON() failed [comm_dur]");
			goto end;
		}
	}

	comm_dur_variance = cJSON_GetObjectItemCaseSensitive(
		ue_communicationJSON, "commDurVariance");
	if(comm_dur_variance) {
		if(!cJSON_IsNumber(comm_dur_variance)) {
			printf(
				"ue_communication_parseFromJSON() failed [comm_dur_variance]");
			goto end;
		}
	}

	perio_time = cJSON_GetObjectItemCaseSensitive(ue_communicationJSON,
	                                              "perioTime");
	if(perio_time) {
		if(!cJSON_IsNumber(perio_time)) {
			printf(
				"ue_communication_parseFromJSON() failed [perio_time]");
			goto end;
		}
	}

	perio_time_variance = cJSON_GetObjectItemCaseSensitive(
		ue_communicationJSON, "perioTimeVariance");
	if(perio_time_variance) {
		if(!cJSON_IsNumber(perio_time_variance)) {
			printf(
				"ue_communication_parseFromJSON() failed [perio_time_variance]");
			goto end;
		}
	}

	ts = cJSON_GetObjectItemCaseSensitive(ue_communicationJSON, "ts");
	if(ts) {
		if(!cJSON_IsString(ts) &&
		   !cJSON_IsNull(ts))
		{
			printf("ue_communication_parseFromJSON() failed [ts]");
			goto end;
		}
	}

	ts_variance = cJSON_GetObjectItemCaseSensitive(ue_communicationJSON,
	                                               "tsVariance");
	if(ts_variance) {
		if(!cJSON_IsNumber(ts_variance)) {
			printf(
				"ue_communication_parseFromJSON() failed [ts_variance]");
			goto end;
		}
	}

	recurring_time = cJSON_GetObjectItemCaseSensitive(ue_communicationJSON,
	                                                  "recurringTime");
	if(recurring_time) {
		recurring_time_local_nonprim =
			scheduled_communication_time_1_parseFromJSON(
				recurring_time);
		if(!recurring_time_local_nonprim) {
			printf(
				"scheduled_communication_time_1_parseFromJSON failed [recurring_time]");
			goto end;
		}
	}

	traf_char = cJSON_GetObjectItemCaseSensitive(ue_communicationJSON,
	                                             "trafChar");
	if(traf_char) {
		traf_char_local_nonprim =
			traffic_characterization_parseFromJSON(traf_char);
		if(!traf_char_local_nonprim) {
			printf(
				"traffic_characterization_parseFromJSON failed [traf_char]");
			goto end;
		}
	}

	ratio = cJSON_GetObjectItemCaseSensitive(ue_communicationJSON, "ratio");
	if(ratio) {
		if(!cJSON_IsNumber(ratio)) {
			printf("ue_communication_parseFromJSON() failed [ratio]");
			goto end;
		}
	}

	perio_comm_ind = cJSON_GetObjectItemCaseSensitive(ue_communicationJSON,
	                                                  "perioCommInd");
	if(perio_comm_ind) {
		if(!cJSON_IsBool(perio_comm_ind)) {
			printf(
				"ue_communication_parseFromJSON() failed [perio_comm_ind]");
			goto end;
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(ue_communicationJSON,
	                                              "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"ue_communication_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	ana_of_app_list = cJSON_GetObjectItemCaseSensitive(ue_communicationJSON,
	                                                   "anaOfAppList");
	if(ana_of_app_list) {
		ana_of_app_list_local_nonprim =
			app_list_for_ue_comm_parseFromJSON(ana_of_app_list);
		if(!ana_of_app_list_local_nonprim) {
			printf(
				"app_list_for_ue_comm_parseFromJSON failed [ana_of_app_list]");
			goto end;
		}
	}

	sess_inact_timer = cJSON_GetObjectItemCaseSensitive(
		ue_communicationJSON, "sessInactTimer");
	if(sess_inact_timer) {
		sess_inact_timer_local_nonprim =
			sess_inact_timer_for_ue_comm_parseFromJSON(
				sess_inact_timer);
		if(!sess_inact_timer_local_nonprim) {
			printf(
				"sess_inact_timer_for_ue_comm_parseFromJSON failed [sess_inact_timer]");
			goto end;
		}
	}

	ue_communication_local_var = ue_communication_create(
		comm_dur ? true : false,
		comm_dur ? comm_dur->valuedouble : 0,
		comm_dur_variance ? true : false,
		comm_dur_variance ? comm_dur_variance->valuedouble : 0,
		perio_time ? true : false,
		perio_time ? perio_time->valuedouble : 0,
		perio_time_variance ? true : false,
		perio_time_variance ? perio_time_variance->valuedouble : 0,
		ts &&
		!cJSON_IsNull(ts) ? strdup(ts->valuestring) : NULL,
		ts_variance ? true : false,
		ts_variance ? ts_variance->valuedouble : 0,
		recurring_time ? recurring_time_local_nonprim : NULL,
		traf_char ? traf_char_local_nonprim : NULL,
		ratio ? true : false,
		ratio ? ratio->valuedouble : 0,
		perio_comm_ind ? true : false,
		perio_comm_ind ? perio_comm_ind->valueint : 0,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0,
		ana_of_app_list ? ana_of_app_list_local_nonprim : NULL,
		sess_inact_timer ? sess_inact_timer_local_nonprim : NULL
		);

	return ue_communication_local_var;
end:
	if(recurring_time_local_nonprim) {
		scheduled_communication_time_1_free(recurring_time_local_nonprim);
		recurring_time_local_nonprim = NULL;
	}
	if(traf_char_local_nonprim) {
		traffic_characterization_free(traf_char_local_nonprim);
		traf_char_local_nonprim = NULL;
	}
	if(ana_of_app_list_local_nonprim) {
		app_list_for_ue_comm_free(ana_of_app_list_local_nonprim);
		ana_of_app_list_local_nonprim = NULL;
	}
	if(sess_inact_timer_local_nonprim) {
		sess_inact_timer_for_ue_comm_free(sess_inact_timer_local_nonprim);
		sess_inact_timer_local_nonprim = NULL;
	}
	return NULL;
}

ue_communication_t *ue_communication_copy(ue_communication_t	*dst,
                                          ue_communication_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_communication_convertToJSON(src);
	if(!item) {
		printf("ue_communication_convertToJSON() failed");
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

	ue_communication_free(dst);
	dst = ue_communication_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
