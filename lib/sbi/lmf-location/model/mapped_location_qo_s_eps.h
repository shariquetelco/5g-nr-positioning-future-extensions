/*
 * mapped_location_qo_s_eps.h
 *
 * Mapped Location QoS for EPS.
 */

#ifndef _mapped_location_qo_s_eps_H_
#define _mapped_location_qo_s_eps_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mapped_location_qo_s_eps_s mapped_location_qo_s_eps_t;
typedef struct mapped_location_qo_s_eps_s {
	float h_accuracy;
	bool is_v_accuracy;
	float v_accuracy;
} mapped_location_qo_s_eps_t;

mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_create(
	float	h_accuracy,
	bool	is_v_accuracy,
	float	v_accuracy);
void mapped_location_qo_s_eps_free(
	mapped_location_qo_s_eps_t *mapped_location_qo_s_eps);
mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_parseFromJSON(
	cJSON *mapped_location_qo_s_epsJSON);
cJSON *mapped_location_qo_s_eps_convertToJSON(
	mapped_location_qo_s_eps_t *mapped_location_qo_s_eps);
mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_copy(
	mapped_location_qo_s_eps_t *dst, mapped_location_qo_s_eps_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _mapped_location_qo_s_eps_H_ */
