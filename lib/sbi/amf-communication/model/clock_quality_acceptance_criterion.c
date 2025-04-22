#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "clock_quality_acceptance_criterion.h"

clock_quality_acceptance_criterion_t *clock_quality_acceptance_criterion_create(
	list_t *synchronization_state, clock_quality_t *clock_quality,
	list_t *parent_time_source) {
	clock_quality_acceptance_criterion_t *
	        clock_quality_acceptance_criterion_local_var =
		malloc(sizeof(clock_quality_acceptance_criterion_t));

	clock_quality_acceptance_criterion_local_var->synchronization_state =
		synchronization_state;
	clock_quality_acceptance_criterion_local_var->clock_quality =
		clock_quality;
	clock_quality_acceptance_criterion_local_var->parent_time_source =
		parent_time_source;

	return clock_quality_acceptance_criterion_local_var;
}

void clock_quality_acceptance_criterion_free(
	clock_quality_acceptance_criterion_t *clock_quality_acceptance_criterion)
{
	lnode_t *node = NULL;

	if(NULL == clock_quality_acceptance_criterion) {
		return;
	}
	if(clock_quality_acceptance_criterion->synchronization_state) {
		list_for_each(
			clock_quality_acceptance_criterion->synchronization_state,
			node) {
			synchronization_state_free(node->data);
		}
		list_free(
			clock_quality_acceptance_criterion->synchronization_state);
		clock_quality_acceptance_criterion->synchronization_state =
			NULL;
	}
	if(clock_quality_acceptance_criterion->clock_quality) {
		clock_quality_free(
			clock_quality_acceptance_criterion->clock_quality);
		clock_quality_acceptance_criterion->clock_quality = NULL;
	}
	if(clock_quality_acceptance_criterion->parent_time_source) {
		list_for_each(
			clock_quality_acceptance_criterion->parent_time_source,
			node) {
			time_source_free(node->data);
		}
		list_free(clock_quality_acceptance_criterion->parent_time_source);
		clock_quality_acceptance_criterion->parent_time_source = NULL;
	}
	free(clock_quality_acceptance_criterion);
}

cJSON *clock_quality_acceptance_criterion_convertToJSON(
	clock_quality_acceptance_criterion_t *clock_quality_acceptance_criterion)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(clock_quality_acceptance_criterion == NULL) {
		printf(
			"clock_quality_acceptance_criterion_convertToJSON() failed [ClockQualityAcceptanceCriterion]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(clock_quality_acceptance_criterion->synchronization_state) {
		cJSON *synchronization_stateList = cJSON_AddArrayToObject(item,
		                                                          "synchronizationState");
		if(synchronization_stateList == NULL) {
			printf(
				"clock_quality_acceptance_criterion_convertToJSON() failed [synchronization_state]");
			goto end;
		}
		list_for_each(
			clock_quality_acceptance_criterion->synchronization_state,
			node) {
			cJSON *itemLocal = synchronization_state_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"clock_quality_acceptance_criterion_convertToJSON() failed [synchronization_state]");
				goto end;
			}
			cJSON_AddItemToArray(synchronization_stateList,
			                     itemLocal);
		}
	}

	if(clock_quality_acceptance_criterion->clock_quality) {
		cJSON *clock_quality_local_JSON = clock_quality_convertToJSON(
			clock_quality_acceptance_criterion->clock_quality);
		if(clock_quality_local_JSON == NULL) {
			printf(
				"clock_quality_acceptance_criterion_convertToJSON() failed [clock_quality]");
			goto end;
		}
		cJSON_AddItemToObject(item, "clockQuality",
		                      clock_quality_local_JSON);
		if(item->child == NULL) {
			printf(
				"clock_quality_acceptance_criterion_convertToJSON() failed [clock_quality]");
			goto end;
		}
	}

	if(clock_quality_acceptance_criterion->parent_time_source) {
		cJSON *parent_time_sourceList = cJSON_AddArrayToObject(item,
		                                                       "parentTimeSource");
		if(parent_time_sourceList == NULL) {
			printf(
				"clock_quality_acceptance_criterion_convertToJSON() failed [parent_time_source]");
			goto end;
		}
		list_for_each(
			clock_quality_acceptance_criterion->parent_time_source,
			node) {
			cJSON *itemLocal =
				time_source_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"clock_quality_acceptance_criterion_convertToJSON() failed [parent_time_source]");
				goto end;
			}
			cJSON_AddItemToArray(parent_time_sourceList, itemLocal);
		}
	}

end:
	return item;
}

