/*
 * ciphering_algorithm.h
 *
 *
 */

#ifndef _ciphering_algorithm_H_
#define _ciphering_algorithm_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ciphering_algorithm_NULL = 0, ciphering_algorithm_NEA0,
	       ciphering_algorithm_NEA1, ciphering_algorithm_NEA2,
	       ciphering_algorithm_NEA3 } ciphering_algorithm_e;

char *ciphering_algorithm_ToString(ciphering_algorithm_e ciphering_algorithm);

ciphering_algorithm_e ciphering_algorithm_FromString(char *ciphering_algorithm);

#ifdef __cplusplus
}
#endif

#endif /* _ciphering_algorithm_H_ */
