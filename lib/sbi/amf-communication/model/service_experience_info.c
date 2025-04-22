#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_experience_info.h"

service_experience_info_t *service_experience_info_create(
	svc_experience_t *svc_exprc, bool is_svc_exprc_variance,
	float svc_exprc_variance, list_t *supis, snssai_t *snssai, char *app_id,
	service_experience_type_t *srv_expc_type, list_t *ue_locs,
	upf_information_t *upf_info, char *dnai, addr_fqdn_t *app_server_inst,
	bool is_confidence, int confidence, char *dnn,
	network_area_info_t *network_area, char *nsi_id, bool is_ratio,
	int ratio, rat_freq_information_t *rat_freq,
	pdu_session_info_1_t *pdu_ses_info) {
	service_experience_info_t *service_experience_info_local_var = malloc(
		sizeof(service_experience_info_t));

	service_experience_info_local_var->svc_exprc = svc_exprc;
	service_experience_info_local_var->is_svc_exprc_variance =
		is_svc_exprc_variance;
	service_experience_info_local_var->svc_exprc_variance =
		svc_exprc_variance;
	service_experience_info_local_var->supis = supis;
	service_experience_info_local_var->snssai = snssai;
	service_experience_info_local_var->app_id = app_id;
	service_experience_info_local_var->srv_expc_type = srv_expc_type;
	service_experience_info_local_var->ue_locs = ue_locs;
	service_experience_info_local_var->upf_info = upf_info;
	service_experience_info_local_var->dnai = dnai;
	service_experience_info_local_var->app_server_inst = app_server_inst;
	service_experience_info_local_var->is_confidence = is_confidence;
	service_experience_info_local_var->confidence = confidence;
	service_experience_info_local_var->dnn = dnn;
	service_experience_info_local_var->network_area = network_area;
	service_experience_info_local_var->nsi_id = nsi_id;
	service_experience_info_local_var->is_ratio = is_ratio;
	service_experience_info_local_var->ratio = ratio;
	service_experience_info_local_var->rat_freq = rat_freq;
	service_experience_info_local_var->pdu_ses_info = pdu_ses_info;

	return service_experience_info_local_var;
}

void service_experience_info_free(
	service_experience_info_t *service_experience_info) {
	lnode_t *node = NULL;

	if(NULL == service_experience_info) {
		return;
	}
	if(service_experience_info->svc_exprc) {
		svc_experience_free(service_experience_info->svc_exprc);
		service_experience_info->svc_exprc = NULL;
	}
	if(service_experience_info->supis) {
		list_for_each(service_experience_info->supis, node) {
			free(node->data);
		}
		list_free(service_experience_info->supis);
		service_experience_info->supis = NULL;
	}
	if(service_experience_info->snssai) {
		snssai_free(service_experience_info->snssai);
		service_experience_info->snssai = NULL;
	}
	if(service_experience_info->app_id) {
		free(service_experience_info->app_id);
		service_experience_info->app_id = NULL;
	}
	if(service_experience_info->srv_expc_type) {
		service_experience_type_free(
			service_experience_info->srv_expc_type);
		service_experience_info->srv_expc_type = NULL;
	}
	if(service_experience_info->ue_locs) {
		list_for_each(service_experience_info->ue_locs, node) {
			location_info_free(node->data);
		}
		list_free(service_experience_info->ue_locs);
		service_experience_info->ue_locs = NULL;
	}
	if(service_experience_info->upf_info) {
		upf_information_free(service_experience_info->upf_info);
		service_experience_info->upf_info = NULL;
	}
	if(service_experience_info->dnai) {
		free(service_experience_info->dnai);
		service_experience_info->dnai = NULL;
	}
	if(service_experience_info->app_server_inst) {
		addr_fqdn_free(service_experience_info->app_server_inst);
		service_experience_info->app_server_inst = NULL;
	}
	if(service_experience_info->dnn) {
		free(service_experience_info->dnn);
		service_experience_info->dnn = NULL;
	}
	if(service_experience_info->network_area) {
		network_area_info_free(service_experience_info->network_area);
		service_experience_info->network_area = NULL;
	}
	if(service_experience_info->nsi_id) {
		free(service_experience_info->nsi_id);
		service_experience_info->nsi_id = NULL;
	}
	if(service_experience_info->rat_freq) {
		rat_freq_information_free(service_experience_info->rat_freq);
		service_experience_info->rat_freq = NULL;
	}
	if(service_experience_info->pdu_ses_info) {
		pdu_session_info_1_free(service_experience_info->pdu_ses_info);
		service_experience_info->pdu_ses_info = NULL;
	}
	free(service_experience_info);
}

