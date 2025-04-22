/*
 * wlan_performance_req.h
 *
 * Represents other WLAN performance analytics requirements.
 */

#ifndef _wlan_performance_req_H_
#define _wlan_performance_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "matching_direction.h"
#include "wlan_ordering_criterion.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct wlan_performance_req_s wlan_performance_req_t;
typedef struct wlan_performance_req_s {
	list_t *ss_ids;
	list_t *bss_ids;
	struct wlan_ordering_criterion_s *wlan_order_criter;
	struct matching_direction_s *order;
} wlan_performance_req_t;

wlan_performance_req_t *wlan_performance_req_create(list_t *ss_ids,
                                                    list_t *bss_ids,
                                                    wlan_ordering_criterion_t *wlan_order_criter, matching_direction_t *order);
void wlan_performance_req_free(wlan_performance_req_t *wlan_performance_req);
wlan_performance_req_t *wlan_performance_req_parseFromJSON(
	cJSON *wlan_performance_reqJSON);
cJSON *wlan_performance_req_convertToJSON(
	wlan_performance_req_t *wlan_performance_req);
wlan_performance_req_t *wlan_performance_req_copy(
	wlan_performance_req_t	*dst,
	wlan_performance_req_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _wlan_performance_req_H_ */
