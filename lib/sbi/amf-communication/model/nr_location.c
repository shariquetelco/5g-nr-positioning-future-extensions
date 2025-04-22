#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nr_location.h"

nr_location_t *nr_location_create(tai_t *tai, ncgi_t *ncgi, bool is_ignore_ncgi,
                                  int ignore_ncgi,
                                  bool is_age_of_location_information,
                                  int age_of_location_information,
                                  char *ue_location_timestamp,
                                  char *geographical_information,
                                  char *geodetic_information,
                                  global_ran_node_id_t *global_gnb_id,
                                  ntn_tai_info_t *ntn_tai_info) {
	nr_location_t *nr_location_local_var = malloc(sizeof(nr_location_t));

	nr_location_local_var->tai = tai;
	nr_location_local_var->ncgi = ncgi;
	nr_location_local_var->is_ignore_ncgi = is_ignore_ncgi;
	nr_location_local_var->ignore_ncgi = ignore_ncgi;
	nr_location_local_var->is_age_of_location_information =
		is_age_of_location_information;
	nr_location_local_var->age_of_location_information =
		age_of_location_information;
	nr_location_local_var->ue_location_timestamp = ue_location_timestamp;
	nr_location_local_var->geographical_information =
		geographical_information;
	nr_location_local_var->geodetic_information = geodetic_information;
	nr_location_local_var->global_gnb_id = global_gnb_id;
	nr_location_local_var->ntn_tai_info = ntn_tai_info;

	return nr_location_local_var;
}

void nr_location_free(nr_location_t *nr_location) {
	lnode_t *node = NULL;

	if(NULL == nr_location) {
		return;
	}
	if(nr_location->tai) {
		tai_free(nr_location->tai);
		nr_location->tai = NULL;
	}
	if(nr_location->ncgi) {
		ncgi_free(nr_location->ncgi);
		nr_location->ncgi = NULL;
	}
	if(nr_location->ue_location_timestamp) {
		free(nr_location->ue_location_timestamp);
		nr_location->ue_location_timestamp = NULL;
	}
	if(nr_location->geographical_information) {
		free(nr_location->geographical_information);
		nr_location->geographical_information = NULL;
	}
	if(nr_location->geodetic_information) {
		free(nr_location->geodetic_information);
		nr_location->geodetic_information = NULL;
	}
	if(nr_location->global_gnb_id) {
		global_ran_node_id_free(nr_location->global_gnb_id);
		nr_location->global_gnb_id = NULL;
	}
	if(nr_location->ntn_tai_info) {
		ntn_tai_info_free(nr_location->ntn_tai_info);
		nr_location->ntn_tai_info = NULL;
	}
	free(nr_location);
}

