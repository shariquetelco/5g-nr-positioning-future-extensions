#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_proximity.h"

ue_proximity_t *ue_proximity_create(bool is_ue_distance, int ue_distance,
                                    velocity_estimate_t *ue_velocity,
                                    bool is_avr_speed, float avr_speed,
                                    location_orientation_t *loc_orientation,
                                    list_t *ue_trajectories, bool is_ratio,
                                    int ratio) {
	ue_proximity_t *ue_proximity_local_var = malloc(sizeof(ue_proximity_t));

	ue_proximity_local_var->is_ue_distance = is_ue_distance;
	ue_proximity_local_var->ue_distance = ue_distance;
	ue_proximity_local_var->ue_velocity = ue_velocity;
	ue_proximity_local_var->is_avr_speed = is_avr_speed;
	ue_proximity_local_var->avr_speed = avr_speed;
	ue_proximity_local_var->loc_orientation = loc_orientation;
	ue_proximity_local_var->ue_trajectories = ue_trajectories;
	ue_proximity_local_var->is_ratio = is_ratio;
	ue_proximity_local_var->ratio = ratio;

	return ue_proximity_local_var;
}

void ue_proximity_free(ue_proximity_t *ue_proximity) {
	lnode_t *node = NULL;

	if(NULL == ue_proximity) {
		return;
	}
	if(ue_proximity->ue_velocity) {
		velocity_estimate_free(ue_proximity->ue_velocity);
		ue_proximity->ue_velocity = NULL;
	}
	if(ue_proximity->loc_orientation) {
		location_orientation_free(ue_proximity->loc_orientation);
		ue_proximity->loc_orientation = NULL;
	}
	if(ue_proximity->ue_trajectories) {
		list_for_each(ue_proximity->ue_trajectories, node) {
			ue_trajectory_free(node->data);
		}
		list_free(ue_proximity->ue_trajectories);
		ue_proximity->ue_trajectories = NULL;
	}
	free(ue_proximity);
}

cJSON *ue_proximity_convertToJSON(ue_proximity_t *ue_proximity) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_proximity == NULL) {
		printf("ue_proximity_convertToJSON() failed [UeProximity]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_proximity->is_ue_distance) {
		if(cJSON_AddNumberToObject(item, "ueDistance",
		                           ue_proximity->ue_distance) == NULL)
		{
			printf(
				"ue_proximity_convertToJSON() failed [ue_distance]");
			goto end;
		}
	}

	if(ue_proximity->ue_velocity) {
		cJSON *ue_velocity_local_JSON = velocity_estimate_convertToJSON(
			ue_proximity->ue_velocity);
		if(ue_velocity_local_JSON == NULL) {
			printf(
				"ue_proximity_convertToJSON() failed [ue_velocity]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueVelocity",
		                      ue_velocity_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_proximity_convertToJSON() failed [ue_velocity]");
			goto end;
		}
	}

	if(ue_proximity->is_avr_speed) {
		if(cJSON_AddNumberToObject(item, "avrSpeed",
		                           ue_proximity->avr_speed) == NULL)
		{
			printf("ue_proximity_convertToJSON() failed [avr_speed]");
			goto end;
		}
	}

	if(ue_proximity->loc_orientation) {
		cJSON *loc_orientation_local_JSON =
			location_orientation_convertToJSON(
				ue_proximity->loc_orientation);
		if(loc_orientation_local_JSON == NULL) {
			printf(
				"ue_proximity_convertToJSON() failed [loc_orientation]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locOrientation",
		                      loc_orientation_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_proximity_convertToJSON() failed [loc_orientation]");
			goto end;
		}
	}

	if(ue_proximity->ue_trajectories) {
		cJSON *ue_trajectoriesList = cJSON_AddArrayToObject(item,
		                                                    "ueTrajectories");
		if(ue_trajectoriesList == NULL) {
			printf(
				"ue_proximity_convertToJSON() failed [ue_trajectories]");
			goto end;
		}
		list_for_each(ue_proximity->ue_trajectories, node) {
			cJSON *itemLocal = ue_trajectory_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"ue_proximity_convertToJSON() failed [ue_trajectories]");
				goto end;
			}
			cJSON_AddItemToArray(ue_trajectoriesList, itemLocal);
		}
	}

	if(ue_proximity->is_ratio) {
		if(cJSON_AddNumberToObject(item, "ratio",
		                           ue_proximity->ratio) == NULL)
		{
			printf("ue_proximity_convertToJSON() failed [ratio]");
			goto end;
		}
	}

end:
	return item;
}

