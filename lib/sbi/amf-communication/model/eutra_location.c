#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "eutra_location.h"

eutra_location_t *eutra_location_create(tai_t *tai, bool is_ignore_tai,
                                        int ignore_tai, ecgi_t *ecgi,
                                        bool is_ignore_ecgi, int ignore_ecgi,
                                        bool is_age_of_location_information,
                                        int age_of_location_information,
                                        char *ue_location_timestamp,
                                        char *geographical_information,
                                        char *geodetic_information,
                                        global_ran_node_id_t *global_ngenb_id,
                                        global_ran_node_id_t *global_enb_id) {
	eutra_location_t *eutra_location_local_var =
		malloc(sizeof(eutra_location_t));

	eutra_location_local_var->tai = tai;
	eutra_location_local_var->is_ignore_tai = is_ignore_tai;
	eutra_location_local_var->ignore_tai = ignore_tai;
	eutra_location_local_var->ecgi = ecgi;
	eutra_location_local_var->is_ignore_ecgi = is_ignore_ecgi;
	eutra_location_local_var->ignore_ecgi = ignore_ecgi;
	eutra_location_local_var->is_age_of_location_information =
		is_age_of_location_information;
	eutra_location_local_var->age_of_location_information =
		age_of_location_information;
	eutra_location_local_var->ue_location_timestamp = ue_location_timestamp;
	eutra_location_local_var->geographical_information =
		geographical_information;
	eutra_location_local_var->geodetic_information = geodetic_information;
	eutra_location_local_var->global_ngenb_id = global_ngenb_id;
	eutra_location_local_var->global_enb_id = global_enb_id;

	return eutra_location_local_var;
}

void eutra_location_free(eutra_location_t *eutra_location) {
	lnode_t *node = NULL;

	if(NULL == eutra_location) {
		return;
	}
	if(eutra_location->tai) {
		tai_free(eutra_location->tai);
		eutra_location->tai = NULL;
	}
	if(eutra_location->ecgi) {
		ecgi_free(eutra_location->ecgi);
		eutra_location->ecgi = NULL;
	}
	if(eutra_location->ue_location_timestamp) {
		free(eutra_location->ue_location_timestamp);
		eutra_location->ue_location_timestamp = NULL;
	}
	if(eutra_location->geographical_information) {
		free(eutra_location->geographical_information);
		eutra_location->geographical_information = NULL;
	}
	if(eutra_location->geodetic_information) {
		free(eutra_location->geodetic_information);
		eutra_location->geodetic_information = NULL;
	}
	if(eutra_location->global_ngenb_id) {
		global_ran_node_id_free(eutra_location->global_ngenb_id);
		eutra_location->global_ngenb_id = NULL;
	}
	if(eutra_location->global_enb_id) {
		global_ran_node_id_free(eutra_location->global_enb_id);
		eutra_location->global_enb_id = NULL;
	}
	free(eutra_location);
}

