#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dispersion_requirement.h"

dispersion_requirement_t *dispersion_requirement_create(
	dispersion_type_t *disper_type, list_t *class_criters,
	list_t *rank_criters,
	dispersion_ordering_criterion_t *disp_order_criter,
	matching_direction_t *order) {
	dispersion_requirement_t *dispersion_requirement_local_var = malloc(
		sizeof(dispersion_requirement_t));

	dispersion_requirement_local_var->disper_type = disper_type;
	dispersion_requirement_local_var->class_criters = class_criters;
	dispersion_requirement_local_var->rank_criters = rank_criters;
	dispersion_requirement_local_var->disp_order_criter = disp_order_criter;
	dispersion_requirement_local_var->order = order;

	return dispersion_requirement_local_var;
}

void dispersion_requirement_free(
	dispersion_requirement_t *dispersion_requirement) {
	lnode_t *node = NULL;

	if(NULL == dispersion_requirement) {
		return;
	}
	if(dispersion_requirement->disper_type) {
		dispersion_type_free(dispersion_requirement->disper_type);
		dispersion_requirement->disper_type = NULL;
	}
	if(dispersion_requirement->class_criters) {
		list_for_each(dispersion_requirement->class_criters, node) {
			class_criterion_free(node->data);
		}
		list_free(dispersion_requirement->class_criters);
		dispersion_requirement->class_criters = NULL;
	}
	if(dispersion_requirement->rank_criters) {
		list_for_each(dispersion_requirement->rank_criters, node) {
			ranking_criterion_free(node->data);
		}
		list_free(dispersion_requirement->rank_criters);
		dispersion_requirement->rank_criters = NULL;
	}
	if(dispersion_requirement->disp_order_criter) {
		dispersion_ordering_criterion_free(
			dispersion_requirement->disp_order_criter);
		dispersion_requirement->disp_order_criter = NULL;
	}
	if(dispersion_requirement->order) {
		matching_direction_free(dispersion_requirement->order);
		dispersion_requirement->order = NULL;
	}
	free(dispersion_requirement);
}

cJSON *dispersion_requirement_convertToJSON(
	dispersion_requirement_t *dispersion_requirement) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dispersion_requirement == NULL) {
		printf(
			"dispersion_requirement_convertToJSON() failed [DispersionRequirement]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!dispersion_requirement->disper_type) {
		printf(
			"dispersion_requirement_convertToJSON() failed [disper_type]");
		return NULL;
	}
	cJSON *disper_type_local_JSON = dispersion_type_convertToJSON(
		dispersion_requirement->disper_type);
	if(disper_type_local_JSON == NULL) {
		printf(
			"dispersion_requirement_convertToJSON() failed [disper_type]");
		goto end;
	}
	cJSON_AddItemToObject(item, "disperType", disper_type_local_JSON);
	if(item->child == NULL) {
		printf(
			"dispersion_requirement_convertToJSON() failed [disper_type]");
		goto end;
	}

	if(dispersion_requirement->class_criters) {
		cJSON *class_critersList = cJSON_AddArrayToObject(item,
		                                                  "classCriters");
		if(class_critersList == NULL) {
			printf(
				"dispersion_requirement_convertToJSON() failed [class_criters]");
			goto end;
		}
		list_for_each(dispersion_requirement->class_criters, node) {
			cJSON *itemLocal = class_criterion_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"dispersion_requirement_convertToJSON() failed [class_criters]");
				goto end;
			}
			cJSON_AddItemToArray(class_critersList, itemLocal);
		}
	}

	if(dispersion_requirement->rank_criters) {
		cJSON *rank_critersList = cJSON_AddArrayToObject(item,
		                                                 "rankCriters");
		if(rank_critersList == NULL) {
			printf(
				"dispersion_requirement_convertToJSON() failed [rank_criters]");
			goto end;
		}
		list_for_each(dispersion_requirement->rank_criters, node) {
			cJSON *itemLocal = ranking_criterion_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"dispersion_requirement_convertToJSON() failed [rank_criters]");
				goto end;
			}
			cJSON_AddItemToArray(rank_critersList, itemLocal);
		}
	}

	if(dispersion_requirement->disp_order_criter) {
		cJSON *disp_order_criter_local_JSON =
			dispersion_ordering_criterion_convertToJSON(
				dispersion_requirement->disp_order_criter);
		if(disp_order_criter_local_JSON == NULL) {
			printf(
				"dispersion_requirement_convertToJSON() failed [disp_order_criter]");
			goto end;
		}
		cJSON_AddItemToObject(item, "dispOrderCriter",
		                      disp_order_criter_local_JSON);
		if(item->child == NULL) {
			printf(
				"dispersion_requirement_convertToJSON() failed [disp_order_criter]");
			goto end;
		}
	}

	if(dispersion_requirement->order) {
		cJSON *order_local_JSON = matching_direction_convertToJSON(
			dispersion_requirement->order);
		if(order_local_JSON == NULL) {
			printf(
				"dispersion_requirement_convertToJSON() failed [order]");
			goto end;
		}
		cJSON_AddItemToObject(item, "order", order_local_JSON);
		if(item->child == NULL) {
			printf(
				"dispersion_requirement_convertToJSON() failed [order]");
			goto end;
		}
	}

end:
	return item;
}

