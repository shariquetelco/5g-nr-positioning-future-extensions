#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_trajectory.h"

ue_trajectory_t *ue_trajectory_create(char *supi, char *gpsi,
                                      list_t *timestamped_locs) {
	ue_trajectory_t *ue_trajectory_local_var = malloc(
		sizeof(ue_trajectory_t));

	ue_trajectory_local_var->supi = supi;
	ue_trajectory_local_var->gpsi = gpsi;
	ue_trajectory_local_var->timestamped_locs = timestamped_locs;

	return ue_trajectory_local_var;
}

void ue_trajectory_free(ue_trajectory_t *ue_trajectory) {
	lnode_t *node = NULL;

	if(NULL == ue_trajectory) {
		return;
	}
	if(ue_trajectory->supi) {
		free(ue_trajectory->supi);
		ue_trajectory->supi = NULL;
	}
	if(ue_trajectory->gpsi) {
		free(ue_trajectory->gpsi);
		ue_trajectory->gpsi = NULL;
	}
	if(ue_trajectory->timestamped_locs) {
		list_for_each(ue_trajectory->timestamped_locs, node) {
			timestamped_location_free(node->data);
		}
		list_free(ue_trajectory->timestamped_locs);
		ue_trajectory->timestamped_locs = NULL;
	}
	free(ue_trajectory);
}

cJSON *ue_trajectory_convertToJSON(ue_trajectory_t *ue_trajectory) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_trajectory == NULL) {
		printf("ue_trajectory_convertToJSON() failed [UeTrajectory]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_trajectory->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           ue_trajectory->supi) == NULL)
		{
			printf("ue_trajectory_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(ue_trajectory->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           ue_trajectory->gpsi) == NULL)
		{
			printf("ue_trajectory_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(!ue_trajectory->timestamped_locs) {
		printf("ue_trajectory_convertToJSON() failed [timestamped_locs]");
		return NULL;
	}
	cJSON *timestamped_locsList = cJSON_AddArrayToObject(item,
	                                                     "timestampedLocs");
	if(timestamped_locsList == NULL) {
		printf("ue_trajectory_convertToJSON() failed [timestamped_locs]");
		goto end;
	}
	list_for_each(ue_trajectory->timestamped_locs, node) {
		cJSON *itemLocal =
			timestamped_location_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"ue_trajectory_convertToJSON() failed [timestamped_locs]");
			goto end;
		}
		cJSON_AddItemToArray(timestamped_locsList, itemLocal);
	}

end:
	return item;
}

ue_trajectory_t *ue_trajectory_parseFromJSON(cJSON *ue_trajectoryJSON) {
	ue_trajectory_t *ue_trajectory_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *supi = NULL;
	cJSON *gpsi = NULL;
	cJSON *timestamped_locs = NULL;
	list_t *timestamped_locsList = NULL;
	supi = cJSON_GetObjectItemCaseSensitive(ue_trajectoryJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf("ue_trajectory_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(ue_trajectoryJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("ue_trajectory_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	timestamped_locs = cJSON_GetObjectItemCaseSensitive(ue_trajectoryJSON,
	                                                    "timestampedLocs");
	if(!timestamped_locs) {
		printf("ue_trajectory_parseFromJSON() failed [timestamped_locs]");
		goto end;
	}
	cJSON *timestamped_locs_local = NULL;
	if(!cJSON_IsArray(timestamped_locs)) {
		printf("ue_trajectory_parseFromJSON() failed [timestamped_locs]");
		goto end;
	}

	timestamped_locsList = list_create();

	cJSON_ArrayForEach(timestamped_locs_local, timestamped_locs) {
		if(!cJSON_IsObject(timestamped_locs_local)) {
			printf(
				"ue_trajectory_parseFromJSON() failed [timestamped_locs]");
			goto end;
		}
		timestamped_location_t *timestamped_locsItem =
			timestamped_location_parseFromJSON(
				timestamped_locs_local);
		if(!timestamped_locsItem) {
			printf("No timestamped_locsItem");
			goto end;
		}
		list_add(timestamped_locsList, timestamped_locsItem);
	}

	ue_trajectory_local_var = ue_trajectory_create(
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		timestamped_locsList
		);

	return ue_trajectory_local_var;
end:
	if(timestamped_locsList) {
		list_for_each(timestamped_locsList, node) {
			timestamped_location_free(node->data);
		}
		list_free(timestamped_locsList);
		timestamped_locsList = NULL;
	}
	return NULL;
}

ue_trajectory_t *ue_trajectory_copy(ue_trajectory_t	*dst,
                                    ue_trajectory_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_trajectory_convertToJSON(src);
	if(!item) {
		printf("ue_trajectory_convertToJSON() failed");
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

	ue_trajectory_free(dst);
	dst = ue_trajectory_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
