/*
 * lte_v2x_auth.h
 *
 * Contains LTE V2X services authorized information.
 */

#ifndef _lte_v2x_auth_H_
#define _lte_v2x_auth_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_auth.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct lte_v2x_auth_s lte_v2x_auth_t;
typedef struct lte_v2x_auth_s {
	struct ue_auth_s *vehicle_ue_auth;
	struct ue_auth_s *pedestrian_ue_auth;
} lte_v2x_auth_t;

lte_v2x_auth_t *lte_v2x_auth_create(ue_auth_t	*vehicle_ue_auth,
                                    ue_auth_t	*pedestrian_ue_auth);
void lte_v2x_auth_free(lte_v2x_auth_t *lte_v2x_auth);
lte_v2x_auth_t *lte_v2x_auth_parseFromJSON(cJSON *lte_v2x_authJSON);
cJSON *lte_v2x_auth_convertToJSON(lte_v2x_auth_t *lte_v2x_auth);
lte_v2x_auth_t *lte_v2x_auth_copy(lte_v2x_auth_t *dst, lte_v2x_auth_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _lte_v2x_auth_H_ */
