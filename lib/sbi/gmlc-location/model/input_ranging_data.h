/*
 * input_ranging_data.h
 *
 * Contains the input parameters in PorvideRanging service operation
 */

#ifndef _input_ranging_data_H_
#define _input_ranging_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "external_client_type.h"
#include "location_qo_s.h"
#include "ranging_sl_result.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct input_ranging_data_s input_ranging_data_t;
typedef struct input_ranging_data_s {
	char *gpsi;
	char *supi;
	struct location_qo_s_s *location_qo_s;
	external_client_type_e external_client_type;
	char *external_client_identification;
	list_t *requested_ranging_sl_result;
	char *scheduled_loc_time;
} input_ranging_data_t;

input_ranging_data_t *input_ranging_data_create(char *gpsi, char *supi,
                                                location_qo_s_t *location_qo_s,
                                                external_client_type_e external_client_type, char *external_client_identification, list_t *requested_ranging_sl_result, char *scheduled_loc_time);
void input_ranging_data_free(input_ranging_data_t *input_ranging_data);
input_ranging_data_t *input_ranging_data_parseFromJSON(
	cJSON *input_ranging_dataJSON);
cJSON *input_ranging_data_convertToJSON(
	input_ranging_data_t *input_ranging_data);
input_ranging_data_t *input_ranging_data_copy(input_ranging_data_t	*dst,
                                              input_ranging_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _input_ranging_data_H_ */
