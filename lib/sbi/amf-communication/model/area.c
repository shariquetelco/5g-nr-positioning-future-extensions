#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "area.h"

area_t *area_create(list_t *tacs, char *area_code) {
	area_t *area_local_var = malloc(sizeof(area_t));

	area_local_var->tacs = tacs;
	area_local_var->area_code = area_code;

	return area_local_var;
}

void area_free(area_t *area) {
	lnode_t *node = NULL;

	if(NULL == area) {
		return;
	}
	if(area->tacs) {
		list_for_each(area->tacs, node) {
			free(node->data);
		}
		list_free(area->tacs);
		area->tacs = NULL;
	}
	if(area->area_code) {
		free(area->area_code);
		area->area_code = NULL;
	}
	free(area);
}

cJSON *area_convertToJSON(area_t *area) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(area == NULL) {
		printf("area_convertToJSON() failed [Area]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(area->tacs) {
		cJSON *tacsList = cJSON_AddArrayToObject(item, "tacs");
		if(tacsList == NULL) {
			printf("area_convertToJSON() failed [tacs]");
			goto end;
		}
		list_for_each(area->tacs, node) {
			if(cJSON_AddStringToObject(tacsList, "",
			                           (char *) node->data) == NULL)
			{
				printf("area_convertToJSON() failed [tacs]");
				goto end;
			}
		}
	}

	if(area->area_code) {
		if(cJSON_AddStringToObject(item, "areaCode",
		                           area->area_code) == NULL)
		{
			printf("area_convertToJSON() failed [area_code]");
			goto end;
		}
	}

end:
	return item;
}

area_t *area_parseFromJSON(cJSON *areaJSON) {
	area_t *area_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *tacs = NULL;
	list_t *tacsList = NULL;
	cJSON *area_code = NULL;
	tacs = cJSON_GetObjectItemCaseSensitive(areaJSON, "tacs");
	if(tacs) {
		cJSON *tacs_local = NULL;
		if(!cJSON_IsArray(tacs)) {
			printf("area_parseFromJSON() failed [tacs]");
			goto end;
		}

		tacsList = list_create();

		cJSON_ArrayForEach(tacs_local, tacs) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(tacs_local)) {
				printf("area_parseFromJSON() failed [tacs]");
				goto end;
			}
			list_add(tacsList, strdup(tacs_local->valuestring));
		}
	}

	area_code = cJSON_GetObjectItemCaseSensitive(areaJSON, "areaCode");
	if(area_code) {
		if(!cJSON_IsString(area_code) &&
		   !cJSON_IsNull(area_code))
		{
			printf("area_parseFromJSON() failed [area_code]");
			goto end;
		}
	}

	area_local_var = area_create(
		tacs ? tacsList : NULL,
		area_code &&
		!cJSON_IsNull(area_code) ? strdup(area_code->valuestring) : NULL
		);

	return area_local_var;
end:
	if(tacsList) {
		list_for_each(tacsList, node) {
			free(node->data);
		}
		list_free(tacsList);
		tacsList = NULL;
	}
	return NULL;
}

area_t *area_copy(area_t *dst, area_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = area_convertToJSON(src);
	if(!item) {
		printf("area_convertToJSON() failed");
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

	area_free(dst);
	dst = area_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
