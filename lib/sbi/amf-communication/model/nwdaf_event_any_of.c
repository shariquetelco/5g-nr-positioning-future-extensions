#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nwdaf_event_any_of.h"

char *nwdaf_event_any_of_ToString(nwdaf_event_any_of_e nwdaf_event_any_of) {
	const char *nwdaf_event_any_ofArray[] =
	{ "NULL", "SLICE_LOAD_LEVEL", "NETWORK_PERFORMANCE", "NF_LOAD",
	  "SERVICE_EXPERIENCE", "UE_MOBILITY", "UE_COMMUNICATION",
	  "QOS_SUSTAINABILITY", "ABNORMAL_BEHAVIOUR",
	  "USER_DATA_CONGESTION", "NSI_LOAD_LEVEL", "DN_PERFORMANCE",
	  "DISPERSION", "RED_TRANS_EXP", "WLAN_PERFORMANCE",
	  "SM_CONGESTION", "PFD_DETERMINATION", "PDU_SESSION_TRAFFIC",
	  "E2E_DATA_VOL_TRANS_TIME", "MOVEMENT_BEHAVIOUR", "NUM_OF_UE",
	  "MOV_UE_RATIO", "AVR_SPEED", "SPEED_THRESHOLD",
	  "MOV_UE_DIRECTION", "LOC_ACCURACY", "RELATIVE_PROXIMITY" };
	size_t sizeofArray = sizeof(nwdaf_event_any_ofArray) /
	                     sizeof(nwdaf_event_any_ofArray[0]);
	if(nwdaf_event_any_of < sizeofArray) {
		return (char *) nwdaf_event_any_ofArray[nwdaf_event_any_of];
	} else {
		return (char *) "Unknown";
	}
}

nwdaf_event_any_of_e nwdaf_event_any_of_FromString(char *nwdaf_event_any_of) {
	int stringToReturn = 0;
	const char *nwdaf_event_any_ofArray[] =
	{ "NULL", "SLICE_LOAD_LEVEL", "NETWORK_PERFORMANCE", "NF_LOAD",
	  "SERVICE_EXPERIENCE", "UE_MOBILITY", "UE_COMMUNICATION",
	  "QOS_SUSTAINABILITY", "ABNORMAL_BEHAVIOUR",
	  "USER_DATA_CONGESTION", "NSI_LOAD_LEVEL", "DN_PERFORMANCE",
	  "DISPERSION", "RED_TRANS_EXP", "WLAN_PERFORMANCE",
	  "SM_CONGESTION", "PFD_DETERMINATION", "PDU_SESSION_TRAFFIC",
	  "E2E_DATA_VOL_TRANS_TIME", "MOVEMENT_BEHAVIOUR", "NUM_OF_UE",
	  "MOV_UE_RATIO", "AVR_SPEED", "SPEED_THRESHOLD",
	  "MOV_UE_DIRECTION", "LOC_ACCURACY", "RELATIVE_PROXIMITY" };
	size_t sizeofArray = sizeof(nwdaf_event_any_ofArray) /
	                     sizeof(nwdaf_event_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(nwdaf_event_any_of,
		          nwdaf_event_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
