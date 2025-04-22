/*
 * amf_event_type_any_of.h
 *
 *
 */

#ifndef _amf_event_type_any_of_H_
#define _amf_event_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { amf_event_type_any_of_NULL = 0,
	       amf_event_type_any_of_LOCATION_REPORT,
	       amf_event_type_any_of_PRESENCE_IN_AOI_REPORT,
	       amf_event_type_any_of_TIMEZONE_REPORT,
	       amf_event_type_any_of_ACCESS_TYPE_REPORT,
	       amf_event_type_any_of_REGISTRATION_STATE_REPORT,
	       amf_event_type_any_of_CONNECTIVITY_STATE_REPORT,
	       amf_event_type_any_of_REACHABILITY_REPORT,
	       amf_event_type_any_of_COMMUNICATION_FAILURE_REPORT,
	       amf_event_type_any_of_UES_IN_AREA_REPORT,
	       amf_event_type_any_of_SUBSCRIPTION_ID_CHANGE,
	       amf_event_type_any_of_SUBSCRIPTION_ID_ADDITION,
	       amf_event_type_any_of_SUBSCRIPTION_TERMINATION,
	       amf_event_type_any_of_LOSS_OF_CONNECTIVITY,
	       amf_event_type_any_of__5GS_USER_STATE_REPORT,
	       amf_event_type_any_of_AVAILABILITY_AFTER_DDN_FAILURE,
	       amf_event_type_any_of_TYPE_ALLOCATION_CODE_REPORT,
	       amf_event_type_any_of_FREQUENT_MOBILITY_REGISTRATION_REPORT,
	       amf_event_type_any_of_SNSSAI_TA_MAPPING_REPORT,
	       amf_event_type_any_of_UE_LOCATION_TRENDS,
	       amf_event_type_any_of_UE_ACCESS_BEHAVIOR_TRENDS,
	       amf_event_type_any_of_UE_MM_TRANSACTION_REPORT }
amf_event_type_any_of_e;

char *amf_event_type_any_of_ToString(
	amf_event_type_any_of_e amf_event_type_any_of);

amf_event_type_any_of_e amf_event_type_any_of_FromString(
	char *amf_event_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _amf_event_type_any_of_H_ */
