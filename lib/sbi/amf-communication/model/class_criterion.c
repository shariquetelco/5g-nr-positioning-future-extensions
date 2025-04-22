#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "class_criterion.h"

class_criterion_t *class_criterion_create(dispersion_class_t	*disper_class,
                                          int			class_threshold,
                                          matching_direction_t	*thres_match) {
	class_criterion_t *class_criterion_local_var =
		malloc(sizeof(class_criterion_t));

	class_criterion_local_var->disper_class = disper_class;
	class_criterion_local_var->class_threshold = class_threshold;
	class_criterion_local_var->thres_match = thres_match;

	return class_criterion_local_var;
}

void class_criterion_free(class_criterion_t *class_criterion) {
	lnode_t *node = NULL;

	if(NULL == class_criterion) {
		return;
	}
	if(class_criterion->disper_class) {
		dispersion_class_free(class_criterion->disper_class);
		class_criterion->disper_class = NULL;
	}
	if(class_criterion->thres_match) {
		matching_direction_free(class_criterion->thres_match);
		class_criterion->thres_match = NULL;
	}
	free(class_criterion);
}

cJSON *class_criterion_convertToJSON(class_criterion_t *class_criterion) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(class_criterion == NULL) {
		printf("class_criterion_convertToJSON() failed [ClassCriterion]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!class_criterion->disper_class) {
		printf("class_criterion_convertToJSON() failed [disper_class]");
		return NULL;
	}
	cJSON *disper_class_local_JSON = dispersion_class_convertToJSON(
		class_criterion->disper_class);
	if(disper_class_local_JSON == NULL) {
		printf("class_criterion_convertToJSON() failed [disper_class]");
		goto end;
	}
	cJSON_AddItemToObject(item, "disperClass", disper_class_local_JSON);
	if(item->child == NULL) {
		printf("class_criterion_convertToJSON() failed [disper_class]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "classThreshold",
	                           class_criterion->class_threshold) == NULL)
	{
		printf(
			"class_criterion_convertToJSON() failed [class_threshold]");
		goto end;
	}

	if(!class_criterion->thres_match) {
		printf("class_criterion_convertToJSON() failed [thres_match]");
		return NULL;
	}
	cJSON *thres_match_local_JSON = matching_direction_convertToJSON(
		class_criterion->thres_match);
	if(thres_match_local_JSON == NULL) {
		printf("class_criterion_convertToJSON() failed [thres_match]");
		goto end;
	}
	cJSON_AddItemToObject(item, "thresMatch", thres_match_local_JSON);
	if(item->child == NULL) {
		printf("class_criterion_convertToJSON() failed [thres_match]");
		goto end;
	}

end:
	return item;
}

class_criterion_t *class_criterion_parseFromJSON(cJSON *class_criterionJSON) {
	class_criterion_t *class_criterion_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *disper_class = NULL;
	dispersion_class_t *disper_class_local_nonprim = NULL;
	cJSON *class_threshold = NULL;
	cJSON *thres_match = NULL;
	matching_direction_t *thres_match_local_nonprim = NULL;
	disper_class = cJSON_GetObjectItemCaseSensitive(class_criterionJSON,
	                                                "disperClass");
	if(!disper_class) {
		printf("class_criterion_parseFromJSON() failed [disper_class]");
		goto end;
	}
	disper_class_local_nonprim =
		dispersion_class_parseFromJSON(disper_class);
	if(!disper_class_local_nonprim) {
		printf("dispersion_class_parseFromJSON failed [disper_class]");
		goto end;
	}

	class_threshold = cJSON_GetObjectItemCaseSensitive(class_criterionJSON,
	                                                   "classThreshold");
	if(!class_threshold) {
		printf(
			"class_criterion_parseFromJSON() failed [class_threshold]");
		goto end;
	}
	if(!cJSON_IsNumber(class_threshold)) {
		printf(
			"class_criterion_parseFromJSON() failed [class_threshold]");
		goto end;
	}

	thres_match = cJSON_GetObjectItemCaseSensitive(class_criterionJSON,
	                                               "thresMatch");
	if(!thres_match) {
		printf("class_criterion_parseFromJSON() failed [thres_match]");
		goto end;
	}
	thres_match_local_nonprim =
		matching_direction_parseFromJSON(thres_match);
	if(!thres_match_local_nonprim) {
		printf("matching_direction_parseFromJSON failed [thres_match]");
		goto end;
	}

	class_criterion_local_var = class_criterion_create(
		disper_class_local_nonprim,

		class_threshold->valuedouble,
		thres_match_local_nonprim
		);

	return class_criterion_local_var;
end:
	if(disper_class_local_nonprim) {
		dispersion_class_free(disper_class_local_nonprim);
		disper_class_local_nonprim = NULL;
	}
	if(thres_match_local_nonprim) {
		matching_direction_free(thres_match_local_nonprim);
		thres_match_local_nonprim = NULL;
	}
	return NULL;
}

class_criterion_t *class_criterion_copy(class_criterion_t	*dst,
                                        class_criterion_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = class_criterion_convertToJSON(src);
	if(!item) {
		printf("class_criterion_convertToJSON() failed");
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

	class_criterion_free(dst);
	dst = class_criterion_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
