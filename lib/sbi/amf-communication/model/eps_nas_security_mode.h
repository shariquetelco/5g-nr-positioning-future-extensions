/*
 * eps_nas_security_mode.h
 *
 * Indicates the EPS NAS Security Mode
 */

#ifndef _eps_nas_security_mode_H_
#define _eps_nas_security_mode_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "eps_nas_ciphering_algorithm.h"
#include "eps_nas_integrity_algorithm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct eps_nas_security_mode_s eps_nas_security_mode_t;
typedef struct eps_nas_security_mode_s {
	eps_nas_integrity_algorithm_e integrity_algorithm;
	eps_nas_ciphering_algorithm_e ciphering_algorithm;
} eps_nas_security_mode_t;

eps_nas_security_mode_t *eps_nas_security_mode_create(
	eps_nas_integrity_algorithm_e	integrity_algorithm,
	eps_nas_ciphering_algorithm_e	ciphering_algorithm);
void eps_nas_security_mode_free(eps_nas_security_mode_t *eps_nas_security_mode);
eps_nas_security_mode_t *eps_nas_security_mode_parseFromJSON(
	cJSON *eps_nas_security_modeJSON);
cJSON *eps_nas_security_mode_convertToJSON(
	eps_nas_security_mode_t *eps_nas_security_mode);
eps_nas_security_mode_t *eps_nas_security_mode_copy(
	eps_nas_security_mode_t *dst, eps_nas_security_mode_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _eps_nas_security_mode_H_ */
