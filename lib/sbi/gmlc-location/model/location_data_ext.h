/*
 * location_data_ext.h
 *
 * Extended Location Data for UEs
 */

#ifndef _location_data_ext_H_
#define _location_data_ext_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "accuracy_fulfilment_indicator.h"
#include "civic_address.h"
#include "geographic_area.h"
#include "gnss_positioning_method_and_usage.h"
#include "high_accuracy_gnss_metrics.h"
#include "indoor_outdoor_ind.h"
#include "local_area.h"
#include "location_data.h"
#include "location_privacy_ver_result.h"
#include "los_nlos_measure_ind.h"
#include "minor_location_qo_s.h"
#include "model_2_d_relative_location.h"
#include "model_3_d_relative_location.h"
#include "periodic_event_info.h"
#include "positioning_method_and_usage.h"
#include "range_direction.h"
#include "success_type.h"
#include "velocity_estimate.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct location_data_ext_s location_data_ext_t;
typedef struct location_data_ext_s {
	char *gpsi;
	char *supi;
	struct geographic_area_s *location_estimate;
	struct civic_address_s *civic_address;
	struct local_area_s *local_location_estimate;
	bool is_age_of_location_estimate;
	int age_of_location_estimate;
	char *timestamp_of_location_estimate;
	list_t *positioning_data_list;
	list_t *gnss_positioning_data_list;
	accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator;
	struct velocity_estimate_s *ue_velocity;
	char *ldr_reference;
	bool is_altitude;
	double altitude;
	char *serving_lmf_identification;
	struct location_privacy_ver_result_s *location_privacy_ver_result;
	success_type_e success_type;
	struct minor_location_qo_s_s *achieved_qos;
	bool is_direct_report_ind;
	int direct_report_ind;
	struct periodic_event_info_s *accepted_periodic_event_info;
	struct high_accuracy_gnss_metrics_s *ha_gnss_metrics;
	los_nlos_measure_ind_e los_nlos_measure_ind;
	indoor_outdoor_ind_e indoor_outdoor_ind;
	char *related_applicationlayer_id;
	struct range_direction_s *distance_direction;
	struct model_2_d_relative_location_s *_2d_relative_location;
	struct model_3_d_relative_location_s *_3d_relative_location;
	struct velocity_estimate_s *relative_velocity;
} location_data_ext_t;

location_data_ext_t *location_data_ext_create(char *gpsi, char *supi,
                                              geographic_area_t *location_estimate, civic_address_t *civic_address, local_area_t *local_location_estimate, bool is_age_of_location_estimate, int age_of_location_estimate, char *timestamp_of_location_estimate, list_t *positioning_data_list, list_t *gnss_positioning_data_list, accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator, velocity_estimate_t *ue_velocity, char *ldr_reference, bool is_altitude, double altitude, char *serving_lmf_identification, location_privacy_ver_result_t *location_privacy_ver_result, success_type_e success_type, minor_location_qo_s_t *achieved_qos, bool is_direct_report_ind, int direct_report_ind, periodic_event_info_t *accepted_periodic_event_info, high_accuracy_gnss_metrics_t *ha_gnss_metrics, los_nlos_measure_ind_e los_nlos_measure_ind, indoor_outdoor_ind_e indoor_outdoor_ind, char *related_applicationlayer_id, range_direction_t *distance_direction, model_2_d_relative_location_t *_2d_relative_location, model_3_d_relative_location_t *_3d_relative_location, velocity_estimate_t *relative_velocity);
void location_data_ext_free(location_data_ext_t *location_data_ext);
location_data_ext_t *location_data_ext_parseFromJSON(
	cJSON *location_data_extJSON);
cJSON *location_data_ext_convertToJSON(location_data_ext_t *location_data_ext);
location_data_ext_t *location_data_ext_copy(location_data_ext_t *dst,
                                            location_data_ext_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _location_data_ext_H_ */
