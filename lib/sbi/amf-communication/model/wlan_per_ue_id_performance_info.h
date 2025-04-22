/*
 * wlan_per_ue_id_performance_info.h
 *
 * The WLAN performance per UE ID.
 */

#ifndef _wlan_per_ue_id_performance_info_H_
#define _wlan_per_ue_id_performance_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "wlan_per_ts_performance_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct wlan_per_ue_id_performance_info_s
        wlan_per_ue_id_performance_info_t;
typedef struct wlan_per_ue_id_performance_info_s {
	char *supi;
	char *gpsi;
	list_t *wlan_per_ts_infos;
} wlan_per_ue_id_performance_info_t;

wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info_create(
	char *supi, char *gpsi, list_t *wlan_per_ts_infos);
void wlan_per_ue_id_performance_info_free(
	wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info);
wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info_parseFromJSON(
	cJSON *wlan_per_ue_id_performance_infoJSON);
cJSON *wlan_per_ue_id_performance_info_convertToJSON(
	wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info);
wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info_copy(
	wlan_per_ue_id_performance_info_t	*dst,
	wlan_per_ue_id_performance_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _wlan_per_ue_id_performance_info_H_ */
