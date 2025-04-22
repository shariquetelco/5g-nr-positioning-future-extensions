/*
 * nas_security_mode.h
 *
 * Indicates the NAS Security Mode
 */

#ifndef _nas_security_mode_H_
#define _nas_security_mode_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ciphering_algorithm.h"
#include "integrity_algorithm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nas_security_mode_s nas_security_mode_t;
typedef struct nas_security_mode_s {
	integrity_algorithm_e integrity_algorithm;
	ciphering_algorithm_e ciphering_algorithm;
} nas_security_mode_t;

nas_security_mode_t *nas_security_mode_create(
	integrity_algorithm_e	integrity_algorithm,
	ciphering_algorithm_e	ciphering_algorithm);
void nas_security_mode_free(nas_security_mode_t *nas_security_mode);
nas_security_mode_t *nas_security_mode_parseFromJSON(
	cJSON *nas_security_modeJSON);
cJSON *nas_security_mode_convertToJSON(nas_security_mode_t *nas_security_mode);
nas_security_mode_t *nas_security_mode_copy(nas_security_mode_t *dst,
                                            nas_security_mode_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nas_security_mode_H_ */