clock_quality_acceptance_criterion_t *
clock_quality_acceptance_criterion_parseFromJSON(
	cJSON *clock_quality_acceptance_criterionJSON) {
	clock_quality_acceptance_criterion_t *
	        clock_quality_acceptance_criterion_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *synchronization_state = NULL;
	list_t *synchronization_stateList = NULL;
	cJSON *clock_quality = NULL;
	clock_quality_t *clock_quality_local_nonprim = NULL;
	cJSON *parent_time_source = NULL;
	list_t *parent_time_sourceList = NULL;
	synchronization_state = cJSON_GetObjectItemCaseSensitive(
		clock_quality_acceptance_criterionJSON, "synchronizationState");
	if(synchronization_state) {
		cJSON *synchronization_state_local = NULL;
		if(!cJSON_IsArray(synchronization_state)) {
			printf(
				"clock_quality_acceptance_criterion_parseFromJSON() failed [synchronization_state]");
			goto end;
		}

		synchronization_stateList = list_create();

		cJSON_ArrayForEach(synchronization_state_local,
		                   synchronization_state) {
			if(!cJSON_IsObject(synchronization_state_local)) {
				printf(
					"clock_quality_acceptance_criterion_parseFromJSON() failed [synchronization_state]");
				goto end;
			}
			synchronization_state_t *synchronization_stateItem =
				synchronization_state_parseFromJSON(
					synchronization_state_local);
			if(!synchronization_stateItem) {
				printf("No synchronization_stateItem");
				goto end;
			}
			list_add(synchronization_stateList,
			         synchronization_stateItem);
		}
	}

	clock_quality = cJSON_GetObjectItemCaseSensitive(
		clock_quality_acceptance_criterionJSON, "clockQuality");
	if(clock_quality) {
		clock_quality_local_nonprim = clock_quality_parseFromJSON(
			clock_quality);
		if(!clock_quality_local_nonprim) {
			printf(
				"clock_quality_parseFromJSON failed [clock_quality]");
			goto end;
		}
	}

	parent_time_source = cJSON_GetObjectItemCaseSensitive(
		clock_quality_acceptance_criterionJSON, "parentTimeSource");
	if(parent_time_source) {
		cJSON *parent_time_source_local = NULL;
		if(!cJSON_IsArray(parent_time_source)) {
			printf(
				"clock_quality_acceptance_criterion_parseFromJSON() failed [parent_time_source]");
			goto end;
		}

		parent_time_sourceList = list_create();

		cJSON_ArrayForEach(parent_time_source_local,
		                   parent_time_source) {
			if(!cJSON_IsObject(parent_time_source_local)) {
				printf(
					"clock_quality_acceptance_criterion_parseFromJSON() failed [parent_time_source]");
				goto end;
			}
			time_source_t *parent_time_sourceItem =
				time_source_parseFromJSON(
					parent_time_source_local);
			if(!parent_time_sourceItem) {
				printf("No parent_time_sourceItem");
				goto end;
			}
			list_add(parent_time_sourceList,
			         parent_time_sourceItem);
		}
	}

	clock_quality_acceptance_criterion_local_var =
		clock_quality_acceptance_criterion_create(
			synchronization_state ? synchronization_stateList : NULL,
			clock_quality ? clock_quality_local_nonprim : NULL,
			parent_time_source ? parent_time_sourceList : NULL
			);

	return clock_quality_acceptance_criterion_local_var;
end:
	if(synchronization_stateList) {
		list_for_each(synchronization_stateList, node) {
			synchronization_state_free(node->data);
		}
		list_free(synchronization_stateList);
		synchronization_stateList = NULL;
	}
	if(clock_quality_local_nonprim) {
		clock_quality_free(clock_quality_local_nonprim);
		clock_quality_local_nonprim = NULL;
	}
	if(parent_time_sourceList) {
		list_for_each(parent_time_sourceList, node) {
			time_source_free(node->data);
		}
		list_free(parent_time_sourceList);
		parent_time_sourceList = NULL;
	}
	return NULL;
}

clock_quality_acceptance_criterion_t *clock_quality_acceptance_criterion_copy(
	clock_quality_acceptance_criterion_t	*dst,
	clock_quality_acceptance_criterion_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = clock_quality_acceptance_criterion_convertToJSON(src);
	if(!item) {
		printf(
			"clock_quality_acceptance_criterion_convertToJSON() failed");
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

	clock_quality_acceptance_criterion_free(dst);
	dst = clock_quality_acceptance_criterion_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
