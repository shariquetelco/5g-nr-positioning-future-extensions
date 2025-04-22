#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rslp_information.h"

rslp_information_t *rslp_information_create(n2_info_content_t *n2_pc5_rslp_pol)
{
	rslp_information_t *rslp_information_local_var =
		malloc(sizeof(rslp_information_t));

	rslp_information_local_var->n2_pc5_rslp_pol = n2_pc5_rslp_pol;

	return rslp_information_local_var;
}

void rslp_information_free(rslp_information_t *rslp_information) {
	lnode_t *node = NULL;

	if(NULL == rslp_information) {
		return;
	}
	if(rslp_information->n2_pc5_rslp_pol) {
		n2_info_content_free(rslp_information->n2_pc5_rslp_pol);
		rslp_information->n2_pc5_rslp_pol = NULL;
	}
	free(rslp_information);
}

cJSON *rslp_information_convertToJSON(rslp_information_t *rslp_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(rslp_information == NULL) {
		printf(
			"rslp_information_convertToJSON() failed [RslpInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(rslp_information->n2_pc5_rslp_pol) {
		cJSON *n2_pc5_rslp_pol_local_JSON =
			n2_info_content_convertToJSON(
				rslp_information->n2_pc5_rslp_pol);
		if(n2_pc5_rslp_pol_local_JSON == NULL) {
			printf(
				"rslp_information_convertToJSON() failed [n2_pc5_rslp_pol]");
			goto end;
		}
		cJSON_AddItemToObject(item, "n2Pc5RslpPol",
		                      n2_pc5_rslp_pol_local_JSON);
		if(item->child == NULL) {
			printf(
				"rslp_information_convertToJSON() failed [n2_pc5_rslp_pol]");
			goto end;
		}
	}

end:
	return item;
}

rslp_information_t *rslp_information_parseFromJSON(cJSON *rslp_informationJSON)
{
	rslp_information_t *rslp_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *n2_pc5_rslp_pol = NULL;
	n2_info_content_t *n2_pc5_rslp_pol_local_nonprim = NULL;
	n2_pc5_rslp_pol = cJSON_GetObjectItemCaseSensitive(rslp_informationJSON,
	                                                   "n2Pc5RslpPol");
	if(n2_pc5_rslp_pol) {
		n2_pc5_rslp_pol_local_nonprim = n2_info_content_parseFromJSON(
			n2_pc5_rslp_pol);
		if(!n2_pc5_rslp_pol_local_nonprim) {
			printf(
				"n2_info_content_parseFromJSON failed [n2_pc5_rslp_pol]");
			goto end;
		}
	}

	rslp_information_local_var = rslp_information_create(
		n2_pc5_rslp_pol ? n2_pc5_rslp_pol_local_nonprim : NULL
		);

	return rslp_information_local_var;
end:
	if(n2_pc5_rslp_pol_local_nonprim) {
		n2_info_content_free(n2_pc5_rslp_pol_local_nonprim);
		n2_pc5_rslp_pol_local_nonprim = NULL;
	}
	return NULL;
}

rslp_information_t *rslp_information_copy(rslp_information_t	*dst,
                                          rslp_information_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = rslp_information_convertToJSON(src);
	if(!item) {
		printf("rslp_information_convertToJSON() failed");
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

	rslp_information_free(dst);
	dst = rslp_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
