/*
 * prose_context.h
 *
 * Represents the ProSe services related parameters.
 */

#ifndef _prose_context_H_
#define _prose_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "pc5_qo_s_para.h"
#include "ue_auth.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct prose_context_s prose_context_t;
typedef struct prose_context_s {
	struct ue_auth_s *direct_discovery;
	struct ue_auth_s *direct_comm;
	struct ue_auth_s *l2_relay;
	struct ue_auth_s *l3_relay;
	struct ue_auth_s *l2_remote;
	struct ue_auth_s *l3_remote;
	struct ue_auth_s *l2_ue_relay;
	struct ue_auth_s *l3_ue_relay;
	struct ue_auth_s *l2_end;
	struct ue_auth_s *l3_end;
	struct ue_auth_s *multi_path_comm;
	char *nr_ue_pc5_ambr;
	struct pc5_qo_s_para_s *pc5_qo_s_para;
} prose_context_t;

prose_context_t *prose_context_create(ue_auth_t *direct_discovery,
                                      ue_auth_t *direct_comm,
                                      ue_auth_t *l2_relay, ue_auth_t *l3_relay,
                                      ue_auth_t *l2_remote,
                                      ue_auth_t *l3_remote,
                                      ue_auth_t *l2_ue_relay,
                                      ue_auth_t *l3_ue_relay, ue_auth_t *l2_end,
                                      ue_auth_t *l3_end,
                                      ue_auth_t *multi_path_comm,
                                      char *nr_ue_pc5_ambr,
                                      pc5_qo_s_para_t *pc5_qo_s_para);
void prose_context_free(prose_context_t *prose_context);
prose_context_t *prose_context_parseFromJSON(cJSON *prose_contextJSON);
cJSON *prose_context_convertToJSON(prose_context_t *prose_context);
prose_context_t *prose_context_copy(prose_context_t *dst, prose_context_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _prose_context_H_ */
