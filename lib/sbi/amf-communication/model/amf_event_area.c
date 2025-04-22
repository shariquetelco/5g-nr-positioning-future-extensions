#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "amf_event_area.h"

amf_event_area_t *amf_event_area_create(presence_info_t *presence_info,
                                        ladn_info_t *ladn_info,
                                        snssai_t *s_nssai, char *nsi_id) {
	amf_event_area_t *amf_event_area_local_var =
		malloc(sizeof(amf_event_area_t));

	amf_event_area_local_var->presence_info = presence_info;
	amf_event_area_local_var->ladn_info = ladn_info;
	amf_event_area_local_var->s_nssai = s_nssai;
	amf_event_area_local_var->nsi_id = nsi_id;

	return amf_event_area_local_var;
}

void amf_event_area_free(amf_event_area_t *amf_event_area) {
	lnode_t *node = NULL;

	if(NULL == amf_event_area) {
		return;
	}
	if(amf_event_area->presence_info) {
		presence_info_free(amf_event_area->presence_info);
		amf_event_area->presence_info = NULL;
	}
	if(amf_event_area->ladn_info) {
		ladn_info_free(amf_event_area->ladn_info);
		amf_event_area->ladn_info = NULL;
	}
	if(amf_event_area->s_nssai) {
		snssai_free(amf_event_area->s_nssai);
		amf_event_area->s_nssai = NULL;
	}
	if(amf_event_area->nsi_id) {
		free(amf_event_area->nsi_id);
		amf_event_area->nsi_id = NULL;
	}
	free(amf_event_area);
}

cJSON *amf_event_area_convertToJSON(amf_event_area_t *amf_event_area) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(amf_event_area == NULL) {
		printf("amf_event_area_convertToJSON() failed [AmfEventArea]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(amf_event_area->presence_info) {
		cJSON *presence_info_local_JSON = presence_info_convertToJSON(
			amf_event_area->presence_info);
		if(presence_info_local_JSON == NULL) {
			printf(
				"amf_event_area_convertToJSON() failed [presence_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "presenceInfo",
		                      presence_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_area_convertToJSON() failed [presence_info]");
			goto end;
		}
	}

	if(amf_event_area->ladn_info) {
		cJSON *ladn_info_local_JSON = ladn_info_convertToJSON(
			amf_event_area->ladn_info);
		if(ladn_info_local_JSON == NULL) {
			printf(
				"amf_event_area_convertToJSON() failed [ladn_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ladnInfo", ladn_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_area_convertToJSON() failed [ladn_info]");
			goto end;
		}
	}

	if(amf_event_area->s_nssai) {
		cJSON *s_nssai_local_JSON = snssai_convertToJSON(
			amf_event_area->s_nssai);
		if(s_nssai_local_JSON == NULL) {
			printf("amf_event_area_convertToJSON() failed [s_nssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "sNssai", s_nssai_local_JSON);
		if(item->child == NULL) {
			printf("amf_event_area_convertToJSON() failed [s_nssai]");
			goto end;
		}
	}

	if(amf_event_area->nsi_id) {
		if(cJSON_AddStringToObject(item, "nsiId",
		                           amf_event_area->nsi_id) == NULL)
		{
			printf("amf_event_area_convertToJSON() failed [nsi_id]");
			goto end;
		}
	}

end:
	return item;
}

amf_event_area_t *amf_event_area_parseFromJSON(cJSON *amf_event_areaJSON) {
	amf_event_area_t *amf_event_area_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *presence_info = NULL;
	presence_info_t *presence_info_local_nonprim = NULL;
	cJSON *ladn_info = NULL;
	ladn_info_t *ladn_info_local_nonprim = NULL;
	cJSON *s_nssai = NULL;
	snssai_t *s_nssai_local_nonprim = NULL;
	cJSON *nsi_id = NULL;
	presence_info = cJSON_GetObjectItemCaseSensitive(amf_event_areaJSON,
	                                                 "presenceInfo");
	if(presence_info) {
		presence_info_local_nonprim = presence_info_parseFromJSON(
			presence_info);
		if(!presence_info_local_nonprim) {
			printf(
				"presence_info_parseFromJSON failed [presence_info]");
			goto end;
		}
	}

	ladn_info = cJSON_GetObjectItemCaseSensitive(amf_event_areaJSON,
	                                             "ladnInfo");
	if(ladn_info) {
		ladn_info_local_nonprim = ladn_info_parseFromJSON(ladn_info);
		if(!ladn_info_local_nonprim) {
			printf("ladn_info_parseFromJSON failed [ladn_info]");
			goto end;
		}
	}

	s_nssai =
		cJSON_GetObjectItemCaseSensitive(amf_event_areaJSON, "sNssai");
	if(s_nssai) {
		s_nssai_local_nonprim = snssai_parseFromJSON(s_nssai);
		if(!s_nssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [s_nssai]");
			goto end;
		}
	}

	nsi_id = cJSON_GetObjectItemCaseSensitive(amf_event_areaJSON, "nsiId");
	if(nsi_id) {
		if(!cJSON_IsString(nsi_id) &&
		   !cJSON_IsNull(nsi_id))
		{
			printf("amf_event_area_parseFromJSON() failed [nsi_id]");
			goto end;
		}
	}

	amf_event_area_local_var = amf_event_area_create(
		presence_info ? presence_info_local_nonprim : NULL,
		ladn_info ? ladn_info_local_nonprim : NULL,
		s_nssai ? s_nssai_local_nonprim : NULL,
		nsi_id &&
		!cJSON_IsNull(nsi_id) ? strdup(nsi_id->valuestring) : NULL
		);

	return amf_event_area_local_var;
end:
	if(presence_info_local_nonprim) {
		presence_info_free(presence_info_local_nonprim);
		presence_info_local_nonprim = NULL;
	}
	if(ladn_info_local_nonprim) {
		ladn_info_free(ladn_info_local_nonprim);
		ladn_info_local_nonprim = NULL;
	}
	if(s_nssai_local_nonprim) {
		snssai_free(s_nssai_local_nonprim);
		s_nssai_local_nonprim = NULL;
	}
	return NULL;
}

amf_event_area_t *amf_event_area_copy(amf_event_area_t	*dst,
                                      amf_event_area_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = amf_event_area_convertToJSON(src);
	if(!item) {
		printf("amf_event_area_convertToJSON() failed");
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

	amf_event_area_free(dst);
	dst = amf_event_area_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
