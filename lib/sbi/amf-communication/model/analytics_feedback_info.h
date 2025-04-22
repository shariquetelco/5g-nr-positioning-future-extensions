/*
 * analytics_feedback_info.h
 *
 * Analytics feedback information.
 */

#ifndef _analytics_feedback_info_H_
#define _analytics_feedback_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nwdaf_event.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct analytics_feedback_info_s analytics_feedback_info_t;
typedef struct analytics_feedback_info_s {
	list_t *action_times;
	list_t *used_ana_types;
	bool is_impact_ind;
	int impact_ind;
} analytics_feedback_info_t;

analytics_feedback_info_t *analytics_feedback_info_create(list_t *action_times,
                                                          list_t *used_ana_types, bool is_impact_ind, int impact_ind);
void analytics_feedback_info_free(
	analytics_feedback_info_t *analytics_feedback_info);
analytics_feedback_info_t *analytics_feedback_info_parseFromJSON(
	cJSON *analytics_feedback_infoJSON);
cJSON *analytics_feedback_info_convertToJSON(
	analytics_feedback_info_t *analytics_feedback_info);
analytics_feedback_info_t *analytics_feedback_info_copy(
	analytics_feedback_info_t *dst, analytics_feedback_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _analytics_feedback_info_H_ */
