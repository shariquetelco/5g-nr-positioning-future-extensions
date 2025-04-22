#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "redundant_transmission_exp_info.h"

redundant_transmission_exp_info_t *redundant_transmission_exp_info_create(
	network_area_info_t *spatial_valid_con, char *dnn,
	list_t *red_trans_exps) {
	redundant_transmission_exp_info_t *
	        redundant_transmission_exp_info_local_var =
		malloc(sizeof(redundant_transmission_exp_info_t));

	redundant_transmission_exp_info_local_var->spatial_valid_con =
		spatial_valid_con;
	redundant_transmission_exp_info_local_var->dnn = dnn;
	redundant_transmission_exp_info_local_var->red_trans_exps =
		red_trans_exps;

	return redundant_transmission_exp_info_local_var;
}

void redundant_transmission_exp_info_free(
	redundant_transmission_exp_info_t *redundant_transmission_exp_info) {
	lnode_t *node = NULL;

	if(NULL == redundant_transmission_exp_info) {
		return;
	}
	if(redundant_transmission_exp_info->spatial_valid_con) {
		network_area_info_free(
			redundant_transmission_exp_info->spatial_valid_con);
		redundant_transmission_exp_info->spatial_valid_con = NULL;
	}
	if(redundant_transmission_exp_info->dnn) {
		free(redundant_transmission_exp_info->dnn);
		redundant_transmission_exp_info->dnn = NULL;
	}
	if(redundant_transmission_exp_info->red_trans_exps) {
		list_for_each(redundant_transmission_exp_info->red_trans_exps,
		              node) {
			redundant_transmission_exp_per_ts_free(node->data);
		}
		list_free(redundant_transmission_exp_info->red_trans_exps);
		redundant_transmission_exp_info->red_trans_exps = NULL;
	}
	free(redundant_transmission_exp_info);
}

