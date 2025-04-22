/*
 * los_nlos_measure_ind.h
 *
 *
 */

#ifndef _los_nlos_measure_ind_H_
#define _los_nlos_measure_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { los_nlos_measure_ind_NULL = 0, los_nlos_measure_ind_LOS,
	       los_nlos_measure_ind_NLOS } los_nlos_measure_ind_e;

char *los_nlos_measure_ind_ToString(
	los_nlos_measure_ind_e los_nlos_measure_ind);

los_nlos_measure_ind_e los_nlos_measure_ind_FromString(
	char *los_nlos_measure_ind);

#ifdef __cplusplus
}
#endif

#endif /* _los_nlos_measure_ind_H_ */
