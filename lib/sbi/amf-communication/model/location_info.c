#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_info.h"

location_info_t *location_info_create(user_location_t *loc,
                                      geographical_area_t *geo_loc,
                                      bool is_ratio, int ratio,
                                      bool is_confidence, int confidence,
                                      list_t *geo_distr_infos,
                                      bool is_dist_threshold,
                                      int dist_threshold) {
	location_info_t *location_info_local_var = malloc(
		sizeof(location_info_t));

	location_info_local_var->loc = loc;
	location_info_local_var->geo_loc = geo_loc;
	location_info_local_var->is_ratio = is_ratio;
	location_info_local_var->ratio = ratio;
	location_info_local_var->is_confidence = is_confidence;
	location_info_local_var->confidence = confidence;
	location_info_local_var->geo_distr_infos = geo_distr_infos;
	location_info_local_var->is_dist_threshold = is_dist_threshold;
	location_info_local_var->dist_threshold = dist_threshold;

	return location_info_local_var;
}

void location_info_free(location_info_t *location_info) {
	lnode_t *node = NULL;

	if(NULL == location_info) {
		return;
	}
	if(location_info->loc) {
		user_location_free(location_info->loc);
		location_info->loc = NULL;
	}
	if(location_info->geo_loc) {
		geographical_area_free(location_info->geo_loc);
		location_info->geo_loc = NULL;
	}
	if(location_info->geo_distr_infos) {
		list_for_each(location_info->geo_distr_infos, node) {
			geo_distribution_info_free(node->data);
		}
		list_free(location_info->geo_distr_infos);
		location_info->geo_distr_infos = NULL;
	}
	free(location_info);
}

cJSON *location_info_convertToJSON(location_info_t *location_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(location_info == NULL) {
		printf("location_info_convertToJSON() failed [LocationInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!location_info->loc) {
		printf("location_info_convertToJSON() failed [loc]");
		return NULL;
	}
	cJSON *loc_local_JSON = user_location_convertToJSON(location_info->loc);
	if(loc_local_JSON == NULL) {
		printf("location_info_convertToJSON() failed [loc]");
		goto end;
	}
	cJSON_AddItemToObject(item, "loc", loc_local_JSON);
	if(item->child == NULL) {
		printf("location_info_convertToJSON() failed [loc]");
		goto end;
	}

	if(location_info->geo_loc) {
		cJSON *geo_loc_local_JSON = geographical_area_convertToJSON(
			location_info->geo_loc);
		if(geo_loc_local_JSON == NULL) {
			printf("location_info_convertToJSON() failed [geo_loc]");
			goto end;
		}
		cJSON_AddItemToObject(item, "geoLoc", geo_loc_local_JSON);
		if(item->child == NULL) {
			printf("location_info_convertToJSON() failed [geo_loc]");
			goto end;
		}
	}

	if(location_info->is_ratio) {
		if(cJSON_AddNumberToObject(item, "ratio",
		                           location_info->ratio) == NULL)
		{
			printf("location_info_convertToJSON() failed [ratio]");
			goto end;
		}
	}

	if(location_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           location_info->confidence) == NULL)
		{
			printf(
				"location_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

	if(location_info->geo_distr_infos) {
		cJSON *geo_distr_infosList = cJSON_AddArrayToObject(item,
		                                                    "geoDistrInfos");
		if(geo_distr_infosList == NULL) {
			printf(
				"location_info_convertToJSON() failed [geo_distr_infos]");
			goto end;
		}
		list_for_each(location_info->geo_distr_infos, node) {
			cJSON *itemLocal = geo_distribution_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"location_info_convertToJSON() failed [geo_distr_infos]");
				goto end;
			}
			cJSON_AddItemToArray(geo_distr_infosList, itemLocal);
		}
	}

	if(location_info->is_dist_threshold) {
		if(cJSON_AddNumberToObject(item, "distThreshold",
		                           location_info->dist_threshold) ==
		   NULL)
		{
			printf(
				"location_info_convertToJSON() failed [dist_threshold]");
			goto end;
		}
	}

end:
	return item;
}

