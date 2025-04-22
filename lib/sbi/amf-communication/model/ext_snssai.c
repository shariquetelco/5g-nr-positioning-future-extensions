#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ext_snssai.h"

char *wildcard_sdext_snssai_ToString(ext_snssai_wildcard_sd_e wildcard_sd) {
	const char *wildcard_sdArray[] = { "NULL", "true" };
	size_t sizeofArray = sizeof(wildcard_sdArray) /
	                     sizeof(wildcard_sdArray[0]);
	if(wildcard_sd < sizeofArray) {
		return (char *) wildcard_sdArray[wildcard_sd];
	} else {
		return (char *) "Unknown";
	}
}

ext_snssai_wildcard_sd_e wildcard_sdext_snssai_FromString(char *wildcard_sd) {
	int stringToReturn = 0;
	const char *wildcard_sdArray[] = { "NULL", "true" };
	size_t sizeofArray = sizeof(wildcard_sdArray) /
	                     sizeof(wildcard_sdArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(wildcard_sd, wildcard_sdArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
ext_snssai_t *ext_snssai_create(int sst, char *sd, list_t *sd_ranges,
                                ext_snssai_wildcard_sd_e wildcard_sd) {
	ext_snssai_t *ext_snssai_local_var = malloc(sizeof(ext_snssai_t));

	ext_snssai_local_var->sst = sst;
	ext_snssai_local_var->sd = sd;
	ext_snssai_local_var->sd_ranges = sd_ranges;
	ext_snssai_local_var->wildcard_sd = wildcard_sd;

	return ext_snssai_local_var;
}

void ext_snssai_free(ext_snssai_t *ext_snssai) {
	lnode_t *node = NULL;

	if(NULL == ext_snssai) {
		return;
	}
	if(ext_snssai->sd) {
		free(ext_snssai->sd);
		ext_snssai->sd = NULL;
	}
	if(ext_snssai->sd_ranges) {
		list_for_each(ext_snssai->sd_ranges, node) {
			sd_range_free(node->data);
		}
		list_free(ext_snssai->sd_ranges);
		ext_snssai->sd_ranges = NULL;
	}
	free(ext_snssai);
}

cJSON *ext_snssai_convertToJSON(ext_snssai_t *ext_snssai) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ext_snssai == NULL) {
		printf("ext_snssai_convertToJSON() failed [ExtSnssai]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "sst", ext_snssai->sst) == NULL) {
		printf("ext_snssai_convertToJSON() failed [sst]");
		goto end;
	}

	if(ext_snssai->sd) {
		if(cJSON_AddStringToObject(item, "sd",
		                           ext_snssai->sd) == NULL)
		{
			printf("ext_snssai_convertToJSON() failed [sd]");
			goto end;
		}
	}

	if(ext_snssai->sd_ranges) {
		cJSON *sd_rangesList = cJSON_AddArrayToObject(item, "sdRanges");
		if(sd_rangesList == NULL) {
			printf("ext_snssai_convertToJSON() failed [sd_ranges]");
			goto end;
		}
		list_for_each(ext_snssai->sd_ranges, node) {
			cJSON *itemLocal = sd_range_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"ext_snssai_convertToJSON() failed [sd_ranges]");
				goto end;
			}
			cJSON_AddItemToArray(sd_rangesList, itemLocal);
		}
	}

	if(ext_snssai->wildcard_sd != ext_snssai_WILDCARDSD_NULL) {
		if(cJSON_AddStringToObject(item, "wildcardSd",
		                           wildcard_sdext_snssai_ToString(
						   ext_snssai->wildcard_sd)) ==
		   NULL)
		{
			printf("ext_snssai_convertToJSON() failed [wildcard_sd]");
			goto end;
		}
	}

end:
	return item;
}

ext_snssai_t *ext_snssai_parseFromJSON(cJSON *ext_snssaiJSON) {
	ext_snssai_t *ext_snssai_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *sst = NULL;
	cJSON *sd = NULL;
	cJSON *sd_ranges = NULL;
	list_t *sd_rangesList = NULL;
	cJSON *wildcard_sd = NULL;
	ext_snssai_wildcard_sd_e wildcard_sdVariable = 0;
	sst = cJSON_GetObjectItemCaseSensitive(ext_snssaiJSON, "sst");
	if(!sst) {
		printf("ext_snssai_parseFromJSON() failed [sst]");
		goto end;
	}
	if(!cJSON_IsNumber(sst)) {
		printf("ext_snssai_parseFromJSON() failed [sst]");
		goto end;
	}

	sd = cJSON_GetObjectItemCaseSensitive(ext_snssaiJSON, "sd");
	if(sd) {
		if(!cJSON_IsString(sd) &&
		   !cJSON_IsNull(sd))
		{
			printf("ext_snssai_parseFromJSON() failed [sd]");
			goto end;
		}
	}

	sd_ranges =
		cJSON_GetObjectItemCaseSensitive(ext_snssaiJSON, "sdRanges");
	if(sd_ranges) {
		cJSON *sd_ranges_local = NULL;
		if(!cJSON_IsArray(sd_ranges)) {
			printf("ext_snssai_parseFromJSON() failed [sd_ranges]");
			goto end;
		}

		sd_rangesList = list_create();

		cJSON_ArrayForEach(sd_ranges_local, sd_ranges) {
			if(!cJSON_IsObject(sd_ranges_local)) {
				printf(
					"ext_snssai_parseFromJSON() failed [sd_ranges]");
				goto end;
			}
			sd_range_t *sd_rangesItem = sd_range_parseFromJSON(
				sd_ranges_local);
			if(!sd_rangesItem) {
				printf("No sd_rangesItem");
				goto end;
			}
			list_add(sd_rangesList, sd_rangesItem);
		}
	}

	wildcard_sd = cJSON_GetObjectItemCaseSensitive(ext_snssaiJSON,
	                                               "wildcardSd");
	if(wildcard_sd) {
		if(!cJSON_IsString(wildcard_sd)) {
			printf("ext_snssai_parseFromJSON() failed [wildcard_sd]");
			goto end;
		}
		wildcard_sdVariable = wildcard_sdext_snssai_FromString(
			wildcard_sd->valuestring);
	}

	ext_snssai_local_var = ext_snssai_create(

		sst->valuedouble,
		sd &&
		!cJSON_IsNull(sd) ? strdup(sd->valuestring) : NULL,
		sd_ranges ? sd_rangesList : NULL,
		wildcard_sd ? wildcard_sdVariable : 0
		);

	return ext_snssai_local_var;
end:
	if(sd_rangesList) {
		list_for_each(sd_rangesList, node) {
			sd_range_free(node->data);
		}
		list_free(sd_rangesList);
		sd_rangesList = NULL;
	}
	return NULL;
}

ext_snssai_t *ext_snssai_copy(ext_snssai_t *dst, ext_snssai_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ext_snssai_convertToJSON(src);
	if(!item) {
		printf("ext_snssai_convertToJSON() failed");
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

	ext_snssai_free(dst);
	dst = ext_snssai_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
