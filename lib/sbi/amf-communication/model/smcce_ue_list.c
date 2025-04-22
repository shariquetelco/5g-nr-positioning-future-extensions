#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "smcce_ue_list.h"

smcce_ue_list_t *smcce_ue_list_create(list_t *high_level, list_t *medium_level,
                                      list_t *low_level) {
	smcce_ue_list_t *smcce_ue_list_local_var = malloc(
		sizeof(smcce_ue_list_t));

	smcce_ue_list_local_var->high_level = high_level;
	smcce_ue_list_local_var->medium_level = medium_level;
	smcce_ue_list_local_var->low_level = low_level;

	return smcce_ue_list_local_var;
}

void smcce_ue_list_free(smcce_ue_list_t *smcce_ue_list) {
	lnode_t *node = NULL;

	if(NULL == smcce_ue_list) {
		return;
	}
	if(smcce_ue_list->high_level) {
		list_for_each(smcce_ue_list->high_level, node) {
			free(node->data);
		}
		list_free(smcce_ue_list->high_level);
		smcce_ue_list->high_level = NULL;
	}
	if(smcce_ue_list->medium_level) {
		list_for_each(smcce_ue_list->medium_level, node) {
			free(node->data);
		}
		list_free(smcce_ue_list->medium_level);
		smcce_ue_list->medium_level = NULL;
	}
	if(smcce_ue_list->low_level) {
		list_for_each(smcce_ue_list->low_level, node) {
			free(node->data);
		}
		list_free(smcce_ue_list->low_level);
		smcce_ue_list->low_level = NULL;
	}
	free(smcce_ue_list);
}

cJSON *smcce_ue_list_convertToJSON(smcce_ue_list_t *smcce_ue_list) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(smcce_ue_list == NULL) {
		printf("smcce_ue_list_convertToJSON() failed [SmcceUeList]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(smcce_ue_list->high_level) {
		cJSON *high_levelList =
			cJSON_AddArrayToObject(item, "highLevel");
		if(high_levelList == NULL) {
			printf(
				"smcce_ue_list_convertToJSON() failed [high_level]");
			goto end;
		}
		list_for_each(smcce_ue_list->high_level, node) {
			if(cJSON_AddStringToObject(high_levelList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"smcce_ue_list_convertToJSON() failed [high_level]");
				goto end;
			}
		}
	}

	if(smcce_ue_list->medium_level) {
		cJSON *medium_levelList = cJSON_AddArrayToObject(item,
		                                                 "mediumLevel");
		if(medium_levelList == NULL) {
			printf(
				"smcce_ue_list_convertToJSON() failed [medium_level]");
			goto end;
		}
		list_for_each(smcce_ue_list->medium_level, node) {
			if(cJSON_AddStringToObject(medium_levelList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"smcce_ue_list_convertToJSON() failed [medium_level]");
				goto end;
			}
		}
	}

	if(smcce_ue_list->low_level) {
		cJSON *low_levelList = cJSON_AddArrayToObject(item, "lowLevel");
		if(low_levelList == NULL) {
			printf(
				"smcce_ue_list_convertToJSON() failed [low_level]");
			goto end;
		}
		list_for_each(smcce_ue_list->low_level, node) {
			if(cJSON_AddStringToObject(low_levelList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"smcce_ue_list_convertToJSON() failed [low_level]");
				goto end;
			}
		}
	}

end:
	return item;
}

smcce_ue_list_t *smcce_ue_list_parseFromJSON(cJSON *smcce_ue_listJSON) {
	smcce_ue_list_t *smcce_ue_list_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *high_level = NULL;
	list_t *high_levelList = NULL;
	cJSON *medium_level = NULL;
	list_t *medium_levelList = NULL;
	cJSON *low_level = NULL;
	list_t *low_levelList = NULL;
	high_level = cJSON_GetObjectItemCaseSensitive(smcce_ue_listJSON,
	                                              "highLevel");
	if(high_level) {
		cJSON *high_level_local = NULL;
		if(!cJSON_IsArray(high_level)) {
			printf(
				"smcce_ue_list_parseFromJSON() failed [high_level]");
			goto end;
		}

		high_levelList = list_create();

		cJSON_ArrayForEach(high_level_local, high_level) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(high_level_local)) {
				printf(
					"smcce_ue_list_parseFromJSON() failed [high_level]");
				goto end;
			}
			list_add(high_levelList,
			         strdup(high_level_local->valuestring));
		}
	}

	medium_level = cJSON_GetObjectItemCaseSensitive(smcce_ue_listJSON,
	                                                "mediumLevel");
	if(medium_level) {
		cJSON *medium_level_local = NULL;
		if(!cJSON_IsArray(medium_level)) {
			printf(
				"smcce_ue_list_parseFromJSON() failed [medium_level]");
			goto end;
		}

		medium_levelList = list_create();

		cJSON_ArrayForEach(medium_level_local, medium_level) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(medium_level_local)) {
				printf(
					"smcce_ue_list_parseFromJSON() failed [medium_level]");
				goto end;
			}
			list_add(medium_levelList,
			         strdup(medium_level_local->valuestring));
		}
	}

	low_level = cJSON_GetObjectItemCaseSensitive(smcce_ue_listJSON,
	                                             "lowLevel");
	if(low_level) {
		cJSON *low_level_local = NULL;
		if(!cJSON_IsArray(low_level)) {
			printf(
				"smcce_ue_list_parseFromJSON() failed [low_level]");
			goto end;
		}

		low_levelList = list_create();

		cJSON_ArrayForEach(low_level_local, low_level) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(low_level_local)) {
				printf(
					"smcce_ue_list_parseFromJSON() failed [low_level]");
				goto end;
			}
			list_add(low_levelList,
			         strdup(low_level_local->valuestring));
		}
	}

	smcce_ue_list_local_var = smcce_ue_list_create(
		high_level ? high_levelList : NULL,
		medium_level ? medium_levelList : NULL,
		low_level ? low_levelList : NULL
		);

	return smcce_ue_list_local_var;
end:
	if(high_levelList) {
		list_for_each(high_levelList, node) {
			free(node->data);
		}
		list_free(high_levelList);
		high_levelList = NULL;
	}
	if(medium_levelList) {
		list_for_each(medium_levelList, node) {
			free(node->data);
		}
		list_free(medium_levelList);
		medium_levelList = NULL;
	}
	if(low_levelList) {
		list_for_each(low_levelList, node) {
			free(node->data);
		}
		list_free(low_levelList);
		low_levelList = NULL;
	}
	return NULL;
}

smcce_ue_list_t *smcce_ue_list_copy(smcce_ue_list_t	*dst,
                                    smcce_ue_list_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = smcce_ue_list_convertToJSON(src);
	if(!item) {
		printf("smcce_ue_list_convertToJSON() failed");
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

	smcce_ue_list_free(dst);
	dst = smcce_ue_list_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
