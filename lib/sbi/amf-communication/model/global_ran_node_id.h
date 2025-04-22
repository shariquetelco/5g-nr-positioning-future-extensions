/*
 * global_ran_node_id.h
 *
 * One of the six attributes n3IwfId, gNbIdm, ngeNbId, wagfId, tngfId, eNbId shall be present.
 */

#ifndef _global_ran_node_id_H_
#define _global_ran_node_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "gnb_id.h"
#include "plmn_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct global_ran_node_id_s global_ran_node_id_t;
typedef struct global_ran_node_id_s {
	struct plmn_id_s *plmn_id;
	char *n3_iwf_id;
	struct gnb_id_s *g_nb_id;
	char *nge_nb_id;
	char *wagf_id;
	char *tngf_id;
	char *nid;
	char *e_nb_id;
} global_ran_node_id_t;

global_ran_node_id_t *global_ran_node_id_create(plmn_id_t *plmn_id,
                                                char *n3_iwf_id,
                                                gnb_id_t *g_nb_id,
                                                char *nge_nb_id, char *wagf_id,
                                                char *tngf_id, char *nid,
                                                char *e_nb_id);
void global_ran_node_id_free(global_ran_node_id_t *global_ran_node_id);
global_ran_node_id_t *global_ran_node_id_parseFromJSON(
	cJSON *global_ran_node_idJSON);
cJSON *global_ran_node_id_convertToJSON(
	global_ran_node_id_t *global_ran_node_id);
global_ran_node_id_t *global_ran_node_id_copy(global_ran_node_id_t	*dst,
                                              global_ran_node_id_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _global_ran_node_id_H_ */
