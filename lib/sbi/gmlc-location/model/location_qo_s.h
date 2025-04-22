/*
 * location_qo_s.h
 *
 * QoS of Location request.
 */

#ifndef _location_qo_s_H_
#define _location_qo_s_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "lcs_qos_class.h"
#include "minor_location_qo_s.h"
#include "response_time.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct location_qo_s_s location_qo_s_t;
typedef struct location_qo_s_s {
	bool is_h_accuracy;
	float h_accuracy;
	bool is_v_accuracy;
	float v_accuracy;
	bool is_vertical_requested;
	int vertical_requested;
	response_time_e response_time;
	list_t *minor_loc_qoses;
	lcs_qos_class_e lcs_qos_class;
} location_qo_s_t;

location_qo_s_t *location_qo_s_create(bool is_h_accuracy, float h_accuracy,
                                      bool is_v_accuracy, float v_accuracy,
                                      bool is_vertical_requested,
                                      int vertical_requested,
                                      response_time_e response_time,
                                      list_t *minor_loc_qoses,
                                      lcs_qos_class_e lcs_qos_class);
void location_qo_s_free(location_qo_s_t *location_qo_s);
location_qo_s_t *location_qo_s_parseFromJSON(cJSON *location_qo_sJSON);
cJSON *location_qo_s_convertToJSON(location_qo_s_t *location_qo_s);
location_qo_s_t *location_qo_s_copy(location_qo_s_t *dst, location_qo_s_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _location_qo_s_H_ */
