#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "amf_event_subscription.h"

amf_event_subscription_t *amf_event_subscription_create(list_t *event_list,
                                                        char *event_notify_uri,
                                                        char *notify_correlation_id, char *nf_id, char *subs_change_notify_uri, char *subs_change_notify_correlation_id, char *supi, char *group_id, list_t *exclude_supi_list, list_t *exclude_gpsi_list, list_t *include_supi_list, list_t *include_gpsi_list, char *gpsi, char *pei, bool is_any_ue, int any_ue, amf_event_mode_t *options, nf_type_t *source_nf_type, bool is_term_notify_ind,
                                                        int term_notify_ind) {
	amf_event_subscription_t *amf_event_subscription_local_var = malloc(
		sizeof(amf_event_subscription_t));

	amf_event_subscription_local_var->event_list = event_list;
	amf_event_subscription_local_var->event_notify_uri = event_notify_uri;
	amf_event_subscription_local_var->notify_correlation_id =
		notify_correlation_id;
	amf_event_subscription_local_var->nf_id = nf_id;
	amf_event_subscription_local_var->subs_change_notify_uri =
		subs_change_notify_uri;
	amf_event_subscription_local_var->subs_change_notify_correlation_id =
		subs_change_notify_correlation_id;
	amf_event_subscription_local_var->supi = supi;
	amf_event_subscription_local_var->group_id = group_id;
	amf_event_subscription_local_var->exclude_supi_list = exclude_supi_list;
	amf_event_subscription_local_var->exclude_gpsi_list = exclude_gpsi_list;
	amf_event_subscription_local_var->include_supi_list = include_supi_list;
	amf_event_subscription_local_var->include_gpsi_list = include_gpsi_list;
	amf_event_subscription_local_var->gpsi = gpsi;
	amf_event_subscription_local_var->pei = pei;
	amf_event_subscription_local_var->is_any_ue = is_any_ue;
	amf_event_subscription_local_var->any_ue = any_ue;
	amf_event_subscription_local_var->options = options;
	amf_event_subscription_local_var->source_nf_type = source_nf_type;
	amf_event_subscription_local_var->is_term_notify_ind =
		is_term_notify_ind;
	amf_event_subscription_local_var->term_notify_ind = term_notify_ind;

	return amf_event_subscription_local_var;
}

void amf_event_subscription_free(
	amf_event_subscription_t *amf_event_subscription) {
	lnode_t *node = NULL;

	if(NULL == amf_event_subscription) {
		return;
	}
	if(amf_event_subscription->event_list) {
		list_for_each(amf_event_subscription->event_list, node) {
			amf_event_free(node->data);
		}
		list_free(amf_event_subscription->event_list);
		amf_event_subscription->event_list = NULL;
	}
	if(amf_event_subscription->event_notify_uri) {
		free(amf_event_subscription->event_notify_uri);
		amf_event_subscription->event_notify_uri = NULL;
	}
	if(amf_event_subscription->notify_correlation_id) {
		free(amf_event_subscription->notify_correlation_id);
		amf_event_subscription->notify_correlation_id = NULL;
	}
	if(amf_event_subscription->nf_id) {
		free(amf_event_subscription->nf_id);
		amf_event_subscription->nf_id = NULL;
	}
	if(amf_event_subscription->subs_change_notify_uri) {
		free(amf_event_subscription->subs_change_notify_uri);
		amf_event_subscription->subs_change_notify_uri = NULL;
	}
	if(amf_event_subscription->subs_change_notify_correlation_id) {
		free(amf_event_subscription->subs_change_notify_correlation_id);
		amf_event_subscription->subs_change_notify_correlation_id =
			NULL;
	}
	if(amf_event_subscription->supi) {
		free(amf_event_subscription->supi);
		amf_event_subscription->supi = NULL;
	}
	if(amf_event_subscription->group_id) {
		free(amf_event_subscription->group_id);
		amf_event_subscription->group_id = NULL;
	}
	if(amf_event_subscription->exclude_supi_list) {
		list_for_each(amf_event_subscription->exclude_supi_list, node) {
			free(node->data);
		}
		list_free(amf_event_subscription->exclude_supi_list);
		amf_event_subscription->exclude_supi_list = NULL;
	}
	if(amf_event_subscription->exclude_gpsi_list) {
		list_for_each(amf_event_subscription->exclude_gpsi_list, node) {
			free(node->data);
		}
		list_free(amf_event_subscription->exclude_gpsi_list);
		amf_event_subscription->exclude_gpsi_list = NULL;
	}
	if(amf_event_subscription->include_supi_list) {
		list_for_each(amf_event_subscription->include_supi_list, node) {
			free(node->data);
		}
		list_free(amf_event_subscription->include_supi_list);
		amf_event_subscription->include_supi_list = NULL;
	}
	if(amf_event_subscription->include_gpsi_list) {
		list_for_each(amf_event_subscription->include_gpsi_list, node) {
			free(node->data);
		}
		list_free(amf_event_subscription->include_gpsi_list);
		amf_event_subscription->include_gpsi_list = NULL;
	}
	if(amf_event_subscription->gpsi) {
		free(amf_event_subscription->gpsi);
		amf_event_subscription->gpsi = NULL;
	}
	if(amf_event_subscription->pei) {
		free(amf_event_subscription->pei);
		amf_event_subscription->pei = NULL;
	}
	if(amf_event_subscription->options) {
		amf_event_mode_free(amf_event_subscription->options);
		amf_event_subscription->options = NULL;
	}
	if(amf_event_subscription->source_nf_type) {
		nf_type_free(amf_event_subscription->source_nf_type);
		amf_event_subscription->source_nf_type = NULL;
	}
	free(amf_event_subscription);
}

