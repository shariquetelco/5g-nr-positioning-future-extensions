/*
 * release_session_info.h
 *
 * PDU session Id(s) and the cause for triggering the release.
 */

#ifndef _release_session_info_H_
#define _release_session_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "release_cause.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct release_session_info_s release_session_info_t;
typedef struct release_session_info_s {
	list_t *release_session_list;
	release_cause_e release_cause;
} release_session_info_t;

release_session_info_t *release_session_info_create(
	list_t *release_session_list, release_cause_e release_cause);
void release_session_info_free(release_session_info_t *release_session_info);
release_session_info_t *release_session_info_parseFromJSON(
	cJSON *release_session_infoJSON);
cJSON *release_session_info_convertToJSON(
	release_session_info_t *release_session_info);
release_session_info_t *release_session_info_copy(
	release_session_info_t	*dst,
	release_session_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _release_session_info_H_ */
