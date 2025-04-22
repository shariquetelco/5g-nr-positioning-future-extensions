/*
 * loc_update_data.h
 *
 * Contains the input parameters in LocationUpdate service operation
 */

#ifndef _loc_update_data_H_
#define _loc_update_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "accuracy_fulfilment_indicator.h"
#include "civic_address.h"
#include "geographic_area.h"
#include "lcs_qos_class.h"
#include "location_request_type.h"
#include "pseudonym_indicator.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct loc_update_data_s loc_update_data_t;
typedef struct loc_update_data_s {
	char *gpsi;
	char *supi;
	pseudonym_indicator_e pseudonym_indicator;
	location_request_type_e location_request_type;
	struct geographic_area_s *location_estimate;
	int age_of_location_estimate;
	char *timestamp_of_location_estimate;
	accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator;
	struct civic_address_s *civic_address;
	lcs_qos_class_e lcs_qos_class;
	char *external_client_identification;
	char *af_id;
	char *gmlc_number;
	bool is_lcs_service_type;
	int lcs_service_type;
} loc_update_data_t;

loc_update_data_t *loc_update_data_create(char *gpsi, char *supi,
                                          pseudonym_indicator_e pseudonym_indicator, location_request_type_e location_request_type, geographic_area_t *location_estimate, int age_of_location_estimate, char *timestamp_of_location_estimate, accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator, civic_address_t *civic_address, lcs_qos_class_e lcs_qos_class, char *external_client_identification, char *af_id, char *gmlc_number, bool is_lcs_service_type, int lcs_service_type);
void loc_update_data_free(loc_update_data_t *loc_update_data);
loc_update_data_t *loc_update_data_parseFromJSON(cJSON *loc_update_dataJSON);
cJSON *loc_update_data_convertToJSON(loc_update_data_t *loc_update_data);
loc_update_data_t *loc_update_data_copy(loc_update_data_t	*dst,
                                        loc_update_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _loc_update_data_H_ */
