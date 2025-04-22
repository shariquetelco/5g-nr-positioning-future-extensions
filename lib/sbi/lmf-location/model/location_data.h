/*
 * location_data.h
 *
 * Information within Determine Location Response.
 */

#ifndef _location_data_H_
#define _location_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "accuracy_fulfilment_indicator.h"
#include "civic_address.h"
#include "ecgi.h"
#include "geographic_area.h"
#include "gnss_positioning_method_and_usage.h"
#include "high_accuracy_gnss_metrics.h"
#include "indoor_outdoor_ind.h"
#include "local_area.h"
#include "los_nlos_measure_ind.h"
#include "minor_location_qo_s.h"
#include "model_2_d_relative_location.h"
#include "model_3_d_relative_location.h"
#include "ncgi.h"
#include "periodic_event_info.h"
#include "positioning_method_and_usage.h"
#include "range_direction.h"
#include "ue_area_indication.h"
#include "velocity_estimate.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct location_data_s location_data_t;
typedef struct location_data_s {
	struct geographic_area_s *location_estimate;
	accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator;
	bool is_age_of_location_estimate;
	int age_of_location_estimate;
	char *timestamp_of_location_estimate;
	struct velocity_estimate_s *velocity_estimate;
	struct civic_address_s *civic_address;
	struct local_area_s *local_location_estimate;
	list_t *positioning_data_list;
	list_t *gnss_positioning_data_list;
	struct ecgi_s *ecgi;
	struct ncgi_s *ncgi;
	bool is_altitude;
	double altitude;
	bool is_barometric_pressure;
	int barometric_pressure;
	char *serving_lmf_identification;
	char *ue_positioning_cap;
	struct ue_area_indication_s *ue_area_ind;
	char *supported_features;
	struct minor_location_qo_s_s *achieved_qos;
	bool is_direct_report_ind;
	int direct_report_ind;
	indoor_outdoor_ind_e indoor_outdoor_ind;
	struct periodic_event_info_s *accepted_periodic_event_info;
	struct high_accuracy_gnss_metrics_s *ha_gnss_metrics;
	los_nlos_measure_ind_e los_nlos_measure_ind;
	char *related_applicationlayer_id;
	struct range_direction_s *distance_direction;
	struct model_2_d_relative_location_s *_2d_relative_location;
	struct model_3_d_relative_location_s *_3d_relative_location;
	struct velocity_estimate_s *relative_velocity;
	char *ranging_sl_capability;
} location_data_t;

location_data_t *location_data_create(geographic_area_t *location_estimate,
                                      accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator, bool is_age_of_location_estimate, int age_of_location_estimate, char *timestamp_of_location_estimate, velocity_estimate_t *velocity_estimate, civic_address_t *civic_address, local_area_t *local_location_estimate, list_t *positioning_data_list, list_t *gnss_positioning_data_list, ecgi_t *ecgi, ncgi_t *ncgi, bool is_altitude, double altitude, bool is_barometric_pressure, int barometric_pressure, char *serving_lmf_identification, char *ue_positioning_cap, ue_area_indication_t *ue_area_ind, char *supported_features, minor_location_qo_s_t *achieved_qos, bool is_direct_report_ind, int direct_report_ind, indoor_outdoor_ind_e indoor_outdoor_ind, periodic_event_info_t *accepted_periodic_event_info, high_accuracy_gnss_metrics_t *ha_gnss_metrics, los_nlos_measure_ind_e los_nlos_measure_ind, char *related_applicationlayer_id, range_direction_t *distance_direction, model_2_d_relative_location_t *_2d_relative_location, model_3_d_relative_location_t *_3d_relative_location, velocity_estimate_t *relative_velocity, char *ranging_sl_capability);
void location_data_free(location_data_t *location_data);
location_data_t *location_data_parseFromJSON(cJSON *location_dataJSON);
cJSON *location_data_convertToJSON(location_data_t *location_data);
location_data_t *location_data_copy(location_data_t *dst, location_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _location_data_H_ */
