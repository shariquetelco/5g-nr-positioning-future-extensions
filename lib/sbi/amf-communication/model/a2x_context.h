/*
 * a2x_context.h
 *
 * Represents the A2X services related parameters
 */

#ifndef _a2x_context_H_
#define _a2x_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "lte_a2x_auth.h"
#include "nr_a2x_auth.h"
#include "pc5_qo_s_para.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct a2x_context_s a2x_context_t;
typedef struct a2x_context_s {
	struct nr_a2x_auth_s *nr_a2x_services_auth;
	struct lte_a2x_auth_s *lte_a2x_services_auth;
	char *nr_ue_sidelink_ambr;
	char *lte_ue_sidelink_ambr;
	struct pc5_qo_s_para_s *pc5_qo_s_para;
} a2x_context_t;

a2x_context_t *a2x_context_create(nr_a2x_auth_t		*nr_a2x_services_auth,
                                  lte_a2x_auth_t	*lte_a2x_services_auth,
                                  char			*nr_ue_sidelink_ambr,
                                  char			*lte_ue_sidelink_ambr,
                                  pc5_qo_s_para_t	*pc5_qo_s_para);
void a2x_context_free(a2x_context_t *a2x_context);
a2x_context_t *a2x_context_parseFromJSON(cJSON *a2x_contextJSON);
cJSON *a2x_context_convertToJSON(a2x_context_t *a2x_context);
a2x_context_t *a2x_context_copy(a2x_context_t *dst, a2x_context_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _a2x_context_H_ */
