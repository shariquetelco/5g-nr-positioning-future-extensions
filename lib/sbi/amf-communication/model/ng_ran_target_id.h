/*
 * ng_ran_target_id.h
 *
 * Indicates a NG RAN as target of the handover
 */

#ifndef _ng_ran_target_id_H_
#define _ng_ran_target_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "global_ran_node_id.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ng_ran_target_id_s ng_ran_target_id_t;
typedef struct ng_ran_target_id_s {
	struct global_ran_node_id_s *ran_node_id;
	struct tai_s *tai;
} ng_ran_target_id_t;

ng_ran_target_id_t *ng_ran_target_id_create(
	global_ran_node_id_t	*ran_node_id,
	tai_t			*tai);
void ng_ran_target_id_free(ng_ran_target_id_t *ng_ran_target_id);
ng_ran_target_id_t *ng_ran_target_id_parseFromJSON(cJSON *ng_ran_target_idJSON);
cJSON *ng_ran_target_id_convertToJSON(ng_ran_target_id_t *ng_ran_target_id);
ng_ran_target_id_t *ng_ran_target_id_copy(ng_ran_target_id_t	*dst,
                                          ng_ran_target_id_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ng_ran_target_id_H_ */
