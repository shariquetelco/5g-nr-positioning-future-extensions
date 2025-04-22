#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_update_data.h"

loc_update_data_t *loc_update_data_create(char *gpsi, char *supi,
                                          pseudonym_indicator_e pseudonym_indicator, location_request_type_e location_request_type, geographic_area_t *location_estimate, int age_of_location_estimate, char *timestamp_of_location_estimate, accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator, civic_address_t *civic_address, lcs_qos_class_e lcs_qos_class, char *external_client_identification, char *af_id, char *gmlc_number, bool is_lcs_service_type,
                                          int lcs_service_type) {
	loc_update_data_t *loc_update_data_local_var =
		malloc(sizeof(loc_update_data_t));

	loc_update_data_local_var->gpsi = gpsi;
	loc_update_data_local_var->supi = supi;
	loc_update_data_local_var->pseudonym_indicator = pseudonym_indicator;
	loc_update_data_local_var->location_request_type =
		location_request_type;
	loc_update_data_local_var->location_estimate = location_estimate;
	loc_update_data_local_var->age_of_location_estimate =
		age_of_location_estimate;
	loc_update_data_local_var->timestamp_of_location_estimate =
		timestamp_of_location_estimate;
	loc_update_data_local_var->accuracy_fulfilment_indicator =
		accuracy_fulfilment_indicator;
	loc_update_data_local_var->civic_address = civic_address;
	loc_update_data_local_var->lcs_qos_class = lcs_qos_class;
	loc_update_data_local_var->external_client_identification =
		external_client_identification;
	loc_update_data_local_var->af_id = af_id;
	loc_update_data_local_var->gmlc_number = gmlc_number;
	loc_update_data_local_var->is_lcs_service_type = is_lcs_service_type;
	loc_update_data_local_var->lcs_service_type = lcs_service_type;

	return loc_update_data_local_var;
}

void loc_update_data_free(loc_update_data_t *loc_update_data) {
	lnode_t *node = NULL;

	if(NULL == loc_update_data) {
		return;
	}
	if(loc_update_data->gpsi) {
		free(loc_update_data->gpsi);
		loc_update_data->gpsi = NULL;
	}
	if(loc_update_data->supi) {
		free(loc_update_data->supi);
		loc_update_data->supi = NULL;
	}
	if(loc_update_data->location_estimate) {
		geographic_area_free(loc_update_data->location_estimate);
		loc_update_data->location_estimate = NULL;
	}
	if(loc_update_data->timestamp_of_location_estimate) {
		free(loc_update_data->timestamp_of_location_estimate);
		loc_update_data->timestamp_of_location_estimate = NULL;
	}
	if(loc_update_data->civic_address) {
		civic_address_free(loc_update_data->civic_address);
		loc_update_data->civic_address = NULL;
	}
	if(loc_update_data->external_client_identification) {
		free(loc_update_data->external_client_identification);
		loc_update_data->external_client_identification = NULL;
	}
	if(loc_update_data->af_id) {
		free(loc_update_data->af_id);
		loc_update_data->af_id = NULL;
	}
	if(loc_update_data->gmlc_number) {
		free(loc_update_data->gmlc_number);
		loc_update_data->gmlc_number = NULL;
	}
	free(loc_update_data);
}