cJSON *nr_location_convertToJSON(nr_location_t *nr_location) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nr_location == NULL) {
		printf("nr_location_convertToJSON() failed [NrLocation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!nr_location->tai) {
		printf("nr_location_convertToJSON() failed [tai]");
		return NULL;
	}
	cJSON *tai_local_JSON = tai_convertToJSON(nr_location->tai);
	if(tai_local_JSON == NULL) {
		printf("nr_location_convertToJSON() failed [tai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "tai", tai_local_JSON);
	if(item->child == NULL) {
		printf("nr_location_convertToJSON() failed [tai]");
		goto end;
	}

	if(!nr_location->ncgi) {
		printf("nr_location_convertToJSON() failed [ncgi]");
		return NULL;
	}
	cJSON *ncgi_local_JSON = ncgi_convertToJSON(nr_location->ncgi);
	if(ncgi_local_JSON == NULL) {
		printf("nr_location_convertToJSON() failed [ncgi]");
		goto end;
	}
	cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
	if(item->child == NULL) {
		printf("nr_location_convertToJSON() failed [ncgi]");
		goto end;
	}

	if(nr_location->is_ignore_ncgi) {
		if(cJSON_AddBoolToObject(item, "ignoreNcgi",
		                         nr_location->ignore_ncgi) == NULL)
		{
			printf(
				"nr_location_convertToJSON() failed [ignore_ncgi]");
			goto end;
		}
	}

	if(nr_location->is_age_of_location_information) {
		if(cJSON_AddNumberToObject(item, "ageOfLocationInformation",
		                           nr_location->
		                           age_of_location_information) == NULL)
		{
			printf(
				"nr_location_convertToJSON() failed [age_of_location_information]");
			goto end;
		}
	}

	if(nr_location->ue_location_timestamp) {
		if(cJSON_AddStringToObject(item, "ueLocationTimestamp",
		                           nr_location->ue_location_timestamp)
		   == NULL)
		{
			printf(
				"nr_location_convertToJSON() failed [ue_location_timestamp]");
			goto end;
		}
	}

	if(nr_location->geographical_information) {
		if(cJSON_AddStringToObject(item, "geographicalInformation",
		                           nr_location->geographical_information)
		   == NULL)
		{
			printf(
				"nr_location_convertToJSON() failed [geographical_information]");
			goto end;
		}
	}

	if(nr_location->geodetic_information) {
		if(cJSON_AddStringToObject(item, "geodeticInformation",
		                           nr_location->geodetic_information) ==
		   NULL)
		{
			printf(
				"nr_location_convertToJSON() failed [geodetic_information]");
			goto end;
		}
	}

	if(nr_location->global_gnb_id) {
		cJSON *global_gnb_id_local_JSON =
			global_ran_node_id_convertToJSON(
				nr_location->global_gnb_id);
		if(global_gnb_id_local_JSON == NULL) {
			printf(
				"nr_location_convertToJSON() failed [global_gnb_id]");
			goto end;
		}
		cJSON_AddItemToObject(item, "globalGnbId",
		                      global_gnb_id_local_JSON);
		if(item->child == NULL) {
			printf(
				"nr_location_convertToJSON() failed [global_gnb_id]");
			goto end;
		}
	}

	if(nr_location->ntn_tai_info) {
		cJSON *ntn_tai_info_local_JSON = ntn_tai_info_convertToJSON(
			nr_location->ntn_tai_info);
		if(ntn_tai_info_local_JSON == NULL) {
			printf(
				"nr_location_convertToJSON() failed [ntn_tai_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ntnTaiInfo",
		                      ntn_tai_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"nr_location_convertToJSON() failed [ntn_tai_info]");
			goto end;
		}
	}

end:
	return item;
}

nr_location_t *nr_location_parseFromJSON(cJSON *nr_locationJSON) {
	nr_location_t *nr_location_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *tai = NULL;
	tai_t *tai_local_nonprim = NULL;
	cJSON *ncgi = NULL;
	ncgi_t *ncgi_local_nonprim = NULL;
	cJSON *ignore_ncgi = NULL;
	cJSON *age_of_location_information = NULL;
	cJSON *ue_location_timestamp = NULL;
	cJSON *geographical_information = NULL;
	cJSON *geodetic_information = NULL;
	cJSON *global_gnb_id = NULL;
	global_ran_node_id_t *global_gnb_id_local_nonprim = NULL;
	cJSON *ntn_tai_info = NULL;
	ntn_tai_info_t *ntn_tai_info_local_nonprim = NULL;
	tai = cJSON_GetObjectItemCaseSensitive(nr_locationJSON, "tai");
	if(!tai) {
		printf("nr_location_parseFromJSON() failed [tai]");
		goto end;
	}
	tai_local_nonprim = tai_parseFromJSON(tai);
	if(!tai_local_nonprim) {
		printf("tai_parseFromJSON failed [tai]");
		goto end;
	}

	ncgi = cJSON_GetObjectItemCaseSensitive(nr_locationJSON, "ncgi");
	if(!ncgi) {
		printf("nr_location_parseFromJSON() failed [ncgi]");
		goto end;
	}
	ncgi_local_nonprim = ncgi_parseFromJSON(ncgi);
	if(!ncgi_local_nonprim) {
		printf("ncgi_parseFromJSON failed [ncgi]");
		goto end;
	}

	ignore_ncgi = cJSON_GetObjectItemCaseSensitive(nr_locationJSON,
	                                               "ignoreNcgi");
	if(ignore_ncgi) {
		if(!cJSON_IsBool(ignore_ncgi)) {
			printf(
				"nr_location_parseFromJSON() failed [ignore_ncgi]");
			goto end;
		}
	}

	age_of_location_information = cJSON_GetObjectItemCaseSensitive(
		nr_locationJSON, "ageOfLocationInformation");
	if(age_of_location_information) {
		if(!cJSON_IsNumber(age_of_location_information)) {
			printf(
				"nr_location_parseFromJSON() failed [age_of_location_information]");
			goto end;
		}
	}

	ue_location_timestamp = cJSON_GetObjectItemCaseSensitive(
		nr_locationJSON, "ueLocationTimestamp");
	if(ue_location_timestamp) {
		if(!cJSON_IsString(ue_location_timestamp) &&
		   !cJSON_IsNull(ue_location_timestamp))
		{
			printf(
				"nr_location_parseFromJSON() failed [ue_location_timestamp]");
			goto end;
		}
	}

	geographical_information = cJSON_GetObjectItemCaseSensitive(
		nr_locationJSON, "geographicalInformation");
	if(geographical_information) {
		if(!cJSON_IsString(geographical_information) &&
		   !cJSON_IsNull(geographical_information))
		{
			printf(
				"nr_location_parseFromJSON() failed [geographical_information]");
			goto end;
		}
	}

	geodetic_information = cJSON_GetObjectItemCaseSensitive(nr_locationJSON,
	                                                        "geodeticInformation");
	if(geodetic_information) {
		if(!cJSON_IsString(geodetic_information) &&
		   !cJSON_IsNull(geodetic_information))
		{
			printf(
				"nr_location_parseFromJSON() failed [geodetic_information]");
			goto end;
		}
	}

	global_gnb_id = cJSON_GetObjectItemCaseSensitive(nr_locationJSON,
	                                                 "globalGnbId");
	if(global_gnb_id) {
		global_gnb_id_local_nonprim = global_ran_node_id_parseFromJSON(
			global_gnb_id);
		if(!global_gnb_id_local_nonprim) {
			printf(
				"global_ran_node_id_parseFromJSON failed [global_gnb_id]");
			goto end;
		}
	}

	ntn_tai_info = cJSON_GetObjectItemCaseSensitive(nr_locationJSON,
	                                                "ntnTaiInfo");
	if(ntn_tai_info) {
		ntn_tai_info_local_nonprim = ntn_tai_info_parseFromJSON(
			ntn_tai_info);
		if(!ntn_tai_info_local_nonprim) {
			printf(
				"ntn_tai_info_parseFromJSON failed [ntn_tai_info]");
			goto end;
		}
	}

	nr_location_local_var = nr_location_create(
		tai_local_nonprim,
		ncgi_local_nonprim,
		ignore_ncgi ? true : false,
		ignore_ncgi ? ignore_ncgi->valueint : 0,
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
		global_gnb_id ? global_gnb_id_local_nonprim : NULL,
		ntn_tai_info ? ntn_tai_info_local_nonprim : NULL
		);

	return nr_location_local_var;
end:
	if(tai_local_nonprim) {
		tai_free(tai_local_nonprim);
		tai_local_nonprim = NULL;
	}
	if(ncgi_local_nonprim) {
		ncgi_free(ncgi_local_nonprim);
		ncgi_local_nonprim = NULL;
	}
	if(global_gnb_id_local_nonprim) {
		global_ran_node_id_free(global_gnb_id_local_nonprim);
		global_gnb_id_local_nonprim = NULL;
	}
	if(ntn_tai_info_local_nonprim) {
		ntn_tai_info_free(ntn_tai_info_local_nonprim);
		ntn_tai_info_local_nonprim = NULL;
	}
	return NULL;
}

nr_location_t *nr_location_copy(nr_location_t *dst, nr_location_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nr_location_convertToJSON(src);
	if(!item) {
		printf("nr_location_convertToJSON() failed");
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

	nr_location_free(dst);
	dst = nr_location_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
