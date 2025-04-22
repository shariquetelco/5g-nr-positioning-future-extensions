/*
 * prev_sub_info.h
 *
 * Information of the previous subscription.
 */

#ifndef _prev_sub_info_H_
#define _prev_sub_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nwdaf_event.h"
#include "ue_analytics_context_descriptor.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct prev_sub_info_s prev_sub_info_t;
typedef struct prev_sub_info_s {
	char *producer_id;
	char *producer_set_id;
	char *subscription_id;
	list_t *nf_ana_events;
	list_t *ue_ana_events;
} prev_sub_info_t;

prev_sub_info_t *prev_sub_info_create(char *producer_id, char *producer_set_id,
                                      char *subscription_id,
                                      list_t *nf_ana_events,
                                      list_t *ue_ana_events);
void prev_sub_info_free(prev_sub_info_t *prev_sub_info);
prev_sub_info_t *prev_sub_info_parseFromJSON(cJSON *prev_sub_infoJSON);
cJSON *prev_sub_info_convertToJSON(prev_sub_info_t *prev_sub_info);
prev_sub_info_t *prev_sub_info_copy(prev_sub_info_t *dst, prev_sub_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _prev_sub_info_H_ */
