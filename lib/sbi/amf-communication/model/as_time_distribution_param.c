#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "as_time_distribution_param.h"

as_time_distribution_param_t *as_time_distribution_param_create(
	bool is_as_time_dist_ind, int as_time_dist_ind,
	bool is_uu_error_budget_null, bool is_uu_error_budget,
	int uu_error_budget, clock_quality_detail_level_t *clk_qlt_det_lvl,
	clock_quality_acceptance_criterion_t *clk_qlt_acpt_cri) {
	as_time_distribution_param_t *as_time_distribution_param_local_var =
		malloc(sizeof(as_time_distribution_param_t));

	as_time_distribution_param_local_var->is_as_time_dist_ind =
		is_as_time_dist_ind;
	as_time_distribution_param_local_var->as_time_dist_ind =
		as_time_dist_ind;
	as_time_distribution_param_local_var->is_uu_error_budget_null =
		is_uu_error_budget_null;
	as_time_distribution_param_local_var->is_uu_error_budget =
		is_uu_error_budget;
	as_time_distribution_param_local_var->uu_error_budget = uu_error_budget;
	as_time_distribution_param_local_var->clk_qlt_det_lvl = clk_qlt_det_lvl;
	as_time_distribution_param_local_var->clk_qlt_acpt_cri =
		clk_qlt_acpt_cri;

	return as_time_distribution_param_local_var;
}

void as_time_distribution_param_free(
	as_time_distribution_param_t *as_time_distribution_param) {
	lnode_t *node = NULL;

	if(NULL == as_time_distribution_param) {
		return;
	}
	if(as_time_distribution_param->clk_qlt_det_lvl) {
		clock_quality_detail_level_free(
			as_time_distribution_param->clk_qlt_det_lvl);
		as_time_distribution_param->clk_qlt_det_lvl = NULL;
	}
	if(as_time_distribution_param->clk_qlt_acpt_cri) {
		clock_quality_acceptance_criterion_free(
			as_time_distribution_param->clk_qlt_acpt_cri);
		as_time_distribution_param->clk_qlt_acpt_cri = NULL;
	}
	free(as_time_distribution_param);
}

cJSON *as_time_distribution_param_convertToJSON(
	as_time_distribution_param_t *as_time_distribution_param) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(as_time_distribution_param == NULL) {
		printf(
			"as_time_distribution_param_convertToJSON() failed [AsTimeDistributionParam]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(as_time_distribution_param->is_as_time_dist_ind) {
		if(cJSON_AddBoolToObject(item, "asTimeDistInd",
		                         as_time_distribution_param->
		                         as_time_dist_ind) == NULL)
		{
			printf(
				"as_time_distribution_param_convertToJSON() failed [as_time_dist_ind]");
			goto end;
		}
	}

	if(as_time_distribution_param->is_uu_error_budget) {
		if(cJSON_AddNumberToObject(item, "uuErrorBudget",
		                           as_time_distribution_param->
		                           uu_error_budget) == NULL)
		{
			printf(
				"as_time_distribution_param_convertToJSON() failed [uu_error_budget]");
			goto end;
		}
	} else if(as_time_distribution_param->is_uu_error_budget_null) {
		if(cJSON_AddNullToObject(item, "uuErrorBudget") == NULL) {
			printf(
				"as_time_distribution_param_convertToJSON() failed [uu_error_budget]");
			goto end;
		}
	}

	if(as_time_distribution_param->clk_qlt_det_lvl) {
		cJSON *clk_qlt_det_lvl_local_JSON =
			clock_quality_detail_level_convertToJSON(
				as_time_distribution_param->clk_qlt_det_lvl);
		if(clk_qlt_det_lvl_local_JSON == NULL) {
			printf(
				"as_time_distribution_param_convertToJSON() failed [clk_qlt_det_lvl]");
			goto end;
		}
		cJSON_AddItemToObject(item, "clkQltDetLvl",
		                      clk_qlt_det_lvl_local_JSON);
		if(item->child == NULL) {
			printf(
				"as_time_distribution_param_convertToJSON() failed [clk_qlt_det_lvl]");
			goto end;
		}
	}

	if(as_time_distribution_param->clk_qlt_acpt_cri) {
		cJSON *clk_qlt_acpt_cri_local_JSON =
			clock_quality_acceptance_criterion_convertToJSON(
				as_time_distribution_param->clk_qlt_acpt_cri);
		if(clk_qlt_acpt_cri_local_JSON == NULL) {
			printf(
				"as_time_distribution_param_convertToJSON() failed [clk_qlt_acpt_cri]");
			goto end;
		}
		cJSON_AddItemToObject(item, "clkQltAcptCri",
		                      clk_qlt_acpt_cri_local_JSON);
		if(item->child == NULL) {
			printf(
				"as_time_distribution_param_convertToJSON() failed [clk_qlt_acpt_cri]");
			goto end;
		}
	}

end:
	return item;
}

