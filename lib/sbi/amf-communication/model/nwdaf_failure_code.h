/*
 * nwdaf_failure_code.h
 *
 * Represents the failure reason.   Possible values are: - UNAVAILABLE_DATA: Indicates the requested statistics information for the event is rejected   since necessary data to perform the service is unavailable. - BOTH_STAT_PRED_NOT_ALLOWED: Indicates the requested analysis information for the event is   rejected since the start time is in the past and the end time is in the future, which   means the NF service consumer requested both statistics and prediction for the analytics. - PREDICTION_NOT_ALLOWED: Indicates that the request for the prediction of the analytics   event is not allowed. - UNSATISFIED_REQUESTED_ANALYTICS_TIME: Indicates that the requested event is rejected since   the analytics information is not ready when the time indicated by the \&quot;timeAnaNeeded\&quot;   attribute (as provided during the creation or modification of subscription) is reached. - NO_ROAMING_SUPPORT: Indicates that the request shall be rejected because roaming analytics   or data are required and the NWDAF neither supports roaming exchange capabilitiy nor can   it forward the request to another NWDAF. - OTHER: Indicates the requested analysis information for the event is rejected due to other   reasons.
 */

#ifndef _nwdaf_failure_code_H_
#define _nwdaf_failure_code_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nwdaf_failure_code_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nwdaf_failure_code_s nwdaf_failure_code_t;
typedef struct nwdaf_failure_code_s {} nwdaf_failure_code_t;

nwdaf_failure_code_t *nwdaf_failure_code_create();
void nwdaf_failure_code_free(nwdaf_failure_code_t *nwdaf_failure_code);
nwdaf_failure_code_t *nwdaf_failure_code_parseFromJSON(
	cJSON *nwdaf_failure_codeJSON);
cJSON *nwdaf_failure_code_convertToJSON(
	nwdaf_failure_code_t *nwdaf_failure_code);
nwdaf_failure_code_t *nwdaf_failure_code_copy(nwdaf_failure_code_t	*dst,
                                              nwdaf_failure_code_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _nwdaf_failure_code_H_ */
