/*
 * rat_type_any_of.h
 *
 *
 */

#ifndef _rat_type_any_of_H_
#define _rat_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { rat_type_any_of_NULL = 0, rat_type_any_of_NR,
	       rat_type_any_of_EUTRA, rat_type_any_of_WLAN,
	       rat_type_any_of__VIRTUAL,
	       rat_type_any_of_NBIOT, rat_type_any_of_WIRELINE,
	       rat_type_any_of_WIRELINE_CABLE, rat_type_any_of_WIRELINE_BBF,
	       rat_type_any_of_LTE_M, rat_type_any_of_NR_U,
	       rat_type_any_of_EUTRA_U,
	       rat_type_any_of_TRUSTED_N3GA, rat_type_any_of_TRUSTED_WLAN,
	       rat_type_any_of_UTRA, rat_type_any_of_GERA,
	       rat_type_any_of_NR_LEO,
	       rat_type_any_of_NR_MEO, rat_type_any_of_NR_GEO,
	       rat_type_any_of_NR_OTHER_SAT, rat_type_any_of_NR_REDCAP,
	       rat_type_any_of_WB_E_UTRAN_LEO, rat_type_any_of_WB_E_UTRAN_MEO,
	       rat_type_any_of_WB_E_UTRAN_GEO,
	       rat_type_any_of_WB_E_UTRAN_OTHERSAT,
	       rat_type_any_of_NB_IOT_LEO, rat_type_any_of_NB_IOT_MEO,
	       rat_type_any_of_NB_IOT_GEO, rat_type_any_of_NB_IOT_OTHERSAT,
	       rat_type_any_of_LTE_M_LEO, rat_type_any_of_LTE_M_MEO,
	       rat_type_any_of_LTE_M_GEO, rat_type_any_of_LTE_M_OTHERSAT,
	       rat_type_any_of_NR_EREDCAP } rat_type_any_of_e;

char *rat_type_any_of_ToString(rat_type_any_of_e rat_type_any_of);

rat_type_any_of_e rat_type_any_of_FromString(char *rat_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _rat_type_any_of_H_ */
