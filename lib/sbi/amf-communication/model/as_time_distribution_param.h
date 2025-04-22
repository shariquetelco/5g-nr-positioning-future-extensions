/*
 * as_time_distribution_param.h
 *
 * Contains the 5G acess stratum time distribution parameters.
 */

#ifndef _as_time_distribution_param_H_
#define _as_time_distribution_param_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "clock_quality_acceptance_criterion.h"
#include "clock_quality_detail_level.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct as_time_distribution_param_s as_time_distribution_param_t;
typedef struct as_time_distribution_param_s {
	bool is_as_time_dist_ind;
	int as_time_dist_ind;
	bool is_uu_error_budget_null;
	bool is_uu_error_budget;
	int uu_error_budget;
	struct clock_quality_detail_level_s *clk_qlt_det_lvl;
	struct clock_quality_acceptance_criterion_s *clk_qlt_acpt_cri;
} as_time_distribution_param_t;

as_time_distribution_param_t *as_time_distribution_param_create(
	bool is_as_time_dist_ind, int as_time_dist_ind,
	bool is_uu_error_budget_null, bool is_uu_error_budget,
	int uu_error_budget, clock_quality_detail_level_t *clk_qlt_det_lvl,
	clock_quality_acceptance_criterion_t *clk_qlt_acpt_cri);
void as_time_distribution_param_free(
	as_time_distribution_param_t *as_time_distribution_param);
as_time_distribution_param_t *as_time_distribution_param_parseFromJSON(
	cJSON *as_time_distribution_paramJSON);
cJSON *as_time_distribution_param_convertToJSON(
	as_time_distribution_param_t *as_time_distribution_param);
as_time_distribution_param_t *as_time_distribution_param_copy(
	as_time_distribution_param_t *dst, as_time_distribution_param_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _as_time_distribution_param_H_ */
