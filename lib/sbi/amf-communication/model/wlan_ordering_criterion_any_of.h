/*
 * wlan_ordering_criterion_any_of.h
 *
 *
 */

#ifndef _wlan_ordering_criterion_any_of_H_
#define _wlan_ordering_criterion_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { wlan_ordering_criterion_any_of_NULL = 0,
	       wlan_ordering_criterion_any_of_TIME_SLOT_START,
	       wlan_ordering_criterion_any_of_NUMBER_OF_UES,
	       wlan_ordering_criterion_any_of_RSSI,
	       wlan_ordering_criterion_any_of_RTT,
	       wlan_ordering_criterion_any_of_TRAFFIC_INFO }
wlan_ordering_criterion_any_of_e;

char *wlan_ordering_criterion_any_of_ToString(
	wlan_ordering_criterion_any_of_e wlan_ordering_criterion_any_of);

wlan_ordering_criterion_any_of_e wlan_ordering_criterion_any_of_FromString(
	char *wlan_ordering_criterion_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _wlan_ordering_criterion_any_of_H_ */
