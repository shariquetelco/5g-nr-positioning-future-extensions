#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rel_prox_req.h"

rel_prox_req_t *rel_prox_req_create(list_t *direction, bool is_num_of_ue,
                                    int num_of_ue, list_t *proximity_crits) {
	rel_prox_req_t *rel_prox_req_local_var = malloc(sizeof(rel_prox_req_t));

	rel_prox_req_local_var->direction = direction;
	rel_prox_req_local_var->is_num_of_ue = is_num_of_ue;
	rel_prox_req_local_var->num_of_ue = num_of_ue;
	rel_prox_req_local_var->proximity_crits = proximity_crits;

	return rel_prox_req_local_var;
}

void rel_prox_req_free(rel_prox_req_t *rel_prox_req) {
	lnode_t *node = NULL;

	if(NULL == rel_prox_req) {
		return;
	}
	if(rel_prox_req->direction) {
		list_for_each(rel_prox_req->direction, node) {
			direction_free(node->data);
		}
		list_free(rel_prox_req->direction);
		rel_prox_req->direction = NULL;
	}
	if(rel_prox_req->proximity_crits) {
		list_for_each(rel_prox_req->proximity_crits, node) {
			proximity_criterion_free(node->data);
		}
		list_free(rel_prox_req->proximity_crits);
		rel_prox_req->proximity_crits = NULL;
	}
	free(rel_prox_req);
}

cJSON *rel_prox_req_convertToJSON(rel_prox_req_t *rel_prox_req) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(rel_prox_req == NULL) {
		printf("rel_prox_req_convertToJSON() failed [RelProxReq]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(rel_prox_req->direction) {
		cJSON *directionList =
			cJSON_AddArrayToObject(item, "direction");
		if(directionList == NULL) {
			printf("rel_prox_req_convertToJSON() failed [direction]");
			goto end;
		}
		list_for_each(rel_prox_req->direction, node) {
			cJSON *itemLocal = direction_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"rel_prox_req_convertToJSON() failed [direction]");
				goto end;
			}
			cJSON_AddItemToArray(directionList, itemLocal);
		}
	}

	if(rel_prox_req->is_num_of_ue) {
		if(cJSON_AddNumberToObject(item, "numOfUe",
		                           rel_prox_req->num_of_ue) == NULL)
		{
			printf("rel_prox_req_convertToJSON() failed [num_of_ue]");
			goto end;
		}
	}

	if(rel_prox_req->proximity_crits) {
		cJSON *proximity_critsList = cJSON_AddArrayToObject(item,
		                                                    "proximityCrits");
		if(proximity_critsList == NULL) {
			printf(
				"rel_prox_req_convertToJSON() failed [proximity_crits]");
			goto end;
		}
		list_for_each(rel_prox_req->proximity_crits, node) {
			cJSON *itemLocal = proximity_criterion_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"rel_prox_req_convertToJSON() failed [proximity_crits]");
				goto end;
			}
			cJSON_AddItemToArray(proximity_critsList, itemLocal);
		}
	}

end:
	return item;
}

rel_prox_req_t *rel_prox_req_parseFromJSON(cJSON *rel_prox_reqJSON) {
	rel_prox_req_t *rel_prox_req_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *direction = NULL;
	list_t *directionList = NULL;
	cJSON *num_of_ue = NULL;
	cJSON *proximity_crits = NULL;
	list_t *proximity_critsList = NULL;
	direction = cJSON_GetObjectItemCaseSensitive(rel_prox_reqJSON,
	                                             "direction");
	if(direction) {
		cJSON *direction_local = NULL;
		if(!cJSON_IsArray(direction)) {
			printf("rel_prox_req_parseFromJSON() failed [direction]");
			goto end;
		}

		directionList = list_create();

		cJSON_ArrayForEach(direction_local, direction) {
			if(!cJSON_IsObject(direction_local)) {
				printf(
					"rel_prox_req_parseFromJSON() failed [direction]");
				goto end;
			}
			direction_t *directionItem = direction_parseFromJSON(
				direction_local);
			if(!directionItem) {
				printf("No directionItem");
				goto end;
			}
			list_add(directionList, directionItem);
		}
	}

	num_of_ue =
		cJSON_GetObjectItemCaseSensitive(rel_prox_reqJSON, "numOfUe");
	if(num_of_ue) {
		if(!cJSON_IsNumber(num_of_ue)) {
			printf("rel_prox_req_parseFromJSON() failed [num_of_ue]");
			goto end;
		}
	}

	proximity_crits = cJSON_GetObjectItemCaseSensitive(rel_prox_reqJSON,
	                                                   "proximityCrits");
	if(proximity_crits) {
		cJSON *proximity_crits_local = NULL;
		if(!cJSON_IsArray(proximity_crits)) {
			printf(
				"rel_prox_req_parseFromJSON() failed [proximity_crits]");
			goto end;
		}

		proximity_critsList = list_create();

		cJSON_ArrayForEach(proximity_crits_local, proximity_crits) {
			if(!cJSON_IsObject(proximity_crits_local)) {
				printf(
					"rel_prox_req_parseFromJSON() failed [proximity_crits]");
				goto end;
			}
			proximity_criterion_t *proximity_critsItem =
				proximity_criterion_parseFromJSON(
					proximity_crits_local);
			if(!proximity_critsItem) {
				printf("No proximity_critsItem");
				goto end;
			}
			list_add(proximity_critsList, proximity_critsItem);
		}
	}

	rel_prox_req_local_var = rel_prox_req_create(
		direction ? directionList : NULL,
		num_of_ue ? true : false,
		num_of_ue ? num_of_ue->valuedouble : 0,
		proximity_crits ? proximity_critsList : NULL
		);

	return rel_prox_req_local_var;
end:
	if(directionList) {
		list_for_each(directionList, node) {
			direction_free(node->data);
		}
		list_free(directionList);
		directionList = NULL;
	}
	if(proximity_critsList) {
		list_for_each(proximity_critsList, node) {
			proximity_criterion_free(node->data);
		}
		list_free(proximity_critsList);
		proximity_critsList = NULL;
	}
	return NULL;
}

rel_prox_req_t *rel_prox_req_copy(rel_prox_req_t *dst, rel_prox_req_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = rel_prox_req_convertToJSON(src);
	if(!item) {
		printf("rel_prox_req_convertToJSON() failed");
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

	rel_prox_req_free(dst);
	dst = rel_prox_req_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
