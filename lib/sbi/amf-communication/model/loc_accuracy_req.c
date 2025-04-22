#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_accuracy_req.h"

loc_accuracy_req_t *loc_accuracy_req_create(bool is_acc_thres, int acc_thres,
                                            matching_direction_t *acc_thres_match_dir, bool is_in_out_thres, int in_out_thres, matching_direction_t *in_out_thres_match_dir,
                                            positioning_method_t *pos_method) {
	loc_accuracy_req_t *loc_accuracy_req_local_var =
		malloc(sizeof(loc_accuracy_req_t));

	loc_accuracy_req_local_var->is_acc_thres = is_acc_thres;
	loc_accuracy_req_local_var->acc_thres = acc_thres;
	loc_accuracy_req_local_var->acc_thres_match_dir = acc_thres_match_dir;
	loc_accuracy_req_local_var->is_in_out_thres = is_in_out_thres;
	loc_accuracy_req_local_var->in_out_thres = in_out_thres;
	loc_accuracy_req_local_var->in_out_thres_match_dir =
		in_out_thres_match_dir;
	loc_accuracy_req_local_var->pos_method = pos_method;

	return loc_accuracy_req_local_var;
}

void loc_accuracy_req_free(loc_accuracy_req_t *loc_accuracy_req) {
	lnode_t *node = NULL;

	if(NULL == loc_accuracy_req) {
		return;
	}
	if(loc_accuracy_req->acc_thres_match_dir) {
		matching_direction_free(loc_accuracy_req->acc_thres_match_dir);
		loc_accuracy_req->acc_thres_match_dir = NULL;
	}
	if(loc_accuracy_req->in_out_thres_match_dir) {
		matching_direction_free(loc_accuracy_req->in_out_thres_match_dir);
		loc_accuracy_req->in_out_thres_match_dir = NULL;
	}
	if(loc_accuracy_req->pos_method) {
		positioning_method_free(loc_accuracy_req->pos_method);
		loc_accuracy_req->pos_method = NULL;
	}
	free(loc_accuracy_req);
}

cJSON *loc_accuracy_req_convertToJSON(loc_accuracy_req_t *loc_accuracy_req) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(loc_accuracy_req == NULL) {
		printf(
			"loc_accuracy_req_convertToJSON() failed [LocAccuracyReq]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(loc_accuracy_req->is_acc_thres) {
		if(cJSON_AddNumberToObject(item, "accThres",
		                           loc_accuracy_req->acc_thres) == NULL)
		{
			printf(
				"loc_accuracy_req_convertToJSON() failed [acc_thres]");
			goto end;
		}
	}

	if(loc_accuracy_req->acc_thres_match_dir) {
		cJSON *acc_thres_match_dir_local_JSON =
			matching_direction_convertToJSON(
				loc_accuracy_req->acc_thres_match_dir);
		if(acc_thres_match_dir_local_JSON == NULL) {
			printf(
				"loc_accuracy_req_convertToJSON() failed [acc_thres_match_dir]");
			goto end;
		}
		cJSON_AddItemToObject(item, "accThresMatchDir",
		                      acc_thres_match_dir_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_accuracy_req_convertToJSON() failed [acc_thres_match_dir]");
			goto end;
		}
	}

	if(loc_accuracy_req->is_in_out_thres) {
		if(cJSON_AddNumberToObject(item, "inOutThres",
		                           loc_accuracy_req->in_out_thres) ==
		   NULL)
		{
			printf(
				"loc_accuracy_req_convertToJSON() failed [in_out_thres]");
			goto end;
		}
	}

	if(loc_accuracy_req->in_out_thres_match_dir) {
		cJSON *in_out_thres_match_dir_local_JSON =
			matching_direction_convertToJSON(
				loc_accuracy_req->in_out_thres_match_dir);
		if(in_out_thres_match_dir_local_JSON == NULL) {
			printf(
				"loc_accuracy_req_convertToJSON() failed [in_out_thres_match_dir]");
			goto end;
		}
		cJSON_AddItemToObject(item, "inOutThresMatchDir",
		                      in_out_thres_match_dir_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_accuracy_req_convertToJSON() failed [in_out_thres_match_dir]");
			goto end;
		}
	}

	if(loc_accuracy_req->pos_method) {
		cJSON *pos_method_local_JSON = positioning_method_convertToJSON(
			loc_accuracy_req->pos_method);
		if(pos_method_local_JSON == NULL) {
			printf(
				"loc_accuracy_req_convertToJSON() failed [pos_method]");
			goto end;
		}
		cJSON_AddItemToObject(item, "posMethod", pos_method_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_accuracy_req_convertToJSON() failed [pos_method]");
			goto end;
		}
	}

end:
	return item;
}

