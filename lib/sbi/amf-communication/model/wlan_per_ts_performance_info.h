/*
 * wlan_per_ts_performance_info.h
 *
 * WLAN performance information per Time Slot during the analytics target period.
 */

#ifndef _wlan_per_ts_performance_info_H_
#define _wlan_per_ts_performance_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "traffic_information.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct wlan_per_ts_performance_info_s wlan_per_ts_performance_info_t;
typedef struct wlan_per_ts_performance_info_s {
	char *ts_start;
	int ts_duration;
	bool is_rssi;
	int rssi;
	bool is_rtt;
	int rtt;
	struct traffic_information_s *traffic_info;
	bool is_number_of_ues;
	int number_of_ues;
	bool is_confidence;
	int confidence;
} wlan_per_ts_performance_info_t;

wlan_per_ts_performance_info_t *wlan_per_ts_performance_info_create(
	char *ts_start, int ts_duration, bool is_rssi, int rssi, bool is_rtt,
	int rtt, traffic_information_t *traffic_info, bool is_number_of_ues,
	int number_of_ues, bool is_confidence, int confidence);
void wlan_per_ts_performance_info_free(
	wlan_per_ts_performance_info_t *wlan_per_ts_performance_info);
wlan_per_ts_performance_info_t *wlan_per_ts_performance_info_parseFromJSON(
	cJSON *wlan_per_ts_performance_infoJSON);
cJSON *wlan_per_ts_performance_info_convertToJSON(
	wlan_per_ts_performance_info_t *wlan_per_ts_performance_info);
wlan_per_ts_performance_info_t *wlan_per_ts_performance_info_copy(
	wlan_per_ts_performance_info_t	*dst,
	wlan_per_ts_performance_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _wlan_per_ts_performance_info_H_ */
