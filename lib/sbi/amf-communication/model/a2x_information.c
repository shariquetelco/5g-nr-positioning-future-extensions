#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "a2x_information.h"

a2x_information_t *a2x_information_create(n2_info_content_t *n2_pc5_pol) {
	a2x_information_t *a2x_information_local_var =
		malloc(sizeof(a2x_information_t));

	a2x_information_local_var->n2_pc5_pol = n2_pc5_pol;

	return a2x_information_local_var;
}

void a2x_information_free(a2x_information_t *a2x_information) {
	lnode_t *node = NULL;

	if(NULL == a2x_information) {
		return;
	}
	if(a2x_information->n2_pc5_pol) {
		n2_info_content_free(a2x_information->n2_pc5_pol);
		a2x_information->n2_pc5_pol = NULL;
	}
	free(a2x_information);
}

cJSON *a2x_information_convertToJSON(a2x_information_t *a2x_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(a2x_information == NULL) {
		printf("a2x_information_convertToJSON() failed [A2xInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(a2x_information->n2_pc5_pol) {
		cJSON *n2_pc5_pol_local_JSON = n2_info_content_convertToJSON(
			a2x_information->n2_pc5_pol);
		if(n2_pc5_pol_local_JSON == NULL) {
			printf(
				"a2x_information_convertToJSON() failed [n2_pc5_pol]");
			goto end;
		}
		cJSON_AddItemToObject(item, "n2Pc5Pol", n2_pc5_pol_local_JSON);
		if(item->child == NULL) {
			printf(
				"a2x_information_convertToJSON() failed [n2_pc5_pol]");
			goto end;
		}
	}

end:
	return item;
}

a2x_information_t *a2x_information_parseFromJSON(cJSON *a2x_informationJSON) {
	a2x_information_t *a2x_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *n2_pc5_pol = NULL;
	n2_info_content_t *n2_pc5_pol_local_nonprim = NULL;
	n2_pc5_pol = cJSON_GetObjectItemCaseSensitive(a2x_informationJSON,
	                                              "n2Pc5Pol");
	if(n2_pc5_pol) {
		n2_pc5_pol_local_nonprim = n2_info_content_parseFromJSON(
			n2_pc5_pol);
		if(!n2_pc5_pol_local_nonprim) {
			printf(
				"n2_info_content_parseFromJSON failed [n2_pc5_pol]");
			goto end;
		}
	}

	a2x_information_local_var = a2x_information_create(
		n2_pc5_pol ? n2_pc5_pol_local_nonprim : NULL
		);

	return a2x_information_local_var;
end:
	if(n2_pc5_pol_local_nonprim) {
		n2_info_content_free(n2_pc5_pol_local_nonprim);
		n2_pc5_pol_local_nonprim = NULL;
	}
	return NULL;
}

a2x_information_t *a2x_information_copy(a2x_information_t	*dst,
                                        a2x_information_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = a2x_information_convertToJSON(src);
	if(!item) {
		printf("a2x_information_convertToJSON() failed");
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

	a2x_information_free(dst);
	dst = a2x_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
