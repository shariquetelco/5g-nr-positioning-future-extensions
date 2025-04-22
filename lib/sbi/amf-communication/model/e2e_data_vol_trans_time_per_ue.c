#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "e2e_data_vol_trans_time_per_ue.h"

e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue_create(
	char *supi, char *gpsi, snssai_t *snssai, char *app_id,
	user_location_t *ue_loc, char *dnn,
	network_area_info_t *spatial_validity, time_window_t *validity_period,
	data_volume_transfer_time_t *data_vol_trans_time) {
	e2e_data_vol_trans_time_per_ue_t *
	        e2e_data_vol_trans_time_per_ue_local_var =
		malloc(sizeof(e2e_data_vol_trans_time_per_ue_t));

	e2e_data_vol_trans_time_per_ue_local_var->supi = supi;
	e2e_data_vol_trans_time_per_ue_local_var->gpsi = gpsi;
	e2e_data_vol_trans_time_per_ue_local_var->snssai = snssai;
	e2e_data_vol_trans_time_per_ue_local_var->app_id = app_id;
	e2e_data_vol_trans_time_per_ue_local_var->ue_loc = ue_loc;
	e2e_data_vol_trans_time_per_ue_local_var->dnn = dnn;
	e2e_data_vol_trans_time_per_ue_local_var->spatial_validity =
		spatial_validity;
	e2e_data_vol_trans_time_per_ue_local_var->validity_period =
		validity_period;
	e2e_data_vol_trans_time_per_ue_local_var->data_vol_trans_time =
		data_vol_trans_time;

	return e2e_data_vol_trans_time_per_ue_local_var;
}

void e2e_data_vol_trans_time_per_ue_free(
	e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue) {
	lnode_t *node = NULL;

	if(NULL == e2e_data_vol_trans_time_per_ue) {
		return;
	}
	if(e2e_data_vol_trans_time_per_ue->supi) {
		free(e2e_data_vol_trans_time_per_ue->supi);
		e2e_data_vol_trans_time_per_ue->supi = NULL;
	}
	if(e2e_data_vol_trans_time_per_ue->gpsi) {
		free(e2e_data_vol_trans_time_per_ue->gpsi);
		e2e_data_vol_trans_time_per_ue->gpsi = NULL;
	}
	if(e2e_data_vol_trans_time_per_ue->snssai) {
		snssai_free(e2e_data_vol_trans_time_per_ue->snssai);
		e2e_data_vol_trans_time_per_ue->snssai = NULL;
	}
	if(e2e_data_vol_trans_time_per_ue->app_id) {
		free(e2e_data_vol_trans_time_per_ue->app_id);
		e2e_data_vol_trans_time_per_ue->app_id = NULL;
	}
	if(e2e_data_vol_trans_time_per_ue->ue_loc) {
		user_location_free(e2e_data_vol_trans_time_per_ue->ue_loc);
		e2e_data_vol_trans_time_per_ue->ue_loc = NULL;
	}
	if(e2e_data_vol_trans_time_per_ue->dnn) {
		free(e2e_data_vol_trans_time_per_ue->dnn);
		e2e_data_vol_trans_time_per_ue->dnn = NULL;
	}
	if(e2e_data_vol_trans_time_per_ue->spatial_validity) {
		network_area_info_free(
			e2e_data_vol_trans_time_per_ue->spatial_validity);
		e2e_data_vol_trans_time_per_ue->spatial_validity = NULL;
	}
	if(e2e_data_vol_trans_time_per_ue->validity_period) {
		time_window_free(e2e_data_vol_trans_time_per_ue->validity_period);
		e2e_data_vol_trans_time_per_ue->validity_period = NULL;
	}
	if(e2e_data_vol_trans_time_per_ue->data_vol_trans_time) {
		data_volume_transfer_time_free(
			e2e_data_vol_trans_time_per_ue->data_vol_trans_time);
		e2e_data_vol_trans_time_per_ue->data_vol_trans_time = NULL;
	}
	free(e2e_data_vol_trans_time_per_ue);
}

