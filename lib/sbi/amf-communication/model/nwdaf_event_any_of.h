/*
 * nwdaf_event_any_of.h
 *
 *
 */

#ifndef _nwdaf_event_any_of_H_
#define _nwdaf_event_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { nwdaf_event_any_of_NULL = 0, nwdaf_event_any_of_SLICE_LOAD_LEVEL,
	       nwdaf_event_any_of_NETWORK_PERFORMANCE,
	       nwdaf_event_any_of_NF_LOAD,
	       nwdaf_event_any_of_SERVICE_EXPERIENCE,
	       nwdaf_event_any_of_UE_MOBILITY,
	       nwdaf_event_any_of_UE_COMMUNICATION,
	       nwdaf_event_any_of_QOS_SUSTAINABILITY,
	       nwdaf_event_any_of_ABNORMAL_BEHAVIOUR,
	       nwdaf_event_any_of_USER_DATA_CONGESTION,
	       nwdaf_event_any_of_NSI_LOAD_LEVEL,
	       nwdaf_event_any_of_DN_PERFORMANCE,
	       nwdaf_event_any_of_DISPERSION, nwdaf_event_any_of_RED_TRANS_EXP,
	       nwdaf_event_any_of_WLAN_PERFORMANCE,
	       nwdaf_event_any_of_SM_CONGESTION,
	       nwdaf_event_any_of_PFD_DETERMINATION,
	       nwdaf_event_any_of_PDU_SESSION_TRAFFIC,
	       nwdaf_event_any_of_E2E_DATA_VOL_TRANS_TIME,
	       nwdaf_event_any_of_MOVEMENT_BEHAVIOUR,
	       nwdaf_event_any_of_NUM_OF_UE,
	       nwdaf_event_any_of_MOV_UE_RATIO, nwdaf_event_any_of_AVR_SPEED,
	       nwdaf_event_any_of_SPEED_THRESHOLD,
	       nwdaf_event_any_of_MOV_UE_DIRECTION,
	       nwdaf_event_any_of_LOC_ACCURACY,
	       nwdaf_event_any_of_RELATIVE_PROXIMITY } nwdaf_event_any_of_e;

char *nwdaf_event_any_of_ToString(nwdaf_event_any_of_e nwdaf_event_any_of);

nwdaf_event_any_of_e nwdaf_event_any_of_FromString(char *nwdaf_event_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _nwdaf_event_any_of_H_ */
