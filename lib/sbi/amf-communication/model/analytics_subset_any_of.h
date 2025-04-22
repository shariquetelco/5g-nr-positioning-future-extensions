/*
 * analytics_subset_any_of.h
 *
 *
 */

#ifndef _analytics_subset_any_of_H_
#define _analytics_subset_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { analytics_subset_any_of_NULL = 0,
	       analytics_subset_any_of_NUM_OF_UE_REG,
	       analytics_subset_any_of_NUM_OF_PDU_SESS_ESTBL,
	       analytics_subset_any_of_RES_USAGE,
	       analytics_subset_any_of_NUM_OF_EXCEED_RES_USAGE_LOAD_LEVEL_THR,
	       analytics_subset_any_of_PERIOD_OF_EXCEED_RES_USAGE_LOAD_LEVEL_THR,
	       analytics_subset_any_of_EXCEED_LOAD_LEVEL_THR_IND,
	       analytics_subset_any_of_LIST_OF_TOP_APP_UL,
	       analytics_subset_any_of_LIST_OF_TOP_APP_DL,
	       analytics_subset_any_of_NF_STATUS,
	       analytics_subset_any_of_NF_RESOURCE_USAGE,
	       analytics_subset_any_of_NF_LOAD,
	       analytics_subset_any_of_NF_PEAK_LOAD,
	       analytics_subset_any_of_NF_LOAD_AVG_IN_AOI,
	       analytics_subset_any_of_DISPER_AMOUNT,
	       analytics_subset_any_of_DISPER_CLASS,
	       analytics_subset_any_of_RANKING,
	       analytics_subset_any_of_PERCENTILE_RANKING,
	       analytics_subset_any_of_RSSI, analytics_subset_any_of_RTT,
	       analytics_subset_any_of_TRAFFIC_INFO,
	       analytics_subset_any_of_NUMBER_OF_UES,
	       analytics_subset_any_of_APP_LIST_FOR_UE_COMM,
	       analytics_subset_any_of_N4_SESS_INACT_TIMER_FOR_UE_COMM,
	       analytics_subset_any_of_AVG_TRAFFIC_RATE,
	       analytics_subset_any_of_MAX_TRAFFIC_RATE,
	       analytics_subset_any_of_AGG_TRAFFIC_RATE,
	       analytics_subset_any_of_VAR_TRAFFIC_RATE,
	       analytics_subset_any_of_AVG_PACKET_DELAY,
	       analytics_subset_any_of_MAX_PACKET_DELAY,
	       analytics_subset_any_of_VAR_PACKET_DELAY,
	       analytics_subset_any_of_AVG_PACKET_LOSS_RATE,
	       analytics_subset_any_of_MAX_PACKET_LOSS_RATE,
	       analytics_subset_any_of_VAR_PACKET_LOSS_RATE,
	       analytics_subset_any_of_UE_LOCATION,
	       analytics_subset_any_of_LIST_OF_HIGH_EXP_UE,
	       analytics_subset_any_of_LIST_OF_MEDIUM_EXP_UE,
	       analytics_subset_any_of_LIST_OF_LOW_EXP_UE,
	       analytics_subset_any_of_AVG_UL_PKT_DROP_RATE,
	       analytics_subset_any_of_VAR_UL_PKT_DROP_RATE,
	       analytics_subset_any_of_AVG_DL_PKT_DROP_RATE,
	       analytics_subset_any_of_VAR_DL_PKT_DROP_RATE,
	       analytics_subset_any_of_AVG_UL_PKT_DELAY,
	       analytics_subset_any_of_VAR_UL_PKT_DELAY,
	       analytics_subset_any_of_AVG_DL_PKT_DELAY,
	       analytics_subset_any_of_VAR_DL_PKT_DELAY,
	       analytics_subset_any_of_TRAFFIC_MATCH_TD,
	       analytics_subset_any_of_TRAFFIC_UNMATCH_TD,
	       analytics_subset_any_of_NUMBER_OF_UE,
	       analytics_subset_any_of_UE_GEOG_DIST,
	       analytics_subset_any_of_UE_DIRECTION,
	       analytics_subset_any_of_AVG_E2E_UL_PKT_DELAY,
	       analytics_subset_any_of_VAR_E2E_UL_PKT_DELAY,
	       analytics_subset_any_of_AVG_E2E_DL_PKT_DELAY,
	       analytics_subset_any_of_VAR_E2E_DL_PKT_DELAY,
	       analytics_subset_any_of_AVG_E2E_UL_PKT_LOSS_RATE,
	       analytics_subset_any_of_VAR_E2E_UL_PKT_LOSS_RATE,
	       analytics_subset_any_of_AVG_E2E_DL_PKT_LOSS_RATE,
	       analytics_subset_any_of_VAR_E2E_DL_PKT_LOSS_RATE,
	       analytics_subset_any_of_E2E_DATA_VOL_TRANS_TIME_FOR_UE_LIST,
	       analytics_subset_any_of_IN_OUT_PERCENT,
	       analytics_subset_any_of_TIME_TO_COLLISION }
analytics_subset_any_of_e;

char *analytics_subset_any_of_ToString(
	analytics_subset_any_of_e analytics_subset_any_of);

analytics_subset_any_of_e analytics_subset_any_of_FromString(
	char *analytics_subset_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _analytics_subset_any_of_H_ */