cJSON *e2e_data_vol_trans_time_per_ue_convertToJSON(
	e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(e2e_data_vol_trans_time_per_ue == NULL) {
		printf(
			"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [E2eDataVolTransTimePerUe]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(e2e_data_vol_trans_time_per_ue->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           e2e_data_vol_trans_time_per_ue->supi)
		   == NULL)
		{
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_per_ue->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           e2e_data_vol_trans_time_per_ue->gpsi)
		   == NULL)
		{
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_per_ue->snssai) {
		cJSON *snssai_local_JSON = snssai_convertToJSON(
			e2e_data_vol_trans_time_per_ue->snssai);
		if(snssai_local_JSON == NULL) {
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [snssai]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_per_ue->app_id) {
		if(cJSON_AddStringToObject(item, "appId",
		                           e2e_data_vol_trans_time_per_ue->
		                           app_id) == NULL)
		{
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [app_id]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_per_ue->ue_loc) {
		cJSON *ue_loc_local_JSON = user_location_convertToJSON(
			e2e_data_vol_trans_time_per_ue->ue_loc);
		if(ue_loc_local_JSON == NULL) {
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [ue_loc]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueLoc", ue_loc_local_JSON);
		if(item->child == NULL) {
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [ue_loc]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_per_ue->dnn) {
		if(cJSON_AddStringToObject(item, "dnn",
		                           e2e_data_vol_trans_time_per_ue->dnn)
		   == NULL)
		{
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [dnn]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_per_ue->spatial_validity) {
		cJSON *spatial_validity_local_JSON =
			network_area_info_convertToJSON(
				e2e_data_vol_trans_time_per_ue->spatial_validity);
		if(spatial_validity_local_JSON == NULL) {
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [spatial_validity]");
			goto end;
		}
		cJSON_AddItemToObject(item, "spatialValidity",
		                      spatial_validity_local_JSON);
		if(item->child == NULL) {
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [spatial_validity]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_per_ue->validity_period) {
		cJSON *validity_period_local_JSON = time_window_convertToJSON(
			e2e_data_vol_trans_time_per_ue->validity_period);
		if(validity_period_local_JSON == NULL) {
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [validity_period]");
			goto end;
		}
		cJSON_AddItemToObject(item, "validityPeriod",
		                      validity_period_local_JSON);
		if(item->child == NULL) {
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [validity_period]");
			goto end;
		}
	}

	if(e2e_data_vol_trans_time_per_ue->data_vol_trans_time) {
		cJSON *data_vol_trans_time_local_JSON =
			data_volume_transfer_time_convertToJSON(
				e2e_data_vol_trans_time_per_ue->data_vol_trans_time);
		if(data_vol_trans_time_local_JSON == NULL) {
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [data_vol_trans_time]");
			goto end;
		}
		cJSON_AddItemToObject(item, "dataVolTransTime",
		                      data_vol_trans_time_local_JSON);
		if(item->child == NULL) {
			printf(
				"e2e_data_vol_trans_time_per_ue_convertToJSON() failed [data_vol_trans_time]");
			goto end;
		}
	}

end:
	return item;
}

e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue_parseFromJSON(
	cJSON *e2e_data_vol_trans_time_per_ueJSON) {
	e2e_data_vol_trans_time_per_ue_t *
	        e2e_data_vol_trans_time_per_ue_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *supi = NULL;
	cJSON *gpsi = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *app_id = NULL;
	cJSON *ue_loc = NULL;
	user_location_t *ue_loc_local_nonprim = NULL;
	cJSON *dnn = NULL;
	cJSON *spatial_validity = NULL;
	network_area_info_t *spatial_validity_local_nonprim = NULL;
	cJSON *validity_period = NULL;
	time_window_t *validity_period_local_nonprim = NULL;
	cJSON *data_vol_trans_time = NULL;
	data_volume_transfer_time_t *data_vol_trans_time_local_nonprim = NULL;
	supi = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_per_ueJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf(
				"e2e_data_vol_trans_time_per_ue_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_per_ueJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf(
				"e2e_data_vol_trans_time_per_ue_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	snssai = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_per_ueJSON, "snssai");
	if(snssai) {
		snssai_local_nonprim = snssai_parseFromJSON(snssai);
		if(!snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [snssai]");
			goto end;
		}
	}

	app_id = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_per_ueJSON, "appId");
	if(app_id) {
		if(!cJSON_IsString(app_id) &&
		   !cJSON_IsNull(app_id))
		{
			printf(
				"e2e_data_vol_trans_time_per_ue_parseFromJSON() failed [app_id]");
			goto end;
		}
	}

	ue_loc = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_per_ueJSON, "ueLoc");
	if(ue_loc) {
		ue_loc_local_nonprim = user_location_parseFromJSON(ue_loc);
		if(!ue_loc_local_nonprim) {
			printf("user_location_parseFromJSON failed [ue_loc]");
			goto end;
		}
	}

	dnn = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_per_ueJSON, "dnn");
	if(dnn) {
		if(!cJSON_IsString(dnn) &&
		   !cJSON_IsNull(dnn))
		{
			printf(
				"e2e_data_vol_trans_time_per_ue_parseFromJSON() failed [dnn]");
			goto end;
		}
	}

	spatial_validity = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_per_ueJSON, "spatialValidity");
	if(spatial_validity) {
		spatial_validity_local_nonprim =
			network_area_info_parseFromJSON(spatial_validity);
		if(!spatial_validity_local_nonprim) {
			printf(
				"network_area_info_parseFromJSON failed [spatial_validity]");
			goto end;
		}
	}

	validity_period = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_per_ueJSON, "validityPeriod");
	if(validity_period) {
		validity_period_local_nonprim = time_window_parseFromJSON(
			validity_period);
		if(!validity_period_local_nonprim) {
			printf(
				"time_window_parseFromJSON failed [validity_period]");
			goto end;
		}
	}

	data_vol_trans_time = cJSON_GetObjectItemCaseSensitive(
		e2e_data_vol_trans_time_per_ueJSON, "dataVolTransTime");
	if(data_vol_trans_time) {
		data_vol_trans_time_local_nonprim =
			data_volume_transfer_time_parseFromJSON(
				data_vol_trans_time);
		if(!data_vol_trans_time_local_nonprim) {
			printf(
				"data_volume_transfer_time_parseFromJSON failed [data_vol_trans_time]");
			goto end;
		}
	}

	e2e_data_vol_trans_time_per_ue_local_var =
		e2e_data_vol_trans_time_per_ue_create(
			supi &&
			!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
			gpsi &&
			!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
			snssai ? snssai_local_nonprim : NULL,
			app_id &&
			!cJSON_IsNull(app_id) ? strdup(
				app_id->valuestring) : NULL,
			ue_loc ? ue_loc_local_nonprim : NULL,
			dnn &&
			!cJSON_IsNull(dnn) ? strdup(
				dnn->valuestring) : NULL,
			spatial_validity ? spatial_validity_local_nonprim : NULL,
			validity_period ? validity_period_local_nonprim : NULL,
			data_vol_trans_time ? data_vol_trans_time_local_nonprim : NULL
			);

	return e2e_data_vol_trans_time_per_ue_local_var;
end:
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(ue_loc_local_nonprim) {
		user_location_free(ue_loc_local_nonprim);
		ue_loc_local_nonprim = NULL;
	}
	if(spatial_validity_local_nonprim) {
		network_area_info_free(spatial_validity_local_nonprim);
		spatial_validity_local_nonprim = NULL;
	}
	if(validity_period_local_nonprim) {
		time_window_free(validity_period_local_nonprim);
		validity_period_local_nonprim = NULL;
	}
	if(data_vol_trans_time_local_nonprim) {
		data_volume_transfer_time_free(data_vol_trans_time_local_nonprim);
		data_vol_trans_time_local_nonprim = NULL;
	}
	return NULL;
}

e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue_copy(
	e2e_data_vol_trans_time_per_ue_t	*dst,
	e2e_data_vol_trans_time_per_ue_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = e2e_data_vol_trans_time_per_ue_convertToJSON(src);
	if(!item) {
		printf("e2e_data_vol_trans_time_per_ue_convertToJSON() failed");
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

	e2e_data_vol_trans_time_per_ue_free(dst);
	dst = e2e_data_vol_trans_time_per_ue_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