as_time_distribution_param_t *as_time_distribution_param_parseFromJSON(
	cJSON *as_time_distribution_paramJSON) {
	as_time_distribution_param_t *as_time_distribution_param_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *as_time_dist_ind = NULL;
	cJSON *uu_error_budget = NULL;
	cJSON *clk_qlt_det_lvl = NULL;
	clock_quality_detail_level_t *clk_qlt_det_lvl_local_nonprim = NULL;
	cJSON *clk_qlt_acpt_cri = NULL;
	clock_quality_acceptance_criterion_t *clk_qlt_acpt_cri_local_nonprim =
		NULL;
	as_time_dist_ind = cJSON_GetObjectItemCaseSensitive(
		as_time_distribution_paramJSON, "asTimeDistInd");
	if(as_time_dist_ind) {
		if(!cJSON_IsBool(as_time_dist_ind)) {
			printf(
				"as_time_distribution_param_parseFromJSON() failed [as_time_dist_ind]");
			goto end;
		}
	}

	uu_error_budget = cJSON_GetObjectItemCaseSensitive(
		as_time_distribution_paramJSON, "uuErrorBudget");
	if(uu_error_budget) {
		if(!cJSON_IsNull(uu_error_budget)) {
			if(!cJSON_IsNumber(uu_error_budget)) {
				printf(
					"as_time_distribution_param_parseFromJSON() failed [uu_error_budget]");
				goto end;
			}
		}
	}

	clk_qlt_det_lvl = cJSON_GetObjectItemCaseSensitive(
		as_time_distribution_paramJSON, "clkQltDetLvl");
	if(clk_qlt_det_lvl) {
		clk_qlt_det_lvl_local_nonprim =
			clock_quality_detail_level_parseFromJSON(clk_qlt_det_lvl);
		if(!clk_qlt_det_lvl_local_nonprim) {
			printf(
				"clock_quality_detail_level_parseFromJSON failed [clk_qlt_det_lvl]");
			goto end;
		}
	}

	clk_qlt_acpt_cri = cJSON_GetObjectItemCaseSensitive(
		as_time_distribution_paramJSON, "clkQltAcptCri");
	if(clk_qlt_acpt_cri) {
		clk_qlt_acpt_cri_local_nonprim =
			clock_quality_acceptance_criterion_parseFromJSON(
				clk_qlt_acpt_cri);
		if(!clk_qlt_acpt_cri_local_nonprim) {
			printf(
				"clock_quality_acceptance_criterion_parseFromJSON failed [clk_qlt_acpt_cri]");
			goto end;
		}
	}

	as_time_distribution_param_local_var =
		as_time_distribution_param_create(
			as_time_dist_ind ? true : false,
			as_time_dist_ind ? as_time_dist_ind->valueint : 0,
			uu_error_budget &&
			cJSON_IsNull(uu_error_budget) ? true : false,
			uu_error_budget ? true : false,
			uu_error_budget ? uu_error_budget->valuedouble : 0,
			clk_qlt_det_lvl ? clk_qlt_det_lvl_local_nonprim : NULL,
			clk_qlt_acpt_cri ? clk_qlt_acpt_cri_local_nonprim : NULL
			);

	return as_time_distribution_param_local_var;
end:
	if(clk_qlt_det_lvl_local_nonprim) {
		clock_quality_detail_level_free(clk_qlt_det_lvl_local_nonprim);
		clk_qlt_det_lvl_local_nonprim = NULL;
	}
	if(clk_qlt_acpt_cri_local_nonprim) {
		clock_quality_acceptance_criterion_free(
			clk_qlt_acpt_cri_local_nonprim);
		clk_qlt_acpt_cri_local_nonprim = NULL;
	}
	return NULL;
}

as_time_distribution_param_t *as_time_distribution_param_copy(
	as_time_distribution_param_t *dst, as_time_distribution_param_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = as_time_distribution_param_convertToJSON(src);
	if(!item) {
		printf("as_time_distribution_param_convertToJSON() failed");
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

	as_time_distribution_param_free(dst);
	dst = as_time_distribution_param_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
