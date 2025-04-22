#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "analytics_subset_any_of.h"

char *analytics_subset_any_of_ToString(
	analytics_subset_any_of_e analytics_subset_any_of) {
	const char *analytics_subset_any_ofArray[] =
	{ "NULL", "NUM_OF_UE_REG", "NUM_OF_PDU_SESS_ESTBL", "RES_USAGE",
	  "NUM_OF_EXCEED_RES_USAGE_LOAD_LEVEL_THR",
	  "PERIOD_OF_EXCEED_RES_USAGE_LOAD_LEVEL_THR",
	  "EXCEED_LOAD_LEVEL_THR_IND", "LIST_OF_TOP_APP_UL",
	  "LIST_OF_TOP_APP_DL", "NF_STATUS", "NF_RESOURCE_USAGE",
	  "NF_LOAD", "NF_PEAK_LOAD", "NF_LOAD_AVG_IN_AOI",
	  "DISPER_AMOUNT", "DISPER_CLASS", "RANKING",
	  "PERCENTILE_RANKING", "RSSI", "RTT", "TRAFFIC_INFO",
	  "NUMBER_OF_UES", "APP_LIST_FOR_UE_COMM",
	  "N4_SESS_INACT_TIMER_FOR_UE_COMM", "AVG_TRAFFIC_RATE",
	  "MAX_TRAFFIC_RATE", "AGG_TRAFFIC_RATE", "VAR_TRAFFIC_RATE",
	  "AVG_PACKET_DELAY", "MAX_PACKET_DELAY", "VAR_PACKET_DELAY",
	  "AVG_PACKET_LOSS_RATE", "MAX_PACKET_LOSS_RATE",
	  "VAR_PACKET_LOSS_RATE", "UE_LOCATION", "LIST_OF_HIGH_EXP_UE",
	  "LIST_OF_MEDIUM_EXP_UE", "LIST_OF_LOW_EXP_UE",
	  "AVG_UL_PKT_DROP_RATE", "VAR_UL_PKT_DROP_RATE",
	  "AVG_DL_PKT_DROP_RATE", "VAR_DL_PKT_DROP_RATE",
	  "AVG_UL_PKT_DELAY", "VAR_UL_PKT_DELAY", "AVG_DL_PKT_DELAY",
	  "VAR_DL_PKT_DELAY", "TRAFFIC_MATCH_TD", "TRAFFIC_UNMATCH_TD",
	  "NUMBER_OF_UE", "UE_GEOG_DIST", "UE_DIRECTION",
	  "AVG_E2E_UL_PKT_DELAY", "VAR_E2E_UL_PKT_DELAY",
	  "AVG_E2E_DL_PKT_DELAY", "VAR_E2E_DL_PKT_DELAY",
	  "AVG_E2E_UL_PKT_LOSS_RATE", "VAR_E2E_UL_PKT_LOSS_RATE",
	  "AVG_E2E_DL_PKT_LOSS_RATE", "VAR_E2E_DL_PKT_LOSS_RATE",
	  "E2E_DATA_VOL_TRANS_TIME_FOR_UE_LIST", "IN_OUT_PERCENT",
	  "TIME_TO_COLLISION" };
	size_t sizeofArray = sizeof(analytics_subset_any_ofArray) /
	                     sizeof(analytics_subset_any_ofArray[0]);
	if(analytics_subset_any_of < sizeofArray) {
		return (char *) analytics_subset_any_ofArray[
			analytics_subset_any_of];
	} else {
		return (char *) "Unknown";
	}
}

analytics_subset_any_of_e analytics_subset_any_of_FromString(
	char *analytics_subset_any_of) {
	int stringToReturn = 0;
	const char *analytics_subset_any_ofArray[] =
	{ "NULL", "NUM_OF_UE_REG", "NUM_OF_PDU_SESS_ESTBL", "RES_USAGE",
	  "NUM_OF_EXCEED_RES_USAGE_LOAD_LEVEL_THR",
	  "PERIOD_OF_EXCEED_RES_USAGE_LOAD_LEVEL_THR",
	  "EXCEED_LOAD_LEVEL_THR_IND", "LIST_OF_TOP_APP_UL",
	  "LIST_OF_TOP_APP_DL", "NF_STATUS", "NF_RESOURCE_USAGE",
	  "NF_LOAD", "NF_PEAK_LOAD", "NF_LOAD_AVG_IN_AOI",
	  "DISPER_AMOUNT", "DISPER_CLASS", "RANKING",
	  "PERCENTILE_RANKING", "RSSI", "RTT", "TRAFFIC_INFO",
	  "NUMBER_OF_UES", "APP_LIST_FOR_UE_COMM",
	  "N4_SESS_INACT_TIMER_FOR_UE_COMM", "AVG_TRAFFIC_RATE",
	  "MAX_TRAFFIC_RATE", "AGG_TRAFFIC_RATE", "VAR_TRAFFIC_RATE",
	  "AVG_PACKET_DELAY", "MAX_PACKET_DELAY", "VAR_PACKET_DELAY",
	  "AVG_PACKET_LOSS_RATE", "MAX_PACKET_LOSS_RATE",
	  "VAR_PACKET_LOSS_RATE", "UE_LOCATION", "LIST_OF_HIGH_EXP_UE",
	  "LIST_OF_MEDIUM_EXP_UE", "LIST_OF_LOW_EXP_UE",
	  "AVG_UL_PKT_DROP_RATE", "VAR_UL_PKT_DROP_RATE",
	  "AVG_DL_PKT_DROP_RATE", "VAR_DL_PKT_DROP_RATE",
	  "AVG_UL_PKT_DELAY", "VAR_UL_PKT_DELAY", "AVG_DL_PKT_DELAY",
	  "VAR_DL_PKT_DELAY", "TRAFFIC_MATCH_TD", "TRAFFIC_UNMATCH_TD",
	  "NUMBER_OF_UE", "UE_GEOG_DIST", "UE_DIRECTION",
	  "AVG_E2E_UL_PKT_DELAY", "VAR_E2E_UL_PKT_DELAY",
	  "AVG_E2E_DL_PKT_DELAY", "VAR_E2E_DL_PKT_DELAY",
	  "AVG_E2E_UL_PKT_LOSS_RATE", "VAR_E2E_UL_PKT_LOSS_RATE",
	  "AVG_E2E_DL_PKT_LOSS_RATE", "VAR_E2E_DL_PKT_LOSS_RATE",
	  "E2E_DATA_VOL_TRANS_TIME_FOR_UE_LIST", "IN_OUT_PERCENT",
	  "TIME_TO_COLLISION" };
	size_t sizeofArray = sizeof(analytics_subset_any_ofArray) /
	                     sizeof(analytics_subset_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(analytics_subset_any_of,
		          analytics_subset_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
