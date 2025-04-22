/*
 * v2x_context.h
 *
 * Represents the V2X services related parameters
 */

#ifndef _v2x_context_H_
#define _v2x_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "lte_v2x_auth.h"
#include "nr_v2x_auth.h"
#include "pc5_qo_s_para.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct v2x_context_s v2x_context_t;
typedef struct v2x_context_s {
	struct nr_v2x_auth_s *nr_v2x_services_auth;
	struct lte_v2x_auth_s *lte_v2x_services_auth;
	char *nr_ue_sidelink_ambr;
	char *lte_ue_sidelink_ambr;
	struct pc5_qo_s_para_s *pc5_qo_s_para;
} v2x_context_t;

v2x_context_t *v2x_context_create(nr_v2x_auth_t		*nr_v2x_services_auth,
                                  lte_v2x_auth_t	*lte_v2x_services_auth,
                                  char			*nr_ue_sidelink_ambr,
                                  char			*lte_ue_sidelink_ambr,
                                  pc5_qo_s_para_t	*pc5_qo_s_para);
void v2x_context_free(v2x_context_t *v2x_context);
v2x_context_t *v2x_context_parseFromJSON(cJSON *v2x_contextJSON);
cJSON *v2x_context_convertToJSON(v2x_context_t *v2x_context);
v2x_context_t *v2x_context_copy(v2x_context_t *dst, v2x_context_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _v2x_context_H_ */
