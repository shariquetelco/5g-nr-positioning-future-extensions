#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "prev_sub_info.h"

prev_sub_info_t *prev_sub_info_create(char *producer_id, char *producer_set_id,
                                      char *subscription_id,
                                      list_t *nf_ana_events,
                                      list_t *ue_ana_events) {
	prev_sub_info_t *prev_sub_info_local_var = malloc(
		sizeof(prev_sub_info_t));

	prev_sub_info_local_var->producer_id = producer_id;
	prev_sub_info_local_var->producer_set_id = producer_set_id;
	prev_sub_info_local_var->subscription_id = subscription_id;
	prev_sub_info_local_var->nf_ana_events = nf_ana_events;
	prev_sub_info_local_var->ue_ana_events = ue_ana_events;

	return prev_sub_info_local_var;
}

void prev_sub_info_free(prev_sub_info_t *prev_sub_info) {
	lnode_t *node = NULL;

	if(NULL == prev_sub_info) {
		return;
	}
	if(prev_sub_info->producer_id) {
		free(prev_sub_info->producer_id);
		prev_sub_info->producer_id = NULL;
	}
	if(prev_sub_info->producer_set_id) {
		free(prev_sub_info->producer_set_id);
		prev_sub_info->producer_set_id = NULL;
	}
	if(prev_sub_info->subscription_id) {
		free(prev_sub_info->subscription_id);
		prev_sub_info->subscription_id = NULL;
	}
	if(prev_sub_info->nf_ana_events) {
		list_for_each(prev_sub_info->nf_ana_events, node) {
			nwdaf_event_free(node->data);
		}
		list_free(prev_sub_info->nf_ana_events);
		prev_sub_info->nf_ana_events = NULL;
	}
	if(prev_sub_info->ue_ana_events) {
		list_for_each(prev_sub_info->ue_ana_events, node) {
			ue_analytics_context_descriptor_free(node->data);
		}
		list_free(prev_sub_info->ue_ana_events);
		prev_sub_info->ue_ana_events = NULL;
	}
	free(prev_sub_info);
}

cJSON *prev_sub_info_convertToJSON(prev_sub_info_t *prev_sub_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(prev_sub_info == NULL) {
		printf("prev_sub_info_convertToJSON() failed [PrevSubInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(prev_sub_info->producer_id) {
		if(cJSON_AddStringToObject(item, "producerId",
		                           prev_sub_info->producer_id) == NULL)
		{
			printf(
				"prev_sub_info_convertToJSON() failed [producer_id]");
			goto end;
		}
	}

	if(prev_sub_info->producer_set_id) {
		if(cJSON_AddStringToObject(item, "producerSetId",
		                           prev_sub_info->producer_set_id) ==
		   NULL)
		{
			printf(
				"prev_sub_info_convertToJSON() failed [producer_set_id]");
			goto end;
		}
	}

	if(!prev_sub_info->subscription_id) {
		printf("prev_sub_info_convertToJSON() failed [subscription_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "subscriptionId",
	                           prev_sub_info->subscription_id) == NULL)
	{
		printf("prev_sub_info_convertToJSON() failed [subscription_id]");
		goto end;
	}

	if(prev_sub_info->nf_ana_events) {
		cJSON *nf_ana_eventsList = cJSON_AddArrayToObject(item,
		                                                  "nfAnaEvents");
		if(nf_ana_eventsList == NULL) {
			printf(
				"prev_sub_info_convertToJSON() failed [nf_ana_events]");
			goto end;
		}
		list_for_each(prev_sub_info->nf_ana_events, node) {
			cJSON *itemLocal =
				nwdaf_event_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"prev_sub_info_convertToJSON() failed [nf_ana_events]");
				goto end;
			}
			cJSON_AddItemToArray(nf_ana_eventsList, itemLocal);
		}
	}

	if(prev_sub_info->ue_ana_events) {
		cJSON *ue_ana_eventsList = cJSON_AddArrayToObject(item,
		                                                  "ueAnaEvents");
		if(ue_ana_eventsList == NULL) {
			printf(
				"prev_sub_info_convertToJSON() failed [ue_ana_events]");
			goto end;
		}
		list_for_each(prev_sub_info->ue_ana_events, node) {
			cJSON *itemLocal =
				ue_analytics_context_descriptor_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"prev_sub_info_convertToJSON() failed [ue_ana_events]");
				goto end;
			}
			cJSON_AddItemToArray(ue_ana_eventsList, itemLocal);
		}
	}

end:
	return item;
}

