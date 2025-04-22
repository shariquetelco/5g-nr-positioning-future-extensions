/*
 * up_cum_evt_rpt_criteria.h
 *
 * Criteria for sending cumulative events reports over control plane
 */

#ifndef _up_cum_evt_rpt_criteria_H_
#define _up_cum_evt_rpt_criteria_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct up_cum_evt_rpt_criteria_s up_cum_evt_rpt_criteria_t;
typedef struct up_cum_evt_rpt_criteria_s {
	bool is_evt_rpt_time_criteria;
	int evt_rpt_time_criteria;
	bool is_evt_rpt_count_criteria;
	int evt_rpt_count_criteria;
} up_cum_evt_rpt_criteria_t;

up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_create(
	bool is_evt_rpt_time_criteria, int evt_rpt_time_criteria,
	bool is_evt_rpt_count_criteria, int evt_rpt_count_criteria);
void up_cum_evt_rpt_criteria_free(
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria);
up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_parseFromJSON(
	cJSON *up_cum_evt_rpt_criteriaJSON);
cJSON *up_cum_evt_rpt_criteria_convertToJSON(
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria);
up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_copy(
	up_cum_evt_rpt_criteria_t *dst, up_cum_evt_rpt_criteria_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _up_cum_evt_rpt_criteria_H_ */
