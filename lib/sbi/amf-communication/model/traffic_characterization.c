#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "traffic_characterization.h"

traffic_characterization_t *traffic_characterization_create(char *dnn,
                                                            snssai_t *snssai,
                                                            char *app_id,
                                                            list_t *f_descs,
                                                            bool is_ul_vol,
                                                            long ul_vol,
                                                            bool is_ul_vol_variance, float ul_vol_variance, bool is_dl_vol, long dl_vol, bool is_dl_vol_variance,
                                                            float dl_vol_variance)
{
	traffic_characterization_t *traffic_characterization_local_var = malloc(
		sizeof(traffic_characterization_t));

	traffic_characterization_local_var->dnn = dnn;
	traffic_characterization_local_var->snssai = snssai;
	traffic_characterization_local_var->app_id = app_id;
	traffic_characterization_local_var->f_descs = f_descs;
	traffic_characterization_local_var->is_ul_vol = is_ul_vol;
	traffic_characterization_local_var->ul_vol = ul_vol;
	traffic_characterization_local_var->is_ul_vol_variance =
		is_ul_vol_variance;
	traffic_characterization_local_var->ul_vol_variance = ul_vol_variance;
	traffic_characterization_local_var->is_dl_vol = is_dl_vol;
	traffic_characterization_local_var->dl_vol = dl_vol;
	traffic_characterization_local_var->is_dl_vol_variance =
		is_dl_vol_variance;
	traffic_characterization_local_var->dl_vol_variance = dl_vol_variance;

	return traffic_characterization_local_var;
}

void traffic_characterization_free(
	traffic_characterization_t *traffic_characterization) {
	lnode_t *node = NULL;

	if(NULL == traffic_characterization) {
		return;
	}
	if(traffic_characterization->dnn) {
		free(traffic_characterization->dnn);
		traffic_characterization->dnn = NULL;
	}
	if(traffic_characterization->snssai) {
		snssai_free(traffic_characterization->snssai);
		traffic_characterization->snssai = NULL;
	}
	if(traffic_characterization->app_id) {
		free(traffic_characterization->app_id);
		traffic_characterization->app_id = NULL;
	}
	if(traffic_characterization->f_descs) {
		list_for_each(traffic_characterization->f_descs, node) {
			ip_eth_flow_description_free(node->data);
		}
		list_free(traffic_characterization->f_descs);
		traffic_characterization->f_descs = NULL;
	}
	free(traffic_characterization);
}

cJSON *traffic_characterization_convertToJSON(
	traffic_characterization_t *traffic_characterization) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(traffic_characterization == NULL) {
		printf(
			"traffic_characterization_convertToJSON() failed [TrafficCharacterization]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(traffic_characterization->dnn) {
		if(cJSON_AddStringToObject(item, "dnn",
		                           traffic_characterization->dnn) ==
		   NULL)
		{
			printf(
				"traffic_characterization_convertToJSON() failed [dnn]");
			goto end;
		}
	}

	if(traffic_characterization->snssai) {
		cJSON *snssai_local_JSON = snssai_convertToJSON(
			traffic_characterization->snssai);
		if(snssai_local_JSON == NULL) {
			printf(
				"traffic_characterization_convertToJSON() failed [snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"traffic_characterization_convertToJSON() failed [snssai]");
			goto end;
		}
	}

	if(traffic_characterization->app_id) {
		if(cJSON_AddStringToObject(item, "appId",
		                           traffic_characterization->app_id) ==
		   NULL)
		{
			printf(
				"traffic_characterization_convertToJSON() failed [app_id]");
			goto end;
		}
	}

	if(traffic_characterization->f_descs) {
		cJSON *f_descsList = cJSON_AddArrayToObject(item, "fDescs");
		if(f_descsList == NULL) {
			printf(
				"traffic_characterization_convertToJSON() failed [f_descs]");
			goto end;
		}
		list_for_each(traffic_characterization->f_descs, node) {
			cJSON *itemLocal =
				ip_eth_flow_description_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"traffic_characterization_convertToJSON() failed [f_descs]");
				goto end;
			}
			cJSON_AddItemToArray(f_descsList, itemLocal);
		}
	}

	if(traffic_characterization->is_ul_vol) {
		if(cJSON_AddNumberToObject(item, "ulVol",
		                           traffic_characterization->ul_vol) ==
		   NULL)
		{
			printf(
				"traffic_characterization_convertToJSON() failed [ul_vol]");
			goto end;
		}
	}

	if(traffic_characterization->is_ul_vol_variance) {
		if(cJSON_AddNumberToObject(item, "ulVolVariance",
		                           traffic_characterization->
		                           ul_vol_variance) == NULL)
		{
			printf(
				"traffic_characterization_convertToJSON() failed [ul_vol_variance]");
			goto end;
		}
	}

	if(traffic_characterization->is_dl_vol) {
		if(cJSON_AddNumberToObject(item, "dlVol",
		                           traffic_characterization->dl_vol) ==
		   NULL)
		{
			printf(
				"traffic_characterization_convertToJSON() failed [dl_vol]");
			goto end;
		}
	}

	if(traffic_characterization->is_dl_vol_variance) {
		if(cJSON_AddNumberToObject(item, "dlVolVariance",
		                           traffic_characterization->
		                           dl_vol_variance) == NULL)
		{
			printf(
				"traffic_characterization_convertToJSON() failed [dl_vol_variance]");
			goto end;
		}
	}

