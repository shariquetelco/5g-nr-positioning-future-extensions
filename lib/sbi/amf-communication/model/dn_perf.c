#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dn_perf.h"

dn_perf_t *dn_perf_create(addr_fqdn_t *app_server_ins_addr,
                          upf_information_t *upf_info, char *dnai,
                          perf_data_t *perf_data,
                          network_area_info_t *spatial_valid_con,
                          time_window_t *temporal_valid_con) {
	dn_perf_t *dn_perf_local_var = malloc(sizeof(dn_perf_t));

	dn_perf_local_var->app_server_ins_addr = app_server_ins_addr;
	dn_perf_local_var->upf_info = upf_info;
	dn_perf_local_var->dnai = dnai;
	dn_perf_local_var->perf_data = perf_data;
	dn_perf_local_var->spatial_valid_con = spatial_valid_con;
	dn_perf_local_var->temporal_valid_con = temporal_valid_con;

	return dn_perf_local_var;
}

void dn_perf_free(dn_perf_t *dn_perf) {
	lnode_t *node = NULL;

	if(NULL == dn_perf) {
		return;
	}
	if(dn_perf->app_server_ins_addr) {
		addr_fqdn_free(dn_perf->app_server_ins_addr);
		dn_perf->app_server_ins_addr = NULL;
	}
	if(dn_perf->upf_info) {
		upf_information_free(dn_perf->upf_info);
		dn_perf->upf_info = NULL;
	}
	if(dn_perf->dnai) {
		free(dn_perf->dnai);
		dn_perf->dnai = NULL;
	}
	if(dn_perf->perf_data) {
		perf_data_free(dn_perf->perf_data);
		dn_perf->perf_data = NULL;
	}
	if(dn_perf->spatial_valid_con) {
		network_area_info_free(dn_perf->spatial_valid_con);
		dn_perf->spatial_valid_con = NULL;
	}
	if(dn_perf->temporal_valid_con) {
		time_window_free(dn_perf->temporal_valid_con);
		dn_perf->temporal_valid_con = NULL;
	}
	free(dn_perf);
}

