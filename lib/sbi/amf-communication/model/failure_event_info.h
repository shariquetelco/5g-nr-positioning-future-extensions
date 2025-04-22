/*
 * failure_event_info.h
 *
 * Contains information on the event for which the subscription is not successful.
 */

#ifndef _failure_event_info_H_
#define _failure_event_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nwdaf_event.h"
#include "nwdaf_failure_code.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct failure_event_info_s failure_event_info_t;
typedef struct failure_event_info_s {
	struct nwdaf_event_s *event;
	struct nwdaf_failure_code_s *failure_code;
} failure_event_info_t;

failure_event_info_t *failure_event_info_create(nwdaf_event_t		*event,
                                                nwdaf_failure_code_t	*failure_code);
void failure_event_info_free(failure_event_info_t *failure_event_info);
failure_event_info_t *failure_event_info_parseFromJSON(
	cJSON *failure_event_infoJSON);
cJSON *failure_event_info_convertToJSON(
	failure_event_info_t *failure_event_info);
failure_event_info_t *failure_event_info_copy(failure_event_info_t	*dst,
                                              failure_event_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _failure_event_info_H_ */
