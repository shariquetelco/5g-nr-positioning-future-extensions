#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_area_indication.h"

ue_area_indication_t *ue_area_indication_create(char	*country,
                                                bool	is_international_area_ind,
                                                int	international_area_ind)
{
	ue_area_indication_t *ue_area_indication_local_var =
		malloc(sizeof(ue_area_indication_t));

	ue_area_indication_local_var->country = country;
	ue_area_indication_local_var->is_international_area_ind =
		is_international_area_ind;
	ue_area_indication_local_var->international_area_ind =
		international_area_ind;

	return ue_area_indication_local_var;
}

void ue_area_indication_free(ue_area_indication_t *ue_area_indication) {
	lnode_t *node = NULL;

	if(NULL == ue_area_indication) {
		return;
	}
	if(ue_area_indication->country) {
		free(ue_area_indication->country);
		ue_area_indication->country = NULL;
	}
	free(ue_area_indication);
}

cJSON *ue_area_indication_convertToJSON(
	ue_area_indication_t *ue_area_indication) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_area_indication == NULL) {
		printf(
			"ue_area_indication_convertToJSON() failed [UeAreaIndication]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_area_indication->country) {
		if(cJSON_AddStringToObject(item, "country",
		                           ue_area_indication->country) == NULL)
		{
			printf(
				"ue_area_indication_convertToJSON() failed [country]");
			goto end;
		}
	}

	if(ue_area_indication->is_international_area_ind) {
		if(cJSON_AddBoolToObject(item, "internationalAreaInd",
		                         ue_area_indication->
		                         international_area_ind) == NULL)
		{
			printf(
				"ue_area_indication_convertToJSON() failed [international_area_ind]");
			goto end;
		}
	}

end:
	return item;
}

ue_area_indication_t *ue_area_indication_parseFromJSON(
	cJSON *ue_area_indicationJSON) {
	ue_area_indication_t *ue_area_indication_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *country = NULL;
	cJSON *international_area_ind = NULL;
	country = cJSON_GetObjectItemCaseSensitive(ue_area_indicationJSON,
	                                           "country");
	if(country) {
		if(!cJSON_IsString(country) &&
		   !cJSON_IsNull(country))
		{
			printf(
				"ue_area_indication_parseFromJSON() failed [country]");
			goto end;
		}
	}

	international_area_ind = cJSON_GetObjectItemCaseSensitive(
		ue_area_indicationJSON, "internationalAreaInd");
	if(international_area_ind) {
		if(!cJSON_IsBool(international_area_ind)) {
			printf(
				"ue_area_indication_parseFromJSON() failed [international_area_ind]");
			goto end;
		}
	}

	ue_area_indication_local_var = ue_area_indication_create(
		country &&
		!cJSON_IsNull(country) ? strdup(country->valuestring) : NULL,
		international_area_ind ? true : false,
		international_area_ind ? international_area_ind->valueint : 0
		);

	return ue_area_indication_local_var;
end:
	return NULL;
}

ue_area_indication_t *ue_area_indication_copy(ue_area_indication_t	*dst,
                                              ue_area_indication_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_area_indication_convertToJSON(src);
	if(!item) {
		printf("ue_area_indication_convertToJSON() failed");
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

	ue_area_indication_free(dst);
	dst = ue_area_indication_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
