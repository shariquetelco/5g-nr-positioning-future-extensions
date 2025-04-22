/*
 * indoor_outdoor_ind.h
 *
 *
 */

#ifndef _indoor_outdoor_ind_H_
#define _indoor_outdoor_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { indoor_outdoor_ind_NULL = 0, indoor_outdoor_ind_INDOOR,
	       indoor_outdoor_ind_OUTDOOR } indoor_outdoor_ind_e;

char *indoor_outdoor_ind_ToString(indoor_outdoor_ind_e indoor_outdoor_ind);

indoor_outdoor_ind_e indoor_outdoor_ind_FromString(char *indoor_outdoor_ind);

#ifdef __cplusplus
}
#endif

#endif /* _indoor_outdoor_ind_H_ */
