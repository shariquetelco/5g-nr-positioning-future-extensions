#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "geo_distribution_info.h"

geo_distribution_info_t *geo_distribution_info_create(user_location_t	*loc,
                                                      list_t		*supis,
                                                      list_t		*gpsis)
{
	geo_distribution_info_t *geo_distribution_info_local_var = malloc(
		sizeof(geo_distribution_info_t));

	geo_distribution_info_local_var->loc = loc;
	geo_distribution_info_local_var->supis = supis;
	geo_distribution_info_local_var->gpsis = gpsis;

	return geo_distribution_info_local_var;
}

void geo_distribution_info_free(geo_distribution_info_t *geo_distribution_info)
{
	lnode_t *node = NULL;

	if(NULL == geo_distribution_info) {
		return;
	}
	if(geo_distribution_info->loc) {
		user_location_free(geo_distribution_info->loc);
		geo_distribution_info->loc = NULL;
	}
	if(geo_distribution_info->supis) {
		list_for_each(geo_distribution_info->supis, node) {
			free(node->data);
		}
		list_free(geo_distribution_info->supis);
		geo_distribution_info->supis = NULL;
	}
	if(geo_distribution_info->gpsis) {
		list_for_each(geo_distribution_info->gpsis, node) {
			free(node->data);
		}
		list_free(geo_distribution_info->gpsis);
		geo_distribution_info->gpsis = NULL;
	}
	free(geo_distribution_info);
}

cJSON *geo_distribution_info_convertToJSON(
	geo_distribution_info_t *geo_distribution_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(geo_distribution_info == NULL) {
		printf(
			"geo_distribution_info_convertToJSON() failed [GeoDistributionInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!geo_distribution_info->loc) {
		printf("geo_distribution_info_convertToJSON() failed [loc]");
		return NULL;
	}
	cJSON *loc_local_JSON = user_location_convertToJSON(
		geo_distribution_info->loc);
	if(loc_local_JSON == NULL) {
		printf("geo_distribution_info_convertToJSON() failed [loc]");
		goto end;
	}
	cJSON_AddItemToObject(item, "loc", loc_local_JSON);
	if(item->child == NULL) {
		printf("geo_distribution_info_convertToJSON() failed [loc]");
		goto end;
	}

	if(geo_distribution_info->supis) {
		cJSON *supisList = cJSON_AddArrayToObject(item, "supis");
		if(supisList == NULL) {
			printf(
				"geo_distribution_info_convertToJSON() failed [supis]");
			goto end;
		}
		list_for_each(geo_distribution_info->supis, node) {
			if(cJSON_AddStringToObject(supisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"geo_distribution_info_convertToJSON() failed [supis]");
				goto end;
			}
		}
	}

	if(geo_distribution_info->gpsis) {
		cJSON *gpsisList = cJSON_AddArrayToObject(item, "gpsis");
		if(gpsisList == NULL) {
			printf(
				"geo_distribution_info_convertToJSON() failed [gpsis]");
			goto end;
		}
		list_for_each(geo_distribution_info->gpsis, node) {
			if(cJSON_AddStringToObject(gpsisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"geo_distribution_info_convertToJSON() failed [gpsis]");
				goto end;
			}
		}
	}

end:
	return item;
}

geo_distribution_info_t *geo_distribution_info_parseFromJSON(
	cJSON *geo_distribution_infoJSON) {
	geo_distribution_info_t *geo_distribution_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *loc = NULL;
	user_location_t *loc_local_nonprim = NULL;
	cJSON *supis = NULL;
	list_t *supisList = NULL;
	cJSON *gpsis = NULL;
	list_t *gpsisList = NULL;
	loc =
		cJSON_GetObjectItemCaseSensitive(geo_distribution_infoJSON,
		                                 "loc");
	if(!loc) {
		printf("geo_distribution_info_parseFromJSON() failed [loc]");
		goto end;
	}
	loc_local_nonprim = user_location_parseFromJSON(loc);
	if(!loc_local_nonprim) {
		printf("user_location_parseFromJSON failed [loc]");
		goto end;
	}

	supis = cJSON_GetObjectItemCaseSensitive(geo_distribution_infoJSON,
	                                         "supis");
	if(supis) {
		cJSON *supis_local = NULL;
		if(!cJSON_IsArray(supis)) {
			printf(
				"geo_distribution_info_parseFromJSON() failed [supis]");
			goto end;
		}

		supisList = list_create();

		cJSON_ArrayForEach(supis_local, supis) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(supis_local)) {
				printf(
					"geo_distribution_info_parseFromJSON() failed [supis]");
				goto end;
			}
			list_add(supisList, strdup(supis_local->valuestring));
		}
	}

	gpsis = cJSON_GetObjectItemCaseSensitive(geo_distribution_infoJSON,
	                                         "gpsis");
	if(gpsis) {
		cJSON *gpsis_local = NULL;
		if(!cJSON_IsArray(gpsis)) {
			printf(
				"geo_distribution_info_parseFromJSON() failed [gpsis]");
			goto end;
		}

		gpsisList = list_create();

		cJSON_ArrayForEach(gpsis_local, gpsis) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(gpsis_local)) {
				printf(
					"geo_distribution_info_parseFromJSON() failed [gpsis]");
				goto end;
			}
			list_add(gpsisList, strdup(gpsis_local->valuestring));
		}
	}

	geo_distribution_info_local_var = geo_distribution_info_create(
		loc_local_nonprim,
		supis ? supisList : NULL,
		gpsis ? gpsisList : NULL
		);

	return geo_distribution_info_local_var;
end:
	if(loc_local_nonprim) {
		user_location_free(loc_local_nonprim);
		loc_local_nonprim = NULL;
	}
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
	return NULL;
}

geo_distribution_info_t *geo_distribution_info_copy(
	geo_distribution_info_t *dst, geo_distribution_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = geo_distribution_info_convertToJSON(src);
	if(!item) {
		printf("geo_distribution_info_convertToJSON() failed");
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

	geo_distribution_info_free(dst);
	dst = geo_distribution_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
