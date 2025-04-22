/*
 * ranging_data.h
 *
 * Contains the response parameters in ProvideRanging service operation
 */

#ifndef _ranging_data_H_
#define _ranging_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "minor_location_qo_s.h"
#include "model_2_d_relative_location.h"
#include "model_3_d_relative_location.h"
#include "positioning_method_and_usage.h"
#include "range_direction.h"
#include "velocity_estimate.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ranging_data_s ranging_data_t;
typedef struct ranging_data_s {
	char *gpsi;
	char *supi;
	char *timestamp_of_location_estimate;
	struct minor_location_qo_s_s *achieved_qos;
	list_t *ranging_data_list;
	char *related_applicationlayer_id;
	struct range_direction_s *range_direction;
	struct model_2_d_relative_location_s *_2d_relative_location;
	struct model_3_d_relative_location_s *_3d_relative_location;
	struct velocity_estimate_s *relative_velocity;
} ranging_data_t;

ranging_data_t *ranging_data_create(char *gpsi, char *supi,
                                    char *timestamp_of_location_estimate,
                                    minor_location_qo_s_t *achieved_qos,
                                    list_t *ranging_data_list,
                                    char *related_applicationlayer_id,
                                    range_direction_t *range_direction,
                                    model_2_d_relative_location_t *_2d_relative_location, model_3_d_relative_location_t *_3d_relative_location, velocity_estimate_t *relative_velocity);
void ranging_data_free(ranging_data_t *ranging_data);
ranging_data_t *ranging_data_parseFromJSON(cJSON *ranging_dataJSON);
cJSON *ranging_data_convertToJSON(ranging_data_t *ranging_data);
ranging_data_t *ranging_data_copy(ranging_data_t *dst, ranging_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ranging_data_H_ */