cJSON *amf_event_subscription_convertToJSON(
	amf_event_subscription_t *amf_event_subscription) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(amf_event_subscription == NULL) {
		printf(
			"amf_event_subscription_convertToJSON() failed [AmfEventSubscription]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!amf_event_subscription->event_list) {
		printf(
			"amf_event_subscription_convertToJSON() failed [event_list]");
		return NULL;
	}
	cJSON *event_listList = cJSON_AddArrayToObject(item, "eventList");
	if(event_listList == NULL) {
		printf(
			"amf_event_subscription_convertToJSON() failed [event_list]");
		goto end;
	}
	list_for_each(amf_event_subscription->event_list, node) {
		cJSON *itemLocal = amf_event_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"amf_event_subscription_convertToJSON() failed [event_list]");
			goto end;
		}
		cJSON_AddItemToArray(event_listList, itemLocal);
	}

	if(!amf_event_subscription->event_notify_uri) {
		printf(
			"amf_event_subscription_convertToJSON() failed [event_notify_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "eventNotifyUri",
	                           amf_event_subscription->event_notify_uri) ==
	   NULL)
	{
		printf(
			"amf_event_subscription_convertToJSON() failed [event_notify_uri]");
		goto end;
	}

	if(!amf_event_subscription->notify_correlation_id) {
		printf(
			"amf_event_subscription_convertToJSON() failed [notify_correlation_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "notifyCorrelationId",
	                           amf_event_subscription->notify_correlation_id)
	   == NULL)
	{
		printf(
			"amf_event_subscription_convertToJSON() failed [notify_correlation_id]");
		goto end;
	}

	if(!amf_event_subscription->nf_id) {
		printf("amf_event_subscription_convertToJSON() failed [nf_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "nfId",
	                           amf_event_subscription->nf_id) == NULL)
	{
		printf("amf_event_subscription_convertToJSON() failed [nf_id]");
		goto end;
	}

	if(amf_event_subscription->subs_change_notify_uri) {
		if(cJSON_AddStringToObject(item, "subsChangeNotifyUri",
		                           amf_event_subscription->
		                           subs_change_notify_uri) == NULL)
		{
			printf(
				"amf_event_subscription_convertToJSON() failed [subs_change_notify_uri]");
			goto end;
		}
	}

	if(amf_event_subscription->subs_change_notify_correlation_id) {
		if(cJSON_AddStringToObject(item,
		                           "subsChangeNotifyCorrelationId",
		                           amf_event_subscription->
		                           subs_change_notify_correlation_id) ==
		   NULL)
		{
			printf(
				"amf_event_subscription_convertToJSON() failed [subs_change_notify_correlation_id]");
			goto end;
		}
	}

	if(amf_event_subscription->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           amf_event_subscription->supi) ==
		   NULL)
		{
			printf(
				"amf_event_subscription_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(amf_event_subscription->group_id) {
		if(cJSON_AddStringToObject(item, "groupId",
		                           amf_event_subscription->group_id) ==
		   NULL)
		{
			printf(
				"amf_event_subscription_convertToJSON() failed [group_id]");
			goto end;
		}
	}

	if(amf_event_subscription->exclude_supi_list) {
		cJSON *exclude_supi_listList = cJSON_AddArrayToObject(item,
		                                                      "excludeSupiList");
		if(exclude_supi_listList == NULL) {
			printf(
				"amf_event_subscription_convertToJSON() failed [exclude_supi_list]");
			goto end;
		}
		list_for_each(amf_event_subscription->exclude_supi_list, node) {
			if(cJSON_AddStringToObject(exclude_supi_listList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"amf_event_subscription_convertToJSON() failed [exclude_supi_list]");
				goto end;
			}
		}
	}

	if(amf_event_subscription->exclude_gpsi_list) {
		cJSON *exclude_gpsi_listList = cJSON_AddArrayToObject(item,
		                                                      "excludeGpsiList");
		if(exclude_gpsi_listList == NULL) {
			printf(
				"amf_event_subscription_convertToJSON() failed [exclude_gpsi_list]");
			goto end;
		}
		list_for_each(amf_event_subscription->exclude_gpsi_list, node) {
			if(cJSON_AddStringToObject(exclude_gpsi_listList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"amf_event_subscription_convertToJSON() failed [exclude_gpsi_list]");
				goto end;
			}
		}
	}

	if(amf_event_subscription->include_supi_list) {
		cJSON *include_supi_listList = cJSON_AddArrayToObject(item,
		                                                      "includeSupiList");
		if(include_supi_listList == NULL) {
			printf(
				"amf_event_subscription_convertToJSON() failed [include_supi_list]");
			goto end;
		}
		list_for_each(amf_event_subscription->include_supi_list, node) {
			if(cJSON_AddStringToObject(include_supi_listList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"amf_event_subscription_convertToJSON() failed [include_supi_list]");
				goto end;
			}
		}
	}

	if(amf_event_subscription->include_gpsi_list) {
		cJSON *include_gpsi_listList = cJSON_AddArrayToObject(item,
		                                                      "includeGpsiList");
		if(include_gpsi_listList == NULL) {
			printf(
				"amf_event_subscription_convertToJSON() failed [include_gpsi_list]");
			goto end;
		}
		list_for_each(amf_event_subscription->include_gpsi_list, node) {
			if(cJSON_AddStringToObject(include_gpsi_listList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"amf_event_subscription_convertToJSON() failed [include_gpsi_list]");
				goto end;
			}
		}
	}

	if(amf_event_subscription->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           amf_event_subscription->gpsi) ==
		   NULL)
		{
			printf(
				"amf_event_subscription_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(amf_event_subscription->pei) {
		if(cJSON_AddStringToObject(item, "pei",
		                           amf_event_subscription->pei) == NULL)
		{
			printf(
				"amf_event_subscription_convertToJSON() failed [pei]");
			goto end;
		}
	}

	if(amf_event_subscription->is_any_ue) {
		if(cJSON_AddBoolToObject(item, "anyUE",
		                         amf_event_subscription->any_ue) ==
		   NULL)
		{
			printf(
				"amf_event_subscription_convertToJSON() failed [any_ue]");
			goto end;
		}
	}

	if(amf_event_subscription->options) {
		cJSON *options_local_JSON = amf_event_mode_convertToJSON(
			amf_event_subscription->options);
		if(options_local_JSON == NULL) {
			printf(
				"amf_event_subscription_convertToJSON() failed [options]");
			goto end;
		}
		cJSON_AddItemToObject(item, "options", options_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_subscription_convertToJSON() failed [options]");
			goto end;
		}
	}

	if(amf_event_subscription->source_nf_type) {
		cJSON *source_nf_type_local_JSON = nf_type_convertToJSON(
			amf_event_subscription->source_nf_type);
		if(source_nf_type_local_JSON == NULL) {
			printf(
				"amf_event_subscription_convertToJSON() failed [source_nf_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "sourceNfType",
		                      source_nf_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_subscription_convertToJSON() failed [source_nf_type]");
			goto end;
		}
	}

	if(amf_event_subscription->is_term_notify_ind) {
		if(cJSON_AddBoolToObject(item, "termNotifyInd",
		                         amf_event_subscription->term_notify_ind)
		   == NULL)
		{
			printf(
				"amf_event_subscription_convertToJSON() failed [term_notify_ind]");
			goto end;
		}
	}

end:
	return item;
}

amf_event_subscription_t *amf_event_subscription_parseFromJSON(
	cJSON *amf_event_subscriptionJSON) {
	amf_event_subscription_t *amf_event_subscription_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *event_list = NULL;
	list_t *event_listList = NULL;
	cJSON *event_notify_uri = NULL;
	cJSON *notify_correlation_id = NULL;
	cJSON *nf_id = NULL;
	cJSON *subs_change_notify_uri = NULL;
	cJSON *subs_change_notify_correlation_id = NULL;
	cJSON *supi = NULL;
	cJSON *group_id = NULL;
	cJSON *exclude_supi_list = NULL;
	list_t *exclude_supi_listList = NULL;
	cJSON *exclude_gpsi_list = NULL;
	list_t *exclude_gpsi_listList = NULL;
	cJSON *include_supi_list = NULL;
	list_t *include_supi_listList = NULL;
	cJSON *include_gpsi_list = NULL;
	list_t *include_gpsi_listList = NULL;
	cJSON *gpsi = NULL;
	cJSON *pei = NULL;
	cJSON *any_ue = NULL;
	cJSON *options = NULL;
	amf_event_mode_t *options_local_nonprim = NULL;
	cJSON *source_nf_type = NULL;
	nf_type_t *source_nf_type_local_nonprim = NULL;
	cJSON *term_notify_ind = NULL;
	event_list = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscriptionJSON, "eventList");
	if(!event_list) {
		printf(
			"amf_event_subscription_parseFromJSON() failed [event_list]");
		goto end;
	}
	cJSON *event_list_local = NULL;
	if(!cJSON_IsArray(event_list)) {
		printf(
			"amf_event_subscription_parseFromJSON() failed [event_list]");
		goto end;
	}

	event_listList = list_create();

	cJSON_ArrayForEach(event_list_local, event_list) {
		if(!cJSON_IsObject(event_list_local)) {
			printf(
				"amf_event_subscription_parseFromJSON() failed [event_list]");
			goto end;
		}
		amf_event_t *event_listItem = amf_event_parseFromJSON(
			event_list_local);
		if(!event_listItem) {
			printf("No event_listItem");
			goto end;
		}
		list_add(event_listList, event_listItem);
	}

	event_notify_uri = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscriptionJSON, "eventNotifyUri");
	if(!event_notify_uri) {
		printf(
			"amf_event_subscription_parseFromJSON() failed [event_notify_uri]");
		goto end;
	}
	if(!cJSON_IsString(event_notify_uri)) {
		printf(
			"amf_event_subscription_parseFromJSON() failed [event_notify_uri]");
		goto end;
	}

	notify_correlation_id = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscriptionJSON, "notifyCorrelationId");
	if(!notify_correlation_id) {
		printf(
			"amf_event_subscription_parseFromJSON() failed [notify_correlation_id]");
		goto end;
	}
	if(!cJSON_IsString(notify_correlation_id)) {
		printf(
			"amf_event_subscription_parseFromJSON() failed [notify_correlation_id]");
		goto end;
	}

	nf_id = cJSON_GetObjectItemCaseSensitive(amf_event_subscriptionJSON,
	                                         "nfId");
	if(!nf_id) {
		printf("amf_event_subscription_parseFromJSON() failed [nf_id]");
		goto end;
	}
	if(!cJSON_IsString(nf_id)) {
		printf("amf_event_subscription_parseFromJSON() failed [nf_id]");
		goto end;
	}

	subs_change_notify_uri = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscriptionJSON, "subsChangeNotifyUri");
	if(subs_change_notify_uri) {
		if(!cJSON_IsString(subs_change_notify_uri) &&
		   !cJSON_IsNull(subs_change_notify_uri))
		{
			printf(
				"amf_event_subscription_parseFromJSON() failed [subs_change_notify_uri]");
			goto end;
		}
	}

	subs_change_notify_correlation_id = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscriptionJSON, "subsChangeNotifyCorrelationId");
	if(subs_change_notify_correlation_id) {
		if(!cJSON_IsString(subs_change_notify_correlation_id) &&
		   !cJSON_IsNull(subs_change_notify_correlation_id))
		{
			printf(
				"amf_event_subscription_parseFromJSON() failed [subs_change_notify_correlation_id]");
			goto end;
		}
	}

	supi = cJSON_GetObjectItemCaseSensitive(amf_event_subscriptionJSON,
	                                        "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf(
				"amf_event_subscription_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	group_id = cJSON_GetObjectItemCaseSensitive(amf_event_subscriptionJSON,
	                                            "groupId");
	if(group_id) {
		if(!cJSON_IsString(group_id) &&
		   !cJSON_IsNull(group_id))
		{
			printf(
				"amf_event_subscription_parseFromJSON() failed [group_id]");
			goto end;
		}
	}

	exclude_supi_list = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscriptionJSON, "excludeSupiList");
	if(exclude_supi_list) {
		cJSON *exclude_supi_list_local = NULL;
		if(!cJSON_IsArray(exclude_supi_list)) {
			printf(
				"amf_event_subscription_parseFromJSON() failed [exclude_supi_list]");
			goto end;
		}

		exclude_supi_listList = list_create();

		cJSON_ArrayForEach(exclude_supi_list_local, exclude_supi_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(exclude_supi_list_local)) {
				printf(
					"amf_event_subscription_parseFromJSON() failed [exclude_supi_list]");
				goto end;
			}
			list_add(exclude_supi_listList,
			         strdup(exclude_supi_list_local->valuestring));
		}
	}

	exclude_gpsi_list = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscriptionJSON, "excludeGpsiList");
	if(exclude_gpsi_list) {
		cJSON *exclude_gpsi_list_local = NULL;
		if(!cJSON_IsArray(exclude_gpsi_list)) {
			printf(
				"amf_event_subscription_parseFromJSON() failed [exclude_gpsi_list]");
			goto end;
		}

		exclude_gpsi_listList = list_create();

		cJSON_ArrayForEach(exclude_gpsi_list_local, exclude_gpsi_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(exclude_gpsi_list_local)) {
				printf(
					"amf_event_subscription_parseFromJSON() failed [exclude_gpsi_list]");
				goto end;
			}
			list_add(exclude_gpsi_listList,
			         strdup(exclude_gpsi_list_local->valuestring));
		}
	}

	include_supi_list = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscriptionJSON, "includeSupiList");
	if(include_supi_list) {
		cJSON *include_supi_list_local = NULL;
		if(!cJSON_IsArray(include_supi_list)) {
			printf(
				"amf_event_subscription_parseFromJSON() failed [include_supi_list]");
			goto end;
		}

		include_supi_listList = list_create();

		cJSON_ArrayForEach(include_supi_list_local, include_supi_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(include_supi_list_local)) {
				printf(
					"amf_event_subscription_parseFromJSON() failed [include_supi_list]");
				goto end;
			}
			list_add(include_supi_listList,
			         strdup(include_supi_list_local->valuestring));
		}
	}

	include_gpsi_list = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscriptionJSON, "includeGpsiList");
	if(include_gpsi_list) {
		cJSON *include_gpsi_list_local = NULL;
		if(!cJSON_IsArray(include_gpsi_list)) {
			printf(
				"amf_event_subscription_parseFromJSON() failed [include_gpsi_list]");
			goto end;
		}

		include_gpsi_listList = list_create();

		cJSON_ArrayForEach(include_gpsi_list_local, include_gpsi_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(include_gpsi_list_local)) {
				printf(
					"amf_event_subscription_parseFromJSON() failed [include_gpsi_list]");
				goto end;
			}
			list_add(include_gpsi_listList,
			         strdup(include_gpsi_list_local->valuestring));
		}
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(amf_event_subscriptionJSON,
	                                        "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf(
				"amf_event_subscription_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	pei =
		cJSON_GetObjectItemCaseSensitive(amf_event_subscriptionJSON,
		                                 "pei");
	if(pei) {
		if(!cJSON_IsString(pei) &&
		   !cJSON_IsNull(pei))
		{
			printf(
				"amf_event_subscription_parseFromJSON() failed [pei]");
			goto end;
		}
	}

	any_ue = cJSON_GetObjectItemCaseSensitive(amf_event_subscriptionJSON,
	                                          "anyUE");
	if(any_ue) {
		if(!cJSON_IsBool(any_ue)) {
			printf(
				"amf_event_subscription_parseFromJSON() failed [any_ue]");
			goto end;
		}
	}

	options = cJSON_GetObjectItemCaseSensitive(amf_event_subscriptionJSON,
	                                           "options");
	if(options) {
		options_local_nonprim = amf_event_mode_parseFromJSON(options);
		if(!options_local_nonprim) {
			printf("amf_event_mode_parseFromJSON failed [options]");
			goto end;
		}
	}

	source_nf_type = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscriptionJSON, "sourceNfType");
	if(source_nf_type) {
		source_nf_type_local_nonprim = nf_type_parseFromJSON(
			source_nf_type);
		if(!source_nf_type_local_nonprim) {
			printf("nf_type_parseFromJSON failed [source_nf_type]");
			goto end;
		}
	}

	term_notify_ind = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscriptionJSON, "termNotifyInd");
	if(term_notify_ind) {
		if(!cJSON_IsBool(term_notify_ind)) {
			printf(
				"amf_event_subscription_parseFromJSON() failed [term_notify_ind]");
			goto end;
		}
	}

	amf_event_subscription_local_var = amf_event_subscription_create(
		event_listList,
		strdup(event_notify_uri->valuestring),
		strdup(notify_correlation_id->valuestring),
		strdup(nf_id->valuestring),
		subs_change_notify_uri &&
		!cJSON_IsNull(subs_change_notify_uri) ? strdup(
			subs_change_notify_uri->valuestring) : NULL,
		subs_change_notify_correlation_id &&
		!cJSON_IsNull(subs_change_notify_correlation_id) ? strdup(
			subs_change_notify_correlation_id->valuestring) : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		group_id &&
		!cJSON_IsNull(group_id) ? strdup(group_id->valuestring) : NULL,
		exclude_supi_list ? exclude_supi_listList : NULL,
		exclude_gpsi_list ? exclude_gpsi_listList : NULL,
		include_supi_list ? include_supi_listList : NULL,
		include_gpsi_list ? include_gpsi_listList : NULL,
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		pei &&
		!cJSON_IsNull(pei) ? strdup(pei->valuestring) : NULL,
		any_ue ? true : false,
		any_ue ? any_ue->valueint : 0,
		options ? options_local_nonprim : NULL,
		source_nf_type ? source_nf_type_local_nonprim : NULL,
		term_notify_ind ? true : false,
		term_notify_ind ? term_notify_ind->valueint : 0
		);

	return amf_event_subscription_local_var;