loc_accuracy_req_t *loc_accuracy_req_parseFromJSON(cJSON *loc_accuracy_reqJSON)
{
	loc_accuracy_req_t *loc_accuracy_req_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *acc_thres = NULL;
	cJSON *acc_thres_match_dir = NULL;
	matching_direction_t *acc_thres_match_dir_local_nonprim = NULL;
	cJSON *in_out_thres = NULL;
	cJSON *in_out_thres_match_dir = NULL;
	matching_direction_t *in_out_thres_match_dir_local_nonprim = NULL;
	cJSON *pos_method = NULL;
	positioning_method_t *pos_method_local_nonprim = NULL;
	acc_thres = cJSON_GetObjectItemCaseSensitive(loc_accuracy_reqJSON,
	                                             "accThres");
	if(acc_thres) {
		if(!cJSON_IsNumber(acc_thres)) {
			printf(
				"loc_accuracy_req_parseFromJSON() failed [acc_thres]");
			goto end;
		}
	}

	acc_thres_match_dir = cJSON_GetObjectItemCaseSensitive(
		loc_accuracy_reqJSON, "accThresMatchDir");
	if(acc_thres_match_dir) {
		acc_thres_match_dir_local_nonprim =
			matching_direction_parseFromJSON(acc_thres_match_dir);
		if(!acc_thres_match_dir_local_nonprim) {
			printf(
				"matching_direction_parseFromJSON failed [acc_thres_match_dir]");
			goto end;
		}
	}

	in_out_thres = cJSON_GetObjectItemCaseSensitive(loc_accuracy_reqJSON,
	                                                "inOutThres");
	if(in_out_thres) {
		if(!cJSON_IsNumber(in_out_thres)) {
			printf(
				"loc_accuracy_req_parseFromJSON() failed [in_out_thres]");
			goto end;
		}
	}

	in_out_thres_match_dir = cJSON_GetObjectItemCaseSensitive(
		loc_accuracy_reqJSON, "inOutThresMatchDir");
	if(in_out_thres_match_dir) {
		in_out_thres_match_dir_local_nonprim =
			matching_direction_parseFromJSON(in_out_thres_match_dir);
		if(!in_out_thres_match_dir_local_nonprim) {
			printf(
				"matching_direction_parseFromJSON failed [in_out_thres_match_dir]");
			goto end;
		}
	}

	pos_method = cJSON_GetObjectItemCaseSensitive(loc_accuracy_reqJSON,
	                                              "posMethod");
	if(pos_method) {
		pos_method_local_nonprim = positioning_method_parseFromJSON(
			pos_method);
		if(!pos_method_local_nonprim) {
			printf(
				"positioning_method_parseFromJSON failed [pos_method]");
			goto end;
		}
	}

	loc_accuracy_req_local_var = loc_accuracy_req_create(
		acc_thres ? true : false,
		acc_thres ? acc_thres->valuedouble : 0,
		acc_thres_match_dir ? acc_thres_match_dir_local_nonprim : NULL,
		in_out_thres ? true : false,
		in_out_thres ? in_out_thres->valuedouble : 0,
		in_out_thres_match_dir ? in_out_thres_match_dir_local_nonprim : NULL,
		pos_method ? pos_method_local_nonprim : NULL
		);

	return loc_accuracy_req_local_var;
end:
	if(acc_thres_match_dir_local_nonprim) {
		matching_direction_free(acc_thres_match_dir_local_nonprim);
		acc_thres_match_dir_local_nonprim = NULL;
	}
	if(in_out_thres_match_dir_local_nonprim) {
		matching_direction_free(in_out_thres_match_dir_local_nonprim);
		in_out_thres_match_dir_local_nonprim = NULL;
	}
	if(pos_method_local_nonprim) {
		positioning_method_free(pos_method_local_nonprim);
		pos_method_local_nonprim = NULL;
	}
	return NULL;
}

loc_accuracy_req_t *loc_accuracy_req_copy(loc_accuracy_req_t	*dst,
                                          loc_accuracy_req_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = loc_accuracy_req_convertToJSON(src);
	if(!item) {
		printf("loc_accuracy_req_convertToJSON() failed");
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

	loc_accuracy_req_free(dst);
	dst = loc_accuracy_req_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