cJSON *eutra_location_convertToJSON(eutra_location_t *eutra_location) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(eutra_location == NULL) {
		printf("eutra_location_convertToJSON() failed [EutraLocation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!eutra_location->tai) {
		printf("eutra_location_convertToJSON() failed [tai]");
		return NULL;
	}
	cJSON *tai_local_JSON = tai_convertToJSON(eutra_location->tai);
	if(tai_local_JSON == NULL) {
		printf("eutra_location_convertToJSON() failed [tai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "tai", tai_local_JSON);
	if(item->child == NULL) {
		printf("eutra_location_convertToJSON() failed [tai]");
		goto end;
	}

	if(eutra_location->is_ignore_tai) {
		if(cJSON_AddBoolToObject(item, "ignoreTai",
		                         eutra_location->ignore_tai) == NULL)
		{
			printf(
				"eutra_location_convertToJSON() failed [ignore_tai]");
			goto end;
		}
	}

	if(!eutra_location->ecgi) {
		printf("eutra_location_convertToJSON() failed [ecgi]");
		return NULL;
	}
	cJSON *ecgi_local_JSON = ecgi_convertToJSON(eutra_location->ecgi);
	if(ecgi_local_JSON == NULL) {
		printf("eutra_location_convertToJSON() failed [ecgi]");
		goto end;
	}
	cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
	if(item->child == NULL) {
		printf("eutra_location_convertToJSON() failed [ecgi]");
		goto end;
	}

	if(eutra_location->is_ignore_ecgi) {
		if(cJSON_AddBoolToObject(item, "ignoreEcgi",
		                         eutra_location->ignore_ecgi) == NULL)
		{
			printf(
				"eutra_location_convertToJSON() failed [ignore_ecgi]");
			goto end;
		}
	}

	if(eutra_location->is_age_of_location_information) {
		if(cJSON_AddNumberToObject(item, "ageOfLocationInformation",
		                           eutra_location->
		                           age_of_location_information) == NULL)
		{
			printf(
				"eutra_location_convertToJSON() failed [age_of_location_information]");
			goto end;
		}
	}

	if(eutra_location->ue_location_timestamp) {
		if(cJSON_AddStringToObject(item, "ueLocationTimestamp",
		                           eutra_location->ue_location_timestamp)
		   == NULL)
		{
			printf(
				"eutra_location_convertToJSON() failed [ue_location_timestamp]");
			goto end;
		}
	}

	if(eutra_location->geographical_information) {
		if(cJSON_AddStringToObject(item, "geographicalInformation",
		                           eutra_location->
		                           geographical_information) == NULL)
		{
			printf(
				"eutra_location_convertToJSON() failed [geographical_information]");
			goto end;
		}
	}

	if(eutra_location->geodetic_information) {
		if(cJSON_AddStringToObject(item, "geodeticInformation",
		                           eutra_location->geodetic_information)
		   == NULL)
		{
			printf(
				"eutra_location_convertToJSON() failed [geodetic_information]");
			goto end;
		}
	}

	if(eutra_location->global_ngenb_id) {
		cJSON *global_ngenb_id_local_JSON =
			global_ran_node_id_convertToJSON(
				eutra_location->global_ngenb_id);
		if(global_ngenb_id_local_JSON == NULL) {
			printf(
				"eutra_location_convertToJSON() failed [global_ngenb_id]");
			goto end;
		}
		cJSON_AddItemToObject(item, "globalNgenbId",
		                      global_ngenb_id_local_JSON);
		if(item->child == NULL) {
			printf(
				"eutra_location_convertToJSON() failed [global_ngenb_id]");
			goto end;
		}
	}

	if(eutra_location->global_enb_id) {
		cJSON *global_enb_id_local_JSON =
			global_ran_node_id_convertToJSON(
				eutra_location->global_enb_id);
		if(global_enb_id_local_JSON == NULL) {
			printf(
				"eutra_location_convertToJSON() failed [global_enb_id]");
			goto end;
		}
		cJSON_AddItemToObject(item, "globalENbId",
		                      global_enb_id_local_JSON);
		if(item->child == NULL) {
			printf(
				"eutra_location_convertToJSON() failed [global_enb_id]");
			goto end;
		}
	}

end:
	return item;
}

eutra_location_t *eutra_location_parseFromJSON(cJSON *eutra_locationJSON) {
	eutra_location_t *eutra_location_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *tai = NULL;
	tai_t *tai_local_nonprim = NULL;
	cJSON *ignore_tai = NULL;
	cJSON *ecgi = NULL;
	ecgi_t *ecgi_local_nonprim = NULL;
	cJSON *ignore_ecgi = NULL;
	cJSON *age_of_location_information = NULL;
	cJSON *ue_location_timestamp = NULL;
	cJSON *geographical_information = NULL;
	cJSON *geodetic_information = NULL;
	cJSON *global_ngenb_id = NULL;
	global_ran_node_id_t *global_ngenb_id_local_nonprim = NULL;
	cJSON *global_enb_id = NULL;
	global_ran_node_id_t *global_enb_id_local_nonprim = NULL;
	tai = cJSON_GetObjectItemCaseSensitive(eutra_locationJSON, "tai");
	if(!tai) {
		printf("eutra_location_parseFromJSON() failed [tai]");
		goto end;
	}
	tai_local_nonprim = tai_parseFromJSON(tai);
	if(!tai_local_nonprim) {
		printf("tai_parseFromJSON failed [tai]");
		goto end;
	}

	ignore_tai = cJSON_GetObjectItemCaseSensitive(eutra_locationJSON,
	                                              "ignoreTai");
	if(ignore_tai) {
		if(!cJSON_IsBool(ignore_tai)) {
			printf(
				"eutra_location_parseFromJSON() failed [ignore_tai]");
			goto end;
		}
	}

	ecgi = cJSON_GetObjectItemCaseSensitive(eutra_locationJSON, "ecgi");
	if(!ecgi) {
		printf("eutra_location_parseFromJSON() failed [ecgi]");
		goto end;
	}
	ecgi_local_nonprim = ecgi_parseFromJSON(ecgi);
	if(!ecgi_local_nonprim) {
		printf("ecgi_parseFromJSON failed [ecgi]");
		goto end;
	}

	ignore_ecgi = cJSON_GetObjectItemCaseSensitive(eutra_locationJSON,
	                                               "ignoreEcgi");
	if(ignore_ecgi) {
		if(!cJSON_IsBool(ignore_ecgi)) {
			printf(
				"eutra_location_parseFromJSON() failed [ignore_ecgi]");
			goto end;
		}
	}

	age_of_location_information = cJSON_GetObjectItemCaseSensitive(
		eutra_locationJSON, "ageOfLocationInformation");
	if(age_of_location_information) {
		if(!cJSON_IsNumber(age_of_location_information)) {
			printf(
				"eutra_location_parseFromJSON() failed [age_of_location_information]");
			goto end;
		}
	}

	ue_location_timestamp = cJSON_GetObjectItemCaseSensitive(
		eutra_locationJSON, "ueLocationTimestamp");
	if(ue_location_timestamp) {
		if(!cJSON_IsString(ue_location_timestamp) &&
		   !cJSON_IsNull(ue_location_timestamp))
		{
			printf(
				"eutra_location_parseFromJSON() failed [ue_location_timestamp]");
			goto end;
		}
	}

	geographical_information = cJSON_GetObjectItemCaseSensitive(
		eutra_locationJSON, "geographicalInformation");
	if(geographical_information) {
		if(!cJSON_IsString(geographical_information) &&
		   !cJSON_IsNull(geographical_information))
		{
			printf(
				"eutra_location_parseFromJSON() failed [geographical_information]");
			goto end;
		}
	}

	geodetic_information = cJSON_GetObjectItemCaseSensitive(
		eutra_locationJSON, "geodeticInformation");
	if(geodetic_information) {
		if(!cJSON_IsString(geodetic_information) &&
		   !cJSON_IsNull(geodetic_information))
		{
			printf(
				"eutra_location_parseFromJSON() failed [geodetic_information]");
			goto end;
		}
	}

	global_ngenb_id = cJSON_GetObjectItemCaseSensitive(eutra_locationJSON,
	                                                   "globalNgenbId");
	if(global_ngenb_id) {
		global_ngenb_id_local_nonprim =
			global_ran_node_id_parseFromJSON(global_ngenb_id);
		if(!global_ngenb_id_local_nonprim) {
			printf(
				"global_ran_node_id_parseFromJSON failed [global_ngenb_id]");
			goto end;
		}
	}

	global_enb_id = cJSON_GetObjectItemCaseSensitive(eutra_locationJSON,
	                                                 "globalENbId");
	if(global_enb_id) {
		global_enb_id_local_nonprim = global_ran_node_id_parseFromJSON(
			global_enb_id);
		if(!global_enb_id_local_nonprim) {
			printf(
				"global_ran_node_id_parseFromJSON failed [global_enb_id]");
			goto end;
		}
	}

	eutra_location_local_var = eutra_location_create(
		tai_local_nonprim,
		ignore_tai ? true : false,
		ignore_tai ? ignore_tai->valueint : 0,
		ecgi_local_nonprim,
		ignore_ecgi ? true : false,
		ignore_ecgi ? ignore_ecgi->valueint : 0,
		age_of_location_information ? true : false,
		age_of_location_information ? age_of_location_information->valuedouble : 0,
		ue_location_timestamp &&
		!cJSON_IsNull(ue_location_timestamp) ? strdup(
			ue_location_timestamp->valuestring) : NULL,
		geographical_information &&
		!cJSON_IsNull(geographical_information) ? strdup(
			geographical_information->valuestring) : NULL,
		geodetic_information &&
		!cJSON_IsNull(geodetic_information) ? strdup(
			geodetic_information->valuestring) : NULL,
		global_ngenb_id ? global_ngenb_id_local_nonprim : NULL,
		global_enb_id ? global_enb_id_local_nonprim : NULL
		);

	return eutra_location_local_var;
end:
	if(tai_local_nonprim) {
		tai_free(tai_local_nonprim);
		tai_local_nonprim = NULL;
	}
	if(ecgi_local_nonprim) {
		ecgi_free(ecgi_local_nonprim);
		ecgi_local_nonprim = NULL;
	}
	if(global_ngenb_id_local_nonprim) {
		global_ran_node_id_free(global_ngenb_id_local_nonprim);
		global_ngenb_id_local_nonprim = NULL;
	}
	if(global_enb_id_local_nonprim) {
		global_ran_node_id_free(global_enb_id_local_nonprim);
		global_enb_id_local_nonprim = NULL;
	}
	return NULL;
}

eutra_location_t *eutra_location_copy(eutra_location_t	*dst,
                                      eutra_location_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = eutra_location_convertToJSON(src);
	if(!item) {
		printf("eutra_location_convertToJSON() failed");
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

	eutra_location_free(dst);
	dst = eutra_location_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