location_info_t *location_info_parseFromJSON(cJSON *location_infoJSON) {
	location_info_t *location_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *loc = NULL;
	user_location_t *loc_local_nonprim = NULL;
	cJSON *geo_loc = NULL;
	geographical_area_t *geo_loc_local_nonprim = NULL;
	cJSON *ratio = NULL;
	cJSON *confidence = NULL;
	cJSON *geo_distr_infos = NULL;
	list_t *geo_distr_infosList = NULL;
	cJSON *dist_threshold = NULL;
	loc = cJSON_GetObjectItemCaseSensitive(location_infoJSON, "loc");
	if(!loc) {
		printf("location_info_parseFromJSON() failed [loc]");
		goto end;
	}
	loc_local_nonprim = user_location_parseFromJSON(loc);
	if(!loc_local_nonprim) {
		printf("user_location_parseFromJSON failed [loc]");
		goto end;
	}

	geo_loc = cJSON_GetObjectItemCaseSensitive(location_infoJSON, "geoLoc");
	if(geo_loc) {
		geo_loc_local_nonprim =
			geographical_area_parseFromJSON(geo_loc);
		if(!geo_loc_local_nonprim) {
			printf(
				"geographical_area_parseFromJSON failed [geo_loc]");
			goto end;
		}
	}

	ratio = cJSON_GetObjectItemCaseSensitive(location_infoJSON, "ratio");
	if(ratio) {
		if(!cJSON_IsNumber(ratio)) {
			printf("location_info_parseFromJSON() failed [ratio]");
			goto end;
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(location_infoJSON,
	                                              "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"location_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	geo_distr_infos = cJSON_GetObjectItemCaseSensitive(location_infoJSON,
	                                                   "geoDistrInfos");
	if(geo_distr_infos) {
		cJSON *geo_distr_infos_local = NULL;
		if(!cJSON_IsArray(geo_distr_infos)) {
			printf(
				"location_info_parseFromJSON() failed [geo_distr_infos]");
			goto end;
		}

		geo_distr_infosList = list_create();

		cJSON_ArrayForEach(geo_distr_infos_local, geo_distr_infos) {
			if(!cJSON_IsObject(geo_distr_infos_local)) {
				printf(
					"location_info_parseFromJSON() failed [geo_distr_infos]");
				goto end;
			}
			geo_distribution_info_t *geo_distr_infosItem =
				geo_distribution_info_parseFromJSON(
					geo_distr_infos_local);
			if(!geo_distr_infosItem) {
				printf("No geo_distr_infosItem");
				goto end;
			}
			list_add(geo_distr_infosList, geo_distr_infosItem);
		}
	}

	dist_threshold = cJSON_GetObjectItemCaseSensitive(location_infoJSON,
	                                                  "distThreshold");
	if(dist_threshold) {
		if(!cJSON_IsNumber(dist_threshold)) {
			printf(
				"location_info_parseFromJSON() failed [dist_threshold]");
			goto end;
		}
	}

	location_info_local_var = location_info_create(
		loc_local_nonprim,
		geo_loc ? geo_loc_local_nonprim : NULL,
		ratio ? true : false,
		ratio ? ratio->valuedouble : 0,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0,
		geo_distr_infos ? geo_distr_infosList : NULL,
		dist_threshold ? true : false,
		dist_threshold ? dist_threshold->valuedouble : 0
		);

	return location_info_local_var;
end:
	if(loc_local_nonprim) {
		user_location_free(loc_local_nonprim);
		loc_local_nonprim = NULL;
	}
	if(geo_loc_local_nonprim) {
		geographical_area_free(geo_loc_local_nonprim);
		geo_loc_local_nonprim = NULL;
	}
	if(geo_distr_infosList) {
		list_for_each(geo_distr_infosList, node) {
			geo_distribution_info_free(node->data);
		}
		list_free(geo_distr_infosList);
		geo_distr_infosList = NULL;
	}
	return NULL;
}

location_info_t *location_info_copy(location_info_t	*dst,
                                    location_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = location_info_convertToJSON(src);
	if(!item) {
		printf("location_info_convertToJSON() failed");
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

	location_info_free(dst);
	dst = location_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
