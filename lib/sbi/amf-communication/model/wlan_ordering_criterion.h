/*
 * wlan_ordering_criterion.h
 *
 * Represents the order criterion for the list of WLAN performance information.   Possible values are: - TIME_SLOT_START: Indicates the order of time slot start. - NUMBER_OF_UES: Indicates the order of number of UEs. - RSSI: Indicates the order of RSSI. - RTT: Indicates the order of RTT. - TRAFFIC_INFO: Indicates the order of Traffic information.
 */

#ifndef _wlan_ordering_criterion_H_
#define _wlan_ordering_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "wlan_ordering_criterion_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct wlan_ordering_criterion_s wlan_ordering_criterion_t;
typedef struct wlan_ordering_criterion_s {} wlan_ordering_criterion_t;

wlan_ordering_criterion_t *wlan_ordering_criterion_create();
void wlan_ordering_criterion_free(
	wlan_ordering_criterion_t *wlan_ordering_criterion);
wlan_ordering_criterion_t *wlan_ordering_criterion_parseFromJSON(
	cJSON *wlan_ordering_criterionJSON);
cJSON *wlan_ordering_criterion_convertToJSON(
	wlan_ordering_criterion_t *wlan_ordering_criterion);
wlan_ordering_criterion_t *wlan_ordering_criterion_copy(
	wlan_ordering_criterion_t *dst, wlan_ordering_criterion_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _wlan_ordering_criterion_H_ */
