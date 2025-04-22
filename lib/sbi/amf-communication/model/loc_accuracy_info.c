#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_accuracy_info.h"

loc_accuracy_info_t *loc_accuracy_info_create(list_t	*loc_acc_per_meths,
                                              bool	is_in_out_ue_pct,
                                              int	in_out_ue_pct,
                                              bool	is_in_out_ind,
                                              int	in_out_ind,
                                              bool	is_confidence,
                                              int	confidence) {
	loc_accuracy_info_t *loc_accuracy_info_local_var =
		malloc(sizeof(loc_accuracy_info_t));

	loc_accuracy_info_local_var->loc_acc_per_meths = loc_acc_per_meths;
	loc_accuracy_info_local_var->is_in_out_ue_pct = is_in_out_ue_pct;
	loc_accuracy_info_local_var->in_out_ue_pct = in_out_ue_pct;
	loc_accuracy_info_local_var->is_in_out_ind = is_in_out_ind;
	loc_accuracy_info_local_var->in_out_ind = in_out_ind;
	loc_accuracy_info_local_var->is_confidence = is_confidence;
	loc_accuracy_info_local_var->confidence = confidence;

	return loc_accuracy_info_local_var;
}

void loc_accuracy_info_free(loc_accuracy_info_t *loc_accuracy_info) {
	lnode_t *node = NULL;

	if(NULL == loc_accuracy_info) {
		return;
	}
	if(loc_accuracy_info->loc_acc_per_meths) {
		list_for_each(loc_accuracy_info->loc_acc_per_meths, node) {
			loc_accuracy_per_method_free(node->data);
		}
		list_free(loc_accuracy_info->loc_acc_per_meths);
		loc_accuracy_info->loc_acc_per_meths = NULL;
	}
	free(loc_accuracy_info);
}

cJSON *loc_accuracy_info_convertToJSON(loc_accuracy_info_t *loc_accuracy_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(loc_accuracy_info == NULL) {
		printf(
			"loc_accuracy_info_convertToJSON() failed [LocAccuracyInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!loc_accuracy_info->loc_acc_per_meths) {
		printf(
			"loc_accuracy_info_convertToJSON() failed [loc_acc_per_meths]");
		return NULL;
	}
	cJSON *loc_acc_per_methsList = cJSON_AddArrayToObject(item,
	                                                      "locAccPerMeths");
	if(loc_acc_per_methsList == NULL) {
		printf(
			"loc_accuracy_info_convertToJSON() failed [loc_acc_per_meths]");
		goto end;
	}
	list_for_each(loc_accuracy_info->loc_acc_per_meths, node) {
		cJSON *itemLocal = loc_accuracy_per_method_convertToJSON(
			node->data);
		if(itemLocal == NULL) {
			printf(
				"loc_accuracy_info_convertToJSON() failed [loc_acc_per_meths]");
			goto end;
		}
		cJSON_AddItemToArray(loc_acc_per_methsList, itemLocal);
	}

	if(loc_accuracy_info->is_in_out_ue_pct) {
		if(cJSON_AddNumberToObject(item, "inOutUePct",
		                           loc_accuracy_info->in_out_ue_pct) ==
		   NULL)
		{
			printf(
				"loc_accuracy_info_convertToJSON() failed [in_out_ue_pct]");
			goto end;
		}
	}

	if(loc_accuracy_info->is_in_out_ind) {
		if(cJSON_AddBoolToObject(item, "inOutInd",
		                         loc_accuracy_info->in_out_ind) == NULL)
		{
			printf(
				"loc_accuracy_info_convertToJSON() failed [in_out_ind]");
			goto end;
		}
	}

	if(loc_accuracy_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           loc_accuracy_info->confidence) ==
		   NULL)
		{
			printf(
				"loc_accuracy_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

end:
	return item;
}

loc_accuracy_info_t *loc_accuracy_info_parseFromJSON(
	cJSON *loc_accuracy_infoJSON) {
	loc_accuracy_info_t *loc_accuracy_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *loc_acc_per_meths = NULL;
	list_t *loc_acc_per_methsList = NULL;
	cJSON *in_out_ue_pct = NULL;
	cJSON *in_out_ind = NULL;
	cJSON *confidence = NULL;
	loc_acc_per_meths = cJSON_GetObjectItemCaseSensitive(
		loc_accuracy_infoJSON, "locAccPerMeths");
	if(!loc_acc_per_meths) {
		printf(
			"loc_accuracy_info_parseFromJSON() failed [loc_acc_per_meths]");
		goto end;
	}
	cJSON *loc_acc_per_meths_local = NULL;
	if(!cJSON_IsArray(loc_acc_per_meths)) {
		printf(
			"loc_accuracy_info_parseFromJSON() failed [loc_acc_per_meths]");
		goto end;
	}

	loc_acc_per_methsList = list_create();

	cJSON_ArrayForEach(loc_acc_per_meths_local, loc_acc_per_meths) {
		if(!cJSON_IsObject(loc_acc_per_meths_local)) {
			printf(
				"loc_accuracy_info_parseFromJSON() failed [loc_acc_per_meths]");
			goto end;
		}
		loc_accuracy_per_method_t *loc_acc_per_methsItem =
			loc_accuracy_per_method_parseFromJSON(
				loc_acc_per_meths_local);
		if(!loc_acc_per_methsItem) {
			printf("No loc_acc_per_methsItem");
			goto end;
		}
		list_add(loc_acc_per_methsList, loc_acc_per_methsItem);
	}

	in_out_ue_pct = cJSON_GetObjectItemCaseSensitive(loc_accuracy_infoJSON,
	                                                 "inOutUePct");
	if(in_out_ue_pct) {
		if(!cJSON_IsNumber(in_out_ue_pct)) {
			printf(
				"loc_accuracy_info_parseFromJSON() failed [in_out_ue_pct]");
			goto end;
		}
	}

	in_out_ind = cJSON_GetObjectItemCaseSensitive(loc_accuracy_infoJSON,
	                                              "inOutInd");
	if(in_out_ind) {
		if(!cJSON_IsBool(in_out_ind)) {
			printf(
				"loc_accuracy_info_parseFromJSON() failed [in_out_ind]");
			goto end;
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(loc_accuracy_infoJSON,
	                                              "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"loc_accuracy_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	loc_accuracy_info_local_var = loc_accuracy_info_create(
		loc_acc_per_methsList,
		in_out_ue_pct ? true : false,
		in_out_ue_pct ? in_out_ue_pct->valuedouble : 0,
		in_out_ind ? true : false,
		in_out_ind ? in_out_ind->valueint : 0,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0
		);

	return loc_accuracy_info_local_var;
end:
	if(loc_acc_per_methsList) {
		list_for_each(loc_acc_per_methsList, node) {
			loc_accuracy_per_method_free(node->data);
		}
		list_free(loc_acc_per_methsList);
		loc_acc_per_methsList = NULL;
	}
	return NULL;
}

loc_accuracy_info_t *loc_accuracy_info_copy(loc_accuracy_info_t *dst,
                                            loc_accuracy_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = loc_accuracy_info_convertToJSON(src);
	if(!item) {
		printf("loc_accuracy_info_convertToJSON() failed");
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

	loc_accuracy_info_free(dst);
	dst = loc_accuracy_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
