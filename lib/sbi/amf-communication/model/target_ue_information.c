#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "target_ue_information.h"

target_ue_information_t *target_ue_information_create(bool is_any_ue,
                                                      int any_ue, list_t *supis,
                                                      list_t *gpsis,
                                                      list_t *int_group_ids) {
	target_ue_information_t *target_ue_information_local_var = malloc(
		sizeof(target_ue_information_t));

	target_ue_information_local_var->is_any_ue = is_any_ue;
	target_ue_information_local_var->any_ue = any_ue;
	target_ue_information_local_var->supis = supis;
	target_ue_information_local_var->gpsis = gpsis;
	target_ue_information_local_var->int_group_ids = int_group_ids;

	return target_ue_information_local_var;
}

void target_ue_information_free(target_ue_information_t *target_ue_information)
{
	lnode_t *node = NULL;

	if(NULL == target_ue_information) {
		return;
	}
	if(target_ue_information->supis) {
		list_for_each(target_ue_information->supis, node) {
			free(node->data);
		}
		list_free(target_ue_information->supis);
		target_ue_information->supis = NULL;
	}
	if(target_ue_information->gpsis) {
		list_for_each(target_ue_information->gpsis, node) {
			free(node->data);
		}
		list_free(target_ue_information->gpsis);
		target_ue_information->gpsis = NULL;
	}
	if(target_ue_information->int_group_ids) {
		list_for_each(target_ue_information->int_group_ids, node) {
			free(node->data);
		}
		list_free(target_ue_information->int_group_ids);
		target_ue_information->int_group_ids = NULL;
	}
	free(target_ue_information);
}

cJSON *target_ue_information_convertToJSON(
	target_ue_information_t *target_ue_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(target_ue_information == NULL) {
		printf(
			"target_ue_information_convertToJSON() failed [TargetUeInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(target_ue_information->is_any_ue) {
		if(cJSON_AddBoolToObject(item, "anyUe",
		                         target_ue_information->any_ue) == NULL)
		{
			printf(
				"target_ue_information_convertToJSON() failed [any_ue]");
			goto end;
		}
	}

	if(target_ue_information->supis) {
		cJSON *supisList = cJSON_AddArrayToObject(item, "supis");
		if(supisList == NULL) {
			printf(
				"target_ue_information_convertToJSON() failed [supis]");
			goto end;
		}
		list_for_each(target_ue_information->supis, node) {
			if(cJSON_AddStringToObject(supisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"target_ue_information_convertToJSON() failed [supis]");
				goto end;
			}
		}
	}

	if(target_ue_information->gpsis) {
		cJSON *gpsisList = cJSON_AddArrayToObject(item, "gpsis");
		if(gpsisList == NULL) {
			printf(
				"target_ue_information_convertToJSON() failed [gpsis]");
			goto end;
		}
		list_for_each(target_ue_information->gpsis, node) {
			if(cJSON_AddStringToObject(gpsisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"target_ue_information_convertToJSON() failed [gpsis]");
				goto end;
			}
		}
	}

	if(target_ue_information->int_group_ids) {
		cJSON *int_group_idsList = cJSON_AddArrayToObject(item,
		                                                  "intGroupIds");
		if(int_group_idsList == NULL) {
			printf(
				"target_ue_information_convertToJSON() failed [int_group_ids]");
			goto end;
		}
		list_for_each(target_ue_information->int_group_ids, node) {
			if(cJSON_AddStringToObject(int_group_idsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"target_ue_information_convertToJSON() failed [int_group_ids]");
				goto end;
			}
		}
	}

end:
	return item;
}

target_ue_information_t *target_ue_information_parseFromJSON(
	cJSON *target_ue_informationJSON) {
	target_ue_information_t *target_ue_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *any_ue = NULL;
	cJSON *supis = NULL;
	list_t *supisList = NULL;
	cJSON *gpsis = NULL;
	list_t *gpsisList = NULL;
	cJSON *int_group_ids = NULL;
	list_t *int_group_idsList = NULL;
	any_ue = cJSON_GetObjectItemCaseSensitive(target_ue_informationJSON,
	                                          "anyUe");
	if(any_ue) {
		if(!cJSON_IsBool(any_ue)) {
			printf(
				"target_ue_information_parseFromJSON() failed [any_ue]");
			goto end;
		}
	}

	supis = cJSON_GetObjectItemCaseSensitive(target_ue_informationJSON,
	                                         "supis");
	if(supis) {
		cJSON *supis_local = NULL;
		if(!cJSON_IsArray(supis)) {
			printf(
				"target_ue_information_parseFromJSON() failed [supis]");
			goto end;
		}

		supisList = list_create();

		cJSON_ArrayForEach(supis_local, supis) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(supis_local)) {
				printf(
					"target_ue_information_parseFromJSON() failed [supis]");
				goto end;
			}
			list_add(supisList, strdup(supis_local->valuestring));
		}
	}

	gpsis = cJSON_GetObjectItemCaseSensitive(target_ue_informationJSON,
	                                         "gpsis");
	if(gpsis) {
		cJSON *gpsis_local = NULL;
		if(!cJSON_IsArray(gpsis)) {
			printf(
				"target_ue_information_parseFromJSON() failed [gpsis]");
			goto end;
		}

		gpsisList = list_create();

		cJSON_ArrayForEach(gpsis_local, gpsis) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(gpsis_local)) {
				printf(
					"target_ue_information_parseFromJSON() failed [gpsis]");
				goto end;
			}
			list_add(gpsisList, strdup(gpsis_local->valuestring));
		}
	}

	int_group_ids = cJSON_GetObjectItemCaseSensitive(
		target_ue_informationJSON, "intGroupIds");
	if(int_group_ids) {
		cJSON *int_group_ids_local = NULL;
		if(!cJSON_IsArray(int_group_ids)) {
			printf(
				"target_ue_information_parseFromJSON() failed [int_group_ids]");
			goto end;
		}

		int_group_idsList = list_create();

		cJSON_ArrayForEach(int_group_ids_local, int_group_ids) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(int_group_ids_local)) {
				printf(
					"target_ue_information_parseFromJSON() failed [int_group_ids]");
				goto end;
			}
			list_add(int_group_idsList,
			         strdup(int_group_ids_local->valuestring));
		}
	}

	target_ue_information_local_var = target_ue_information_create(
		any_ue ? true : false,
		any_ue ? any_ue->valueint : 0,
		supis ? supisList : NULL,
		gpsis ? gpsisList : NULL,
		int_group_ids ? int_group_idsList : NULL
		);

	return target_ue_information_local_var;
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
	if(int_group_idsList) {
		list_for_each(int_group_idsList, node) {
			free(node->data);
		}
		list_free(int_group_idsList);
		int_group_idsList = NULL;
	}
	return NULL;
}

target_ue_information_t *target_ue_information_copy(
	target_ue_information_t *dst, target_ue_information_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = target_ue_information_convertToJSON(src);
	if(!item) {
		printf("target_ue_information_convertToJSON() failed");
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

	target_ue_information_free(dst);
	dst = target_ue_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
