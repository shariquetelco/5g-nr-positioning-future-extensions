#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pro_se_information.h"

pro_se_information_t *pro_se_information_create(
	n2_info_content_t *n2_pc5_pro_se_pol) {
	pro_se_information_t *pro_se_information_local_var =
		malloc(sizeof(pro_se_information_t));

	pro_se_information_local_var->n2_pc5_pro_se_pol = n2_pc5_pro_se_pol;

	return pro_se_information_local_var;
}

void pro_se_information_free(pro_se_information_t *pro_se_information) {
	lnode_t *node = NULL;

	if(NULL == pro_se_information) {
		return;
	}
	if(pro_se_information->n2_pc5_pro_se_pol) {
		n2_info_content_free(pro_se_information->n2_pc5_pro_se_pol);
		pro_se_information->n2_pc5_pro_se_pol = NULL;
	}
	free(pro_se_information);
}

cJSON *pro_se_information_convertToJSON(
	pro_se_information_t *pro_se_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pro_se_information == NULL) {
		printf(
			"pro_se_information_convertToJSON() failed [ProSeInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(pro_se_information->n2_pc5_pro_se_pol) {
		cJSON *n2_pc5_pro_se_pol_local_JSON =
			n2_info_content_convertToJSON(
				pro_se_information->n2_pc5_pro_se_pol);
		if(n2_pc5_pro_se_pol_local_JSON == NULL) {
			printf(
				"pro_se_information_convertToJSON() failed [n2_pc5_pro_se_pol]");
			goto end;
		}
		cJSON_AddItemToObject(item, "n2Pc5ProSePol",
		                      n2_pc5_pro_se_pol_local_JSON);
		if(item->child == NULL) {
			printf(
				"pro_se_information_convertToJSON() failed [n2_pc5_pro_se_pol]");
			goto end;
		}
	}

end:
	return item;
}

pro_se_information_t *pro_se_information_parseFromJSON(
	cJSON *pro_se_informationJSON) {
	pro_se_information_t *pro_se_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *n2_pc5_pro_se_pol = NULL;
	n2_info_content_t *n2_pc5_pro_se_pol_local_nonprim = NULL;
	n2_pc5_pro_se_pol = cJSON_GetObjectItemCaseSensitive(
		pro_se_informationJSON, "n2Pc5ProSePol");
	if(n2_pc5_pro_se_pol) {
		n2_pc5_pro_se_pol_local_nonprim = n2_info_content_parseFromJSON(
			n2_pc5_pro_se_pol);
		if(!n2_pc5_pro_se_pol_local_nonprim) {
			printf(
				"n2_info_content_parseFromJSON failed [n2_pc5_pro_se_pol]");
			goto end;
		}
	}

	pro_se_information_local_var = pro_se_information_create(
		n2_pc5_pro_se_pol ? n2_pc5_pro_se_pol_local_nonprim : NULL
		);

	return pro_se_information_local_var;
end:
	if(n2_pc5_pro_se_pol_local_nonprim) {
		n2_info_content_free(n2_pc5_pro_se_pol_local_nonprim);
		n2_pc5_pro_se_pol_local_nonprim = NULL;
	}
	return NULL;
}

pro_se_information_t *pro_se_information_copy(pro_se_information_t	*dst,
                                              pro_se_information_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pro_se_information_convertToJSON(src);
	if(!item) {
		printf("pro_se_information_convertToJSON() failed");
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

	pro_se_information_free(dst);
	dst = pro_se_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
