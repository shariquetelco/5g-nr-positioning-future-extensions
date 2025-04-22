#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "area_of_interest_event_state.h"

area_of_interest_event_state_t *area_of_interest_event_state_create(
	presence_state_t *presence, list_t *individual_pra_id_list) {
	area_of_interest_event_state_t *area_of_interest_event_state_local_var =
		malloc(sizeof(area_of_interest_event_state_t));

	area_of_interest_event_state_local_var->presence = presence;
	area_of_interest_event_state_local_var->individual_pra_id_list =
		individual_pra_id_list;

	return area_of_interest_event_state_local_var;
}

void area_of_interest_event_state_free(
	area_of_interest_event_state_t *area_of_interest_event_state) {
	lnode_t *node = NULL;

	if(NULL == area_of_interest_event_state) {
		return;
	}
	if(area_of_interest_event_state->presence) {
		presence_state_free(area_of_interest_event_state->presence);
		area_of_interest_event_state->presence = NULL;
	}
	if(area_of_interest_event_state->individual_pra_id_list) {
		list_for_each(
			area_of_interest_event_state->individual_pra_id_list,
			node) {
			free(node->data);
		}
		list_free(area_of_interest_event_state->individual_pra_id_list);
		area_of_interest_event_state->individual_pra_id_list = NULL;
	}
	free(area_of_interest_event_state);
}

cJSON *area_of_interest_event_state_convertToJSON(
	area_of_interest_event_state_t *area_of_interest_event_state) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(area_of_interest_event_state == NULL) {
		printf(
			"area_of_interest_event_state_convertToJSON() failed [AreaOfInterestEventState]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!area_of_interest_event_state->presence) {
		printf(
			"area_of_interest_event_state_convertToJSON() failed [presence]");
		return NULL;
	}
	cJSON *presence_local_JSON = presence_state_convertToJSON(
		area_of_interest_event_state->presence);
	if(presence_local_JSON == NULL) {
		printf(
			"area_of_interest_event_state_convertToJSON() failed [presence]");
		goto end;
	}
	cJSON_AddItemToObject(item, "presence", presence_local_JSON);
	if(item->child == NULL) {
		printf(
			"area_of_interest_event_state_convertToJSON() failed [presence]");
		goto end;
	}

	if(area_of_interest_event_state->individual_pra_id_list) {
		cJSON *individual_pra_id_listList = cJSON_AddArrayToObject(item,
		                                                           "individualPraIdList");
		if(individual_pra_id_listList == NULL) {
			printf(
				"area_of_interest_event_state_convertToJSON() failed [individual_pra_id_list]");
			goto end;
		}
		list_for_each(
			area_of_interest_event_state->individual_pra_id_list,
			node) {
			if(cJSON_AddStringToObject(individual_pra_id_listList,
			                           "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"area_of_interest_event_state_convertToJSON() failed [individual_pra_id_list]");
				goto end;
			}
		}
	}

end:
	return item;
}

area_of_interest_event_state_t *area_of_interest_event_state_parseFromJSON(
	cJSON *area_of_interest_event_stateJSON) {
	area_of_interest_event_state_t *area_of_interest_event_state_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *presence = NULL;
	presence_state_t *presence_local_nonprim = NULL;
	cJSON *individual_pra_id_list = NULL;
	list_t *individual_pra_id_listList = NULL;
	presence = cJSON_GetObjectItemCaseSensitive(
		area_of_interest_event_stateJSON, "presence");
	if(!presence) {
		printf(
			"area_of_interest_event_state_parseFromJSON() failed [presence]");
		goto end;
	}
	presence_local_nonprim = presence_state_parseFromJSON(presence);
	if(!presence_local_nonprim) {
		printf("presence_state_parseFromJSON failed [presence]");
		goto end;
	}

	individual_pra_id_list = cJSON_GetObjectItemCaseSensitive(
		area_of_interest_event_stateJSON, "individualPraIdList");
	if(individual_pra_id_list) {
		cJSON *individual_pra_id_list_local = NULL;
		if(!cJSON_IsArray(individual_pra_id_list)) {
			printf(
				"area_of_interest_event_state_parseFromJSON() failed [individual_pra_id_list]");
			goto end;
		}

		individual_pra_id_listList = list_create();

		cJSON_ArrayForEach(individual_pra_id_list_local,
		                   individual_pra_id_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(individual_pra_id_list_local)) {
				printf(
					"area_of_interest_event_state_parseFromJSON() failed [individual_pra_id_list]");
				goto end;
			}
			list_add(individual_pra_id_listList,
			         strdup(individual_pra_id_list_local->
			                valuestring));
		}
	}

	area_of_interest_event_state_local_var =
		area_of_interest_event_state_create(
			presence_local_nonprim,
			individual_pra_id_list ? individual_pra_id_listList : NULL
			);

	return area_of_interest_event_state_local_var;
end:
	if(presence_local_nonprim) {
		presence_state_free(presence_local_nonprim);
		presence_local_nonprim = NULL;
	}
	if(individual_pra_id_listList) {
		list_for_each(individual_pra_id_listList, node) {
			free(node->data);
		}
		list_free(individual_pra_id_listList);
		individual_pra_id_listList = NULL;
	}
	return NULL;
}

area_of_interest_event_state_t *area_of_interest_event_state_copy(
	area_of_interest_event_state_t	*dst,
	area_of_interest_event_state_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = area_of_interest_event_state_convertToJSON(src);
	if(!item) {
		printf("area_of_interest_event_state_convertToJSON() failed");
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

	area_of_interest_event_state_free(dst);
	dst = area_of_interest_event_state_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
