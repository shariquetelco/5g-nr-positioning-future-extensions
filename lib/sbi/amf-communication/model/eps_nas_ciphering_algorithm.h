/*
 * eps_nas_ciphering_algorithm.h
 *
 *
 */

#ifndef _eps_nas_ciphering_algorithm_H_
#define _eps_nas_ciphering_algorithm_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { eps_nas_ciphering_algorithm_NULL = 0,
	       eps_nas_ciphering_algorithm_EEA0,
	       eps_nas_ciphering_algorithm_EEA1,
	       eps_nas_ciphering_algorithm_EEA2,
	       eps_nas_ciphering_algorithm_EEA3 } eps_nas_ciphering_algorithm_e;

char *eps_nas_ciphering_algorithm_ToString(
	eps_nas_ciphering_algorithm_e eps_nas_ciphering_algorithm);

eps_nas_ciphering_algorithm_e eps_nas_ciphering_algorithm_FromString(
	char *eps_nas_ciphering_algorithm);

#ifdef __cplusplus
}
#endif

#endif /* _eps_nas_ciphering_algorithm_H_ */