cJSON *dn_perf_convertToJSON(dn_perf_t *dn_perf) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dn_perf == NULL) {
		printf("dn_perf_convertToJSON() failed [DnPerf]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(dn_perf->app_server_ins_addr) {
		cJSON *app_server_ins_addr_local_JSON = addr_fqdn_convertToJSON(
			dn_perf->app_server_ins_addr);
		if(app_server_ins_addr_local_JSON == NULL) {
			printf(
				"dn_perf_convertToJSON() failed [app_server_ins_addr]");
			goto end;
		}
		cJSON_AddItemToObject(item, "appServerInsAddr",
		                      app_server_ins_addr_local_JSON);
		if(item->child == NULL) {
			printf(
				"dn_perf_convertToJSON() failed [app_server_ins_addr]");
			goto end;
		}
	}

	if(dn_perf->upf_info) {
		cJSON *upf_info_local_JSON = upf_information_convertToJSON(
			dn_perf->upf_info);
		if(upf_info_local_JSON == NULL) {
			printf("dn_perf_convertToJSON() failed [upf_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "upfInfo", upf_info_local_JSON);
		if(item->child == NULL) {
			printf("dn_perf_convertToJSON() failed [upf_info]");
			goto end;
		}
	}

	if(dn_perf->dnai) {
		if(cJSON_AddStringToObject(item, "dnai",
		                           dn_perf->dnai) == NULL)
		{
			printf("dn_perf_convertToJSON() failed [dnai]");
			goto end;
		}
	}

	if(!dn_perf->perf_data) {
		printf("dn_perf_convertToJSON() failed [perf_data]");
		return NULL;
	}
	cJSON *perf_data_local_JSON =
		perf_data_convertToJSON(dn_perf->perf_data);
	if(perf_data_local_JSON == NULL) {
		printf("dn_perf_convertToJSON() failed [perf_data]");
		goto end;
	}
	cJSON_AddItemToObject(item, "perfData", perf_data_local_JSON);
	if(item->child == NULL) {
		printf("dn_perf_convertToJSON() failed [perf_data]");
		goto end;
	}

	if(dn_perf->spatial_valid_con) {
		cJSON *spatial_valid_con_local_JSON =
			network_area_info_convertToJSON(
				dn_perf->spatial_valid_con);
		if(spatial_valid_con_local_JSON == NULL) {
			printf(
				"dn_perf_convertToJSON() failed [spatial_valid_con]");
			goto end;
		}
		cJSON_AddItemToObject(item, "spatialValidCon",
		                      spatial_valid_con_local_JSON);
		if(item->child == NULL) {
			printf(
				"dn_perf_convertToJSON() failed [spatial_valid_con]");
			goto end;
		}
	}

	if(dn_perf->temporal_valid_con) {
		cJSON *temporal_valid_con_local_JSON =
			time_window_convertToJSON(dn_perf->temporal_valid_con);
		if(temporal_valid_con_local_JSON == NULL) {
			printf(
				"dn_perf_convertToJSON() failed [temporal_valid_con]");
			goto end;
		}
		cJSON_AddItemToObject(item, "temporalValidCon",
		                      temporal_valid_con_local_JSON);
		if(item->child == NULL) {
			printf(
				"dn_perf_convertToJSON() failed [temporal_valid_con]");
			goto end;
		}
	}

end:
	return item;
}

dn_perf_t *dn_perf_parseFromJSON(cJSON *dn_perfJSON) {
	dn_perf_t *dn_perf_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *app_server_ins_addr = NULL;
	addr_fqdn_t *app_server_ins_addr_local_nonprim = NULL;
	cJSON *upf_info = NULL;
	upf_information_t *upf_info_local_nonprim = NULL;
	cJSON *dnai = NULL;
	cJSON *perf_data = NULL;
	perf_data_t *perf_data_local_nonprim = NULL;
	cJSON *spatial_valid_con = NULL;
	network_area_info_t *spatial_valid_con_local_nonprim = NULL;
	cJSON *temporal_valid_con = NULL;
	time_window_t *temporal_valid_con_local_nonprim = NULL;
	app_server_ins_addr = cJSON_GetObjectItemCaseSensitive(dn_perfJSON,
	                                                       "appServerInsAddr");
	if(app_server_ins_addr) {
		app_server_ins_addr_local_nonprim = addr_fqdn_parseFromJSON(
			app_server_ins_addr);
		if(!app_server_ins_addr_local_nonprim) {
			printf(
				"addr_fqdn_parseFromJSON failed [app_server_ins_addr]");
			goto end;
		}
	}

	upf_info = cJSON_GetObjectItemCaseSensitive(dn_perfJSON, "upfInfo");
	if(upf_info) {
		upf_info_local_nonprim =
			upf_information_parseFromJSON(upf_info);
		if(!upf_info_local_nonprim) {
			printf("upf_information_parseFromJSON failed [upf_info]");
			goto end;
		}
	}

	dnai = cJSON_GetObjectItemCaseSensitive(dn_perfJSON, "dnai");
	if(dnai) {
		if(!cJSON_IsString(dnai) &&
		   !cJSON_IsNull(dnai))
		{
			printf("dn_perf_parseFromJSON() failed [dnai]");
			goto end;
		}
	}

	perf_data = cJSON_GetObjectItemCaseSensitive(dn_perfJSON, "perfData");
	if(!perf_data) {
		printf("dn_perf_parseFromJSON() failed [perf_data]");
		goto end;
	}
	perf_data_local_nonprim = perf_data_parseFromJSON(perf_data);
	if(!perf_data_local_nonprim) {
		printf("perf_data_parseFromJSON failed [perf_data]");
		goto end;
	}

	spatial_valid_con = cJSON_GetObjectItemCaseSensitive(dn_perfJSON,
	                                                     "spatialValidCon");
	if(spatial_valid_con) {
		spatial_valid_con_local_nonprim =
			network_area_info_parseFromJSON(spatial_valid_con);
		if(!spatial_valid_con_local_nonprim) {
			printf(
				"network_area_info_parseFromJSON failed [spatial_valid_con]");
			goto end;
		}
	}

	temporal_valid_con = cJSON_GetObjectItemCaseSensitive(dn_perfJSON,
	                                                      "temporalValidCon");
	if(temporal_valid_con) {
		temporal_valid_con_local_nonprim = time_window_parseFromJSON(
			temporal_valid_con);
		if(!temporal_valid_con_local_nonprim) {
			printf(
				"time_window_parseFromJSON failed [temporal_valid_con]");
			goto end;
		}
	}

	dn_perf_local_var = dn_perf_create(
		app_server_ins_addr ? app_server_ins_addr_local_nonprim : NULL,
		upf_info ? upf_info_local_nonprim : NULL,
		dnai &&
		!cJSON_IsNull(dnai) ? strdup(dnai->valuestring) : NULL,
		perf_data_local_nonprim,
		spatial_valid_con ? spatial_valid_con_local_nonprim : NULL,
		temporal_valid_con ? temporal_valid_con_local_nonprim : NULL
		);

	return dn_perf_local_var;
end:
	if(app_server_ins_addr_local_nonprim) {
		addr_fqdn_free(app_server_ins_addr_local_nonprim);
		app_server_ins_addr_local_nonprim = NULL;
	}
	if(upf_info_local_nonprim) {
		upf_information_free(upf_info_local_nonprim);
		upf_info_local_nonprim = NULL;
	}
	if(perf_data_local_nonprim) {
		perf_data_free(perf_data_local_nonprim);
		perf_data_local_nonprim = NULL;
	}
	if(spatial_valid_con_local_nonprim) {
		network_area_info_free(spatial_valid_con_local_nonprim);
		spatial_valid_con_local_nonprim = NULL;
	}
	if(temporal_valid_con_local_nonprim) {
		time_window_free(temporal_valid_con_local_nonprim);
		temporal_valid_con_local_nonprim = NULL;
	}
	return NULL;
}

dn_perf_t *dn_perf_copy(dn_perf_t *dst, dn_perf_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dn_perf_convertToJSON(src);
	if(!item) {
		printf("dn_perf_convertToJSON() failed");
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

	dn_perf_free(dst);
	dst = dn_perf_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
