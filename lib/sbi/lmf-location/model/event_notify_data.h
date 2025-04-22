/*
 * event_notify_data.h
 *
 * Information within Event Notify Request.
 */

#ifndef _event_notify_data_H_
#define _event_notify_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "civic_address.h"
#include "geographic_area.h"
#include "gnss_positioning_method_and_usage.h"
#include "high_accuracy_gnss_metrics.h"
#include "indoor_outdoor_ind.h"
#include "local_area.h"
#include "los_nlos_measure_ind.h"
#include "minor_location_qo_s.h"
#include "model_2_d_relative_location.h"
#include "model_3_d_relative_location.h"
#include "positioning_method_and_usage.h"
#include "range_direction.h"
#include "reported_event_type.h"
#include "termination_cause.h"
#include "velocity_estimate.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct event_notify_data_s event_notify_data_t;
typedef struct event_notify_data_s {
	reported_event_type_e reported_event_type;
	char *supi;
	char *gpsi;
	char *hgmlc_call_back_uri;
	char *ldr_reference;
	char *lir_reference;
	struct geographic_area_s *location_estimate;
	bool is_age_of_location_estimate;
	int age_of_location_estimate;
	char *timestamp_of_location_estimate;
	struct civic_address_s *civic_address;
	struct local_area_s *local_location_estimate;
	list_t *positioning_data_list;
	list_t *gnss_positioning_data_list;
	char *serving_lm_fidentification;
	termination_cause_e termination_cause;
	struct velocity_estimate_s *velocity_estimate;
	bool is_altitude;
	double altitude;
	struct minor_location_qo_s_s *achieved_qos;
	char *supported_features;
	indoor_outdoor_ind_e indoor_outdoor_ind;
	struct high_accuracy_gnss_metrics_s *ha_gnss_metrics;
	los_nlos_measure_ind_e los_nlos_measure_ind;
	bool is_up_loc_rep_stat_af;
	int up_loc_rep_stat_af;
	char *related_applicationlayer_id;
	struct range_direction_s *distance_direction;
	struct model_2_d_relative_location_s *_2d_relative_location;
	struct model_3_d_relative_location_s *_3d_relative_location;
	struct velocity_estimate_s *relative_velocity;
} event_notify_data_t;

event_notify_data_t *event_notify_data_create(
	reported_event_type_e reported_event_type, char *supi, char *gpsi,
	char *hgmlc_call_back_uri, char *ldr_reference, char *lir_reference,
	geographic_area_t *location_estimate, bool is_age_of_location_estimate,
	int age_of_location_estimate, char *timestamp_of_location_estimate,
	civic_address_t *civic_address, local_area_t *local_location_estimate,
	list_t *positioning_data_list, list_t *gnss_positioning_data_list,
	char *serving_lm_fidentification, termination_cause_e termination_cause,
	velocity_estimate_t *velocity_estimate, bool is_altitude,
	double altitude, minor_location_qo_s_t *achieved_qos,
	char *supported_features, indoor_outdoor_ind_e indoor_outdoor_ind,
	high_accuracy_gnss_metrics_t *ha_gnss_metrics,
	los_nlos_measure_ind_e los_nlos_measure_ind, bool is_up_loc_rep_stat_af,
	int up_loc_rep_stat_af, char *related_applicationlayer_id,
	range_direction_t *distance_direction,
	model_2_d_relative_location_t *_2d_relative_location,
	model_3_d_relative_location_t *_3d_relative_location,
	velocity_estimate_t *relative_velocity);
void event_notify_data_free(event_notify_data_t *event_notify_data);
event_notify_data_t *event_notify_data_parseFromJSON(
	cJSON *event_notify_dataJSON);
cJSON *event_notify_data_convertToJSON(event_notify_data_t *event_notify_data);
event_notify_data_t *event_notify_data_copy(event_notify_data_t *dst,
                                            event_notify_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _event_notify_data_H_ */
