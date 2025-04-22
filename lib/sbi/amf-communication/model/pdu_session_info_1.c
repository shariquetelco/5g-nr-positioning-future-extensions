#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pdu_session_info_1.h"

pdu_session_info_1_t *pdu_session_info_1_create(
	pdu_session_type_t *pdu_sess_type, ssc_mode_t *ssc_mode,
	list_t *access_types) {
	pdu_session_info_1_t *pdu_session_info_1_local_var =
		malloc(sizeof(pdu_session_info_1_t));

	pdu_session_info_1_local_var->pdu_sess_type = pdu_sess_type;
	pdu_session_info_1_local_var->ssc_mode = ssc_mode;
	pdu_session_info_1_local_var->access_types = access_types;

	return pdu_session_info_1_local_var;
}

void pdu_session_info_1_free(pdu_session_info_1_t *pdu_session_info_1) {
	lnode_t *node = NULL;

	if(NULL == pdu_session_info_1) {
		return;
	}
	if(pdu_session_info_1->pdu_sess_type) {
		pdu_session_type_free(pdu_session_info_1->pdu_sess_type);
		pdu_session_info_1->pdu_sess_type = NULL;
	}
	if(pdu_session_info_1->ssc_mode) {
		ssc_mode_free(pdu_session_info_1->ssc_mode);
		pdu_session_info_1->ssc_mode = NULL;
	}
	if(pdu_session_info_1->access_types) {
		list_free(pdu_session_info_1->access_types);
		pdu_session_info_1->access_types = NULL;
	}
	free(pdu_session_info_1);
}

cJSON *pdu_session_info_1_convertToJSON(
	pdu_session_info_1_t *pdu_session_info_1) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pdu_session_info_1 == NULL) {
		printf(
			"pdu_session_info_1_convertToJSON() failed [PduSessionInfo_1]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(pdu_session_info_1->pdu_sess_type) {
		cJSON *pdu_sess_type_local_JSON =
			pdu_session_type_convertToJSON(
				pdu_session_info_1->pdu_sess_type);
		if(pdu_sess_type_local_JSON == NULL) {
			printf(
				"pdu_session_info_1_convertToJSON() failed [pdu_sess_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "pduSessType",
		                      pdu_sess_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"pdu_session_info_1_convertToJSON() failed [pdu_sess_type]");
			goto end;
		}
	}

	if(pdu_session_info_1->ssc_mode) {
		cJSON *ssc_mode_local_JSON = ssc_mode_convertToJSON(
			pdu_session_info_1->ssc_mode);
		if(ssc_mode_local_JSON == NULL) {
			printf(
				"pdu_session_info_1_convertToJSON() failed [ssc_mode]");
			goto end;
		}
		cJSON_AddItemToObject(item, "sscMode", ssc_mode_local_JSON);
		if(item->child == NULL) {
			printf(
				"pdu_session_info_1_convertToJSON() failed [ssc_mode]");
			goto end;
		}
	}

	if(pdu_session_info_1->access_types != access_type_NULL) {
		cJSON *access_typesList = cJSON_AddArrayToObject(item,
		                                                 "accessTypes");
		if(access_typesList == NULL) {
			printf(
				"pdu_session_info_1_convertToJSON() failed [access_types]");
			goto end;
		}
		list_for_each(pdu_session_info_1->access_types, node) {
			if(cJSON_AddStringToObject(access_typesList, "",
			                           access_type_ToString((
										intptr_t)
			                                                node->
			                                                data))
			   == NULL)
			{
				printf(
					"pdu_session_info_1_convertToJSON() failed [access_types]");
				goto end;
			}
		}
	}

end:
	return item;
}

pdu_session_info_1_t *pdu_session_info_1_parseFromJSON(
	cJSON *pdu_session_info_1JSON) {
	pdu_session_info_1_t *pdu_session_info_1_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pdu_sess_type = NULL;
	pdu_session_type_t *pdu_sess_type_local_nonprim = NULL;
	cJSON *ssc_mode = NULL;
	ssc_mode_t *ssc_mode_local_nonprim = NULL;
	cJSON *access_types = NULL;
	list_t *access_typesList = NULL;
	pdu_sess_type = cJSON_GetObjectItemCaseSensitive(pdu_session_info_1JSON,
	                                                 "pduSessType");
	if(pdu_sess_type) {
		pdu_sess_type_local_nonprim = pdu_session_type_parseFromJSON(
			pdu_sess_type);
		if(!pdu_sess_type_local_nonprim) {
			printf(
				"pdu_session_type_parseFromJSON failed [pdu_sess_type]");
			goto end;
		}
	}

	ssc_mode = cJSON_GetObjectItemCaseSensitive(pdu_session_info_1JSON,
	                                            "sscMode");
	if(ssc_mode) {
		ssc_mode_local_nonprim = ssc_mode_parseFromJSON(ssc_mode);
		if(!ssc_mode_local_nonprim) {
			printf("ssc_mode_parseFromJSON failed [ssc_mode]");
			goto end;
		}
	}

	access_types = cJSON_GetObjectItemCaseSensitive(pdu_session_info_1JSON,
	                                                "accessTypes");
	if(access_types) {
		cJSON *access_types_local = NULL;
		if(!cJSON_IsArray(access_types)) {
			printf(
				"pdu_session_info_1_parseFromJSON() failed [access_types]");
			goto end;
		}

		access_typesList = list_create();

		cJSON_ArrayForEach(access_types_local, access_types) {
			access_type_e localEnum = access_type_NULL;
			if(!cJSON_IsString(access_types_local)) {
				printf(
					"pdu_session_info_1_parseFromJSON() failed [access_types]");
				goto end;
			}
			localEnum = access_type_FromString(
				access_types_local->valuestring);
			if(!localEnum) {
				printf(
					"Enum value \"%s\" for field \"access_types\" is not supported. Ignoring it ...",
					access_types_local->valuestring);
			} else {
				list_add(access_typesList, (void *) localEnum);
			}
		}
		if(access_typesList->count == 0) {
			printf(
				"pdu_session_info_1_parseFromJSON() failed: Expected access_typesList to not be empty (after ignoring unsupported enum values).");
			goto end;
		}
	}

	pdu_session_info_1_local_var = pdu_session_info_1_create(
		pdu_sess_type ? pdu_sess_type_local_nonprim : NULL,
		ssc_mode ? ssc_mode_local_nonprim : NULL,
		access_types ? access_typesList : NULL
		);

	return pdu_session_info_1_local_var;
end:
	if(pdu_sess_type_local_nonprim) {
		pdu_session_type_free(pdu_sess_type_local_nonprim);
		pdu_sess_type_local_nonprim = NULL;
	}
	if(ssc_mode_local_nonprim) {
		ssc_mode_free(ssc_mode_local_nonprim);
		ssc_mode_local_nonprim = NULL;
	}
	if(access_typesList) {
		list_free(access_typesList);
		access_typesList = NULL;
	}
	return NULL;
}

pdu_session_info_1_t *pdu_session_info_1_copy(pdu_session_info_1_t	*dst,
                                              pdu_session_info_1_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pdu_session_info_1_convertToJSON(src);
	if(!item) {
		printf("pdu_session_info_1_convertToJSON() failed");
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

	pdu_session_info_1_free(dst);
	dst = pdu_session_info_1_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
