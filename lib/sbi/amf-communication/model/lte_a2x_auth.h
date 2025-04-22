/*
 * lte_a2x_auth.h
 *
 * Contains LTE A2X services authorized information.
 */

#ifndef _lte_a2x_auth_H_
#define _lte_a2x_auth_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_auth.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct lte_a2x_auth_s lte_a2x_auth_t;
typedef struct lte_a2x_auth_s {
	struct ue_auth_s *uav_ue_auth;
} lte_a2x_auth_t;

lte_a2x_auth_t *lte_a2x_auth_create(ue_auth_t *uav_ue_auth);
void lte_a2x_auth_free(lte_a2x_auth_t *lte_a2x_auth);
lte_a2x_auth_t *lte_a2x_auth_parseFromJSON(cJSON *lte_a2x_authJSON);
cJSON *lte_a2x_auth_convertToJSON(lte_a2x_auth_t *lte_a2x_auth);
lte_a2x_auth_t *lte_a2x_auth_copy(lte_a2x_auth_t *dst, lte_a2x_auth_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _lte_a2x_auth_H_ */
