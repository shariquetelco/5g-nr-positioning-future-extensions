#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rat_type_any_of.h"

char *rat_type_any_of_ToString(rat_type_any_of_e rat_type_any_of) {
	const char *rat_type_any_ofArray[] =
	{ "NULL", "NR", "EUTRA", "WLAN", "VIRTUAL", "NBIOT", "WIRELINE",
	  "WIRELINE_CABLE", "WIRELINE_BBF", "LTE-M", "NR_U", "EUTRA_U",
	  "TRUSTED_N3GA", "TRUSTED_WLAN", "UTRA", "GERA", "NR_LEO",
	  "NR_MEO", "NR_GEO", "NR_OTHER_SAT", "NR_REDCAP",
	  "WB_E_UTRAN_LEO", "WB_E_UTRAN_MEO", "WB_E_UTRAN_GEO",
	  "WB_E_UTRAN_OTHERSAT", "NB_IOT_LEO", "NB_IOT_MEO", "NB_IOT_GEO",
	  "NB_IOT_OTHERSAT", "LTE_M_LEO", "LTE_M_MEO", "LTE_M_GEO",
	  "LTE_M_OTHERSAT", "NR_EREDCAP" };
	size_t sizeofArray = sizeof(rat_type_any_ofArray) /
	                     sizeof(rat_type_any_ofArray[0]);
	if(rat_type_any_of < sizeofArray) {
		return (char *) rat_type_any_ofArray[rat_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

rat_type_any_of_e rat_type_any_of_FromString(char *rat_type_any_of) {
	int stringToReturn = 0;
	const char *rat_type_any_ofArray[] =
	{ "NULL", "NR", "EUTRA", "WLAN", "VIRTUAL", "NBIOT", "WIRELINE",
	  "WIRELINE_CABLE", "WIRELINE_BBF", "LTE-M", "NR_U", "EUTRA_U",
	  "TRUSTED_N3GA", "TRUSTED_WLAN", "UTRA", "GERA", "NR_LEO",
	  "NR_MEO", "NR_GEO", "NR_OTHER_SAT", "NR_REDCAP",
	  "WB_E_UTRAN_LEO", "WB_E_UTRAN_MEO", "WB_E_UTRAN_GEO",
	  "WB_E_UTRAN_OTHERSAT", "NB_IOT_LEO", "NB_IOT_MEO", "NB_IOT_GEO",
	  "NB_IOT_OTHERSAT", "LTE_M_LEO", "LTE_M_MEO", "LTE_M_GEO",
	  "LTE_M_OTHERSAT", "NR_EREDCAP" };
	size_t sizeofArray = sizeof(rat_type_any_ofArray) /
	                     sizeof(rat_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(rat_type_any_of,
		          rat_type_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
