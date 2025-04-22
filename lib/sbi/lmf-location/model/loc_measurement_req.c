#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_measurement_req.h"

loc_measurement_req_t *loc_measurement_req_create(ncgi_t *ncgi, ecgi_t *ecgi,
                                                  geographic_area_t *pre_calcu_loc_estimate, char *timestamp_of_pre_calcu_loc_estimate,
                                                  list_t *time_windows) {
	loc_measurement_req_t *loc_measurement_req_local_var =
		malloc(sizeof(loc_measurement_req_t));

	loc_measurement_req_local_var->ncgi = ncgi;
	loc_measurement_req_local_var->ecgi = ecgi;
	loc_measurement_req_local_var->pre_calcu_loc_estimate =
		pre_calcu_loc_estimate;
	loc_measurement_req_local_var->timestamp_of_pre_calcu_loc_estimate =
		timestamp_of_pre_calcu_loc_estimate;
	loc_measurement_req_local_var->time_windows = time_windows;

	return loc_measurement_req_local_var;
}

void loc_measurement_req_free(loc_measurement_req_t *loc_measurement_req) {
	lnode_t *node = NULL;

	if(NULL == loc_measurement_req) {
		return;
	}
	if(loc_measurement_req->ncgi) {
		ncgi_free(loc_measurement_req->ncgi);
		loc_measurement_req->ncgi = NULL;
	}
	if(loc_measurement_req->ecgi) {
		ecgi_free(loc_measurement_req->ecgi);
		loc_measurement_req->ecgi = NULL;
	}
	if(loc_measurement_req->pre_calcu_loc_estimate) {
		geographic_area_free(loc_measurement_req->pre_calcu_loc_estimate);
		loc_measurement_req->pre_calcu_loc_estimate = NULL;
	}
	if(loc_measurement_req->timestamp_of_pre_calcu_loc_estimate) {
		free(loc_measurement_req->timestamp_of_pre_calcu_loc_estimate);
		loc_measurement_req->timestamp_of_pre_calcu_loc_estimate = NULL;
	}
	if(loc_measurement_req->time_windows) {
		list_for_each(loc_measurement_req->time_windows, node) {
			free(node->data);
		}
		list_free(loc_measurement_req->time_windows);
		loc_measurement_req->time_windows = NULL;
	}
	free(loc_measurement_req);
}

cJSON *loc_measurement_req_convertToJSON(
	loc_measurement_req_t *loc_measurement_req) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(loc_measurement_req == NULL) {
		printf(
			"loc_measurement_req_convertToJSON() failed [LocMeasurementReq]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(loc_measurement_req->ncgi) {
		cJSON *ncgi_local_JSON = ncgi_convertToJSON(
			loc_measurement_req->ncgi);
		if(ncgi_local_JSON == NULL) {
			printf(
				"loc_measurement_req_convertToJSON() failed [ncgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_measurement_req_convertToJSON() failed [ncgi]");
			goto end;
		}
	}

	if(loc_measurement_req->ecgi) {
		cJSON *ecgi_local_JSON = ecgi_convertToJSON(
			loc_measurement_req->ecgi);
		if(ecgi_local_JSON == NULL) {
			printf(
				"loc_measurement_req_convertToJSON() failed [ecgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_measurement_req_convertToJSON() failed [ecgi]");
			goto end;
		}
	}

	if(loc_measurement_req->pre_calcu_loc_estimate) {
		cJSON *pre_calcu_loc_estimate_local_JSON =
			geographic_area_convertToJSON(
				loc_measurement_req->pre_calcu_loc_estimate);
		if(pre_calcu_loc_estimate_local_JSON == NULL) {
			printf(
				"loc_measurement_req_convertToJSON() failed [pre_calcu_loc_estimate]");
			goto end;
		}
		cJSON_AddItemToObject(item, "preCalcuLocEstimate",
		                      pre_calcu_loc_estimate_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_measurement_req_convertToJSON() failed [pre_calcu_loc_estimate]");
			goto end;
		}
	}

	if(loc_measurement_req->timestamp_of_pre_calcu_loc_estimate) {
		if(cJSON_AddStringToObject(item,
		                           "timestampOfPreCalcuLocEstimate",
		                           loc_measurement_req->
		                           timestamp_of_pre_calcu_loc_estimate)
		   ==
		   NULL)
		{
			printf(
				"loc_measurement_req_convertToJSON() failed [timestamp_of_pre_calcu_loc_estimate]");
			goto end;
		}
	}

	if(loc_measurement_req->time_windows) {
		cJSON *time_windowsList = cJSON_AddArrayToObject(item,
		                                                 "timeWindows");
		if(time_windowsList == NULL) {
			printf(
				"loc_measurement_req_convertToJSON() failed [time_windows]");
			goto end;
		}
		list_for_each(loc_measurement_req->time_windows, node) {
			if(cJSON_AddStringToObject(time_windowsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"loc_measurement_req_convertToJSON() failed [time_windows]");
				goto end;
			}
		}
	}

end:
	return item;
}

