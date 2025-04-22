/*
 * pru_ind_any_of.h
 *
 *
 */

#ifndef _pru_ind_any_of_H_
#define _pru_ind_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { pru_ind_any_of_NULL = 0, pru_ind_any_of_NON_PRU,
	       pru_ind_any_of_STATIONARY_PRU,
	       pru_ind_any_of_NON_STATIONARY_PRU } pru_ind_any_of_e;

char *pru_ind_any_of_ToString(pru_ind_any_of_e pru_ind_any_of);

pru_ind_any_of_e pru_ind_any_of_FromString(char *pru_ind_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _pru_ind_any_of_H_ */
