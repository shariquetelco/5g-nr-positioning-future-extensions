#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2x_information.h"

v2x_information_t *v2x_information_create(n2_info_content_t *n2_pc5_pol) {
	v2x_information_t *v2x_information_local_var =
		malloc(sizeof(v2x_information_t));

	v2x_information_local_var->n2_pc5_pol = n2_pc5_pol;

	return v2x_information_local_var;
}

void v2x_information_free(v2x_information_t *v2x_information) {
	lnode_t *node = NULL;

	if(NULL == v2x_information) {
		return;
	}
	if(v2x_information->n2_pc5_pol) {
		n2_info_content_free(v2x_information->n2_pc5_pol);
		v2x_information->n2_pc5_pol = NULL;
	}
	free(v2x_information);
}

cJSON *v2x_information_convertToJSON(v2x_information_t *v2x_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(v2x_information == NULL) {
		printf("v2x_information_convertToJSON() failed [V2xInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(v2x_information->n2_pc5_pol) {
		cJSON *n2_pc5_pol_local_JSON = n2_info_content_convertToJSON(
			v2x_information->n2_pc5_pol);
		if(n2_pc5_pol_local_JSON == NULL) {
			printf(
				"v2x_information_convertToJSON() failed [n2_pc5_pol]");
			goto end;
		}
		cJSON_AddItemToObject(item, "n2Pc5Pol", n2_pc5_pol_local_JSON);
		if(item->child == NULL) {
			printf(
				"v2x_information_convertToJSON() failed [n2_pc5_pol]");
			goto end;
		}
	}

end:
	return item;
}

v2x_information_t *v2x_information_parseFromJSON(cJSON *v2x_informationJSON) {
	v2x_information_t *v2x_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *n2_pc5_pol = NULL;
	n2_info_content_t *n2_pc5_pol_local_nonprim = NULL;
	n2_pc5_pol = cJSON_GetObjectItemCaseSensitive(v2x_informationJSON,
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

	v2x_information_local_var = v2x_information_create(
		n2_pc5_pol ? n2_pc5_pol_local_nonprim : NULL
		);

	return v2x_information_local_var;
end:
	if(n2_pc5_pol_local_nonprim) {
		n2_info_content_free(n2_pc5_pol_local_nonprim);
		n2_pc5_pol_local_nonprim = NULL;
	}
	return NULL;
}

v2x_information_t *v2x_information_copy(v2x_information_t	*dst,
                                        v2x_information_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = v2x_information_convertToJSON(src);
	if(!item) {
		printf("v2x_information_convertToJSON() failed");
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

	v2x_information_free(dst);
	dst = v2x_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