ue_proximity_t *ue_proximity_parseFromJSON(cJSON *ue_proximityJSON) {
	ue_proximity_t *ue_proximity_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ue_distance = NULL;
	cJSON *ue_velocity = NULL;
	velocity_estimate_t *ue_velocity_local_nonprim = NULL;
	cJSON *avr_speed = NULL;
	cJSON *loc_orientation = NULL;
	location_orientation_t *loc_orientation_local_nonprim = NULL;
	cJSON *ue_trajectories = NULL;
	list_t *ue_trajectoriesList = NULL;
	cJSON *ratio = NULL;
	ue_distance = cJSON_GetObjectItemCaseSensitive(ue_proximityJSON,
	                                               "ueDistance");
	if(ue_distance) {
		if(!cJSON_IsNumber(ue_distance)) {
			printf(
				"ue_proximity_parseFromJSON() failed [ue_distance]");
			goto end;
		}
	}

	ue_velocity = cJSON_GetObjectItemCaseSensitive(ue_proximityJSON,
	                                               "ueVelocity");
	if(ue_velocity) {
		ue_velocity_local_nonprim = velocity_estimate_parseFromJSON(
			ue_velocity);
		if(!ue_velocity_local_nonprim) {
			printf(
				"velocity_estimate_parseFromJSON failed [ue_velocity]");
			goto end;
		}
	}

	avr_speed = cJSON_GetObjectItemCaseSensitive(ue_proximityJSON,
	                                             "avrSpeed");
	if(avr_speed) {
		if(!cJSON_IsNumber(avr_speed)) {
			printf("ue_proximity_parseFromJSON() failed [avr_speed]");
			goto end;
		}
	}

	loc_orientation = cJSON_GetObjectItemCaseSensitive(ue_proximityJSON,
	                                                   "locOrientation");
	if(loc_orientation) {
		loc_orientation_local_nonprim =
			location_orientation_parseFromJSON(loc_orientation);
		if(!loc_orientation_local_nonprim) {
			printf(
				"location_orientation_parseFromJSON failed [loc_orientation]");
			goto end;
		}
	}

	ue_trajectories = cJSON_GetObjectItemCaseSensitive(ue_proximityJSON,
	                                                   "ueTrajectories");
	if(ue_trajectories) {
		cJSON *ue_trajectories_local = NULL;
		if(!cJSON_IsArray(ue_trajectories)) {
			printf(
				"ue_proximity_parseFromJSON() failed [ue_trajectories]");
			goto end;
		}

		ue_trajectoriesList = list_create();

		cJSON_ArrayForEach(ue_trajectories_local, ue_trajectories) {
			if(!cJSON_IsObject(ue_trajectories_local)) {
				printf(
					"ue_proximity_parseFromJSON() failed [ue_trajectories]");
				goto end;
			}
			ue_trajectory_t *ue_trajectoriesItem =
				ue_trajectory_parseFromJSON(
					ue_trajectories_local);
			if(!ue_trajectoriesItem) {
				printf("No ue_trajectoriesItem");
				goto end;
			}
			list_add(ue_trajectoriesList, ue_trajectoriesItem);
		}
	}

	ratio = cJSON_GetObjectItemCaseSensitive(ue_proximityJSON, "ratio");
	if(ratio) {
		if(!cJSON_IsNumber(ratio)) {
			printf("ue_proximity_parseFromJSON() failed [ratio]");
			goto end;
		}
	}

	ue_proximity_local_var = ue_proximity_create(
		ue_distance ? true : false,
		ue_distance ? ue_distance->valuedouble : 0,
		ue_velocity ? ue_velocity_local_nonprim : NULL,
		avr_speed ? true : false,
		avr_speed ? avr_speed->valuedouble : 0,
		loc_orientation ? loc_orientation_local_nonprim : NULL,
		ue_trajectories ? ue_trajectoriesList : NULL,
		ratio ? true : false,
		ratio ? ratio->valuedouble : 0
		);

	return ue_proximity_local_var;
end:
	if(ue_velocity_local_nonprim) {
		velocity_estimate_free(ue_velocity_local_nonprim);
		ue_velocity_local_nonprim = NULL;
	}
	if(loc_orientation_local_nonprim) {
		location_orientation_free(loc_orientation_local_nonprim);
		loc_orientation_local_nonprim = NULL;
	}
	if(ue_trajectoriesList) {
		list_for_each(ue_trajectoriesList, node) {
			ue_trajectory_free(node->data);
		}
		list_free(ue_trajectoriesList);
		ue_trajectoriesList = NULL;
	}
	return NULL;
}

ue_proximity_t *ue_proximity_copy(ue_proximity_t *dst, ue_proximity_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_proximity_convertToJSON(src);
	if(!item) {
		printf("ue_proximity_convertToJSON() failed");
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

	ue_proximity_free(dst);
	dst = ue_proximity_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
