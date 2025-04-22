#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "expected_ue_behavior.h"

expected_ue_behavior_t *expected_ue_behavior_create(
	list_t	*exp_move_trajectory,
	char	*validity_time)
{
	expected_ue_behavior_t *expected_ue_behavior_local_var =
		malloc(sizeof(expected_ue_behavior_t));

	expected_ue_behavior_local_var->exp_move_trajectory =
		exp_move_trajectory;
	expected_ue_behavior_local_var->validity_time = validity_time;

	return expected_ue_behavior_local_var;
}

void expected_ue_behavior_free(expected_ue_behavior_t *expected_ue_behavior) {
	lnode_t *node = NULL;

	if(NULL == expected_ue_behavior) {
		return;
	}
	if(expected_ue_behavior->exp_move_trajectory) {
		list_for_each(expected_ue_behavior->exp_move_trajectory, node) {
			user_location_free(node->data);
		}
		list_free(expected_ue_behavior->exp_move_trajectory);
		expected_ue_behavior->exp_move_trajectory = NULL;
	}
	if(expected_ue_behavior->validity_time) {
		free(expected_ue_behavior->validity_time);
		expected_ue_behavior->validity_time = NULL;
	}
	free(expected_ue_behavior);
}

cJSON *expected_ue_behavior_convertToJSON(
	expected_ue_behavior_t *expected_ue_behavior) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(expected_ue_behavior == NULL) {
		printf(
			"expected_ue_behavior_convertToJSON() failed [ExpectedUeBehavior]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!expected_ue_behavior->exp_move_trajectory) {
		printf(
			"expected_ue_behavior_convertToJSON() failed [exp_move_trajectory]");
		return NULL;
	}
	cJSON *exp_move_trajectoryList = cJSON_AddArrayToObject(item,
	                                                        "expMoveTrajectory");
	if(exp_move_trajectoryList == NULL) {
		printf(
			"expected_ue_behavior_convertToJSON() failed [exp_move_trajectory]");
		goto end;
	}
	list_for_each(expected_ue_behavior->exp_move_trajectory, node) {
		cJSON *itemLocal = user_location_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"expected_ue_behavior_convertToJSON() failed [exp_move_trajectory]");
			goto end;
		}
		cJSON_AddItemToArray(exp_move_trajectoryList, itemLocal);
	}

	if(!expected_ue_behavior->validity_time) {
		printf(
			"expected_ue_behavior_convertToJSON() failed [validity_time]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "validityTime",
	                           expected_ue_behavior->validity_time) == NULL)
	{
		printf(
			"expected_ue_behavior_convertToJSON() failed [validity_time]");
		goto end;
	}

end:
	return item;
}

expected_ue_behavior_t *expected_ue_behavior_parseFromJSON(
	cJSON *expected_ue_behaviorJSON) {
	expected_ue_behavior_t *expected_ue_behavior_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *exp_move_trajectory = NULL;
	list_t *exp_move_trajectoryList = NULL;
	cJSON *validity_time = NULL;
	exp_move_trajectory = cJSON_GetObjectItemCaseSensitive(
		expected_ue_behaviorJSON, "expMoveTrajectory");
	if(!exp_move_trajectory) {
		printf(
			"expected_ue_behavior_parseFromJSON() failed [exp_move_trajectory]");
		goto end;
	}
	cJSON *exp_move_trajectory_local = NULL;
	if(!cJSON_IsArray(exp_move_trajectory)) {
		printf(
			"expected_ue_behavior_parseFromJSON() failed [exp_move_trajectory]");
		goto end;
	}

	exp_move_trajectoryList = list_create();

	cJSON_ArrayForEach(exp_move_trajectory_local, exp_move_trajectory) {
		if(!cJSON_IsObject(exp_move_trajectory_local)) {
			printf(
				"expected_ue_behavior_parseFromJSON() failed [exp_move_trajectory]");
			goto end;
		}
		user_location_t *exp_move_trajectoryItem =
			user_location_parseFromJSON(exp_move_trajectory_local);
		if(!exp_move_trajectoryItem) {
			printf("No exp_move_trajectoryItem");
			goto end;
		}
		list_add(exp_move_trajectoryList, exp_move_trajectoryItem);
	}

	validity_time = cJSON_GetObjectItemCaseSensitive(
		expected_ue_behaviorJSON, "validityTime");
	if(!validity_time) {
		printf(
			"expected_ue_behavior_parseFromJSON() failed [validity_time]");
		goto end;
	}
	if(!cJSON_IsString(validity_time) &&
	   !cJSON_IsNull(validity_time))
	{
		printf(
			"expected_ue_behavior_parseFromJSON() failed [validity_time]");
		goto end;
	}

	expected_ue_behavior_local_var = expected_ue_behavior_create(
		exp_move_trajectoryList,
		strdup(validity_time->valuestring)
		);

	return expected_ue_behavior_local_var;
end:
	if(exp_move_trajectoryList) {
		list_for_each(exp_move_trajectoryList, node) {
			user_location_free(node->data);
		}
		list_free(exp_move_trajectoryList);
		exp_move_trajectoryList = NULL;
	}
	return NULL;
}

expected_ue_behavior_t *expected_ue_behavior_copy(
	expected_ue_behavior_t	*dst,
	expected_ue_behavior_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = expected_ue_behavior_convertToJSON(src);
	if(!item) {
		printf("expected_ue_behavior_convertToJSON() failed");
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

	expected_ue_behavior_free(dst);
	dst = expected_ue_behavior_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
