/*
 * nr_a2x_auth.h
 *
 * Contains NR A2X services authorized information.
 */

#ifndef _nr_a2x_auth_H_
#define _nr_a2x_auth_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_auth.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nr_a2x_auth_s nr_a2x_auth_t;
typedef struct nr_a2x_auth_s {
	struct ue_auth_s *uav_ue_auth;
} nr_a2x_auth_t;

nr_a2x_auth_t *nr_a2x_auth_create(ue_auth_t *uav_ue_auth);
void nr_a2x_auth_free(nr_a2x_auth_t *nr_a2x_auth);
nr_a2x_auth_t *nr_a2x_auth_parseFromJSON(cJSON *nr_a2x_authJSON);
cJSON *nr_a2x_auth_convertToJSON(nr_a2x_auth_t *nr_a2x_auth);
nr_a2x_auth_t *nr_a2x_auth_copy(nr_a2x_auth_t *dst, nr_a2x_auth_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nr_a2x_auth_H_ */