cJSON *loc_update_data_convertToJSON(loc_update_data_t *loc_update_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(loc_update_data == NULL) {
		printf("loc_update_data_convertToJSON() failed [LocUpdateData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(loc_update_data->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           loc_update_data->gpsi) == NULL)
		{
			printf("loc_update_data_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(loc_update_data->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           loc_update_data->supi) == NULL)
		{
			printf("loc_update_data_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(loc_update_data->pseudonym_indicator != pseudonym_indicator_NULL) {
		if(cJSON_AddStringToObject(item, "pseudonymIndicator",
		                           pseudonym_indicator_ToString(
						   loc_update_data->
						   pseudonym_indicator))
		   == NULL)
		{
			printf(
				"loc_update_data_convertToJSON() failed [pseudonym_indicator]");
			goto end;
		}
	}

	if(loc_update_data->location_request_type ==
	   location_request_type_NULL)
	{
		printf(
			"loc_update_data_convertToJSON() failed [location_request_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "locationRequestType",
	                           location_request_type_ToString(
					   loc_update_data->
					   location_request_type))
	   == NULL)
	{
		printf(
			"loc_update_data_convertToJSON() failed [location_request_type]");
		goto end;
	}

	if(!loc_update_data->location_estimate) {
		printf(
			"loc_update_data_convertToJSON() failed [location_estimate]");
		return NULL;
	}
	cJSON *location_estimate_local_JSON = geographic_area_convertToJSON(
		loc_update_data->location_estimate);
	if(location_estimate_local_JSON == NULL) {
		printf(
			"loc_update_data_convertToJSON() failed [location_estimate]");
		goto end;
	}
	cJSON_AddItemToObject(item, "locationEstimate",
	                      location_estimate_local_JSON);
	if(item->child == NULL) {
		printf(
			"loc_update_data_convertToJSON() failed [location_estimate]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "ageOfLocationEstimate",
	                           loc_update_data->age_of_location_estimate) ==
	   NULL)
	{
		printf(
			"loc_update_data_convertToJSON() failed [age_of_location_estimate]");
		goto end;
	}

	if(loc_update_data->timestamp_of_location_estimate) {
		if(cJSON_AddStringToObject(item, "timestampOfLocationEstimate",
		                           loc_update_data->
		                           timestamp_of_location_estimate) ==
		   NULL)
		{
			printf(
				"loc_update_data_convertToJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	if(loc_update_data->accuracy_fulfilment_indicator ==
	   accuracy_fulfilment_indicator_NULL)
	{
		printf(
			"loc_update_data_convertToJSON() failed [accuracy_fulfilment_indicator]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "accuracyFulfilmentIndicator",
	                           accuracy_fulfilment_indicator_ToString(
					   loc_update_data->
					   accuracy_fulfilment_indicator))
	   == NULL)
	{
		printf(
			"loc_update_data_convertToJSON() failed [accuracy_fulfilment_indicator]");
		goto end;
	}

	if(loc_update_data->civic_address) {
		cJSON *civic_address_local_JSON = civic_address_convertToJSON(
			loc_update_data->civic_address);
		if(civic_address_local_JSON == NULL) {
			printf(
				"loc_update_data_convertToJSON() failed [civic_address]");
			goto end;
		}
		cJSON_AddItemToObject(item, "civicAddress",
		                      civic_address_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_update_data_convertToJSON() failed [civic_address]");
			goto end;
		}
	}

	if(loc_update_data->lcs_qos_class == lcs_qos_class_NULL) {
		printf("loc_update_data_convertToJSON() failed [lcs_qos_class]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "lcsQosClass",
	                           lcs_qos_class_ToString(loc_update_data->
	                                                  lcs_qos_class)) ==
	   NULL)
	{
		printf("loc_update_data_convertToJSON() failed [lcs_qos_class]");
		goto end;
	}

	if(loc_update_data->external_client_identification) {
		if(cJSON_AddStringToObject(item, "externalClientIdentification",
		                           loc_update_data->
		                           external_client_identification) ==
		   NULL)
		{
			printf(
				"loc_update_data_convertToJSON() failed [external_client_identification]");
			goto end;
		}
	}

	if(loc_update_data->af_id) {
		if(cJSON_AddStringToObject(item, "afId",
		                           loc_update_data->af_id) == NULL)
		{
			printf("loc_update_data_convertToJSON() failed [af_id]");
			goto end;
		}
	}

	if(loc_update_data->gmlc_number) {
		if(cJSON_AddStringToObject(item, "gmlcNumber",
		                           loc_update_data->gmlc_number) ==
		   NULL)
		{
			printf(
				"loc_update_data_convertToJSON() failed [gmlc_number]");
			goto end;
		}
	}

	if(loc_update_data->is_lcs_service_type) {
		if(cJSON_AddNumberToObject(item, "lcsServiceType",
		                           loc_update_data->lcs_service_type) ==
		   NULL)
		{
			printf(
				"loc_update_data_convertToJSON() failed [lcs_service_type]");
			goto end;
		}
	}

end:
	return item;
}

loc_update_data_t *loc_update_data_parseFromJSON(cJSON *loc_update_dataJSON) {
	loc_update_data_t *loc_update_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *gpsi = NULL;
	cJSON *supi = NULL;
	cJSON *pseudonym_indicator = NULL;
	pseudonym_indicator_e pseudonym_indicatorVariable = 0;
	cJSON *location_request_type = NULL;
	location_request_type_e location_request_typeVariable = 0;
	cJSON *location_estimate = NULL;
	geographic_area_t *location_estimate_local_nonprim = NULL;
	cJSON *age_of_location_estimate = NULL;
	cJSON *timestamp_of_location_estimate = NULL;
	cJSON *accuracy_fulfilment_indicator = NULL;
	accuracy_fulfilment_indicator_e accuracy_fulfilment_indicatorVariable =
		0;
	cJSON *civic_address = NULL;
	civic_address_t *civic_address_local_nonprim = NULL;
	cJSON *lcs_qos_class = NULL;
	lcs_qos_class_e lcs_qos_classVariable = 0;
	cJSON *external_client_identification = NULL;
	cJSON *af_id = NULL;
	cJSON *gmlc_number = NULL;
	cJSON *lcs_service_type = NULL;
	gpsi = cJSON_GetObjectItemCaseSensitive(loc_update_dataJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("loc_update_data_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	supi = cJSON_GetObjectItemCaseSensitive(loc_update_dataJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf("loc_update_data_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	pseudonym_indicator = cJSON_GetObjectItemCaseSensitive(
		loc_update_dataJSON, "pseudonymIndicator");
	if(pseudonym_indicator) {
		if(!cJSON_IsString(pseudonym_indicator)) {
			printf(
				"loc_update_data_parseFromJSON() failed [pseudonym_indicator]");
			goto end;
		}
		pseudonym_indicatorVariable = pseudonym_indicator_FromString(
			pseudonym_indicator->valuestring);
	}

	location_request_type = cJSON_GetObjectItemCaseSensitive(
		loc_update_dataJSON, "locationRequestType");
	if(!location_request_type) {
		printf(
			"loc_update_data_parseFromJSON() failed [location_request_type]");
		goto end;
	}
	if(!cJSON_IsString(location_request_type)) {
		printf(
			"loc_update_data_parseFromJSON() failed [location_request_type]");
		goto end;
	}
	location_request_typeVariable = location_request_type_FromString(
		location_request_type->valuestring);

	location_estimate = cJSON_GetObjectItemCaseSensitive(
		loc_update_dataJSON, "locationEstimate");
	if(!location_estimate) {
		printf(
			"loc_update_data_parseFromJSON() failed [location_estimate]");
		goto end;
	}
	location_estimate_local_nonprim = geographic_area_parseFromJSON(
		location_estimate);
	if(!location_estimate_local_nonprim) {
		printf(
			"geographic_area_parseFromJSON failed [location_estimate]");
		goto end;
	}

	age_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		loc_update_dataJSON, "ageOfLocationEstimate");
	if(!age_of_location_estimate) {
		printf(
			"loc_update_data_parseFromJSON() failed [age_of_location_estimate]");
		goto end;
	}
	if(!cJSON_IsNumber(age_of_location_estimate)) {
		printf(
			"loc_update_data_parseFromJSON() failed [age_of_location_estimate]");
		goto end;
	}

	timestamp_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		loc_update_dataJSON, "timestampOfLocationEstimate");
	if(timestamp_of_location_estimate) {
		if(!cJSON_IsString(timestamp_of_location_estimate) &&
		   !cJSON_IsNull(timestamp_of_location_estimate))
		{
			printf(
				"loc_update_data_parseFromJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	accuracy_fulfilment_indicator = cJSON_GetObjectItemCaseSensitive(
		loc_update_dataJSON, "accuracyFulfilmentIndicator");
	if(!accuracy_fulfilment_indicator) {
		printf(
			"loc_update_data_parseFromJSON() failed [accuracy_fulfilment_indicator]");
		goto end;
	}
	if(!cJSON_IsString(accuracy_fulfilment_indicator)) {
		printf(
			"loc_update_data_parseFromJSON() failed [accuracy_fulfilment_indicator]");
		goto end;
	}
	accuracy_fulfilment_indicatorVariable =
		accuracy_fulfilment_indicator_FromString(
			accuracy_fulfilment_indicator->valuestring);

	civic_address = cJSON_GetObjectItemCaseSensitive(loc_update_dataJSON,
	                                                 "civicAddress");
	if(civic_address) {
		civic_address_local_nonprim = civic_address_parseFromJSON(
			civic_address);
		if(!civic_address_local_nonprim) {
			printf(
				"civic_address_parseFromJSON failed [civic_address]");
			goto end;
		}
	}

	lcs_qos_class = cJSON_GetObjectItemCaseSensitive(loc_update_dataJSON,
	                                                 "lcsQosClass");
	if(!lcs_qos_class) {
		printf("loc_update_data_parseFromJSON() failed [lcs_qos_class]");
		goto end;
	}
	if(!cJSON_IsString(lcs_qos_class)) {
		printf("loc_update_data_parseFromJSON() failed [lcs_qos_class]");
		goto end;
	}
	lcs_qos_classVariable = lcs_qos_class_FromString(
		lcs_qos_class->valuestring);

	external_client_identification = cJSON_GetObjectItemCaseSensitive(
		loc_update_dataJSON, "externalClientIdentification");
	if(external_client_identification) {
		if(!cJSON_IsString(external_client_identification) &&
		   !cJSON_IsNull(external_client_identification))
		{
			printf(
				"loc_update_data_parseFromJSON() failed [external_client_identification]");
			goto end;
		}
	}

	af_id = cJSON_GetObjectItemCaseSensitive(loc_update_dataJSON, "afId");
	if(af_id) {
		if(!cJSON_IsString(af_id) &&
		   !cJSON_IsNull(af_id))
		{
			printf("loc_update_data_parseFromJSON() failed [af_id]");
			goto end;
		}
	}

	gmlc_number = cJSON_GetObjectItemCaseSensitive(loc_update_dataJSON,
	                                               "gmlcNumber");
	if(gmlc_number) {
		if(!cJSON_IsString(gmlc_number) &&
		   !cJSON_IsNull(gmlc_number))
		{
			printf(
				"loc_update_data_parseFromJSON() failed [gmlc_number]");
			goto end;
		}
	}

	lcs_service_type = cJSON_GetObjectItemCaseSensitive(loc_update_dataJSON,
	                                                    "lcsServiceType");
	if(lcs_service_type) {
		if(!cJSON_IsNumber(lcs_service_type)) {
			printf(
				"loc_update_data_parseFromJSON() failed [lcs_service_type]");
			goto end;
		}
	}

	loc_update_data_local_var = loc_update_data_create(
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		pseudonym_indicator ? pseudonym_indicatorVariable : 0,
		location_request_typeVariable,
		location_estimate_local_nonprim,

		age_of_location_estimate->valuedouble,
		timestamp_of_location_estimate &&
		!cJSON_IsNull(timestamp_of_location_estimate) ? strdup(
			timestamp_of_location_estimate->valuestring) : NULL,
		accuracy_fulfilment_indicatorVariable,
		civic_address ? civic_address_local_nonprim : NULL,
		lcs_qos_classVariable,
		external_client_identification &&
		!cJSON_IsNull(external_client_identification) ? strdup(
			external_client_identification->valuestring) : NULL,
		af_id &&
		!cJSON_IsNull(af_id) ? strdup(af_id->valuestring) : NULL,
		gmlc_number &&
		!cJSON_IsNull(gmlc_number) ? strdup(
			gmlc_number->valuestring) : NULL,
		lcs_service_type ? true : false,
		lcs_service_type ? lcs_service_type->valuedouble : 0
		);

	return loc_update_data_local_var;
end:
	if(location_estimate_local_nonprim) {
		geographic_area_free(location_estimate_local_nonprim);
		location_estimate_local_nonprim = NULL;
	}
	if(civic_address_local_nonprim) {
		civic_address_free(civic_address_local_nonprim);
		civic_address_local_nonprim = NULL;
	}
	return NULL;
}

loc_update_data_t *loc_update_data_copy(loc_update_data_t	*dst,
                                        loc_update_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = loc_update_data_convertToJSON(src);
	if(!item) {
		printf("loc_update_data_convertToJSON() failed");
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

	loc_update_data_free(dst);
	dst = loc_update_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