cJSON *service_experience_info_convertToJSON(
	service_experience_info_t *service_experience_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(service_experience_info == NULL) {
		printf(
			"service_experience_info_convertToJSON() failed [ServiceExperienceInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!service_experience_info->svc_exprc) {
		printf(
			"service_experience_info_convertToJSON() failed [svc_exprc]");
		return NULL;
	}
	cJSON *svc_exprc_local_JSON = svc_experience_convertToJSON(
		service_experience_info->svc_exprc);
	if(svc_exprc_local_JSON == NULL) {
		printf(
			"service_experience_info_convertToJSON() failed [svc_exprc]");
		goto end;
	}
	cJSON_AddItemToObject(item, "svcExprc", svc_exprc_local_JSON);
	if(item->child == NULL) {
		printf(
			"service_experience_info_convertToJSON() failed [svc_exprc]");
		goto end;
	}

	if(service_experience_info->is_svc_exprc_variance) {
		if(cJSON_AddNumberToObject(item, "svcExprcVariance",
		                           service_experience_info->
		                           svc_exprc_variance) == NULL)
		{
			printf(
				"service_experience_info_convertToJSON() failed [svc_exprc_variance]");
			goto end;
		}
	}

	if(service_experience_info->supis) {
		cJSON *supisList = cJSON_AddArrayToObject(item, "supis");
		if(supisList == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [supis]");
			goto end;
		}
		list_for_each(service_experience_info->supis, node) {
			if(cJSON_AddStringToObject(supisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"service_experience_info_convertToJSON() failed [supis]");
				goto end;
			}
		}
	}

	if(service_experience_info->snssai) {
		cJSON *snssai_local_JSON = snssai_convertToJSON(
			service_experience_info->snssai);
		if(snssai_local_JSON == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [snssai]");
			goto end;
		}
	}

	if(service_experience_info->app_id) {
		if(cJSON_AddStringToObject(item, "appId",
		                           service_experience_info->app_id) ==
		   NULL)
		{
			printf(
				"service_experience_info_convertToJSON() failed [app_id]");
			goto end;
		}
	}

	if(service_experience_info->srv_expc_type) {
		cJSON *srv_expc_type_local_JSON =
			service_experience_type_convertToJSON(
				service_experience_info->srv_expc_type);
		if(srv_expc_type_local_JSON == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [srv_expc_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "srvExpcType",
		                      srv_expc_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [srv_expc_type]");
			goto end;
		}
	}

	if(service_experience_info->ue_locs) {
		cJSON *ue_locsList = cJSON_AddArrayToObject(item, "ueLocs");
		if(ue_locsList == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [ue_locs]");
			goto end;
		}
		list_for_each(service_experience_info->ue_locs, node) {
			cJSON *itemLocal = location_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"service_experience_info_convertToJSON() failed [ue_locs]");
				goto end;
			}
			cJSON_AddItemToArray(ue_locsList, itemLocal);
		}
	}

	if(service_experience_info->upf_info) {
		cJSON *upf_info_local_JSON = upf_information_convertToJSON(
			service_experience_info->upf_info);
		if(upf_info_local_JSON == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [upf_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "upfInfo", upf_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [upf_info]");
			goto end;
		}
	}

	if(service_experience_info->dnai) {
		if(cJSON_AddStringToObject(item, "dnai",
		                           service_experience_info->dnai) ==
		   NULL)
		{
			printf(
				"service_experience_info_convertToJSON() failed [dnai]");
			goto end;
		}
	}

	if(service_experience_info->app_server_inst) {
		cJSON *app_server_inst_local_JSON = addr_fqdn_convertToJSON(
			service_experience_info->app_server_inst);
		if(app_server_inst_local_JSON == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [app_server_inst]");
			goto end;
		}
		cJSON_AddItemToObject(item, "appServerInst",
		                      app_server_inst_local_JSON);
		if(item->child == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [app_server_inst]");
			goto end;
		}
	}

	if(service_experience_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           service_experience_info->confidence)
		   == NULL)
		{
			printf(
				"service_experience_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

	if(service_experience_info->dnn) {
		if(cJSON_AddStringToObject(item, "dnn",
		                           service_experience_info->dnn) ==
		   NULL)
		{
			printf(
				"service_experience_info_convertToJSON() failed [dnn]");
			goto end;
		}
	}

	if(service_experience_info->network_area) {
		cJSON *network_area_local_JSON =
			network_area_info_convertToJSON(
				service_experience_info->network_area);
		if(network_area_local_JSON == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [network_area]");
			goto end;
		}
		cJSON_AddItemToObject(item, "networkArea",
		                      network_area_local_JSON);
		if(item->child == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [network_area]");
			goto end;
		}
	}

	if(service_experience_info->nsi_id) {
		if(cJSON_AddStringToObject(item, "nsiId",
		                           service_experience_info->nsi_id) ==
		   NULL)
		{
			printf(
				"service_experience_info_convertToJSON() failed [nsi_id]");
			goto end;
		}
	}

	if(service_experience_info->is_ratio) {
		if(cJSON_AddNumberToObject(item, "ratio",
		                           service_experience_info->ratio) ==
		   NULL)
		{
			printf(
				"service_experience_info_convertToJSON() failed [ratio]");
			goto end;
		}
	}

	if(service_experience_info->rat_freq) {
		cJSON *rat_freq_local_JSON = rat_freq_information_convertToJSON(
			service_experience_info->rat_freq);
		if(rat_freq_local_JSON == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [rat_freq]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ratFreq", rat_freq_local_JSON);
		if(item->child == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [rat_freq]");
			goto end;
		}
	}

	if(service_experience_info->pdu_ses_info) {
		cJSON *pdu_ses_info_local_JSON =
			pdu_session_info_1_convertToJSON(
				service_experience_info->pdu_ses_info);
		if(pdu_ses_info_local_JSON == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [pdu_ses_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "pduSesInfo",
		                      pdu_ses_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"service_experience_info_convertToJSON() failed [pdu_ses_info]");
			goto end;
		}
	}

end:
	return item;
}

service_experience_info_t *service_experience_info_parseFromJSON(
	cJSON *service_experience_infoJSON) {
	service_experience_info_t *service_experience_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *svc_exprc = NULL;
	svc_experience_t *svc_exprc_local_nonprim = NULL;
	cJSON *svc_exprc_variance = NULL;
	cJSON *supis = NULL;
	list_t *supisList = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *app_id = NULL;
	cJSON *srv_expc_type = NULL;
	service_experience_type_t *srv_expc_type_local_nonprim = NULL;
	cJSON *ue_locs = NULL;
	list_t *ue_locsList = NULL;
	cJSON *upf_info = NULL;
	upf_information_t *upf_info_local_nonprim = NULL;
	cJSON *dnai = NULL;
	cJSON *app_server_inst = NULL;
	addr_fqdn_t *app_server_inst_local_nonprim = NULL;
	cJSON *confidence = NULL;
	cJSON *dnn = NULL;
	cJSON *network_area = NULL;
	network_area_info_t *network_area_local_nonprim = NULL;
	cJSON *nsi_id = NULL;
	cJSON *ratio = NULL;
	cJSON *rat_freq = NULL;
	rat_freq_information_t *rat_freq_local_nonprim = NULL;
	cJSON *pdu_ses_info = NULL;
	pdu_session_info_1_t *pdu_ses_info_local_nonprim = NULL;
	svc_exprc = cJSON_GetObjectItemCaseSensitive(
		service_experience_infoJSON, "svcExprc");
	if(!svc_exprc) {
		printf(
			"service_experience_info_parseFromJSON() failed [svc_exprc]");
		goto end;
	}
	svc_exprc_local_nonprim = svc_experience_parseFromJSON(svc_exprc);
	if(!svc_exprc_local_nonprim) {
		printf("svc_experience_parseFromJSON failed [svc_exprc]");
		goto end;
	}

	svc_exprc_variance = cJSON_GetObjectItemCaseSensitive(
		service_experience_infoJSON, "svcExprcVariance");
	if(svc_exprc_variance) {
		if(!cJSON_IsNumber(svc_exprc_variance)) {
			printf(
				"service_experience_info_parseFromJSON() failed [svc_exprc_variance]");
			goto end;
		}
	}

	supis = cJSON_GetObjectItemCaseSensitive(service_experience_infoJSON,
	                                         "supis");
	if(supis) {
		cJSON *supis_local = NULL;
		if(!cJSON_IsArray(supis)) {
			printf(
				"service_experience_info_parseFromJSON() failed [supis]");
			goto end;
		}

		supisList = list_create();

		cJSON_ArrayForEach(supis_local, supis) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(supis_local)) {
				printf(
					"service_experience_info_parseFromJSON() failed [supis]");
				goto end;
			}
			list_add(supisList, strdup(supis_local->valuestring));
		}
	}

	snssai = cJSON_GetObjectItemCaseSensitive(service_experience_infoJSON,
	                                          "snssai");
	if(snssai) {
		snssai_local_nonprim = snssai_parseFromJSON(snssai);
		if(!snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [snssai]");
			goto end;
		}
	}

	app_id = cJSON_GetObjectItemCaseSensitive(service_experience_infoJSON,
	                                          "appId");
	if(app_id) {
		if(!cJSON_IsString(app_id) &&
		   !cJSON_IsNull(app_id))
		{
			printf(
				"service_experience_info_parseFromJSON() failed [app_id]");
			goto end;
		}
	}

	srv_expc_type = cJSON_GetObjectItemCaseSensitive(
		service_experience_infoJSON, "srvExpcType");
	if(srv_expc_type) {
		srv_expc_type_local_nonprim =
			service_experience_type_parseFromJSON(srv_expc_type);
		if(!srv_expc_type_local_nonprim) {
			printf(
				"service_experience_type_parseFromJSON failed [srv_expc_type]");
			goto end;
		}
	}

	ue_locs = cJSON_GetObjectItemCaseSensitive(service_experience_infoJSON,
	                                           "ueLocs");
	if(ue_locs) {
		cJSON *ue_locs_local = NULL;
		if(!cJSON_IsArray(ue_locs)) {
			printf(
				"service_experience_info_parseFromJSON() failed [ue_locs]");
			goto end;
		}

		ue_locsList = list_create();

		cJSON_ArrayForEach(ue_locs_local, ue_locs) {
			if(!cJSON_IsObject(ue_locs_local)) {
				printf(
					"service_experience_info_parseFromJSON() failed [ue_locs]");
				goto end;
			}
			location_info_t *ue_locsItem =
				location_info_parseFromJSON(ue_locs_local);
			if(!ue_locsItem) {
				printf("No ue_locsItem");
				goto end;
			}
			list_add(ue_locsList, ue_locsItem);
		}
	}

	upf_info = cJSON_GetObjectItemCaseSensitive(service_experience_infoJSON,
	                                            "upfInfo");
	if(upf_info) {
		upf_info_local_nonprim =
			upf_information_parseFromJSON(upf_info);
		if(!upf_info_local_nonprim) {
			printf("upf_information_parseFromJSON failed [upf_info]");
			goto end;
		}
	}

	dnai = cJSON_GetObjectItemCaseSensitive(service_experience_infoJSON,
	                                        "dnai");
	if(dnai) {
		if(!cJSON_IsString(dnai) &&
		   !cJSON_IsNull(dnai))
		{
			printf(
				"service_experience_info_parseFromJSON() failed [dnai]");
			goto end;
		}
	}

	app_server_inst = cJSON_GetObjectItemCaseSensitive(
		service_experience_infoJSON, "appServerInst");
	if(app_server_inst) {
		app_server_inst_local_nonprim = addr_fqdn_parseFromJSON(
			app_server_inst);
		if(!app_server_inst_local_nonprim) {
			printf(
				"addr_fqdn_parseFromJSON failed [app_server_inst]");
			goto end;
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(
		service_experience_infoJSON, "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"service_experience_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	dnn = cJSON_GetObjectItemCaseSensitive(service_experience_infoJSON,
	                                       "dnn");
	if(dnn) {
		if(!cJSON_IsString(dnn) &&
		   !cJSON_IsNull(dnn))
		{
			printf(
				"service_experience_info_parseFromJSON() failed [dnn]");
			goto end;
		}
	}

	network_area = cJSON_GetObjectItemCaseSensitive(
		service_experience_infoJSON, "networkArea");
	if(network_area) {
		network_area_local_nonprim = network_area_info_parseFromJSON(
			network_area);
		if(!network_area_local_nonprim) {
			printf(
				"network_area_info_parseFromJSON failed [network_area]");
			goto end;
		}
	}

	nsi_id = cJSON_GetObjectItemCaseSensitive(service_experience_infoJSON,
	                                          "nsiId");
	if(nsi_id) {
		if(!cJSON_IsString(nsi_id) &&
		   !cJSON_IsNull(nsi_id))
		{
			printf(
				"service_experience_info_parseFromJSON() failed [nsi_id]");
			goto end;
		}
	}

	ratio = cJSON_GetObjectItemCaseSensitive(service_experience_infoJSON,
	                                         "ratio");
	if(ratio) {
		if(!cJSON_IsNumber(ratio)) {
			printf(
				"service_experience_info_parseFromJSON() failed [ratio]");
			goto end;
		}
	}

	rat_freq = cJSON_GetObjectItemCaseSensitive(service_experience_infoJSON,
	                                            "ratFreq");
	if(rat_freq) {
		rat_freq_local_nonprim = rat_freq_information_parseFromJSON(
			rat_freq);
		if(!rat_freq_local_nonprim) {
			printf(
				"rat_freq_information_parseFromJSON failed [rat_freq]");
			goto end;
		}
	}

	pdu_ses_info = cJSON_GetObjectItemCaseSensitive(
		service_experience_infoJSON, "pduSesInfo");
	if(pdu_ses_info) {
		pdu_ses_info_local_nonprim = pdu_session_info_1_parseFromJSON(
			pdu_ses_info);
		if(!pdu_ses_info_local_nonprim) {
			printf(
				"pdu_session_info_1_parseFromJSON failed [pdu_ses_info]");
			goto end;
		}
	}

	service_experience_info_local_var = service_experience_info_create(
		svc_exprc_local_nonprim,
		svc_exprc_variance ? true : false,
		svc_exprc_variance ? svc_exprc_variance->valuedouble : 0,
		supis ? supisList : NULL,
		snssai ? snssai_local_nonprim : NULL,
		app_id &&
		!cJSON_IsNull(app_id) ? strdup(app_id->valuestring) : NULL,
		srv_expc_type ? srv_expc_type_local_nonprim : NULL,
		ue_locs ? ue_locsList : NULL,
		upf_info ? upf_info_local_nonprim : NULL,
		dnai &&
		!cJSON_IsNull(dnai) ? strdup(dnai->valuestring) : NULL,
		app_server_inst ? app_server_inst_local_nonprim : NULL,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0,
		dnn &&
		!cJSON_IsNull(dnn) ? strdup(dnn->valuestring) : NULL,
		network_area ? network_area_local_nonprim : NULL,
		nsi_id &&
		!cJSON_IsNull(nsi_id) ? strdup(nsi_id->valuestring) : NULL,
		ratio ? true : false,
		ratio ? ratio->valuedouble : 0,
		rat_freq ? rat_freq_local_nonprim : NULL,
		pdu_ses_info ? pdu_ses_info_local_nonprim : NULL
		);

	return service_experience_info_local_var;
end:
	if(svc_exprc_local_nonprim) {
		svc_experience_free(svc_exprc_local_nonprim);
		svc_exprc_local_nonprim = NULL;
	}
	if(supisList) {
		list_for_each(supisList, node) {
			free(node->data);
		}
		list_free(supisList);
		supisList = NULL;
	}
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(srv_expc_type_local_nonprim) {
		service_experience_type_free(srv_expc_type_local_nonprim);
		srv_expc_type_local_nonprim = NULL;
	}
	if(ue_locsList) {
		list_for_each(ue_locsList, node) {
			location_info_free(node->data);
		}
		list_free(ue_locsList);
		ue_locsList = NULL;
	}
	if(upf_info_local_nonprim) {
		upf_information_free(upf_info_local_nonprim);
		upf_info_local_nonprim = NULL;
	}
	if(app_server_inst_local_nonprim) {
		addr_fqdn_free(app_server_inst_local_nonprim);
		app_server_inst_local_nonprim = NULL;
	}
	if(network_area_local_nonprim) {
		network_area_info_free(network_area_local_nonprim);
		network_area_local_nonprim = NULL;
	}
	if(rat_freq_local_nonprim) {
		rat_freq_information_free(rat_freq_local_nonprim);
		rat_freq_local_nonprim = NULL;
	}
	if(pdu_ses_info_local_nonprim) {
		pdu_session_info_1_free(pdu_ses_info_local_nonprim);
		pdu_ses_info_local_nonprim = NULL;
	}
	return NULL;
}

service_experience_info_t *service_experience_info_copy(
	service_experience_info_t *dst, service_experience_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = service_experience_info_convertToJSON(src);
	if(!item) {
		printf("service_experience_info_convertToJSON() failed");
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

	service_experience_info_free(dst);
	dst = service_experience_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
