#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "resource_usage_requirement.h"

resource_usage_requirement_t *resource_usage_requirement_create(
	traffic_direction_t *tfc_dirc, value_expression_t *val_exp) {
	resource_usage_requirement_t *resource_usage_requirement_local_var =
		malloc(sizeof(resource_usage_requirement_t));

	resource_usage_requirement_local_var->tfc_dirc = tfc_dirc;
	resource_usage_requirement_local_var->val_exp = val_exp;

	return resource_usage_requirement_local_var;
}

void resource_usage_requirement_free(
	resource_usage_requirement_t *resource_usage_requirement) {
	lnode_t *node = NULL;

	if(NULL == resource_usage_requirement) {
		return;
	}
	if(resource_usage_requirement->tfc_dirc) {
		traffic_direction_free(resource_usage_requirement->tfc_dirc);
		resource_usage_requirement->tfc_dirc = NULL;
	}
	if(resource_usage_requirement->val_exp) {
		value_expression_free(resource_usage_requirement->val_exp);
		resource_usage_requirement->val_exp = NULL;
	}
	free(resource_usage_requirement);
}

cJSON *resource_usage_requirement_convertToJSON(
	resource_usage_requirement_t *resource_usage_requirement) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(resource_usage_requirement == NULL) {
		printf(
			"resource_usage_requirement_convertToJSON() failed [ResourceUsageRequirement]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(resource_usage_requirement->tfc_dirc) {
		cJSON *tfc_dirc_local_JSON = traffic_direction_convertToJSON(
			resource_usage_requirement->tfc_dirc);
		if(tfc_dirc_local_JSON == NULL) {
			printf(
				"resource_usage_requirement_convertToJSON() failed [tfc_dirc]");
			goto end;
		}
		cJSON_AddItemToObject(item, "tfcDirc", tfc_dirc_local_JSON);
		if(item->child == NULL) {
			printf(
				"resource_usage_requirement_convertToJSON() failed [tfc_dirc]");
			goto end;
		}
	}

	if(resource_usage_requirement->val_exp) {
		cJSON *val_exp_local_JSON = value_expression_convertToJSON(
			resource_usage_requirement->val_exp);
		if(val_exp_local_JSON == NULL) {
			printf(
				"resource_usage_requirement_convertToJSON() failed [val_exp]");
			goto end;
		}
		cJSON_AddItemToObject(item, "valExp", val_exp_local_JSON);
		if(item->child == NULL) {
			printf(
				"resource_usage_requirement_convertToJSON() failed [val_exp]");
			goto end;
		}
	}

end:
	return item;
}

resource_usage_requirement_t *resource_usage_requirement_parseFromJSON(
	cJSON *resource_usage_requirementJSON) {
	resource_usage_requirement_t *resource_usage_requirement_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *tfc_dirc = NULL;
	traffic_direction_t *tfc_dirc_local_nonprim = NULL;
	cJSON *val_exp = NULL;
	value_expression_t *val_exp_local_nonprim = NULL;
	tfc_dirc = cJSON_GetObjectItemCaseSensitive(
		resource_usage_requirementJSON, "tfcDirc");
	if(tfc_dirc) {
		tfc_dirc_local_nonprim = traffic_direction_parseFromJSON(
			tfc_dirc);
		if(!tfc_dirc_local_nonprim) {
			printf(
				"traffic_direction_parseFromJSON failed [tfc_dirc]");
			goto end;
		}
	}

	val_exp = cJSON_GetObjectItemCaseSensitive(
		resource_usage_requirementJSON, "valExp");
	if(val_exp) {
		val_exp_local_nonprim = value_expression_parseFromJSON(val_exp);
		if(!val_exp_local_nonprim) {
			printf("value_expression_parseFromJSON failed [val_exp]");
			goto end;
		}
	}

	resource_usage_requirement_local_var =
		resource_usage_requirement_create(
			tfc_dirc ? tfc_dirc_local_nonprim : NULL,
			val_exp ? val_exp_local_nonprim : NULL
			);

	return resource_usage_requirement_local_var;
end:
	if(tfc_dirc_local_nonprim) {
		traffic_direction_free(tfc_dirc_local_nonprim);
		tfc_dirc_local_nonprim = NULL;
	}
	if(val_exp_local_nonprim) {
		value_expression_free(val_exp_local_nonprim);
		val_exp_local_nonprim = NULL;
	}
	return NULL;
}

resource_usage_requirement_t *resource_usage_requirement_copy(
	resource_usage_requirement_t *dst, resource_usage_requirement_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = resource_usage_requirement_convertToJSON(src);
	if(!item) {
		printf("resource_usage_requirement_convertToJSON() failed");
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

	resource_usage_requirement_free(dst);
	dst = resource_usage_requirement_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
