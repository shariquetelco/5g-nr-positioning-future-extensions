/*
 * minor_location_qo_s.h
 *
 * Contain Minor Location QoS.
 */

#ifndef _minor_location_qo_s_H_
#define _minor_location_qo_s_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct minor_location_qo_s_s minor_location_qo_s_t;
typedef struct minor_location_qo_s_s {
	bool is_h_accuracy;
	float h_accuracy;
	bool is_v_accuracy;
	float v_accuracy;
} minor_location_qo_s_t;

minor_location_qo_s_t *minor_location_qo_s_create(bool	is_h_accuracy,
                                                  float h_accuracy,
                                                  bool	is_v_accuracy,
                                                  float v_accuracy);
void minor_location_qo_s_free(minor_location_qo_s_t *minor_location_qo_s);
minor_location_qo_s_t *minor_location_qo_s_parseFromJSON(
	cJSON *minor_location_qo_sJSON);
cJSON *minor_location_qo_s_convertToJSON(
	minor_location_qo_s_t *minor_location_qo_s);
minor_location_qo_s_t *minor_location_qo_s_copy(minor_location_qo_s_t	*dst,
                                                minor_location_qo_s_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _minor_location_qo_s_H_ */