loc_measurement_req_t *loc_measurement_req_parseFromJSON(
	cJSON *loc_measurement_reqJSON) {
	loc_measurement_req_t *loc_measurement_req_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ncgi = NULL;
	ncgi_t *ncgi_local_nonprim = NULL;
	cJSON *ecgi = NULL;
	ecgi_t *ecgi_local_nonprim = NULL;
	cJSON *pre_calcu_loc_estimate = NULL;
	geographic_area_t *pre_calcu_loc_estimate_local_nonprim = NULL;
	cJSON *timestamp_of_pre_calcu_loc_estimate = NULL;
	cJSON *time_windows = NULL;
	list_t *time_windowsList = NULL;
	ncgi =
		cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON,
		                                 "ncgi");
	if(ncgi) {
		ncgi_local_nonprim = ncgi_parseFromJSON(ncgi);
		if(!ncgi_local_nonprim) {
			printf("ncgi_parseFromJSON failed [ncgi]");
			goto end;
		}
	}

	ecgi =
		cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON,
		                                 "ecgi");
	if(ecgi) {
		ecgi_local_nonprim = ecgi_parseFromJSON(ecgi);
		if(!ecgi_local_nonprim) {
			printf("ecgi_parseFromJSON failed [ecgi]");
			goto end;
		}
	}

	pre_calcu_loc_estimate = cJSON_GetObjectItemCaseSensitive(
		loc_measurement_reqJSON, "preCalcuLocEstimate");
	if(pre_calcu_loc_estimate) {
		pre_calcu_loc_estimate_local_nonprim =
			geographic_area_parseFromJSON(pre_calcu_loc_estimate);
		if(!pre_calcu_loc_estimate_local_nonprim) {
			printf(
				"geographic_area_parseFromJSON failed [pre_calcu_loc_estimate]");
			goto end;
		}
	}

	timestamp_of_pre_calcu_loc_estimate = cJSON_GetObjectItemCaseSensitive(
		loc_measurement_reqJSON, "timestampOfPreCalcuLocEstimate");
	if(timestamp_of_pre_calcu_loc_estimate) {
		if(!cJSON_IsString(timestamp_of_pre_calcu_loc_estimate) &&
		   !cJSON_IsNull(timestamp_of_pre_calcu_loc_estimate))
		{
			printf(
				"loc_measurement_req_parseFromJSON() failed [timestamp_of_pre_calcu_loc_estimate]");
			goto end;
		}
	}

	time_windows = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON,
	                                                "timeWindows");
	if(time_windows) {
		cJSON *time_windows_local = NULL;
		if(!cJSON_IsArray(time_windows)) {
			printf(
				"loc_measurement_req_parseFromJSON() failed [time_windows]");
			goto end;
		}

		time_windowsList = list_create();

		cJSON_ArrayForEach(time_windows_local, time_windows) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(time_windows_local)) {
				printf(
					"loc_measurement_req_parseFromJSON() failed [time_windows]");
				goto end;
			}
			list_add(time_windowsList,
			         strdup(time_windows_local->valuestring));
		}
	}

	loc_measurement_req_local_var = loc_measurement_req_create(
		ncgi ? ncgi_local_nonprim : NULL,
		ecgi ? ecgi_local_nonprim : NULL,
		pre_calcu_loc_estimate ? pre_calcu_loc_estimate_local_nonprim : NULL,
		timestamp_of_pre_calcu_loc_estimate &&
		!cJSON_IsNull(timestamp_of_pre_calcu_loc_estimate) ? strdup(
			timestamp_of_pre_calcu_loc_estimate->valuestring) : NULL,
		time_windows ? time_windowsList : NULL
		);

	return loc_measurement_req_local_var;
end:
	if(ncgi_local_nonprim) {
		ncgi_free(ncgi_local_nonprim);
		ncgi_local_nonprim = NULL;
	}
	if(ecgi_local_nonprim) {
		ecgi_free(ecgi_local_nonprim);
		ecgi_local_nonprim = NULL;
	}
	if(pre_calcu_loc_estimate_local_nonprim) {
		geographic_area_free(pre_calcu_loc_estimate_local_nonprim);
		pre_calcu_loc_estimate_local_nonprim = NULL;
	}
	if(time_windowsList) {
		list_for_each(time_windowsList, node) {
			free(node->data);
		}
		list_free(time_windowsList);
		time_windowsList = NULL;
	}
	return NULL;
}

loc_measurement_req_t *loc_measurement_req_copy(loc_measurement_req_t	*dst,
                                                loc_measurement_req_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = loc_measurement_req_convertToJSON(src);
	if(!item) {
		printf("loc_measurement_req_convertToJSON() failed");
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

	loc_measurement_req_free(dst);
	dst = loc_measurement_req_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
