#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mov_behav_req.h"

mov_behav_req_t *mov_behav_req_create(
	loc_info_granularity_t	*location_gran_req,
	threshold_level_t	*report_thresholds)
{
	mov_behav_req_t *mov_behav_req_local_var = malloc(
		sizeof(mov_behav_req_t));

	mov_behav_req_local_var->location_gran_req = location_gran_req;
	mov_behav_req_local_var->report_thresholds = report_thresholds;

	return mov_behav_req_local_var;
}

void mov_behav_req_free(mov_behav_req_t *mov_behav_req) {
	lnode_t *node = NULL;

	if(NULL == mov_behav_req) {
		return;
	}
	if(mov_behav_req->location_gran_req) {
		loc_info_granularity_free(mov_behav_req->location_gran_req);
		mov_behav_req->location_gran_req = NULL;
	}
	if(mov_behav_req->report_thresholds) {
		threshold_level_free(mov_behav_req->report_thresholds);
		mov_behav_req->report_thresholds = NULL;
	}
	free(mov_behav_req);
}

cJSON *mov_behav_req_convertToJSON(mov_behav_req_t *mov_behav_req) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(mov_behav_req == NULL) {
		printf("mov_behav_req_convertToJSON() failed [MovBehavReq]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(mov_behav_req->location_gran_req) {
		cJSON *location_gran_req_local_JSON =
			loc_info_granularity_convertToJSON(
				mov_behav_req->location_gran_req);
		if(location_gran_req_local_JSON == NULL) {
			printf(
				"mov_behav_req_convertToJSON() failed [location_gran_req]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locationGranReq",
		                      location_gran_req_local_JSON);
		if(item->child == NULL) {
			printf(
				"mov_behav_req_convertToJSON() failed [location_gran_req]");
			goto end;
		}
	}

	if(mov_behav_req->report_thresholds) {
		cJSON *report_thresholds_local_JSON =
			threshold_level_convertToJSON(
				mov_behav_req->report_thresholds);
		if(report_thresholds_local_JSON == NULL) {
			printf(
				"mov_behav_req_convertToJSON() failed [report_thresholds]");
			goto end;
		}
		cJSON_AddItemToObject(item, "reportThresholds",
		                      report_thresholds_local_JSON);
		if(item->child == NULL) {
			printf(
				"mov_behav_req_convertToJSON() failed [report_thresholds]");
			goto end;
		}
	}

end:
	return item;
}

mov_behav_req_t *mov_behav_req_parseFromJSON(cJSON *mov_behav_reqJSON) {
	mov_behav_req_t *mov_behav_req_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *location_gran_req = NULL;
	loc_info_granularity_t *location_gran_req_local_nonprim = NULL;
	cJSON *report_thresholds = NULL;
	threshold_level_t *report_thresholds_local_nonprim = NULL;
	location_gran_req = cJSON_GetObjectItemCaseSensitive(mov_behav_reqJSON,
	                                                     "locationGranReq");
	if(location_gran_req) {
		location_gran_req_local_nonprim =
			loc_info_granularity_parseFromJSON(location_gran_req);
		if(!location_gran_req_local_nonprim) {
			printf(
				"loc_info_granularity_parseFromJSON failed [location_gran_req]");
			goto end;
		}
	}

	report_thresholds = cJSON_GetObjectItemCaseSensitive(mov_behav_reqJSON,
	                                                     "reportThresholds");
	if(report_thresholds) {
		report_thresholds_local_nonprim = threshold_level_parseFromJSON(
			report_thresholds);
		if(!report_thresholds_local_nonprim) {
			printf(
				"threshold_level_parseFromJSON failed [report_thresholds]");
			goto end;
		}
	}

	mov_behav_req_local_var = mov_behav_req_create(
		location_gran_req ? location_gran_req_local_nonprim : NULL,
		report_thresholds ? report_thresholds_local_nonprim : NULL
		);

	return mov_behav_req_local_var;
end:
	if(location_gran_req_local_nonprim) {
		loc_info_granularity_free(location_gran_req_local_nonprim);
		location_gran_req_local_nonprim = NULL;
	}
	if(report_thresholds_local_nonprim) {
		threshold_level_free(report_thresholds_local_nonprim);
		report_thresholds_local_nonprim = NULL;
	}
	return NULL;
}

mov_behav_req_t *mov_behav_req_copy(mov_behav_req_t	*dst,
                                    mov_behav_req_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = mov_behav_req_convertToJSON(src);
	if(!item) {
		printf("mov_behav_req_convertToJSON() failed");
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

	mov_behav_req_free(dst);
	dst = mov_behav_req_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
