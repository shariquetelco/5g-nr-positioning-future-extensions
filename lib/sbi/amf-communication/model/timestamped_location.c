#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "timestamped_location.h"

timestamped_location_t *timestamped_location_create(char	*ts,
                                                    list_t	*loc_info) {
	timestamped_location_t *timestamped_location_local_var =
		malloc(sizeof(timestamped_location_t));

	timestamped_location_local_var->ts = ts;
	timestamped_location_local_var->loc_info = loc_info;

	return timestamped_location_local_var;
}

void timestamped_location_free(timestamped_location_t *timestamped_location) {
	lnode_t *node = NULL;

	if(NULL == timestamped_location) {
		return;
	}
	if(timestamped_location->ts) {
		free(timestamped_location->ts);
		timestamped_location->ts = NULL;
	}
	if(timestamped_location->loc_info) {
		list_for_each(timestamped_location->loc_info, node) {
			location_info_free(node->data);
		}
		list_free(timestamped_location->loc_info);
		timestamped_location->loc_info = NULL;
	}
	free(timestamped_location);
}

cJSON *timestamped_location_convertToJSON(
	timestamped_location_t *timestamped_location) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(timestamped_location == NULL) {
		printf(
			"timestamped_location_convertToJSON() failed [TimestampedLocation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!timestamped_location->ts) {
		printf("timestamped_location_convertToJSON() failed [ts]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "ts",
	                           timestamped_location->ts) == NULL)
	{
		printf("timestamped_location_convertToJSON() failed [ts]");
		goto end;
	}

	if(!timestamped_location->loc_info) {
		printf("timestamped_location_convertToJSON() failed [loc_info]");
		return NULL;
	}
	cJSON *loc_infoList = cJSON_AddArrayToObject(item, "locInfo");
	if(loc_infoList == NULL) {
		printf("timestamped_location_convertToJSON() failed [loc_info]");
		goto end;
	}
	list_for_each(timestamped_location->loc_info, node) {
		cJSON *itemLocal = location_info_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"timestamped_location_convertToJSON() failed [loc_info]");
			goto end;
		}
		cJSON_AddItemToArray(loc_infoList, itemLocal);
	}

end:
	return item;
}

timestamped_location_t *timestamped_location_parseFromJSON(
	cJSON *timestamped_locationJSON) {
	timestamped_location_t *timestamped_location_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ts = NULL;
	cJSON *loc_info = NULL;
	list_t *loc_infoList = NULL;
	ts = cJSON_GetObjectItemCaseSensitive(timestamped_locationJSON, "ts");
	if(!ts) {
		printf("timestamped_location_parseFromJSON() failed [ts]");
		goto end;
	}
	if(!cJSON_IsString(ts) &&
	   !cJSON_IsNull(ts))
	{
		printf("timestamped_location_parseFromJSON() failed [ts]");
		goto end;
	}

	loc_info = cJSON_GetObjectItemCaseSensitive(timestamped_locationJSON,
	                                            "locInfo");
	if(!loc_info) {
		printf("timestamped_location_parseFromJSON() failed [loc_info]");
		goto end;
	}
	cJSON *loc_info_local = NULL;
	if(!cJSON_IsArray(loc_info)) {
		printf("timestamped_location_parseFromJSON() failed [loc_info]");
		goto end;
	}

	loc_infoList = list_create();

	cJSON_ArrayForEach(loc_info_local, loc_info) {
		if(!cJSON_IsObject(loc_info_local)) {
			printf(
				"timestamped_location_parseFromJSON() failed [loc_info]");
			goto end;
		}
		location_info_t *loc_infoItem = location_info_parseFromJSON(
			loc_info_local);
		if(!loc_infoItem) {
			printf("No loc_infoItem");
			goto end;
		}
		list_add(loc_infoList, loc_infoItem);
	}

	timestamped_location_local_var = timestamped_location_create(
		strdup(ts->valuestring),
		loc_infoList
		);

	return timestamped_location_local_var;
end:
	if(loc_infoList) {
		list_for_each(loc_infoList, node) {
			location_info_free(node->data);
		}
		list_free(loc_infoList);
		loc_infoList = NULL;
	}
	return NULL;
}

timestamped_location_t *timestamped_location_copy(
	timestamped_location_t	*dst,
	timestamped_location_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = timestamped_location_convertToJSON(src);
	if(!item) {
		printf("timestamped_location_convertToJSON() failed");
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

	timestamped_location_free(dst);
	dst = timestamped_location_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