cJSON *redundant_transmission_exp_info_convertToJSON(
	redundant_transmission_exp_info_t *redundant_transmission_exp_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(redundant_transmission_exp_info == NULL) {
		printf(
			"redundant_transmission_exp_info_convertToJSON() failed [RedundantTransmissionExpInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(redundant_transmission_exp_info->spatial_valid_con) {
		cJSON *spatial_valid_con_local_JSON =
			network_area_info_convertToJSON(
				redundant_transmission_exp_info->spatial_valid_con);
		if(spatial_valid_con_local_JSON == NULL) {
			printf(
				"redundant_transmission_exp_info_convertToJSON() failed [spatial_valid_con]");
			goto end;
		}
		cJSON_AddItemToObject(item, "spatialValidCon",
		                      spatial_valid_con_local_JSON);
		if(item->child == NULL) {
			printf(
				"redundant_transmission_exp_info_convertToJSON() failed [spatial_valid_con]");
			goto end;
		}
	}

	if(redundant_transmission_exp_info->dnn) {
		if(cJSON_AddStringToObject(item, "dnn",
		                           redundant_transmission_exp_info->dnn)
		   == NULL)
		{
			printf(
				"redundant_transmission_exp_info_convertToJSON() failed [dnn]");
			goto end;
		}
	}

	if(!redundant_transmission_exp_info->red_trans_exps) {
		printf(
			"redundant_transmission_exp_info_convertToJSON() failed [red_trans_exps]");
		return NULL;
	}
	cJSON *red_trans_expsList =
		cJSON_AddArrayToObject(item, "redTransExps");
	if(red_trans_expsList == NULL) {
		printf(
			"redundant_transmission_exp_info_convertToJSON() failed [red_trans_exps]");
		goto end;
	}
	list_for_each(redundant_transmission_exp_info->red_trans_exps, node) {
		cJSON *itemLocal =
			redundant_transmission_exp_per_ts_convertToJSON(
				node->data);
		if(itemLocal == NULL) {
			printf(
				"redundant_transmission_exp_info_convertToJSON() failed [red_trans_exps]");
			goto end;
		}
		cJSON_AddItemToArray(red_trans_expsList, itemLocal);
	}

end:
	return item;
}

redundant_transmission_exp_info_t *redundant_transmission_exp_info_parseFromJSON(
	cJSON *redundant_transmission_exp_infoJSON) {
	redundant_transmission_exp_info_t *
	        redundant_transmission_exp_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *spatial_valid_con = NULL;
	network_area_info_t *spatial_valid_con_local_nonprim = NULL;
	cJSON *dnn = NULL;
	cJSON *red_trans_exps = NULL;
	list_t *red_trans_expsList = NULL;
	spatial_valid_con = cJSON_GetObjectItemCaseSensitive(
		redundant_transmission_exp_infoJSON, "spatialValidCon");
	if(spatial_valid_con) {
		spatial_valid_con_local_nonprim =
			network_area_info_parseFromJSON(spatial_valid_con);
		if(!spatial_valid_con_local_nonprim) {
			printf(
				"network_area_info_parseFromJSON failed [spatial_valid_con]");
			goto end;
		}
	}

	dnn = cJSON_GetObjectItemCaseSensitive(
		redundant_transmission_exp_infoJSON, "dnn");
	if(dnn) {
		if(!cJSON_IsString(dnn) &&
		   !cJSON_IsNull(dnn))
		{
			printf(
				"redundant_transmission_exp_info_parseFromJSON() failed [dnn]");
			goto end;
		}
	}

	red_trans_exps = cJSON_GetObjectItemCaseSensitive(
		redundant_transmission_exp_infoJSON, "redTransExps");
	if(!red_trans_exps) {
		printf(
			"redundant_transmission_exp_info_parseFromJSON() failed [red_trans_exps]");
		goto end;
	}
	cJSON *red_trans_exps_local = NULL;
	if(!cJSON_IsArray(red_trans_exps)) {
		printf(
			"redundant_transmission_exp_info_parseFromJSON() failed [red_trans_exps]");
		goto end;
	}

	red_trans_expsList = list_create();

	cJSON_ArrayForEach(red_trans_exps_local, red_trans_exps) {
		if(!cJSON_IsObject(red_trans_exps_local)) {
			printf(
				"redundant_transmission_exp_info_parseFromJSON() failed [red_trans_exps]");
			goto end;
		}
		redundant_transmission_exp_per_ts_t *red_trans_expsItem =
			redundant_transmission_exp_per_ts_parseFromJSON(
				red_trans_exps_local);
		if(!red_trans_expsItem) {
			printf("No red_trans_expsItem");
			goto end;
		}
		list_add(red_trans_expsList, red_trans_expsItem);
	}

	redundant_transmission_exp_info_local_var =
		redundant_transmission_exp_info_create(
			spatial_valid_con ? spatial_valid_con_local_nonprim : NULL,
			dnn &&
			!cJSON_IsNull(dnn) ? strdup(dnn->valuestring) : NULL,
			red_trans_expsList
			);

	return redundant_transmission_exp_info_local_var;
end:
	if(spatial_valid_con_local_nonprim) {
		network_area_info_free(spatial_valid_con_local_nonprim);
		spatial_valid_con_local_nonprim = NULL;
	}
	if(red_trans_expsList) {
		list_for_each(red_trans_expsList, node) {
			redundant_transmission_exp_per_ts_free(node->data);
		}
		list_free(red_trans_expsList);
		red_trans_expsList = NULL;
	}
	return NULL;
}

redundant_transmission_exp_info_t *redundant_transmission_exp_info_copy(
	redundant_transmission_exp_info_t	*dst,
	redundant_transmission_exp_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = redundant_transmission_exp_info_convertToJSON(src);
	if(!item) {
		printf("redundant_transmission_exp_info_convertToJSON() failed");
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

	redundant_transmission_exp_info_free(dst);
	dst = redundant_transmission_exp_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
