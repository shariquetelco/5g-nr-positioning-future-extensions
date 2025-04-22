/*
 * rel_prox_req.h
 *
 * Represents the Relative Proximity analytics requirements.
 */

#ifndef _rel_prox_req_H_
#define _rel_prox_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "direction.h"
#include "proximity_criterion.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rel_prox_req_s rel_prox_req_t;
typedef struct rel_prox_req_s {
	list_t *direction;
	bool is_num_of_ue;
	int num_of_ue;
	list_t *proximity_crits;
} rel_prox_req_t;

rel_prox_req_t *rel_prox_req_create(list_t *direction, bool is_num_of_ue,
                                    int num_of_ue, list_t *proximity_crits);
void rel_prox_req_free(rel_prox_req_t *rel_prox_req);
rel_prox_req_t *rel_prox_req_parseFromJSON(cJSON *rel_prox_reqJSON);
cJSON *rel_prox_req_convertToJSON(rel_prox_req_t *rel_prox_req);
rel_prox_req_t *rel_prox_req_copy(rel_prox_req_t *dst, rel_prox_req_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _rel_prox_req_H_ */