dispersion_requirement_t *dispersion_requirement_parseFromJSON(
	cJSON *dispersion_requirementJSON) {
	dispersion_requirement_t *dispersion_requirement_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *disper_type = NULL;
	dispersion_type_t *disper_type_local_nonprim = NULL;
	cJSON *class_criters = NULL;
	list_t *class_critersList = NULL;
	cJSON *rank_criters = NULL;
	list_t *rank_critersList = NULL;
	cJSON *disp_order_criter = NULL;
	dispersion_ordering_criterion_t *disp_order_criter_local_nonprim = NULL;
	cJSON *order = NULL;
	matching_direction_t *order_local_nonprim = NULL;
	disper_type = cJSON_GetObjectItemCaseSensitive(
		dispersion_requirementJSON, "disperType");
	if(!disper_type) {
		printf(
			"dispersion_requirement_parseFromJSON() failed [disper_type]");
		goto end;
	}
	disper_type_local_nonprim = dispersion_type_parseFromJSON(disper_type);
	if(!disper_type_local_nonprim) {
		printf("dispersion_type_parseFromJSON failed [disper_type]");
		goto end;
	}

	class_criters = cJSON_GetObjectItemCaseSensitive(
		dispersion_requirementJSON, "classCriters");
	if(class_criters) {
		cJSON *class_criters_local = NULL;
		if(!cJSON_IsArray(class_criters)) {
			printf(
				"dispersion_requirement_parseFromJSON() failed [class_criters]");
			goto end;
		}

		class_critersList = list_create();

		cJSON_ArrayForEach(class_criters_local, class_criters) {
			if(!cJSON_IsObject(class_criters_local)) {
				printf(
					"dispersion_requirement_parseFromJSON() failed [class_criters]");
				goto end;
			}
			class_criterion_t *class_critersItem =
				class_criterion_parseFromJSON(
					class_criters_local);
			if(!class_critersItem) {
				printf("No class_critersItem");
				goto end;
			}
			list_add(class_critersList, class_critersItem);
		}
	}

	rank_criters = cJSON_GetObjectItemCaseSensitive(
		dispersion_requirementJSON, "rankCriters");
	if(rank_criters) {
		cJSON *rank_criters_local = NULL;
		if(!cJSON_IsArray(rank_criters)) {
			printf(
				"dispersion_requirement_parseFromJSON() failed [rank_criters]");
			goto end;
		}

		rank_critersList = list_create();

		cJSON_ArrayForEach(rank_criters_local, rank_criters) {
			if(!cJSON_IsObject(rank_criters_local)) {
				printf(
					"dispersion_requirement_parseFromJSON() failed [rank_criters]");
				goto end;
			}
			ranking_criterion_t *rank_critersItem =
				ranking_criterion_parseFromJSON(
					rank_criters_local);
			if(!rank_critersItem) {
				printf("No rank_critersItem");
				goto end;
			}
			list_add(rank_critersList, rank_critersItem);
		}
	}

	disp_order_criter = cJSON_GetObjectItemCaseSensitive(
		dispersion_requirementJSON, "dispOrderCriter");
	if(disp_order_criter) {
		disp_order_criter_local_nonprim =
			dispersion_ordering_criterion_parseFromJSON(
				disp_order_criter);
		if(!disp_order_criter_local_nonprim) {
			printf(
				"dispersion_ordering_criterion_parseFromJSON failed [disp_order_criter]");
			goto end;
		}
	}

	order = cJSON_GetObjectItemCaseSensitive(dispersion_requirementJSON,
	                                         "order");
	if(order) {
		order_local_nonprim = matching_direction_parseFromJSON(order);
		if(!order_local_nonprim) {
			printf("matching_direction_parseFromJSON failed [order]");
			goto end;
		}
	}

	dispersion_requirement_local_var = dispersion_requirement_create(
		disper_type_local_nonprim,
		class_criters ? class_critersList : NULL,
		rank_criters ? rank_critersList : NULL,
		disp_order_criter ? disp_order_criter_local_nonprim : NULL,
		order ? order_local_nonprim : NULL
		);

	return dispersion_requirement_local_var;
end:
	if(disper_type_local_nonprim) {
		dispersion_type_free(disper_type_local_nonprim);
		disper_type_local_nonprim = NULL;
	}
	if(class_critersList) {
		list_for_each(class_critersList, node) {
			class_criterion_free(node->data);
		}
		list_free(class_critersList);
		class_critersList = NULL;
	}
	if(rank_critersList) {
		list_for_each(rank_critersList, node) {
			ranking_criterion_free(node->data);
		}
		list_free(rank_critersList);
		rank_critersList = NULL;
	}
	if(disp_order_criter_local_nonprim) {
		dispersion_ordering_criterion_free(
			disp_order_criter_local_nonprim);
		disp_order_criter_local_nonprim = NULL;
	}
	if(order_local_nonprim) {
		matching_direction_free(order_local_nonprim);
		order_local_nonprim = NULL;
	}
	return NULL;
}

dispersion_requirement_t *dispersion_requirement_copy(
	dispersion_requirement_t *dst, dispersion_requirement_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dispersion_requirement_convertToJSON(src);
	if(!item) {
		printf("dispersion_requirement_convertToJSON() failed");
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

	dispersion_requirement_free(dst);
	dst = dispersion_requirement_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
