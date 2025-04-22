/*
 * traffic_profile_any_of.h
 *
 *
 */

#ifndef _traffic_profile_any_of_H_
#define _traffic_profile_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { traffic_profile_any_of_NULL = 0,
	       traffic_profile_any_of_SINGLE_TRANS_UL,
	       traffic_profile_any_of_SINGLE_TRANS_DL,
	       traffic_profile_any_of_DUAL_TRANS_UL_FIRST,
	       traffic_profile_any_of_DUAL_TRANS_DL_FIRST,
	       traffic_profile_any_of_MULTI_TRANS } traffic_profile_any_of_e;

char *traffic_profile_any_of_ToString(
	traffic_profile_any_of_e traffic_profile_any_of);

traffic_profile_any_of_e traffic_profile_any_of_FromString(
	char *traffic_profile_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _traffic_profile_any_of_H_ */
