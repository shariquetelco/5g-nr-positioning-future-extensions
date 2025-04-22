#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rel_prox_info.h"

rel_prox_info_t *rel_prox_info_create(char *ts_start, int ts_duration,
                                      list_t *supis, list_t *gpsis,
                                      list_t *ue_proximities,
                                      time_to_collision_info_t *ttc_info) {
	rel_prox_info_t *rel_prox_info_local_var = malloc(
		sizeof(rel_prox_info_t));

	rel_prox_info_local_var->ts_start = ts_start;
	rel_prox_info_local_var->ts_duration = ts_duration;
	rel_prox_info_local_var->supis = supis;
	rel_prox_info_local_var->gpsis = gpsis;
	rel_prox_info_local_var->ue_proximities = ue_proximities;
	rel_prox_info_local_var->ttc_info = ttc_info;

	return rel_prox_info_local_var;
}

void rel_prox_info_free(rel_prox_info_t *rel_prox_info) {
	lnode_t *node = NULL;

	if(NULL == rel_prox_info) {
		return;
	}
	if(rel_prox_info->ts_start) {
		free(rel_prox_info->ts_start);
		rel_prox_info->ts_start = NULL;
	}
	if(rel_prox_info->supis) {
		list_for_each(rel_prox_info->supis, node) {
			free(node->data);
		}
		list_free(rel_prox_info->supis);
		rel_prox_info->supis = NULL;
	}
	if(rel_prox_info->gpsis) {
		list_for_each(rel_prox_info->gpsis, node) {
			free(node->data);
		}
		list_free(rel_prox_info->gpsis);
		rel_prox_info->gpsis = NULL;
	}
	if(rel_prox_info->ue_proximities) {
		list_for_each(rel_prox_info->ue_proximities, node) {
			ue_proximity_free(node->data);
		}
		list_free(rel_prox_info->ue_proximities);
		rel_prox_info->ue_proximities = NULL;
	}
	if(rel_prox_info->ttc_info) {
		time_to_collision_info_free(rel_prox_info->ttc_info);
		rel_prox_info->ttc_info = NULL;
	}
	free(rel_prox_info);
}

cJSON *rel_prox_info_convertToJSON(rel_prox_info_t *rel_prox_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(rel_prox_info == NULL) {
		printf("rel_prox_info_convertToJSON() failed [RelProxInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!rel_prox_info->ts_start) {
		printf("rel_prox_info_convertToJSON() failed [ts_start]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "tsStart",
	                           rel_prox_info->ts_start) == NULL)
	{
		printf("rel_prox_info_convertToJSON() failed [ts_start]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "tsDuration",
	                           rel_prox_info->ts_duration) == NULL)
	{
		printf("rel_prox_info_convertToJSON() failed [ts_duration]");
		goto end;
	}

	if(rel_prox_info->supis) {
		cJSON *supisList = cJSON_AddArrayToObject(item, "supis");
		if(supisList == NULL) {
			printf("rel_prox_info_convertToJSON() failed [supis]");
			goto end;
		}
		list_for_each(rel_prox_info->supis, node) {
			if(cJSON_AddStringToObject(supisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"rel_prox_info_convertToJSON() failed [supis]");
				goto end;
			}
		}
	}

	if(rel_prox_info->gpsis) {
		cJSON *gpsisList = cJSON_AddArrayToObject(item, "gpsis");
		if(gpsisList == NULL) {
			printf("rel_prox_info_convertToJSON() failed [gpsis]");
			goto end;
		}
		list_for_each(rel_prox_info->gpsis, node) {
			if(cJSON_AddStringToObject(gpsisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"rel_prox_info_convertToJSON() failed [gpsis]");
				goto end;
			}
		}
	}

	if(!rel_prox_info->ue_proximities) {
		printf("rel_prox_info_convertToJSON() failed [ue_proximities]");
		return NULL;
	}
	cJSON *ue_proximitiesList =
		cJSON_AddArrayToObject(item, "ueProximities");
	if(ue_proximitiesList == NULL) {
		printf("rel_prox_info_convertToJSON() failed [ue_proximities]");
		goto end;
	}
	list_for_each(rel_prox_info->ue_proximities, node) {
		cJSON *itemLocal = ue_proximity_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"rel_prox_info_convertToJSON() failed [ue_proximities]");
			goto end;
		}
		cJSON_AddItemToArray(ue_proximitiesList, itemLocal);
	}

	if(rel_prox_info->ttc_info) {
		cJSON *ttc_info_local_JSON =
			time_to_collision_info_convertToJSON(
				rel_prox_info->ttc_info);
		if(ttc_info_local_JSON == NULL) {
			printf("rel_prox_info_convertToJSON() failed [ttc_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ttcInfo", ttc_info_local_JSON);
		if(item->child == NULL) {
			printf("rel_prox_info_convertToJSON() failed [ttc_info]");
			goto end;
		}
	}

end:
	return item;
}

