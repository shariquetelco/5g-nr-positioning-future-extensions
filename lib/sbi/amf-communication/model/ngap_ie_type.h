/*
 * ngap_ie_type.h
 *
 *
 */

#ifndef _ngap_ie_type_H_
#define _ngap_ie_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ngap_ie_type_NULL = 0, ngap_ie_type_PDU_RES_SETUP_REQ,
	       ngap_ie_type_PDU_RES_REL_CMD, ngap_ie_type_PDU_RES_MOD_REQ,
	       ngap_ie_type_HANDOVER_CMD, ngap_ie_type_HANDOVER_REQUIRED,
	       ngap_ie_type_HANDOVER_PREP_FAIL,
	       ngap_ie_type_SRC_TO_TAR_CONTAINER,
	       ngap_ie_type_TAR_TO_SRC_CONTAINER,
	       ngap_ie_type_TAR_TO_SRC_FAIL_CONTAINER,
	       ngap_ie_type_RAN_STATUS_TRANS_CONTAINER,
	       ngap_ie_type_SON_CONFIG_TRANSFER, ngap_ie_type_NRPPA_PDU,
	       ngap_ie_type_UE_RADIO_CAPABILITY, ngap_ie_type_RIM_INFO_TRANSFER,
	       ngap_ie_type_SECONDARY_RAT_USAGE, ngap_ie_type_PC5_QOS_PARA,
	       ngap_ie_type_EARLY_STATUS_TRANS_CONTAINER,
	       ngap_ie_type_UE_RADIO_CAPABILITY_FOR_PAGING } ngap_ie_type_e;

char *ngap_ie_type_ToString(ngap_ie_type_e ngap_ie_type);

ngap_ie_type_e ngap_ie_type_FromString(char *ngap_ie_type);

#ifdef __cplusplus
}
#endif

#endif /* _ngap_ie_type_H_ */
