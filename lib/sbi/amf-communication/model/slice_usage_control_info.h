/*
 * slice_usage_control_info.h
 *
 * The network slice usage control related information
 */

#ifndef _slice_usage_control_info_H_
#define _slice_usage_control_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct slice_usage_control_info_s slice_usage_control_info_t;
typedef struct slice_usage_control_info_s {
	struct snssai_s *s_nssai;
	bool is_dereg_inact_timer;
	int dereg_inact_timer;
	bool is_sess_inact_timer;
	int sess_inact_timer;
} slice_usage_control_info_t;

slice_usage_control_info_t *slice_usage_control_info_create(snssai_t *s_nssai,
                                                            bool is_dereg_inact_timer, int dereg_inact_timer, bool is_sess_inact_timer, int sess_inact_timer);
void slice_usage_control_info_free(
	slice_usage_control_info_t *slice_usage_control_info);
slice_usage_control_info_t *slice_usage_control_info_parseFromJSON(
	cJSON *slice_usage_control_infoJSON);
cJSON *slice_usage_control_info_convertToJSON(
	slice_usage_control_info_t *slice_usage_control_info);
slice_usage_control_info_t *slice_usage_control_info_copy(
	slice_usage_control_info_t *dst, slice_usage_control_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _slice_usage_control_info_H_ */
