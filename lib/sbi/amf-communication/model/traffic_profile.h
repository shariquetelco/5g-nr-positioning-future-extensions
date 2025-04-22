/*
 * traffic_profile.h
 *
 * Possible values are: - SINGLE_TRANS_UL: Uplink single packet transmission. - SINGLE_TRANS_DL: Downlink single packet transmission. - DUAL_TRANS_UL_FIRST: Dual packet transmission, firstly uplink packet transmission   with subsequent downlink packet transmission. - DUAL_TRANS_DL_FIRST: Dual packet transmission, firstly downlink packet transmission   with subsequent uplink packet transmission.
 */

#ifndef _traffic_profile_H_
#define _traffic_profile_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "traffic_profile_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct traffic_profile_s traffic_profile_t;
typedef struct traffic_profile_s {} traffic_profile_t;

traffic_profile_t *traffic_profile_create();
void traffic_profile_free(traffic_profile_t *traffic_profile);
traffic_profile_t *traffic_profile_parseFromJSON(cJSON *traffic_profileJSON);
cJSON *traffic_profile_convertToJSON(traffic_profile_t *traffic_profile);
traffic_profile_t *traffic_profile_copy(traffic_profile_t	*dst,
                                        traffic_profile_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _traffic_profile_H_ */
