#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_in_area_filter.h"

ue_in_area_filter_t *ue_in_area_filter_create(ue_type_t *ue_type,
                                              bool	is_aerial_srv_dnn_ind,
                                              int	aerial_srv_dnn_ind,
                                              bool	is_ue_id_omit_ind,
                                              int	ue_id_omit_ind) {
	ue_in_area_filter_t *ue_in_area_filter_local_var =
		malloc(sizeof(ue_in_area_filter_t));

	ue_in_area_filter_local_var->ue_type = ue_type;
	ue_in_area_filter_local_var->is_aerial_srv_dnn_ind =
		is_aerial_srv_dnn_ind;
	ue_in_area_filter_local_var->aerial_srv_dnn_ind = aerial_srv_dnn_ind;
	ue_in_area_filter_local_var->is_ue_id_omit_ind = is_ue_id_omit_ind;
	ue_in_area_filter_local_var->ue_id_omit_ind = ue_id_omit_ind;

	return ue_in_area_filter_local_var;
}

void ue_in_area_filter_free(ue_in_area_filter_t *ue_in_area_filter) {
	lnode_t *node = NULL;

	if(NULL == ue_in_area_filter) {
		return;
	}
	if(ue_in_area_filter->ue_type) {
		ue_type_free(ue_in_area_filter->ue_type);
		ue_in_area_filter->ue_type = NULL;
	}
	free(ue_in_area_filter);
}

cJSON *ue_in_area_filter_convertToJSON(ue_in_area_filter_t *ue_in_area_filter) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_in_area_filter == NULL) {
		printf(
			"ue_in_area_filter_convertToJSON() failed [UeInAreaFilter]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_in_area_filter->ue_type) {
		cJSON *ue_type_local_JSON = ue_type_convertToJSON(
			ue_in_area_filter->ue_type);
		if(ue_type_local_JSON == NULL) {
			printf(
				"ue_in_area_filter_convertToJSON() failed [ue_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueType", ue_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_in_area_filter_convertToJSON() failed [ue_type]");
			goto end;
		}
	}

	if(ue_in_area_filter->is_aerial_srv_dnn_ind) {
		if(cJSON_AddBoolToObject(item, "aerialSrvDnnInd",
		                         ue_in_area_filter->aerial_srv_dnn_ind)
		   == NULL)
		{
			printf(
				"ue_in_area_filter_convertToJSON() failed [aerial_srv_dnn_ind]");
			goto end;
		}
	}

	if(ue_in_area_filter->is_ue_id_omit_ind) {
		if(cJSON_AddBoolToObject(item, "ueIdOmitInd",
		                         ue_in_area_filter->ue_id_omit_ind) ==
		   NULL)
		{
			printf(
				"ue_in_area_filter_convertToJSON() failed [ue_id_omit_ind]");
			goto end;
		}
	}

end:
	return item;
}

ue_in_area_filter_t *ue_in_area_filter_parseFromJSON(
	cJSON *ue_in_area_filterJSON) {
	ue_in_area_filter_t *ue_in_area_filter_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ue_type = NULL;
	ue_type_t *ue_type_local_nonprim = NULL;
	cJSON *aerial_srv_dnn_ind = NULL;
	cJSON *ue_id_omit_ind = NULL;
	ue_type = cJSON_GetObjectItemCaseSensitive(ue_in_area_filterJSON,
	                                           "ueType");
	if(ue_type) {
		ue_type_local_nonprim = ue_type_parseFromJSON(ue_type);
		if(!ue_type_local_nonprim) {
			printf("ue_type_parseFromJSON failed [ue_type]");
			goto end;
		}
	}

	aerial_srv_dnn_ind = cJSON_GetObjectItemCaseSensitive(
		ue_in_area_filterJSON, "aerialSrvDnnInd");
	if(aerial_srv_dnn_ind) {
		if(!cJSON_IsBool(aerial_srv_dnn_ind)) {
			printf(
				"ue_in_area_filter_parseFromJSON() failed [aerial_srv_dnn_ind]");
			goto end;
		}
	}

	ue_id_omit_ind = cJSON_GetObjectItemCaseSensitive(ue_in_area_filterJSON,
	                                                  "ueIdOmitInd");
	if(ue_id_omit_ind) {
		if(!cJSON_IsBool(ue_id_omit_ind)) {
			printf(
				"ue_in_area_filter_parseFromJSON() failed [ue_id_omit_ind]");
			goto end;
		}
	}

	ue_in_area_filter_local_var = ue_in_area_filter_create(
		ue_type ? ue_type_local_nonprim : NULL,
		aerial_srv_dnn_ind ? true : false,
		aerial_srv_dnn_ind ? aerial_srv_dnn_ind->valueint : 0,
		ue_id_omit_ind ? true : false,
		ue_id_omit_ind ? ue_id_omit_ind->valueint : 0
		);

	return ue_in_area_filter_local_var;
end:
	if(ue_type_local_nonprim) {
		ue_type_free(ue_type_local_nonprim);
		ue_type_local_nonprim = NULL;
	}
	return NULL;
}

ue_in_area_filter_t *ue_in_area_filter_copy(ue_in_area_filter_t *dst,
                                            ue_in_area_filter_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_in_area_filter_convertToJSON(src);
	if(!item) {
		printf("ue_in_area_filter_convertToJSON() failed");
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

	ue_in_area_filter_free(dst);
	dst = ue_in_area_filter_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