end:
	if(event_listList) {
		list_for_each(event_listList, node) {
			amf_event_free(node->data);
		}
		list_free(event_listList);
		event_listList = NULL;
	}
	if(exclude_supi_listList) {
		list_for_each(exclude_supi_listList, node) {
			free(node->data);
		}
		list_free(exclude_supi_listList);
		exclude_supi_listList = NULL;
	}
	if(exclude_gpsi_listList) {
		list_for_each(exclude_gpsi_listList, node) {
			free(node->data);
		}
		list_free(exclude_gpsi_listList);
		exclude_gpsi_listList = NULL;
	}
	if(include_supi_listList) {
		list_for_each(include_supi_listList, node) {
			free(node->data);
		}
		list_free(include_supi_listList);
		include_supi_listList = NULL;
	}
	if(include_gpsi_listList) {
		list_for_each(include_gpsi_listList, node) {
			free(node->data);
		}
		list_free(include_gpsi_listList);
		include_gpsi_listList = NULL;
	}
	if(options_local_nonprim) {
		amf_event_mode_free(options_local_nonprim);
		options_local_nonprim = NULL;
	}
	if(source_nf_type_local_nonprim) {
		nf_type_free(source_nf_type_local_nonprim);
		source_nf_type_local_nonprim = NULL;
	}
	return NULL;
}

amf_event_subscription_t *amf_event_subscription_copy(
	amf_event_subscription_t *dst, amf_event_subscription_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = amf_event_subscription_convertToJSON(src);
	if(!item) {
		printf("amf_event_subscription_convertToJSON() failed");
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

	amf_event_subscription_free(dst);
	dst = amf_event_subscription_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
