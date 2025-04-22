#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "circumstance_description.h"

circumstance_description_t *circumstance_description_create(bool is_freq,
                                                            float freq,
                                                            char *tm,
                                                            network_area_info_t *loc_area, bool is_vol,
                                                            long vol) {
	circumstance_description_t *circumstance_description_local_var = malloc(
		sizeof(circumstance_description_t));

	circumstance_description_local_var->is_freq = is_freq;
	circumstance_description_local_var->freq = freq;
	circumstance_description_local_var->tm = tm;
	circumstance_description_local_var->loc_area = loc_area;
	circumstance_description_local_var->is_vol = is_vol;
	circumstance_description_local_var->vol = vol;

	return circumstance_description_local_var;
}

void circumstance_description_free(
	circumstance_description_t *circumstance_description) {
	lnode_t *node = NULL;

	if(NULL == circumstance_description) {
		return;
	}
	if(circumstance_description->tm) {
		free(circumstance_description->tm);
		circumstance_description->tm = NULL;
	}
	if(circumstance_description->loc_area) {
		network_area_info_free(circumstance_description->loc_area);
		circumstance_description->loc_area = NULL;
	}
	free(circumstance_description);
}

cJSON *circumstance_description_convertToJSON(
	circumstance_description_t *circumstance_description) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(circumstance_description == NULL) {
		printf(
			"circumstance_description_convertToJSON() failed [CircumstanceDescription]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(circumstance_description->is_freq) {
		if(cJSON_AddNumberToObject(item, "freq",
		                           circumstance_description->freq) ==
		   NULL)
		{
			printf(
				"circumstance_description_convertToJSON() failed [freq]");
			goto end;
		}
	}

	if(circumstance_description->tm) {
		if(cJSON_AddStringToObject(item, "tm",
		                           circumstance_description->tm) ==
		   NULL)
		{
			printf(
				"circumstance_description_convertToJSON() failed [tm]");
			goto end;
		}
	}

	if(circumstance_description->loc_area) {
		cJSON *loc_area_local_JSON = network_area_info_convertToJSON(
			circumstance_description->loc_area);
		if(loc_area_local_JSON == NULL) {
			printf(
				"circumstance_description_convertToJSON() failed [loc_area]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locArea", loc_area_local_JSON);
		if(item->child == NULL) {
			printf(
				"circumstance_description_convertToJSON() failed [loc_area]");
			goto end;
		}
	}

	if(circumstance_description->is_vol) {
		if(cJSON_AddNumberToObject(item, "vol",
		                           circumstance_description->vol) ==
		   NULL)
		{
			printf(
				"circumstance_description_convertToJSON() failed [vol]");
			goto end;
		}
	}

end:
	return item;
}

circumstance_description_t *circumstance_description_parseFromJSON(
	cJSON *circumstance_descriptionJSON) {
	circumstance_description_t *circumstance_description_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *freq = NULL;
	cJSON *tm = NULL;
	cJSON *loc_area = NULL;
	network_area_info_t *loc_area_local_nonprim = NULL;
	cJSON *vol = NULL;
	freq = cJSON_GetObjectItemCaseSensitive(circumstance_descriptionJSON,
	                                        "freq");
	if(freq) {
		if(!cJSON_IsNumber(freq)) {
			printf(
				"circumstance_description_parseFromJSON() failed [freq]");
			goto end;
		}
	}

	tm =
		cJSON_GetObjectItemCaseSensitive(circumstance_descriptionJSON,
		                                 "tm");
	if(tm) {
		if(!cJSON_IsString(tm) &&
		   !cJSON_IsNull(tm))
		{
			printf(
				"circumstance_description_parseFromJSON() failed [tm]");
			goto end;
		}
	}

	loc_area = cJSON_GetObjectItemCaseSensitive(
		circumstance_descriptionJSON, "locArea");
	if(loc_area) {
		loc_area_local_nonprim = network_area_info_parseFromJSON(
			loc_area);
		if(!loc_area_local_nonprim) {
			printf(
				"network_area_info_parseFromJSON failed [loc_area]");
			goto end;
		}
	}

	vol = cJSON_GetObjectItemCaseSensitive(circumstance_descriptionJSON,
	                                       "vol");
	if(vol) {
		if(!cJSON_IsNumber(vol)) {
			printf(
				"circumstance_description_parseFromJSON() failed [vol]");
			goto end;
		}
	}

	circumstance_description_local_var = circumstance_description_create(
		freq ? true : false,
		freq ? freq->valuedouble : 0,
		tm &&
		!cJSON_IsNull(tm) ? strdup(tm->valuestring) : NULL,
		loc_area ? loc_area_local_nonprim : NULL,
		vol ? true : false,
		vol ? vol->valuedouble : 0
		);

	return circumstance_description_local_var;
end:
	if(loc_area_local_nonprim) {
		network_area_info_free(loc_area_local_nonprim);
		loc_area_local_nonprim = NULL;
	}
	return NULL;
}

circumstance_description_t *circumstance_description_copy(
	circumstance_description_t *dst, circumstance_description_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = circumstance_description_convertToJSON(src);
	if(!item) {
		printf("circumstance_description_convertToJSON() failed");
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

	circumstance_description_free(dst);
	dst = circumstance_description_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
