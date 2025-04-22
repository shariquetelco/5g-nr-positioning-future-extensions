#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_accuracy_per_method.h"

loc_accuracy_per_method_t *loc_accuracy_per_method_create(
	positioning_method_t *pos_method, int loc_acc, bool is_los_nlos_pct,
	int los_nlos_pct, bool is_los_nlos_ind, int los_nlos_ind) {
	loc_accuracy_per_method_t *loc_accuracy_per_method_local_var = malloc(
		sizeof(loc_accuracy_per_method_t));

	loc_accuracy_per_method_local_var->pos_method = pos_method;
	loc_accuracy_per_method_local_var->loc_acc = loc_acc;
	loc_accuracy_per_method_local_var->is_los_nlos_pct = is_los_nlos_pct;
	loc_accuracy_per_method_local_var->los_nlos_pct = los_nlos_pct;
	loc_accuracy_per_method_local_var->is_los_nlos_ind = is_los_nlos_ind;
	loc_accuracy_per_method_local_var->los_nlos_ind = los_nlos_ind;

	return loc_accuracy_per_method_local_var;
}

void loc_accuracy_per_method_free(
	loc_accuracy_per_method_t *loc_accuracy_per_method) {
	lnode_t *node = NULL;

	if(NULL == loc_accuracy_per_method) {
		return;
	}
	if(loc_accuracy_per_method->pos_method) {
		positioning_method_free(loc_accuracy_per_method->pos_method);
		loc_accuracy_per_method->pos_method = NULL;
	}
	free(loc_accuracy_per_method);
}

cJSON *loc_accuracy_per_method_convertToJSON(
	loc_accuracy_per_method_t *loc_accuracy_per_method) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(loc_accuracy_per_method == NULL) {
		printf(
			"loc_accuracy_per_method_convertToJSON() failed [LocAccuracyPerMethod]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!loc_accuracy_per_method->pos_method) {
		printf(
			"loc_accuracy_per_method_convertToJSON() failed [pos_method]");
		return NULL;
	}
	cJSON *pos_method_local_JSON = positioning_method_convertToJSON(
		loc_accuracy_per_method->pos_method);
	if(pos_method_local_JSON == NULL) {
		printf(
			"loc_accuracy_per_method_convertToJSON() failed [pos_method]");
		goto end;
	}
	cJSON_AddItemToObject(item, "posMethod", pos_method_local_JSON);
	if(item->child == NULL) {
		printf(
			"loc_accuracy_per_method_convertToJSON() failed [pos_method]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "locAcc",
	                           loc_accuracy_per_method->loc_acc) == NULL)
	{
		printf(
			"loc_accuracy_per_method_convertToJSON() failed [loc_acc]");
		goto end;
	}

	if(loc_accuracy_per_method->is_los_nlos_pct) {
		if(cJSON_AddNumberToObject(item, "losNlosPct",
		                           loc_accuracy_per_method->los_nlos_pct)
		   == NULL)
		{
			printf(
				"loc_accuracy_per_method_convertToJSON() failed [los_nlos_pct]");
			goto end;
		}
	}

	if(loc_accuracy_per_method->is_los_nlos_ind) {
		if(cJSON_AddBoolToObject(item, "losNlosInd",
		                         loc_accuracy_per_method->los_nlos_ind)
		   == NULL)
		{
			printf(
				"loc_accuracy_per_method_convertToJSON() failed [los_nlos_ind]");
			goto end;
		}
	}

end:
	return item;
}

loc_accuracy_per_method_t *loc_accuracy_per_method_parseFromJSON(
	cJSON *loc_accuracy_per_methodJSON) {
	loc_accuracy_per_method_t *loc_accuracy_per_method_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pos_method = NULL;
	positioning_method_t *pos_method_local_nonprim = NULL;
	cJSON *loc_acc = NULL;
	cJSON *los_nlos_pct = NULL;
	cJSON *los_nlos_ind = NULL;
	pos_method = cJSON_GetObjectItemCaseSensitive(
		loc_accuracy_per_methodJSON, "posMethod");
	if(!pos_method) {
		printf(
			"loc_accuracy_per_method_parseFromJSON() failed [pos_method]");
		goto end;
	}
	pos_method_local_nonprim = positioning_method_parseFromJSON(pos_method);
	if(!pos_method_local_nonprim) {
		printf("positioning_method_parseFromJSON failed [pos_method]");
		goto end;
	}

	loc_acc = cJSON_GetObjectItemCaseSensitive(loc_accuracy_per_methodJSON,
	                                           "locAcc");
	if(!loc_acc) {
		printf(
			"loc_accuracy_per_method_parseFromJSON() failed [loc_acc]");
		goto end;
	}
	if(!cJSON_IsNumber(loc_acc)) {
		printf(
			"loc_accuracy_per_method_parseFromJSON() failed [loc_acc]");
		goto end;
	}

	los_nlos_pct = cJSON_GetObjectItemCaseSensitive(
		loc_accuracy_per_methodJSON, "losNlosPct");
	if(los_nlos_pct) {
		if(!cJSON_IsNumber(los_nlos_pct)) {
			printf(
				"loc_accuracy_per_method_parseFromJSON() failed [los_nlos_pct]");
			goto end;
		}
	}

	los_nlos_ind = cJSON_GetObjectItemCaseSensitive(
		loc_accuracy_per_methodJSON, "losNlosInd");
	if(los_nlos_ind) {
		if(!cJSON_IsBool(los_nlos_ind)) {
			printf(
				"loc_accuracy_per_method_parseFromJSON() failed [los_nlos_ind]");
			goto end;
		}
	}

	loc_accuracy_per_method_local_var = loc_accuracy_per_method_create(
		pos_method_local_nonprim,

		loc_acc->valuedouble,
		los_nlos_pct ? true : false,
		los_nlos_pct ? los_nlos_pct->valuedouble : 0,
		los_nlos_ind ? true : false,
		los_nlos_ind ? los_nlos_ind->valueint : 0
		);

	return loc_accuracy_per_method_local_var;
end:
	if(pos_method_local_nonprim) {
		positioning_method_free(pos_method_local_nonprim);
		pos_method_local_nonprim = NULL;
	}
	return NULL;
}

loc_accuracy_per_method_t *loc_accuracy_per_method_copy(
	loc_accuracy_per_method_t *dst, loc_accuracy_per_method_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = loc_accuracy_per_method_convertToJSON(src);
	if(!item) {
		printf("loc_accuracy_per_method_convertToJSON() failed");
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

	loc_accuracy_per_method_free(dst);
	dst = loc_accuracy_per_method_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