prev_sub_info_t *prev_sub_info_parseFromJSON(cJSON *prev_sub_infoJSON) {
	prev_sub_info_t *prev_sub_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *producer_id = NULL;
	cJSON *producer_set_id = NULL;
	cJSON *subscription_id = NULL;
	cJSON *nf_ana_events = NULL;
	list_t *nf_ana_eventsList = NULL;
	cJSON *ue_ana_events = NULL;
	list_t *ue_ana_eventsList = NULL;
	producer_id = cJSON_GetObjectItemCaseSensitive(prev_sub_infoJSON,
	                                               "producerId");
	if(producer_id) {
		if(!cJSON_IsString(producer_id) &&
		   !cJSON_IsNull(producer_id))
		{
			printf(
				"prev_sub_info_parseFromJSON() failed [producer_id]");
			goto end;
		}
	}

	producer_set_id = cJSON_GetObjectItemCaseSensitive(prev_sub_infoJSON,
	                                                   "producerSetId");
	if(producer_set_id) {
		if(!cJSON_IsString(producer_set_id) &&
		   !cJSON_IsNull(producer_set_id))
		{
			printf(
				"prev_sub_info_parseFromJSON() failed [producer_set_id]");
			goto end;
		}
	}

	subscription_id = cJSON_GetObjectItemCaseSensitive(prev_sub_infoJSON,
	                                                   "subscriptionId");
	if(!subscription_id) {
		printf("prev_sub_info_parseFromJSON() failed [subscription_id]");
		goto end;
	}
	if(!cJSON_IsString(subscription_id)) {
		printf("prev_sub_info_parseFromJSON() failed [subscription_id]");
		goto end;
	}

	nf_ana_events = cJSON_GetObjectItemCaseSensitive(prev_sub_infoJSON,
	                                                 "nfAnaEvents");
	if(nf_ana_events) {
		cJSON *nf_ana_events_local = NULL;
		if(!cJSON_IsArray(nf_ana_events)) {
			printf(
				"prev_sub_info_parseFromJSON() failed [nf_ana_events]");
			goto end;
		}

		nf_ana_eventsList = list_create();

		cJSON_ArrayForEach(nf_ana_events_local, nf_ana_events) {
			if(!cJSON_IsObject(nf_ana_events_local)) {
				printf(
					"prev_sub_info_parseFromJSON() failed [nf_ana_events]");
				goto end;
			}
			nwdaf_event_t *nf_ana_eventsItem =
				nwdaf_event_parseFromJSON(nf_ana_events_local);
			if(!nf_ana_eventsItem) {
				printf("No nf_ana_eventsItem");
				goto end;
			}
			list_add(nf_ana_eventsList, nf_ana_eventsItem);
		}
	}

	ue_ana_events = cJSON_GetObjectItemCaseSensitive(prev_sub_infoJSON,
	                                                 "ueAnaEvents");
	if(ue_ana_events) {
		cJSON *ue_ana_events_local = NULL;
		if(!cJSON_IsArray(ue_ana_events)) {
			printf(
				"prev_sub_info_parseFromJSON() failed [ue_ana_events]");
			goto end;
		}

		ue_ana_eventsList = list_create();

		cJSON_ArrayForEach(ue_ana_events_local, ue_ana_events) {
			if(!cJSON_IsObject(ue_ana_events_local)) {
				printf(
					"prev_sub_info_parseFromJSON() failed [ue_ana_events]");
				goto end;
			}
			ue_analytics_context_descriptor_t *ue_ana_eventsItem =
				ue_analytics_context_descriptor_parseFromJSON(
					ue_ana_events_local);
			if(!ue_ana_eventsItem) {
				printf("No ue_ana_eventsItem");
				goto end;
			}
			list_add(ue_ana_eventsList, ue_ana_eventsItem);
		}
	}

	prev_sub_info_local_var = prev_sub_info_create(
		producer_id &&
		!cJSON_IsNull(producer_id) ? strdup(
			producer_id->valuestring) : NULL,
		producer_set_id &&
		!cJSON_IsNull(producer_set_id) ? strdup(producer_set_id->
		                                        valuestring) : NULL,
		strdup(subscription_id->valuestring),
		nf_ana_events ? nf_ana_eventsList : NULL,
		ue_ana_events ? ue_ana_eventsList : NULL
		);

	return prev_sub_info_local_var;
end:
	if(nf_ana_eventsList) {
		list_for_each(nf_ana_eventsList, node) {
			nwdaf_event_free(node->data);
		}
		list_free(nf_ana_eventsList);
		nf_ana_eventsList = NULL;
	}
	if(ue_ana_eventsList) {
		list_for_each(ue_ana_eventsList, node) {
			ue_analytics_context_descriptor_free(node->data);
		}
		list_free(ue_ana_eventsList);
		ue_ana_eventsList = NULL;
	}
	return NULL;
}

prev_sub_info_t *prev_sub_info_copy(prev_sub_info_t	*dst,
                                    prev_sub_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = prev_sub_info_convertToJSON(src);
	if(!item) {
		printf("prev_sub_info_convertToJSON() failed");
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

	prev_sub_info_free(dst);
	dst = prev_sub_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
