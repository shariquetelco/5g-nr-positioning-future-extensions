#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "accuracy_info.h"

accuracy_info_t *accuracy_info_create(bool is_accuracy_val, int accuracy_val,
                                      bool is_accu_sample_nbr,
                                      int accu_sample_nbr,
                                      analytics_accuracy_indication_t *ana_accu_ind)
{
	accuracy_info_t *accuracy_info_local_var = malloc(
		sizeof(accuracy_info_t));

	accuracy_info_local_var->is_accuracy_val = is_accuracy_val;
	accuracy_info_local_var->accuracy_val = accuracy_val;
	accuracy_info_local_var->is_accu_sample_nbr = is_accu_sample_nbr;
	accuracy_info_local_var->accu_sample_nbr = accu_sample_nbr;
	accuracy_info_local_var->ana_accu_ind = ana_accu_ind;

	return accuracy_info_local_var;
}

void accuracy_info_free(accuracy_info_t *accuracy_info) {
	lnode_t *node = NULL;

	if(NULL == accuracy_info) {
		return;
	}
	if(accuracy_info->ana_accu_ind) {
		analytics_accuracy_indication_free(accuracy_info->ana_accu_ind);
		accuracy_info->ana_accu_ind = NULL;
	}
	free(accuracy_info);
}

cJSON *accuracy_info_convertToJSON(accuracy_info_t *accuracy_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(accuracy_info == NULL) {
		printf("accuracy_info_convertToJSON() failed [AccuracyInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(accuracy_info->is_accuracy_val) {
		if(cJSON_AddNumberToObject(item, "accuracyVal",
		                           accuracy_info->accuracy_val) == NULL)
		{
			printf(
				"accuracy_info_convertToJSON() failed [accuracy_val]");
			goto end;
		}
	}

	if(accuracy_info->is_accu_sample_nbr) {
		if(cJSON_AddNumberToObject(item, "accuSampleNbr",
		                           accuracy_info->accu_sample_nbr) ==
		   NULL)
		{
			printf(
				"accuracy_info_convertToJSON() failed [accu_sample_nbr]");
			goto end;
		}
	}

	if(accuracy_info->ana_accu_ind) {
		cJSON *ana_accu_ind_local_JSON =
			analytics_accuracy_indication_convertToJSON(
				accuracy_info->ana_accu_ind);
		if(ana_accu_ind_local_JSON == NULL) {
			printf(
				"accuracy_info_convertToJSON() failed [ana_accu_ind]");
			goto end;
		}
		cJSON_AddItemToObject(item, "anaAccuInd",
		                      ana_accu_ind_local_JSON);
		if(item->child == NULL) {
			printf(
				"accuracy_info_convertToJSON() failed [ana_accu_ind]");
			goto end;
		}
	}

end:
	return item;
}

accuracy_info_t *accuracy_info_parseFromJSON(cJSON *accuracy_infoJSON) {
	accuracy_info_t *accuracy_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *accuracy_val = NULL;
	cJSON *accu_sample_nbr = NULL;
	cJSON *ana_accu_ind = NULL;
	analytics_accuracy_indication_t *ana_accu_ind_local_nonprim = NULL;
	accuracy_val = cJSON_GetObjectItemCaseSensitive(accuracy_infoJSON,
	                                                "accuracyVal");
	if(accuracy_val) {
		if(!cJSON_IsNumber(accuracy_val)) {
			printf(
				"accuracy_info_parseFromJSON() failed [accuracy_val]");
			goto end;
		}
	}

	accu_sample_nbr = cJSON_GetObjectItemCaseSensitive(accuracy_infoJSON,
	                                                   "accuSampleNbr");
	if(accu_sample_nbr) {
		if(!cJSON_IsNumber(accu_sample_nbr)) {
			printf(
				"accuracy_info_parseFromJSON() failed [accu_sample_nbr]");
			goto end;
		}
	}

	ana_accu_ind = cJSON_GetObjectItemCaseSensitive(accuracy_infoJSON,
	                                                "anaAccuInd");
	if(ana_accu_ind) {
		ana_accu_ind_local_nonprim =
			analytics_accuracy_indication_parseFromJSON(ana_accu_ind);
		if(!ana_accu_ind_local_nonprim) {
			printf(
				"analytics_accuracy_indication_parseFromJSON failed [ana_accu_ind]");
			goto end;
		}
	}

	accuracy_info_local_var = accuracy_info_create(
		accuracy_val ? true : false,
		accuracy_val ? accuracy_val->valuedouble : 0,
		accu_sample_nbr ? true : false,
		accu_sample_nbr ? accu_sample_nbr->valuedouble : 0,
		ana_accu_ind ? ana_accu_ind_local_nonprim : NULL
		);

	return accuracy_info_local_var;
end:
	if(ana_accu_ind_local_nonprim) {
		analytics_accuracy_indication_free(ana_accu_ind_local_nonprim);
		ana_accu_ind_local_nonprim = NULL;
	}
	return NULL;
}

accuracy_info_t *accuracy_info_copy(accuracy_info_t	*dst,
                                    accuracy_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = accuracy_info_convertToJSON(src);
	if(!item) {
		printf("accuracy_info_convertToJSON() failed");
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

	accuracy_info_free(dst);
	dst = accuracy_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
