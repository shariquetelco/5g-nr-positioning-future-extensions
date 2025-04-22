#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_area.h"

reporting_area_t *reporting_area_create(reporting_area_type_e area_type,
                                        tai_t *tai, ecgi_t *ecgi,
                                        ncgi_t *ncgi) {
	reporting_area_t *reporting_area_local_var =
		malloc(sizeof(reporting_area_t));

	reporting_area_local_var->area_type = area_type;
	reporting_area_local_var->tai = tai;
	reporting_area_local_var->ecgi = ecgi;
	reporting_area_local_var->ncgi = ncgi;

	return reporting_area_local_var;
}

void reporting_area_free(reporting_area_t *reporting_area) {
	lnode_t *node = NULL;

	if(NULL == reporting_area) {
		return;
	}
	if(reporting_area->tai) {
		tai_free(reporting_area->tai);
		reporting_area->tai = NULL;
	}
	if(reporting_area->ecgi) {
		ecgi_free(reporting_area->ecgi);
		reporting_area->ecgi = NULL;
	}
	if(reporting_area->ncgi) {
		ncgi_free(reporting_area->ncgi);
		reporting_area->ncgi = NULL;
	}
	free(reporting_area);
}

cJSON *reporting_area_convertToJSON(reporting_area_t *reporting_area) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(reporting_area == NULL) {
		printf("reporting_area_convertToJSON() failed [ReportingArea]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(reporting_area->area_type == reporting_area_type_NULL) {
		printf("reporting_area_convertToJSON() failed [area_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "areaType",
	                           reporting_area_type_ToString(reporting_area->
	                                                        area_type)) ==
	   NULL)
	{
		printf("reporting_area_convertToJSON() failed [area_type]");
		goto end;
	}

	if(reporting_area->tai) {
		cJSON *tai_local_JSON = tai_convertToJSON(reporting_area->tai);
		if(tai_local_JSON == NULL) {
			printf("reporting_area_convertToJSON() failed [tai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "tai", tai_local_JSON);
		if(item->child == NULL) {
			printf("reporting_area_convertToJSON() failed [tai]");
			goto end;
		}
	}

	if(reporting_area->ecgi) {
		cJSON *ecgi_local_JSON =
			ecgi_convertToJSON(reporting_area->ecgi);
		if(ecgi_local_JSON == NULL) {
			printf("reporting_area_convertToJSON() failed [ecgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
		if(item->child == NULL) {
			printf("reporting_area_convertToJSON() failed [ecgi]");
			goto end;
		}
	}

	if(reporting_area->ncgi) {
		cJSON *ncgi_local_JSON =
			ncgi_convertToJSON(reporting_area->ncgi);
		if(ncgi_local_JSON == NULL) {
			printf("reporting_area_convertToJSON() failed [ncgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
		if(item->child == NULL) {
			printf("reporting_area_convertToJSON() failed [ncgi]");
			goto end;
		}
	}

end:
	return item;
}

reporting_area_t *reporting_area_parseFromJSON(cJSON *reporting_areaJSON) {
	reporting_area_t *reporting_area_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *area_type = NULL;
	reporting_area_type_e area_typeVariable = 0;
	cJSON *tai = NULL;
	tai_t *tai_local_nonprim = NULL;
	cJSON *ecgi = NULL;
	ecgi_t *ecgi_local_nonprim = NULL;
	cJSON *ncgi = NULL;
	ncgi_t *ncgi_local_nonprim = NULL;
	area_type = cJSON_GetObjectItemCaseSensitive(reporting_areaJSON,
	                                             "areaType");
	if(!area_type) {
		printf("reporting_area_parseFromJSON() failed [area_type]");
		goto end;
	}
	if(!cJSON_IsString(area_type)) {
		printf("reporting_area_parseFromJSON() failed [area_type]");
		goto end;
	}
	area_typeVariable = reporting_area_type_FromString(
		area_type->valuestring);

	tai = cJSON_GetObjectItemCaseSensitive(reporting_areaJSON, "tai");
	if(tai) {
		tai_local_nonprim = tai_parseFromJSON(tai);
		if(!tai_local_nonprim) {
			printf("tai_parseFromJSON failed [tai]");
			goto end;
		}
	}

	ecgi = cJSON_GetObjectItemCaseSensitive(reporting_areaJSON, "ecgi");
	if(ecgi) {
		ecgi_local_nonprim = ecgi_parseFromJSON(ecgi);
		if(!ecgi_local_nonprim) {
			printf("ecgi_parseFromJSON failed [ecgi]");
			goto end;
		}
	}

	ncgi = cJSON_GetObjectItemCaseSensitive(reporting_areaJSON, "ncgi");
	if(ncgi) {
		ncgi_local_nonprim = ncgi_parseFromJSON(ncgi);
		if(!ncgi_local_nonprim) {
			printf("ncgi_parseFromJSON failed [ncgi]");
			goto end;
		}
	}

	reporting_area_local_var = reporting_area_create(
		area_typeVariable,
		tai ? tai_local_nonprim : NULL,
		ecgi ? ecgi_local_nonprim : NULL,
		ncgi ? ncgi_local_nonprim : NULL
		);

	return reporting_area_local_var;
end:
	if(tai_local_nonprim) {
		tai_free(tai_local_nonprim);
		tai_local_nonprim = NULL;
	}
	if(ecgi_local_nonprim) {
		ecgi_free(ecgi_local_nonprim);
		ecgi_local_nonprim = NULL;
	}
	if(ncgi_local_nonprim) {
		ncgi_free(ncgi_local_nonprim);
		ncgi_local_nonprim = NULL;
	}
	return NULL;
}

reporting_area_t *reporting_area_copy(reporting_area_t	*dst,
                                      reporting_area_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = reporting_area_convertToJSON(src);
	if(!item) {
		printf("reporting_area_convertToJSON() failed");
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

	reporting_area_free(dst);
	dst = reporting_area_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