end:
	return item;
}

traffic_characterization_t *traffic_characterization_parseFromJSON(
	cJSON *traffic_characterizationJSON) {
	traffic_characterization_t *traffic_characterization_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *dnn = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *app_id = NULL;
	cJSON *f_descs = NULL;
	list_t *f_descsList = NULL;
	cJSON *ul_vol = NULL;
	cJSON *ul_vol_variance = NULL;
	cJSON *dl_vol = NULL;
	cJSON *dl_vol_variance = NULL;
	dnn = cJSON_GetObjectItemCaseSensitive(traffic_characterizationJSON,
	                                       "dnn");
	if(dnn) {
		if(!cJSON_IsString(dnn) &&
		   !cJSON_IsNull(dnn))
		{
			printf(
				"traffic_characterization_parseFromJSON() failed [dnn]");
			goto end;
		}
	}

	snssai = cJSON_GetObjectItemCaseSensitive(traffic_characterizationJSON,
	                                          "snssai");
	if(snssai) {
		snssai_local_nonprim = snssai_parseFromJSON(snssai);
		if(!snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [snssai]");
			goto end;
		}
	}

	app_id = cJSON_GetObjectItemCaseSensitive(traffic_characterizationJSON,
	                                          "appId");
	if(app_id) {
		if(!cJSON_IsString(app_id) &&
		   !cJSON_IsNull(app_id))
		{
			printf(
				"traffic_characterization_parseFromJSON() failed [app_id]");
			goto end;
		}
	}

	f_descs = cJSON_GetObjectItemCaseSensitive(traffic_characterizationJSON,
	                                           "fDescs");
	if(f_descs) {
		cJSON *f_descs_local = NULL;
		if(!cJSON_IsArray(f_descs)) {
			printf(
				"traffic_characterization_parseFromJSON() failed [f_descs]");
			goto end;
		}

		f_descsList = list_create();

		cJSON_ArrayForEach(f_descs_local, f_descs) {
			if(!cJSON_IsObject(f_descs_local)) {
				printf(
					"traffic_characterization_parseFromJSON() failed [f_descs]");
				goto end;
			}
			ip_eth_flow_description_t *f_descsItem =
				ip_eth_flow_description_parseFromJSON(
					f_descs_local);
			if(!f_descsItem) {
				printf("No f_descsItem");
				goto end;
			}
			list_add(f_descsList, f_descsItem);
		}
	}

	ul_vol = cJSON_GetObjectItemCaseSensitive(traffic_characterizationJSON,
	                                          "ulVol");
	if(ul_vol) {
		if(!cJSON_IsNumber(ul_vol)) {
			printf(
				"traffic_characterization_parseFromJSON() failed [ul_vol]");
			goto end;
		}
	}

	ul_vol_variance = cJSON_GetObjectItemCaseSensitive(
		traffic_characterizationJSON, "ulVolVariance");
	if(ul_vol_variance) {
		if(!cJSON_IsNumber(ul_vol_variance)) {
			printf(
				"traffic_characterization_parseFromJSON() failed [ul_vol_variance]");
			goto end;
		}
	}

	dl_vol = cJSON_GetObjectItemCaseSensitive(traffic_characterizationJSON,
	                                          "dlVol");
	if(dl_vol) {
		if(!cJSON_IsNumber(dl_vol)) {
			printf(
				"traffic_characterization_parseFromJSON() failed [dl_vol]");
			goto end;
		}
	}

	dl_vol_variance = cJSON_GetObjectItemCaseSensitive(
		traffic_characterizationJSON, "dlVolVariance");
	if(dl_vol_variance) {
		if(!cJSON_IsNumber(dl_vol_variance)) {
			printf(
				"traffic_characterization_parseFromJSON() failed [dl_vol_variance]");
			goto end;
		}
	}

	traffic_characterization_local_var = traffic_characterization_create(
		dnn &&
		!cJSON_IsNull(dnn) ? strdup(dnn->valuestring) : NULL,
		snssai ? snssai_local_nonprim : NULL,
		app_id &&
		!cJSON_IsNull(app_id) ? strdup(app_id->valuestring) : NULL,
		f_descs ? f_descsList : NULL,
		ul_vol ? true : false,
		ul_vol ? ul_vol->valuedouble : 0,
		ul_vol_variance ? true : false,
		ul_vol_variance ? ul_vol_variance->valuedouble : 0,
		dl_vol ? true : false,
		dl_vol ? dl_vol->valuedouble : 0,
		dl_vol_variance ? true : false,
		dl_vol_variance ? dl_vol_variance->valuedouble : 0
		);

	return traffic_characterization_local_var;
end:
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(f_descsList) {
		list_for_each(f_descsList, node) {
			ip_eth_flow_description_free(node->data);
		}
		list_free(f_descsList);
		f_descsList = NULL;
	}
	return NULL;
}

traffic_characterization_t *traffic_characterization_copy(
	traffic_characterization_t *dst, traffic_characterization_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = traffic_characterization_convertToJSON(src);
	if(!item) {
		printf("traffic_characterization_convertToJSON() failed");
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

	traffic_characterization_free(dst);
	dst = traffic_characterization_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
