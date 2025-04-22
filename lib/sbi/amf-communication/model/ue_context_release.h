/*
 * ue_context_release.h
 *
 * Data within a Release UE Context request
 */

#ifndef _ue_context_release_H_
#define _ue_context_release_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ng_ap_cause.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_context_release_s ue_context_release_t;
typedef struct ue_context_release_s {
	char *supi;
	bool is_unauthenticated_supi;
	int unauthenticated_supi;
	struct ng_ap_cause_s *ngap_cause;
} ue_context_release_t;

ue_context_release_t *ue_context_release_create(char		*supi,
                                                bool		is_unauthenticated_supi,
                                                int		unauthenticated_supi,
                                                ng_ap_cause_t	*ngap_cause);
void ue_context_release_free(ue_context_release_t *ue_context_release);
ue_context_release_t *ue_context_release_parseFromJSON(
	cJSON *ue_context_releaseJSON);
cJSON *ue_context_release_convertToJSON(
	ue_context_release_t *ue_context_release);
ue_context_release_t *ue_context_release_copy(ue_context_release_t	*dst,
                                              ue_context_release_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_context_release_H_ */
