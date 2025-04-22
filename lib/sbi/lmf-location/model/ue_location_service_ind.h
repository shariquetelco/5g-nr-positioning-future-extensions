/*
 * ue_location_service_ind.h
 *
 *
 */

#ifndef _ue_location_service_ind_H_
#define _ue_location_service_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ue_location_service_ind_NULL = 0,
	       ue_location_service_ind_LOCATION_ESTIMATE,
	       ue_location_service_ind_LOCATION_ASSISTANCE_DATA }
ue_location_service_ind_e;

char *ue_location_service_ind_ToString(
	ue_location_service_ind_e ue_location_service_ind);

ue_location_service_ind_e ue_location_service_ind_FromString(
	char *ue_location_service_ind);

#ifdef __cplusplus
}
#endif

#endif /* _ue_location_service_ind_H_ */
