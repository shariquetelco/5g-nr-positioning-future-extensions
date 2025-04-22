/*
 * immediate_mdt_conf.h
 *
 * Immediate MDT Configuration
 */

#ifndef _immediate_mdt_conf_H_
#define _immediate_mdt_conf_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "area_scope.h"
#include "collection_period_rmm_lte_mdt.h"
#include "collection_period_rmm_nr_mdt.h"
#include "job_type.h"
#include "measurement_lte_for_mdt.h"
#include "measurement_nr_for_mdt.h"
#include "measurement_period_lte_mdt.h"
#include "plmn_id.h"
#include "positioning_method_mdt.h"
#include "report_amount_mdt.h"
#include "report_interval_mdt.h"
#include "report_interval_nr_mdt.h"
#include "reporting_trigger.h"
#include "sensor_measurement.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct immediate_mdt_conf_s immediate_mdt_conf_t;
typedef struct immediate_mdt_conf_s {
	struct job_type_s *job_type;
	list_t *measurement_lte_list;
	list_t *measurement_nr_list;
	list_t *reporting_trigger_list;
	struct report_interval_mdt_s *report_interval;
	struct report_interval_nr_mdt_s *report_interval_nr;
	struct report_amount_mdt_s *report_amount;
	bool is_event_threshold_rsrp;
	int event_threshold_rsrp;
	bool is_event_threshold_rsrq;
	int event_threshold_rsrq;
	bool is_event_threshold_rsrp_nr;
	int event_threshold_rsrp_nr;
	bool is_event_threshold_rsrq_nr;
	int event_threshold_rsrq_nr;
	struct collection_period_rmm_lte_mdt_s *collection_period_rmm_lte;
	struct collection_period_rmm_nr_mdt_s *collection_period_rmm_nr;
	struct measurement_period_lte_mdt_s *measurement_period_lte;
	struct area_scope_s *area_scope;
	struct positioning_method_mdt_s *positioning_method;
	list_t *add_positioning_method_list;
	list_t *mdt_allowed_plmn_id_list;
	list_t *sensor_measurement_list;
} immediate_mdt_conf_t;

immediate_mdt_conf_t *immediate_mdt_conf_create(job_type_t *job_type,
                                                list_t *measurement_lte_list,
                                                list_t *measurement_nr_list,
                                                list_t *reporting_trigger_list,
                                                report_interval_mdt_t *report_interval, report_interval_nr_mdt_t *report_interval_nr, report_amount_mdt_t *report_amount, bool is_event_threshold_rsrp, int event_threshold_rsrp, bool is_event_threshold_rsrq, int event_threshold_rsrq, bool is_event_threshold_rsrp_nr, int event_threshold_rsrp_nr, bool is_event_threshold_rsrq_nr, int event_threshold_rsrq_nr, collection_period_rmm_lte_mdt_t *collection_period_rmm_lte, collection_period_rmm_nr_mdt_t *collection_period_rmm_nr, measurement_period_lte_mdt_t *measurement_period_lte, area_scope_t *area_scope, positioning_method_mdt_t *positioning_method, list_t *add_positioning_method_list, list_t *mdt_allowed_plmn_id_list, list_t *sensor_measurement_list);
void immediate_mdt_conf_free(immediate_mdt_conf_t *immediate_mdt_conf);
immediate_mdt_conf_t *immediate_mdt_conf_parseFromJSON(
	cJSON *immediate_mdt_confJSON);
cJSON *immediate_mdt_conf_convertToJSON(
	immediate_mdt_conf_t *immediate_mdt_conf);
immediate_mdt_conf_t *immediate_mdt_conf_copy(immediate_mdt_conf_t	*dst,
                                              immediate_mdt_conf_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _immediate_mdt_conf_H_ */
