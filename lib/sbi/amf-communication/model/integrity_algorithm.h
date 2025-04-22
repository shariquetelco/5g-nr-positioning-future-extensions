/*
 * integrity_algorithm.h
 *
 *
 */

#ifndef _integrity_algorithm_H_
#define _integrity_algorithm_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { integrity_algorithm_NULL = 0, integrity_algorithm_NIA0,
	       integrity_algorithm_NIA1, integrity_algorithm_NIA2,
	       integrity_algorithm_NIA3 } integrity_algorithm_e;

char *integrity_algorithm_ToString(integrity_algorithm_e integrity_algorithm);

integrity_algorithm_e integrity_algorithm_FromString(char *integrity_algorithm);

#ifdef __cplusplus
}
#endif

#endif /* _integrity_algorithm_H_ */
