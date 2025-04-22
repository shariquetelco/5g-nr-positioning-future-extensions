#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n2_ran_information.h"

n2_ran_information_t *n2_ran_information_create(
	n2_info_content_t *n2_info_content) {
	n2_ran_information_t *n2_ran_information_local_var =
		malloc(sizeof(n2_ran_information_t));

	n2_ran_information_local_var->n2_info_content = n2_info_content;

	return n2_ran_information_local_var;
}

void n2_ran_information_free(n2_ran_information_t *n2_ran_information) {
	lnode_t *node = NULL;

	if(NULL == n2_ran_information) {
		return;
	}
	if(n2_ran_information->n2_info_content) {
		n2_info_content_free(n2_ran_information->n2_info_content);
		n2_ran_information->n2_info_content = NULL;
	}
	free(n2_ran_information);
}

cJSON *n2_ran_information_convertToJSON(
	n2_ran_information_t *n2_ran_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n2_ran_information == NULL) {
		printf(
			"n2_ran_information_convertToJSON() failed [N2RanInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!n2_ran_information->n2_info_content) {
		printf(
			"n2_ran_information_convertToJSON() failed [n2_info_content]");
		return NULL;
	}
	cJSON *n2_info_content_local_JSON = n2_info_content_convertToJSON(
		n2_ran_information->n2_info_content);
	if(n2_info_content_local_JSON == NULL) {
		printf(
			"n2_ran_information_convertToJSON() failed [n2_info_content]");
		goto end;
	}
	cJSON_AddItemToObject(item, "n2InfoContent",
	                      n2_info_content_local_JSON);
	if(item->child == NULL) {
		printf(
			"n2_ran_information_convertToJSON() failed [n2_info_content]");
		goto end;
	}

end:
	return item;
}

n2_ran_information_t *n2_ran_information_parseFromJSON(
	cJSON *n2_ran_informationJSON) {
	n2_ran_information_t *n2_ran_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *n2_info_content = NULL;
	n2_info_content_t *n2_info_content_local_nonprim = NULL;
	n2_info_content = cJSON_GetObjectItemCaseSensitive(
		n2_ran_informationJSON, "n2InfoContent");
	if(!n2_info_content) {
		printf(
			"n2_ran_information_parseFromJSON() failed [n2_info_content]");
		goto end;
	}
	n2_info_content_local_nonprim = n2_info_content_parseFromJSON(
		n2_info_content);
	if(!n2_info_content_local_nonprim) {
		printf("n2_info_content_parseFromJSON failed [n2_info_content]");
		goto end;
	}

	n2_ran_information_local_var = n2_ran_information_create(
		n2_info_content_local_nonprim
		);

	return n2_ran_information_local_var;
end:
	if(n2_info_content_local_nonprim) {
		n2_info_content_free(n2_info_content_local_nonprim);
		n2_info_content_local_nonprim = NULL;
	}
	return NULL;
}

n2_ran_information_t *n2_ran_information_copy(n2_ran_information_t	*dst,
                                              n2_ran_information_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = n2_ran_information_convertToJSON(src);
	if(!item) {
		printf("n2_ran_information_convertToJSON() failed");
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

	n2_ran_information_free(dst);
	dst = n2_ran_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