rel_prox_info_t *rel_prox_info_parseFromJSON(cJSON *rel_prox_infoJSON) {
	rel_prox_info_t *rel_prox_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ts_start = NULL;
	cJSON *ts_duration = NULL;
	cJSON *supis = NULL;
	list_t *supisList = NULL;
	cJSON *gpsis = NULL;
	list_t *gpsisList = NULL;
	cJSON *ue_proximities = NULL;
	list_t *ue_proximitiesList = NULL;
	cJSON *ttc_info = NULL;
	time_to_collision_info_t *ttc_info_local_nonprim = NULL;
	ts_start =
		cJSON_GetObjectItemCaseSensitive(rel_prox_infoJSON, "tsStart");
	if(!ts_start) {
		printf("rel_prox_info_parseFromJSON() failed [ts_start]");
		goto end;
	}
	if(!cJSON_IsString(ts_start) &&
	   !cJSON_IsNull(ts_start))
	{
		printf("rel_prox_info_parseFromJSON() failed [ts_start]");
		goto end;
	}

	ts_duration = cJSON_GetObjectItemCaseSensitive(rel_prox_infoJSON,
	                                               "tsDuration");
	if(!ts_duration) {
		printf("rel_prox_info_parseFromJSON() failed [ts_duration]");
		goto end;
	}
	if(!cJSON_IsNumber(ts_duration)) {
		printf("rel_prox_info_parseFromJSON() failed [ts_duration]");
		goto end;
	}

	supis = cJSON_GetObjectItemCaseSensitive(rel_prox_infoJSON, "supis");
	if(supis) {
		cJSON *supis_local = NULL;
		if(!cJSON_IsArray(supis)) {
			printf("rel_prox_info_parseFromJSON() failed [supis]");
			goto end;
		}

		supisList = list_create();

		cJSON_ArrayForEach(supis_local, supis) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(supis_local)) {
				printf(
					"rel_prox_info_parseFromJSON() failed [supis]");
				goto end;
			}
			list_add(supisList, strdup(supis_local->valuestring));
		}
	}

	gpsis = cJSON_GetObjectItemCaseSensitive(rel_prox_infoJSON, "gpsis");
	if(gpsis) {
		cJSON *gpsis_local = NULL;
		if(!cJSON_IsArray(gpsis)) {
			printf("rel_prox_info_parseFromJSON() failed [gpsis]");
			goto end;
		}

		gpsisList = list_create();

		cJSON_ArrayForEach(gpsis_local, gpsis) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(gpsis_local)) {
				printf(
					"rel_prox_info_parseFromJSON() failed [gpsis]");
				goto end;
			}
			list_add(gpsisList, strdup(gpsis_local->valuestring));
		}
	}

	ue_proximities = cJSON_GetObjectItemCaseSensitive(rel_prox_infoJSON,
	                                                  "ueProximities");
	if(!ue_proximities) {
		printf("rel_prox_info_parseFromJSON() failed [ue_proximities]");
		goto end;
	}
	cJSON *ue_proximities_local = NULL;
	if(!cJSON_IsArray(ue_proximities)) {
		printf("rel_prox_info_parseFromJSON() failed [ue_proximities]");
		goto end;
	}

	ue_proximitiesList = list_create();

	cJSON_ArrayForEach(ue_proximities_local, ue_proximities) {
		if(!cJSON_IsObject(ue_proximities_local)) {
			printf(
				"rel_prox_info_parseFromJSON() failed [ue_proximities]");
			goto end;
		}
		ue_proximity_t *ue_proximitiesItem = ue_proximity_parseFromJSON(
			ue_proximities_local);
		if(!ue_proximitiesItem) {
			printf("No ue_proximitiesItem");
			goto end;
		}
		list_add(ue_proximitiesList, ue_proximitiesItem);
	}

	ttc_info =
		cJSON_GetObjectItemCaseSensitive(rel_prox_infoJSON, "ttcInfo");
	if(ttc_info) {
		ttc_info_local_nonprim = time_to_collision_info_parseFromJSON(
			ttc_info);
		if(!ttc_info_local_nonprim) {
			printf(
				"time_to_collision_info_parseFromJSON failed [ttc_info]");
			goto end;
		}
	}

	rel_prox_info_local_var = rel_prox_info_create(
		strdup(ts_start->valuestring),

		ts_duration->valuedouble,
		supis ? supisList : NULL,
		gpsis ? gpsisList : NULL,
		ue_proximitiesList,
		ttc_info ? ttc_info_local_nonprim : NULL
		);

	return rel_prox_info_local_var;
end:
	if(supisList) {
		list_for_each(supisList, node) {
			free(node->data);
		}
		list_free(supisList);
		supisList = NULL;
	}
	if(gpsisList) {
		list_for_each(gpsisList, node) {
			free(node->data);
		}
		list_free(gpsisList);
		gpsisList = NULL;
	}
	if(ue_proximitiesList) {
		list_for_each(ue_proximitiesList, node) {
			ue_proximity_free(node->data);
		}
		list_free(ue_proximitiesList);
		ue_proximitiesList = NULL;
	}
	if(ttc_info_local_nonprim) {
		time_to_collision_info_free(ttc_info_local_nonprim);
		ttc_info_local_nonprim = NULL;
	}
	return NULL;
}

rel_prox_info_t *rel_prox_info_copy(rel_prox_info_t	*dst,
                                    rel_prox_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = rel_prox_info_convertToJSON(src);
	if(!item) {
		printf("rel_prox_info_convertToJSON() failed");
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

	rel_prox_info_free(dst);
	dst = rel_prox_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
