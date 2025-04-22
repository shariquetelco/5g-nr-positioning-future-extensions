/*
 * wlan_performance_info.h
 *
 * The WLAN performance related information.
 */

#ifndef _wlan_performance_info_H_
#define _wlan_performance_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_area_info.h"
#include "wlan_per_ss_id_performance_info.h"
#include "wlan_per_ue_id_performance_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct wlan_performance_info_s wlan_performance_info_t;
typedef struct wlan_performance_info_s {
	struct network_area_info_s *network_area;
	list_t *wlan_per_ssid_infos;
	list_t *wlan_per_ue_id_infos;
} wlan_performance_info_t;

wlan_performance_info_t *wlan_performance_info_create(
	network_area_info_t *network_area, list_t *wlan_per_ssid_infos,
	list_t *wlan_per_ue_id_infos);
void wlan_performance_info_free(wlan_performance_info_t *wlan_performance_info);
wlan_performance_info_t *wlan_performance_info_parseFromJSON(
	cJSON *wlan_performance_infoJSON);
cJSON *wlan_performance_info_convertToJSON(
	wlan_performance_info_t *wlan_performance_info);
wlan_performance_info_t *wlan_performance_info_copy(
	wlan_performance_info_t *dst, wlan_performance_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _wlan_performance_info_H_ */
