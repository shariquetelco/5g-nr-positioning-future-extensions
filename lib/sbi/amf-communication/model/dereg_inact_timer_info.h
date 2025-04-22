/*
 * dereg_inact_timer_info.h
 *
 * Network Slice Deregistration Inactivity Timer Information
 */

#ifndef _dereg_inact_timer_info_H_
#define _dereg_inact_timer_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nssaa_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dereg_inact_timer_info_s dereg_inact_timer_info_t;
typedef struct dereg_inact_timer_info_s {
	struct nssaa_status_s *dereg_inact_expiry_time;
} dereg_inact_timer_info_t;

dereg_inact_timer_info_t *dereg_inact_timer_info_create(
	nssaa_status_t *dereg_inact_expiry_time);
void dereg_inact_timer_info_free(
	dereg_inact_timer_info_t *dereg_inact_timer_info);
dereg_inact_timer_info_t *dereg_inact_timer_info_parseFromJSON(
	cJSON *dereg_inact_timer_infoJSON);
cJSON *dereg_inact_timer_info_convertToJSON(
	dereg_inact_timer_info_t *dereg_inact_timer_info);
dereg_inact_timer_info_t *dereg_inact_timer_info_copy(
	dereg_inact_timer_info_t *dst, dereg_inact_timer_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _dereg_inact_timer_info_H_ */
